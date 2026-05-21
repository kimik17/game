#include "warrior.h"
#include "Monster.h"

warrior::warrior(string name, int hp, int mp, int power, int defence)
	: player(name, hp, mp, power, defence +  30)
{
	this->job = "전사";
}
void warrior::attack(monster* target)
{
	int php = target->gethp();
	int damage = power - target->getdefence();

	if (damage <= 0) damage = 1;

	target->sethp(target->gethp() - damage);
	cout << "검을 휘두른다 ->" << target->getname()<<"에게 "<< damage << " 데미지" << endl;
	if (target->gethp() >= 0) {
		cout << target->getname() << "HP: " << php << "->" << target->gethp() << " (사망)" << endl;
	}
	else {
		cout << target->getname() << "HP: " << php << "->" << target->gethp() << endl;
	}
}