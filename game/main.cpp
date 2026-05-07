#include "player.h"
#include "warrior.h"
#include "magician.h"
#include "thief.h"
#include "archer.h"
#include "monster.h"
#include "battle.h"
#include "Slime.h"
#include "Goblin.h"
#include "Potion.h"

#include<iostream>
#include<string>
using std::cout;
using std::endl;
using std::cin;
using std::string;

void statusBeforeJob(string name, int* stats)
{
	cout << "------------------------------------" << endl;
	cout << "닉네임: " << name << " | 직업: 무직 | Lv.0" << endl;
	cout << "HP: " << stats[0] << " | MP: " << stats[1] << " | 공격력: " << stats[2] << " | 방어력: " << stats[3] << endl;
	cout << "------------------------------------" << endl;
}

int main() 
{
	string tempname;
	const int SIZE = 4;
	int tempstat[SIZE] = { 0 };
	// stat[0] = HP, stat[1] = MP, stat[2] = 공격력, stat[3] = 방어력

	int HPP = 5;
	int MPP = 5;
	int powerp = 1;
	int Defensep = 1;

	int choice;
	bool isGameStart = false;

	AlchemyWorkshop workshop;

	cout << "===========================================" << endl;
	cout << "   [ 던전 탈출 텍스트 RPG ]" << endl;
	cout << "===========================================" << endl;
	cout << "용사의 이름을 입력해주세요: ";
	cin >> tempname;

	while (true) 
	{
		cout << "\nHP와 MP를 입력해주세요: ";
		cin >> tempstat[0] >> tempstat[1];
		if (tempstat[0] >= 50 && tempstat[1] >= 50)
		{
			break;
		}
		else
		{
			cout << "HP나 MP의 값이 너무 작습니다. 다시 입력해주세요." << endl;
		}
	}

	cout << endl;

	while (true)
	{
		cout << "공격력과 방어력을 입력해주세요: ";
		cin >> tempstat[2] >> tempstat[3];
		cout << endl;
		if (tempstat[2] >= 20 && tempstat[3] >= 20)
		{
			break;
		}
		else
		{
			cout << "공격력이나 방어력의 값이 너무 작습니다. 다시 입력해주세요." << endl;
		}
	}

	statusBeforeJob(tempname, tempstat);

	cout << endl;
	
	player* Myplayer = nullptr;

	cout << "* HP 포션 5개, MP 포션 5개가 기본 지급되었습니다." << endl;
	cout << "============================================" << endl;
	cout << "< 캐릭터 강화 >" << endl;
	cout << "1. HP UP    2. MP UP    3. 공격력 2배" << endl;
	cout << "4. 방어력 2배  5. 현재 능력치  0. 게임 시작" << endl;
	cout << "============================================" << endl;

	while (!isGameStart)
	{
		cout << "번호를 선택해주세요:";
		cin >> choice;
		switch (choice)
		{
			case 0:
				cout << "게임을 시작합니다!" << endl;
				isGameStart = true;
				break;

			case 1:
				if (HPP == 0)
				{
					cout << "포션 부족" << endl;
				}
				else
				{
					cout << "* HP가 20 증가했습니다. (HP 포션 차감 : 남은 포션 "<< --HPP << "개)" << endl;
					tempstat[0] += 20;
				}
				cout << endl;
				break;

			case 2:
				if (MPP == 0)
				{
					cout << "포션 부족" << endl;
				}
				else
				{
					cout << "* MP가 20 증가했습니다. (MP 포션 차감 : 남은 포션 " << --MPP << "개)" << endl;
					tempstat[1] += 20;
				}
				cout << endl;
				break;

			case 3:
				if (powerp == 0)
				{
					cout << "포션 부족" << endl;
				}
				else
				{
					cout << "* 공격력이 2배 증가했습니다. (공격력 포션 차감 : 남은 포션 " << --powerp << "개)" << endl;
					tempstat[2] *= 2;
				}
				cout << endl;
				break;

			case 4:
				if (Defensep == 0)
				{
					cout << "포션 부족" << endl;
				}
				else 
				{
					cout << "* 방어력이 2배 증가했습니다. (방어력 포션 차감 : 남은 포션 " << --Defensep << "개)" << endl;
					tempstat[3] *= 2;
				}
				cout << endl;
				break;

			case 5:
				statusBeforeJob(tempname, tempstat);
				cout << endl;
				break;
		}
	}
	cout << "<전직 시스템>" << endl;
	cout << tempname <<"님, 직업을 선택해주세요!" << endl;
	cout <<"1. 전사   2. 마법사   3. 도적   4. 궁수" << endl;
	cout << "선택: ";
	cin >> choice;

	switch (choice)
	{
		case 1:
			Myplayer = new warrior(tempname, tempstat[0], tempstat[1], tempstat[2], tempstat[3]);
			cout << "전사로 전직하였습니다 (방어력 + 30)" << endl;
			break;
		case 2:
			Myplayer = new magician(tempname, tempstat[0], tempstat[1], tempstat[2], tempstat[3]);
			cout << "마법사로 전직하였습니다 (MP + 30)" << endl;
			break;
		case 3:
			Myplayer = new thief(tempname, tempstat[0], tempstat[1], tempstat[2], tempstat[3]);
			cout << "도적로 전직하였습니다 (HP + 30)" << endl;
			break;
		case 4:
			Myplayer = new archer(tempname, tempstat[0], tempstat[1], tempstat[2], tempstat[3]);
			cout << "궁수로 전직하였습니다 (공격력 +30)" << endl;
			break;
	}

	status(Myplayer);
	
	cout << endl;

	monster* m = nullptr;
	int i = 0;
	while (i == 0)
	{
		int choice;
		cout << "==메인 메뉴==" << endl;
		cout << "1.던전 입장" << endl;
		cout << "2.인벤토리" << endl;
		cout << "3.포션 제작소" << endl;
		cout << "0.게임 종료" << endl;
		cin >> choice;
		switch(choice)
		{
		case 0:
			cout << "게임을 종료합니다" << endl;
			i++;
			break;
		case 1:
			battle(Myplayer, m);
			break;
		case 2:
			Myplayer->showinventory();
			break;
		case 3:
			int potionChoice = 0;
			cout << "\n[ 포션 제작소 ]" << endl;
			cout << "1. 전체 레시피 보기" << endl;
			cout << "2. 이름으로 검색" << endl;
			cout << "3. 재료로 검색" << endl;
			cout << "0. 뒤로가기" << endl;
			cout << "선택: ";
			cin >> potionChoice;

			cin.ignore();

			if (potionChoice == 1) {
				workshop.ShowAllRecipes();
			}
			else if (potionChoice == 2) {
				string searchName;
				cout << "검색할 레시피 이름: ";
				getline(cin, searchName);
				workshop.SearchByName(searchName);
			}
			else if (potionChoice == 3) {
				string searchIngre;
				cout << "검색할 재료 이름: ";
				getline(cin, searchIngre);
				workshop.SearchByIngredient(searchIngre);
			}
			break;
		}
	}

	delete m;
	delete Myplayer;

	return 0;
}
