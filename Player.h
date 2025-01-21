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
	int Player_get_coins() const { return coins; }


	//------------------
	//-----�������------
	//------------------
	void Player_heal() { health->Heal(); }
	void Player_potion_heal(int heal) { health->Potion_heal(heal); }


	//--------------------------------
	//-----���������� dmg ������------
	//--------------------------------
	void Player_set_weapondmg(int dmg) { weapon_dmg = dmg; }


	//--------------------------------------
	//-----���������� ������ ���������------
	//--------------------------------------
	Cell& Get_cell(int i) { return inventory->Get_cell(i); }


	//---------------------------------------------------
	//-----���������� �������� ���������� ���������------
	//---------------------------------------------------
	int Get_inventory_count() { return inventory->Get_count(); }


	//------------------------------------------
	//-----���������� �������� � ���������------
	//------------------------------------------
	void Invent_add(Cell& cell) { inventory->Invent_add(cell); }


	//-----------------------------------------
	//-----�������� �������� �� ���������------
	//-----------------------------------------
	void Invent_subtract(int k) { inventory->Invent_subtract(k); }


	//---------------------------------------------
	//-----���������� �������� ����� � ������------
	//---------------------------------------------
	const char* Potion_get_type(Cell& cell) { return inventory->Potion_get_type(cell); }
	int Potion_get_health_res(Cell& cell) { return inventory->Potion_get_health_res(cell); }
	const char* Weapon_get_type(Cell& cell) { return inventory->Weapon_get_type(cell); }
	int Weapon_get_weapon_dmg(Cell& cell) { return inventory->Weapon_get_weapon_dmg(cell); }


	//-------------------------------------
	//-----������� ��������� �� �����------
	//-------------------------------------
	void Print_inventory(Player& player) { inventory->Print_inventory(); }


	//---------------------------------------------
	//-----������� ���������� ������ �� �����------
	//---------------------------------------------
	static void Print_player(Player& player)
	{
		std::cout << "Name: " + player.name << std::endl;
		printf("Player health: %d/%d\n", player.health->Get_cur_health(), player.health->Get_max_health());
		printf("Player damage: %d\n", player.damage);
		printf("Player weapon damage: %d\n", player.weapon_dmg);
		printf("player coins: %d\n", player.coins);
	}
};
