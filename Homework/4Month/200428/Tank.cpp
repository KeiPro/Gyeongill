#include "Tank.h"
#include "macroFunction.h"
#include "Missile.h"

HRESULT Tank::Init()
{
	// 몸통
	center.x = WINSIZE_X / 2;
	center.y = WINSIZE_Y;
	bodySize = 150;

	// 포신
	barrelEnd.x = WINSIZE_X / 2;
	barrelEnd.y = center.y - 150;

	barrelAngle = PI / 4.0f ;
	shootTimer = 0; // 30프레임에 한 번씩.
	
	return S_OK;
}

void Tank::Release()
{
}

void Tank::Update()
{
	// 탱크의 키입력을 처리한다.
	if (KeyManager::GetSingleton()->IsStayKeyDown(VK_LEFT))
	{

		barrelAngle += (PI / 180 * 3);
	}
	else if (KeyManager::GetSingleton()->IsStayKeyDown(VK_RIGHT))
	{
		barrelAngle -= (PI / 180 * 3);
	}

	//if (KeyManager::GetSingleton()->IsStayKeyDown(VK_SPACE))
	//{
	//	shootTimer++;

	//	if (shootTimer >= 20) //30프레임에 한 번씩
	//	{
	//		shootTimer = 0;
	//		Fire();
	//	}
	//}

	//if (KeyManager::GetSingleton()->IsOnceKeyUp(VK_SPACE))
	//{
	//	Fire();
	//}	

	shootTimer++;

	if (KeyManager::GetSingleton()->IsStayKeyDown(VK_SPACE))
	{
		if (shootTimer >= 30)
		{
			shootTimer = 0;
			Fire();
		}
	}




	// 포신 끝 좌표를 프레임마다 계산한다.
	barrelEnd.x = center.x + cosf(barrelAngle) * 150; //center x, y좌표를 기준으로 각도 계산을 해준다.
	barrelEnd.y = center.y - sinf(barrelAngle) * 150;

	//미사일 위치 업데이트
	if (missile)
	{
		for (int i = 0; i < missileMaxCount; i++)
		{
			missile[i].Update();
		}
	}
}

void Tank::Render(HDC hdc)
{
	// 몸통
	RenderEllipseToCenter(hdc, center.x, center.y, bodySize, bodySize);

	// 포신
	RenderLine(hdc, center.x, center.y, barrelEnd.x, barrelEnd.y);

	if (missile)
	{
		for (int i = 0; i < missileMaxCount; i++)
		{
			missile[i].Render(hdc);
		}
	}
}

void Tank::Fire()
{
	// 먼저 확인해야 하는 내용?
	for (int i = 0; i < missileMaxCount; i++)
	{
		if (missile[i].GetIsFire() == false)
		{
			if (missile)
			{
				missile[i].SetIsFire(true);
				missile[i].SetPos(barrelEnd);
				missile[i].SetAngle(barrelAngle);
				break;
			}
		}
	}
}

Tank::Tank() : missileMaxCount(5)
{
	missile = new Missile[missileMaxCount];
	for (int i = 0; i < missileMaxCount; i++)
	{
		missile[i].Init();
	}
	//missile = new Missile();
	//missile->Init();
}

Tank::~Tank()
{
	delete[] missile;
}

