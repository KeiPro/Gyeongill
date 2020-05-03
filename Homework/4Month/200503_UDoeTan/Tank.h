#pragma once
#include "GameNode.h"

class Missile;
class MainGame;
class Enemy;
class Tank
{
private:
	FPOINT center;
	//int x, y;		// 위치 좌표
	// 몸통
	int bodySize;

	// 포신
	FPOINT barrelEnd;
	float barrelAngle;			// 단위 : degree(도) 0 ~ 360
								//		: radian    0.0 ~ PI * 2 ( 3.141592 ...... )
	Missile* missile;
	MainGame* mainGame;
	int missileMaxCount;
	int enemyCount;



	int shootTimer;
	int shootCount; // 유도탄활용변수
	float minEnemyDistance;
	float tmpDistance;
	Enemy* minEnemy; // 최종적으로 모든 계산을 마친 tmpEnemy를 받을 변수 
	Enemy* tmpEnemy; // 임시적으로 매 프레임마다 거리를 계산하여 가장 가까운 거리의 적을 저장할 변수.
	Enemy* enemy; // MainGame으로부터 받은 Enemy의 변수


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

