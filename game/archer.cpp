#include "archer.h"


archer::archer(string name, int hp, int mp, int power, int defence)
		: player(name, hp, mp, power + 30, defence)
{
	this->job = "궁수";
}
void archer::attack(monster* target)
{
	cout << "화살을 발사한다" << endl;
}
