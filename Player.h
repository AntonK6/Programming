#pragma once
#include "Health.h"
#include "Inventory.h"

#include <stdio.h>
#include <iostream>
#include <string>


class Player
{
	Inventory* inventory = new Inventory;
	Health* health = new Health{ 100 };
	std::string name;
	int damage = 5;
	int weapon_dmg = 0;
	bool is_alive = true;
	int coins = 0;
	
public:
	Player(std::string iname = "Steve")
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
		delete health;
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


	//-------------------------------
	//-----��������� �����----------
	//-------------------------------
	void operator+ (int dmg)
	{
		this->damage += dmg;
	}


	//----------------------------------------
	//-----���������� ���������� ������------
	//----------------------------------------
	int Player_get_cur_health() { return health->Get_cur_health(); }
	int Get_player_dmg() const { return damage + weapon_dmg; }
	bool Player_alive() const { return is_alive; }


	//-------------------------------
	//-----����� �������� ����------
	//-------------------------------
	void Player_taking(int dmg) { health->Health_dmg(dmg); }


	//-----------------
	//-----������------
	//-----------------
	void Player_set_coins(int coin_cnt) { coins += coin_cnt; }


	//------------------
	//-----�������------
	//------------------
	void Player_heal() { health->Heal(); }
	void Player_potion_heal(int heal) { health->Potion_heal(heal); }


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
		std::cout << "Name: " << this->name << std::endl;
		std::cout << "Player health: " << this->health->Get_cur_health() << "/" << this->health->Get_max_health() << std::endl;
		std::cout << "Player damage: " << this->damage << std::endl;
		std::cout << "Player weapon damage: " << this->weapon_dmg << std::endl;
		std::cout << "player coins: " << this->coins << std::endl;
	}
};
