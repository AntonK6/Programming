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
	//-----��������� �������------
	//----------------------------
	void Monster_init(int m_health, int m_dmg, std::string type)
	{
		this->damage = m_dmg;
		this->type = type;
		this->health = m_health;
	}


	//----------------------------------------
	//-----���������� ���������� �������------
	//----------------------------------------
	int Monster_get_cur_health() { return health.Get_cur_health(); }
	int Get_monster_dmg() const { return damage; }


	//----------------------
	//-----������ ����------
	//----------------------
	void Monster_dead() { is_alive = false; }


	//------------------------------------
	//-----�������� ������� �� �����------
	//------------------------------------
	bool Monster_alive() const { return is_alive; }


	//-------------------------------
	//-----������ �������� ����------
	//-------------------------------
	void Monster_taking(int dmg) { health.Health_dmg(dmg); }


	//----------------------------------------------
	//-----������� ���������� ������� �� �����------
	//----------------------------------------------
	static void Print_monster(Monster& monster)
	{
		std::cout<<"type: " + monster.type<<std::endl;
		printf("Monster health: %d/%d\n", monster.health.Get_cur_health(), monster.health.Get_max_health());
		printf("Monster damage: %d\n", monster.damage);
	}
};