#pragma once
#include "player.h"

class warrior : public player
{
public:
	warrior(string name, int hp, int mp, int power, int defence);
	void attack(monster* target) override;
};
