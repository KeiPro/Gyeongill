#pragma region A ~ Z ������ �� ���� ���

/*
�ǽ�.
A ~ Z Ű �߿� ������ ���� ��ǻ�Ͱ� �����Ѵ�. --> 65 ~ 90(�빮��)
������ �� ���� Ű�� �Է��ؼ� ������ ���� �����.
������ �Է��� Ű�� ������ Ű�� ������ �¸�
Ʋ���� ���� ��ȸ�� �����ְ�, 5�� Ʋ���� ������ �˷��ְ� ���ӿ���

+ Ʋ�� ������ ������ �Էµ� ���ĺ� �տ� �ִ� ���ĺ����� �ڿ� �ִ� ���ĺ����� �˷��ش�.
*/

#include <iostream>
#include <string>
#include <conio.h>
#include <ctime>

using namespace std;

int main()
{

	srand(time(NULL));
	char randChar = rand() % (90 - 65 + 1) + 65; //��ǻ�Ͱ� ������ ������ ����
	cout << (char)randChar << endl;
	int remainChance = 5; //���� ��ȸ

	cout << "��ǻ�Ͱ� ������ �����ڸ� �����ּ���!" << endl;

	cout << "====================================" << endl;
	cout << endl;

	while (remainChance > 0)
	{
		cout << "< ���� ��ȸ : " << remainChance << "> " << endl;
		cout << "�����ڸ� �Է��� �ּ��� : ";
		char inputKey; //�Է¹޴� ����

		inputKey = _getch(); //�������� �Է¹޴� �ڵ� //97~122(�ҹ���)
		cout << inputKey << endl;

		//����ó��
		if (!(inputKey >= 'A' && inputKey <= 'Z') && !(inputKey >= 'a' && inputKey <= 'z'))
		{
			cout << "�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��� �ּ���." << endl;
			cout << endl;
			continue;
		}

		if (inputKey == randChar || (inputKey - 32) == randChar)
		{
			cout << "�����Դϴ�!" << endl;
			break; //�ݺ����� ��� �����Ű�� Ű����
		}
		else
		{
			remainChance--;

			if (remainChance <= 0) //���ӿ���
			{
				cout << endl;
				cout << "���� ����..." << endl;
				cout << "��ǻ�Ͱ� ������ Ű�� " << randChar << "�Դϴ�." << endl;
			}
			else //Ʋ�� ��
			{
				if (inputKey >= 'a') //�ҹ��� �Է� a = 97
				{
					if ((inputKey - 32 > randChar))
					{
						cout << "������ �Էµ� ���ĺ����� �տ� �ֽ��ϴ�." << endl;
					}
					else if ((inputKey - 32 < randChar))
					{
						cout << "������ �Էµ� ���ĺ����� �ڿ� �ֽ��ϴ�." << endl;
					}
				}
				else //�빮�� �Է� A = 65
				{
					if ((inputKey > randChar))
					{
						cout << "������ �Էµ� ���ĺ����� �տ� �ֽ��ϴ�." << endl;
					}
					else if ((inputKey < randChar))
					{
						cout << "������ �Էµ� ���ĺ����� �ڿ� �ֽ��ϴ�." << endl;
					}
				}

			}
		}

		cout << endl;
		cout << "====================================" << endl;
		cout << endl;
	}
}
#pragma endregion