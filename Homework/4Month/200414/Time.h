#pragma once
#include <iostream>

using namespace std;

class Time
{
		//��� ����
public:
	int hour;	// �ø� ��Ÿ����. 0 ~ 23
	int minute;	// ���� ��Ÿ����. 0 ~ 59

	//��� �Լ� (����)
	void Print();
	void InitTime(int hour, int minute);
	
};


