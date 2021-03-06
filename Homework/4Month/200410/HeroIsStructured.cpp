/*
	영웅은 구조적

	** 영웅은 절차적 2 : 영웅은 구조적
	1) 가로 * 세로 타일 사이즈를 원하게 설정할 수 있도록 만들자. (동적 할당)
	2) w, a, s, d이동
	***3) 배열, 구조체, 함수를 최대한 활용해보자.
	4) 전투는 가위 바위 보
	5) 몬스터는 포켓몬스터처럼 랜덤한 인카운터 방식. //이 타일에 들어갔을 때 확률에 따라서 만날수도 있고 안만날수도있고
	6) 타일에 종류가 있다. (숲, 늪, 땅) 마다 만나는 몬스터도 다르다. 숲에서 만나는 얘들 늪에서 만나는 얘들 ... 다 다르게
	7) 플레이어 속성 : 이름 / 최대 HP(레벨에 따라 증가) / 현재 HP / 경험치 / 레벨 / 골드
	8) 물약 : 이름 / 가격 / 회복치
	9) 몬스터 : 이름(포켓몬스터) / 최대 HP / 현재 HP / 획득 경험치 / 획득 골드 / 속성
	10) 상점 : 아이템 종류
*/

#include <iostream>
#include <string>
#include <Windows.h>
#include <ctime>
#include <conio.h>
#include <cmath>

#define MONSTERSIZE 16 
#define SHOPSIZE 3 //상점은 3개

enum TILETYPE{ SHOP=1, LAND , WATER , FOREST, FLY }; //땅, 물, 숲, 비행
enum SRP { SCISSORS=1, ROCK, PAPER };

using namespace std;

//영웅 구조체
struct Hero
{
	string heroName; //히어로 이름
	int maxHp; //최대체력
	int currentHp; //현재체력
	int maxExp; //다음 레벨업을 하기 위한 경험치
	int currentExp; //경험치
	int myGold; //재화
	int myXPosition, myYPosition; //나의 x, y좌표
	int damage;
};

//몬스터 구조체
struct Monster
{
	string monsterName; //몬스터 이름
	int maxHp; //몬스터의 최대체력
	int currentHp; //몬스터의 현재체력
	int giveExp; //몬스터의 경험치
	int giveGold; //획득 골드
	int tileType; //몬스터가 생존하고 있는 타일
	int monsterDmg; //몬스터 데미지
};

//물약 구조체
struct Portion 
{
	string name; //물약의 이름
	int price; //물약 가격
	int healHp; //회복치
};

//상점 구조체
struct Shop
{
	int shopXPosition, shopYPosition;
};

void MapCreate(char** map, int width, int height, int* tilePositionSave, Shop* shop); //맵 동적할당 함수 원형
void MapFree(char** map, int width, int height); //맵을 해제하는 함수 원형
void Settings(Hero* hero, Monster* monster, string monsterName[], int area); // 히어로와 몬스터를 세팅하기 위한 함수
void HeroSetting(Hero* hero, int count); //히어로를 세팅하기 위해 area값을 넘겨주기 위한 함수
void MonsterSetting(Monster* monster, string monsterName[], int count); //몬스터를 세팅하기위해 area값을 넘겨주기 위한 함수
void MapPrint(char** map, int width, int height); //맵 출력 함수
int CharacterMove(Hero* hero, char* move, char** map, int width, int height, int* tilePositionSave); //캐릭터가 움직임 함수원형
void FightAndShop(Hero* hero, Monster* monster, int moveResult, int* tilePositionSave); //상점 방문 or 몬스터와 싸울 함수
void ShopVisit(Hero* hero); //상점을 방문했을 때
void MonsterMeet(Hero* hero, Monster* monster, int monsterType, int* tilePositionSave); //몬스터와 싸우는 함수
inline bool RandResult(int result); //몬스터를 만날 확률을 구하는 함수

int monsterCount = 0; //총 몬스터 마리수 전역변수 설정

