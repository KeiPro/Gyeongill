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

	maxMissile = 5;
	missileNum = 0;

	return S_OK;
}

void Tank::Release()
{
}

void Tank::Update()
{
	// 포신 끝 좌표를 프레임마다 계산한다.
	barrelEnd.x = center.x + cosf(barrelAngle) * 150; //center x, y좌표를 기준으로 각도 계산을 해준다.
	barrelEnd.y = center.y - sinf(barrelAngle) * 150;

	//미사일 위치 업데이트
	if (missile)
	{
		for (int i = 0; i < maxMissile; i++)
		{
			if (missile[i].GetIsFire() == true)
			{
				if (missile[i].GetIsPosition() == false)
				{
					missile[i].SetPos(barrelEnd);
					missile[i].SetAngle(barrelAngle);
					missile[i].SetIsPosition(true);
				}
				else
				{
					missile[i].Update();
				}
			}
			
			//if (missile[i].GetIsFire())
			//{
			//	if (missile[i].GetIsPosition() == false)
			//	{
			//		missile[i].SetPos(barrelEnd);
			//		missile[i].SetAngle(barrelAngle);
			//		missile[i].SetIsPosition(true);
			//	}
			//	else
			//	{
			//		missile[i].Update();
			//	}
			//}
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
		for (int i = 0; i < maxMissile; i++)
		{
			if (missile[i].GetIsFire() == true)
			{
				missile[i].Render(hdc);
			}
		}
	}
}

void Tank::Fire(/*int missileIndex*/)
{
	for (int i = 0; i < maxMissile; i++)
	{
		if (missile[i].GetIsFire() == false)
		{
			missile[i].SetIsFire(true);
			break;
		}
	}


	/*if (missile)
	{
		missile[missileIndex].SetIsFire(true);

	}*/
}

Tank::Tank()
{
	missile = new Missile[5];
	for (int i = 0; i < 5; i++)
	{
		missile[i].Init();
	}
}

Tank::~Tank()
{
	delete[] missile;
}

