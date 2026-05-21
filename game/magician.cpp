#include "magician.h"
#include "monster.h"

magician::magician(string name, int hp, int mp, int power, int defence)
	: player(name, hp, mp + 30, power, defence)
{
	this->job = "마법사";
}
void magician::attack(monster* target)
{
	int php = target->gethp();
	int damage = power - target->getdefence();

	if (damage <= 0) damage = 1;

	target->sethp(target->gethp() - damage);
	cout << "파이어볼을 발사한다->" << target->getname() << "에게 " << damage << " 데미지" << endl;
	if (target->gethp() >= 0) {
		cout << target->getname() << "HP: " << php << "->" << target->gethp() << " (사망)" << endl;
	}
	else {
		cout << target->getname() << "HP: " << php << "->" << target->gethp() << endl;
	}
}