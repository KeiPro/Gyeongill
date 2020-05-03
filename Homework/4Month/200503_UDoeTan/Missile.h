#pragma once
#include "pch.h"
#include "GameNode.h"

class Enemy;
class Missile : public GameNode
{
private:
	FPOINT pos;
	int size;
	float angle;
	float speed;
	float tmpSpeed;
	float atanAngle;
	bool isFire;
	bool isUDoeTan;
	Enemy* minEnemy;
	float tmpAngle;
	int targetTimer;

public:

	virtual HRESULT Init();
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC hdc);

	void SetPos(FPOINT pt) { pos = pt; }
	void SetAngle(float _angle) { this->angle = _angle; }
	void SetIsFire(bool _isFire) { isFire = _isFire; }
	void SetSpeed(float _speed) { this->speed = _speed; }
	//void SetMainGame(MainGame* _mainGame) { mainGame = _mainGame; }
	void SetUDoeTan(bool _uDoTan) { isUDoeTan = _uDoTan; }
	void SetMinEnemy(Enemy* _enemy) { minEnemy = _enemy; }
	void SetTmpSpeed(float _tmpSpeed) { tmpSpeed = _tmpSpeed; }
	void SetTmpAngle(float _tmpAngle) { tmpAngle = _tmpAngle; }
	void SetTargetTimer(int _timer) { targetTimer = _timer; }

	FPOINT GetPos() { return pos; }
	bool GetIsFire() { return isFire; }
	float GetSize() { return size; }
	float GetSpeed() { return speed; }
	float GetAngle() { return angle; }
	//MainGame* GetMainGame() { return mainGame; }
	bool GetUDoeTan() { return isUDoeTan; }

	Missile() {};
	~Missile();
};