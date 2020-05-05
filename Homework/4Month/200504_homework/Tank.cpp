#include "Tank.h"
#include "macroFunction.h"
#include "Missile.h"
#include "MainGame.h"

HRESULT Tank::Init(MainGame* _mainGame)
{
	pos.x = 0;
	pos.y = WINSIZE_Y;
	size = 200;
	barrelAngle = (PI / 4.0f);
	barrelEnd.x = pos.x + size * cosf(barrelAngle);
	barrelEnd.y = pos.y - size * sinf(barrelAngle);
	power = 0.0f;
	printPower = 0;
	mainGame = _mainGame;

	missile = new Missile[missileMaxCount];

	for (int i = 0; i < missileMaxCount; i++)
	{
		missile[i].Init(mainGame);
	}

	return S_OK;
}

void Tank::Release()
{
	delete[] missile;
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

	if (KeyManager::GetSingleton()->IsStayKeyDown(VK_SPACE))
	{
		power += 10 * 0.016666f;
		if (power < 13.0f)
		{
			printPower = power;
		}
		else
		{
			printPower = 13;
		}
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
	RenderEllipseToCenter(hdc, pos.x, pos.y, size, size); //탱크 몸체

	RenderLine(hdc, pos.x, pos.y, barrelEnd.x, barrelEnd.y); //탱크 포대

	PowerInfoUpdate(hdc);

	if (missile)
	{
		for (int i = 0; i < missileMaxCount; i++)
		{
			if (missile[i].GetIsFire() == true) missile[i].Render(hdc);
		}
	}
}

void Tank::PowerInfoUpdate(HDC hdc)
{
	mainGame->oldfont = (HFONT)SelectObject(hdc, mainGame->font);
	SetTextColor(hdc, RGB(128, 255 ,128));
	SetBkMode(hdc, TRANSPARENT);

	wsprintf(szText, " Score : %d ", mainGame->GetScore());
	TextOut(hdc, 20, 20, szText, strlen(szText));
	
	wsprintf(szText, " Power : %d ", printPower);
	TextOut(hdc, 20, 50, szText, strlen(szText));

	SelectObject(hdc, mainGame->oldfont);
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
				if (power >= 13.0f)
					power = 13.0f;
				
				missile[i].SetSpeed(power); //초속을 계속 증가시킨다.
				power = 0.0f;
				break;
			}
		}
	}
}

Tank::Tank() : missileMaxCount(50)
{

}

Tank::~Tank()
{
	
}

