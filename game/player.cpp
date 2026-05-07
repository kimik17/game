#include "player.h"

player::player(string name, int hp, int mp, int power, int defence)
{
	this->name = name;
	this->hp = hp;
	this->mp = mp;
	this->power = power;
	this->defence = defence;
	this->job = "무직";
}

player::~player() {}

// -- get --
string player::getname() const { return name; }
string player::getjob() const { return job; }
int player::getlevel() const { return level; }
int player::gethp() const { return hp; }
int player::getmp() const { return mp; }
int player::getpower() const { return power; }
int player::getdefence() const { return defence; }

// -- set -- 
void player::setlevel(int value) { level = value; }
void player::sethp(int value) { hp = value; }
void player::setmp(int value) { mp = value; }
void player::setpower(int value) { power = value; }
void player::setdefence(int value) { defence = value; }

void status(player* p)
{
	cout << "------------------------------------" << endl;
	cout << "닉네임: " << p->getname() << " | 직업: " << p->getjob() << " | Lv." << p->getlevel() << endl;
	cout << "HP: " << p->gethp() << " | MP: " << p->getmp() << " | 공격력: " << p->getpower() << " | 방어력: " << p->getdefence() << endl;
	cout << "------------------------------------" << endl;
}

void player::addInventory(Item droppedItem) {
	if (inventory.size() >= 10) {
		cout << "\n[알림] 가방이 가득 찼습니다! 아이템을 더 이상 담을 수 없습니다." << endl;
	}
	else {
	inventory.push_back(droppedItem);
	cout << "-> " << droppedItem.name << " 획득 성공!" << endl;
	cout << endl;
	}
}
void player::showinventory()
{
	int count = 1;
	cout << "\n[ 인벤토리 (" << inventory.size() << "/10) ]" << endl;
	if (inventory.size() == 0)
	{
		cout << "아이템이 없습니다"<< endl;
		cout << endl;

	}
	if (inventory.empty())
	{

	}
	else
	{
		for (const auto& it : inventory)
		{
			cout << count << ". " << it.name << " (" << it.price << "G)" << endl;
			count++;
		}
		cout << endl;
	}
}