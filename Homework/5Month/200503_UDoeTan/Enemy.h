#pragma once
#include "pch.h"
#include "GameNode.h"

class MainGame;
class Enemy : public GameNode
{
private:
	FPOINT myPos;
	FPOINT tankPos;
	float normalVectorX, normalVectorY;
	float directionX, directionY;
	float sqrtValue;
	int speed;
	int size;
	bool shootDown;

	MainGame* mainGame;

public:

	virtual HRESULT Init();		
	virtual void Release();		
	virtual void Update();		
	virtual void Render(HDC hdc);


	int GetMySize() { return size; }
	FPOINT GetMyPos() { return myPos; }
	MainGame* GetMainGame() { return mainGame; }
	bool GetShootDown() { return shootDown; }

	void SetTankPos(FPOINT _tankPos) { tankPos = _tankPos; }
	void SetMainGame(MainGame* _mainGame) { mainGame = _mainGame; }
	void SetShootDown(bool _shootDown) { shootDown = _shootDown; }

};