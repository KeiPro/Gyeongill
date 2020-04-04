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
	int randomGetMoney; //���͸� ���� �� �����ϰ� ���� ���� ����
	int damage = 1; //������ ���ݷ� 

	int difficulty; //���̵�
	int monsterCount; //���� ��
	bool positionOverlapCheck; //������ ��ġ�� ��ġ������ üũ�ϴ� ����
	int fightAndRun; //�ο��� ���������� �Է¹��� ����
	bool victory = false; //���Ϳ� �ο� �̰峪 ������ �Ǵ��� ����

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

	heroesHp = (int)(15 - difficulty * 0.5f); //���̵��� ���� ü�ºκ� ����.

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

		cout << endl;
		cout << " * * < ���� ��ǥ���� > * * " << endl;
		cout << endl;
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
			if (i < 6)
				Sleep(100);
			else if (i < 7)
				Sleep(300);
			else if (i < 8)
				Sleep(400);
			else if (i < 10)
				Sleep(800);
			else
				Sleep(100);

#pragma endregion

		}
#pragma region �ܼ� �ؽ�Ʈ ���
		cout << endl;
		cout << "< ���̵��� ���� HP�� ���͸� �����մϴ�. >" << endl;
		Sleep(1500);

		cout << " - ������ HP : " << heroesHp << endl;

		Sleep(1000);
		cout << " - ���� ���� : " << monsterCount << endl;
		Sleep(1500);

		cout << " >> ��� ���͸� �� ���������� ������ ��ӵ˴ϴ�..." << endl;
		Sleep(2000);

		cout << " >> ��ø� ��ٷ� �ּ���. ����� ������ ���۵˴ϴ�. ";
		Sleep(3000);

		cout << endl;

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

#pragma region �̷� ��� �� ������ ����.
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

			cout << endl;
			cout << " * * < ������ ������ ���� ���� > * * " << endl;
			cout << endl;
			cout << " - ������ : w, a, s, d " << endl;
			cout << " - ���� ��ġ : O " << endl;
			cout << " - ���� ��ġ : $ " << endl;
			cout << " - ���� ��ġ : M " << endl;
			cout << endl;
			cout << "����)" << endl;
			cout << "\t1. ������ ������ ���͸� ��� ������ �¸��ϴ� �����Դϴ�. " << endl;
			cout << "\t2. ���Ϳ� ����ġ�� ������ ������ ������ �� �ֽ��ϴ�. " << endl;
			cout << "\t\t2-1). ������ �����ϸ� ���������� ������ �����մϴ�." << endl;
			cout << "\t\t2-2). ������ �����ϸ� �����ϱ� �� ��Ȳ���� ���ư��� �˴ϴ�." << endl;
			cout << "\t\t\t( ������ �ϴ� ��, �����ĵ� ������ ü���� �����Ǵ� �Ƚ��ϼ���!! )" << endl;
			cout << "\t3. ���͸� ������ ���� �������� ȹ���� �� �ֽ��ϴ�." << endl;
			cout << "\t4. ȹ���� ���� ������ �������� ���ݷ��� �ø��ų� ü���� ȸ���ϼ���. " << endl;

			inputKey = _getch(); //����ڷκ��� �Է¹޴� _getch()�Լ�.

#pragma region ������
			switch (inputKey)
			{
			case 'w':

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

				break;

			case 'a':

				if (myYPosition == 0) //�������� �� ���� ������ ����ؼ� while���� ������.
					continue;
				else
				{
					map[myXPosition][myYPosition] = '#';
					myPrevXPosition = myXPosition, myPrevYPosition = myYPosition;
					myYPosition--;
					map[myXPosition][myYPosition] = 'O';
				}

				break;

			case 's':

				if (myXPosition == mapHeight - 1) //�Ʒ��� �� ���� ������ ����ؼ� while���� ������.
					continue;
				else
				{
					map[myXPosition][myYPosition] = '#';
					myPrevXPosition = myXPosition, myPrevYPosition = myYPosition;
					myXPosition++;
					map[myXPosition][myYPosition] = 'O';
				}

				break;

			case 'd':

				if (myYPosition == mapWidth - 1) //���������� �� ���� ������ ����ؼ� while���� ������.
					continue;
				else
				{
					map[myXPosition][myYPosition] = '#';
					myPrevXPosition = myXPosition, myPrevYPosition = myYPosition;
					myYPosition++;
					map[myXPosition][myYPosition] = 'O';
				}

				break;

			default:
				continue;
				break;
			}
			
#pragma endregion

