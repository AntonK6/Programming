#pragma once
#include <stdio.h>

class Health
{
protected:
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


	int Get_cur_health() { return cur_health; }
	int Get_max_health() { return max_health; }


	//---------------------------------
	//-----Повышение здоровья----------
	//---------------------------------
	virtual void Heal_lvlup() { max_health += 5; cur_health = max_health; }


	//------------------	
	//-----Лечение------ 
	//------------------
	void Heal() { cur_health = max_health; }
};