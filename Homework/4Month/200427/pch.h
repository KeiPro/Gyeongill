#pragma once

#include <Windows.h>
#include <math.h>

// enum, struct, .h, #define
enum BOX
{
	BOX_First,
	BOX_Second,
	BOX_End
};

#define WINSIZE_X	600
#define WINSIZE_Y	900
#define WINSTART_X	50
#define WINSTART_Y	50

#define PI			3.141592

extern HWND g_hWnd;