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
	//-----Игрок умер------
	//---------------------
	void Player_dead() { is_alive = false; }


	//-------------------------------
	//-----Повышение уровня----------
	//-------------------------------
	friend Player& operator++(Player& player);			// префиксный
	friend Player& operator++(Player& player, int);		// постфиксный


	//---------------------------------
	//-----Повышение здоровья----------
	//---------------------------------
	void Heal_lvlup(int hp) { max_health += hp; cur_health = max_health; }


	//-------------------------------
	//-----Повышение урона-----------
	//-------------------------------
	void operator+ (int dmg)
	{
		this->damage += dmg;
	}


	//----------------------------------------
	//-----Возвращают показатели игрока------
	//----------------------------------------
	int Player_get_cur_health() { return cur_health; }
	int Get_player_dmg() const { return damage + weapon_dmg; }
	bool Player_alive() const { return is_alive; }


	//-------------------------------
	//-----Игрок получает урон------
	//-------------------------------
	void Player_taking(int dmg) { cur_health -= dmg; }


	//-----------------
	//-----Монеты------
	//-----------------
	void Player_set_coins(int coin_cnt) { coins += coin_cnt; }


	//------------------
	//-----Лечение------
	//------------------
	void Player_heal() { cur_health = max_health; }
	void Player_potion_heal(int heal) { cur_health += heal; }


	//--------------------------------------
	//-----Возвращает ячейку инвентаря------
	//--------------------------------------
	Cell& Get_cell(int i) { return inventory->Get_cell(i); }


	//------------------------------------------
	//-----Добавление предмета в инвентарь------
	//------------------------------------------
	void Invent_add(Cell& cell) { inventory->Invent_add(cell); }


	//-----------------------------------------
	//-----Удаление предмета из инвентаря------
	//-----------------------------------------
	void Invent_subtract() { inventory->Invent_subtract(); }


	//-------------------------------------
	//-----Выводит интентарь на экран------
	//-------------------------------------
	void Print_inventory() { inventory->Print_inventory(); }


	//---------------------------------------------------
	//-----Игрок выбирает, какое зелье использовать------
	//---------------------------------------------------
	int Restoring_health();


	//----------------------------------------------------
	//-----Игрок выбирает, какое оружие использовать------
	//----------------------------------------------------
	int Choosing_weapon();


	//-----------------------------------------------------------------------------------
	//-----Магазин(может восстановить жизни или увеличить dmg или повысить уровень)------
	//-----------------------------------------------------------------------------------
	void Shop();


	//---------------------------------------------
	//-----Выводит показатели игрока на экран------
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
