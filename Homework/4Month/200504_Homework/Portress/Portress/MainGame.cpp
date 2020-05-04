#include "MainGame.h"
#include "macroFunction.h"
#include "Image.h"
#include "Tank.h"

HRESULT MainGame::Init()
{
	// backBuffer
	backBuffer = new Image();
	backBuffer->Init(WINSIZE_X, WINSIZE_Y); //이미지를 먼저 다 그려넣을 공간이 필요하다. 이 크기로 빈 비트맵을 만들어 준다.

	KeyManager::GetSingleton()->Init(); //이 시점에서 static변수에 메모리 할당이 된다.

	hTimer = (HANDLE)SetTimer(g_hWnd, 0, 10, NULL);

	bg = new Image();
	bg->Init("Orianna.bmp", WINSIZE_X, WINSIZE_Y);

	//탱크
	tank = new Tank();
	tank->Init();

	isInit = true;
	
	return S_OK;
}


void MainGame::Release()
{
	tank->Release();
	delete tank;

	bg->Release();
	delete bg;

	KillTimer(g_hWnd, 0);

	KeyManager::GetSingleton()->Release();
	KeyManager::GetSingleton()->ReleaseSingleton();

	backBuffer->Release();
	delete backBuffer;
}

void MainGame::Update()
{
	if (tank)
	{
		tank->Update();
	}

	InvalidateRect(g_hWnd, NULL, false); //false로 바꿔준다.
}

void MainGame::Render(HDC hdc)
{	
	// 다~~ backBuffer에다가 그려준다.

	if (bg)
	{
		bg->Render(backBuffer->GetMemDC(), 0, 0); 
	}

	if (tank)
	{
		tank->Render(backBuffer->GetMemDC());
	}

	backBuffer->Render(hdc, 0, 0);
}

LRESULT MainGame::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	switch (iMessage)
	{
	case WM_TIMER:
		if(isInit == true)
			this->Update();
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		if (isInit == true)
			this->Render(hdc);

		EndPaint(hWnd, &ps);
		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_LEFT:
			break;
		case VK_RIGHT:
			break;
		case VK_UP:
			break;
		case VK_DOWN:
			break;

		case VK_SPACE:

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

MainGame::MainGame() : isInit(false)
{
}


MainGame::~MainGame()
{
}
