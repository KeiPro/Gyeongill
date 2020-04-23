// main.cpp

/*
	Win32 API
	: Application Programing Interface
	�ü���� �������α׷��� ���� �����ϴ� �Լ��� ����

	�ϵ���� ----------�ü��(Windows)-------- �������α׷�
						(API �Լ�)

	�ڵ�(Handle)
	�޽���(Message)
*/

#include <Windows.h>
#include <ctime>

// ��������
HINSTANCE	g_hInstance;	// ���α׷� �ν��Ͻ� �ڵ�
HWND		g_hWnd;			// ������ �ڵ�
LPSTR		g_lpszClass = (LPSTR)TEXT("�������� ����");

enum BOX
{
	BOX_First, BOX_Second, BOX_End
};

BOX currentBox;
BOX nextBox;
RECT rc[BOX_End], rcIn;

int GetMin(int num1, int num2)
{
	if (num1 < num2)
		return num1;

	return num2;
}

int GetMax(int num1, int num2)
{
	if (num1 > num2)
		return num1;

	return num2;
}



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

bool Collider(RECT rc1, RECT rc2)
{
	if (!((rc1.right < rc2.left) || (rc1.bottom < rc2.top) || (rc1.left > rc2.right) || (rc1.top > rc2.bottom )))
	{
		return true;
	}
	return false;
}

RECT GetRectToCenter(int x, int y, int width, int height)
{
	RECT rc = { x - (width / 2), y - (height / 2),
		x + (width / 2), y + (height / 2) };
	return rc;
}

void Init()
{
	currentBox = BOX_First;
	nextBox = BOX_Second;
	// ū ���� �ʱ�ȭ
	for (int i = 0; i < BOX_End; i++)
	{
		rc[i] = GetRectToCenter(100 + i * 300, 100, 150, 150);
	}

	// ���� ���� �ʱ�ȭ
	rcIn = GetRectToCenter(110, 120, 50, 50);
}

void RenderRect(HDC hdc, int x, int y, int size)
{
	MoveToEx(hdc, x, y, NULL);
	LineTo(hdc, x + size, y);
	LineTo(hdc, x + size, y + size);
	LineTo(hdc, x, y + size);
	LineTo(hdc, x, y);
	//Rectangle(hdc, x, y, x + size, y + size);
}

// centerX, centerY : �簢���� ����
// width, height : �ʺ�, ����
void RenderRectToCenter(HDC hdc, int centerX, int centerY,
	int width, int height)
{
	Rectangle(hdc, centerX - (width / 2), centerY - (height / 2),
		centerX + (width / 2), centerY + (height / 2));
}

void CollisionChange(HDC hdc, RECT rc[], bool* vector, int* r, int* g, int* b, int* solidColor)
{
	if (rc[BOX_Second].left + 150 >= 1200)
	{
		*r = rand() % 255; *g = rand() % 255; *b = rand() % 255; 
		*solidColor = rand() % 255;
		*vector = false;
	}
	else if (rc[BOX_Second].left <= 0)
	{
		*r = rand() % 255;	*g = rand() % 255;	*b = rand() % 255;
		*solidColor = rand() % 255;
		*vector = true;
	}
}

RECT GetRect(int centerX, int centerY,
	int size)
{
	RECT rc{ centerX, centerY,centerX + size, centerY + size };

	return rc;
}

void Go(RECT* rc)
{
	rc[BOX_Second].left++;
}

