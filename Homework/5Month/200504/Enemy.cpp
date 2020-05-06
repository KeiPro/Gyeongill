#include "Enemy.h"
#include "macroFunction.h"
#include "Tank.h"

HRESULT Enemy::Init()
{
	pos.x = WINSIZE_X - 20;
	pos.y = -20;

	speed = 1.0f;
	angle = PI;
	size = 40;

	target = nullptr;

	return S_OK;
}

void Enemy::Release()
{
}

void Enemy::Update()
{
	// 타겟이 있는지 확인
	if (target)
	{
		// ...
	}

	pos.x += cosf(angle) * speed;
	pos.y -= sinf(angle) * speed;
}

void Enemy::Render(HDC hdc)
{

	RenderEllipseToCenter(hdc, pos.x, pos.y, size, size);
}

void Enemy::SetTarget(Tank * tank)
{
	target = tank;
	float x = (target->GetTankPosition().x - pos.x);
	float y = (target->GetTankPosition().y - pos.y);

	angle = atan2(-y, x);
}

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}
