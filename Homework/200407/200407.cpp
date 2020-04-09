/*
	* 자료구조

	데이터를 효율적으로 관리하기 위해 사용하는 것.

	// 노드 node ( 값(Data) + 주소(다음 노드의 메모리 주소) )

*/

#include <iostream>



using namespace std;

struct Node
{
	int data;
	Node* next; //다음 노드의 주소를 담을 수 있는 포인터
};


int main()
{

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


	/*
		출력하는 방법1
	*/


	cout << head->data << endl;
	cout << head->next->data << endl;
	cout << head->next->next->data << endl;

	/*
		출력하는 방법2
	*/
	Node* p = head;

	while (p != nullptr)
	{
		cout << p->data << " ";
		p = p->next;
	}

	cout << endl;


	cout << head->next->next->next->data << endl;


	return 0;
}