// ������ �޽���(�̺�Ʈ)�� ó���ϴ� �Լ�
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage,
	WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	char szText[128] = "";
	static bool vector = true;
	static int solidColor = rand() % 255;

	//�׷��� ���� ������ �ٲ۴�.
	HPEN hPen, hOldPen;

	//������ ���θ� ä�� �� ����Ѵ�.
	HBRUSH hBrush, hOldBrush;

	static int r = rand()%255, g = rand() % 255, b = rand() % 255;

	//static RECT rc[10];

	// Ÿ�̸� ��ü�� �����ϴ� �ڵ�
	static HANDLE hTimer;

	switch (iMessage)
	{
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_LEFT: 

			//���� ���ڰ� ����ִ� ū ���ڸ� �����δ�.
			rc[currentBox].left -= 5;
			rc[currentBox] = GetRect(rc[currentBox].left, rc[currentBox].top, 150);

			if (rcIn.right > rc[currentBox].right)
			{
				rcIn.left = rc[currentBox].right - 50;
				rcIn = GetRect(rcIn.left, rcIn.top, 50);
			}

			break;

		case VK_RIGHT:

			rc[currentBox].left += 5;
			rc[currentBox] = GetRect(rc[currentBox].left, rc[currentBox].top, 150);

			//� ��쿡 ���� ������ ��ġ�� �ٲ�°�?
			if (rcIn.left < rc[currentBox].left)
			{
				rcIn.left = rc[currentBox].left;
				rcIn = GetRect(rcIn.left, rcIn.top, 50);
			}
			
			break;

		case VK_UP:

			rc[currentBox].top -= 5;
			rc[currentBox] = GetRect(rc[currentBox].left, rc[currentBox].top, 150);

			if (rcIn.bottom > rc[currentBox].bottom)
			{
				rcIn.top = rc[currentBox].bottom - 50;
				rcIn = GetRect(rcIn.left, rcIn.top, 50);
			}

			break;

		case VK_DOWN:

			//���� ���ڰ� ����ִ� ū ���ڸ� �����δ�.
			rc[currentBox].top += 5;
			rc[currentBox] = GetRect(rc[currentBox].left, rc[currentBox].top, 150);

			if (rcIn.top < rc[currentBox].top)
			{
				rcIn.top = rc[currentBox].top;
				rcIn = GetRect(rcIn.left, rcIn.top, 50);
			}

			break;

		case VK_ESCAPE:
			break;
		}

		if (CheckRectCollistion(rc[BOX_First], rc[BOX_Second]))
		{
			// �浹�� �߻� ���� ��
			// 1) ���� ���ڸ� �ű��.
			// 2) �����̴� ������� �ѱ��.
			currentBox = (BOX)((currentBox + 1) % BOX_End);

			int setX = rc[currentBox].left + 150 / 2 - 50 / 2;
			int setY = rc[currentBox].top + 50;

			rcIn = GetRect(setX, setY, 50);
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
		if (vector)
		{
			rc[BOX_Second].left += 3;
			rc[BOX_Second].right += 3;
		}
		else
		{
			rc[BOX_Second].left -= 3;
			rc[BOX_Second].right -= 3;
		}
		
		InvalidateRect(g_hWnd, NULL, true); //ȭ�� ����.
		break;
		
	case WM_PAINT:		// ������ ȭ���� �ٽ� �׷����� ��쿡 �߻��ϴ� �޽���
		hdc = BeginPaint(g_hWnd, &ps);		

		CollisionChange(hdc, rc, &vector, &r, &g, &b, &solidColor);

		hPen = CreatePen(PS_SOLID, 1, RGB(r, g, b)); //ps : pen style
		hOldPen = (HPEN)SelectObject(hdc, hPen);

		hBrush = CreateSolidBrush(RGB(r,g,b));
		hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);

		Rectangle(hdc, rc[BOX_Second].left, rc[BOX_Second].top, rc[BOX_Second].right, rc[BOX_Second].bottom);

		//RenderRect(hdc, rc[BOX_Second].left, rc[BOX_Second].top, 150);
		DeleteObject(hBrush);

		SelectObject(hdc, hOldPen);
		DeleteObject(hPen);

		wsprintf(szText, "%d, %d, %d ", r, g, b);
		TextOut(hdc, 200, 200, szText, strlen(szText));

		EndPaint(g_hWnd, &ps);
		break;
	case WM_DESTROY:
		KillTimer(g_hWnd, 1);

		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}