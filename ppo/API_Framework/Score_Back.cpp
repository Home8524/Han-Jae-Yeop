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
		TransparentBlt(_hdc, // ** 최종 출력 위치
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
	
	TransparentBlt(_hdc, // ** 최종 출력 위치
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

	TransparentBlt(_hdc, // ** 최종 출력 위치
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

	TransparentBlt(_hdc, // ** 최종 출력 위치
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

	TransparentBlt(_hdc, // ** 최종 출력 위치
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
	// ** 파일을 불러온다.
	ifstream pFileCSV(_FileName);

	string Partitions = "#/, _";

	// ** 그렇게 나눠진 문자들을 별도의 리스트를 만들어 관리하기위해 컨터이너를 생성한다.
	list<string> BufferList;

	// ** 파일을 오픈한다.
	if (pFileCSV.is_open())
	{
		while (!pFileCSV.eof())
		{
			string Buffer;
			getline(pFileCSV, Buffer);

			// ** 불러온 문자열을 Partitions 을 사용하여 문자열별로 나누어 준다.
			for (auto Start = Buffer.begin(), Stop = Start; Stop != Buffer.end(); )
			{
				Stop = find_first_of(Start, Buffer.end(), Partitions.begin(), Partitions.end());

				// ** 나눠진 문자열들은 별도의 리스트에 관리한다.
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
		// ** 해당 문자열이 공백이 아닌경우에만 
		if ((*iter) != "")
		{

			string Level = (*iter);
			++iter;
			int Score = atoi((*iter).c_str());
			++iter;

			// ** 모든 분류가 마무리 되었다면 학생정보를 저장하는 리스트에 담는다.
			ScoreList2.insert(make_pair(Level, Score));
		}
		else
			++iter;
	}

	map<string, int>::iterator iter = ScoreList2.find("Easy");
	int Tmp = iter->second;

	return Tmp;
}