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
	//-----���������� �������� �������� � ������������� ��������------
	//----------------------------------------------------------------
	int Get_max_health() const { return max_health; }
	int Get_cur_health() const { return cur_health; }


	//------------------
	//-----�������------
	//------------------
	void Heal() { cur_health = max_health; }
	void Potion_heal(int heal) { cur_health += heal; }


	//--------------------------
	//-----��������� �����------
	//--------------------------
	void Health_dmg(int dmg) { cur_health -= dmg; }
};