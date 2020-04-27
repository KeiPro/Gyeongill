#include "Tank.h"
#include "macroFunction.h"
#include "Missile.h"

HRESULT Tank::Init()
{
	// ����
	center.x = WINSIZE_X / 2;
	center.y = WINSIZE_Y;
	bodySize = 150;

	// ����
	barrelEnd.x = WINSIZE_X / 2;
	barrelEnd.y = center.y - 150;

	barrelAngle = PI / 4.0f ;

	return S_OK;
}

void Tank::Release()
{
}

void Tank::Update()
{
	// ���� �� ��ǥ�� �����Ӹ��� ����Ѵ�.
	barrelEnd.x = center.x + cosf(barrelAngle) * 150; //center x, y��ǥ�� �������� ���� ����� ���ش�.
	barrelEnd.y = center.y - sinf(barrelAngle) * 150;

	//�̻��� ��ġ ������Ʈ
	if (missile)
	{
		missile->SetPos(barrelEnd);
		missile->SetAngle(barrelAngle);
		missile->Update();
	}
}

void Tank::Render(HDC hdc)
{
	// ����
	RenderEllipseToCenter(hdc, center.x, center.y, bodySize, bodySize);

	// ����
	RenderLine(hdc, center.x, center.y, barrelEnd.x, barrelEnd.y);

	if (missile)
	{
		missile->Render(hdc);
	}
}

void Tank::Fire()
{
	if (missile)
	{
		missile->SetIsFire(true);
	}
}

Tank::Tank()
{
	missile = new Missile();
	missile->Init();
}

Tank::~Tank()
{
	delete missile;
}

