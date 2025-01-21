#include "Monster.h"


//---------------------------------
//---------Атака монстра-----------
//---------------------------------
void Monster::Monster_attack(Player& player)
{
	if (health.Get_cur_health() >= 0)
	{
		std::cout << "Monster attacked" << std::endl;
		player.Player_taking(damage);
	}
	if (player.Player_get_cur_health() <= 0)
	{
		std::cout << "Player is dead" << std::endl;
		player.Player_dead();
	}
}


//---------------------------------
//---------Атака игрока------------
//---------------------------------
void Monster::Player_attack(Player& player)
{
	if (player.Player_get_cur_health() >= 0)
	{
		std::cout << "Player attacked" << std::endl;
		health.Health_dmg(player.Get_player_dmg());
	}
	if (this->Monster_get_cur_health() <= 0)
	{
		std::cout << "Monster is dead" << std::endl;
		is_alive = false;
	}
}