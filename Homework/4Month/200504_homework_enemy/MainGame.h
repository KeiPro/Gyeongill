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
	Image* backBuffer; //����ٰ� �� �Ѳ����� �׸��� ����Ѵ�.
	
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


	void FontCreate(); //��Ʈ�� �����ϴ� �Լ�

	LRESULT MainProc(HWND hWnd, UINT iMessage,
		WPARAM wParam, LPARAM lParam);

	MainGame();
	~MainGame();
};

