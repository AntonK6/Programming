#pragma once
#include "Cell.h"

#include <stdio.h>

class Inventory
{
	Cell invent[6];
	int count = 0;
	int current = 0;

public:

	int Get_count() { return count; };
	int Get_current() { return current; };

	void Invent_add(Cell& cell)
	{
		invent[current] = cell;
		count++;
		current++;
	};
	void Invent_subtract()
	{
		Cell vrem;
		invent[current] = vrem;
		count--;
		current--;
	};

	const char* Potion_get_type(Cell& cell) { return cell.Potion_get_type(); }
	int Potion_get_health_res(Cell& cell) { return cell.Potion_get_health_res(); }
	const char* Weapon_get_type(Cell& cell) { return cell.Weapon_get_type(); }
	int Weapon_get_weapon_dmg(Cell& cell) { return cell.Weapon_get_weapon_dmg(); }

	Cell Get_cell(int i) { return invent[i]; }

	void Print_inventory()
	{
		if (current != 0) {
			printf("\n___________INVENTORY___________\n");
			for (int i = 0; i < count; i++)
			{
				if (this->Potion_get_health_res(invent[i]) > 0)
				{
					printf("_______________________________\n");
					printf("%d: Type: % s\n", i + 1, this->Potion_get_type(invent[i]));
					printf("Health_res: %d\n", this->Potion_get_health_res(invent[i]));
					printf("_______________________________\n");
				}
				else
				{
					printf("_______________________________\n");
					printf("%d: Type: % s\n", i + 1, this->Weapon_get_type(invent[i]));
					printf("Weapon_dmg: %d\n", this->Weapon_get_weapon_dmg(invent[i]));
					printf("_______________________________\n");
				}
			}
		}
	}
};

