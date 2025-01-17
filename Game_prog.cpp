#include <stdio.h>
#include <time.h>
#include "Classes.cpp"



void init_player(Player& player, const char* name)
{
	player.name = name;
	player.health.max_health = 100;
	player.health.cur_health = 100;
	player.weapon_dmg = 0;
	player.coins = 0;
	player.inventory.count = 0;
	player.inventory.current = 0;
}


void print_player(Player player)
{
	printf("Name: %s\n", player.name);
	printf("Player health: %d/%d\n", player.health.cur_health, player.health.max_health);
	printf("Player damage: %d\n", player.damage);
	printf("Player weapon damage: %d\n", player.weapon_dmg);
	printf("player coins: %d\n", player.coins);
}


void init_monster(Monster& monster, const char* type, int damage, int health)
{
	monster.damage = damage;
	monster.type = type;
	monster.health.max_health = health;
	monster.health.cur_health = health;
}


void print_monster(Monster monster)
{
	printf("Type: %s\n", monster.type);
	printf("Monster damage: %d\n", monster.damage);
	printf("Monster health: %d/%d\n", monster.health.cur_health, monster.health.max_health);
}


void manster_attack(Monster& monster, Player& player)
{
	if (monster.health.cur_health >= 0)
	{
		printf("Monster attacked\n");
		player.health.cur_health -= monster.damage;
	}
	if (player.health.cur_health <= 0)
	{
		printf("Player is dead\n");
		player.is_alive = false;
	}
}


void player_attack(Monster& monster, Player& player)
{
	if (player.health.cur_health >= 0)
	{
		printf("Player attacked\n");
		monster.health.cur_health -= (player.damage + player.weapon_dmg);
	}
	if (monster.health.cur_health <= 0)
	{
		printf("Monster is dead\n");
		monster.is_alive = false;
	}
}


void battle(Player& player, const char* type, int m_dmg, int m_health, int coins)
{
	Monster monster;
	init_monster(monster, type, m_dmg, m_health);
	while (monster.is_alive && player.is_alive)
	{
		print_player(player);
		printf("\n");
		print_monster(monster);
		printf("\n");
		player_attack(monster, player);
		printf("\n");
		if (monster.is_alive)
		{
			manster_attack(monster, player);
			if (player.is_alive) {
				printf("\nclick to continue\n\n");
				while (getchar() != '\n');
			}
		}
		else {
			printf("\nclick to continue\n\n");
			while (getchar() != '\n');
		}
	}
	if (player.is_alive == 0)
		exit(0);

	player.coins += coins;
}


void get_potion(Player& player, const char* type, int health_res)
{
	Cell potion;
	potion.potion.type = type;
	potion.potion.health_res = health_res;
	if (player.inventory.count < 6)
	{
		player.inventory.invent[player.inventory.current] = potion;
		player.inventory.current++;
		player.inventory.count++;
	}
}


void get_weapon(Player& player, const char* name_weapon, int weapon_dmg)
{
	Cell weapon;
	weapon.weapon.type = name_weapon;
	weapon.weapon.weapon_dmg = weapon_dmg;
	if (player.inventory.count < 6)
	{
		player.inventory.invent[player.inventory.current] = weapon;
		player.inventory.current++;
		player.inventory.count++;
	}
}


void Finding_potion(Player& player, int type)
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


