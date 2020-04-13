#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

struct Monster
{
	string name;
	int HP;
	int attackValue;
	float moveSpeed;
};

struct Pirates
{
	string name;
	int hp;
	int attack;
	int defense;
	float speed;
};

struct Student
{
	string name;
	int age;
	float score[4]; //����
	string sex;
	char graduation; //���� ���� ���� O, X�� �޴´�.
};

int main()
{
	
	/*
		����ü

		�迭 / ����ü / �Լ� -> C���� �ڵ� �߻�ȭ�� ���Ǵ� 3���� ����� �ϳ��̴�.
		��, �ڵ� �߻�ȭ�� ���� ����.
		
		���⼭ �߻�ȭ��? ���� ����(���� ����)�� ����ȭ�� ��ȣȭ, ����ȭ�� ���ؼ� ������������ + �ڵ������� �䳻�� �� ��.
		�ڵ� �߻�ȭ? student1, student2, student3 ........ --> student[] �� ���� �ڵ带 ����ȭ ��Ŵ ==> �ڵ� �߻�ȭ

		�߻�ȭ�� �߿��� ���� : �ڵ带 ¥�� �����, �������� ������� �̿��ϴ� �͵� ��� ����̴ϱ� ����� �����ϱ� ������ �߿��ϴ�.

		�迭 : �Ӽ��� ������ ���� ���� �����͸� ���� �̸��� �������� ǥ�������ν� �߻�ȭ�� �Ѵ�.
		����ü : �����͸� Ư�� ������ ��� �߻�ȭ�� �Ѵ�.
		�Լ� : �ڵ� Ư�� ��� ������ ��� �߻�ȭ�� �Ѵ�.

		����ü��?
		������ ��Ƴ��� ���� / ������ ����ü
		����ü�� � ��쿡 ����ϴ°�?
		Ư�� �������� ������ ���� �������� ���� ��
		������ �̸�, ������ HP, ������ ���ݷ�, ������ �̵���..... ���Ͷ�� �ϳ��� ��ü�� ǥ���ϴ� ��.

		int num;
		Monster goblin, orc, troll;
		Monster mobs[10];
		Monster slime = { "Ȳ�� ������", 10, 1, 0.02f };
		// �迭 ���� �ʱ�ȭ ����� �����ϰ� �ʱ�ȭ �� �� �ִ�.
		// �޸� ������ �迭�� �Ȱ����Ƿ�.

		����ü�� �����ϴ� ��
		����ü�� ����ϴ� �Լ� ������ �����Ѵ�.(�ش� �Լ��� �ۿ� ����)
	*/

	/*
	//����ü�� �ȹ���ٸ�?								����ٸ�?
			A												B	
	string monsteName[5];
	int monsterHP[5];					========> Monster monsters[5];
	float monsterMoveSpeed[5];
	int monsterAttackValue[5];

	1) �޸� ���� �������� ����.
		A 

	*/

	//Monster monsters[5];
	//monsters[0].name = "ȫ����";
	//monsters[0].HP = 100;
	//monsters[4].moveSpeed = 3.0f;

	/*
		�ǽ�.
		Pirates(����)��� ����ü�� �ϳ� �����Ѵ�.
		������ �Ӽ� : �̸�, hp, ���ݷ�, ����, ���ǵ�(float)
		lupi��� �̸��� ����ü ������ ������ �Ŀ�
		lupi������ �� ���� �Ӽ��� ���� �Է��ϰ� �Է��� ������ ����غ���.

		+ ���ǵ尡 3.0f �̻��̸�
		'�̸�'�� ���ǵ�� 5.0�Դϴ�. (����)
		'�̸�'�� ���ǵ�� 2.5�Դϴ�. (����)
	*/

	/*
	Pirates lupi;

	cout << "�̸� �Է� : ";
	cin >> lupi.name;

	cout << "ü�� �Է� : ";
	cin >> lupi.hp;

	cout << "���ݷ� �Է� : ";
	cin >> lupi.attack;

	cout << "���� �Է� : ";
	cin >> lupi.defense;

	cout << "���ǵ� �Է� : ";
	cin >> lupi.speed;

	cout << "�̸� : " << lupi.name << ", ü�� : " << lupi.hp << ", ���ݷ� : " 
		<< lupi.attack << ", ���� : " << lupi.defense << ", ���ǵ� : " << lupi.speed << endl;

	if (lupi.speed >= 3.0f)
	{
		cout << "'" << lupi.name << "'" << "�� ���ǵ�� " << lupi.speed << "�Դϴ�. (����)";
	}
	else
		cout << "'" << lupi.name << "'" << "�� ���ǵ�� " << lupi.speed << "�Դϴ�. (����)";
		*/

#pragma region �ǽ�.
/*
	�л��� ����üȭ�ؼ� ���� �Ӽ��� ��������.
	�̸�, ����, 1~4�г������ ����, ����, �������ɿ��θ� �л��� ������ cin���� �Է¹޴´�. (3��)

	1) �л��� ��ȣ�� �Է��ϸ� (1, 2, 3)
	�ش� �л��� �������� ��µȴ�.

	2) �л��� �̸��� �Է��ϸ�
	�ش� �л��� �������� ��µȴ�.
*/

	Student students[3];
	
	int total;
	for (int i = 0; i < 3; i++)
	{
		cout << " <  ��  ��  > " << endl;
		cout << "�̸� : ";
		cin >> students[i].name;

		cout << "���� : ";
		cin >> students[i].age;

		total = 0;
		for (int j = 0; j < 4; j++)
		{
			cout << (j+1) << "�г� ���� : ";
			cin >> students[i].score[j];
			total += students[i].score[j];
		}

		cout << "����(��, ��) : ";
		cin >> students[i].sex;

		students[i].graduation = (total / 4.0) > 2.5f ? 'O' : 'X';

		cout << "�Է� �Ϸ�!" << endl;
		Sleep(1000);
		system("cls");
	}

	int stuNumber; //�л��� ��ȣ
	string inputName;

	while (true) 
	{
		cout << "�л� ��ȣ�� �Է��� �ּ���(1~3) : ";
		cin >> stuNumber;

		cout << " < �л� ������ > " << endl;
		cout << "�̸� : " << students[stuNumber - 1].name << endl;
		cout << "���� : " << students[stuNumber - 1].age << endl;
		for (int i = 0; i < 4; i++)
		{
			cout << i+1 << "�г� ���� : " << students[stuNumber - 1].score[i] << endl;
		}
		cout << "���� : " << students[stuNumber - 1].sex << endl;
		cout << "���� ���� ���� : " << students[stuNumber - 1].graduation << endl;

		Sleep(2000);
		system("cls");

		cout << "�л� �̸��� �Է��� �ּ��� : ";
		cin >> inputName;

		for (int i = 0; i < 3; i++)
		{
			if (inputName == students[i].name)
			{
				cout << " < �л� ������ > " << endl;
				cout << "�̸� : " << students[i].name << endl;
				cout << "���� : " << students[i].age << endl;
				for (int i = 0; i < 4; i++)
				{
					cout << i + 1 << "�г� ���� : " << students[stuNumber - 1].score[i] << endl;
				}
				cout << "���� : " << students[i].sex << endl;
				cout << "���� ���� ���� : " << students[i].graduation << endl;
			}
		}

		Sleep(2000);
		system("cls");
	}


#pragma endregion

	return 0;
}