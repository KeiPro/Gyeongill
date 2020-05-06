#pragma once

#include <Windows.h>
#include <math.h>
#include "KeyManager.h"
#include <ctime>

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
//#define ENEMYCOUNT 5

extern HWND g_hWnd;
extern HINSTANCE g_hInstance;

typedef struct tagFPOINT
{
	float x;
	float y;
}FPOINT;