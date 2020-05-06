#pragma once
#include "GameNode.h"
#include "Enemy.h"


class Tank;
class Missile;
class MainGame : public GameNode
{
private:
	bool isInit;
	HANDLE hTimer;

	HPEN hPen, hOldPen, hGreenPen;
	HBRUSH hBrush, hOldBrush;
	
	
	Tank* tank;
	Enemy* enemy;
	int timer;
	int stage; int score; char szText[128];
	int enemyCount;
	int shootDownCount;
	bool stageUpdate;
	
public:
	virtual HRESULT Init();
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC hdc);
	
	LRESULT MainProc(HWND hWnd, UINT iMessage,
		WPARAM wParam, LPARAM lParam);

	//float GetDistance(float x1, float y1, float x2, float y2);
	bool CheckCollision(Missile* m1, Missile* m2);
	bool CheckCollision(Missile* m1, Enemy* m2);
	//float GetAngle(float x1, float y1, float x2, float y2);
	Tank* GetTank() { return tank; }
	

	MainGame();
	~MainGame();
};

