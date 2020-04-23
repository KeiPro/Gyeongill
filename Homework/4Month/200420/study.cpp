#include <Windows.h>

HINSTANCE hInstance;
HWND hwnd;
LPSTR lpsz_Class = (LPSTR)TEXT("윈도우 메인 시작");

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMessage, WPARAM wparam, LPARAM lparam);

int APIENTRY WinMain(HINSTANCE _hInstance, HINSTANCE _prevInstance, LPSTR _lpstr, int nCmdShow)
{
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

	hwnd = CreateWindow(lpsz_Class, lpsz_Class, WS_OVERLAPPEDWINDOW, 50, 50, 1200, 900, NULL, NULL, hInstance, NULL);
	ShowWindow(hwnd);

	MSG message;
	while (GetMessage(&message, 0, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	return message.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMessage, WPARAM wparam, LPARAM lparam)
{
	switch ( iMessage )
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hwnd, iMessage, wparam, lparam);
}