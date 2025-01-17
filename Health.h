#pragma once
#include <stdio.h>

class Health
{
	int max_health = 0;
	int cur_health = 0;

public:
	Health(int cur = 100, int max = 100) : max_health(max), cur_health(cur)
	{ }
	
	int Get_max_health() { return max_health; }
	int Get_cur_health() { return cur_health; }

	void Heal() { cur_health = max_health; }
	void Potion_heal(int heal) { cur_health + heal; }

	void Health_dmg(int dmg) { cur_health -= dmg; }
};