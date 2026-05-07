#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Item.h"
using std::cout;
using std::endl;
using std::string;

class player
{
protected:
	string name;
	string job;
	int level = 0;
	int hp = 0;
	int mp = 0;
	int power = 0;
	int defence = 0;
	std::vector<Item> inventory;
public:
	player(string name, int hp, int mp, int power, int defence);
	virtual ~player();

	// -- get --
	string getname() const;
	string getjob() const;
	int getlevel() const;
	int gethp() const;
	int getmp() const;
	int getpower() const;
	int getdefence() const;

	// -- set -- 
	void setlevel(int value);
	void sethp(int value);
	void setmp(int value);
	void setpower(int value);
	void setdefence(int value);


	virtual void attack(class monster* target) =0;

	void addInventory(Item droppedItem);

	int getInventorySize() {
		return inventory.size();
	}

	void showinventory();
};
void status(player* p);