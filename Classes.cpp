#include <iostream>
#include <stdio.h>
#include <stdbool.h>


struct Health
{
	int max_health = 0;
	int cur_health = 0;
};


struct Monster
{
	Health health;
	const char* type;
	int damage;
	bool is_alive = true;
};


struct Potion
{
	const char* type;
	int health_res = 0;
};

struct Weapon
{
	const char* type;
	int weapon_dmg = 0;
};


struct Cell
{
	Weapon weapon;
	Potion potion;
};


struct Inventory
{
	Cell invent[6];
	int count = 0;
	int current = 0;
};


struct Player
{
	const char* name;
	Health health;
	int damage = 5;
	int weapon_dmg = 0;
	bool is_alive = true;
	int coins = 0;
	Inventory inventory;
};