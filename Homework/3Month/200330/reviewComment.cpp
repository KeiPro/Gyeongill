/*
�˰������� �����ϴ� �ܰ�
	1. �䱸������ �ڿ���� �Ẹ�� ��.
	2. ������ �Ǵ� Flow Chart
	3. �ǻ��ڵ� �ۼ�
*/

/*
	C++ ���α׷��� �� ������ �ִ� ǥ���� Ư�� 
	1) CPP�� ��/�ҹ��ڸ� ��Ȯ�ϰ� �����Ѵ�.
	main, Main, mAIN

	2) CPP�� ����� ��Ҹ� �����Ѵ�.
	inta=3(x)	int a = 3(o)

	3) ���๮�� ���� ;(�����ݷ�)���� �������Ѵ�.
	int a = 3; int b = 5;

	��� C++���α׷��� �ּ� 1���� main�Լ��� ������.
	C++ ���α׷��� ����ȴٴ� ���� main�Լ����� ������ ����ȴٴ� ���̴�.
	main�Լ��� �����Ű�� ���ؼ��� �ҽ����α׷� => (�����ϰ� ��ũ�� ���� => exe���� ����(exe ����)��Ŵ.
	��Ÿ��(����ð�)
*/

#include "pch.h" //���α׷��Ӱ� ���� ������� �� �̷������� ǥ��.
#include <iostream>
#include <string>

/*
	#include�� �̿��ؼ� �ٸ� �ҽ������� ������ �ҷ��� �� �ִ�.
	iostream = input output stream
	#include "���ϸ�.h" <- C���̺귯�� ������ ���Խ�Ű�ų� �츮�� ���� �ҽ������� ���Խ�ų �� �����ϴ� ���.
	#include <���ϸ�> <- CPP ���̺귯�� ������ ���Խ�ų ��.
	#include�� �ҽ������� ���� ������ ��ġ�ؾ� �Ѵ�.
*/

/*
	-�⺻���� ������� = ������ �Ʒ���
	-��������� ��Ʈ�� = ����� (�ݺ���, ���ǹ�)

	-�Է��� �Ϸ��� �Է¹��� �����͸� ������ ������ �ʿ��ϴ�. -> memory
	-cin : �Է��� ���� �� ����ϴ� ���ɾ�
	-���� : ���� ������ �� �ִ� �޸� ������ �ٿ��� �̸�
	-1) �̸�  2) ��  3) �޸��� �ּ�  4) ũ��(������ Ÿ��)
	-int age = 15;

		->������ Ÿ���� ������ ������ '����'�Ѵ�.
		  �޸� ������ ����ִ� ���� ���� �ּҸ� ã�Ƽ� 4����Ʈ ũ���� ������ �����͸�
		  ������ ������ age��� �̸����� �����Ѵ�.
*/

/*
	������ �̸� ��Ģ
	1) C++���� ����ϴ� Ű����(keyword)���� ���� �̸����� ����� �� ����.
		ex) int int; double double;

	2) ���ĺ�, ����, _�θ� ������ �� �ִ�.
	3) ��ҹ��� ���� myAge, myage�� �ٸ���.
	4) ������ �̸��� ���ڷ� ������ �� ����. 1num(x), _2num(o)
	5) �̸� ���̿� ���⸦ ���� �� ����. C++������ ����� ��Ҹ� �����ϱ� ������ �׷���.
		ex) my age(x) -> myAge �Ǵ� my_age �� ǥ��.

	������ Ÿ�� = ������ ������ �������� ���¸� �ڷ����̶�� �Ѵ�.
	������ Ÿ�� = ������, �Ǽ���, ������, ���ڿ�, Boolean��

	1) ������
	���� Ÿ�Ը�		ũ��(byte)		����
	int					4		-21�� ~ +21��
	long long			8
	short				2		-32768 ~ +32767
	__int8				1
	__int16				2
	__int32				4
	__int64				8

	unsigned ���ξ �ٿ��� ��� ���·θ� �� �� �ִ�.

	2) �Ǽ��� ����(�ε��Ҽ��� �Ǽ�)
	float				4 
	double				8

	3) ������ ����
	char				1		1���� ���ڸ� ǥ���Ѵ�. �ѱ� ��, ��, ��, ��� �ּ� 2����Ʈ�� ǥ��.
	
	4) ���ڿ� ����
	string				8		���ڿ��� �� ũ�� + 1 (��null ����)

	5) Boolean�� ����
	bool				1		���� 0/1(false/true)

	�ڷ����̳� ������ ũ��� sizeof()�����ڸ� ���ؼ� ������ �� �ִ�.
*/

/*
	�ڵ��� �� �� �켱 �����ؾ� �� ��
	1) ������ Ÿ�� : �޸𸮸� ��� ����� ���ΰ�?
	2) ������ : 1)���� �����͵��� ��� ����� ���ΰ�?
	3) ���� ���� : � ������ ���� ���๮���� ������ΰ�?

	int num = 10;
	//�̸� : num, �� : 10, ũ�� : 4 �޸��ּ� : &num
*/

/*
	�����?
		�޸� ������ ����Ǿ� ������ ������ �Ұ����� �����͸� ������ �Ѵ�.
		� ����� ������ ���� �̸��� ���� ���� �ִ�.
		����� ������ ���� const��� Ű���带 ����Ѵ�.

		const int A = 500;
*/

/*
	������ �̸��� ���� ���� : �ڵ��� �������� ���̱� ���� ���.
	1) �鿩���⸦ ��Ȯ�ϰ� Ȱ������.
	2) ������ ����� �ʱ�ȭ�� �ִ��� �ڵ� ������ �� �տ� ��Ƴ���.
	3) ����, �Լ� ���̹� ��Ģ�� ��������.
	- �밡���� ǥ���
			������ �տ� ���� Ÿ���� ǥ���ϴ� �� ���δ�.
				ex) int nPlayerCount;
					float fMyWeight;
					������, �� ������ �ʴ� ���.
	- ī�� ǥ���
			a) ������ �� �ܾ� �̻����� �����Ѵ�.
			ù ��° �ܾ�� �ҹ��ڷ� �� ��° �ܾ�� �빮�ڷ� �����Ѵ�.
			int playerCount;
			float myWeight;
			bool isAlive;
			bool ������ ����+����, ����+�����, �����+���� ���·� �����Ѵ�.
			isAlive, hasHair, isPretty, eatMeal

			b) ����� ������ �빮�ڷ� �����ϸ� �� �ܾ� �̻����� ����
			const int MAX_HP = 100;
			const double MAX_SPEED = 5.3;

			c) �Լ�, ����ü, Ŭ���� ���� ù �ܾ��� ù ���ڸ� �빮�ڷ� ǥ���Ѵ�.
			int GetTime(); //�ð��� ������ �Լ�.
*/