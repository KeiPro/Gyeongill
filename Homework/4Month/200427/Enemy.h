#pragma once
#include "pch.h"
#include "GameNode.h"

class Enemy : public GameNode
{
private:
	POINT myPos;
	POINT tankPos;
	float normalVectorX, normalVectorY;
	float directionX, directionY;
	float sqrtValue;
	int speed;


public:

	virtual HRESULT Init();		
	virtual void Release();		
	virtual void Update();		
	virtual void Render(HDC hdc);

	void SetTankPos(POINT _tankPos) { tankPos = _tankPos; }

};