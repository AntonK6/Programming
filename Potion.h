#pragma once
class Potion
{
	const char* type;
	int health_res = 0;

public:
	void Potion_set_type(const char* type_potion) { type = type_potion; }
	void Potion_set_health_res(int health_res_potion) { health_res = health_res_potion; }

	const char* Potion_get_type() { return type; }
	int Potion_get_health_res() { return health_res; }
};

