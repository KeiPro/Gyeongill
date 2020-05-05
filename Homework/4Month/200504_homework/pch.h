#pragma once
#pragma comment(lib, "msimg32.lib")

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

#define WINSIZE_X	1215
#define WINSIZE_Y	717
#define WINSTART_X	100
#define WINSTART_Y	100

#define PI			3.141592
//#define ENEMYCOUNT 5

extern HWND g_hWnd;
extern HINSTANCE g_hInstance;

typedef struct tagFPOINT
{
	float x;
	float y;
}FPOINT;