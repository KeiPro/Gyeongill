#include <Windows.h>
#include <ctime>

// 전역변수
HINSTANCE	g_hInstance;	// 프로그램 인스턴스 핸들
HWND		g_hWnd;			// 윈도우 핸들
LPSTR		g_lpszClass = (LPSTR)TEXT("윈메인의 시작");

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

// 윈도우를 생성하기 위한 함수
int APIENTRY WinMain(HINSTANCE _hInstance, HINSTANCE _hPrevInstance,
	LPSTR _lpszCmdParam, int nCmdShow)
{
	srand(time(NULL));

	// 윈도우 생성을 위한 기본셋팅
	g_hInstance = _hInstance;
	WNDCLASS wndClass;
	wndClass.cbClsExtra = 0;	// 클래스 여분 메모리
	wndClass.cbWndExtra = 0;	// 윈도우 여분 메모리
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hInstance = g_hInstance;
	wndClass.lpfnWndProc = WndProc;
	wndClass.lpszClassName = g_lpszClass;
	wndClass.lpszMenuName = NULL;
	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	// 윈도우 클래스 등록
	RegisterClass(&wndClass);

	// 윈도우 생성
	g_hWnd = CreateWindow(g_lpszClass, g_lpszClass,
		WS_OVERLAPPEDWINDOW,
		50, 50,
		1200, 900,
		NULL,
		NULL,
		g_hInstance,
		NULL);

	// 윈도우 출력
	ShowWindow(g_hWnd, nCmdShow);

	// 메시지 큐에 있는 메시지 처리
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


// 윈도우 메시지(이벤트)를 처리하는 함수
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

	//그려질 선의 정보를 바꾼다.
	//HPEN hPen, hOldPen;

	//도형의 내부를 채울 때 사용한다.
	HBRUSH hBrush, hOldBrush;

	static int r = rand() % 255, g = rand() % 255, b = rand() % 255;

	//static RECT rc[10];

	// 타이머 객체를 지정하는 핸들
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

		//매개변수 : 윈도우 핸들, 타이머번호, 호출딜레이, 호출함수
		//g_hWnd;
		hTimer = (HANDLE)SetTimer(hWnd, 0, 1, NULL); //핸들, 타이머의 아이디 설정, 타이머가 호출될 간격	타이머가 실행될때 실행될 함수
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

		InvalidateRect(g_hWnd, NULL, true); //화면 갱신.
		break;

	case WM_PAINT:		// 윈도우 화면이 다시 그려지는 경우에 발생하는 메시지
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