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
	Image* backBuffer; //����ٰ� �� �Ѳ����� �׸��� ����Ѵ�.

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

