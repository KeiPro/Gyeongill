#include "MainGame.h"
#include "macroFunction.h"
#include "Tank.h"
#include "Missile.h"
#include "Enemy.h"
#include "Image.h"
#include "KofPlayer.h"
#include "KofPlayer2.h"

HRESULT MainGame::Init()
{
	// backBuffer
	backBuffer = new Image();
	backBuffer->Init(WINSIZE_X, WINSIZE_Y); //이미지를 먼저 다 그려넣을 공간이 필요하다. 이 크기로 빈 비트맵을 만들어 준다.

	KeyManager::GetSingleton()->Init(); //이 시점에서 static변수에 메모리 할당이 된다.

	hTimer = (HANDLE)SetTimer(g_hWnd, 0, 10, NULL);

	enemyCount = 5;

	// 탱크
	tank = new Tank();
	tank->Init();

	enemy = new Enemy();
	enemy->Init();
	
	bg = new Image();
	bg->Init("Image/bin.bmp", 1400, 933);

	// Iori
	iori = new KofPlayer();
	iori->Init();
	iori->SetPosX(200);
	iori->SetPosY(WINSIZE_Y - 300);

	//iori2 = new KofPlayer2();
	//iori2->Init();

	iori2 = new KofPlayer();
	iori2->Init();
	iori2->SetPosX(WINSIZE_X - 200);
	iori2->SetPosY(WINSIZE_Y - 300);
	iori2->SetScale(1.7f);

	tank->SetTarget(enemy);

	isInit = true;
	
	return S_OK;
}


void MainGame::Release()
{
	iori2->Release();
	delete iori2;

	iori->Release();
	delete iori;

	bg->Release();
	delete bg;

	enemy->Release();
	delete enemy;

	tank->Release();
	delete tank;

	KillTimer(g_hWnd, 0);

	KeyManager::GetSingleton()->Release();
	KeyManager::GetSingleton()->ReleaseSingleton();

	backBuffer->Release();
	delete backBuffer;
}

void MainGame::Update()
{
	if (KeyManager::GetSingleton()->IsOnceKeyDown(VK_SPACE))
	{
		if (enemy)
		{
			enemy->SetTarget(tank);
		}
	}

	if (enemy)
	{
		enemy->Update();
	}
	
	if (tank)
	{
		tank->Update();
	}

	if (iori) iori->Update(); 

	if (iori2)	iori2->Update();

	InvalidateRect(g_hWnd, NULL, false); //false로 바꿔준다.
}

void MainGame::Render(HDC hdc)
{	
	// 다~~ backBuffer에다가 그려준다.

	//background도 순서가 중요하다.
	if (bg)
	{
		bg->Render(backBuffer->GetMemDC(), 0, 0); 
	}

	if (tank)
	{
		tank->Render(backBuffer->GetMemDC());
	}
	
	if (enemy)
	{
		enemy->Render(backBuffer->GetMemDC());
	}

	if (iori) iori->Render(backBuffer->GetMemDC()); 

	if (iori2) 	iori2->Render(backBuffer->GetMemDC());

	backBuffer->Render(hdc, 0, 0);


	//if (bg)
	//{
	//	bg->Render(hdc, 100, 100); // 0 0 : 복사될 위치의 좌표
	//}

	////if (marble)
	////{
	////	marble->Render(hdc, 300, 300);
	////}

	//if (tank)
	//{
	//	tank->Render(hdc);	
	//}
	//	
	//if (enemy)
	//{
	//	enemy->Render(hdc);
	//}
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

bool MainGame::CheckCollision(Missile* m1, Missile* m2)
{
	float halfSize1 = m1->GetSize() / 2;
	float halfSize2 = m2->GetSize() / 2;
	FPOINT pos1 = m1->GetPos();
	FPOINT pos2 = m2->GetPos();

	if ( (halfSize1 + halfSize2) >= GetDistance(pos1.x, pos1.y, pos2.x, pos2.y) )
	{
		return true;
	}

	return false;
}

MainGame::MainGame() : isInit(false)
{
}


MainGame::~MainGame()
{
}
