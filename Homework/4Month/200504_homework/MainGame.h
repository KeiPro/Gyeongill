#pragma once
#include "GameNode.h"

class Image;
class Tank;
class MainGame : public GameNode
{
private:
	bool isInit;
	HANDLE hTimer;

	Tank* tank;
	

	Image* bg;
	Image* backBuffer; //여기다가 다 한꺼번에 그리고 출력한다.

	int timer;
	
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

