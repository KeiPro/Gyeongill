#include "Tank.h"
#include "macroFunction.h"
#include "Missile.h"
#include "Enemy.h"
#include "Image.h"

HRESULT Tank::Init()
{
	// 몸통
	center.x = WINSIZE_X / 2;
	center.y = WINSIZE_Y;
	bodySize = 150;

	// 포신
	barrelEnd.x = WINSIZE_X / 2;
	barrelEnd.y = center.y - 150;

	barrelAngle = (float)(PI / 4.0f) ;
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
		barrelAngle += (float)(PI / 180 * 3);
	}
	else if (KeyManager::GetSingleton()->IsStayKeyDown(VK_RIGHT))
	{
		barrelAngle -= (float)(PI / 180 * 3);
	}

	if (KeyManager::GetSingleton()->IsOnceKeyUp(VK_SPACE))
	{
		Fire();
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

//backBuffer->MemDC가 들어올 것이고,
void Tank::Render(HDC hdc)
{
	// 몸통
	RenderEllipseToCenter(hdc, (int)center.x, (int)center.y, (int)bodySize, (int)bodySize);

	// 포신
	RenderLine(hdc, (int)center.x, (int)center.y, (int)barrelEnd.x, (int)barrelEnd.y);

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
			missile[i].SetIsFire(true);
			missile[i].SetPos(barrelEnd);
			missile[i].SetAngle(barrelAngle);

			if ( i % 3 == 2 )
			{
				missile[i].SetTarget(target);
			}

			break;
		}
	}
}

Tank::Tank() : missileMaxCount(50)
{
	missile = new Missile[missileMaxCount];

	for (int i = 0; i < missileMaxCount; i++)
	{
		missile[i].Init();
		
	}
}

Tank::~Tank()
{

}

