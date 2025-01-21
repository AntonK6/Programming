#pragma once
#include <stdio.h>

class Health
{
	int max_health = 0;
	int cur_health = 0;

public:
	Health(int cur = 100)
	{
		try {
			if (cur <= 0)
				throw 20;
			max_health = cur;
			cur_health = cur;
		}
		catch (int k)
		{
			max_health = k;
			cur_health = k;
		}
		
	}
	

	//----------------------------------------------------------------
	//-----Возвращают значения текущего и максимального здоровья------
	//----------------------------------------------------------------
	int Get_max_health() const { return max_health; }
	int Get_cur_health() const { return cur_health; }


	//------------------
	//-----Лечение------
	//------------------
	void Heal() { cur_health = max_health; }
	void Potion_heal(int heal) { cur_health += heal; }


	//--------------------------
	//-----Получение урона------
	//--------------------------
	void Health_dmg(int dmg) { cur_health -= dmg; }
};