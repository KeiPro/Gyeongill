/*
	������ ������

	** ������ ������ 2 : ������ ������
	1) ���� * ���� Ÿ�� ����� ���ϰ� ������ �� �ֵ��� ������. (���� �Ҵ�)
	2) w, a, s, d�̵�
	***3) �迭, ����ü, �Լ��� �ִ��� Ȱ���غ���.
	4) ������ ���� ���� ��
	5) ���ʹ� ���ϸ���ó�� ������ ��ī���� ���. //�� Ÿ�Ͽ� ���� �� Ȯ���� ���� �������� �ְ� �ȸ��������ְ�
	6) Ÿ�Ͽ� ������ �ִ�. (��, ��, ��) ���� ������ ���͵� �ٸ���. ������ ������ ��� �˿��� ������ ��� ... �� �ٸ���
	7) �÷��̾� �Ӽ� : �̸� / �ִ� HP(������ ���� ����) / ���� HP / ����ġ / ���� / ���
	8) ���� : �̸� / ���� / ȸ��ġ
	9) ���� : �̸�(���ϸ���) / �ִ� HP / ���� HP / ȹ�� ����ġ / ȹ�� ��� / �Ӽ�
	10) ���� : ������ ����
*/

#include <iostream>
#include <string>
#include <Windows.h>
#include <ctime>

#define MONSTERSIZE 16

enum TILETYPE{ LAND=2 , WATER , FOREST, FLY }; //��, �ٴ�, ��, ����

using namespace std;

//���� ����ü
struct Hero
{
	string heroName; //����� �̸�
	int maxHp; //�ִ�ü��
	int currentHp; //����ü��
	int maxExp; //���� �������� �ϱ� ���� ����ġ
	int currentExp; //����ġ
	int myGold; //��ȭ
	int myXPosition, myYPosition; //���� x, y��ǥ
};

//���� ����ü
struct Monster
{
	string monsterName; //���� �̸�
	int maxHp; //������ �ִ�ü��
	int currentHp; //������ ����ü��
	int giveExp; //������ ����ġ
	int giveGold; //ȹ�� ���
	//int properties; //�Ӽ�
	int tileType; //���Ͱ� �����ϰ� �ִ� Ÿ��
};

//���� ����ü
struct Portion 
{
	string name; //������ �̸�
	int price; //���� ����
	int healHp; //ȸ��ġ
};

void MapCreate(char** map, int width, int height); //�� �����Ҵ� �Լ� ����
void MapFree(char** map, int width, int height); //���� �����ϴ� �Լ� ����
void Settings(Hero* hero, Monster* monster, string monsterName[], int area); // ����ο� ���͸� �����ϱ� ���� �Լ�

void HeroSetting(Hero* hero, int count); //����θ� �����ϱ� ���� area���� �Ѱ��ֱ� ���� �Լ�
void MonsterSetting(Monster* monster, string monsterName[], int count); //���͸� �����ϱ����� area���� �Ѱ��ֱ� ���� �Լ�
void MapPrint(char** map, int width, int height); //�� ��� �Լ�

int monsterCount = 0; //�� ���� ������ �������� ����

int main()
{
	srand(time(NULL));

	Hero heroes;
	Monster* monster;
	string monsterName[] = { "�𷡵���", "��Ʈ����", "������", "��ī��", //monsterName[0] ~ monsterName[3] : ��
		"����ì��", "�ߵ���", "ŷũ��", "����Ÿ",					 //monsterName[4] ~ monsterName[7] : ��
		"��ħ��", "����", "���÷��þ�", "���ĸ�",						 //monsterNmae[8] ~ monsterName[11] : ��
		"������", "������", "���ڸ�", "���󵵽�"};						 //monsterName[12] ~ monsterName[15] : ����
	
	monster = new Monster[MONSTERSIZE];
	
	int width;
	int height;

	cout << "�ʺ� �Է� : ";
	cin >> width;
	cout << "���� �Է� : ";
	cin >> height;
	
	char** map = new char*[height]; //2���� �迭 �����Ҵ� �ϱ� ���� ���� ������ ����
	MapCreate(map, width, height); //�� �����Ҵ� �Լ�
#pragma region �� ���̿��� ������ �̷������.

	Settings( &heroes, monster, monsterName , width * height); //����ο� ���� ������ �Ͼ�� �Լ�

	MapPrint( map, width, height); //�� ��� �Լ�

#pragma endregion
	MapFree(map, width, height); //�� ���� �Լ�
	   	  
	delete[] monster;
	return 0;
}

