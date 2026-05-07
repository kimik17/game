#pragma once
#include "monster.h"

class Slime : public monster
{
public:
	Slime();
	Slime(std::string name, int hp, int power, int defence, std::string dropitemname, int dropitemprice);
	void attack(class player* target) override;
};

