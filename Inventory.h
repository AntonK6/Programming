#pragma once
#include "Cell.h"

#include <stdio.h>
#include <iostream>

class Inventory
{
	static int count;
	Cell* invent = new Cell[6];

public:
	~Inventory()
	{
		delete[] invent;
	}


	//---------------------------------------------------
	//-----Возвращает значение количества предметов------
	//---------------------------------------------------
	static int Get_count() { return count; };


	//------------------------------------------
	//-----Добавление предмета в инвентарь------
	//------------------------------------------
	void Invent_add(Cell& cell)
	{
		invent[count] = cell;
		count++;
	};


	//-----------------------------------------
	//-----Удаление предмета из инвентаря------
	//-----------------------------------------
	int Invent_subtract();
	int Invent_subtract(int num);


	//---------------------------------------------
	//-----Возвращают значения зелья и оружия------
	//---------------------------------------------
	const char* Potion_get_type(Cell& cell) { return cell.Potion_get_type(); }
	int Potion_get_health_res(Cell& cell) { return cell.Potion_get_health_res(); }
	const char* Weapon_get_type(Cell& cell) { return cell.Weapon_get_type(); }
	int Weapon_get_weapon_dmg(Cell& cell) { return cell.Weapon_get_weapon_dmg(); }


	//--------------------------------------
	//-----Возвращает ячейку инвентаря------
	//--------------------------------------
	Cell& Get_cell(int i) const { return invent[i]; }


	//-------------------------------------
	//-----Выводит интентарь на экран------
	//-------------------------------------
	void Print_inventory()
	{
		if (count != 0) {
			std::cout << "\n___________INVENTORY___________" << std::endl;
			for (int i = 0; i < count; i++)
			{
				if (this->Potion_get_health_res(invent[i]) > 0)
				{
					std::cout << "_______________________________" << std::endl;
					std::cout << i + 1 << ": Type: " << this->Potion_get_type(invent[i]) << std::endl;
					std::cout << "Health_res: " << this->Potion_get_health_res(invent[i]) << std::endl;
					std::cout << "_______________________________" << std::endl;
				}
				else
				{
					std::cout << "_______________________________" << std::endl;
					std::cout << i + 1 << ": Type: " << this->Weapon_get_type(invent[i]) << std::endl;
					std::cout << "Weapon_dmg: " << this->Weapon_get_weapon_dmg(invent[i]) << std::endl;
					std::cout << "_______________________________" << std::endl;
				}
			}
		}
	}
};