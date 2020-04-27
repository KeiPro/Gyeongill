#include "MainGame.h"
#include "macroFunction.h"
#include "Tank.h"
#include "Enemy.h"

HRESULT MainGame::Init()
{
	hTimer = (HANDLE)SetTimer(g_hWnd, 0, 10, NULL);
	
	// ÅÊÅ©
	tank = new Tank();
	tank->Init();
	tank->SetMainGame(this);

	// Enemy
	enemy = new Enemy[ENEMYCOUNT];
	for (int i = 0; i < ENEMYCOUNT; i++)
	{
		enemy[i].SetMainGame(this);
		enemy[i].Init();
		enemy[i].SetTankPos(tank->GetTankPosition());
	}

	return S_OK;
}

void MainGame::Release()
{
	delete tank;
	delete[] enemy;
	
	KillTimer(g_hWnd, 0);
}

void MainGame::Update()
{
	if (tank)
	{
		tank->Update();
	}

	if (enemy)
	{
		for (int i = 0; i < ENEMYCOUNT; i++)
		{
			enemy[i].Update();
		}
	}

	InvalidateRect(g_hWnd, NULL, true);
}

void MainGame::Render(HDC hdc)
{	
	if (tank)
	{
		tank->Render(hdc);	
	}

	if (enemy)
	{
		for (int i = 0; i < ENEMYCOUNT; i++)
		{
			enemy[i].Render(hdc);
		}
	}

}

LRESULT MainGame::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

 	switch (iMessage)
	{
	case WM_TIMER:
		this->Update();
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		this->Render(hdc);
		EndPaint(hWnd, &ps);
		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_LEFT:
			tank->SetBarrelAngle(tank->GetBarrelAngle() + (PI / 180 * 7));
			break;
		case VK_RIGHT:
			tank->SetBarrelAngle(tank->GetBarrelAngle() - (PI / 180 * 7));
			break;
		case VK_UP:
			break;
		case VK_DOWN:
			break;

		case VK_SPACE:

			tank->Fire();

			break;
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}

MainGame::MainGame()
{
}


MainGame::~MainGame()
{
}
