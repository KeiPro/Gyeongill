#pragma once
#include "pch.h"
#include "GameNode.h"

class Tank;
class Enemy : public GameNode
{
private:
	FPOINT pos;
	FPOINT tankPos;

	float angle;
	int speed;
	int size;
	bool shootDown;

	Tank* target;

public:

	virtual HRESULT Init();		
	virtual void Release();		
	virtual void Update();		
	virtual void Render(HDC hdc);

	void SetTarget(Tank* tank);
	FPOINT GetPos() { return pos; }

	Enemy();
	~Enemy();


};