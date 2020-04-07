
/*
	기술문서(ppt)

	제목 : 용사는 절차적

		2. 목차

		간단한 게임 소개
		개발 환경
		순서도
		게임을 만들면서 어려웠던 점
		->이렇게 하고 싶었다.해보고 싶었더니 이런점이 어려워서 이렇게 해결했다.
		ppt로 만들고->pdf로 변환 후 숙제폴더에 오늘날짜로 업로드

		visual studio2017
		플랫폼 : Windows
		언어 : C++
*/

/*
	* 자료구조

	데이터를 효율적으로 관리하기 위해 사용하는 것.

	리스트에 대해서....

*/

//리스트 구현 맛보기


#include <iostream>

// 노드 node ( 값(Data) + 주소(다음 노드의 메모리 주소) )

using namespace std;

struct Node
{
	int data;
	Node* next; //다음 노드의 주소를 담을 수 있는 포인터
};



int main()
{
	//int test[3][4][5]; //3개짜리의 배열이 2개씩 하나 있다.

	//int*** test = new int**[3];

	//test[0] = new int*[4];
	//test[1] = new int*[4];
	//test[2] = new int*[4];
	//
	//for (int i = 0; i < 3; i++)
	//{
	//	test[i] = new int*[4];
	//}

	//for (int i = 0; i < 3; i++)
	//{
	//	test[i] = new int*[4];

	//	for (int j = 0; j < 4; j++)
	//	{
	//		test[i][j] = new int[5];
	//	}
	//}

	//for (int i = 0; i < 3; i++)
	//{
	//	for (int j = 0; j < 4; j++)
	//	{
	//		delete[] test[i][j];
	//	}

	//	delete[] test[i];
	//}

	//delete[] test;


	//리스트는 데이터 1개가 있을 때마다 메모리 공간 1개씩 추가 된다.
	//Heap메모리에 int데이터 하나 저장하는거랑 다음 노드를 저장할 수 있는 공간 하나가 생성.
	
	// 그림을 그려보기..
	// Node가 현재 세개가 저장되어있는데 이 세개의 값을 하나 씩 출력해볼 수 있게 만들어보기.
	// 기술문서.


	Node* head = new Node; 
	(*head).data = 0;
	(*head).next = nullptr;

	//값을 하나 더 넣는다.
	Node* newNode = new Node;
	newNode->data = 1;
	newNode->next = nullptr;
	
	head->next = newNode; //두 노드를 연결한다.

	newNode = new Node;
	newNode->data = 10;
	newNode->next = nullptr;

	head->next->next = newNode;

	newNode = new Node;
	newNode->data = 20;
	newNode->next = nullptr;

	head->next->next->next = newNode;

	Node* p = head;

	while (p != nullptr)
	{
		cout << p->data << " ";
		p = p->next;
	}

	cout << endl;

	cout << head->data << endl;
	cout << head->next->data << endl;
	cout << head->next->next->data << endl;
	cout << head->next->next->next->data << endl;


	return 0;
}