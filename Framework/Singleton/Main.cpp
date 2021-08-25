#include <iostream>
#include <Windows.h>
#include <vector>
#include <list>
#include <map>
#include <string>

using namespace std;


// ** Singleton
class SingletonManager
{
private:
	static SingletonManager* Instance;
public:
	static SingletonManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new SingletonManager;

		return Instance;
	}
private:
	int Number;
public:
	int* GetNumber() { return &Number; } 
	void SetNumber(int _number) { Number = _number; }
private:
	SingletonManager() {}
public:
	~SingletonManager() {}
};

SingletonManager* SingletonManager::Instance = nullptr;


int main(void)
{
	// ** �̱��� Ŭ������ �Ʒ��� ���� �ܺο��� ���к��ϰ� ����� �� ����.
	//SingletonManager* Single = new SingletonManager;
	



	// ** �̱��� ������ �׻� �ڱ� �ڽ��� ���� Instance �� ���� �����Ѵ�.
	//SingletonManager::GetInstance()-> 




	// ** Setter & Getter �� �����.
	//Setter = ���� ����.
	//Getter = ���� ����.

	/*
	SingletonManager::GetInstance()->SetNumber(10);
	int* pNumber = SingletonManager::GetInstance()->GetNumber();
	cout << (*pNumber) << endl;
	*/



	return 0;
}

