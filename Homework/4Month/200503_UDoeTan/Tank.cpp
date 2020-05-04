#include "Tank.h"
#include "macroFunction.h"
#include "Missile.h"
#include "Enemy.h"

HRESULT Tank::Init()
{
	// ����
	center.x = WINSIZE_X / 2;
	center.y = WINSIZE_Y;
	bodySize = 150;

	// ����
	barrelEnd.x = WINSIZE_X / 2;
	barrelEnd.y = center.y - 150;

	barrelAngle = (float)(PI / 4.0f) ;
	shootTimer = 0; // 30�����ӿ� �� ����.
	
	return S_OK;
}

void Tank::Release()
{

}

void Tank::Update()
{
	// ��ũ�� Ű�Է��� ó���Ѵ�.
	if (KeyManager::GetSingleton()->IsStayKeyDown(VK_LEFT))
	{
		barrelAngle += (float)(PI / 180 * 3);
	}
	else if (KeyManager::GetSingleton()->IsStayKeyDown(VK_RIGHT))
	{
		barrelAngle -= (float)(PI / 180 * 3);
	}

	//if (KeyManager::GetSingleton()->IsStayKeyDown(VK_SPACE))
	//{
	//	shootTimer++;

	//	if (shootTimer >= 20) //30�����ӿ� �� ����
	//	{
	//		shootTimer = 0;
	//		Fire();
	//	}
	//}

	//if (KeyManager::GetSingleton()->IsOnceKeyUp(VK_SPACE))
	//{
	//	Fire();
	//}	

	if (KeyManager::GetSingleton()->IsOnceKeyDown(VK_SPACE))
	{
		Fire();
	}

	// ���� �� ��ǥ�� �����Ӹ��� ����Ѵ�.
	barrelEnd.x = center.x + cosf(barrelAngle) * 150; //center x, y��ǥ�� �������� ���� ����� ���ش�.
	barrelEnd.y = center.y - sinf(barrelAngle) * 150;

	//�̻��� ��ġ ������Ʈ
	if (missile)
	{
		for (int i = 0; i < missileMaxCount; i++)
		{
			missile[i].Update();
		}
	}

	
}

void Tank::Render(HDC hdc)
{
	// ����
	RenderEllipseToCenter(hdc, (int)center.x, (int)center.y, (int)bodySize, (int)bodySize);

	// ����
	RenderLine(hdc, (int)center.x, (int)center.y, (int)barrelEnd.x, (int)barrelEnd.y);

	if (missile)
	{
		for (int i = 0; i < missileMaxCount; i++)
		{
			missile[i].Render(hdc);
		}
	}
}

void Tank::Fire()
{
	// ���� Ȯ���ؾ� �ϴ� ����?
	for (int i = 0; i < missileMaxCount; i++)
	{
		if (missile != NULL)
		{
			if (missile[i].GetIsFire() == false)
			{
				shootCount++;
				if (shootCount % 3 == 0)
				{
					//////////////�� �κ�?????
					//���׹��� �Ÿ� ����� �Ǳ� ���� SetMinEnemy�� ó������ ���ϰ�, ������ �ٱ��� �ִ� �༮�� ��� ����Ű�� �ִ� ������ ���.
					//�ð��� ���� �� 3�� ������ �ùٸ� �༮�� ���� ����.

					if (enemy != NULL)
					{
						for (int i = 0; i < enemyCount; i++)
						{
							if (enemy[i].GetShootDown() == true) continue;

							tmpDistance = GetDistance(center.x, center.y, enemy[i].GetMyPos().x, enemy[i].GetMyPos().y);

							if (minEnemyDistance == -1)
							{
								minEnemyDistance = tmpDistance;
								tmpEnemy = &(enemy[i]);
							}
							else
							{
								if (minEnemyDistance > tmpDistance) //���� ����� ��ġ���� �� ���� ��ġ�� �����Ѵٸ� �� ��ġ�� �����Ѵ�.
								{
									minEnemyDistance = tmpDistance;
									tmpEnemy = &(enemy[i]);
								}
							}
						}

						minEnemyDistance = -1;
						minEnemy = tmpEnemy;
					}

					missile[i].SetUDoeTan(true);
					missile[i].SetMinEnemy(minEnemy);
					

					shootCount = 0;
				}
				missile[i].SetIsFire(true);
				missile[i].SetPos(barrelEnd);
				missile[i].SetAngle(barrelAngle);
				missile[i].SetTmpAngle(barrelAngle);
				break;
			}
		}
	}
}

Tank::Tank() : missileMaxCount(1), shootCount(0), minEnemyDistance(-1)
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

