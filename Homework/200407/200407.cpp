
/*
	�������(ppt)

	���� : ���� ������

		2. ����

		������ ���� �Ұ�
		���� ȯ��
		������
		������ ����鼭 ������� ��
		->�̷��� �ϰ� �;���.�غ��� �;����� �̷����� ������� �̷��� �ذ��ߴ�.
		ppt�� �����->pdf�� ��ȯ �� ���������� ���ó�¥�� ���ε�

		visual studio2017
		�÷��� : Windows
		��� : C++
*/

/*
	* �ڷᱸ��

	�����͸� ȿ�������� �����ϱ� ���� ����ϴ� ��.

	����Ʈ�� ���ؼ�....

*/

//����Ʈ ���� ������


#include <iostream>

// ��� node ( ��(Data) + �ּ�(���� ����� �޸� �ּ�) )

using namespace std;

struct Node
{
	int data;
	Node* next; //���� ����� �ּҸ� ���� �� �ִ� ������
};



int main()
{
	//int test[3][4][5]; //3��¥���� �迭�� 2���� �ϳ� �ִ�.

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