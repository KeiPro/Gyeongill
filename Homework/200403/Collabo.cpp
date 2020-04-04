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
	int myPrevXPosition = 0, myPrevYPosition = 0; //������ ������ �� ��ǥ�� �����ϴ� ����.
	int storeXPosition = 0, storeYPosition = 0; //������ x, y��ǥ
	char inputKey; //�Է¹��� ����


#pragma endregion

#pragma region HerosGameVariable

	string heroesName; //����� �̸�
	int heroesHp; //������� ü��
	int money = 0; //�ݾ�
	int randomGetMoney;

	int difficulty; //���̵�
	int monsterCount; //���� ��
	bool positionOverlapCheck; //������ ��ġ�� ��ġ������ üũ�ϴ� ����

	const int SCISSORS = 1; //����
	const int ROCK = 2; //����
	const int PAPER = 3; //��
	
	int inputSPR; // ����, ����, �� �Է¹��� ����
	int portion; //������ ��ȣ�� �Է��� ����
	int randNumber; //��ǻ�Ͱ� �����ϰ� ������������ ������ ����

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
	
	cout << "������ �̸��� �Է��ϼ��� : ";
	cin >> heroesName;

	cout << "���̵��� �Է��ϼ���(1~10) : ";
	cin >> difficulty;

	heroesHp = (int)(11 - difficulty * 0.6f); //���̵��� ���� ü�ºκ� ����.

#pragma region ���� ��ġ ����

	//Ż�ⱸ ��ġ �����ϱ�. 
	while ((storeXPosition == 0) && (storeYPosition == 0))
	{
		storeXPosition = rand() % mapHeight;
		storeYPosition = rand() % mapWidth;
	}

#pragma endregion
	
#pragma region ���̵� (1~3)
	if (difficulty < 4) //���̵��� 4���� ���� ��� ( ���̵� 1 )
	{
		monsterCount = difficultyOne;
		Monster monsters[difficultyOne]; //�ʱ�ȭ
		//int tmp[difficultyOne]; //�̸��� �����ϰ� ���� ���� 5���� ���ڸ� �Է¹��� ����

		//������ �� ��ŭ for���� ���� �̸��� �����Ѵ�.
		for (int i = 0; i < monsterCount; i++)
		{
			monsters[i].name = gyeongillStuName[rand() % stuNumberTotal];  //���� �̸� ����. �ߺ��̸� ����
			monsters[i].hp = (rand() % 5 + 1); // 1~5�� �������� ü�� �ο�.
			
		}
	}
#pragma endregion
#pragma region ���̵� (3~6)
	else if (difficulty < 7) //���̵��� 4�̻� 7�̸��� ��� ( ���̵� 2 )
	{
		monsterCount = difficultyTwo;
		Monster monsters[difficultyTwo];
		//int tmp[difficultyTwo]; //�̸��� �����ϰ� ���� ���� 10���� ���ڸ� �Է¹��� ����
		
		//������ �� ��ŭ for���� ���� �̸��� �����Ѵ�.
		for (int i = 0; i < monsterCount; i++)
		{
			monsters[i].name = gyeongillStuName[rand() % stuNumberTotal]; //���� �̸� ���� �ߺ� ����
			monsters[i].hp = (rand() % 4 + 2); // 2~5�� �������� ü�� �ο�.

			//tmp[i] = rand() % stuNumberTotal;
		}
	}
#pragma endregion
#pragma region ���̵� (7~8)
	else if (difficulty < 9)
	{
		monsterCount = difficultyThree;
		Monster monsters[difficultyThree];
		//int tmp[difficultyThree]; //�̸��� �����ϰ� ���� ���� 15���� ���ڸ� �Է¹��� ����

		//������ �� ��ŭ for���� ���� �̸��� �����Ѵ�.
		for (int i = 0; i < monsterCount; i++)
		{
			
			monsters[i].name = gyeongillStuName[rand() % stuNumberTotal]; ///���� �̸� ���� �ߺ� ����
			monsters[i].hp = (rand() % 5 + 3); // 3~7�� �������� ü�� �ο�.

			//tmp[i] = rand() % stuNumberTotal;
		}
	}
