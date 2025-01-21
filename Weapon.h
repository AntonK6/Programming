#pragma once
class Weapon
{
	const char* type = "";
	int weapon_dmg = 0;

public:
	//----------------------------------------
	//-----Установка значений для оружия------
	//----------------------------------------
	void Weapon_set_type(const char* type_weapon) { type = type_weapon; }
	void Weapon_set_health_res(int weapon_dmg_weapon) { weapon_dmg = weapon_dmg_weapon; }


	//-------------------------------------
	//-----Возвращают значения оружия------
	//-------------------------------------
	const char* Weapon_get_type() const { return type; }
	int Weapon_get_weapon_dmg() const { return weapon_dmg; }
};

