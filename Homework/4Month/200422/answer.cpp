#include <Windows.h>
#include <ctime>

HINSTANCE hInstance;
HWND g_hwnd;
LPSTR lpsz_Class = (LPSTR)TEXT("윈 메인 시작");

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMessage, WPARAM wparam, LPARAM lparam);

struct Star
{
	int mousePosX;
	int mousePosY;
	int randNum;
	bool isCreate;
};

int APIENTRY WinMain(HINSTANCE _hInstance, HINSTANCE _prevInstance, LPSTR lpstr, int nCmdShow)
{
	srand(time(NULL));
	hInstance = _hInstance;
	WNDCLASS wndClass;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hInstance = hInstance;
	wndClass.lpfnWndProc = WndProc;
	wndClass.lpszClassName = lpsz_Class;
	wndClass.lpszMenuName = NULL;
	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&wndClass);

	g_hwnd = CreateWindow(lpsz_Class, lpsz_Class, WS_OVERLAPPEDWINDOW, 50, 50, 1200, 900, NULL, NULL, hInstance, NULL);
	ShowWindow(g_hwnd, nCmdShow);

	MSG message;
	while (GetMessage(&message, 0, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	return message.wParam;
}

void RectCheck(RECT* _rc, int _mouseX, int _mouseY, RECT* _rc_interval, bool _rcClickCheck[]);
void RactangleMove(HDC hdc, RECT * _rc, int _mouseX, int _mouseY, RECT* _rc_interval, bool _rcClickCheck[]);

RECT GetRectToCenter(int x, int y, int width, int height)
{
	RECT rc = { x - (width / 2), y - (height / 2), x + (width / 2), y + (height / 2) };

	return rc;
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

void Init(RECT* rc, Star* _star)
{
	for (int i = 0; i < 10; i++)
	{
		rc[i].left = 10 + i * 60;
		rc[i].right = rc[i].left + 50;
		rc[i].top = 780;
		rc[i].bottom = rc[i].top + 50;

		_star[i].isCreate = false;
		_star[i].mousePosX = 0;
		_star[i].mousePosY = 0;
		_star[i].randNum = 0;
	}
}

void Render(HDC hdc, RECT* rc, Star* star)
{
	for (int i = 0; i < 10; i++)
	{
		if (star[i].isCreate == true)
		{
			StarRender(hdc, star[i].mousePosX, star[i].mousePosY, star[i].randNum);
		}
		else
		{
			Rectangle(hdc, rc[i].left, rc[i].top, rc[i].right, rc[i].bottom);
		}
	}
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMessage, WPARAM wparam, LPARAM lparam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	static int selectedBox = -1;
	static int mousePosX = 0;
	static int mousePosY = 0;
	static int prevMousePosX;
	static int prevMousePosY;
	static int value = 0;
	static int randNum = 0;
	static bool isLButtonDown = false;
	static Star star[10];

	static RECT rc[10];

	switch (iMessage)
	{

	case WM_KEYDOWN:

		switch (wparam)
		{
		case VK_ESCAPE:
			Init(rc, star);
			InvalidateRect(hwnd, NULL, true);
			break;
		}

		break;

	case WM_CREATE:

		Init(rc, star);

		break;

	case WM_LBUTTONUP:

		isLButtonDown = false;

		if (selectedBox != -1)
		{
			star[selectedBox].mousePosX = mousePosX;
			star[selectedBox].mousePosY = mousePosY;
			star[selectedBox].randNum = rand() % 100 + 50;
			star[selectedBox].isCreate = true;
		}

		selectedBox = -1;
		InvalidateRect(g_hwnd, NULL, true);

		break;

	case WM_LBUTTONDOWN:
		isLButtonDown = true;

		mousePosX = LOWORD(lparam);
		mousePosY = HIWORD(lparam);

		for (int i = 0; i < 10; i++)
		{
			if (!(rc[i].left > mousePosX || rc[i].right < mousePosX || rc[i].top > mousePosY || rc[i].bottom < mousePosY))
			{
				selectedBox = i;
				break;
			}
		}

		//누를때마다 발생하는 함수.
		InvalidateRect(g_hwnd, NULL, true);
		break;

	case WM_MOUSEMOVE:
		if (isLButtonDown)
		{
			mousePosX = LOWORD(lparam);
			mousePosY = HIWORD(lparam);

			if (selectedBox > -1)
			{
				rc[selectedBox] = GetRectToCenter(mousePosX, mousePosY, 50, 50);
			}

			InvalidateRect(g_hwnd, NULL, true);
		}
		break;
	

	case WM_PAINT:
		hdc = BeginPaint(g_hwnd, &ps);

		TextOut(hdc, 10, 10, "Hello, WinMain!", 15);
		
		Render(hdc, rc, star);
		EndPaint(g_hwnd, &ps);

		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hwnd, iMessage, wparam, lparam);
}