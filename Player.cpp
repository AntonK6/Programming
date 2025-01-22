#include "Player.h"

int Player::Restoring_health()
{
	int cnt = 0;

	for (int i = 0; i <= 5; i++)
	{
		if (inventory->Potion_get_health_res(inventory->Get_cell(i)) == 0)
			cnt += 1;
	}

	if (cnt == 6)
	{
		std::cout << "You don't have a potion\n" << std::endl;
		return 0;
	}

	this->Print_inventory();

	std::cout << "Select the potion you want to use" << std::endl;

	int k;
	Cell vrem;
	do {
		std::cin >> k;
	} while (k < 1 || k > 6);
	printf("\n");
	if (inventory->Potion_get_health_res(inventory->Get_cell(k - 1)) != 0)
	{
		this->Player_potion_heal(inventory->Potion_get_health_res(inventory->Get_cell(k - 1)));

		if (cur_health > 100)
			this->Player_heal();
		inventory->Invent_subtract(k);
	}
	else
		std::cout << "It's not a potion\n" << std::endl;

	return 0;
}


int Player::Choosing_weapon()
{
	int cnt = 0;

	for (int i = 0; i <= 5; i++)
	{
		if (inventory->Weapon_get_weapon_dmg(inventory->Get_cell(i)) == 0)
			cnt += 1;
	}

	if (cnt == 6)
	{
		std::cout << "You don't have a weapon\n" << std::endl;
		return 0;
	}

	this->Print_inventory();

	std::cout << "Choose the weapon you want to pick up\n" << std::endl;

	int k;

	do {
		scanf_s("%d", &k);
	} while (k < 1 || k > 6);
	printf("\n");

	if (inventory->Weapon_get_weapon_dmg(inventory->Get_cell(k - 1)) != 0)
		weapon_dmg = inventory->Weapon_get_weapon_dmg(inventory->Get_cell(k - 1));
	else
		std::cout << "It's not a weapon\n" << std::endl;

	while (getchar() != '\n');
	return 0;
}


void Player::Shop()
{
	this->Print_player();
	std::cout << "\nYou have entered the store!" << std::endl;
	std::cout << "1)Exit the store" << std::endl;
	std::cout << "You can:\n2)Restore lives(20 coins)\n3)Increase the attack(+10)(50 coins)\n4)Raise the level(dmg+5)(hp+5)(30 coins)\n5)Increase health(hp+15)(30 coins)\n" << std::endl;
	int k;
	do {
		scanf_s("%d", &k);
	} while (k < 1 || k > 5);
	switch (k)
	{
	case 1:
	{
		break;
	}
	case 2:
	{
		if (coins >= 20)
		{
			this->Player_heal();
			coins -= 20;
		}
		else
		{
			std::cout << "You don't have enough coins" << std::endl;
		}
		break;
	}
	case 3:
	{
		if (coins >= 50)
		{
			damage += 10;
			coins -= 50;
		}
		else
		{
			std::cout << "You don't have enough coins" << std::endl;
		}
		break;
	}
	case 4:
	{
		if (coins >= 30)
		{
			damage += 5;
			coins -= 30;
		}
		else
		{
			std::cout << "You don't have enough coins" << std::endl;
		}
		break;
	}
	case 5:
	{
		Heal_lvlup(15);
		break;
	}
	}
}


Player& operator++(Player& player) // префиксный
{
	std::cout << "Level up: вьп + 5" << std::endl;
	player.damage += 5;
	player.Health::Heal_lvlup();
	return player;
}

Player& operator++(Player& player, int) // постфиксный
{
	std::cout << "Level up: вьп + 5" << std::endl;
	player.damage += 5;
	player.Health::Heal_lvlup();
	return player;
}