int main()
{
	srand(time(NULL));
	Hero hero;
	Monster* monster;
	Shop* shop = nullptr;
	string monsterName[] = { "모래두지", "닥트리오", "딱구리", "뿔카노", //monsterName[0] ~ monsterName[3] : 땅
		"수륙챙이", "야도란", "킹크랩", "아쿠스타",					 //monsterName[4] ~ monsterName[7] : 물
		"독침붕", "콘팡", "라플레시아", "독파리",						 //monsterNmae[8] ~ monsterName[11] : 숲
		"망나뇽", "버터플", "리자몽", "갸라도스"};						 //monsterName[12] ~ monsterName[15] : 비행
	
	monster = new Monster[MONSTERSIZE];
	shop = new Shop[SHOPSIZE];
	int width;
	int height;

	cout << "너비 입력 : ";
	cin >> width;
	cout << "높이 입력 : ";
	cin >> height;
	
	hero.myXPosition = 0, hero.myYPosition = 0; //나의 위치 초기화
	int tilePositionSave = 0;
	char** map = new char*[height]; //2차원 배열 동적할당 하기 위한 이중 포인터 변수
	MapCreate(map, width, height, &tilePositionSave, shop); //맵 동적할당 함수


#pragma region 이 사이에서 게임이 이루어진다.

	Settings( &hero, monster, monsterName , width * height); //히어로와 몬스터 세팅 함수

	char move; //움직임을 받는 변수 CharacterMove함수의 변수로 활용.
	int moveResult; //움직이고 나서 나온 반환값을 받을 변수 // 1 = Shop, 2 = Land, 3 = Water, 4 = Forest, 5 = Fly;

	
	//몬스터 능력치 확인 코드
	for (int i = 0; i < MONSTERSIZE; i++)
	{
		cout << "이름 : " << (*(monster+i)).monsterName << ", 최대 체력 : " << monster[i].maxHp << ", 현재 체력 : " << monster[i].currentHp
			<< ", 몬스터 경험치 : " << monster[i].giveExp << ", 획득 골드 : " << monster[i].giveGold << ", 타일 : " << monster[i].tileType << endl;
	}

	Sleep(5000);
	

	////////////////////////////////////// 게임 진행 ////////////////////////////////////////////////
	while (1)
	{
		system("cls");
		MapPrint(map, width, height); //맵 출력 함수
		moveResult = CharacterMove(&hero, &move, map, width, height, &tilePositionSave); //캐릭터가 움직이는 함수
		FightAndShop(&hero, monster, moveResult, &tilePositionSave); //움직이고 난 후의 타일이 상점인지 몬스터인지
	}


#pragma endregion
	MapFree(map, width, height); //맵 해제 함수
	   	  
	delete[] monster;
	return 0;
}

//맵을 출력하는 함수
void MapPrint(char** map, int width, int height)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (map[i][j] == 0)
				cout << "●";
			if (map[i][j] == 1)
				cout << "♨";
			if (map[i][j] == 2)
				cout << "□";
			if (map[i][j] == 3)
				cout << "ㆀ";
			if (map[i][j] == 4)
				cout << "♧";
			if (map[i][j] == 5)
				cout << "＾";
		}
		cout << endl;
	}
}

//맵 동적할당 및 세팅함수
void MapCreate(char** map, int width, int height, int* tileSavePosition, Shop* shop)
{
	for (int i = 0; i < height; i++)
		*(map + i) = new char[width];

	//땅 초기화
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (rand() % 100 < 50) //땅 50%생성
			{
				map[i][j] = TILETYPE::LAND;
			}
		}
	}

	//바다 초기화
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (map[i][j] != TILETYPE::LAND && (rand() % 100 < 30)) //바다 30%생성
			{
				map[i][j] = TILETYPE::WATER;
			}
		}
	}

	//숲 초기화
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (map[i][j] != TILETYPE::LAND && map[i][j] != TILETYPE::WATER && ( rand() % 100 < 30)) //숲 30%생성
			{
				map[i][j] = TILETYPE::FOREST;
			}
		}
	}

	//비행 초기화
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (map[i][j] != TILETYPE::LAND && map[i][j] != TILETYPE::WATER && map[i][j] != TILETYPE::FOREST) //나머지 비행타일 생성
			{
				map[i][j] = TILETYPE::FLY;
			}
		}
	}

	int count = 0;
	//상점 위치 설정
	for (int i = 0; i < SHOPSIZE; i++)
	{
		shop[i].shopXPosition = rand() % width, shop[i].shopYPosition = rand() % height;
		
		//1 - 상점의 위치가 나의 위치와 겹치지 않게 좌표 설정
		while ((shop[i].shopXPosition == 0) && (shop[i].shopYPosition == 0) )
		{
			shop[i].shopXPosition = rand() % width; shop[i].shopYPosition = rand() % height; 
		}

		if (i != 0)
		{
			for (int j = 0; j < i ; j++) //상점이 겹치지 않게 설정
			{
				while ( ((shop[i].shopXPosition == 0) && (shop[i].shopYPosition == 0))
					|| ((shop[i].shopXPosition == shop[j].shopXPosition) && (shop[i].shopYPosition == shop[j].shopYPosition)))
				{
					shop[i].shopXPosition = rand() % width; shop[i].shopYPosition = rand() % height;
					j = 0;
				}
			}
		}
	}
	

	for (int i = 0; i < SHOPSIZE; i++)
	{
		map[shop[i].shopYPosition][shop[i].shopXPosition] = 1;
	}

	*tileSavePosition = map[0][0]; //내 위치에 대한 타일의 값을 저장
	map[0][0] = 0; //내 위치 설정
}