#pragma region ����
			//���������� üũ�ϴ� �ڵ�
			if (myXPosition == storeXPosition && myYPosition == storeYPosition)
			{
				//������ ���� ������ ���
				while (true)
				{
					system("cls");
					cout << endl;
					cout << "< �������~ " << heroesName << "��. ���ϻ��� �Դϴ�. >" << endl;
					cout << endl;
					cout << "=========================================" << endl;
					cout << "| hp   1  ȸ���ϱ�(�ݾ�100��) :\t 1�Է�\t| " << endl;
					cout << "| hp full ȸ���ϱ�(�ݾ�200��) :\t 2�Է�\t|" << endl;
					cout << "| ������ 1�����ϱ� (�ݾ�300��) : 3�Է�\t| " << endl;
					cout << "| ���� ������\t\t\t: 4�Է� |" << endl;
					cout << "=========================================" << endl;
					cout << endl;
					cout << " * * < �� �� �� �� > * * " << endl;
					cout << endl;
					cout << "< - �̸� : " << heroesName << " > " << endl;
					cout << "< - ���ݷ� : " << damage << " >" << endl;
					cout << "< - ���� ���� ü�� : " << heroesHp << " >" << endl;
					cout << "< - ���� ���� �� : " << monsterCount << " >" << endl;
					cout << "< - ���� �ݾ� : " << money << " >" << endl;
					cout << endl;

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
						else if (heroesHp >= (int)(15 - difficulty * 0.5f))
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
						if (money < 200)
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
							money -= 200;
							heroesHp = (int)(10 - difficulty * 0.5f);
							cout << "ü���� Ǯ�� ȸ���Ǿ����ϴ�. " << endl;
							cout << "���� ���� ü�� : " << heroesHp << endl;
							cout << "���� ���� �� : " << monsterCount << endl;
						}
					}
					else if (portion == 3)
					{
						if (money < 300)
						{
							cout << "�ݾ��� �����մϴ�." << endl;
						}
						else
						{
							damage++;
							cout << "�������� 1�����Ǿ����ϴ�." << endl;
						}
					}
					else
					{
						cout << "�������� �����ϴ�." << endl;
						Sleep(2000);
						system("cls");
						break;
					}

					Sleep(2000);
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
				if (myXPosition == monsters[i].monX && myYPosition == monsters[i].monY) //���Ϳ� ���� ���.
				{
					victory = false;

					while (true)
					{
						system("cls");
						cout << " < ���� ���� > " << endl;
						cout << "  - �̸� : " << monsters[i].name << endl;
						cout << "  - ü�� : " << monsters[i].hp << endl;
						cout << endl;
						cout << " < ������ ���� > " << endl;
						cout << "  - �̸� : " << heroesName << endl;
						cout << "  - ü�� : " << heroesHp << endl;
						cout << "  - ������ �ݾ� : " << money << endl;
						cout << endl;
						cout << " >> �ο�ðڽ��ϱ�?(0) �������ðڽ��ϱ�?(1) : ";
						cin >> fightAndRun;

						if (fightAndRun != 0)
							break;

						//������������ �ϴ� �ڵ�
						randNumber = (rand() % 3 + 1); //��ǻ�� ���������� ����
						system("cls");
						cout << "���� ����!!" << endl;
						cout << "����(1), ����(2), ��(3) ���ڷ� �Է� : ";
						cin >> inputSPR;

						if (inputSPR == SCISSORS) //1 ���� ������ �� ���
						{
							if (randNumber == SCISSORS) //1
							{
								cout << "��� : �����ϴ�." << endl;
								cout << monsters[i].name << " �� �� : ����" << endl;
								cout << "�ٽ� �Է��� �ּ���." << endl;
								Sleep(1500);
								system("cls");
							}
							else if (randNumber == ROCK) //2
							{
								cout << "��� : �й�..." << endl;
								cout << monsters[i].name << " �� �� : ����" << endl;
								cout << "���� ���� ü�� : " << --heroesHp << endl;

								if (heroesHp <= 0)
								{
									cout << monsters[i].name << " �������� ���� " << heroesName <<
										"���� �й��Ͽ����ϴ�. " << endl;
									exit(0);
								}

								Sleep(1500);
								system("cls");
							}
							else //�̱� ���
							{
								cout << "��� : ��!!" << endl;

								monsters[i].hp -= damage;
								if (monsters[i].hp <= 0)
								{
									monsters[i].monX = -1, monsters[i].monY = -1;

									randomGetMoney = rand() % ( 171 ) + 80; // 80 ~ 250
									money += randomGetMoney;
									cout << monsters[i].name << " ��(��) ��� ��" << randomGetMoney << "����"
										" ȹ��!" << endl;
									cout << "���� ���� ü�� : " << heroesHp << endl;
									cout << "������ �ݾ� : " << money << endl;
									cout << "���� ������ �� : " << monsterCount << endl;

									victory = true;
									Sleep(1500);
									system("cls");
									break;
								}
								else
								{
									cout << heroesName << "���� �������� ������!" << endl;
									Sleep(1500);
								}
							}
						}

						if (inputSPR == ROCK) //1
						{
							if (randNumber == ROCK) //1
							{
								cout << "��� : �����ϴ�." << endl;
								cout << monsters[i].name << " �� �� : ����" << endl;
								cout << "�ٽ� �Է��� �ּ���." << endl;
								Sleep(1500);
								system("cls");
							}
							else if (randNumber == PAPER) //2
							{
								cout << "��� : �й�..." << endl;
								cout << monsters[i].name << " �� �� : ��" << endl;
								cout << "���� ���� ü�� : " << --heroesHp << endl;

								if (heroesHp <= 0)
								{
									cout << monsters[i].name << " �������� ���� " << heroesName <<
										"���� �й��Ͽ����ϴ�. " << endl;
									exit(0);
								}

								Sleep(1500);
								system("cls");
							}
							else //�̱� ���
							{
								cout << "��� : ��!!" << endl;

								monsters[i].hp -= damage;
								if (monsters[i].hp <= 0)
								{
									monsters[i].monX = -1, monsters[i].monY = -1;
									
									randomGetMoney = rand() % (171) + 80; // 80 ~ 250									money += randomGetMoney;
									cout << monsters[i].name << " ��(��) ��� ��" << randomGetMoney << "����"
										" ȹ��!" << endl;
									cout << "���� ���� ü�� : " << heroesHp << endl;
									cout << "������ �ݾ� : " << money << endl;
									cout << "���� ������ �� : " << monsterCount << endl;

									victory = true;
									Sleep(1500);
									system("cls");
									break;
								}
								else
								{
									cout << heroesName << "���� �������� ������!" << endl;
									Sleep(1500);
								}
							}
						}

						if (inputSPR == PAPER) //2
						{
							if (randNumber == PAPER) //2
							{
								cout << "��� : �����ϴ�." << endl;
								cout << monsters[i].name << " �� �� : ��" << endl;
								cout << "�ٽ� �Է��� �ּ���." << endl;
								Sleep(1500);
								system("cls");
							}
							else if (randNumber == SCISSORS) //1
							{
								cout << "��� : �й�..." << endl;
								cout << monsters[i].name << " �� �� : ����" << endl;
								cout << "���� ���� ü�� : " << --heroesHp << endl;

								if (heroesHp <= 0)
								{
									cout << monsters[i].name << " �������� ���� " << heroesName <<
										"���� �й��Ͽ����ϴ�. " << endl;
									exit(0);
								}

								Sleep(1500);
								system("cls");
							}
							else //�̱� ���
							{
								
								cout << "��� : ��!!" << endl;
								
								monsters[i].hp -= damage;
								if (monsters[i].hp <= 0)
								{
									monsters[i].monX = -1, monsters[i].monY = -1;

									randomGetMoney = rand() % (171) + 80; // 80 ~ 250									money += randomGetMoney;
									cout << monsters[i].name << " ��(��) ��� ��" << randomGetMoney << "����"
										" ȹ��!" << endl;
									cout << "���� ���� ü�� : " << heroesHp << endl;
									cout << "������ �ݾ� : " << money << endl;
									cout << "���� ������ �� : " << monsterCount << endl;

									victory = true;
									Sleep(1500);
									system("cls");
									break;
								}
								else
								{
									cout << heroesName << "���� �������� ������!" << endl;
									Sleep(1500);
								}
							}
						}
					}

					if (victory == true)
					{
						break;
					}

					//���������� ���� for���� ����ؼ� üũ���� �ʾƵ� �ȴ�.
					if (fightAndRun != 0)
					{
						myXPosition = myPrevXPosition, myYPosition = myPrevYPosition;
						map[myXPosition][myYPosition] = 'O';
						map[monsters[i].monX][monsters[i].monY] = 'M';

						break;
					}

				}
			}

#pragma endregion

			if (monsterCount <= 0)
			{
				cout << heroesName << "���� ��� ���͸� óġ�ϰ� �¸��ϼ̽��ϴ�!" << endl;
				cout << "������ �ݾ� : " << money << endl;
				cout << "óġ�� ���� ��� : ";
				for (int i = 0; i < monsterCount; i++)
				{
					if (i == monsterCount - 1)
					{
						cout << monsters[i].name;
					}
					else
					{
						cout << monsters[i].name << ", ";
					}
				}
			}

		}
	}
#pragma endregion

	return 0;
}