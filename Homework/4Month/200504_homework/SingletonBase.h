#pragma once


template<typename T> //여러가지 데이터 타입이들어오면 그 데이터 타입으로 포인터를 만들어서 동적할당을 할 수 있게...
class SingletonBase
{
protected:
	static T* instance; //데이터 영역에 존재하도록 static keyword추가.
	SingletonBase() {};
	~SingletonBase() {};

public:

	//위에가 static멤버 변수이기 때문에 이것도 static으로 표현해줘야됨.
	static T* GetSingleton();	// instance를 외부에 노출
	void ReleaseSingleton();		// 메모리 할당된 instance 해제

};

// 싱글톤 초기화. instance의 초기화 위치는 멤버 변수가 아니라 class바깥이다.
// static 변수 문법상 {} '영역 밖에서 초기화'한다.
template <typename T>
T* SingletonBase<T>::instance = 0; // SingletonBase<T>:: 

template <typename T>
T* SingletonBase<T>::GetSingleton()
{
	//if (instance) //미리 할당 되어 있으면
	//{
	//	return instance;
	//}
	//else
	//{
	//	instance = new T;
	//	return instance;
	//}

	//없을 때만 할당하고
	if (!instance)
	{
		instance = new T;	// 0x00001
	}

	return instance;
}

template<typename T>
void SingletonBase<T>::ReleaseSingleton()
{
	//메모리 해제가 안 됐을때만 해제 해주는걸로 if문을 사용한다.
	if (instance) {
		delete instance;	// 0x00001 그대로 들어가있다. 주소에 들어가서 메모리는 해제됐지만 변수는 값이 바뀌지 않는다. =, ++, --이런 연산자를 써야 값이 바뀐다.
		instance = 0;	    // 0x00000
	}
}