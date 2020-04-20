// main.cpp

/*

	Win32 API
	: Application Programming Interface
	�ü���� �������α׷��� ���� �����ϴ� �Լ��� ����

	�ϵ���� ------------------�ü��(Windows)------------------ �������α׷�
							   	(API �Լ�)

	�ڵ�(Handle)
	�޽���(Message)
	 --> Win32���� � ���Ұ� ��� �۵��ϴ����� ���߿� �˾ƺ� ��.
*/

// ���ڸ� ǥ���ϴµ� �ʿ��� �����Ͱ� �ٲ𶧸��� ��Ƽ����Ʈ �����ڵ� �������� ������ �ٲ�.


#include <Windows.h> //�̰� �־�� Window API�� ����� �� �ִ�.

//��������
HINSTANCE g_hInstance; //�밡���� ǥ��� g : ��������, h(�ڵ�) : ������ Ÿ���� ��Ÿ�� ���ݺ��� ���� Instance�� �ڵ��̴�. ���α׷� �ν��Ͻ��� �ڵ�
						//HINSTANCE�� ������ int���̶�� ���� �� �� �ִ�.

HWND	  g_hWnd; //������ �ڵ�
LPSTR	  g_lpszClass = (LPSTR)TEXT("�������� ����");

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

//�Լ��� ȣ�� �Ǹ� �ڵ������� �����찡 �Ű������� �� �� ������ ù��°��~~~
//~~~������ ����ϴ� �ν��Ͻ� �ڵ鰪 �ٵ� ������ �Ⱦ� ���� ���α׷� Ȱ��ȭ�� ���ؼ� ���� �����͵�. 

// �����츦 �����ϱ� ���� �Լ�
int APIENTRY WinMain(HINSTANCE _hInstance, HINSTANCE _hPrevInstance,  
	LPSTR _lpszCmdParam, int nCmdShow)
{
	//������ ������ ���� �⺻ ����
	g_hInstance = _hInstance; //�ü���� �Ѱ��ִ� ����
	WNDCLASS wndClass; 
	wndClass.cbClsExtra = 0; //Ŭ������ ���� �޸� �׳� 0�� �־��ش�.
	wndClass.cbWndExtra = 0; //������ ���� �޸�
	wndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW); //Ŀ���� �ڵ�. ���콺Ŀ���� ������� ������ٰ���.
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hInstance = g_hInstance;
	wndClass.lpfnWndProc = WndProc; //�Լ� �̸��� �����Ͷ� �̷������� ����� �� �ִ�.
	wndClass.lpszClassName = g_lpszClass;
	wndClass.lpszMenuName = NULL;
	wndClass.style = CS_HREDRAW | CS_VREDRAW; //ũ�Ⱑ �ٲ𶧸��� ���� �׷��ְ�

	// ������ Ŭ������ ����ϴ� ����
	RegisterClass(&wndClass);

	//�����츦 ������ �����ϴ� ����
	g_hWnd = CreateWindow(g_lpszClass, g_lpszClass, WS_OVERLAPPEDWINDOW, 50, 50, 1200, 900, NULL, NULL, g_hInstance, NULL);

	//������ ���
	ShowWindow(g_hWnd, nCmdShow);

	//�޽��� ť�� �ִ� �޽��� ó��
	MSG message;//�޽��� ó���ϴ� ����ü 
	while (GetMessage(&message, 0, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	return message.wParam;
}

//� ���� �߻����� �� �ڵ����� �Լ��� ȣ�����ִ� ���� : CALLBACK
//if���� �ƴ϶� ������Ŭ������ ���� ������ָ� �ڵ����� ȣ�� ���ش�.
//������ �޽���(�̺�Ʈ)�� ó���ϴ� �Լ� //wparam : Ű �Է�, lparam : ���콺 �̺�Ʈ�� ����
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)//�Լ��� ó���ǰ� ���� ������ �ִ��� �������� �˷���. ������ �ڵ�, � �̺�Ʈ�� �߻��ߴ���
{
	switch (iMessage)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;


	}

	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}