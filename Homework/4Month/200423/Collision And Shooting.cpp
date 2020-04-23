#include <Windows.h>
#include <ctime>

// ��������
HINSTANCE	g_hInstance;	// ���α׷� �ν��Ͻ� �ڵ�
HWND		g_hWnd;			// ������ �ڵ�
LPSTR		g_lpszClass = (LPSTR)TEXT("�������� ����");

enum BOX
{
	EnemyBox = 5
};

struct Missile
{
	RECT missileRect;
	bool shoot;
};

BOX currentBox;
BOX nextBox;
RECT enemyTurretRc[EnemyBox];
RECT enemyMissileRc[EnemyBox];
RECT enemyRc;
RECT playerRc;
Missile playerMissile;
RECT longCollision;

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage,
	WPARAM wParam, LPARAM lParam);

// �����츦 �����ϱ� ���� �Լ�
int APIENTRY WinMain(HINSTANCE _hInstance, HINSTANCE _hPrevInstance,
	LPSTR _lpszCmdParam, int nCmdShow)
{
	srand(time(NULL));

	// ������ ������ ���� �⺻����
	g_hInstance = _hInstance;
	WNDCLASS wndClass;
	wndClass.cbClsExtra = 0;	// Ŭ���� ���� �޸�
	wndClass.cbWndExtra = 0;	// ������ ���� �޸�
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hInstance = g_hInstance;
	wndClass.lpfnWndProc = WndProc;
	wndClass.lpszClassName = g_lpszClass;
	wndClass.lpszMenuName = NULL;
	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	// ������ Ŭ���� ���
	RegisterClass(&wndClass);

	// ������ ����
	g_hWnd = CreateWindow(g_lpszClass, g_lpszClass,
		WS_OVERLAPPEDWINDOW,
		50, 50,
		1200, 900,
		NULL,
		NULL,
		g_hInstance,
		NULL);

	// ������ ���
	ShowWindow(g_hWnd, nCmdShow);

	// �޽��� ť�� �ִ� �޽��� ó��
	MSG message;
	while (GetMessage(&message, 0, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	return message.wParam;
}


void enemyRcMove(HDC hdc, RECT* rc, bool* vector, int* r, int* g, int* b, int* solidColor)
{
	if (rc->left + 100 >= 1200)
	{
		*r = rand() % 255; *g = rand() % 255; *b = rand() % 255;
		*solidColor = rand() % 255;
		*vector = false;
	}
	else if (rc->left <= 0)
	{
		*r = rand() % 255;	*g = rand() % 255;	*b = rand() % 255;
		*solidColor = rand() % 255;
		*vector = true;
	}
}

void StarRender(HDC hdc, int x, int y, int randNum)
{

	MoveToEx(hdc, x + (int)(randNum * 0.4f), y - (int)(randNum * 0.5f), NULL);
	LineTo(hdc, x - (int)(randNum * 0.5f), y + (int)(randNum * 0.2f));
	LineTo(hdc, x + (int)(randNum * 0.5f), y + (int)(randNum * 0.2f));
	LineTo(hdc, x - (int)(randNum * 0.4f), y - (int)(randNum * 0.5f));
	LineTo(hdc, x, y + (int)(randNum * 0.6f));
	LineTo(hdc, x + (int)(randNum * 0.4f), y - (int)(randNum * 0.5f));
}

bool CollisionCheck(RECT rc1, RECT rc2)
{
	if (rc2.top > rc1.bottom || rc2.right < rc1.left || rc2.left > rc1.right || rc2.bottom < rc1.top)
	{
		return false;
	}

	return true;
}

RECT RectCenterCreate(int x, int y, int width, int height)
{
	RECT rc = { x - width / 2, y - height/2, x + width /2, y+height/2};
	return rc;
}

RECT GetRect(int x, int y, int width, int height)
{
	RECT rc = { x, y, x + width, y + height };
	return rc;
}


void Init()
{
	longCollision = RectCenterCreate(600, -30, 1200, 20);
	enemyRc = RectCenterCreate(50, 100, 100, 100);
	playerRc = RectCenterCreate(600, 780, 120, 80);
	playerMissile.missileRect = RectCenterCreate(600, 740, 20, 80);
	playerMissile.shoot = false;
}

void EnemyShoot()
{
	for (int i = 0; i < 5; i++)
	{
		enemyTurretRc[i] = RectCenterCreate((rand() % (190 - 50 + 1) + 50) + 240 * i, 10, 50, 50);
		enemyMissileRc[i] = { enemyTurretRc[i].left + 14, 
							  enemyTurretRc[i].top + 14,
							  enemyTurretRc[i].right - 14,
							  enemyTurretRc[i].bottom - 14};
	}
}


// ������ �޽���(�̺�Ʈ)�� ó���ϴ� �Լ�
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage,
	WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	char szText[128] = "";
	static bool enemyVector = true;
	static int enemyColor = rand() % 255;
	static int playerSpeed = 10;
	static int score = 0;
	static int enemySpeed = 3;
	static int timer = 0;
	static bool enemyCollision = false;
	static bool longCollisionCheck = false;
	static bool gameOver = false;
	static bool collisionEnemyMissile = false;
	static bool gameClear = false;

	

	//�׷��� ���� ������ �ٲ۴�.
	//HPEN hPen, hOldPen;

	//������ ���θ� ä�� �� ����Ѵ�.
	HBRUSH hBrush, hOldBrush;

	static int r = rand() % 255, g = rand() % 255, b = rand() % 255;
	static int missileR = rand() % 255, missileG = rand() % 255, missileB = rand() % 255;

	//static RECT rc[10];

	// Ÿ�̸� ��ü�� �����ϴ� �ڵ�
	static HANDLE hTimer;

	switch (iMessage)
	{
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_LEFT:
			playerRc.left -= playerSpeed;
			playerRc.right -= playerSpeed;

			if (playerMissile.shoot == false) {
				playerMissile.missileRect.left = playerRc.left + 50;
				playerMissile.missileRect.right = playerMissile.missileRect.left + 20;
			}
			break;

		case VK_RIGHT:
			playerRc.left += playerSpeed;
			playerRc.right += playerSpeed;

			if (playerMissile.shoot == false) {
				playerMissile.missileRect.left = playerRc.left + 50;
				playerMissile.missileRect.right = playerMissile.missileRect.left + 20;
			}
			break;

		case VK_UP:

			break;

		case VK_ESCAPE:
			break;

		case VK_SPACE:

			if (playerMissile.shoot == false)
			{
				playerMissile.shoot = true;
			}
			break;
		}

		InvalidateRect(g_hWnd, NULL, true);
		break;
	case WM_CREATE:
		Init();

		//�Ű����� : ������ �ڵ�, Ÿ�̸ӹ�ȣ, ȣ�������, ȣ���Լ�
		//g_hWnd;
		hTimer = (HANDLE)SetTimer(hWnd, 0, 10, NULL); //�ڵ�, Ÿ�̸��� ���̵� ����, Ÿ�̸Ӱ� ȣ��� ����	Ÿ�̸Ӱ� ����ɶ� ����� �Լ�
		//hTimer = (HANDLE)SetTimer(hWnd, 1, 100, NULL); 
		SendMessage(hWnd, WM_TIMER, 1, 0);
		break;

	case WM_TIMER:
		switch (wParam)
		{
		case 0:

			if (enemyVector)
			{
				enemyRc.left += enemySpeed;
				enemyRc.right += enemySpeed;
			}
			else
			{
				enemyRc.left -= enemySpeed;
				enemyRc.right -= enemySpeed;
			}

			if (playerMissile.shoot == true)
			{
				playerMissile.missileRect.top -= 5;
				playerMissile.missileRect.bottom -= 5;
			}

			if (longCollisionCheck == true)
			{
				for (int i = 0; i < 5; i++)
				{
					enemyMissileRc[i].top += 5;
					enemyMissileRc[i].bottom += 5;
				}
			}

			break;

		default:
			break;
		}
		

		InvalidateRect(g_hWnd, NULL, true); //ȭ�� ����.
		break;

	case WM_PAINT:		// ������ ȭ���� �ٽ� �׷����� ��쿡 �߻��ϴ� �޽���
		hdc = BeginPaint(g_hWnd, &ps);

		if (gameClear == true)
		{
			for (int i = 0; i < 30; i++)
			{
				StarRender(hdc, rand() % 800 + 200, rand() % 700 + 50, rand() % 500);
				Sleep(100);
			}

			return 0;
		}


#pragma region EnemyMove
		
#pragma endregion
		Rectangle(hdc, longCollision.left, longCollision.top, longCollision.right, longCollision.bottom);


#pragma region Player
		hBrush = CreateSolidBrush(RGB(153, 76, 0));
		hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);
		Rectangle(hdc, playerRc.left, playerRc.top, playerRc.right, playerRc.bottom);

#pragma endregion

//Collision Check

		if ( (enemyCollision == true) || (longCollisionCheck == true) )
		{
			playerMissile.missileRect.left = playerRc.left + 50;
			playerMissile.missileRect.right = playerMissile.missileRect.left + 20;
			playerMissile.missileRect.top = 700;
			playerMissile.missileRect.bottom = 780;

			if (enemyCollision == true)
			{
				timer++;
			}
			else
			{
				timer++;
				enemyRcMove(hdc, &enemyRc, &enemyVector, &r, &g, &b, &enemyColor);
				hBrush = CreateSolidBrush(RGB(r, g, b));
				hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);
				Rectangle(hdc, enemyRc.left, enemyRc.top, enemyRc.right, enemyRc.bottom);

				
				hBrush = CreateSolidBrush(RGB(255, 0, 0));
				hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);
				for (int i = 0; i < 5; i++)
				{
					Rectangle(hdc, enemyTurretRc[i].left, enemyTurretRc[i].top, enemyTurretRc[i].right, enemyTurretRc[i].bottom);
				}

				missileR = rand() % 255; missileG = rand() % 255; missileB = rand() % 255;

				hBrush = CreateSolidBrush(RGB(missileR, missileG, missileB));
				hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);
				for (int i = 0; i < 5; i++)
				{
					Ellipse(hdc, enemyMissileRc[i].left, enemyMissileRc[i].top, enemyMissileRc[i].right, enemyMissileRc[i].bottom);
					if (CollisionCheck(playerRc, enemyMissileRc[i]))
					{
						TextOut(hdc, 600, 450, szText, strlen(szText));
						hBrush = CreateSolidBrush(RGB(255,0,0));
						hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);
						Ellipse(hdc, 0, 0, 1200, 900);
						//collisionEnemyMissile = true; //�������� �ּ� ó��
					}
				}

			}
		}
		else if ( (enemyCollision == false) && (longCollisionCheck == false))
		{
			enemyRcMove(hdc, &enemyRc, &enemyVector, &r, &g, &b, &enemyColor);
			hBrush = CreateSolidBrush(RGB(r, g, b));
			hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);
			Rectangle(hdc, enemyRc.left, enemyRc.top, enemyRc.right, enemyRc.bottom);

			hBrush = CreateSolidBrush(RGB(255, 255, 128));
			hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);
			Rectangle(hdc, playerMissile.missileRect.left, playerMissile.missileRect.top, playerMissile.missileRect.right, playerMissile.missileRect.bottom);
		}

		if ( (timer >= 120.0f) && (enemyCollision == true))
		{
			timer = 0;
			enemyCollision = false;
			playerMissile.shoot = false;
		}

		//enemy�� �̻����� �浹���� ���.
		if (CollisionCheck(enemyRc, playerMissile.missileRect))
		{
			enemyCollision = true;
			score += 100;
			enemyColor = rand() % 255;
			enemySpeed += 5;

			
		}

		if (CollisionCheck(playerMissile.missileRect, longCollision))
		{
			EnemyShoot();
			longCollisionCheck = true;
		}

		if ((longCollisionCheck == true) && (timer >= 280))
		{
			timer = 0;
			longCollisionCheck = false;
			playerMissile.shoot = false;
			if (collisionEnemyMissile)
				gameOver = true;
		}

		if (gameOver)
		{
			SendMessage(hWnd, WM_CLOSE, 0, 0);
		}
		
		DeleteObject(hBrush);

		wsprintf(szText, "score : %d ", score);
		TextOut(hdc, 10, 0, szText, strlen(szText));

		if (score >= 300)
		{
			gameClear = true;
		}

		EndPaint(g_hWnd, &ps);
		break;
	case WM_DESTROY:
		KillTimer(g_hWnd, 0);
		KillTimer(g_hWnd, 1);

		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}