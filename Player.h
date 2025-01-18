#pragma once
#include "Health.h"
#include "Inventory.h"

#include <stdio.h>


class Player
{
	Inventory* inventory = new Inventory;
	Health* health = new Health{ 100, 100 };
	const char* name;
	int damage = 5;
	int weapon_dmg = 0;
	bool is_alive = true;
	int coins = 0;
	
public:
	Player(const char* name = "Steve") : name(name)
	{
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
	//-----Игрок умер------
	//---------------------
	void Player_dead() { is_alive = false; }


	//----------------------------------------
	//-----Возвращают показатели монстра------
	//----------------------------------------
	int Player_get_cur_health() { return health->Get_cur_health(); }
	int Get_player_dmg() { return damage + weapon_dmg; }
	bool Player_alive() { return is_alive; }


	//-------------------------------
	//-----Игрок получает урон------
	//-------------------------------
	void Player_taking(int dmg) { health->Health_dmg(dmg); }


	//-----------------
	//-----Монеты------
	//-----------------
	void Player_set_coins(int coin_cnt) { coins += coin_cnt; }
	int Player_get_coins() { return coins; }


	//------------------
	//-----Лечение------
	//------------------
	void Player_heal() { health->Heal(); }
	void Player_potion_heal(int heal) { health->Potion_heal(heal); }


	//-------------------------------
	//-----Увеличить dmg игрока------
	//-------------------------------
	void Player_updmg(int dmg) { damage += dmg; }


	//--------------------------------
	//-----Установить dmg оружия------
	//--------------------------------
	void Player_set_weapondmg(int dmg) { weapon_dmg = dmg; }


	//--------------------------------------
	//-----Возвращает ячейку инвентаря------
	//--------------------------------------
	Cell Get_cell(int i) { return inventory->Get_cell(i); }


	//---------------------------------------------------
	//-----Возвращают значения количества предметов------
	//---------------------------------------------------
	int Get_inventory_count() { return inventory->Get_count(); }
	int Get_inventory_current() { return inventory->Get_current(); }


	//------------------------------------------
	//-----Добавление предмета в инвентарь------
	//------------------------------------------
	void Invent_add(Cell& cell) { inventory->Invent_add(cell); }


	//-----------------------------------------
	//-----Удаление предмета из инвентаря------
	//-----------------------------------------
	void Invent_subtract() { inventory->Invent_subtract(); }


	//---------------------------------------------
	//-----Возвращают значения зелья и оружия------
	//---------------------------------------------
	const char* Potion_get_type(Cell& cell) { return inventory->Potion_get_type(cell); }
	int Potion_get_health_res(Cell& cell) { return inventory->Potion_get_health_res(cell); }
	const char* Weapon_get_type(Cell& cell) { return inventory->Weapon_get_type(cell); }
	int Weapon_get_weapon_dmg(Cell& cell) { return inventory->Weapon_get_weapon_dmg(cell); }


	//-------------------------------------
	//-----Выводит интентарь на экран------
	//-------------------------------------
	void Print_inventory(Player& player) { inventory->Print_inventory(); }


	//---------------------------------------------
	//-----Выводит показатели игрока на экран------
	//---------------------------------------------
	void Print_player(Player& player)
	{
		printf("Name: %s\n", player.name);
		printf("Player health: %d/%d\n", player.health->Get_cur_health(), player.health->Get_max_health());
		printf("Player damage: %d\n", player.damage);
		printf("Player weapon damage: %d\n", player.weapon_dmg);
		printf("player coins: %d\n", player.coins);
	}
};