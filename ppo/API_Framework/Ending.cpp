#include "Ending.h"
#include "SceneManager.h"
#include "End_Back.h"
#include "SoundManager.h"
#include "ScoreManager.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <list>
#include <algorithm>
#include <stdlib.h>

Ending::Ending()
{

}

Ending::~Ending()
{
	Release();
}


void Ending::Initialize()
{
	MenuBack = new End_Back;
	MenuBack->Initialize();
	ImageList = Object::GetImageList();
	Time = GetTickCount64();
	SoundManager::GetInstance()->StopSound("BGM4");
	SoundManager::GetInstance()->OnPlaySound("BGM18");
}

void Ending::Update()
{

	if (GetAsyncKeyState('X') && Time + 2000 < GetTickCount64()) {

		SoundManager::GetInstance()->StopSound("BGM18");
		SoundManager::GetInstance()->OnPlaySound("BGM1");
		Time = GetTickCount64();
		SceneManager::GetInstance()->SetScene(SCENEID::STAGE);
	}
}

void Ending::Render(HDC _hdc)
{
	MenuBack->Render(ImageList["Buffer"]->GetMemDC());

	BitBlt(_hdc,
		0, 0,
		WindowsWidth,
		WindowsHeight,
		ImageList["Buffer"]->GetMemDC(),
		0, 0,
		SRCCOPY);
}

void Ending::Release()
{
	SaveDate("../Date/Score.csv");
}

void Ending::SaveDate(const char* _FileName)
{
	int Tmp = LoadDate("../Date/Score.csv");
	ofstream pFileCSV;
	pFileCSV.open(_FileName);
	int Sc = ScoreManager::GetInstance()->GetScore();
	if (Tmp > Sc) Sc = Tmp;

	ScoreList.insert(make_pair("Easy", Sc));
	ScoreList.insert(make_pair("Normal", 0));
	ScoreList.insert(make_pair("Hard", 0));
	ScoreList.insert(make_pair("Lunatic", 0));
	ScoreList.insert(make_pair("Extra", 0));

	// ** 쓰여진 데이터를 모두 저장한다.
	for (map<string,int>::iterator iter = ScoreList.begin();
		iter != ScoreList.end(); ++iter)
	{
		// ** 파일에 데이터를 넣는 과정.  데이터와 데이터 사이에 (,) 를 넣어 분류한다.
		// ** 엑셀 파일에 저장할때 데이터 뒤에(,)를 넣으면 다음 셀로 이동하여 다음 데이터가 저장된다.
		pFileCSV.write((*iter).first.c_str(), (*iter).first.size());
		pFileCSV << "," << (*iter).second << "," << endl;
	}

	cout << "저장외 완료되었습니다." << endl;

	// ** 파일을 닫는다.
	pFileCSV.close();
}
int Ending::LoadDate(const char* _FileName)
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

			string Level= (*iter);
			++iter;
			int Score = atoi((*iter).c_str());
			++iter;

			// ** 모든 분류가 마무리 되었다면 학생정보를 저장하는 리스트에 담는다.
			ScoreList2.insert(make_pair(Level, Score));
		}
		else
			++iter;
	}

	map<string,int>::iterator iter =  ScoreList2.find("Easy");
	int Tmp =  iter->second;

	return Tmp;
}