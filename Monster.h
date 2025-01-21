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
	Monster(int health = 15, int dmg = 5, std::string type = "Zombie") : type(type), health{ health , health }
	{
		damage = dmg;
		is_alive = true;
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
	void Print_monster(Monster& monster)
	{
		std::cout<<"type: " + monster.type<<std::endl;
		printf("Monster health: %d/%d\n", monster.health.Get_cur_health(), monster.health.Get_max_health());
		printf("Monster damage: %d\n", monster.damage);
	}
};