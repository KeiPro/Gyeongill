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
#include <conio.h>

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

void MapCreate(char** map, int width, int height, int* tilePositionSave); //�� �����Ҵ� �Լ� ����
void MapFree(char** map, int width, int height); //���� �����ϴ� �Լ� ����
void Settings(Hero* hero, Monster* monster, string monsterName[], int area); // ����ο� ���͸� �����ϱ� ���� �Լ�
void HeroSetting(Hero* hero, int count); //����θ� �����ϱ� ���� area���� �Ѱ��ֱ� ���� �Լ�
void MonsterSetting(Monster* monster, string monsterName[], int count); //���͸� �����ϱ����� area���� �Ѱ��ֱ� ���� �Լ�
void MapPrint(char** map, int width, int height); //�� ��� �Լ�
void CharacterMove(Hero* hero, char* move, char** map, int width, int height, int* tileSavePosition); //ĳ���Ͱ� ������ �Լ�����


int monsterCount = 0; //�� ���� ������ �������� ����

int main()
{
	srand(time(NULL));

	Hero hero; 
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
	
	hero.myXPosition = 0, hero.myYPosition = 0; //���� ��ġ �ʱ�ȭ
	int tilePositionSave = 0;
	char** map = new char*[height]; //2���� �迭 �����Ҵ� �ϱ� ���� ���� ������ ����
	MapCreate(map, width, height, &tilePositionSave); //�� �����Ҵ� �Լ�

#pragma region �� ���̿��� ������ �̷������.

	Settings( &hero, monster, monsterName , width * height); //����ο� ���� ���� �Լ�

	char move; //�������� �޴� ����


	while (1)
	{
		system("cls");
		MapPrint(map, width, height); //�� ��� �Լ�
		CharacterMove(&hero, &move, map, width, height, &tilePositionSave); //ĳ���� �����̴� �Լ�
	}

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
void MapCreate(char** map, int width, int height, int* tileSavePosition)
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

	*tileSavePosition = map[0][0];
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
		monsterCount = (count + 1) * 3; //�뷱��
	}
	
	HeroSetting(hero, count); //����� �ʱ�ȭ �� ����
	//MonsterSetting(monster, monsterName, count); //���� �ʱ�ȭ �� ����
}

//����� ���� �Լ�
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

//���� �����Լ�
void MonsterSetting(Monster* monster, string monsterName[], int count)
{
	//i�� �����ϴ� ���� �ƴ϶� �ϳ� ���� �� �����ؼ� �׳༮���� �뷱�� �����ϴ°ɷ�??
	for (int i = 0; i < MONSTERSIZE; i++)
	{
		(monster + i)->monsterName = monsterName[i];
		(monster + i)->tileType = i;
		(monster + i)->maxHp = (rand() % 3 + (1 + i))+count; //�� ���ϸ��� ü���� 1~2�� �ȴ�. //
		(monster + i)->currentHp = (monster + i)->maxHp;
		(monster + i)->giveExp = (rand() % 100 + 100 + (i*20)) + (count * 50); //�ּ� ����ġ 100 //�뷱�� ����
		(monster + i)->giveGold = (rand() % 10 + 10 + (i*5)) + (count + 1) * 2; //�ּ� ��� ȹ��
		
		if ((i + 1) % 4 == 0)
		{

		}
	}
}

void CharacterMove(Hero* hero, char* move, char** map, int width, int height, int* tilePositionSave)
{
	*move = _getch();
	
	switch (*move)
	{
		case 'w':
			
			if (hero->myYPosition == 0)
			{
				return;
			}
			else
			{
				map[hero->myYPosition][hero->myXPosition] = *tilePositionSave;
				hero->myYPosition--;
				*tilePositionSave = map[hero->myYPosition][hero->myXPosition];
				map[hero->myYPosition][hero->myXPosition] = 0;
			}

			break;

		case 'a':

			if (hero->myXPosition == 0)
			{
				return;
			}
			else
			{
				map[hero->myYPosition][hero->myXPosition] = *tilePositionSave;
				hero->myXPosition--;
				*tilePositionSave = map[hero->myYPosition][hero->myXPosition];
				map[hero->myYPosition][hero->myXPosition] = 0;
			}

			break;

		case 's':

			if (hero->myYPosition == height-1)
			{
				return;
			}
			else
			{
				map[hero->myYPosition][hero->myXPosition] = *tilePositionSave;
				hero->myYPosition++;
				*tilePositionSave = map[hero->myYPosition][hero->myXPosition];
				map[hero->myYPosition][hero->myXPosition] = 0;
			}

			break;

		case 'd':

			if (hero->myXPosition == width - 1)
			{
				return;
			}
			else
			{
				map[hero->myYPosition][hero->myXPosition] = *tilePositionSave;
				hero->myXPosition++;
				*tilePositionSave = map[hero->myYPosition][hero->myXPosition];
				map[hero->myYPosition][hero->myXPosition] = 0;
			}

			break;
		default:
			break;

	}

}