#include "Inventory.h"

int Inventory::count = 0;

int Inventory::Invent_subtract()
{
	int cnt = 0;

	for (int i = 0; i < 6; i++)
	{
		if (Weapon_get_weapon_dmg(Get_cell(i)) != 0 || Potion_get_health_res(Get_cell(i)) != 0)
			cnt += 1;

	}

	if (cnt == 0)
	{
		std::cout << "The inventory is empty\n" << std::endl;
		return 0;
	}

	int num;
	do {
		scanf_s("%d", &num);
	} while (num < 1 || num > 6);

	Cell vrem;
	if (num == 6) { invent[num - 1] = vrem; }
	for (int i = num; i < 6; i++)
	{
		invent[i - 1] = invent[i];
	}
	count--;
};

int Inventory::Invent_subtract(int num)
{
	int cnt = 0;

	for (int i = 0; i < 6; i++)
	{
		if (Weapon_get_weapon_dmg(Get_cell(i)) != 0 || Potion_get_health_res(Get_cell(i)) != 0)
			cnt += 1;

	}

	if (cnt == 0)
	{
		std::cout << "The inventory is empty\n" << std::endl;
		return 0;
	}

	Cell vrem;
	if (num == 6) { invent[num - 1] = vrem; }
	for (int i = num; i < 6; i++)
	{
		invent[i - 1] = invent[i];
	}
	count--;
};