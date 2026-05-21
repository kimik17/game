#include"battle.h"

void battle(player* p, monster* m)
{
	int randmonster = rand() % 2;
	if (randmonster == 0) {
		m = new Slime();
	}
	else
	{
		m = new Goblin();
	}
	cout << "[ 전투 시작! ]" << p->getname() << "(" << p->getjob() << ")" << " vs " << m->getname() << endl;
	while (true)
	{
		int choice;
		int playerdamage = p->getpower() - m->getdefence();
		cout << "-- 플레이어 턴--" << endl;
		cout << "1. 공격" << endl;
		cout << "2. 인벤토리" << endl;
		cout << "선택: ";
		std::cin >> choice;
		int mhp = m->gethp();
		switch (choice) {
		case 1:
			p->attack(m);
			break;
		case 2:
		{
			p->getInventory().PrintAllItems();
			cout << "사용할 아이템 번호: ";
			int itemChoice;
			std::cin >> itemChoice;

			int itemIndex = itemChoice - 1;
			if (itemIndex >= 0 && itemIndex < p->getInventory().GetSize()) {
				//p->useItem(itemIndex);
			}
			else {
				cout << "잘못된 번호입니다." << endl;
			}
			break;
		}
		default:
			cout << "잘못된 번호입니다!" << endl;
			continue;
		}
		cout << endl;
		if (m->gethp() <= 0)
		{
			cout << "★ 전투 승리!" << endl;
			p->playerlevel(30);
			cout << "(다음 단계에서 인벤토리에 저장됩니다)" << endl;
			cout << endl;
			Item droppedItem;
			droppedItem.name = m->getdropitemname();
			droppedItem.price = m->getdropitemprice();
			droppedItem.type = 2;
			p->addInventory(droppedItem);

			break;
		}
		cout << "-- " << m->getname() << "턴 --" << endl;
		int php = p->gethp();
		m->attack(p);
		if (m->gethp() <= 0)
		{
			cout << "💀 패배 승리!" << endl;
			cout << "(메인 매뉴로 이동합니다)" << endl;
			cout << endl;
			break;
		}
	}
}