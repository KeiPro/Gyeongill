#pragma once
#include "PCH.h"
/*

	파일 입출력
	1) 소스파일 외부에 데이터를 기록할 텍스트 파일을 생성 ( 출력 )
	2) 외부에 있는 텍스트 파일의 데이터를 읽어들인다. ( 입력 )

	3) 사용처
		3-1) 게임의 세이브 / 로드할 때
		3-2) 게임의 특정데이터를 소스 코드안에 넣지 않고 외부파일에서 불러오고 싶을 때( 몬스터 정보, 맵 정보, 아이템 정보, 상점 정보 등등... )

		코드 외부에서 게임의 데이터만 수정해서 게임의 내용을 추가 / 삭제 / 수정 할 수 있어야 한다.
			-> Data_Driven Development (데이터 중심의 개발 방식)


*/

class FileMgr
{
private:
	int*	numData;	//정수형 데이터 입력을 위한 배열 변수

public:
	void WriteFile(string fileName, int* arrName, int maxArrSize); //저장할 파일의 경로랑, 
	void ReadFile(string fileName);
	void InputData(); //데이터 입력 함수

	FileMgr();
	~FileMgr();


};

