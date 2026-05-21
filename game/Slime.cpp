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
	int mhp = target->gethp();
	int damage = power - target->getdefence();
	if (damage <= 0) damage = 1;

	target->sethp(target->gethp() - damage);
	cout << "슬라임이 산성 침을 발사했다" << endl;
	cout << damage << "의 피해를 입었다." << endl;
	if (target->gethp() <= 0) {
		cout << target->getname() << " HP: " << mhp << "->" << target->gethp() << " (사망)" << endl;
	}
	else {
		cout << target->getname() << " HP: " << mhp << "->" << target->gethp() << endl;
	}
	cout << endl;
}