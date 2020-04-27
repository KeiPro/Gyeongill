#include "Missile.h"
#include "macroFunction.h"
#include "MainGame.h"
#include "Enemy.h"

LRESULT Missile::Init()
{
	pos.x = 0;
	pos.y = 0;
	size = 10;
	angle = PI / 2.0f;
	speed = 10.0f;
	isFire = false;
	isPosition = false;

	return S_OK;
}

void Missile::Release()
{

}

void Missile::Update()
{
	if (isFire == true)
	{
		pos.x += speed * cosf(angle);
		pos.y -= speed * sinf(angle);

		if (pos.x > WINSIZE_X || pos.x < 0 || pos.y < 0 || pos.y > WINSIZE_Y)
		{
			this->Init();
		}

		for (int i = 0; i < ENEMYCOUNT; i++)
		{
			if (CheckCircleCollision(pos.x, pos.y, size, (mainGame->GetEnemy())[i].GetMyPos().x, (mainGame->GetEnemy())[i].GetMyPos().y, (mainGame->GetEnemy())[i].GetMySize()) == true)
			{
				this->Init();
				(mainGame->GetEnemy())[i].Init();
			}
		}
	}
}

void Missile::Render(HDC hdc)
{
	if (isFire)
	{
		RenderEllipseToCenter(hdc, pos.x, pos.y, size, size);
	}
}


Missile::Missile()
{

}

Missile::~Missile()
{

}
