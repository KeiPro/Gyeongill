// main.cpp

/*

	Win32 API
	: Application Programming Interface
	운영체제가 응용프로그램을 위해 제공하는 함수의 집합

	하드웨어 ------------------운영체제(Windows)------------------ 응용프로그램
							   	(API 함수)

	핸들(Handle)
	메시지(Message)
	 --> Win32에서 어떤 역할과 어떻게 작동하는지는 나중에 알아볼 것.
*/

// 문자를 표현하는데 필요한 데이터가 바뀔때마다 멀티바이트 유니코드 문자집합 형식이 바뀜.


#include <Windows.h> //이게 있어야 Window API를 사용할 수 있다.

//전역변수
HINSTANCE g_hInstance; //헝가리안 표기법 g : 전역변수, h(핸들) : 데이터 타입을 나타냄 지금부터 만들 Instance의 핸들이다. 프로그램 인스턴스용 핸들
						//HINSTANCE는 들어가보면 int형이라는 것을 알 수 있다.

HWND	  g_hWnd; //윈도우 핸들
LPSTR	  g_lpszClass = (LPSTR)TEXT("윈메인의 시작");

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

//함수가 호출 되면 자동적으로 윈도우가 매개변수를 몇 개 던져줌 첫번째가~~~
//~~~이전에 사용하던 인스턴스 핸들값 근데 지금은 안씀 단지 프로그램 활성화를 위해서 쓰임 다음것도. 

// 윈도우를 생성하기 위한 함수
int APIENTRY WinMain(HINSTANCE _hInstance, HINSTANCE _hPrevInstance,  
	LPSTR _lpszCmdParam, int nCmdShow)
{
	//윈도우 생성을 위한 기본 세팅
	g_hInstance = _hInstance; //운영체제가 넘겨주는 변수
	WNDCLASS wndClass; 
	wndClass.cbClsExtra = 0; //클래스의 여분 메모리 그냥 0을 넣어준다.
	wndClass.cbWndExtra = 0; //윈도우 여분 메모리
	wndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW); //커서의 핸들. 마우스커서의 모양으로 만들어줄것임.
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hInstance = g_hInstance;
	wndClass.lpfnWndProc = WndProc; //함수 이름이 포인터라 이런식으로 등록할 수 있다.
	wndClass.lpszClassName = g_lpszClass;
	wndClass.lpszMenuName = NULL;
	wndClass.style = CS_HREDRAW | CS_VREDRAW; //크기가 바뀔때마다 새로 그려주게

	// 윈도우 클래스를 등록하는 과정
	RegisterClass(&wndClass);

	//윈도우를 실제로 생성하는 과정
	g_hWnd = CreateWindow(g_lpszClass, g_lpszClass, WS_OVERLAPPEDWINDOW, 50, 50, 1200, 900, NULL, NULL, g_hInstance, NULL);

	//윈도우 출력
	ShowWindow(g_hWnd, nCmdShow);

	//메시지 큐에 있는 메시지 처리
	MSG message;//메시지 처리하는 구조체 
	while (GetMessage(&message, 0, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	return message.wParam;
}

//어떤 일이 발생했을 때 자동으로 함수를 호출해주는 형태 : CALLBACK
//if문이 아니라 윈도우클래스를 통해 등록해주면 자동으로 호출 해준다.
//윈도우 메시지(이벤트)를 처리하는 함수 //wparam : 키 입력, lparam : 마우스 이벤트에 대한
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)//함수가 처리되고 나서 오류가 있는지 없는지를 알려줌. 윈도우 핸들, 어떤 이벤트가 발생했는지
{
	switch (iMessage)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;


	}

	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}