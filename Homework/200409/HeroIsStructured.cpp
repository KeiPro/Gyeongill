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

#define MONSTERSIZE 16

enum TILETYPE{ LAND=2 , WATER , FOREST, FLY }; //땅, 바다, 숲, 비행

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
};

//몬스터 구조체
struct Monster
{
	string monsterName; //몬스터 이름
	int maxHp; //몬스터의 최대체력
	int currentHp; //몬스터의 현재체력
	int giveExp; //몬스터의 경험치
	int giveGold; //획득 골드
	//int properties; //속성
	int tileType; //몬스터가 생존하고 있는 타일
};

//물약 구조체
struct Portion 
{
	string name; //물약의 이름
	int price; //물약 가격
	int healHp; //회복치
};

void MapCreate(char** map, int width, int height, int* tilePositionSave); //맵 동적할당 함수 원형
void MapFree(char** map, int width, int height); //맵을 해제하는 함수 원형
void Settings(Hero* hero, Monster* monster, string monsterName[], int area); // 히어로와 몬스터를 세팅하기 위한 함수
void HeroSetting(Hero* hero, int count); //히어로를 세팅하기 위해 area값을 넘겨주기 위한 함수
void MonsterSetting(Monster* monster, string monsterName[], int count); //몬스터를 세팅하기위해 area값을 넘겨주기 위한 함수
void MapPrint(char** map, int width, int height); //맵 출력 함수
void CharacterMove(Hero* hero, char* move, char** map, int width, int height, int* tileSavePosition); //캐릭터가 움직임 함수원형


int monsterCount = 0; //총 몬스터 마리수 전역변수 설정

int main()
{
	srand(time(NULL));

	Hero hero; 
	Monster* monster;
	string monsterName[] = { "모래두지", "닥트리오", "딱구리", "뿔카노", //monsterName[0] ~ monsterName[3] : 땅
		"수륙챙이", "야도란", "킹크랩", "아쿠스타",					 //monsterName[4] ~ monsterName[7] : 물
		"독침붕", "콘팡", "라플레시아", "독파리",						 //monsterNmae[8] ~ monsterName[11] : 숲
		"망나뇽", "버터플", "리자몽", "갸라도스"};						 //monsterName[12] ~ monsterName[15] : 비행
	
	monster = new Monster[MONSTERSIZE];
	
	int width;
	int height;

	cout << "너비 입력 : ";
	cin >> width;
	cout << "높이 입력 : ";
	cin >> height;
	
	hero.myXPosition = 0, hero.myYPosition = 0; //나의 위치 초기화
	int tilePositionSave = 0;
	char** map = new char*[height]; //2차원 배열 동적할당 하기 위한 이중 포인터 변수
	MapCreate(map, width, height, &tilePositionSave); //맵 동적할당 함수

#pragma region 이 사이에서 게임이 이루어진다.

	Settings( &hero, monster, monsterName , width * height); //히어로와 몬스터 세팅 함수

	char move; //움직임을 받는 변수


	while (1)
	{
		system("cls");
		MapPrint(map, width, height); //맵 출력 함수
		CharacterMove(&hero, &move, map, width, height, &tilePositionSave); //캐릭터 움직이는 함수
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
void MapCreate(char** map, int width, int height, int* tileSavePosition)
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
				map[i][j] = LAND;
			}
		}
	}

	//바다 초기화
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (map[i][j] != LAND && (rand() % 100 < 30)) //바다 30%생성
			{
				map[i][j] = WATER;
			}
		}
	}

	//숲 초기화
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (map[i][j] != LAND && map[i][j] != WATER && ( rand() % 100 < 30)) //숲 30%생성
			{
				map[i][j] = FOREST;
			}
		}
	}

	//비행 초기화
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (map[i][j] != LAND && map[i][j] != WATER && map[i][j] != FOREST) //나머지 비행타일 생성
			{
				map[i][j] = FLY;
			}
		}
	}

	*tileSavePosition = map[0][0];
	map[0][0] = 0;
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
	//MonsterSetting(monster, monsterName, count); //몬스터 초기화 및 세팅
}

//히어로 세팅 함수
void HeroSetting(Hero* hero = nullptr, int count = 0)
{
	cout << "히어로의 이름을 입력해 주세요 : ";
	cin >> hero->heroName;

	hero->maxHp = 100 + count * 10; //히어로의 기본 체력은 최소 100의 체력을 가지고 있는다. 
	hero->currentHp = hero->maxHp; //세팅 시에는 현재 체력이 맥스 체력이어야 한다.
	hero->maxExp = 1000 + count * 200;  //최소 경험치 : 1000 설정
	hero->currentExp = 0; //현재 경험치
	hero->myGold = 0; //현재 골드
	hero->myXPosition = 0, hero->myYPosition = 0; //영웅의 좌표
}

//몬스터 세팅함수
void MonsterSetting(Monster* monster, string monsterName[], int count)
{
	//i를 조절하는 것이 아니라 하나 변수 더 선언해서 그녀석으로 밸런스 조절하는걸로??
	for (int i = 0; i < MONSTERSIZE; i++)
	{
		(monster + i)->monsterName = monsterName[i];
		(monster + i)->tileType = i;
		(monster + i)->maxHp = (rand() % 3 + (1 + i))+count; //땅 포켓몬은 체력이 1~2가 된다. //
		(monster + i)->currentHp = (monster + i)->maxHp;
		(monster + i)->giveExp = (rand() % 100 + 100 + (i*20)) + (count * 50); //최소 경험치 100 //밸런스 조절
		(monster + i)->giveGold = (rand() % 10 + 10 + (i*5)) + (count + 1) * 2; //최소 골드 획득
		
		if ((i + 1) % 4 == 0)
		{

		}
	}
}

void CharacterMove(Hero* hero, char* move, char** map, int width, int height, int* tilePositionSave)
{
	*move = _getch();
	
	switch (*move)
	{
		case 'w':
			
			if (hero->myYPosition == 0)
			{
				return;
			}
			else
			{
				map[hero->myYPosition][hero->myXPosition] = *tilePositionSave;
				hero->myYPosition--;
				*tilePositionSave = map[hero->myYPosition][hero->myXPosition];
				map[hero->myYPosition][hero->myXPosition] = 0;
			}

			break;

		case 'a':

			if (hero->myXPosition == 0)
			{
				return;
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
				return;
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
				return;
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

}