#include "FileMgr.h"

void FileMgr::WriteFile(string fileName, int* arrName, int maxArrSize)
{
	ofstream fout; //output�� ����ϴ� ��ü output���Ͻ�Ʈ��
	fout.open(fileName); //�ش� ��ο� �ִ� ������ �����ش�. ���⼭�� ���¿뵵�� �� �� �ִ�.

	//���� ���๮
	for (int i = 0; i < maxArrSize; i++)
	{
		if(i < maxArrSize-1)
		{ 
			fout << arrName[i] << ", ";
		}
		else
		{
			fout << arrName[i]; //���Ͽ� ���� �Ѵ�.
		}

	}

	fout.close();
}

void FileMgr::ReadFile(string fileName)
{
	ifstream fin;
	fin.open(fileName);
	char separate;
	//�����ϴ� �������� ��Ŀ� ���� �о���� �����Ͱ� �޶��� �� �ִ�.

	//�о���� ���๮
	for (int i = 0; i < 10; i++)
	{
		fin >> numData[i];
		fin >> separate;
	}

	fin.close();

	for (int i = 0; i < 10; i++)
	{
		cout << numData[i] << " ";
	}
	cout << endl;
}

void FileMgr::InputData()
{
}

FileMgr::FileMgr()
{
	numData = new int[10];
}

FileMgr::~FileMgr()
{
	delete[] numData;
}
