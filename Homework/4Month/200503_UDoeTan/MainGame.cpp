#include "MainGame.h"
#include "macroFunction.h"
#include "Tank.h"
#include "Missile.h"

HRESULT MainGame::Init()
{
	KeyManager::GetSingleton()->Init(); //이 시점에서 static변수에 메모리 할당이 된다.

	hTimer = (HANDLE)SetTimer(g_hWnd, 0, 10, NULL);
	
	// 탱크
	tank = new Tank();
	tank->SetMainGame(this);
	tank->Init();

	enemy = new Enemy[ENEMYCOUNT];
	tank->SetEnemy(enemy);
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
	//delete missile;

	KillTimer(g_hWnd, 0);

	KeyManager::GetSingleton()->Release();
	KeyManager::GetSingleton()->ReleaseSingleton();
}

void MainGame::Update()
{
	if (tank)
	{
		tank->Update();

#pragma region 적 과의 충돌

		Missile* missile;
		Enemy* _enemy;

		for (int i = 0; i < tank->GetMissileMaxCount(); i++)
		{
			missile = &(tank->GetMissile()[i]);

			if (missile == NULL) continue;

			if (missile->GetIsFire() == true)
			{
				for (int j = 0; j < ENEMYCOUNT; j++)
				{
					_enemy = &(enemy[j]);

					if (_enemy == NULL) continue;

					if ( CheckCollision(missile, _enemy) ) //충돌이 일어났을 때
					{
						missile->SetIsFire(false);
						if (missile->GetUDoeTan() == true) 
						{ 
							missile->SetUDoeTan(false);
							missile->SetMinEnemy(nullptr);
							missile->SetTmpSpeed(1.0f);
							missile->SetTmpAngle(0.0f);
							missile->SetTargetTimer(0);
						}
						_enemy->Init();
					}
				}
			}
		}

#pragma endregion

#pragma region 미사일끼리의 충돌
		//Missile* m1, *m2;
		//float angle;



		//for (int i = 0; i < tank->GetMissileMaxCount() - 1; i++)
		//{
		//	m1 = &(tank->GetMissileDatas()[i]);
		//	if (m1->GetIsFire() == false)
		//		continue;

		//	for (int j = i + 1; j < tank->GetMissileMaxCount(); j++)
		//	{
		//		m2 = &(tank->GetMissileDatas()[j]);

		//		if (m2->GetIsFire() == false)
		//			continue;

		//		//충돌 확인

		//		if (CheckCollision(m1, m2))
		//		{
		//			/*m1->SetSpeed(0.0f);
		//			m2->SetSpeed(0.0f);*/
		//			//angle = GetAngle(m2->GetPos().x, m2->GetPos().y, m1->GetPos().x, m1->GetPos().y);

		//			//m1->SetAngle(angle);
		//			//m1->SetAngle(angle+PI);

		//			//m1->SetAngle(GetAngle(m2->GetPos().x, m2->GetPos().y, m1->GetPos().x, m1->GetPos().y));
		//			//m2->SetAngle(GetAngle(m1->GetPos().x, m1->GetPos().y, m2->GetPos().x, m2->GetPos().y));

		//			//if (m1->GetAngle() < 180)
		//			//{
		//			//	m1->SetAngle( 180-(m1->GetAngle()));
		//			//}
		//			//else
		//			//{
		//			//	m1->SetAngle( 360-(m1->GetAngle()));
		//			//}
		//			//if (m2->GetAngle() < 180)
		//			//{
		//			//	m2->SetAngle( 180-(m2->GetAngle()));
		//			//}
		//			//{
		//			//else
		//			//	m2->SetAngle( 360-(m2->GetAngle()));
		//			//}

		//		}

		//	}
		//}
#pragma endregion


	}

	timer++;

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
			if (&(enemy[i]) == tank->GetMinEnemy())
			{
				hPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
				hOldPen = (HPEN)SelectObject(hdc, hPen);
				enemy[i].Render(hdc);
				SelectObject(hdc, hOldPen);
				DeleteObject((HPEN)SelectObject(hdc, hPen));
			}
			else
			{
				hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
				hOldPen = (HPEN)SelectObject(hdc, hPen);
				enemy[i].Render(hdc);
				SelectObject(hdc, hOldPen);
				DeleteObject((HPEN)SelectObject(hdc, hPen));
			}
		}

		//hPen = CreatePen(PS_DOT, 1, RGB(0, 0, 255));
		//hOldPen = (HPEN)SelectObject(hdc, hPen);
		//for (int i = 0; i < ENEMYCOUNT; i++)
		//{
		//	MoveToEx(hdc, enemy[i].GetMyPos().x, enemy[i].GetMyPos().y, NULL);
		//	LineTo(hdc, tank->GetTankPosition().x, tank->GetTankPosition().y);
		//}

		SelectObject(hdc, hOldPen);
		DeleteObject((HPEN)SelectObject(hdc, hGreenPen));
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

//float MainGame::GetDistance(float x1, float y1, float x2, float y2)
//{
//	float x = (x2 - x1);
//	float y = (y2 - y1);
//
//	float dist = sqrt((x * x) + (y * y));
//
//	return dist;
//}
//

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

bool MainGame::CheckCollision(Missile* _missile, Enemy* enemy)
{
	float halfSize1 = _missile->GetSize() / 2;
	float halfSize2 = enemy->GetMySize() / 2;
	FPOINT pos1 = _missile->GetPos();
	FPOINT pos2 = enemy->GetMyPos();

	if ((halfSize1 + halfSize2) >= GetDistance(pos1.x, pos1.y, pos2.x, pos2.y))
	{
		return true;
	}

	return false;
}

//float MainGame::GetAngle(float x1, float y1, float x2, float y2)
//{
//
//	/*
//		tan(theta) = y / x;
//				   = (y2 - y1) / (x2 - x1);
//				   atan2(  (y2 - y1) , (x2 - x1) );
//	*/
//
//	float x = x2 - x1;
//	float y = y2 - y1;
//
//	return atan2(y, x);
//}

MainGame::MainGame()
{
}


MainGame::~MainGame()
{
}
