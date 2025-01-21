#include <stdio.h>
#include <iostream>
#include <time.h>

#include "Monster.h"
#include "Player.h"


int Inventory::count = 0;

Player& operator++(Player& player) // префиксный
{
	player.damage += 5;
	return player;
}

Player& operator++(Player& player, int) // постфиксный
{
	player.damage += 5;
	return player;
}


//---------------------------------
//---------Атака монстра-----------
//---------------------------------
static void manster_attack(Monster& monster, Player& player)
{
	if (monster.Monster_get_cur_health() >= 0)
	{
		printf("Monster attacked\n");
		player.Player_taking(monster.Get_monster_dmg());
	}
	if (player.Player_get_cur_health() <= 0)
	{
		printf("Player is dead\n");
		player.Player_dead();
	}
}

//---------------------------------
//---------Атака игрока------------
//---------------------------------
static void player_attack(Monster& monster, Player& player)
{
	if (player.Player_get_cur_health() >= 0)
	{
		printf("Player attacked\n");
		monster.Monster_taking(player.Get_player_dmg());
	}
	if (monster.Monster_get_cur_health() <= 0)
	{
		printf("Monster is dead\n");
		monster.Monster_dead();
	}
}


//-----------------------------------------
//-----Сражение, первый атакует игрок------
//-----------------------------------------

static void battle(Player& player, Monster monster, int coins)
{
	while (monster.Monster_alive() && player.Player_alive())
	{
		Player::Print_player(player);
		printf("\n");
		monster.Print_monster(monster);
		printf("\n");
		player_attack(monster, player);
		printf("\n");
		if (monster.Monster_alive())
		{
			manster_attack(monster, player);
			if (player.Player_alive()) {
				printf("\nclick to continue\n\n");
				while (getchar() != '\n');
			}
		}
		else {
			printf("\nclick to continue\n\n");
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



	//---------------------------
	//-----Выкинуть предмет------
	//---------------------------

int Invent_throw(Player& player)
{
	int cnt = 0;

	for (int i = 0; i <= 5; i++)
	{
		if (player.Weapon_get_weapon_dmg(player.Get_cell(i)) != 0 || player.Potion_get_health_res(player.Get_cell(i)) != 0)
			cnt += 1;
	}

	if (cnt == 0)
	{
		printf("The inventory is empty\n\n");
		return 0;
	}

	player.Print_inventory(player);

	int num;
	do {
		scanf_s("%d", &num);
	} while (num < 1 || num > 6);
	player.Invent_subtract(num);
}


//---------------------------------------------------------------
//-----Игрок получает зелье лечения(нужно указать тип(0-3))------
//---------------------------------------------------------------

static void Finding_potion(Player& player, int type)
{
	switch (type)
	{
	case 0: {
		printf("\nHave you found a small healing potion\n\n");
		get_potion(player, "small healing potion", 20);
		break;
	}
	case 1: {
		printf("\nHave you found the average cure potion\n\n");
		get_potion(player, "average cure potion", 40);
		break;
	}
	case 2: {
		printf("\nHave you found a powerful healing potion\n\n");
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
		printf("\nHave you found the sword\n\n");
		get_weapon(player, "sword", 10);
		break;
	}
	case 1: {
		printf("\nHave you found the axe\n\n");
		get_weapon(player, "axe", 7);
		break;
	}
	case 2: {
		printf("\nHave you found the hammer\n\n");
		get_weapon(player, "hammer", 5);
		break;
	}
	default:
		break;
	}
}


//-----------------------------------------------------------------------------------
//-----Магазин(может восстановить жизни или увеличить dmg или повысить уровень)------
//-----------------------------------------------------------------------------------

static void Shop(Player& player)
{
	Player::Print_player(player);
	printf("\nYou have entered the store!\n");
	printf("1)Exit the store\n");
	printf("You can:\n2)Restore lives(20 coins)\n3)Increase the attack(+10)(50 coins)\n4)Raise the level(dmg+5)(30 coins)\n\n");
	int k;
	do {
		scanf_s("%d", &k);
	} while (k < 1 || k > 4);
	switch (k)
	{
	case 1:
	{
		break;
	}
	case 2:
	{
		if (player.Player_get_coins() >= 20)
		{
			player.Player_heal();
			player.Player_set_coins(-20);
		}
		else
		{
			printf("You don't have enough coins\n");
		}
		break;
	}
	case 3:
	{
		if (player.Player_get_coins() >= 50)
		{
			player+10;
			player.Player_set_coins(-50);
		}
		else
		{
			printf("You don't have enough coins\n");
		}
		break;
	}
	case 4:
	{
		if (player.Player_get_coins() >= 30)
		{
			player++;
			player.Player_set_coins(-30);
		}
		else
		{
			printf("You don't have enough coins\n");
		}
		break;
	}
	}
}


//----------------------------------------------------
//-----Игрок выбирает, какое оружие использовать------
//----------------------------------------------------

static int Choosing_weapon(Player& player)
{
	int cnt = 0;

	for (int i = 0; i <= 5; i++)
	{
		if (player.Weapon_get_weapon_dmg(player.Get_cell(i)) == 0)
			cnt += 1;
	}

	if (cnt == 6)
	{
		printf("You don't have a weapon\n\n");
		return 0;
	}

	player.Print_inventory(player);

	printf("Choose the weapon you want to pick up\n\n");

	int k;

	do {
		scanf_s("%d", &k);
	} while (k < 1 || k > 6);
	printf("\n");
	if (player.Weapon_get_weapon_dmg(player.Get_cell(k - 1)) != 0)
		player.Player_set_weapondmg(player.Weapon_get_weapon_dmg(player.Get_cell(k - 1)));
	else
		printf("It's not a weapon\n\n");

	while (getchar() != '\n');
	return 0;
}


//---------------------------------------------------
//-----Игрок выбирает, какое зелье использовать------
//---------------------------------------------------

static int Restoring_health(Player& player)
{
	int cnt = 0;

	for (int i = 0; i <= 5; i++)
	{
		if (player.Potion_get_health_res(player.Get_cell(i)) == 0)
			cnt += 1;
	}

	if (cnt == 6)
	{
		printf("You don't have a potion\n\n");
		return 0;
	}

	player.Print_inventory(player);

	printf("Select the potion you want to use\n");

	int k;
	Cell vrem;
	do {
		scanf_s("%d", &k);
	} while (k < 1 || k > 6);
	printf("\n");
	if (player.Potion_get_health_res(player.Get_cell(k - 1)) != 0)
	{
		player.Player_potion_heal(player.Potion_get_health_res(player.Get_cell(k - 1)));

		if (player.Player_get_cur_health() > 100)
			player.Player_heal();
		player.Invent_subtract(k);
	}
	else
		printf("It's not a potion\n\n");

	while (getchar() != '\n');
	return 0;
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
			Player::Print_player(player);
			printf("\nSelect an action:\n");
			printf("1)Drink a potion\n");
			printf("2)Choose a weapon\n");
			printf("3)Enter the store\n");
			printf("4)Throw item\n");
			printf("5)Fight the next enemy\n");
			scanf_s("%d", &k);
		} while (k < 1 || k > 5);

		switch (k)
		{
		case 1:
		{
			Restoring_health(player);
			break;
		}
		case 2:
		{
			Choosing_weapon(player);
			break;
		}
		case 3:
		{
			Shop(player);
			break;
		}
		case 4:
		{
			Invent_throw(player);
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
	Player* player = new Player("Steve");
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
		printf("\nYou've won\n");
		player->Print_player(*player);
	}

	delete player;
}