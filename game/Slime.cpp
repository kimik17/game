#include "player.h"
#include "Slime.h"
#include <string>

Slime::Slime()
	: monster("슬라임", 30, 20, 10, "", 0) 
{
	int random = rand() % 2;

	if (random == 0)
	{
		this->dropitemname = "슬라임의 핵";
		this->dropitemprice = 50;
	}
	else
	{
		this->dropitemname = "슬라임의 점액";
		this->dropitemprice = 10;
	}
}

void Slime::attack(class player* target)
{
	cout << "슬라임이 산성 침을 발사했다";
}