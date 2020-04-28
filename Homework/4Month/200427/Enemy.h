#pragma once
#include "pch.h"
#include "GameNode.h"

class MainGame;
class Enemy : public GameNode
{
private:
	FloatPosition myPos;
	FloatPosition tankPos;
	float normalVectorX, normalVectorY;
	float directionX, directionY;
	float sqrtValue;
	int speed;
	int size;
	MainGame* mainGame;

public:

	virtual HRESULT Init();		
	virtual void Release();		
	virtual void Update();		
	virtual void Render(HDC hdc);


	int GetMySize() { return size; }
	FloatPosition GetMyPos() { return myPos; }
	MainGame* GetMainGame() { return mainGame; }

	void SetTankPos(FloatPosition _tankPos) { tankPos = _tankPos; }
	void SetMainGame(MainGame* _mainGame) { mainGame = _mainGame; }

};