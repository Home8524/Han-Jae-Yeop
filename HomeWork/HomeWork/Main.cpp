#include<stdio.h>
#include <iostream>
using namespace std;

int main(void)

{
	int Lotto[6];
	int Random;
	int flag = 0;
	for (int i = 0; i < 6; i++)
	{
		Random = rand() % 45 + 1;
		for (int j = 0; j < i; j++)
		{
			if (Lotto[j] == Random) flag = 1;
			break;
		}
		if (flag == 1)
		{
			flag = 0;
			i--;
			continue;
		}
		else Lotto[i] = Random;
	}

	for (int i = 0; i < 6; i++)
		cout << Lotto[i] << " ";

	cout << endl;

	return 0;
}