#pragma once
#include "Health.h"
#include "Player.h"

#include <string>
#include <iostream>

class Monster: Health
{
	std::string type;
	int damage = 0;
	bool is_alive = true;

public:
	Monster(int health = 15, int dmg = 5, std::string type1 = "Zombie"): Health(health)
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
		damage = m_dmg;
		type = type;
		max_health = m_health;
		cur_health = m_health;
	}


	//---------------------------------
	//---------����� �������-----------
	//---------------------------------
	void Monster_attack(Player& player);


	//---------------------------------
	//---------����� ������------------
	//---------------------------------
	void Player_attack(Player& player);


	//----------------------------------------
	//-----���������� ���������� �������------
	//----------------------------------------
	int Monster_get_cur_health() { return cur_health; }
	int Get_monster_dmg() const { return damage; }


	//------------------------------------
	//-----�������� ������� �� �����------
	//------------------------------------
	bool Monster_alive() const { return is_alive; }


	//-------------------------------
	//-----������ �������� ����------
	//-------------------------------
	void Monster_taking(int dmg) { cur_health -= dmg; }


	//----------------------------------------------
	//-----������� ���������� ������� �� �����------
	//----------------------------------------------
	void Print_monster()
	{
		std::cout<<"type: " + type << std::endl;
		std::cout << "Monster health: " << cur_health<< "/" << max_health << std::endl;
		std::cout << "Monster damage: " << damage << std::endl;
	}
};