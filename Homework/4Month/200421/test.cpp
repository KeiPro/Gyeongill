#include <Windows.h>
#include <ctime>

HINSTANCE hInstance;
HWND g_hwnd;
LPSTR lpsz_Class = (LPSTR)TEXT("윈 메인 시작");

void RenderRect(HDC hdc, int x, int y, int width, int height);
void StartRender(HDC hdc, int x, int y, int randNum);

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

// x, y : 시작 위치
// width, height : 너비, 높이
void RenderRect(HDC hdc, int x, int y, int width, int height)
{
	Rectangle(hdc, x, y, x + width, y + height);
}

void StartRender(HDC hdc, int x, int y, int randNum)
{
	MoveToEx(hdc, x + (int)(randNum * 0.4f), y - (int)(randNum * 0.5f), NULL);
	LineTo(hdc, x - (int)(randNum * 0.5f), y + (int)(randNum * 0.2f));
	LineTo(hdc, x + (int)(randNum * 0.5f), y + (int)(randNum * 0.2f));
	LineTo(hdc, x - (int)(randNum * 0.4f), y - (int)(randNum * 0.5f));
	LineTo(hdc, x, y + (int)(randNum * 0.6f));
	LineTo(hdc, x + (int)(randNum * 0.4f), y - (int)(randNum * 0.5f));
}



// centerX, centerY : 사각형의 중점
// width, height : 너비, 높이
void RenderRectToCenter(HDC hdc, int centerX, int centerY, int width, int height)
{
	Rectangle(hdc, centerX - (width / 2), centerY - (height / 2), centerX + (width / 2), centerY + (height / 2));
}

void MoveRectangle(HDC hdc, int mouseX, int mouseY, int mouseClickCheck )
{
	if(mouseClickCheck)
	{
		RenderRectToCenter(hdc, mouseX, mouseY , 100, 100);
	}
}



