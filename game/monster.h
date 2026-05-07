#pragma once
#include <iostream>
#include <string>
using std::cout;
using std::endl;

class monster
{
protected:
	std::string name;
	int hp;
	int power;
	int defence;

	std::string dropitemname;
	int dropitemprice;
public:
	monster(std::string name, int hp, int power, int defence, std::string dropitemname, int dropitemprice);
	virtual ~monster();

	//-- get --
	std::string getname() const;
	int gethp() const;
	int getpower() const;
	int getdefence() const;
	std::string getdropitemname() const;
	int getdropitemprice() const;

	//-- set --
	void sethp(int value);

	virtual void attack(class player* target) =0;
};

