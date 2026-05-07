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
		int playerdamage = p->getpower() - m->getdefence();
		cout << "-- 플레이어 턴--" << endl;
		p->attack(m);
		int mhp = m->gethp();
		if (playerdamage <= 0)
		{
			playerdamage = 1;
		}
		m->sethp(m->gethp() - playerdamage);
		cout << m->getname() << "에게 " << playerdamage << "데미지" << endl;
		if (m->gethp() <= 0)
		{
			cout << m->getname() << "HP: " << mhp << "->" << m->gethp() << " (사망)" << endl;
			cout << "★ 전투 승리!" << endl;
			cout << "->" << m->getname() << "의 " << m->getdropitemname() << " 획득" << endl;
			cout << "(다음 단계에서 인벤토리에 저장됩니다)" << endl;
			cout << endl;
			Item droppedItem;
			droppedItem.name = m->getdropitemname();
			droppedItem.price = m->getdropitemprice();

			p->addInventory(droppedItem);

			break;
		}
		else
		{
			cout << m->getname() << "HP: " << mhp << "->" << m->gethp() << endl;
		}
		int monsterdamage = m->getpower() - p->getdefence();
		cout << "-- " << m->getname() << "턴 --" << endl;
		m->attack(p);
		int php = p->gethp();
		if (monsterdamage <= 0)
		{
			monsterdamage = 1;
		}
		p->sethp(p->gethp() - monsterdamage);
		cout << p->getname() << "에게 " << monsterdamage << "데미지" << endl;
		if (m->gethp() <= 0)
		{
			cout << p->getname() << "HP: " << php << "->" << p->gethp() << " (사망)" << endl;
			cout << "💀 패배 승리!" << endl;
			cout << "(메인 매뉴로 이동합니다)" << endl;
			cout << endl;
			break;
		}
		else
		{
			cout << p->getname() << "HP: " << php << "->" << p->gethp() << endl;
		}
	}
}