#include "End_Back.h"
#include "InputManager.h"
#include "ScoreManager.h"
#include "SoundManager.h"
End_Back::End_Back()
{

}

End_Back::~End_Back()
{

}


void End_Back::Initialize()
{
	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Direction = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(0.0f, 0.0f);

	strKey = "End";
	Active = false;
	ScoreManager::GetInstance()->MakeScoreNumber();
	SoundManager::GetInstance()->StopSound("BGM2");
}

int End_Back::Update()
{
	return 0;
}

void End_Back::Render(HDC _hdc)
{
	

	BitBlt(_hdc,
		0, 0,
		WindowsWidth,
		WindowsHeight,
		ImageList[strKey]->GetMemDC(),
		0, 0,
		SRCCOPY);

	TransparentBlt(_hdc, // ** 최종 출력 위치
		200,
		20,
		200,
		34,
		ImageList["Result1"]->GetMemDC(),
		0,
		0,
		153,
		34,
		RGB(255, 0, 255));

	TransparentBlt(_hdc, // ** 최종 출력 위치
		30,
		100,
		59,
		36,
		ImageList["Result2"]->GetMemDC(),
		0,
		0,
		59,
		36,
		RGB(255, 0, 255));

	TransparentBlt(_hdc, // ** 최종 출력 위치
		30,
		300,
		59,
		36,
		ImageList["Result3"]->GetMemDC(),
		0,
		0,
		59,
		28,
		RGB(255, 0, 255));

	TransparentBlt(_hdc, // ** 최종 출력 위치
		100,
		300,
		100,
		50,
		ImageList["Result4"]->GetMemDC(),
		0,
		0,
		41,
		20,
		RGB(255, 0, 255));

	TransparentBlt(_hdc, // ** 최종 출력 위치
		450,
		400,
		100,
		50,
		ImageList["Result5"]->GetMemDC(),
		555,
		441,
		80,
		30,
		RGB(255, 0, 255));

	ScoreManager::GetInstance()->Render(_hdc);
}

void End_Back::Release()
{

}