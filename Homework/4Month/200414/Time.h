#pragma once
#include <iostream>

using namespace std;

class Time
{
		//멤버 변수
public:
	int hour;	// 시를 나타낸다. 0 ~ 23
	int minute;	// 분을 나타낸다. 0 ~ 59

	//멤버 함수 (원형)
	void Print();
	void InitTime(int hour, int minute);
	
};


