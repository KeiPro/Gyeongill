#include "FileMgr.h"

void FileMgr::WriteFile(string fileName, int* arrName, int maxArrSize)
{
	ofstream fout; //output을 담당하는 객체 output파일스트림
	fout.open(fileName); //해당 경로에 있는 파일을 열어준다. 여기서는 쓰는용도로 열 수 있다.

	//쓰는 실행문
	for (int i = 0; i < maxArrSize; i++)
	{
		if(i < maxArrSize-1)
		{ 
			fout << arrName[i] << ", ";
		}
		else
		{
			fout << arrName[i]; //파일에 쓰게 한다.
		}

	}

	fout.close();
}

void FileMgr::ReadFile(string fileName)
{
	ifstream fin;
	fin.open(fileName);
	char separate;
	//저장하는 데이터의 양식에 따라 읽어오는 데이터가 달라질 수 있다.

	//읽어오는 실행문
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
