#include "Time.h"

void Time::Print()
{
	cout << hour << ":" << minute << endl;
}

void Time::InitTime(int hour, int minute)
{
	if (hour < 0 || hour > 23) return;
	if (minute < 0 || minute > 59) return;
	
	// this : 포인터
	// 현재 실행중인 함수를 호출한 인스턴스의 메모리주소
	cout << this << endl;
	(*this).hour = hour;		//멤버 변수는 각각의 객체가 자기 메모리 공간을 따로 가지고 있다. 멤버 함수는 공유를 한다. hour : 각각의 객체가 가지고 있는 메모리 공간 
	this->minute = minute;	
}

//this : a.InitTime()을 하면 this는 a의 메모리 주소가 된다.
//		 b.InitTime()을 하면 this는 b의 메모리 주소가 된다.