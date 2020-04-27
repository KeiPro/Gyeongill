#pragma once
#include "pch.h"
#include "GameNode.h"

class MainGame; //Enemy의 정보에 접근하기 위해 설정.
class Missile : public GameNode
{
private:
	POINT pos;
	int size;
	float angle;
	float speed;
	bool isFire;
	bool isPosition;

public:

	MainGame* mainGame;
	virtual HRESULT Init();
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC hdc);

	void SetPos(POINT pt) { pos = pt; }
	void SetAngle(float _angle) { angle = _angle; }
	void SetIsFire(bool _isFire) { isFire = _isFire; }
	void SetIsPosition(bool _isPosition) { isPosition = _isPosition; }
	void SetMainGame(MainGame* _mainGame) { mainGame = _mainGame; }

	POINT GetPos() { return pos; }
	bool GetIsFire() { return isFire; }
	bool GetIsPosition() { return isPosition; }
	MainGame* GetMainGame() { return mainGame; }


	Missile();
	~Missile();
};