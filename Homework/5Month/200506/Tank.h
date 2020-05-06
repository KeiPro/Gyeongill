#pragma once
#include "GameNode.h"

class Missile;
class Enemy;
class Image;
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
	int missileMaxCount;
	int enemyCount;

	int shootTimer;
	int shootCount; // ����źȰ�뺯��
	float minEnemyDistance;
	float tmpDistance;

	Enemy* target;
	Image* marble;


public:
	virtual HRESULT Init();
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC hdc);

	void Fire();

	void SetBarrelAngle(float angle) { barrelAngle = angle; }
	void SetShootCount(int _shootCount) { shootCount = _shootCount; }
	void SetMinDistance(float _minEnemyDistance) { minEnemyDistance = _minEnemyDistance; }
	void SetEnemyCount(int _enemyCount) { enemyCount = _enemyCount; }

	void SetTarget(Enemy* enemy) { target = enemy; }

	
	float GetBarrelAngle() { return barrelAngle; }
	FPOINT GetTankPosition() { return center; }
	Missile* GetMissile( ) { return missile; }
	int GetMissileMaxCount() { return missileMaxCount; }
	int GetShootCount() { return shootCount; }
	float GetMinDistance() { return minEnemyDistance; }

	Tank();
	~Tank();
};

