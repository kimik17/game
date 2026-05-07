#pragma once
#include "player.h"

class archer : public player
{
public:
	archer(string name, int hp, int mp, int power, int defence);
	void attack(monster* target) override;
};