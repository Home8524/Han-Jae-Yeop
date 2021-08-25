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
	// ** 싱글톤 클레스는 아래와 같이 외부에서 무분별하게 사용할 수 없다.
	//SingletonManager* Single = new SingletonManager;
	



	// ** 싱글톤 패턴은 항상 자기 자신이 만든 Instance 를 통해 접근한다.
	//SingletonManager::GetInstance()-> 




	// ** Setter & Getter 를 사용함.
	//Setter = 값의 변경.
	//Getter = 값으 참조.

	/*
	SingletonManager::GetInstance()->SetNumber(10);
	int* pNumber = SingletonManager::GetInstance()->GetNumber();
	cout << (*pNumber) << endl;
	*/



	return 0;
}

