#include <iostream>
#include <string>
#include <conio.h>
#include <ctime>
#include <Windows.h>
#include <malloc.h>

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

//���� ����ü
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

	const int mapWidth = 10; //�� ũ��
	const int mapHeight = 10; //�� ũ��
	char map[mapWidth][mapHeight]; //map�� ������ ���� ���� ( x, y )
	int myXPosition = 0, myYPosition = 0; //���� x, y��ǥ
	int escapeXPosition = 0, escapeYPosition = 0; //Ż�ⱸ�� x, y��ǥ
	char inputKey; //�Է¹��� ����

	//�߰�����
	int storeXPosition{0}, storeYPosition{0};  //������ x, y��ġ.

	//

#pragma endregion

#pragma region HerosGameVariable

	string heroesName; //����� �̸�
	int heroesHp; //������� ü��
	int money = 0; //�ݾ�
	int randomGetMoney;

	int difficulty; //���̵�
	int monsterCount; //���� ��

	const string SCISSORS = "����"; //0
	const string ROCK = "����"; //1
	const string PAPER = "��"; //2
	
	int inputSPR; // ����, ����, �� �Է¹��� ����

	//�߰�����
	const int difficultyOne = 5; //���̵� 1
	const int difficultyTwo = 10; //���̵� 2
	const int difficultyThree = 15; //���̵� 3
	const int difficultyFour = 20; //���̵� 4
	string gyeongillStuName[] = { "�����", "��â��", "�����", "�ڼ���", "������",
		"�迵��", "������", "ȫ����", "������", "������", "��û��", "������", "������",
		"������", "������", "��ٷ�" };
	
	int stuNumberTotal = sizeof(gyeongillStuName) / sizeof(gyeongillStuName[0]); //�� �л��� ����

#pragma endregion
	
	// 4. �������ðڽ��ϱ�?�� ���� ���� ����
	
#pragma region �ʱ�κ� [ �����̸� ����~������ ��ӵ˴ϴ� ] ��±���

	cout << "������ �̸��� �Է��ϼ��� : ";
	cin >> heroesName;

	cout << "���̵��� �Է��ϼ���(1~10) : ";
	cin >> difficulty;

	heroesHp = (int)(11 - difficulty * 0.6f);

#pragma region ���̵� �� ���� ��������

	//���� �߰��� ����. ���̵� �����ϱ� �� ���� ����
	if (difficulty < 4) //���̵��� 4���� ���� ��� ( ���̵� 1 )
	{
		monsterCount = difficultyOne;
		Monster monsters[difficultyOne];
		int tmp[difficultyOne]; //�̸��� �����ϰ� ���� ���� 5���� ���ڸ� �Է¹��� ����

		//������ �� ��ŭ for���� ���� �̸��� �����Ѵ�.
		//////////////////////////////////////////////////�ζ� ��ȣ �̴� ���
		for (int i = 0; i < monsterCount; i++)
		{
			tmp[i] = rand() % stuNumberTotal;


		}
	}
	else if (difficulty < 7) //���̵��� 4�̻� 7�̸��� ��� ( ���̵� 2 )
	{
		monsterCount = difficultyTwo;
		Monster monsters[difficultyTwo];
		int tmp[difficultyTwo]; //�̸��� �����ϰ� ���� ���� 10���� ���ڸ� �Է¹��� ����
		
		//������ �� ��ŭ for���� ���� �̸��� �����Ѵ�.
		for (int i = 0; i < monsterCount; i++)
		{
			tmp[i] = rand() % stuNumberTotal;
		}
	}
	else if (difficulty < 9)
	{
		monsterCount = difficultyThree;
		Monster monsters[difficultyThree];
		int tmp[difficultyThree]; //�̸��� �����ϰ� ���� ���� 15���� ���ڸ� �Է¹��� ����

		//������ �� ��ŭ for���� ���� �̸��� �����Ѵ�.
		for (int i = 0; i < monsterCount; i++)
		{
			tmp[i] = rand() % stuNumberTotal;
		}
	}
	else
	{
		monsterCount = difficultyFour;
		Monster monsters[difficultyFour];
		int tmp[difficultyFour]; //�̸��� �����ϰ� ���� ���� 20���� ���ڸ� �Է¹��� ����

		//������ �� ��ŭ for���� ���� �̸��� �����Ѵ�.
		for (int i = 0; i < monsterCount; i++)
		{
			tmp[i] = rand() % stuNumberTotal;
		}
	}

#pragma endregion

#pragma region ���� �̸�, ü�� �����ϱ�

	




#pragma endregion


	//���̵��� ���� ������ HP, ���� ���ڰ� �����ȴ�.
	//--> ���̵� : difficulty ==> ������ HP : 10 - difficulty*0.5 , ���� ���� : difficulty * 2.7f�� ���� ��ȯ;
	cout << "< ���̵��� ���� HP�� ���͸� �����մϴ�. >" << endl;
	Sleep(1500);

	cout << "������ HP : " << heroesHp << endl;

	Sleep(1000);
	cout << "���� ���� : " << monsterCount << endl;

	Sleep(1500);
	cout << "��� ���͸� �� ���� ������ ������ ��ӵ˴ϴ�..." << endl;
	cout << endl;
	Sleep(2000);

#pragma endregion

#pragma region Ż�ⱸ ��ġ, ���� ��ġ ����.

	//Ż�ⱸ ��ġ �����ϱ�. 
	while ((escapeXPosition == 0) && (escapeYPosition == 0))
	{
		escapeXPosition = rand() % mapHeight;
		escapeYPosition = rand() % mapWidth;
	}

#pragma endregion

	

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