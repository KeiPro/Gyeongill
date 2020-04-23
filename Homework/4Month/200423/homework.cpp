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

BOX currentBox;
BOX nextBox;
RECT enemyMissileRc[EnemyBox];
RECT enemyRc;
RECT playerRc, playerMissileRc;

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

bool CheckRectCollistion(RECT rc1, RECT rc2)
{
	if (((rc1.right < rc2.left) || (rc1.bottom < rc2.top) || (rc1.left > rc2.right) || (rc1.top > rc2.bottom)))
	{
		return false;
	}

	return true;
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
	enemyRc = RectCenterCreate(50, 100, 100, 100);
	playerRc = RectCenterCreate(600, 780, 120, 80);
	playerMissileRc = RectCenterCreate(600, 740, 20, 80);
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
	static 

	//�׷��� ���� ������ �ٲ۴�.
	//HPEN hPen, hOldPen;

	//������ ���θ� ä�� �� ����Ѵ�.
	HBRUSH hBrush, hOldBrush;

	static int r = rand() % 255, g = rand() % 255, b = rand() % 255;

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

			playerMissileRc.left = playerRc.left + 50;
			playerMissileRc.right = playerMissileRc.left + 20;

			break;

		case VK_RIGHT:
			playerRc.left += playerSpeed;
			playerRc.right += playerSpeed;

			playerMissileRc.left = playerRc.left + 50;
			playerMissileRc.right = playerMissileRc.left + 20;

			break;

		case VK_UP:

			break;

		case VK_ESCAPE:
			break;

		case VK_SPACE:



			break;
		}


		InvalidateRect(g_hWnd, NULL, true);
		break;
	case WM_CREATE:
		Init();

		//�Ű����� : ������ �ڵ�, Ÿ�̸ӹ�ȣ, ȣ�������, ȣ���Լ�
		//g_hWnd;
		hTimer = (HANDLE)SetTimer(hWnd, 0, 1, NULL); //�ڵ�, Ÿ�̸��� ���̵� ����, Ÿ�̸Ӱ� ȣ��� ����	Ÿ�̸Ӱ� ����ɶ� ����� �Լ�
		SendMessage(hWnd, WM_TIMER, 1, 0);
		break;

	case WM_TIMER:

		if (enemyVector)
		{
			enemyRc.left += 3;
			enemyRc.right += 3;
		}
		else
		{
			enemyRc.left -= 3;
			enemyRc.right -= 3;
		}

		InvalidateRect(g_hWnd, NULL, true); //ȭ�� ����.
		break;

	case WM_PAINT:		// ������ ȭ���� �ٽ� �׷����� ��쿡 �߻��ϴ� �޽���
		hdc = BeginPaint(g_hWnd, &ps);

#pragma region EnemyMove
		enemyRcMove(hdc, &enemyRc, &enemyVector, &r, &g, &b, &enemyColor);
		hBrush = CreateSolidBrush(RGB(r, g, b));
		hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);
		Rectangle(hdc, enemyRc.left, enemyRc.top, enemyRc.right, enemyRc.bottom);
#pragma endregion

#pragma region Player
		hBrush = CreateSolidBrush(RGB(128, 128, 128));
		hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);
		Rectangle(hdc, playerRc.left, playerRc.top, playerRc.right, playerRc.bottom);

		hBrush = CreateSolidBrush(RGB(255, 255, 128));
		hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);
		Rectangle(hdc, playerMissileRc.left, playerMissileRc.top, playerMissileRc.right, playerMissileRc.bottom);
#pragma endregion






		DeleteObject(hBrush);

		wsprintf(szText, "score : %d", 0);
		TextOut(hdc, 10, 0, szText, strlen(szText));

		EndPaint(g_hWnd, &ps);
		break;
	case WM_DESTROY:
		KillTimer(g_hWnd, 1);

		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}