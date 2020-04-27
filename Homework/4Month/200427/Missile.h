#pragma once
#include "pch.h"
#include "GameNode.h"

class Tank;
class Missile : public GameNode
{
private:
	POINT pos;
	int size;
	float angle;
	float speed;
	bool isFire;


public:

	virtual HRESULT Init();
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC hdc);

	void SetPos(POINT pt) { pos = pt; }
	void SetAngle(float _angle) { angle = _angle; }
	void SetIsFire(bool _isFire) { isFire = _isFire; }

	POINT GetPos() { return pos; }
	bool GetIsFire() { return isFire; }


	Missile() {};
	~Missile();
};