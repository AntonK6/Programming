#pragma once

#define MONSTERDEF

#ifdef MONSTERDEF

#include "Health.h"

class Monster
{
	Health health;
	const char* type;
	int damage;
	bool is_alive = true;

public:
	Monster(int health = 15, int dmg = 5, const char* type = "Zombie") : type(type), health{ health , health }
	{
		damage = dmg;
		is_alive = true;
	}

	int Monster_get_cur_health() { return health.Get_cur_health(); }
	int Get_monster_dmg() { return damage; }
	void Monster_dead() { is_alive = false; }
	bool Monster_alive() { return is_alive; }
	void Monster_taking(int dmg) { health.Health_dmg(dmg); }

	void Print_monster(Monster& monster)
	{
		printf("type: %s\n", monster.type);
		printf("Monster health: %d/%d\n", monster.health.Get_cur_health(), monster.health.Get_max_health());
		printf("Monster damage: %d\n", monster.damage);
	}
};

#endif