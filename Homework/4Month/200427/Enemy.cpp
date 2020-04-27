#include "Enemy.h"
#include "macroFunction.h"
#include "MainGame.h"
#include "Tank.h"

HRESULT Enemy::Init()
{
	myPos.x = rand()% (int)(WINSIZE_X * 1.5); myPos.y = -30;
	tankPos.x = mainGame->GetTank()->GetTankPosition().x;
	tankPos.y = mainGame->GetTank()->GetTankPosition().y;
	directionX = 0; directionY = 0;
	normalVectorX = 0; normalVectorY = 0;
	sqrtValue = 0;
	speed = 5;
	size = 50;

	return S_OK;
}

void Enemy::Release()
{
}

void Enemy::Update()
{
	directionX = tankPos.x - myPos.x;
	directionY = tankPos.y - myPos.y;
	sqrtValue = directionX * directionX + directionY * directionY;
	sqrtValue = sqrt(sqrtValue);
	normalVectorX = (float)directionX / sqrtValue;
	normalVectorY = (float)directionY / sqrtValue;

	myPos.x += normalVectorX * speed;
	myPos.y += normalVectorY * speed;

}

void Enemy::Render(HDC hdc)
{
	RenderEllipseToCenter(hdc, myPos.x, myPos.y, size, size);
}
