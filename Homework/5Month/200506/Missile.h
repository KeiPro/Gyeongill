#pragma once
#include "pch.h"
#include "GameNode.h"

class Enemy;
class Image;
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
	Enemy* target;
	float tmpAngle;
	float adjustAngle;
	Image* marble;

public:

	virtual HRESULT Init();
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC hdc);

	void SetTarget(Enemy* enemy) { target = enemy; }
	void SetPos(FPOINT pt) { pos = pt; }
	void SetAngle(float _angle) { this->angle = _angle; }
	void SetIsFire(bool _isFire) { isFire = _isFire; }
	void SetSpeed(float _speed) { this->speed = _speed; }
	//void SetImage(Image* _marble) { marble = _marble; }

	FPOINT GetPos() { return pos; }
	bool GetIsFire() { return isFire; }
	float GetSize() { return  (float)size; }
	float GetSpeed() { return speed; }
	float GetAngle() { return angle; }
	bool GetUDoeTan() { return isUDoeTan; }

	Missile() {};
	~Missile();
};