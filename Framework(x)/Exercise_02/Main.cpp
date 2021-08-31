#define _CRT_SECURE_NO_WARINGS
#include <iostream>

using namespace std;

class AAA
{
private:
	char* Name;

public:

	void Input()
	{
		cout << "이름 입력 : ";
	}

	void Output()
	{
		cout << Name << endl;
	}
	void setName(char* _Name)
	{
		Name = _Name;
	}
	
};
int main(void)
{
	AAA aaa;
	aaa.Input();
	char arr[10];
	cin >> arr;
	aaa.setName(arr);
	aaa.Output();

	return 0;
}