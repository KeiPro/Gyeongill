#include "Missile.h"
#include "macroFunction.h"
#include "Image.h"
#include "MainGame.h"

HRESULT Missile::Init(MainGame* _mainGame)
{
	pos.x = 0;
	pos.y = 0;
	size = 40;
	speed = 0.0f;
	isFire = false;
	angle = 0.0f;
	mainGame = _mainGame;

	yFrame = 0;

	missileImg = new Image();

	missileImg->Init("구슬.bmp", size, size);

	return S_OK;
}

void Missile::Release()
{
}

void Missile::Update()
{
	if (isFire)
	{
		yFrame++;
		pos.x += speed * cosf(angle);
		pos.y -= speed * sinf(angle) - (float)(9.8f / 2 * (yFrame * 0.01666f) * ( yFrame * 0.01666f ));

		if ( CheckCollision(this, mainGame->GetEnemy()) ) //충돌이 일어났을 경우.
		{
			isFire = false;
			mainGame->SetScore(mainGame->GetScore() + 100);
			mainGame->SetEnemyPos();

			yFrame = 0;
		}

		if (pos.x > WINSIZE_X || pos.y <= 0 || pos.y >= WINSIZE_Y)
		{
			isFire = false;
			yFrame = 0;
		}
	}
}

void Missile::Render(HDC hdc)
{
	if (isFire)
	{
		//RenderEllipseToCenter(hdc, pos.x, pos.y, size, size);
		//missileImg->TransparentBltRender(hdc, pos.x - size / 2, pos.y - size / 2);
		missileImg->TransparentBltRender(hdc, pos.x - size / 2, pos.y - size / 2);
	}
}
