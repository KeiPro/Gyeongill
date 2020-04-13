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

#define TILESIZE 4

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
	int monsXPosition, monsYPosition; //몬스터의 x, y좌표
};

//물약 구조체
struct Portion 
{
	string name; //물약의 이름
	int price; //물약 가격
	int healHp; //회복치
};

//타일 구조체
struct Tile {
	int tileType; //땅 : 0, 바다 : 1, 숲 : 2, 늪 : 3
	int tileXPosition, tileYPosition; 
};

void MapCreate(char** map, int width, int height); //맵 동적할당 함수 원형
void MapFree(char** map, int width, int height); //맵을 해제하는 함수 원형
void TileInitializing(Tile* tile); //타일 타입을 초기화 하는 함수
void HeroSetting(Hero* hero, int area); //히어로를 세팅하는 함수


int main()
{
	int width;
	int height;

	cout << "너비 입력 : ";
	cin >> width;
	cout << "높이 입력 : ";
	cin >> height;

	char** map = nullptr; //2차원 배열 동적할당 하기 위한 이중 포인터 변수
	MapCreate(map, width, height); //맵 동적할당 함수

#pragma region 이 사이에서 게임이 이루어진다.
	Tile tile[4];
	Hero heroes;
	







	HeroSetting(&heroes, width * height); //히어로 세팅 함수
	TileInitializing(tile); //각 타일의 타입 초기화
	


#pragma endregion
	MapFree(map, width, height); //맵 해제 함수
	   	  
	return 0;
}


//맵 동적할당 함수
void MapCreate(char** map, int width, int height)
{
	map = new char*[height];

	for (int i = 0; i < height; i++)
		*(map + i) = new char[width];
}

//맵 해제
void MapFree(char** map, int width, int height)
{
	//동적할당 메모리 해제
	for (int i = 0; i < height; i++)
	{
		delete[] map[i];
	}
	delete[] map;
}

//타일 타입 초기화
void TileInitializing(Tile* tile)
{
	for (int i = 0; i < TILESIZE; i++)
	{
		tile[i].tileType = i;
	}
}

//히어로 세팅 함수
void HeroSetting(Hero* hero, int area)
{
	cout << "히어로의 이름을 입력해 주세요 : ";
	cin >> hero->heroName;

	HeroSubSetting();

	if (area <= 100)
	{

	}
	else if (area <= 200)
	{

	}
	else if (area <= 300)
	{

	}
}

void HeroSubSetting(Hero* hero, int )
{

}