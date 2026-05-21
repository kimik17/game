#include "player.h"

player::player(string name, int hp, int mp, int power, int defence)
{
	this->name = name;
	this->hp = hp;
	this->maxhp = hp;
	this->mp = mp;
	this->maxmp = mp;
	this->power = power;
	this->defence = defence;
	this->job = "무직";

	Item hpPotion;
	hpPotion.name = "HP 포션";
	hpPotion.price = 50;
	hpPotion.type = 1;
	inventory.AddItem(hpPotion);

	Item mpPotion;
	mpPotion.name = "MP 포션";
	mpPotion.price = 50;
	mpPotion.type = 1;
	inventory.AddItem(mpPotion);
}

player::~player() {}

// -- get --
string player::getname() const { return name; }
string player::getjob() const { return job; }
int player::getlevel() const { return level; }
int player::gethp() const { return hp; }
int player::getmaxhp() const { return maxhp; }
int player::getmp() const { return mp; }
int player::getmaxmp() const { return maxmp; }
int player::getpower() const { return power; }
int player::getdefence() const { return defence; }
int player::getexp() const { return exp; }
int player::getmaxExp() const { return maxExp; }

// -- set -- 
void player::setlevel(int value) { level = value; }
void player::sethp(int value) { hp = value; }
void player::setmaxhp(int value) { maxhp = value; }
void player::setmp(int value) { mp = value; }
void player::setmaxmp(int value) { maxmp = value; }
void player::setpower(int value) { power = value; }
void player::setdefence(int value) { defence = value; }
void player::setexp(int value) { exp = value; }
void player::setmaxExp(int value) { maxExp = value; }

void status(player* p)
{
	cout << "------------------------------------" << endl;
	cout << "닉네임: " << p->getname() << " | 직업: " << p->getjob() << " | Lv." << p->getlevel() << " | exp: " << p->getexp() << "/" << p->getmaxExp() << endl;
	cout << "HP: " << p->gethp() << " | MP: " << p->getmp() << " | 공격력: " << p->getpower() << " | 방어력: " << p->getdefence() << endl;
	cout << "------------------------------------" << endl;
}

void player::addInventory(Item droppedItem) {
	inventory.AddItem(droppedItem);
	cout << "-> " << droppedItem.name << " 획득 성공!" << endl;
	cout << endl;

}

void player::playerlevel(int inputexp) {
	exp += inputexp;
	cout << "  -> 경험치 +" << inputexp << " 획득! (현재 경험치: " << exp << "/" << maxExp << ")" << endl;

	if (exp >= maxExp) {
		int oldlevel = level;
		level++;
		exp -= maxExp;

		hp += 10;
		maxhp += 10;
		mp += 5;
		maxmp += 5;
		power += 5;
		maxExp += 50;

		cout << "\n... 레벨업 조건 충족" << endl;
		cout << "  -> 레벨 업! Lv." << oldlevel << " -> Lv." << level << endl;
		cout << "  -> HP +10, MP +5, 공격력 +5 증가!\n" << endl;
	}
}
//void player::showinventory()
//{
//	int count = 1;
//	cout << "\n[ 인벤토리 (" << inventory.size() << "/10) ]" << endl;
//	if (inventory.size() == 0)
//	{
//		cout << "아이템이 없습니다"<< endl;
//		cout << endl;
//
//	}
//	if (inventory.empty())
//	{
//
//	}
//	else
//	{
//		for (const auto& it : inventory)
//		{
//			cout << count << ". " << it.name << " (" << it.price << "G)" << endl;
//			count++;
//		}
//		cout << endl;
//	}
//}

void player::useItem(int index) {
	if (index < 0 || index >= inventory.GetSize()) {
		cout << "사용할 수 없는 아이템 번호입니다." << endl;
		return;
	}
	Item& targetItem = inventory.GetItem(index);

	MyVector<Item>& inv = getInventory();

	if (targetItem.name == "HP 포션") {
		hp = std::min(hp + 50, maxhp);
		inventory.Erase(index);
		cout << "HP 포션을 사용했습니다! (현재 HP: " << hp << "/" << maxhp << ")" << endl;
	}
	else if (targetItem.name == "MP 포션") {
		mp = std::min(mp + 50, maxmp);
		inventory.Erase(index);
		cout << "MP 포션을 사용했습니다! (현재 MP: " << mp << "/" << maxmp << ")" << endl;
	}
}