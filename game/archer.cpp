#include "archer.h"
#include "monster.h"

archer::archer(string name, int hp, int mp, int power, int defence)
		: player(name, hp, mp, power + 30, defence)
{
	this->job = "궁수";
}
void archer::attack(monster* target)
{
	int php = target->gethp();
	int damage = (power - target->getdefence()) / 3;
	if (damage <= 0) damage = 1;
	for (int i = 0; i < 3; i++) {
		target->sethp(target->gethp() - damage);
	}
	cout << "화살을 발사한다->" << target->getname() << "에게 " << damage << " 데미지" << endl;
	if (target->gethp() >= 0) {
		cout << target->getname() << "HP: " << php << "->" << target->gethp() << " (사망)" << endl;
	}
	else {
		cout << target->getname() << "HP: " << php << "->" << target->gethp() << endl;
	}
}
