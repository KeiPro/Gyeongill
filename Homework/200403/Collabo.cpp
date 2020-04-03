#include <iostream>
#include <string>
#include <conio.h>
#include <ctime>
#include <Windows.h>
#include <malloc.h>

using namespace std;
/*
탈출게임
10 * 10 크기의 맵을 만든다.
w, a, s, d키 입력을 통해서 상하좌우 이동을 한다.
시작지점은 항상(0, 0).
탈출지점은(0, 0)을 제외하고 랜덤한 위치에 생성 = > 탈출구 X 생성.

O#########
##########
##########
##########
######X###
##########
##########
##########
##########
##########
*/

//몬스터 구조체
struct Monster
{
	string name;
	int hp;
	int monX, monY;
};

int main()
{
	srand(time(NULL));

#pragma region EscapeVariable

	const int mapWidth = 10; //맵 크기
	const int mapHeight = 10; //맵 크기
	char map[mapWidth][mapHeight]; //map을 저장할 변수 생성 ( x, y )
	int myXPosition = 0, myYPosition = 0; //나의 x, y좌표
	int escapeXPosition = 0, escapeYPosition = 0; //탈출구의 x, y좌표
	char inputKey; //입력받을 문자

	//추가변수
	int storeXPosition{0}, storeYPosition{0};  //상점의 x, y위치.

	//

#pragma endregion

#pragma region HerosGameVariable

	string heroesName; //히어로 이름
	int heroesHp; //히어로의 체력
	int money = 0; //금액
	int randomGetMoney;

	int difficulty; //난이도
	int monsterCount; //몬스터 수

	const string SCISSORS = "가위"; //0
	const string ROCK = "바위"; //1
	const string PAPER = "보"; //2
	
	int inputSPR; // 가위, 바위, 보 입력받을 변수

	//추가변수
	const int difficultyOne = 5; //난이도 1
	const int difficultyTwo = 10; //난이도 2
	const int difficultyThree = 15; //난이도 3
	const int difficultyFour = 20; //난이도 4
	string gyeongillStuName[] = { "김민지", "오창렬", "김민제", "박성진", "김종훈",
		"김영우", "남성은", "홍석훈", "김지욱", "강동균", "박청아", "오세진", "유준혁",
		"남궁혁", "윤영서", "김다로" };
	
	int stuNumberTotal = sizeof(gyeongillStuName) / sizeof(gyeongillStuName[0]); //총 학생의 개수

#pragma endregion
	
	// 4. 도망가시겠습니까?의 값을 받을 변수
	
#pragma region 초기부분 [ 영웅이름 설정~전투는 계속됩니다 ] 출력까지

	cout << "영웅의 이름을 입력하세요 : ";
	cin >> heroesName;

	cout << "난이도를 입력하세요(1~10) : ";
	cin >> difficulty;

	heroesHp = (int)(11 - difficulty * 0.6f);

#pragma region 난이도 및 몬스터 개수설정

	//새로 추가된 내용. 난이도 설정하기 및 몬스터 생성
	if (difficulty < 4) //난이도가 4보다 작을 경우 ( 난이도 1 )
	{
		monsterCount = difficultyOne;
		Monster monsters[difficultyOne];
		int tmp[difficultyOne]; //이름을 랜덤하게 고르기 위해 5개의 숫자를 입력받을 변수

		//몬스터의 수 만큼 for문을 돌려 이름을 선택한다.
		//////////////////////////////////////////////////로또 번호 뽑는 방법
		for (int i = 0; i < monsterCount; i++)
		{
			tmp[i] = rand() % stuNumberTotal;


		}
	}
	else if (difficulty < 7) //난이도가 4이상 7미만인 경우 ( 난이도 2 )
	{
		monsterCount = difficultyTwo;
		Monster monsters[difficultyTwo];
		int tmp[difficultyTwo]; //이름을 랜덤하게 고르기 위해 10개의 숫자를 입력받을 변수
		
		//몬스터의 수 만큼 for문을 돌려 이름을 선택한다.
		for (int i = 0; i < monsterCount; i++)
		{
			tmp[i] = rand() % stuNumberTotal;
		}
	}
	else if (difficulty < 9)
	{
		monsterCount = difficultyThree;
		Monster monsters[difficultyThree];
		int tmp[difficultyThree]; //이름을 랜덤하게 고르기 위해 15개의 숫자를 입력받을 변수

		//몬스터의 수 만큼 for문을 돌려 이름을 선택한다.
		for (int i = 0; i < monsterCount; i++)
		{
			tmp[i] = rand() % stuNumberTotal;
		}
	}
	else
	{
		monsterCount = difficultyFour;
		Monster monsters[difficultyFour];
		int tmp[difficultyFour]; //이름을 랜덤하게 고르기 위해 20개의 숫자를 입력받을 변수

		//몬스터의 수 만큼 for문을 돌려 이름을 선택한다.
		for (int i = 0; i < monsterCount; i++)
		{
			tmp[i] = rand() % stuNumberTotal;
		}
	}

#pragma endregion

#pragma region 몬스터 이름, 체력 설정하기

	




#pragma endregion


	//난이도에 따라서 영웅의 HP, 몬스터 숫자가 변동된다.
	//--> 난이도 : difficulty ==> 영웅의 HP : 10 - difficulty*0.5 , 몬스터 숫자 : difficulty * 2.7f를 정수 변환;
	cout << "< 난이도에 의해 HP와 몬스터를 조정합니다. >" << endl;
	Sleep(1500);

	cout << "영웅의 HP : " << heroesHp << endl;

	Sleep(1000);
	cout << "몬스터 숫자 : " << monsterCount << endl;

	Sleep(1500);
	cout << "모든 몬스터를 다 잡을 때까지 전투는 계속됩니다..." << endl;
	cout << endl;
	Sleep(2000);

#pragma endregion

#pragma region 탈출구 위치, 몬스터 위치 설정.

	//탈출구 위치 설정하기. 
	while ((escapeXPosition == 0) && (escapeYPosition == 0))
	{
		escapeXPosition = rand() % mapHeight;
		escapeYPosition = rand() % mapWidth;
	}

#pragma endregion

	

	//맵에 내 위치, 탈출구, map을 저장하는 for문.
	for (int i = 0; i < mapHeight; i++)
	{
		for (int j = 0; j < mapWidth; j++)
		{
			if (i == 0 && j == 0) //내 위치 생성
			{
				map[myXPosition][myYPosition] = 'O';
			}
			else if ((i == escapeXPosition) && (j == escapeYPosition)) //탈출구 출력
			{
				map[escapeXPosition][escapeYPosition] = 'X';
			}
			else //map생성
			{
				map[i][j] = '#';
			}
		}
	}

	while (true)
	{
		system("cls");

		//맵을 계속해서 출력하는 for문
		for (int i = 0; i < mapHeight; i++)
		{
			for (int j = 0; j < mapWidth; j++)
			{
				cout << map[i][j];
			}
			cout << endl;
		}

		//Finish 코드.
		if ((myXPosition == escapeXPosition) && (myYPosition == escapeYPosition))
		{
			cout << "탈출하셨습니다! 축하드립니다!" << endl;
			break;
		}

		inputKey = _getch(); //사용자로부터 입력받는 _getch()함수.

		if (inputKey == 'w')
		{
			if (myXPosition == 0) //올라갈 곳이 없으면 계속해서 while문을 돌린다.
				continue;
			else
			{
				map[myXPosition][myYPosition] = '#';
				myXPosition--;
				map[myXPosition][myYPosition] = 'O';
			}
		}

		if (inputKey == 'a')
		{
			if (myYPosition == 0) //왼쪽으로 갈 곳이 없으면 계속해서 while문을 돌린다.
				continue;
			else
			{
				map[myXPosition][myYPosition] = '#';
				myYPosition--;
				map[myXPosition][myYPosition] = 'O';
			}
		}

		if (inputKey == 's')
		{
			if (myXPosition == mapHeight - 1) //아래로 갈 곳이 없으면 계속해서 while문을 돌린다.
				continue;
			else
			{
				map[myXPosition][myYPosition] = '#';
				myXPosition++;
				map[myXPosition][myYPosition] = 'O';
			}
		}

		if (inputKey == 'd')
		{
			if (myYPosition == mapWidth - 1) //오른쪽으로 갈 곳이 없으면 계속해서 while문을 돌린다.
				continue;
			else
			{
				map[myXPosition][myYPosition] = '#';
				myYPosition++;
				map[myXPosition][myYPosition] = 'O';
			}
		}
	}

	return 0;
}