//맵 메모리 해제
void MapFree(char** map, int width, int height)
{
	//동적할당 메모리 해제
	for (int i = 0; i < height; i++)
	{
		delete[] map[i];
	}
	delete[] map;
}

//히어로 및 몬스터를 세팅하는 함수
void Settings(Hero* hero, Monster* monster, string monsterName[] ,int area)
{
	int count = 0;

	if (area > 100)
	{
		while (area > 100)
		{
			area -= 100;
			count++;
		}
		monsterCount = (count + 1) * 20; //밸런스
	}
	else
	{
		while (area > 0)
		{
			area -= 10;
			count++;
		}
		monsterCount = (count + 1) * 3; //밸런스
	}
	
	HeroSetting(hero, count); //히어로 초기화 및 세팅
	MonsterSetting(monster, monsterName, count); //몬스터 초기화 및 세팅
}

//히어로 세팅 함수
void HeroSetting(Hero* hero = nullptr, int count = 0)
{
	cout << "히어로의 이름을 입력해 주세요 : ";
	cin >> hero->heroName;

	hero->maxHp = 100 + count * 10; //히어로의 기본 체력은 최소 100의 체력을 가지고 있는다. 
	hero->currentHp = hero->maxHp; //세팅 시에는 현재 체력이 맥스 체력이어야 한다.
	hero->maxExp = 1000 + count * 200;  //최소 경험치 : 1000 설정
	hero->damage = 1;
	hero->currentExp = 0; //현재 경험치
	hero->myGold = 0; //현재 골드
	hero->myXPosition = 0, hero->myYPosition = 0; //영웅의 좌표
}

//몬스터 세팅함수
void MonsterSetting(Monster* monster, string monsterName[], int count)
{
	int j = 0;

	for (int i = 0; i < MONSTERSIZE; i++)
	{
		(monster + i)->monsterName = monsterName[i];
		(monster + i)->tileType = TILETYPE(j);
		(monster + i)->maxHp = (rand() % 3 + (int)ceil(1 + j*1.5f)) + count; //땅 포켓몬은 체력이 1~2가 된다.
		(monster + i)->currentHp = (monster + i)->maxHp;
		(monster + i)->giveExp = (rand() % 20 + 100 + (i * 5)) + (count * 50); //최소 경험치 100 //밸런스 조절
		(monster + i)->giveGold = (rand() % 10 + 10 + (i * 5)) + (count + 1) * 2; //최소 골드 획득
		(monster + i)->monsterDmg = count + 3;

		if ((i + 1) % 4 == 0)
		{
			j++; // TILETYPE을 1증가 시키기 위한 변수
		}
	}
}

