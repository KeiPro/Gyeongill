#pragma once
#include "GameNode.h"

class Tank;
class Enemy;
class MainGame : public GameNode
{
private:
	bool isInit;
	HANDLE hTimer;

	HPEN hPen, hOldPen;
	HBRUSH hBrush, hOldBrush;

	BOX currentBox;
	RECT rc[BOX_End], rcIn;

	Tank* tank;
	Enemy* enemy;

public:
	virtual HRESULT Init();
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC hdc);
	

	LRESULT MainProc(HWND hWnd, UINT iMessage,
		WPARAM wParam, LPARAM lParam);

	MainGame();
	~MainGame();
};

