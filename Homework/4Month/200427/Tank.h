#pragma once
#include "GameNode.h"

class Missile;
class MainGame;
class Tank
{
private:
	POINT center;
	//int x, y;		// ��ġ ��ǥ
	// ����
	int bodySize;

	// ����
	POINT barrelEnd;
	float barrelAngle;			// ���� : degree(��) 0 ~ 360
								//		: radian    0.0 ~ PI * 2 ( 3.141592 ...... )

	Missile* missile;
	MainGame* mainGame;
	int maxMissile;
	int missileNum;


public:
	virtual HRESULT Init();
	virtual void Release();
	virtual void Update();	
	virtual void Render(HDC hdc);

	void Fire(/*int missileIndex*/);

	void SetBarrelAngle(float angle) { barrelAngle = angle; }
	void SetMaxMissile(int _missile) { maxMissile = _missile; }
	void SetMissileNum(int _missileNum) { missileNum = _missileNum; }
	void SetMainGame(MainGame* _mainGame) { mainGame = _mainGame; }

	float GetBarrelAngle() { return barrelAngle; }
	POINT GetTankPosition() { return center; }
	int GetMaxMissile() { return maxMissile; }
	int GetMissileNum() { return missileNum; }	
	MainGame* GetMainGame() { return mainGame; }

	Tank();
	~Tank();
};

