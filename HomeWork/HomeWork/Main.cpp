#include <iostream>
#include <vector>

using namespace std;



struct Numbers
{
	int Lottos[6];
};


int main(void)
{
	vector<Numbers*> Lottos;
	int Result[6];

	srand((unsigned)time(NULL));

	for (int n = 0; n < 101; ++n)
	{
		const int ARR_SIZE = 46;
		bool arrFlag[ARR_SIZE] = { false };

		int Count = 0;

		while (Count < 6)
		{
			int Num = rand() % 45 + 1;
			if (!arrFlag[Num])
			{
				arrFlag[Num] = true;
				++Count;
			}
		}


		if (n == 0)
		{
			Numbers* Temp = new Numbers;
			Count = 0;

			for (int i = 1; i < ARR_SIZE; ++i)
			{
				if (arrFlag[i])
				{
					Temp->Lottos[Count] = i;
					Result[Count++] = i;
				}
			}
			Lottos.push_back(Temp);
		}
		else
		{
			Numbers* Temp = new Numbers;
			Count = 0;

			for (int i = 1; i < ARR_SIZE; ++i)
			{
				if (arrFlag[i])
					Temp->Lottos[Count++] = i;
			}
			Lottos.push_back(Temp);
		}
	}

	
	
	
	/*
	for (int i = 0; i < 6; ++i)
		cout << Result[i] << " ";
	cout << endl << endl;


	for (vector<Numbers*>::iterator iter = Lottos.begin();
		iter != Lottos.end(); ++iter)
	{
		for (int i = 0; i < 6; ++i)
			cout << (*iter)->Lottos[i] << " ";
		cout << endl;
	}
	
	*/
	/***************************************************************
	* Result[6] = 1�� ��÷ ��ȣ�̴�.
	* �����̳� Lottos �� �ڵ����� ����� �����̴�. �� 100���� ������ �ִ�.
	* �� �����߿� 1�� ��÷ ��ȣ�� ���Ͽ� ����� Ȯ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
	*
	* 1�� 6�� ��ȣ�� ��� ��ġ
	* 2�� 5�� ��ȣ�� ��ġ
	* 3�� 4�� ��ȣ�� ��ġ
	* 4�� 3�� ��ȣ�� ��ġ
	* 5�� 2�� ��ȣ�� ��ġ
	* �������� ��
	****************************************************************/

	// ** �Ʒ� ������� �ش��� �ۼ��� �ּ���~

	for (vector<Numbers*>::iterator iter = Lottos.begin();
		iter != Lottos.end(); ++iter)
	{
		int Cnt = 0;
		for (int i = 0; i < 6; ++i)
		{
			for (int j = 0; j < 6; ++j)
			{
				if (Result[j] == (*iter)->Lottos[i]) Cnt++;
			}
		}
		
		cout << "��ġ : " << Cnt << endl;
		switch (Cnt)
		{
			case 6:
				cout << "1��" << endl;
				break;
			case 5:
				cout << "2��" << endl;
				break;
			case 4:
				cout << "3��" << endl;
				break;
			case 3:
				cout << "4��" << endl;
				break;
			case 2:
				cout << "5��" << endl;
				break;
			default:
				cout << "��" << endl;
				break;
		}

		cout << "===============" << endl;
	}













	return 0;
}