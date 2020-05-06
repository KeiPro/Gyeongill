#pragma once
#include "GameNode.h"

class Image;
class Tank;
class Enemy;
class MainGame : public GameNode
{
private:
	bool isInit;
	HANDLE hTimer;

	int score;

	Tank* tank;
	Enemy* enemy;
	
	Image* bg;
	Image* backBuffer; //여기다가 다 한꺼번에 그리고 출력한다.
	
	LOGFONT lf;
	

public:
	HFONT font, oldfont;

	virtual HRESULT Init();
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC hdc);

	Enemy* GetEnemy() { return enemy; }
	int GetScore() { return score; }

	void SetScore(int _score) { score = _score; }
	void SetEnemyPos();


	void FontCreate(); //폰트를 설정하는 함수

	LRESULT MainProc(HWND hWnd, UINT iMessage,
		WPARAM wParam, LPARAM lParam);

	MainGame();
	~MainGame();
};

