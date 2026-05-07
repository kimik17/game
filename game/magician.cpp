#include "magician.h"


magician::magician(string name, int hp, int mp, int power, int defence)
	: player(name, hp, mp + 30, power, defence)
{
	this->job = "마법사";
}
void magician::attack(monster* target)
{
	cout << "파이어볼을 발사한다" << endl;
}