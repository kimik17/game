#include "monster.h"

monster::monster(std::string name, int hp, int power, int defence, std::string dropitemname, int dropitemprice)
{
	this->name = name;
	this->hp = hp;
	this->power = power;
	this->defence = defence;
	this->dropitemname = dropitemname;
	this->dropitemprice = dropitemprice;
}

monster::~monster(){}

//-- get --
std::string monster::getname() const { return name; }
int monster::gethp() const { return hp; }
int monster::getpower() const { return power; }
int monster::getdefence() const { return defence; }
std::string monster::getdropitemname() const { return dropitemname; }
int monster::getdropitemprice() const { return dropitemprice; }

//-- set --
void monster::sethp(int value) { hp = value; }