void Finding_weapon(Player& player)
{
	srand(time(0));
	int type = rand() % 2;
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


void Print_inventory(Player player)
{
	if (player.inventory.current != 0) {
		printf("\n___________INVENTORY___________\n");
		for (int i = 0; i < player.inventory.count; i++)
		{
			if (player.inventory.invent[i].potion.health_res > 0)
			{
				printf("_______________________________\n");
				printf("%d: Type: % s\n", i + 1, player.inventory.invent[i].potion.type);
				printf("Health_res: %d\n", player.inventory.invent[i].potion.health_res);
				printf("_______________________________\n");
			}
			else
			{
				printf("_______________________________\n");
				printf("%d: Type: % s\n", i + 1, player.inventory.invent[i].weapon.type);
				printf("Weapon_dmg: %d\n", player.inventory.invent[i].weapon.weapon_dmg);
				printf("_______________________________\n");
			}
		}
	}
}


void Shop(Player& player)
{
	print_player(player);
	printf("\nYou have entered the store!\n");
	printf("1)Exit the store\n");
	printf("You can:\n2)Restore lives(20 coins)\n3)Increase the attack(+5)(30 coins)\n\n");
	int k;
	do {
		scanf_s("%d", &k);
	} while (k < 1 || k > 3);
	switch (k)
	{
	case 1:
	{
		break;
	}
	case 2:
	{
		if (player.coins >= 20)
		{
			player.health.cur_health = player.health.max_health;
			player.coins -= 20;
		}
		else
		{
			printf("You don't have enough coins\n");
		}
		break;
	}
	case 3:
	{
		if (player.coins >= 30)
		{
			player.damage += 5;
			player.coins -= 30;
		}
		else
		{
			printf("You don't have enough coins\n");
		}
		break;
	}
	}
}


int Choosing_weapon(Player& player)
{
	printf("Choose the weapon you want to pick up\n\n");

	Print_inventory(player);

	int cnt = 0;

	for (int i = 0, cnt = 0; i <= 6; i++)
	{
		if (player.inventory.invent[i].weapon.weapon_dmg == 0)
			cnt += 1;
	}

	if (cnt == 6)
	{
		printf("You don't have a weapon\n\n");
		return 1;
	}

	int k;

	do {
		scanf_s("%d", &k);
	} while (k < 1 || k > 6);
	printf("\n");
	if (player.inventory.invent[k - 1].weapon.weapon_dmg != 0)
		player.weapon_dmg = player.inventory.invent[k - 1].weapon.weapon_dmg;
	else
		printf("It's not a weapon\n\n");

	while (getchar() != '\n');
	return 0;
}


int Restoring_health(Player& player)
{
	printf("Select the potion you want to use\n");

	Print_inventory(player);

	int cnt = 0;

	for (int i = 0; i <= 6; i++)
	{
		printf("%d", i);
		if (player.inventory.invent[i].potion.health_res == 0)
			cnt += 1;
	}

	if (cnt == 6)
	{
		printf("You don't have a potion\n\n");
		return 1;
	}

	int k;
	Cell vrem;
	do {
		scanf_s("%d", &k);
	} while (k < 1 || k > 6);
	printf("\n");
	if (player.inventory.invent[k - 1].potion.health_res != 0)
	{
		player.health.cur_health += player.inventory.invent[k - 1].potion.health_res;

		if (player.health.cur_health > 100)
			player.health.cur_health = 100;
		player.inventory.invent[k - 1] = vrem;
		player.inventory.count--;
		player.inventory.current--;
	}
	else
		printf("It's not a potion\n\n");

	while (getchar() != '\n');
	return 0;
}


void Menu(Player& player)
{
	int k;
	do {
		do {
			print_player(player);
			printf("\nSelect an action:\n");
			printf("1)Drink a potion:\n");
			printf("2)Choose a weapon:\n");
			printf("3)Enter the store:\n");
			printf("4)Fight the next enemy:\n");
			scanf_s("%d", &k);
		} while (k < 1 || k > 4);

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
			break;
		}
		}
	} while (k < 4);
	while (getchar() != '\n');
}


int main()
{
	Player player;
	init_player(player, "Steve");
	Menu(player);
	battle(player, "Zombie", 5, 20, 10);
	Menu(player);
	battle(player, "Zombie", 10, 30, 20);
	Menu(player);
	Finding_potion(player, 0);
	Menu(player);
	battle(player, "Skeleton", 15, 40, 30);
	Menu(player);
	Finding_weapon(player);
	Menu(player);
	battle(player, "Boss", 30, 50, 100);
	printf("\nYou've won\n");
	print_player(player);
}