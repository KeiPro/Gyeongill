#include <Windows.h>
#include <ctime>

struct StartStruct
{
	int mouseX;
	int mouseY;
	int randNum;
	bool isAlive;
};

HINSTANCE hInstance;
HWND g_hwnd;
LPSTR lpsz_Class = (LPSTR)TEXT("윈 메인 시작");

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMessage, WPARAM wparam, LPARAM lparam);

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

void RectCheck(RECT* _rc, int _mouseX, int _mouseY, RECT* _rc_interval, bool _rcClickCheck[], bool* isDrag);
void RactangleMove(HDC hdc, RECT * _rc, int _mouseX, int _mouseY, RECT* _rc_interval, bool _rcClickCheck[]);
void StarRender(HDC hdc, int x, int y, int randNum);


LRESULT CALLBACK WndProc(HWND hwnd, UINT iMessage, WPARAM wparam, LPARAM lparam)
{
	HDC hdc;	
	PAINTSTRUCT ps;

	static int mousePosX = 0;
	static int mousePosY = 0;
	static int value = 0;
	static int randNum = 0;
	static bool mouseClickCheck = false;
	static bool rcClickCheck[10] = { false };
	static bool rectangleIsAlive[10] = {true, true, true, true, true, true, true, true, true, true};
	static bool isDrag = false;
	static int count = 0;

	static RECT rc[10] = { 100, 100, 200, 200 };
	static RECT rc_interval = {0, 0, 0, 0};
	static StartStruct star[10];

	char s2Text[128] = "";
	char szText[128] = "";

	switch (iMessage)
	{
	case WM_LBUTTONUP:
		mouseClickCheck = false;
		isDrag = false;

		mousePosX = LOWORD(lparam);
		mousePosY = HIWORD(lparam);

		for (int i = 0; i < 10; i++)
		{
			if (rcClickCheck[i] != false && star[i].isAlive == false)
			{
				star[i].mouseX = mousePosX;
				star[i].mouseY = mousePosY;
				star[i].randNum = rand() % 100 + 50;
				star[i].isAlive = true;
			}
		}

		InvalidateRect(g_hwnd, NULL, true);

		break;

	case WM_LBUTTONDOWN:
		mousePosX = LOWORD(lparam);
		mousePosY = HIWORD(lparam);
		mouseClickCheck = true;

		//누를때마다 발생하는 함수.
		InvalidateRect(g_hwnd, NULL, true);
		break;

	case WM_MOUSEMOVE:

		if (mouseClickCheck == true && isDrag == true)
		{
			mousePosX = LOWORD(lparam);
			mousePosY = HIWORD(lparam);

			InvalidateRect(g_hwnd, NULL, true);
		}
		break;

	case WM_CREATE:

		for (int i = 0; i < 10; i++)
		{
			rc[i] = { i * 110, 900 - 200, (i + 1) * 110, 800 };
			star[i].mouseX = 0;
			star[i].mouseY = 0;
			star[i].isAlive = false;
		}

		InvalidateRect(g_hwnd, NULL, true);
		break;

	case WM_PAINT:
		hdc = BeginPaint(g_hwnd, &ps);

		TextOut(hdc, 10, 10, "Hello, WinMain!", 15);

		for (int i = 0; i < 10; i++)
		{
			if (mouseClickCheck == false && isDrag == false && rcClickCheck[i] == true)
			{
				rectangleIsAlive[i] = false;
			}
		}

		for (int i = 0; i < 10; i++)
		{
			if (rectangleIsAlive[i] == true)
			{
				Rectangle(hdc, rc[i].left, rc[i].top, rc[i].right, rc[i].bottom);
			}
			else
			{
				StarRender(hdc, star[i].mouseX, star[i].mouseY, star[i].randNum);
			}
		}

		if (mouseClickCheck)
		{
			RectCheck(rc, mousePosX, mousePosY, &rc_interval, rcClickCheck, &isDrag);
			RactangleMove(hdc, rc, mousePosX, mousePosY, &rc_interval, rcClickCheck);
		}

	

		EndPaint(g_hwnd, &ps);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hwnd, iMessage, wparam, lparam);
}

void RectCheck(RECT * _rc, int _mouseX, int _mouseY, RECT* _rc_interval, bool _rcClickCheck[], bool* isDrag)
{
	for (int i = 0; i < 10; i++)
	{
		if ( (*isDrag == false) && (_mouseX > _rc[i].left) && (_mouseX < _rc[i].right) && (_mouseY > _rc[i].top) && (_mouseY < _rc[i].bottom))
		{
			*isDrag = true;
			_rcClickCheck[i] = true;
			(*_rc_interval) = {_mouseX-_rc[i].left, _mouseY -_rc[i].top, _rc[i].right - _mouseX, _rc[i].bottom-_mouseY};
		}
	}
}

void RactangleMove(HDC hdc, RECT * _rc, int _mouseX, int _mouseY, RECT* _rc_interval, bool _rcClickCheck[])
{
	for (int i = 0; i < 10; i++)
	{
		if (_rcClickCheck[i])
		{
			_rc[i] = { _mouseX - (_rc[i].right - _rc[i].left) / 2 , 
				_mouseY - (_rc[i].bottom - _rc[i].top)/2,
				_mouseX + (_rc[i].right - _rc[i].left) / 2 ,
				_mouseY + (_rc[i].bottom - _rc[i].top) / 2 };
		}
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