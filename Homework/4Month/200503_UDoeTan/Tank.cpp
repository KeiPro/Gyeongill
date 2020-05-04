#include "Tank.h"
#include "macroFunction.h"
#include "Missile.h"
#include "Enemy.h"

HRESULT Tank::Init()
{
	// 몸통
	center.x = WINSIZE_X / 2;
	center.y = WINSIZE_Y;
	bodySize = 150;

	// 포신
	barrelEnd.x = WINSIZE_X / 2;
	barrelEnd.y = center.y - 150;

	barrelAngle = (float)(PI / 4.0f) ;
	shootTimer = 0; // 30프레임에 한 번씩.
	
	return S_OK;
}

void Tank::Release()
{

}

void Tank::Update()
{
	// 탱크의 키입력을 처리한다.
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

	//	if (shootTimer >= 20) //30프레임에 한 번씩
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

	// 포신 끝 좌표를 프레임마다 계산한다.
	barrelEnd.x = center.x + cosf(barrelAngle) * 150; //center x, y좌표를 기준으로 각도 계산을 해준다.
	barrelEnd.y = center.y - sinf(barrelAngle) * 150;

	//미사일 위치 업데이트
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
	// 몸통
	RenderEllipseToCenter(hdc, (int)center.x, (int)center.y, (int)bodySize, (int)bodySize);

	// 포신
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
	// 먼저 확인해야 하는 내용?
	for (int i = 0; i < missileMaxCount; i++)
	{
		if (missile != NULL)
		{
			if (missile[i].GetIsFire() == false)
			{
				shootCount++;
				if (shootCount % 3 == 0)
				{
					//////////////이 부분?????
					//에네미의 거리 계산이 되기 전에 SetMinEnemy를 처리하지 못하고, 윈도우 바깥에 있는 녀석을 계속 가리키고 있는 느낌이 든다.
					//시간이 지난 후 3번 쏴보면 올바른 녀석을 향해 간다.

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
								if (minEnemyDistance > tmpDistance) //현재 계산한 위치보다 더 작은 위치가 존재한다면 그 위치를 저장한다.
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

