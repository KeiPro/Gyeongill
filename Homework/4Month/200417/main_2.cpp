#include "PCH.h"
#include "FileMgr.h"

int main()
{
	FileMgr fm;
	//int testArray[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	//fm.WriteFile("TestData.txt", testArray, 10);

	fm.ReadFile("TestData.txt");
}