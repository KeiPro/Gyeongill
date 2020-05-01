#pragma once
#include "GameNode.h"

class Missile;
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
	int shootTimer;

public:
	virtual HRESULT Init();
	virtual void Release();
	virtual void Update();	
	virtual void Render(HDC hdc);

	void Fire();

	void SetBarrelAngle(float angle) { barrelAngle = angle; }

	float GetBarrelAngle() { return barrelAngle; }
	FPOINT GetTankPosition() { return center; }
	Missile* GetMissile( ) { return missile; }
	int GetMissileMaxCount() { return missileMaxCount; }
	Missile* GetMissileDatas() { return missile; }


	Tank();
	~Tank();
};

