/*
	1) �ؽ�Ʈ�� ����Ǵ� ����
	2) ������ ���۵Ǹ� ������ �̸��� ���̵��� �Է�
	3) ���̵��� ���� ������ HP / ������ �Ǵ� ������ ���ڰ� ����
	4) ������ ���۵Ǹ� ������ ���͸� ���� ������ ������ ����Ǵ� ���
	5) ���͸� ������ �����ϰ� ���� ȹ���Ѵ�. ( 0 ~ 100 )
	6) ���͸� ������ ������ ��� Ž���� ��, ������ �鸱���� �����Ѵ�.
	7) ������ �鸣�� ���� �Ҹ��ؼ� HP�� ȸ���� �� �ִ�.
	8) ���� ����� ���� ���� ���� �̷������. //���Ϳ� ���и� �ܷ�, ���� �ٽ�, ���� HP�� �Ҹ�(���ʹ� 1�� ���� ���.)
	9) ���͸� �� ������ Claer / HP�� 0�� �Ǹ� ���ӿ���.
	10) Ŭ����� ���� ��Ʈ ���.
*/

#include<iostream>
#include<string>
#include<Windows.h>
#include<ctime>

using namespace std;

int main()
{

	// < ������ �̸��� ���̵� �Է� >

	string heroesName; //����� �̸�
	int heroesHp; //������� ü��
	int money = 0; //�ݾ�
	int randomGetMoney;

	int difficulty; //���̵�
	int monsterCount; //���� ��

	const string SCISSORS = "����"; //0
	const string ROCK = "����"; //1
	const string PAPER = "��"; //2
	string monsterSelect = "������";
	string inputString; // ����, ����, �� �Է¹��� ����
	int inputSelect; //����(0)�� �� ��, Ž��(1)�� �� �� ���� �Է¹��� ����

	srand(time(NULL));
	
	cout << "������ �̸��� �Է��ϼ��� : ";
	cin >> heroesName;

	cout << "���̵��� �Է��ϼ���(1~10) : ";
	cin >> difficulty;

	heroesHp = (int)(10 - difficulty * 0.5f);
	monsterCount = (int)(difficulty * 2.7f);

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

	system("cls"); //ȭ�� �����

	while (true)
	{
		cout << " < ���� ���� > " << endl;
		cout << "������ HP : " << heroesHp << endl;
		cout << "���� ���� : " << monsterCount << "����" << endl;

		int randNumber = rand() % 3; // 0 ~ 2 

		cout << "����, ����, �� �Է� : ";
		cin >> inputString;
		cout << "=========================" << endl;
		if (inputString == SCISSORS) //0
		{
			if (randNumber == 0)
			{
				cout << "��� : �����ϴ�." << endl;
				cout << "�ٽ� �Է��� �ּ���." << endl;
				cout << endl;
			}
			else if (randNumber == 1)
			{
				cout << "��� : �����ϴ�." << endl;
				cout << "���� ���� ü�� : " << --heroesHp << endl;

				if (heroesHp <= 0)
				{
					cout << "�������� �й��Ͽ����ϴ�." << endl;
					break;
				}
			}
			else
			{
				cout << "��� : �¸�! " << endl;
				randomGetMoney = rand() % 100 + 1;
				money += randomGetMoney;
				cout << randomGetMoney << "�� ȹ�� �ϼ̽��ϴ�." << endl;
				cout << "���� ���� ü�� : " << heroesHp << endl;
				cout << "���� ���� �� : " << --monsterCount << endl;
				cout << "���� �ݾ� : " << money << endl;
				cout << "==========================================" << endl;
				Sleep(2000);

				if (monsterCount <= 0) //���� ������ ���� 0 �����̸�
				{
					cout << "�����մϴ�." << heroesName << "��. �¸��ϼ̽��ϴ�." << endl;
					break;
				}

				cout << "���� �̵� : 0, ���� Ž�� : 1 => ";
				cin >> inputSelect;

				int portion;

				switch (inputSelect)
				{
				case 0: //�������� �̵�
					system("cls");
					cout << "< ���� �Դϴ�. >" << endl;
					cout << "hp 1 ȸ���ϱ�(�ݾ�100��): 0�Է� " << endl;
					cout << "hp full ȸ���ϱ�(�ݾ�300��) : 1�Է� " << endl;
					cout << "���� ������ : 2�Է�" << endl;
					cout << "==========================================" << endl;
					cout << "���� ���� ü�� : " << heroesHp << endl;
					cout << "���� ���� �� : " << monsterCount << endl;
					cout << "���� �ݾ� : " << money << endl;
					while (true)
					{
						cout << "��ȣ�� �Է��� �ּ��� : ";
						cin >> portion;
						if (portion == 0)
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
						else if (portion == 1)
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

					break;

				case 1: //���� Ž��
					cout << "�������� �̵��մϴ�..." << endl;
					Sleep(2000);
					system("cls");

					break;

				default:
					break;
				}
			}
		}
		if (inputString == ROCK) //1
		{
			if (randNumber == 1)
			{
				cout << "��� : �����ϴ�." << endl;
				cout << "�ٽ� �Է��� �ּ���." << endl;
				cout << endl;
			}
			else if (randNumber == 2)
			{
				cout << "��� : �����ϴ�." << endl;
				cout << "���� ���� ü�� : " << --heroesHp << endl;

				if (heroesHp <= 0)
				{
					cout << "�������� �й��Ͽ����ϴ�." << endl;
					break;
				}
			}
			else
			{
				cout << "��� : �¸�! " << endl;
				randomGetMoney = rand() % 100 + 1;
				money += randomGetMoney;
				cout << randomGetMoney << "�� ȹ�� �ϼ̽��ϴ�." << endl;
				cout << "���� ���� ü�� : " << heroesHp << endl;
				cout << "���� ���� �� : " << --monsterCount << endl;
				cout << "���� �ݾ� : " << money << endl;
				cout << "==========================================" << endl;

				Sleep(2000);

				if (monsterCount <= 0) //���� ������ ���� 0 �����̸�
				{
					cout << "�����մϴ�." << heroesName << "��. �¸��ϼ̽��ϴ�." << endl;
					break;
				}

				cout << "���� �̵� : 0�Է�, ���� Ž�� : 1�Է� => ";
				cin >> inputSelect;

				int portion;

				switch (inputSelect)
				{
				case 0: //�������� �̵�
					system("cls");
					cout << "< ���� �Դϴ�. >" << endl;
					cout << "hp 1 ȸ���ϱ�(�ݾ�100��): 0�Է� " << endl;
					cout << "hp full ȸ���ϱ�(�ݾ�300��) : 1�Է� " << endl;
					cout << "���� ������ : 2�Է�" << endl;
					cout << "==========================================" << endl;
					cout << "���� ���� ü�� : " << heroesHp << endl;
					cout << "���� ���� �� : " << monsterCount << endl;
					cout << "���� �ݾ� : " << money << endl;

					while (true)
					{
						cout << "��ȣ�� �Է��� �ּ��� : ";
						cin >> portion;
						if (portion == 0)
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
						else if (portion == 1)
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

					break;

				case 1: //���� Ž��
					cout << "�������� �̵��մϴ�..." << endl;
					Sleep(2000);
					system("cls");

					break;

				default:
					break;
				}
			}
		}
		if (inputString == PAPER) //2
		{
			if (randNumber == 2)
			{
				cout << "��� : �����ϴ�." << endl;
				cout << "�ٽ� �Է��� �ּ���." << endl;
				cout << endl;
			}
			else if (randNumber == 1)
			{
				cout << "��� : �����ϴ�." << endl;
				cout << "���� ���� ü�� : " << --heroesHp << endl;
				
				if (heroesHp <= 0)
				{
					cout << "�������� �й��Ͽ����ϴ�." << endl;
					break;
				}
			}
			else
			{
				cout << "��� : �¸�! " << endl;
				randomGetMoney = rand() % 100 + 1;
				money += randomGetMoney;
				cout << randomGetMoney << "�� ȹ�� �ϼ̽��ϴ�." << endl;
				cout << "���� ���� ü�� : " << heroesHp << endl;
				cout << "���� ���� �� : " << --monsterCount << endl;
				cout << "���� �ݾ� : " << money << endl;

				Sleep(2000);

				if (monsterCount <= 0) //���� ������ ���� 0 �����̸�
				{
					cout << "�����մϴ�." << heroesName << "��. �¸��ϼ̽��ϴ�." << endl;
					break;
				}

				cout << "���� �̵� : 0, ���� Ž�� : 1 => ";
				cin >> inputSelect;

				int portion;

				switch (inputSelect)
				{
				case 0: //�������� �̵�
					system("cls");
					cout << "< ���� �Դϴ�. >" << endl;
					cout << "hp 1 ȸ���ϱ�(�ݾ�100��): 0�Է� " << endl;
					cout << "hp full ȸ���ϱ�(�ݾ�300��) : 1�Է� " << endl;
					cout << "���� ������ : 2�Է�" << endl;
					cout << "==========================================" << endl;
					cout << "���� ���� ü�� : " << heroesHp << endl;
					cout << "���� ���� �� : " << monsterCount << endl;
					cout << "���� �ݾ� : " << money << endl;
					cout << "==========================================" << endl;

					while (true)
					{
						cout << "��ȣ�� �Է��� �ּ��� : ";
						cin >> portion;
						if (portion == 0)
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
						else if (portion == 1)
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

					break;

				case 1: //���� Ž��
					cout << "�������� �̵��մϴ�..." << endl;
					Sleep(2000);
					system("cls");

					break;

				default:
					break;
				}
			}
		}

		cout << "=========================" << endl;
	}
	return 0;
}