#pragma once
#include "GameNode.h"

class Missile;
class MainGame;
class Enemy;
class Tank
{
private:
	FPOINT center;
	//int x, y;		// ��ġ ��ǥ
	// ����
	int bodySize;

	// ����
	FPOINT barrelEnd;
	float barrelAngle;			// ���� : degree(��) 0 ~ 360
								//		: radian    0.0 ~ PI * 2 ( 3.141592 ...... )
	Missile* missile;
	MainGame* mainGame;
	int missileMaxCount;
	int enemyCount;



	int shootTimer;
	int shootCount; // ����źȰ�뺯��
	float minEnemyDistance;
	float tmpDistance;
	Enemy* minEnemy; // ���������� ��� ����� ��ģ tmpEnemy�� ���� ���� 
	Enemy* tmpEnemy; // �ӽ������� �� �����Ӹ��� �Ÿ��� ����Ͽ� ���� ����� �Ÿ��� ���� ������ ����.
	Enemy* enemy; // MainGame���κ��� ���� Enemy�� ����


public:
	virtual HRESULT Init();
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC hdc);

	void Fire();

	void SetBarrelAngle(float angle) { barrelAngle = angle; }
	void SetMainGame(MainGame* _mainGame) { mainGame = _mainGame; }
	void SetShootCount(int _shootCount) { shootCount = _shootCount; }
	void SetMinDistance(float _minEnemyDistance) { minEnemyDistance = _minEnemyDistance; }
	void SetEnemy(Enemy* _enemy) { enemy = _enemy; }
	void SetMinEnemy(Enemy* _enemy) { minEnemy = _enemy; }
	void SetEnemyCount(int _enemyCount) { enemyCount = _enemyCount; }
	


	float GetBarrelAngle() { return barrelAngle; }
	FPOINT GetTankPosition() { return center; }
	Missile* GetMissile( ) { return missile; }
	int GetMissileMaxCount() { return missileMaxCount; }
	MainGame* GetMainGame() { return mainGame; }
	int GetShootCount() { return shootCount; }
	float GetMinDistance() { return minEnemyDistance; }
	Enemy* GetEnemy() { return enemy; }
	Enemy* GetMinEnemy() { return minEnemy; }


	Tank();
	~Tank();
};

