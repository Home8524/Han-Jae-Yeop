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

	// ** ������ �����͸� ��� �����Ѵ�.
	for (map<string,int>::iterator iter = ScoreList.begin();
		iter != ScoreList.end(); ++iter)
	{
		// ** ���Ͽ� �����͸� �ִ� ����.  �����Ϳ� ������ ���̿� (,) �� �־� �з��Ѵ�.
		// ** ���� ���Ͽ� �����Ҷ� ������ �ڿ�(,)�� ������ ���� ���� �̵��Ͽ� ���� �����Ͱ� ����ȴ�.
		pFileCSV.write((*iter).first.c_str(), (*iter).first.size());
		pFileCSV << "," << (*iter).second << "," << endl;
	}

	cout << "����� �Ϸ�Ǿ����ϴ�." << endl;

	// ** ������ �ݴ´�.
	pFileCSV.close();
}
int Ending::LoadDate(const char* _FileName)
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

			string Level= (*iter);
			++iter;
			int Score = atoi((*iter).c_str());
			++iter;

			// ** ��� �з��� ������ �Ǿ��ٸ� �л������� �����ϴ� ����Ʈ�� ��´�.
			ScoreList2.insert(make_pair(Level, Score));
		}
		else
			++iter;
	}

	map<string,int>::iterator iter =  ScoreList2.find("Easy");
	int Tmp =  iter->second;

	return Tmp;
}