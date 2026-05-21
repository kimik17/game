#include "thief.h"
#include "monster.h"

thief::thief(string name, int hp, int mp, int power, int defence)
	: player(name, hp + 30, mp, power, defence)
{
	this->job = "도적";
}
void thief::attack(monster* target)
{
	int php = target->gethp();
	int damage = (power - target->getdefence()) / 5;
	for (int i = 0; i < 5; i++) {
		target->sethp(target->gethp() - damage);  
	}
	cout << "단검으로 찌른다->" << target->getname() << "에게 " << damage << " 데미지" << endl;
	if (target->gethp() >= 0) {
		cout << target->getname() << "HP: " << php << "->" << target->gethp() << " (사망)" << endl;
	}
	else {
		cout << target->getname() << "HP: " << php << "->" << target->gethp() << endl;
	}
}
