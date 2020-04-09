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

#define TILESIZE 4

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
	int monsXPosition, monsYPosition; //������ x, y��ǥ
};

//���� ����ü
struct Portion 
{
	string name; //������ �̸�
	int price; //���� ����
	int healHp; //ȸ��ġ
};

//Ÿ�� ����ü
struct Tile {
	int tileType; //�� : 0, �ٴ� : 1, �� : 2, �� : 3
	int tileXPosition, tileYPosition; 
};

void MapCreate(char** map, int width, int height); //�� �����Ҵ� �Լ� ����
void MapFree(char** map, int width, int height); //���� �����ϴ� �Լ� ����
void TileInitializing(Tile* tile); //Ÿ�� Ÿ���� �ʱ�ȭ �ϴ� �Լ�
void HeroSetting(Hero* hero, int area); //����θ� �����ϴ� �Լ�


int main()
{
	int width;
	int height;

	cout << "�ʺ� �Է� : ";
	cin >> width;
	cout << "���� �Է� : ";
	cin >> height;

	char** map = nullptr; //2���� �迭 �����Ҵ� �ϱ� ���� ���� ������ ����
	MapCreate(map, width, height); //�� �����Ҵ� �Լ�

#pragma region �� ���̿��� ������ �̷������.
	Tile tile[4];
	Hero heroes;
	







	HeroSetting(&heroes, width * height); //����� ���� �Լ�
	TileInitializing(tile); //�� Ÿ���� Ÿ�� �ʱ�ȭ
	


#pragma endregion
	MapFree(map, width, height); //�� ���� �Լ�
	   	  
	return 0;
}


//�� �����Ҵ� �Լ�
void MapCreate(char** map, int width, int height)
{
	map = new char*[height];

	for (int i = 0; i < height; i++)
		*(map + i) = new char[width];
}

//�� ����
void MapFree(char** map, int width, int height)
{
	//�����Ҵ� �޸� ����
	for (int i = 0; i < height; i++)
	{
		delete[] map[i];
	}
	delete[] map;
}

//Ÿ�� Ÿ�� �ʱ�ȭ
void TileInitializing(Tile* tile)
{
	for (int i = 0; i < TILESIZE; i++)
	{
		tile[i].tileType = i;
	}
}

//����� ���� �Լ�
void HeroSetting(Hero* hero, int area)
{
	cout << "������� �̸��� �Է��� �ּ��� : ";
	cin >> hero->heroName;

	HeroSubSetting();

	if (area <= 100)
	{

	}
	else if (area <= 200)
	{

	}
	else if (area <= 300)
	{

	}
}

void HeroSubSetting(Hero* hero, int )
{

}