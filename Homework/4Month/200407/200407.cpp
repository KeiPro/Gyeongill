/*
	* �ڷᱸ��

	�����͸� ȿ�������� �����ϱ� ���� ����ϴ� ��.

	// ��� node ( ��(Data) + �ּ�(���� ����� �޸� �ּ�) )

*/

#include <iostream>



using namespace std;

struct Node
{
	int data;
	Node* next; //���� ����� �ּҸ� ���� �� �ִ� ������
};


int main()
{

	//����Ʈ�� ������ 1���� ���� ������ �޸� ���� 1���� �߰� �ȴ�.
	//Heap�޸𸮿� int������ �ϳ� �����ϴ°Ŷ� ���� ��带 ������ �� �ִ� ���� �ϳ��� ����.
	
	// �׸��� �׷�����..
	// Node�� ���� ������ ����Ǿ��ִµ� �� ������ ���� �ϳ� �� ����غ� �� �ְ� ������.
	// �������.

	Node* head = new Node; 
	(*head).data = 0;
	(*head).next = nullptr;

	//���� �ϳ� �� �ִ´�.
	Node* newNode = new Node;
	newNode->data = 1;
	newNode->next = nullptr;
	
	head->next = newNode; //�� ��带 �����Ѵ�.

	newNode = new Node;
	newNode->data = 10;
	newNode->next = nullptr;

	head->next->next = newNode;

	newNode = new Node;
	newNode->data = 20;
	newNode->next = nullptr;

	head->next->next->next = newNode;


	/*
		����ϴ� ���1
	*/


	cout << head->data << endl;
	cout << head->next->data << endl;
	cout << head->next->next->data << endl;

	/*
		����ϴ� ���2
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