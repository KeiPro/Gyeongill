#include <Windows.h>
#include <ctime>

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

void RectCheck(RECT* _rc, int _mouseX, int _mouseY, RECT* _rc_interval, bool _rcClickCheck[]);
void RactangleMove(HDC hdc, RECT * _rc, int _mouseX, int _mouseY, RECT* _rc_interval, bool _rcClickCheck[]);

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

	static RECT rc[10] = { 100, 100, 200, 200 };
	static RECT rc_interval = {0, 0, 0, 0};


	char s2Text[128] = "";
	char szText[128] = "";

	switch (iMessage)
	{
	case WM_LBUTTONUP:
		mouseClickCheck = false;
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
		mousePosX = LOWORD(lparam);
		mousePosY = HIWORD(lparam);

		InvalidateRect(g_hwnd, NULL, true);
		break;

	case WM_CREATE:

		for (int i = 0; i < 10; i++)
		{
			rc[i] = { i * 120, 900 - 80, (i + 1) * 120, 900 };
		}

		InvalidateRect(g_hwnd, NULL, true);
		break;
	
	case WM_PAINT:	
		hdc = BeginPaint(g_hwnd, &ps);

		TextOut(hdc, 10, 10, "Hello, WinMain!", 15);
		wsprintf(szText, "%d, %d, %d, %d", rc_interval.left, rc_interval.top, rc_interval.right, rc_interval.bottom);
		TextOut(hdc, 300, 10, szText, strlen(szText));

		for (int i = 0; i < 10; i++)
		{
			Rectangle(hdc, rc[i].left, rc[i].top, rc[i].right, rc[i].bottom);
		}

		if (mouseClickCheck)
		{
			RectCheck(rc, mousePosX, mousePosY, &rc_interval, rcClickCheck);
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

void RectCheck(RECT * _rc, int _mouseX, int _mouseY, RECT* _rc_interval, bool _rcClickCheck[])
{
	for (int i = 0; i < 10; i++)
	{
		if ((_mouseX >= _rc[i].left) && (_mouseX < _rc[i].right) && (_mouseY >= _rc[i].top) && (_mouseY < _rc[i].bottom))
		{
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
			_rc[i] = { _mouseX - _rc[i].left , _mouseY - _rc[i].top, _rc[i].right + _mouseX, _rc[i].bottom + _mouseY };
			Rectangle(hdc, _rc[i].left, _rc[i].top, _rc[i].right, _rc[i].bottom);
		}
		else
		{
			Rectangle(hdc, _rc[i].left, _rc[i].top, _rc[i].right, _rc[i].bottom);
		}
	}
}
