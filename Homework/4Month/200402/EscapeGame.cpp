#include <iostream>
#include <string>
#include <conio.h>
#include <ctime>

using namespace std;
/*
Ż�����
10 * 10 ũ���� ���� �����.
w, a, s, dŰ �Է��� ���ؼ� �����¿� �̵��� �Ѵ�.
���������� �׻�(0, 0).
Ż��������(0, 0)�� �����ϰ� ������ ��ġ�� ���� = > Ż�ⱸ X ����.

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

	const int mapWidth = 10; //�� ũ��
	const int mapHeight = 10; //�� ũ��
	char map[mapWidth][mapHeight]; //map�� ������ ���� ���� ( x, y )
	int myXPosition = 0, myYPosition = 0; //���� x, y��ǥ
	int escapeXPosition = 0, escapeYPosition = 0; //Ż�ⱸ�� x, y��ǥ
	char inputKey; //�Է¹��� ����

	//Ż�ⱸ ��ġ �����ϱ�. 
	while ((escapeXPosition == 0) && (escapeYPosition == 0))
	{
		escapeXPosition = rand() % mapHeight;
		escapeYPosition = rand() % mapWidth;
	}

	//�ʿ� �� ��ġ, Ż�ⱸ, map�� �����ϴ� for��.
	for (int i = 0; i < mapHeight; i++)
	{
		for (int j = 0; j < mapWidth; j++)
		{
			if (i == 0 && j == 0) //�� ��ġ ����
			{
				map[myXPosition][myYPosition] = 'O';
			}
			else if ((i == escapeXPosition) && (j == escapeYPosition)) //Ż�ⱸ ���
			{
				map[escapeXPosition][escapeYPosition] = 'X';
			}
			else //map����
			{
				map[i][j] = '#';
			}
		}
	}

	while (true)
	{
		system("cls");

		//���� ����ؼ� ����ϴ� for��
		for (int i = 0; i < mapHeight; i++)
		{
			for (int j = 0; j < mapWidth; j++)
			{
				cout << map[i][j];
			}
			cout << endl;
		}

		//Finish �ڵ�.
		if ((myXPosition == escapeXPosition) && (myYPosition == escapeYPosition))
		{
			cout << "Ż���ϼ̽��ϴ�! ���ϵ帳�ϴ�!" << endl;
			break;
		}

		inputKey = _getch(); //����ڷκ��� �Է¹޴� _getch()�Լ�.

		if (inputKey == 'w')
		{
			if (myXPosition == 0) //�ö� ���� ������ ����ؼ� while���� ������.
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
			if (myYPosition == 0) //�������� �� ���� ������ ����ؼ� while���� ������.
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
			if (myXPosition == mapHeight - 1) //�Ʒ��� �� ���� ������ ����ؼ� while���� ������.
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
			if (myYPosition == mapWidth - 1) //���������� �� ���� ������ ����ؼ� while���� ������.
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