//케릭터 움직임 함수
int CharacterMove(Hero* hero, char* move, char** map, int width, int height, int* tilePositionSave)
{
	*move = _getch();
	
	switch (*move)
	{
		case 'w':
			
			if (hero->myYPosition == 0)
			{
				return 0;
			}
			else
			{
				map[hero->myYPosition][hero->myXPosition] = *tilePositionSave; //현재 내 위치에 *tilePositionSave값을 대입.
				hero->myYPosition--;	//나의 위치를                         
				*tilePositionSave = map[hero->myYPosition][hero->myXPosition];
				map[hero->myYPosition][hero->myXPosition] = 0;
			}

			break;

		case 'a':
			 
			if (hero->myXPosition == 0)
			{
				return 0;
			}
			else
			{
				map[hero->myYPosition][hero->myXPosition] = *tilePositionSave;
				hero->myXPosition--;
				*tilePositionSave = map[hero->myYPosition][hero->myXPosition];
				map[hero->myYPosition][hero->myXPosition] = 0;
			}

			break;

		case 's':

			if (hero->myYPosition == height-1)
			{
				return 0;
			}
			else
			{
				map[hero->myYPosition][hero->myXPosition] = *tilePositionSave; 
				hero->myYPosition++;
				*tilePositionSave = map[hero->myYPosition][hero->myXPosition];
				map[hero->myYPosition][hero->myXPosition] = 0;
			}

			break;

		case 'd':

			if (hero->myXPosition == width - 1)
			{
				return 0;
			}
			else
			{
				map[hero->myYPosition][hero->myXPosition] = *tilePositionSave;
				hero->myXPosition++;
				*tilePositionSave = map[hero->myYPosition][hero->myXPosition];
				map[hero->myYPosition][hero->myXPosition] = 0;
			}

			break;
		default:
			break;

	}

	return (*tilePositionSave);

	//if (*tilePositionSave == 1) //상점이라면
	//	return TILETYPE::SHOP;		/* ShopVisit();*/
	//else if (*tilePositionSave == 2) //땅
	//	return TILETYPE::LAND;	/* RandomFightFunction(LAND);*/
	//else if (*tilePositionSave == 3) //물
	//	return TILETYPE::WATER;	/*RandomFightFunction(WATER);*/
	//else if (*tilePositionSave == 4) //숲
	//	return TILETYPE::FOREST; /*RandomFightFunction(FOREST);*/
	//else							 //하늘
	//	return TILETYPE::FLY;		/*RandomFightFunction(FLY);*/
}

//타일에 접근 했을때
void FightAndShop(Hero* hero, Monster* monster , int moveResult, int* tilePositionSave)
{
	if (moveResult == SHOP)
	{
		ShopVisit(hero);
	}
	else
	{
		if (RandResult(moveResult) == true) //몬스터와 만날 확률을 통해 true이면
		{
			MonsterMeet(hero, monster, moveResult, tilePositionSave);
		}
		else	//몬스터 안만남
		{
			return;
		}
	}
}

void MonsterMeet(Hero* hero, Monster* monster, int monsterType, int* tilePositionSave)
{
	int randNum = rand() % 4; // 0~3
	int selectFightOrRun;

	switch (monsterType)
	{
		case TILETYPE::LAND: break; //0~3
		case TILETYPE::WATER: randNum += 4; break;//4~7
		case TILETYPE::FOREST: randNum += 8; break;//8~11
		case TILETYPE::FLY: randNum += 12; break;//12~15

		default: break;
	}
	cout << endl;
	cout << monster[randNum].monsterName << "(이)가 출현했다!!!" << endl;

	Sleep(1000);

	while (1)
	{
		system("cls");
		cout << " < 몬스터 정보 > " << endl;
		cout << "  - 이름 : " << monster[randNum].monsterName << endl;
		cout << "  - 체력 : " << monster[randNum].currentHp << endl;
		cout << "  - 공격력 : " << monster[randNum].monsterDmg << endl;
		cout << endl;
		cout << " < 영웅의 정보 > " << endl;
		cout << "  - 이름 : " << hero->heroName << endl;
		cout << "  - 공격력 : " << hero->damage << endl;
		cout << "  - 체력 : " << hero->currentHp << endl;
		cout << "  - 보유한 금액 : " << hero->myGold << endl;
		cout << endl;
		cout << " >> 싸우시겠습니까?(1) 도망가시겠습니까?(2) : ";
		cin >> selectFightOrRun;

		Sleep(500);
		if (selectFightOrRun == 1)
		{
			Fight(hero, monster, randNum);
		}
		else
		{
			cout << hero->heroName << " : 하...다음에 다시보자.... " << endl;
			Sleep(1000);
			cout << monster[randNum].monsterName << " : 헤헤헤~ 바보!! 멍충이!!!! " << endl;
			Sleep(2000);

			break;
		}
	}
}

void ShopVisit(Hero* hero) //상점을 방문했을 때
{

}

