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
	* Result[6] = 1등 당첨 번호이다.
	* 컨테이너 Lottos 는 자동으로 추출된 조합이다. 총 100개의 조합이 있다.
	* 이 조합중에 1등 당첨 번호와 비교하여 등수를 확인하는 프로그램을 작성하시오.
	*
	* 1등 6개 번호가 모두 일치
	* 2등 5개 번호가 일치
	* 3등 4개 번호가 일치
	* 4등 3개 번호가 일치
	* 5등 2개 번호가 일치
	* 나머지는 꽝
	****************************************************************/

	// ** 아래 공백부터 해답을 작성해 주세요~

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
		
		cout << "일치 : " << Cnt << endl;
		switch (Cnt)
		{
			case 6:
				cout << "1등" << endl;
				break;
			case 5:
				cout << "2등" << endl;
				break;
			case 4:
				cout << "3등" << endl;
				break;
			case 3:
				cout << "4등" << endl;
				break;
			case 2:
				cout << "5등" << endl;
				break;
			default:
				cout << "꽝" << endl;
				break;
		}

		cout << "===============" << endl;
	}













	return 0;
}