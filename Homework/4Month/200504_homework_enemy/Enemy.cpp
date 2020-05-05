#include "Enemy.h"
#include "macroFunction.h"
#include "Image.h"

HRESULT Enemy::Init()
{
	pos.x = WINSIZE_X;
	pos.y = WINSIZE_Y;
	speed = 1.0f;
	angle = PI;
	size = 100;
	isAlive = true;

	enemyImg = new Image();
	enemyImg->Init("spacedragon.bmp", 128, 128);

	return S_OK;
}

void Enemy::Release()
{

}

void Enemy::Update()
{
	pos.x += speed * cosf(angle);
	pos.y = WINSIZE_Y - size / 2 ;
}

void Enemy::Render(HDC hdc)
{
	if (isAlive)
	{
		//RenderEllipseToCenter(hdc, pos.x, pos.y, size, size);
		enemyImg->TransparentBltRender(hdc, pos.x - size / 2 - 20, pos.y - size / 2 - 5);
	}
}