//���� ����ϴ� �Լ�
void MapPrint(char** map, int width, int height)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (map[i][j] == 0)
				cout << "��";
			if (map[i][j] == 2)
				cout << "��";
			if (map[i][j] == 3)
				cout << "��";
			if (map[i][j] == 4)
				cout << "��";
			if (map[i][j] == 5)
				cout << "��";
		}
		cout << endl;
	}
}

//�� �����Ҵ� �� �����Լ�
void MapCreate(char** map, int width, int height)
{
	for (int i = 0; i < height; i++)
		*(map + i) = new char[width];

	//�� �ʱ�ȭ
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (rand() % 100 < 50) //�� 50%����
			{
				map[i][j] = LAND;
			}
		}
	}

	//�ٴ� �ʱ�ȭ
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (map[i][j] != LAND && (rand() % 100 < 30)) //�ٴ� 30%����
			{
				map[i][j] = WATER;
			}
		}
	}

	//�� �ʱ�ȭ
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (map[i][j] != LAND && map[i][j] != WATER && ( rand() % 100 < 30)) //�� 30%����
			{
				map[i][j] = FOREST;
			}
		}
	}

	//���� �ʱ�ȭ
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (map[i][j] != LAND && map[i][j] != WATER && map[i][j] != FOREST) //������ ����Ÿ�� ����
			{
				map[i][j] = FLY;
			}
		}
	}

	map[0][0] = 0;
	
}

//�� �޸� ����
void MapFree(char** map, int width, int height)
{
	//�����Ҵ� �޸� ����
	for (int i = 0; i < height; i++)
	{
		delete[] map[i];
	}
	delete[] map;
}

//����� �� ���͸� �����ϴ� �Լ�
void Settings(Hero* hero, Monster* monster, string monsterName[] ,int area)
{
	int count = 0;

	if (area > 100)
	{
		while (area > 100)
		{
			area -= 100;
			count++;
		}
		monsterCount = (count + 1) * 20; //�뷱��
	}
	else
	{
		while (area > 0)
		{
			area -= 10;
			count++;
		}
		monsterCount = (count + 1) * 3;
	}
	
	HeroSetting(hero, count); //����� �ʱ�ȭ �� ����
	//MonsterSetting(monster, monsterName, count); //���� �ʱ�ȭ �� ����
}

void HeroSetting(Hero* hero = nullptr, int count = 0)
{
	cout << "������� �̸��� �Է��� �ּ��� : ";
	cin >> hero->heroName;

	hero->maxHp = 100 + count * 10; //������� �⺻ ü���� �ּ� 100�� ü���� ������ �ִ´�. 
	hero->currentHp = hero->maxHp; //���� �ÿ��� ���� ü���� �ƽ� ü���̾�� �Ѵ�.
	hero->maxExp = 1000 + count * 200;  //�ּ� ����ġ : 1000 ����
	hero->currentExp = 0; //���� ����ġ
	hero->myGold = 0; //���� ���
	hero->myXPosition = 0, hero->myYPosition = 0; //������ ��ǥ
}

void MonsterSetting(Monster* monster, string monsterName[], int count)
{
	for (int i = 0; i < MONSTERSIZE; i++)
	{
		(monster + i)->monsterName = monsterName[i];
		(monster + i)->maxHp = rand() % 2 + 1; //�� ���ϸ��� ü���� 1~2�� �ȴ�.
		(monster + i)->currentHp = (monster + i)->maxHp;
		(monster + i)->giveExp = rand() % 100 + 100; //�ּ� ����ġ 

		if ((i + 1) % 4 == 0)
		{

		}
	}
}
