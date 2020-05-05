#include "Enemy.h"
#include "macroFunction.h"

HRESULT Enemy::Init()
{
	pos.x = WINSIZE_X;
	pos.y = WINSIZE_Y;
	speed = 1.0f;
	angle = PI;
	size = 50;
	isAlive = true;

	return S_OK;
}

void Enemy::Release()
{

}

void Enemy::Update()
{
	pos.x += speed * cosf(angle);
	pos.y = WINSIZE_Y - size / 2;
}

void Enemy::Render(HDC hdc)
{
	if(isAlive)
		RenderEllipseToCenter(hdc, pos.x, pos.y, size, size);
}
