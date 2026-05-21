#include "Goblin.h"
#include "player.h"
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
	int mhp = target->gethp();
	int damage = power - target->getdefence();
	if (damage <= 0) damage = 1;

	target->sethp(target->gethp() - damage);
	cout << "고블린이 검을 휘둘렀다" << endl;
	cout << damage << "의 피해를 입었다." << endl;
	if (target->gethp() <= 0) {
		cout << target->getname() << " HP: " << mhp << "->" << target->gethp() << " (사망)" << endl;
	}
	else {
		cout << target->getname() << " HP: " << mhp << "->" << target->gethp() << endl;
	}
	cout << endl;
}