#include "Score_Back.h"
#include "InputManager.h"
#include "ScoreManager.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <list>
#include <algorithm>
#include <stdlib.h>
Score_Back::Score_Back()
{

}

Score_Back::~Score_Back()
{

}


void Score_Back::Initialize()
{
	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Direction = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(0.0f, 0.0f);
	int Tmp = LoadDate("../Date/Score.csv");
	ScoreManager::GetInstance()->SetScore(Tmp);
	ScoreManager::GetInstance()->MakeScoreNumber();
	NumberList = ScoreManager::GetInstance()->GetScoreNumber();
	strKey = "End";
	Active = false;
	Image = ScoreManager::GetInstance()->GetImage();
}

int Score_Back::Update()
{
	return 0;
}

void Score_Back::Render(HDC _hdc)
{
	BitBlt(_hdc,
		0, 0,
		WindowsWidth,
		WindowsHeight,
		ImageList[strKey]->GetMemDC(),
		0, 0,
		SRCCOPY);

	TransparentBlt(_hdc,
		0,
		0,
		640,
		490,
		ImageList["Result5"]->GetMemDC(),
		0,
		0,
		640,
		500,
		RGB(255, 0, 255));

	int i = 0;
	
	for (vector<int>::iterator iter = NumberList->begin(); iter != NumberList->end(); ++iter)
	{
		int Tmp;
		Tmp = (*iter);
		TransparentBlt(_hdc, // ** ���� ��� ��ġ
			int(150) + i,
			int(130),
			20,
			20,
			Image->GetMemDC(),
			int(16) * Tmp,
			int(17) * 0,
			int(16),
			int(17),
			RGB(255, 0, 255));
		i += 20;
	}
	
	TransparentBlt(_hdc, // ** ���� ��� ��ġ
		int(150),
		int(163),
		20,
		20,
		Image->GetMemDC(),
		int(16) * 0,
		int(17) * 0,
		int(16),
		int(17),
		RGB(255, 0, 255));

	TransparentBlt(_hdc, // ** ���� ��� ��ġ
		int(150),
		int(193),
		20,
		20,
		Image->GetMemDC(),
		int(16) * 0,
		int(17) * 0,
		int(16),
		int(17),
		RGB(255, 0, 255));

	TransparentBlt(_hdc, // ** ���� ��� ��ġ
		int(150),
		int(224),
		20,
		20,
		Image->GetMemDC(),
		int(16) * 0,
		int(17) * 0,
		int(16),
		int(17),
		RGB(255, 0, 255));

	TransparentBlt(_hdc, // ** ���� ��� ��ġ
		int(150),
		int(256),
		20,
		20,
		Image->GetMemDC(),
		int(16) * 0,
		int(17) * 0,
		int(16),
		int(17),
		RGB(255, 0, 255));

	
}

void Score_Back::Release()
{

}

int Score_Back::LoadDate(const char* _FileName)
{
	// ** ������ �ҷ��´�.
	ifstream pFileCSV(_FileName);

	string Partitions = "#/, _";

	// ** �׷��� ������ ���ڵ��� ������ ����Ʈ�� ����� �����ϱ����� �����̳ʸ� �����Ѵ�.
	list<string> BufferList;

	// ** ������ �����Ѵ�.
	if (pFileCSV.is_open())
	{
		while (!pFileCSV.eof())
		{
			string Buffer;
			getline(pFileCSV, Buffer);

			// ** �ҷ��� ���ڿ��� Partitions �� ����Ͽ� ���ڿ����� ������ �ش�.
			for (auto Start = Buffer.begin(), Stop = Start; Stop != Buffer.end(); )
			{
				Stop = find_first_of(Start, Buffer.end(), Partitions.begin(), Partitions.end());

				// ** ������ ���ڿ����� ������ ����Ʈ�� �����Ѵ�.
				BufferList.push_back(string(Start, Stop));

				if (Stop != Buffer.end())
					Start = Stop + 1;
			}
		}
	}

	pFileCSV.close();

	map<string, int> ScoreList2;

	for (list<string>::iterator iter = BufferList.begin();
		iter != BufferList.end(); )
	{
		// ** �ش� ���ڿ��� ������ �ƴѰ�쿡�� 
		if ((*iter) != "")
		{

			string Level = (*iter);
			++iter;
			int Score = atoi((*iter).c_str());
			++iter;

			// ** ��� �з��� ������ �Ǿ��ٸ� �л������� �����ϴ� ����Ʈ�� ��´�.
			ScoreList2.insert(make_pair(Level, Score));
		}
		else
			++iter;
	}

	map<string, int>::iterator iter = ScoreList2.find("Easy");
	int Tmp = iter->second;

	return Tmp;
}