//가위바위보 함수
void Fight(Hero* hero, Monster* monster, int monNumber)
{
	int inputSPR; //가위 바위 보를 입력받을 변수
	int comSPR; //컴퓨터가 랜덤으로 가위 바위 보를 결정할 변수

	system("cls");
	comSPR = rand() % 3 + 1; // 컴퓨터가 랜덤하게 값을 설정.

	cout << "전투 시작!!" << endl;
	cout << "가위(1), 바위(2), 보(3) 숫자로 입력 : ";
	cin >> inputSPR;

	switch (inputSPR)
	{
		case SRP::SCISSORS:

			if (comSPR == SRP::SCISSORS) //비김 조건
				Draw(hero, monster, monNumber, SRP::SCISSORS);
			else if (comSPR == SRP::ROCK) //패배 조건
				Defeat(hero, monster, monNumber, SRP::SCISSORS);
			else //승리 조건
				Win(hero, monster, monNumber, SRP::SCISSORS);
			break;

		case SRP::ROCK:

			if (comSPR == SRP::ROCK) //비김 조건
				Draw(hero, monster, monNumber, SRP::ROCK);
			else if (comSPR == SRP::PAPER) //패배 조건
				Defeat(hero, monster, monNumber, SRP::ROCK);
			else //승리 조건
				Win(hero, monster, monNumber, SRP::ROCK:);
			break;

		case SRP::PAPER:

			if (comSPR == SRP::PAPER) //비김 조건
				Draw(hero, monster, monNumber, SRP::PAPER);
			else if (comSPR == SRP::SCISSORS) //패배 조건
				Defeat(hero, monster, monNumber, SRP::PAPER);
			else //승리 조건
				Win(hero, monster, monNumber, SRP::PAPER);
			break;

		default:

			break;
	}
}

//타일에 닿았을 때 땅타입은 만날확률 높게 ~ 하늘은 만날 확률 낮게 설정.
inline bool RandResult(int result)
{
	return ((rand() % 100) < (70-10*result));
}

void Draw(Hero* hero, Monster* monster, int monNumber, int result) // 비김 함수
{
	cout << "결과 : 방어!!" << endl;
	if (result == SRP::SCISSORS)
		cout << monster[monNumber].monsterName << "이(가) 낸 것 : 가위" << endl;
	else if(result == SRP::ROCK)
		cout << monster[monNumber].monsterName << "이(가) 낸 것 : 바위" << endl;
	else
		cout << monster[monNumber].monsterName << "이(가) 낸 것 : 보" << endl;

	Sleep(1500);
	system("cls");
}

void Win(Hero* hero, Monster* monster, int monNumber, int result) // 이김 함수
{
	cout << "결과 : 승!!" << endl;

	monster[monNumber].currentHp -= hero->damage;
	if (monster[monNumber].currentHp <= 0)
	{
		hero->myGold += monster[monNumber].giveGold;
		cout << monster[monNumber].monsterName << "를(을) 잡아 돈" << monster[monNumber].giveGold << "원"
			" 획득!" << endl;
		cout << "현재 남은 체력 : " << hero->currentHp << endl;
		cout << "보유한 금액 : " << hero->myGold << endl;
		cout << "남은 몬스터의 수 : " << --monsterCount << endl;

		monster[monNumber].currentHp = monster[monNumber].maxHp;
		
		Sleep(1500);
		system("cls");

		if (monsterCount <= 0)
		{
			cout << endl;
			cout << " ♪（ｖ＾＿＾）ｖｖ（＾＿＾ｖ）♪ " << endl;
			cout << endl;
			cout << hero->heroName << "님이 모든 몬스터를 처치하고 승리!" << endl;
			cout << "보유한 금액 : " << hero->myGold << endl;
			cout << endl;
			exit(0);
		}
	}
	else
	{
		cout << hero->heroName << "님이 "  << hero->damage << " 만큼 공격!" << endl;
		Sleep(1500);
	}
}

void Defeat(Hero* hero, Monster* monster, int monNumber, int result) //패배 함수
{
	hero->currentHp -= monster[monNumber].monsterDmg;
	if (hero->currentHp <= 0)
		hero->currentHp = 0;
	cout << "결과 : 패배..." << endl;
	if(result == SRP::SCISSORS)
		cout << monster[monNumber].monsterName << " 낸 것 : 바위" << endl;	
	if(result == SRP::ROCK)
		cout << monster[monNumber].monsterName << " 낸 것 : 보" << endl;	
	if(result == SRP::PAPER)
		cout << monster[monNumber].monsterName << " 낸 것 : 가위" << endl;
	cout << "현재 남은 체력 : " << hero->currentHp << endl;

	//게임 종료
	if (hero->currentHp <= 0)
	{
		cout << monster[monNumber].monsterName << " 공격으로 인해 " << hero->heroName <<
			"님이 패배하였습니다. " << endl;
		exit(1);
	}

	Sleep(1500);
	system("cls");
}