#include "Time.h"

void Time::Print()
{
	cout << hour << ":" << minute << endl;
}

void Time::InitTime(int hour, int minute)
{
	if (hour < 0 || hour > 23) return;
	if (minute < 0 || minute > 59) return;
	
	// this : ������
	// ���� �������� �Լ��� ȣ���� �ν��Ͻ��� �޸��ּ�
	cout << this << endl;
	(*this).hour = hour;		//��� ������ ������ ��ü�� �ڱ� �޸� ������ ���� ������ �ִ�. ��� �Լ��� ������ �Ѵ�. hour : ������ ��ü�� ������ �ִ� �޸� ���� 
	this->minute = minute;	
}

//this : a.InitTime()�� �ϸ� this�� a�� �޸� �ּҰ� �ȴ�.
//		 b.InitTime()�� �ϸ� this�� b�� �޸� �ּҰ� �ȴ�.