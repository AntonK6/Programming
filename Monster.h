#pragma once
#include "Health.h"

#include <string>
#include <iostream>

class Monster
{
	Health health;
	std::string type;
	int damage = 0;
	bool is_alive = true;

public:
	Monster(int health = 15, int dmg = 5, std::string type1 = "Zombie"): health{ health }
	{
		try {
			if (dmg <= 0)
				throw 5;
			type = type1;
			damage = dmg;
			is_alive = true;
		}
		catch(int k)
		{
			damage = k;
		}
	}

	//----------------------------
	//-----Параметры монстра------
	//----------------------------
	void Monster_init(int m_health, int m_dmg, std::string type)
	{
		this->damage = m_dmg;
		this->type = type;
		this->health = m_health;
	}


	//----------------------------------------
	//-----Возвращают показатели монстра------
	//----------------------------------------
	int Monster_get_cur_health() { return health.Get_cur_health(); }
	int Get_monster_dmg() const { return damage; }


	//----------------------
	//-----Монстр умер------
	//----------------------
	void Monster_dead() { is_alive = false; }


	//------------------------------------
	//-----Проверка монстра на жизнь------
	//------------------------------------
	bool Monster_alive() const { return is_alive; }


	//-------------------------------
	//-----Монстр получает урон------
	//-------------------------------
	void Monster_taking(int dmg) { health.Health_dmg(dmg); }


	//----------------------------------------------
	//-----Выводит показатели монстра на экран------
	//----------------------------------------------
	static void Print_monster(Monster& monster)
	{
		std::cout<<"type: " + monster.type<<std::endl;
		printf("Monster health: %d/%d\n", monster.health.Get_cur_health(), monster.health.Get_max_health());
		printf("Monster damage: %d\n", monster.damage);
	}
};