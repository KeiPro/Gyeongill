#include <Windows.h>
#include <ctime>

HINSTANCE hInstance;
HWND g_hwnd;
LPSTR lpsz_Class = (LPSTR)TEXT("�� ���� ����");

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

// x, y : ���� ��ġ
// width, height : �ʺ�, ����
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



// centerX, centerY : �簢���� ����
// width, height : �ʺ�, ����
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
	// LPARAM lparam : ���콺 �̺�Ʈ�� ����ϴ� ��. lparam : ���콺 ��ǥ

	HDC hdc;	 //H : Handle - DC�� �ڵ�. DC(Device Context) ������â�� �ؽ�Ʈ�� ����ϰų� �׸��� �׸��ų� �ϴ� ���� �⺻���� ����.
	//hdc = GetDC(g_hwnd);

	//ReleaseDC(g_hwnd, hdc); //�޸� ����.
	PAINTSTRUCT ps;

	/*
		����
		1. �������� ( �Լ� ������ ���� ) 
			����Ǵ� �޸� ������ �ٸ���.  
			(Stack ����)
			�Լ��� ����Ǵ� �������� �ڵ����� �޸� ����.


		2. �������� ( �Լ� �ܺο��� ���� ) //���α׷� ���������� ������ �ȵȴ�.
			( ������ ���� )
			���α׷� ����ÿ� ����.


		3. static ����
			����Ǵ� �޸� ���� : (������ ����)
			�����Ǵ� ���� : ���α׷� ����ÿ� ����.
			�ش� ����(�Լ�)������ ������ �ȴ�. == ��������,�ٵ� ���������� �ٸ����� �޸� ������ �ȵȴ�.
			
			** static�� �� �� ����Ǹ� �������ʹ� ���� �־��� ����ó�� ������� �ʴ´�.
			   �����Ϸ��� �� �������鼭 static�� �� �������� �������� �������� ó������ ����.


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
		switch (wparam) //����Ű�� ���ȴ�����
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
		InvalidateRect(g_hwnd, NULL, true); //Rect�� NULL�� �ϸ� ��üȭ�� ����, ȭ���� �� ����� �ٽ� �׸���

		break;

	case WM_LBUTTONUP:
		mouseClickCheck = false;
		InvalidateRect(g_hwnd, NULL, true); //Rect�� NULL�� �ϸ� ��üȭ�� ����, ȭ���� �� ����� �ٽ� �׸���

		break;

	case WM_LBUTTONDOWN:	//WM_LBUTTONDBLCLK:// //���콺 ���ʹ�ư ������ ��
		mousePosX = LOWORD(lparam); //((WORD)(((DWORD_PTR)(l)) & 0xffff))
		mousePosY = HIWORD(lparam);	//((WORD)((((DWORD_PTR)(l)) >> 16) & 0xffff))
		mouseClickCheck = true;

		//speed++;

		//((WORD)(((DWORD_PTR)(lparam)) & 0xffff)); //4����Ʈ¥�� ������ �ٲ� => 32���� ��Ʈ & 0xffff = �ڿ� �ִ� 16���� �ڸ��� �츮�ڴ�. �״��� WORD�� ���� 4����Ʈ�� 2����Ʈ�� �ٲ۴�.
		//((WORD)((((DWORD_PTR)(lparam)) >> 16) & 0xffff)); // 32�� ��, �տ��ִ� ���� �츮�ڴ�. ����Ʈ ������

		if(value < 8)
			value++;

		//���������� �߻��ϴ� �Լ�.
		InvalidateRect(g_hwnd, NULL, true); //Rect�� NULL�� �ϸ� ��üȭ�� ����, ȭ���� �� ����� �ٽ� �׸���
		break;

	case WM_MOUSEMOVE:
		mousePosX = LOWORD(lparam); //((WORD)(((DWORD_PTR)(l)) & 0xffff))
		mousePosY = HIWORD(lparam);	//((WORD)((((DWORD_PTR)(l)) >> 16) & 0xffff))

		InvalidateRect(g_hwnd, NULL, true);
		break;

	case WM_RBUTTONDOWN: //���콺 ������
		mousePosX = LOWORD(lparam);
		mousePosY = HIWORD(lparam);

		speed--;

		if (value >= 0)
			value--;

		InvalidateRect(g_hwnd, NULL, true); //Rect�� NULL�� �ϸ� ��üȭ�� ����, ȭ���� �� ����� �ٽ� �׸���
		break;

	case WM_PAINT:		//������ ȭ���� �ٽ� �׷����� ��쿡 �߻��ϴ� �޽���. �ٸ� â�� ���ȴٰ� ������ �� �ٽ� �׷����°��� ����.
		hdc = BeginPaint(g_hwnd, &ps);

		//Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
		//Ellipse(hdc, 100, 100, 500, 200);
		
		//�� �׸��� (���� ���۵Ǵ� ��ǥ ~ ������ �׸��ٷ� �����ؾߵ�)
		//MoveToEx(hdc, 200, 200, NULL);
		//LineTo(hdc, 400, 200); //���⿡�� �̾ ���� �׸�
		//LineTo(hdc, 300, 314);
		//LineTo(hdc, 200, 200);
		 
		//RenderRect(hdc, mousePosX, mousePosY, 200, 130);
		//RenderRectToCenter(hdc, mousePosX, mousePosY, 200, 200);

		//�ǽ� 1. �� �׸��� �Լ��� ����� ���콺 Ŭ�� ��ġ�� ���� �׷������� �غ���.(�� ũ��� �����ϰ� �ٲ��.)
		randNum = rand() % 500 + 50;
		StartRender(hdc, mousePosX, mousePosY, randNum);

		//�ǽ� 2. ���콺 ���� Ŭ�� + �̵��� �׸� ����ٴϰ� �ٲ㺸��.
		//MoveRectangle(hdc, mousePosX, mousePosY, mouseClickCheck);

		//���׸���
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

#pragma region ������
		// �ǽ�.���콺 ���� Ŭ���� �� �� �Ҷ����� ������ 1�ܾ� ���,
		// ���콺 ������ Ŭ���� �� �� �Ҷ����� 1�ܾ� ����.

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

