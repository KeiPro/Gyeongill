#pragma once
#include "GameNode.h"

class Missile;
class Tank
{
private:
	POINT center;
	//int x, y;		// 위치 좌표
	// 몸통
	int bodySize;

	// 포신
	FPOINT barrelEnd;
	float barrelAngle;			// 단위 : degree(도) 0 ~ 360
								//		: radian    0.0 ~ PI * 2 ( 3.141592 ...... )
	Missile* missile;
	int missileMaxCount;

public:
	virtual HRESULT Init();
	virtual void Release();
	virtual void Update();	
	virtual void Render(HDC hdc);

	void Fire();

	void SetBarrelAngle(float angle) { barrelAngle = angle; }

	float GetBarrelAngle() { return barrelAngle; }
	POINT GetTankPosition() { return center; }

	Tank();
	~Tank();
};

