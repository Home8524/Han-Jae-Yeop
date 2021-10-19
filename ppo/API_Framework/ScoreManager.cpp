#include "ScoreManager.h"

ScoreManager* ScoreManager::Instance = nullptr;

void ScoreManager::Initialize()
{

}

void ScoreManager::MakeScoreNumber()
{
	SetScore(687465415);
	
	stack<int> Numbers;

	while (Score > 0)
	{
		int iTemp = int(Score % 10);
		Score /= 10;

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
			int(50),
			32,
			42,
			Image->GetMemDC(),
			int(64) * Tmp,
			int(85) * 0,
			int(64),
			int(85),
			RGB(255, 0, 255));
		i += 40;
	}
}
