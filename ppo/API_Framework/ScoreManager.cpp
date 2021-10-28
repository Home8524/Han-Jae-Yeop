#include "ScoreManager.h"

ScoreManager* ScoreManager::Instance = nullptr;

void ScoreManager::Initialize()
{

}

void ScoreManager::MakeScoreNumber()
{
	stack<int> Numbers;
	Sc2 = Score;
	if (Sc2 == 0)
	{
		int iTemp = 0;
		Numbers.push(iTemp);
	}
	while (Sc2 > 0)
	{
		int iTemp = int(Sc2 % 10);
		Sc2 /= 10;

		Numbers.push(iTemp);
	}

	while (!Numbers.empty())
	{
		NumberList.push_back(Numbers.top());
		Numbers.pop();
	}
}

void ScoreManager::Render(HDC _hdc)
{
	int i = 0;
	for (vector<int>::iterator iter=NumberList.begin();iter!=NumberList.end();++iter)
	{
		int Tmp;
		Tmp = (*iter);
		TransparentBlt(_hdc, // ** 최종 출력 위치
			int(100)+i,
			int(100),
			32,
			42,
			Image->GetMemDC(),
			int(16) * Tmp,
			int(17) * 0,
			int(16),
			int(17),
			RGB(255, 0, 255));
		i += 40;
	}
}
