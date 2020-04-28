#pragma once
#include "SingletonBase.h"
#include <bitset>
#include "pch.h"

using namespace std;

#define KEY_MAX_COUNT	128

//������� �ϴ� Ŭ������ ������ Ÿ���� ���Ѵ�.
class KeyManager : public SingletonBase<KeyManager>
{
private:
	int arr[10];
	bitset<KEY_MAX_COUNT>	keyUp; //bitset�� �� ������ 0�ƴϸ� 1�� �����Ǿ��ְ�, ������ ũ��� �ȿ� �� ���� 256���� ��� �̸��� keyUp���� �Ѵ�.
									//256���� ������ 0�� 1�θ����� �̷���� ��Ʈ�� �����ϰ� ���� �� ����

	bitset<KEY_MAX_COUNT>	keyDown;



public:
	HRESULT Init();
	void Release();

	bool IsOnceKeyDown(int key);	// Ű�� �� �� ������ ��
	bool IsOnceKeyUp(int key);		// Ű�� ������ ���� ��
	bool IsStayKeyDown(int key);	// Ű�� ������ ���� ��

	bitset<KEY_MAX_COUNT> GetKeyUp() { return keyUp; }
	bitset<KEY_MAX_COUNT> GetKeyDown() { return keyDown; }

	void SetKeyUp(int key, bool state) { keyUp.set(key, state); }
	void SetKeyDown(int key, bool state) { keyDown.set(key, state); }

	KeyManager();
	~KeyManager();
	
};
