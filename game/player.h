#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Item.h"
#include "MyVector.h"
using std::cout;
using std::endl;
using std::string;

class monster;

class player
{
protected:
	string name;
	string job;
	int level = 1;
	int exp = 0;
	int maxExp = 100;
	int hp = 0;
	int maxhp = 0;
	int mp = 0;
	int maxmp = 0;
	int power = 0;
	int defence = 0;
	MyVector<Item> inventory;
public:
	MyVector<Item>& getInventory() { return inventory; }

	player(string name, int hp, int mp, int power, int defence);
	virtual ~player();

	// -- get --
	string getname() const;
	string getjob() const;
	int getlevel() const;
	int gethp() const;
	int getmaxhp() const;
	int getmp() const;
	int getmaxmp() const;
	int getpower() const;
	int getdefence() const;
	int getexp() const;
	int getmaxExp() const;

	// -- set -- 
	void setlevel(int value);
	void sethp(int value);
	void setmaxhp(int value);
	void setmp(int value);
	void setmaxmp(int value);
	void setpower(int value);
	void setdefence(int value);
	void setexp(int value);
	void setmaxExp(int value);

	virtual void attack(monster* target) =0;

	void addInventory(Item droppedItem);

	int getInventorySize() {
		return inventory.GetSize();
	}
	void playerlevel(int inputexp);

	//void showinventory();

	void useItem(int inedex);
};
void status(player* p);