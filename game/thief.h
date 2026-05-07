#pragma once
#include "player.h"

class thief : public player
{
public:
	thief(string name, int hp, int mp, int power, int defence);
	void attack(monster* target) override;
};