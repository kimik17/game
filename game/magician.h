#pragma once
#include "player.h"

class magician : public player
{
public:
	magician(string name, int hp, int mp, int power, int defence);
	void attack(monster* target) override;
};