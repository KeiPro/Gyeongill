#include <iostream>
#include <string>
#include <conio.h>
#include <ctime>

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
int main()
{
	srand(time(NULL));

	const int mapWidth = 10; //맵 크기
	const int mapHeight = 10; //맵 크기
	char map[mapWidth][mapHeight]; //map을 저장할 변수 생성 ( x, y )
	int myXPosition = 0, myYPosition = 0; //나의 x, y좌표
	int escapeXPosition = 0, escapeYPosition = 0; //탈출구의 x, y좌표
	char inputKey; //입력받을 문자

	//탈출구 위치 설정하기. 
	while ((escapeXPosition == 0) && (escapeYPosition == 0))
	{
		escapeXPosition = rand() % mapHeight;
		escapeYPosition = rand() % mapWidth;
	}

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