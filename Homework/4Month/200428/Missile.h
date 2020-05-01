#pragma once
#include "pch.h"
#include "GameNode.h"

class Tank;
class Missile : public GameNode
{
private:
	FPOINT pos;
	int size;
	float angle;
	float speed;
	bool isFire;

public:

	virtual HRESULT Init();
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC hdc);

	void SetPos(FPOINT pt) { pos = pt; }
	void SetAngle(float _angle) { this->angle = _angle; }
	void SetIsFire(bool _isFire) { isFire = _isFire; }
	void SetSpeed(float _speed) { this->speed = _speed; }

	FPOINT GetPos() { return pos; }
	bool GetIsFire() { return isFire; }
	float GetSize() { return size; }
	float GetSpeed() { return speed; }
	float GetAngle() { return angle; }


	Missile() {};
	~Missile();
};