#include "warrior.h"

warrior::warrior(string name, int hp, int mp, int power, int defence)
	: player(name, hp, mp, power, defence +  30)
{
	this->job = "전사";
}
void warrior::attack(monster* target)
{
	cout << "검을 휘두른다" << endl;
}