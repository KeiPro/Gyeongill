#pragma once
#include "PCH.h"
/*

	���� �����
	1) �ҽ����� �ܺο� �����͸� ����� �ؽ�Ʈ ������ ���� ( ��� )
	2) �ܺο� �ִ� �ؽ�Ʈ ������ �����͸� �о���δ�. ( �Է� )

	3) ���ó
		3-1) ������ ���̺� / �ε��� ��
		3-2) ������ Ư�������͸� �ҽ� �ڵ�ȿ� ���� �ʰ� �ܺ����Ͽ��� �ҷ����� ���� ��( ���� ����, �� ����, ������ ����, ���� ���� ���... )

		�ڵ� �ܺο��� ������ �����͸� �����ؼ� ������ ������ �߰� / ���� / ���� �� �� �־�� �Ѵ�.
			-> Data_Driven Development (������ �߽��� ���� ���)


*/

class FileMgr
{
private:
	int*	numData;	//������ ������ �Է��� ���� �迭 ����

public:
	void WriteFile(string fileName, int* arrName, int maxArrSize); //������ ������ ��ζ�, 
	void ReadFile(string fileName);
	void InputData(); //������ �Է� �Լ�

	FileMgr();
	~FileMgr();


};

