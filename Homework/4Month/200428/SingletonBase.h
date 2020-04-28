#pragma once


template<typename T> //�������� ������ Ÿ���̵����� �� ������ Ÿ������ �����͸� ���� �����Ҵ��� �� �� �ְ�...
class SingletonBase
{
protected:
	static T* instance; //������ ������ �����ϵ��� static keyword�߰�.
	SingletonBase() {};
	~SingletonBase() {};

public:

	//������ static��� �����̱� ������ �̰͵� static���� ǥ������ߵ�.
	static T* GetSingleton();	// instance�� �ܺο� ����
	void ReleaseSingleton();		// �޸� �Ҵ�� instance ����

};

// �̱��� �ʱ�ȭ. instance�� �ʱ�ȭ ��ġ�� ��� ������ �ƴ϶� class�ٱ��̴�.
// static ���� ������ {} '���� �ۿ��� �ʱ�ȭ'�Ѵ�.
template <typename T>
T* SingletonBase<T>::instance = 0; // SingletonBase<T>:: 

template <typename T>
T* SingletonBase<T>::GetSingleton()
{
	//if (instance) //�̸� �Ҵ� �Ǿ� ������
	//{
	//	return instance;
	//}
	//else
	//{
	//	instance = new T;
	//	return instance;
	//}

	//���� ���� �Ҵ��ϰ�
	if (!instance)
	{
		instance = new T;	// 0x00001
	}

	return instance;
}

template<typename T>
void SingletonBase<T>::ReleaseSingleton()
{
	//�޸� ������ �� �������� ���� ���ִ°ɷ� if���� ����Ѵ�.
	if (instance) {
		delete instance;	// 0x00001 �״�� ���ִ�. �ּҿ� ���� �޸𸮴� ���������� ������ ���� �ٲ��� �ʴ´�. =, ++, --�̷� �����ڸ� ��� ���� �ٲ��.
		instance = 0;	    // 0x00000
	}
}