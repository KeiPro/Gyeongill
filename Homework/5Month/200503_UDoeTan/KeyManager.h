#pragma once
#include "SingletonBase.h"
#include <bitset>
#include "pch.h"

using namespace std;

#define KEY_MAX_COUNT	128

//만들려고 하는 클래스의 명으로 타입을 정한다.
class KeyManager : public SingletonBase<KeyManager>
{
private:
	int arr[10];
	bitset<KEY_MAX_COUNT>	keyUp; //bitset은 한 공간이 0아니면 1로 구성되어있고, 공간의 크기는 안에 들어간 숫자 256개로 잡고 이름은 keyUp으로 한다.
									//256개의 공간에 0과 1로만으로 이루어진 비트를 저장하고 싶을 때 사용됨

	bitset<KEY_MAX_COUNT>	keyDown;



public:
	HRESULT Init();
	void Release();

	bool IsOnceKeyDown(int key);	// 키를 한 번 눌렀을 때
	bool IsOnceKeyUp(int key);		// 키를 눌렀다 뗐을 때
	bool IsStayKeyDown(int key);	// 키를 누르고 있을 때

	bitset<KEY_MAX_COUNT> GetKeyUp() { return keyUp; }
	bitset<KEY_MAX_COUNT> GetKeyDown() { return keyDown; }

	void SetKeyUp(int key, bool state) { keyUp.set(key, state); }
	void SetKeyDown(int key, bool state) { keyDown.set(key, state); }

	KeyManager();
	~KeyManager();
	
};