#pragma endregion
#pragma region ���̵� (9~10)
	else //���̵� 9, 10
	{
		monsterCount = difficultyFour;
		Monster monsters[difficultyFour];
		//int tmp[difficultyFour]; //�̸��� �����ϰ� ���� ���� 20���� ���ڸ� �Է¹��� ����

		//������ �� ��ŭ for���� ���� �̸��� �����Ѵ�.
		for (int i = 0; i < monsterCount; i++)
		{
			
			monsters[i].name = gyeongillStuName[rand() % stuNumberTotal]; //���� �̸� ���� �ߺ� ����
			monsters[i].hp = (rand() % 5 + 4); // 4~8�� �������� ü�� �ο�.

#pragma region ������ ��ǥ�� �����ϴ� while��

			while (true) //���� ��ġ�� ���
			{
				positionOverlapCheck = false; //�⺻�� false�� ����.
				monsters[i].monX = rand() % mapHeight;
				monsters[i].monY = rand() % mapWidth;

				if ((monsters[i].monX == myXPosition && monsters[i].monY == myYPosition) //���Ͱ� �� ��ġ�� ���
					|| (monsters[i].monX == storeXPosition && monsters[i].monY == storeYPosition)) //���Ͱ� ���� ��ġ�� ���
				{
					continue; //�ٽ� while������ ���ư� ������ ��ǥ�� �ٽ� �����Ѵ�.
				}

				//���͵鳢�� ��ǥ�� ��ġ�� �ʱ� ���� ����. 
				//i==0�� ���� ù ��° ���͸� �����ϴ� ���̹Ƿ� �ٸ� ������ ��ġ�� ������ ���� �ʴ´�.
				if (i != 0)
				{
					for (int j = 0; j < i; j++)
					{
						//���� ������ ������ ��ġ�� ��ĥ ��� if�� ������ ����.
						if (monsters[i].monX == monsters[j].monX && monsters[i].monY == monsters[j].monY)
						{
							positionOverlapCheck = true;
							break;
						}
					}

					//�� if���� ���� ��ġ�Ĵ� ������ true�� �Ǹ�, continue�� ���� �ٽ� while���� �ݺ��ϰ� �ȴ�.
					if (positionOverlapCheck == true)
						continue;
				}

				break; //���Ͱ� �� ��ġ�� �ƴϰ�, ���� ��ġ�� �ƴϰ�, ���͵鳢�� ��ǥ�� ��ġ�� �����Ƿ� break�� ���� ������.
			}

			cout << i << "�� monsters��ǥ : " << monsters[i].monX << ", " << monsters[i].monY << endl;

#pragma endregion

		}
#pragma region �ܼ� �ؽ�Ʈ ���

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

#pragma region �̷� �� �����, ����, ���� ��ġ ����

		//�ʿ� �� ��ġ, Ż�ⱸ, map�� �����ϴ� for��.
		for (int i = 0; i < mapHeight; i++)
		{
			for (int j = 0; j < mapWidth; j++)
			{
				map[i][j] = '#';
			}
		}

		map[0][0] = 'O'; //�� ��ġ ����
		map[storeXPosition][storeYPosition] = '$'; //����ǥ��
		for (int i = 0; i < monsterCount; i++) //���� ��ġ ����
		{
			map[monsters[i].monX][monsters[i].monY] = 'M';
		}
		
#pragma endregion

#pragma region �̷� ��� �� ������
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

			inputKey = _getch(); //����ڷκ��� �Է¹޴� _getch()�Լ�.

#pragma region ������
			if (inputKey == 'w')
			{
				if (myXPosition == 0) //�ö� ���� ������ ����ؼ� while���� ������.
					continue;
				else
				{
					//�ܼ��ϰ� ���ͳ� ������ ������ �̵��ϴ� �ڵ�
					map[myXPosition][myYPosition] = '#';
					myPrevXPosition = myXPosition, myPrevYPosition = myYPosition;
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
					myPrevXPosition = myXPosition, myPrevYPosition = myYPosition;
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
					myPrevXPosition = myXPosition, myPrevYPosition = myYPosition;
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
					myPrevXPosition = myXPosition, myPrevYPosition = myYPosition;
					myYPosition++;
					map[myXPosition][myYPosition] = 'O';
				}
			}
#pragma endregion

			//�������� �����ϰ� ���� ��������, ���������� üũ

#pragma region ����
			//���������� üũ�ϴ� �ڵ�
			if (myXPosition == storeXPosition && myYPosition == storeYPosition)
			{
				//������ ���� ������ ���
				system("cls");
				cout << "< ���� �Դϴ�. >" << endl;
				cout << "hp 1 ȸ���ϱ�(�ݾ�100��): 1�Է� " << endl;
				cout << "hp full ȸ���ϱ�(�ݾ�300��) : 2�Է� " << endl;
				cout << "���� ������ : 3�Է�" << endl;
				cout << "==========================================" << endl;
				cout << "���� ���� ü�� : " << heroesHp << endl;
				cout << "���� ���� �� : " << monsterCount << endl;
				cout << "���� �ݾ� : " << money << endl;
				cout << "==========================================" << endl;

				while (true)
				{
					cout << "��ȣ�� �Է��� �ּ��� : ";
					cin >> portion;
					if (portion == 1)
					{
						//���� ���� ���
						if (money < 100)
						{
							cout << "�ݾ��� �����մϴ�." << endl;
						}
						//ü���� full�� ���
						else if (heroesHp >= (int)(10 - difficulty * 0.5f))
						{
							cout << "ü���� Ǯ �Դϴ�." << endl;
						}
						//ü���� full�� �ƴϰ� ���� ����� ���
						else
						{
							money -= 100;
							heroesHp += 1;
							cout << "ü���� 1ȸ�� �Ǿ����ϴ�. " << endl;
							cout << "���� ���� ü�� : " << heroesHp << endl;
							cout << "���� ���� �� : " << monsterCount << endl;
						}
					}
					else if (portion == 2)
					{
						//���� ���� ���
						if (money < 300)
						{
							cout << "�ݾ��� �����մϴ�." << endl;
						}
						//ü���� full�� ���
						else if (heroesHp >= (int)(10 - difficulty * 0.5f))
						{
							cout << "ü���� Ǯ �Դϴ�." << endl;
						}
						//ü���� full�� �ƴϰ� ���� ����� ���
						else
						{
							money -= 300;
							heroesHp = (int)(10 - difficulty * 0.5f);
							cout << "ü���� Ǯ�� ȸ���Ǿ����ϴ�. " << endl;
							cout << "���� ���� ü�� : " << heroesHp << endl;
							cout << "���� ���� �� : " << monsterCount << endl;
						}
					}
					else
					{
						cout << "�������� �����ϴ�." << endl;
						Sleep(2000);
						system("cls");
						break;
					}
				}
				myXPosition = myPrevXPosition, myYPosition = myPrevYPosition;
				map[myXPosition][myYPosition] = 'O';
				map[storeXPosition][storeYPosition] = '$';
			}
#pragma endregion

#pragma region ���� ����

			//���������� üũ�ϴ� �ڵ�
			for (int i = 0; i < monsterCount; i++)
			{
				if (myXPosition == monsters[i].monX && myYPosition == monsters[i].monY)
				{
					//������������ �ϴ� �ڵ�
					randNumber = (rand() % 3 + 1); //��ǻ�� ���������� ����

					cout << "����(1), ����(2), ��(3) �Է� : ";
					cin >> inputSPR;

					if (inputSPR == SCISSORS) //0
					{
						if (randNumber == SCISSORS)
						{
							cout << "��� : �����ϴ�." << endl;
							cout << "�ٽ� �Է��� �ּ���." << endl;
							cout << endl;
						}
						else if (randNumber == ROCK)
						{
							cout << "��� : �����ϴ�." << endl;
							cout << "���� ���� ü�� : " << --heroesHp << endl;

							if (heroesHp <= 0)
							{
								cout << "�������� �й��Ͽ����ϴ�." << endl;
								break;
							}
						}
					}

				}

			}

#pragma endregion

		}
	}
