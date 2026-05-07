#include "monster.h"
#include "Goblin.h"
#include <string>

Goblin::Goblin()
	: monster("고블린", 40, 25, 5, "", 0)
{
	int random = rand() % 3;

	if (random == 0)
	{
		this->dropitemname = "고블린 가죽";
		this->dropitemprice = 20;
	}
	else if (random == 1) {
		this->dropitemname = "약초";
		this->dropitemprice = 20;
	}
	else
	{
		this->dropitemname = "낡은 검";
		this->dropitemprice = 10;
	}
}

void Goblin::attack(class player* target)
{
	cout << "고블린이 검을 휘둘렀다" << endl;
}