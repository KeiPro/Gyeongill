#include "MainGame.h"
#include "macroFunction.h"
#include "Tank.h"

HRESULT MainGame::Init()
{
	KeyManager::GetSingleton()->Init(); //이 시점에서 static변수에 메모리 할당이 된다.

	hTimer = (HANDLE)SetTimer(g_hWnd, 0, 10, NULL);
	
	// 탱크
	tank = new Tank();
	tank->Init();

	return S_OK;
}

void MainGame::Release()
{
	delete tank;
	delete missile;

	KillTimer(g_hWnd, 0);

	KeyManager::GetSingleton()->Release();
	KeyManager::GetSingleton()->ReleaseSingleton();
}

void MainGame::Update()
{
	if (tank)
	{
		tank->Update();
	}


	InvalidateRect(g_hWnd, NULL, true);
}

void MainGame::Render(HDC hdc)
{	
	if (tank)
	{
		tank->Render(hdc);	
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
			//tank->SetBarrelAngle(tank->GetBarrelAngle() + (PI / 180 * 7));
			break;
		case VK_RIGHT:
			//tank->SetBarrelAngle(tank->GetBarrelAngle() - (PI / 180 * 7));
			break;
		case VK_UP:
			break;
		case VK_DOWN:
			break;

		case VK_SPACE:

			//tank->Fire();			

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