#pragma endregion

	//while (true)
	//{
	//	system("cls");

	//	//���� ����ؼ� ����ϴ� for��
	//	for (int i = 0; i < mapHeight; i++)
	//	{
	//		for (int j = 0; j < mapWidth; j++)
	//		{
	//			cout << map[i][j];
	//		}
	//		cout << endl;
	//	}

	//	//Finish �ڵ�.
	//	//if ((myXPosition == escapeXPosition) && (myYPosition == escapeYPosition))
	//	//{
	//	//	cout << "Ż���ϼ̽��ϴ�! ���ϵ帳�ϴ�!" << endl;
	//	//	break;
	//	//}

	//	inputKey = _getch(); //����ڷκ��� �Է¹޴� _getch()�Լ�.

	//	if (inputKey == 'w')
	//	{
	//		if (myXPosition == 0) //�ö� ���� ������ ����ؼ� while���� ������.
	//			continue;
	//		else
	//		{
	//			map[myXPosition][myYPosition] = '#';
	//			myXPosition--;
	//			map[myXPosition][myYPosition] = 'O';
	//		}
	//	}

	//	if (inputKey == 'a')
	//	{
	//		if (myYPosition == 0) //�������� �� ���� ������ ����ؼ� while���� ������.
	//			continue;
	//		else
	//		{
	//			map[myXPosition][myYPosition] = '#';
	//			myYPosition--;
	//			map[myXPosition][myYPosition] = 'O';
	//		}
	//	}

	//	if (inputKey == 's')
	//	{
	//		if (myXPosition == mapHeight - 1) //�Ʒ��� �� ���� ������ ����ؼ� while���� ������.
	//			continue;
	//		else
	//		{
	//			map[myXPosition][myYPosition] = '#';
	//			myXPosition++;
	//			map[myXPosition][myYPosition] = 'O';
	//		}
	//	}

	//	if (inputKey == 'd')
	//	{
	//		if (myYPosition == mapWidth - 1) //���������� �� ���� ������ ����ؼ� while���� ������.
	//			continue;
	//		else
	//		{
	//			map[myXPosition][myYPosition] = '#';
	//			myYPosition++;
	//			map[myXPosition][myYPosition] = 'O';
	//		}
	//	}
	//}

	return 0;
}