LRESULT CALLBACK WndProc(HWND hwnd, UINT iMessage, WPARAM wparam, LPARAM lparam)
{
	// LPARAM lparam : 마우스 이벤트를 담당하는 것. lparam : 마우스 좌표

	HDC hdc;	 //H : Handle - DC의 핸들. DC(Device Context) 윈도우창에 텍스트를 출력하거나 그림을 그리거나 하는 가장 기본적인 도구.
	//hdc = GetDC(g_hwnd);

	//ReleaseDC(g_hwnd, hdc); //메모리 해제.
	PAINTSTRUCT ps;

	/*
		변수
		1. 지역변수 ( 함수 내에서 선언 ) 
			선언되는 메모리 영역이 다르다.  
			(Stack 영역)
			함수가 종료되는 시점에서 자동으로 메모리 해제.


		2. 전역변수 ( 함수 외부에서 선언 ) //프로그램 끝날때까지 해제가 안된다.
			( 데이터 영역 )
			프로그램 종료시에 해제.


		3. static 변수
			선언되는 메모리 영역 : (데이터 영역)
			해제되는 시점 : 프로그램 종료시에 해제.
			해당 영역(함수)에서만 접근이 된다. == 지역변수,근데 지역변수와 다른점은 메모리 해제가 안된다.
			
			** static은 한 번 실행되면 다음부터는 원래 있었던 변수처럼 실행되지 않는다.
			   컴파일러가 쭉 내려가면서 static은 한 번만나면 다음번에 만났을땐 처리하지 않음.


	*/

	static int mousePosX = 0;
	static int mousePosY = 0;
	static int value = 0;
	static int randNum = 0;
	static bool mouseClickCheck = false;

	static RECT rc = { 100, 100, 200, 200 };
	static int speed = 1;

	char s2Text[128] = "";
	char szText[128] = "";

	switch (iMessage)
	{
	case WM_KEYDOWN:
		switch (wparam) //무슨키가 눌렸는지를
		{

		case 'a':
		case 'A':
			rc.left -= speed;
			rc.right -= speed;

			break;

		case 'd':
		case 'D':
			rc.left += speed;
			rc.right += speed;

			break;	
		
		case 87:
			rc.top -= speed;
			rc.bottom -= speed;

			break;
		
		case 83:
			rc.top += speed;
			rc.bottom += speed;

			break;

		case VK_UP:
			speed++;
			break;

		case VK_DOWN:
			speed--;
			break;

		}
		InvalidateRect(g_hwnd, NULL, true); //Rect를 NULL로 하면 전체화면 지정, 화면을 다 지우고 다시 그릴지

		break;

	case WM_LBUTTONUP:
		mouseClickCheck = false;
		InvalidateRect(g_hwnd, NULL, true); //Rect를 NULL로 하면 전체화면 지정, 화면을 다 지우고 다시 그릴지

		break;

	case WM_LBUTTONDOWN:	//WM_LBUTTONDBLCLK:// //마우스 왼쪽버튼 눌렀을 때
		mousePosX = LOWORD(lparam); //((WORD)(((DWORD_PTR)(l)) & 0xffff))
		mousePosY = HIWORD(lparam);	//((WORD)((((DWORD_PTR)(l)) >> 16) & 0xffff))
		mouseClickCheck = true;

		//speed++;

		//((WORD)(((DWORD_PTR)(lparam)) & 0xffff)); //4바이트짜리 값으로 바꿔 => 32개의 비트 & 0xffff = 뒤에 있는 16개의 자리만 살리겠다. 그다음 WORD를 통해 4바이트를 2바이트로 바꾼다.
		//((WORD)((((DWORD_PTR)(lparam)) >> 16) & 0xffff)); // 32개 중, 앞에있는 것을 살리겠다. 쉬프트 연산자

		if(value < 8)
			value++;

		//누를때마다 발생하는 함수.
		InvalidateRect(g_hwnd, NULL, true); //Rect를 NULL로 하면 전체화면 지정, 화면을 다 지우고 다시 그릴지
		break;

	case WM_MOUSEMOVE:
		mousePosX = LOWORD(lparam); //((WORD)(((DWORD_PTR)(l)) & 0xffff))
		mousePosY = HIWORD(lparam);	//((WORD)((((DWORD_PTR)(l)) >> 16) & 0xffff))

		InvalidateRect(g_hwnd, NULL, true);
		break;

	case WM_RBUTTONDOWN: //마우스 오른쪽
		mousePosX = LOWORD(lparam);
		mousePosY = HIWORD(lparam);

		speed--;

		if (value >= 0)
			value--;

		InvalidateRect(g_hwnd, NULL, true); //Rect를 NULL로 하면 전체화면 지정, 화면을 다 지우고 다시 그릴지
		break;

	case WM_PAINT:		//윈도우 화면이 다시 그려지는 경우에 발생하는 메시지. 다른 창이 가렸다가 빠졌을 때 다시 그려지는것을 말함.
		hdc = BeginPaint(g_hwnd, &ps);

		//Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
		//Ellipse(hdc, 100, 100, 500, 200);
		
		//선 그리기 (선이 시작되는 좌표 ~ 어디까지 그린다로 구성해야됨)
		//MoveToEx(hdc, 200, 200, NULL);
		//LineTo(hdc, 400, 200); //여기에서 이어서 선을 그림
		//LineTo(hdc, 300, 314);
		//LineTo(hdc, 200, 200);
		 
		//RenderRect(hdc, mousePosX, mousePosY, 200, 130);
		//RenderRectToCenter(hdc, mousePosX, mousePosY, 200, 200);

		//실습 1. 별 그리는 함수를 만들고 마우스 클릭 위치에 별이 그려지도록 해보자.(별 크기는 랜덤하게 바뀐다.)
		randNum = rand() % 500 + 50;
		StartRender(hdc, mousePosX, mousePosY, randNum);

		//실습 2. 마우스 왼쪽 클릭 + 이동시 네모가 따라다니게 바꿔보자.
		//MoveRectangle(hdc, mousePosX, mousePosY, mouseClickCheck);

		//별그리기
		//LineTo(hdc, 60, 300);
		//LineTo(hdc, 240, 300);
		//LineTo(hdc, 100, 200);
		//LineTo(hdc, 150, 370);
		//LineTo(hdc, 200, 200);
			   		 
		TextOut(hdc, 10, 10, "Hello, WinMain!", 15);
		wsprintf(szText, "X : %d, Y : %d", mousePosX, mousePosY);
		TextOut(hdc, 300, 10, szText, strlen(szText));

		//wsprintf(szText, "Speed : %d", speed);
		//TextOut(hdc, 600, 10, szText, strlen(szText));

#pragma region 구구단
		// 실습.마우스 왼쪽 클릭을 한 번 할때마다 구구단 1단씩 출력,
		// 마우스 오른쪽 클릭을 한 번 할때마다 1단씩 감소.

		/*for (int j = 0; j < value; j++)
		{
			for (int i = 0; i < 9; i++)
			{
				if (j < 3)
				{
					wsprintf(s2Text, "%d * %d = %d", (2 + j), i + 1, (2 + j) * (i + 1));
					TextOut(hdc, 10 + ((j - 0) * 100), 30 + (i * 20), s2Text, strlen(s2Text));
				}
				else if (j < 6)
				{
					wsprintf(s2Text, "%d * %d = %d", (2 + j), i + 1, (2 + j) * (i + 1));
					TextOut(hdc, 10 + ((j - 3) * 100), 230 + (i * 20), s2Text, strlen(s2Text));
				}
				else
				{
					wsprintf(s2Text, "%d * %d = %d", (2 + j), i + 1, (2 + j) * (i + 1));
					TextOut(hdc, 10 + ((j - 6) * 100), 430 + (i * 20), s2Text, strlen(s2Text));
				}

			}
		}*/
#pragma endregion;

		EndPaint(g_hwnd, &ps);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hwnd, iMessage, wparam, lparam);
}

