#pragma once
#include "Health.h"
#include "Inventory.h"

#include <stdio.h>
#include <iostream>
#include <string>


class Player: Health
{
	Inventory* inventory = new Inventory;
	std::string name;
	int damage = 5;
	int weapon_dmg = 0;
	bool is_alive = true;
	int coins = 0;
	
public:
	Player(std::string iname = "Steve", int health = 100): Health(health)
	{
		name = iname;
		damage = 5;
		weapon_dmg = 0;
		is_alive = true;
		coins = 0;
	}


	~Player()
	{
		delete inventory;
	}


	Player operator=(Health& health)
	{
		Player player{ "Steve", health.Get_cur_health() };

		return player;
	}


	//---------------------
	//-----����� ����------
	//---------------------
	void Player_dead() { is_alive = false; }


	//-------------------------------
	//-----��������� ������----------
	//-------------------------------
	friend Player& operator++(Player& player);			// ����������
	friend Player& operator++(Player& player, int);		// �����������


	//---------------------------------
	//-----��������� ��������----------
	//---------------------------------
	void Heal_lvlup(int hp) { max_health += hp; cur_health = max_health; }


	//-------------------------------
	//-----��������� �����-----------
	//-------------------------------
	void operator+ (int dmg)
	{
		this->damage += dmg;
	}


	//----------------------------------------
	//-----���������� ���������� ������------
	//----------------------------------------
	int Player_get_cur_health() { return cur_health; }
	int Get_player_dmg() const { return damage + weapon_dmg; }
	bool Player_alive() const { return is_alive; }


	//-------------------------------
	//-----����� �������� ����------
	//-------------------------------
	void Player_taking(int dmg) { cur_health -= dmg; }


	//-----------------
	//-----������------
	//-----------------
	void Player_set_coins(int coin_cnt) { coins += coin_cnt; }


	//------------------
	//-----�������------
	//------------------
	void Player_heal() { cur_health = max_health; }
	void Player_potion_heal(int heal) { cur_health += heal; }


	//--------------------------------------
	//-----���������� ������ ���������------
	//--------------------------------------
	Cell& Get_cell(int i) { return inventory->Get_cell(i); }


	//------------------------------------------
	//-----���������� �������� � ���������------
	//------------------------------------------
	void Invent_add(Cell& cell) { inventory->Invent_add(cell); }


	//-----------------------------------------
	//-----�������� �������� �� ���������------
	//-----------------------------------------
	void Invent_subtract() { inventory->Invent_subtract(); }


	//-------------------------------------
	//-----������� ��������� �� �����------
	//-------------------------------------
	void Print_inventory() { inventory->Print_inventory(); }


	//---------------------------------------------------
	//-----����� ��������, ����� ����� ������������------
	//---------------------------------------------------
	int Restoring_health();


	//----------------------------------------------------
	//-----����� ��������, ����� ������ ������������------
	//----------------------------------------------------
	int Choosing_weapon();


	//-----------------------------------------------------------------------------------
	//-----�������(����� ������������ ����� ��� ��������� dmg ��� �������� �������)------
	//-----------------------------------------------------------------------------------
	void Shop();


	//---------------------------------------------
	//-----������� ���������� ������ �� �����------
	//---------------------------------------------
	void Print_player()
	{
		std::cout << "Name: " << name << std::endl;
		std::cout << "Player health: " << cur_health << "/" << max_health << std::endl;
		std::cout << "Player damage: " << damage << std::endl;
		std::cout << "Player weapon damage: " << weapon_dmg << std::endl;
		std::cout << "player coins: " << coins << std::endl;
	}
};
