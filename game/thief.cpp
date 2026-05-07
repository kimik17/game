#include "thief.h"


thief::thief(string name, int hp, int mp, int power, int defence)
	: player(name, hp + 30, mp, power, defence)
{
	this->job = "도적";
}
void thief::attack(monster* target)
{
	cout << "단검으로 찌른다" << endl;
}
