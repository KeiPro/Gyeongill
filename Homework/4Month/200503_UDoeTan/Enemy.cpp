#include "Enemy.h"
#include "macroFunction.h"
#include "MainGame.h"
#include "Tank.h"

HRESULT Enemy::Init()
{
	myPos.x = rand() % 800 - 100; myPos.y = -30;
	tankPos.x = mainGame->GetTank()->GetTankPosition().x;
	tankPos.y = mainGame->GetTank()->GetTankPosition().y;
	directionX = 0; directionY = 0;
	normalVectorX = 0; normalVectorY = 0;
	sqrtValue = 0;
	speed = rand()%3+1;
	size = 50;
	shootDown = false;

	return S_OK;
}

void Enemy::Release()
{
}

void Enemy::Update()
{
	if (shootDown == true)
	{
		myPos.x = 300;
		myPos.y = -1200;

		return;
	}
		
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
	if (shootDown == true)
		return;

	RenderEllipseToCenter(hdc, myPos.x, myPos.y, size, size);
}
