#include <stdio.h>
#include <iostream>
#include <time.h>

#include "Monster.h"
#include "Player.h"


//-----------------------------------------
//-----Сражение, первый атакует игрок------
//-----------------------------------------

static void battle(Player& player, Monster monster, int coins)
{
	while (monster.Monster_alive() && player.Player_alive())
	{
		player.Print_player();
		printf("\n");
		monster.Print_monster();
		printf("\n");
		monster.Player_attack(player);
		printf("\n");
		if (monster.Monster_alive())
		{
			monster.Monster_attack(player);
			if (player.Player_alive()) {
				std::cout << "\nclick to continue" << std::endl;
				while (getchar() != '\n');
			}
		}
		else {
			std::cout << "\nclick to continue" << std::endl;
			while (getchar() != '\n');
		}
	}
	if (player.Player_alive() == 0)
		exit(0);

	player.Player_set_coins(coins);
}


//----------------------------------------------------------------
//-----Добавление в инвентарь зелья лечения(вспомогательная)------
//----------------------------------------------------------------

static void get_potion(Player& player, const char* type, int health_res)
{
	Cell potion;

	potion.Potion_set_type(type);
	potion.Potion_set_health_res(health_res);
	if (Inventory::Get_count() < 6)
	{
		player.Invent_add(potion);
	}
}


//---------------------------------------------------------
//-----Добавление в инвентарь оружия(вспомогательная)------
//---------------------------------------------------------

static void get_weapon(Player& player, const char* name_weapon, int weapon_dmg)
{
	Cell weapon;

	weapon.Weapon_set_type(name_weapon);
	weapon.Weapon_set_weapon_dmg(weapon_dmg);
	if (Inventory::Get_count() < 6)
	{
		player.Invent_add(weapon);
	}
}


//---------------------------------------------------------------
//-----Игрок получает зелье лечения(нужно указать тип(0-3))------
//---------------------------------------------------------------

static void Finding_potion(Player& player, int type)
{
	switch (type)
	{
	case 0: {
		std::cout << "\nHave you found a small healing potion\n" << std::endl;
		get_potion(player, "small healing potion", 20);
		break;
	}
	case 1: {
		std::cout << "\nHave you found the average cure potion\n" << std::endl;
		get_potion(player, "average cure potion", 40);
		break;
	}
	case 2: {
		std::cout << "\nHave you found a powerful healing potion\n" << std::endl;
		get_potion(player, "powerful healing potion", 60);
		break;
	}
	default:
		break;
	}
}


//-------------------------------------------------------------
//-----Игрок получает оружие, которое выбирается рандомно------
//-------------------------------------------------------------

static void Finding_weapon(Player& player)
{
	srand(time(0));
	int type = rand() % 3;
	switch (type)
	{
	case 0: {
		std::cout << "\nHave you found the sword\n" << std::endl;
		get_weapon(player, "sword", 10);
		break;
	}
	case 1: {
		std::cout << "\nHave you found the axe\n" << std::endl;
		get_weapon(player, "axe", 7);
		break;
	}
	case 2: {
		std::cout << "\nHave you found the hammer\n" << std::endl;
		get_weapon(player, "hammer", 5);
		break;
	}
	default:
		break;
	}
}


//-------------------------------
//-----Меню----------------------
//---1)Drink a potion------------
//---2)Choose a weapon-----------
//---3)Enter the store-----------
//---4)Fight the next enemy------
//-------------------------------

static void Menu(Player& player)
{
	int k;
	do {
		do {
			player.Print_player();
			std::cout << "\nSelect an action:" << std::endl;
			std::cout << "1)Drink a potion" << std::endl;
			std::cout << "2)Choose a weapon" << std::endl;
			std::cout << "3)Enter the store" << std::endl;
			std::cout << "4)Throw item" << std::endl;
			std::cout << "5)Fight the next enemy" << std::endl;
			scanf_s("%d", &k);
		} while (k < 1 || k > 5);

		switch (k)
		{
		case 1:
		{
			player.Restoring_health();
			break;
		}
		case 2:
		{
			player.Choosing_weapon();
			break;
		}
		case 3:
		{
			player.Shop();
			break;
		}
		case 4:
		{
			player.Print_inventory();
			player.Invent_subtract();
		}
		case 5:
		{
			break;
		}
		}
	} while (k < 5);
	while (getchar() != '\n');
}


//-----------------------------------------------------
//-----Главная функция, в которой описан ход игры------
//-----------------------------------------------------

int main()
{
	Monster monster[2][3];
	Player* player = new Player("Steve", 100);
	std::string type[3] = { "Zombie", "Skeleton", "Ghost" };

	srand(time(0));

	int m_health = 20;
	int m_dmg = 5;
	int coins = 10;

	int cnt = 0;

	while(cnt != 6)
		{
			int type_m = rand() % 2;
			int type_map = rand() % 5;

			Menu(*player);
			if (type_map < 2) {
				int i = 0;
				int j = 0;

				monster[i][j].Monster_init(m_health, m_dmg, type[type_m]);
				battle(*player, monster[i][j], coins);

				player++;

				cnt++;

				i++;
				j++;

				m_health += 10;
				m_dmg += 5;
				coins += 10;
			}

			if (type_map == 3 || type_map == 2)
			{
				Finding_potion(*player, rand() % 3);
			}

			if (type_map == 4)
			{
				Finding_weapon(*player);
			}
		}

	if (player->Player_alive())
	{
		std::cout << "You've won<\n" << std::endl;
		player->Print_player();
	}

	delete player;
}