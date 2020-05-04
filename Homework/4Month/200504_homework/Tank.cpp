#include "Tank.h"
#include "macroFunction.h"
#include "Missile.h"

HRESULT Tank::Init()
{
	pos.x = 0;
	pos.y = WINSIZE_Y;
	size = 200;
	barrelAngle = (PI / 4.0f);
	barrelEnd.x = pos.x + size * cosf(barrelAngle);
	barrelEnd.y = pos.y - size * sinf(barrelAngle);

	return S_OK;
}

void Tank::Release()
{

}

void Tank::Update()
{
	if (KeyManager::GetSingleton()->IsStayKeyDown(VK_LEFT))
	{
		barrelAngle += (float)(PI / 180 * 3);
	}
	else if(KeyManager::GetSingleton()->IsStayKeyDown(VK_RIGHT))
	{
		barrelAngle -= (float)(PI / 180 * 3);
	}

	if (KeyManager::GetSingleton()->IsOnceKeyUp(VK_SPACE))
	{
		Fire();
	}

	barrelEnd.x = pos.x + size * cosf(barrelAngle);
	barrelEnd.y = pos.y - size * sinf(barrelAngle);

	if (missile)
	{
		for (int i = 0; i < missileMaxCount; i++)
		{
			if(missile[i].GetIsFire() == true) missile[i].Update();
		}
	}
}

void Tank::Render(HDC hdc)
{
	RenderEllipseToCenter(hdc, pos.x, pos.y, size, size);

	RenderLine(hdc, pos.x, pos.y, barrelEnd.x, barrelEnd.y);

	if (missile)
	{
		for (int i = 0; i < missileMaxCount; i++)
		{
			if (missile[i].GetIsFire() == true) missile[i].Render(hdc);
		}
	}
}

void Tank::Fire()
{
	if (missile)
	{
		for (int i = 0; i < missileMaxCount; i++)
		{
			if (missile[i].GetIsFire() == false)
			{
				missile[i].SetIsFire(true);
				missile[i].SetPos(barrelEnd);
				missile[i].SetAngle(barrelAngle);

				break;
			}
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
	delete[] missile;
}

