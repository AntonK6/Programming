#pragma once
#include "Health.h"

class Monster
{
	Health health;
	const char* type;
	int damage = 0;
	bool is_alive = true;

public:
	Monster(int health = 15, int dmg = 5, const char* type = "Zombie") : type(type), health{ health , health }
	{
		damage = dmg;
		is_alive = true;
	}


	//----------------------------------------
	//-----Возвращают показатели монстра------
	//----------------------------------------
	int Monster_get_cur_health() { return health.Get_cur_health(); }
	int Get_monster_dmg() { return damage; }


	//----------------------
	//-----Монстр умер------
	//----------------------
	void Monster_dead() { is_alive = false; }


	//------------------------------------
	//-----Проверка монстра на жизнь------
	//------------------------------------
	bool Monster_alive() { return is_alive; }


	//-------------------------------
	//-----Монстр получает урон------
	//-------------------------------
	void Monster_taking(int dmg) { health.Health_dmg(dmg); }


	//----------------------------------------------
	//-----Выводит показатели монстра на экран------
	//----------------------------------------------
	void Print_monster(Monster& monster)
	{
		printf("type: %s\n", monster.type);
		printf("Monster health: %d/%d\n", monster.health.Get_cur_health(), monster.health.Get_max_health());
		printf("Monster damage: %d\n", monster.damage);
	}
};