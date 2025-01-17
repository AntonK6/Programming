#pragma once
#include "Weapon.h"
#include "Potion.h"

class Cell
{
	Weapon weapon;
	Potion potion;

public:
	void Potion_set_type(const char* type_potion) { potion.Potion_set_type(type_potion); }
	void Potion_set_health_res(int health_res_potion) { potion.Potion_set_health_res(health_res_potion); }

	void Weapon_set_type(const char* type_weapon) { weapon.Weapon_set_type(type_weapon); }
	void Weapon_set_weapon_dmg(int weapon_dmg_weapon) { weapon.Weapon_set_health_res(weapon_dmg_weapon); }

	const char* Potion_get_type() { return potion.Potion_get_type(); }
	int Potion_get_health_res() { return potion.Potion_get_health_res(); }
	const char* Weapon_get_type() { return weapon.Weapon_get_type(); }
	int Weapon_get_weapon_dmg() { return weapon.Weapon_get_weapon_dmg(); }
};

