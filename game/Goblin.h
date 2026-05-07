#pragma once
#include "monster.h"
class Goblin : public monster
{
public:
	Goblin();
	Goblin(std::string name, int hp, int power, int defence, std::string dropitemname, int dorpitemprice);
	void attack(class player* target) override;
};

