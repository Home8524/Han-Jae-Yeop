#include "Stage1_Back.h"
#include "InputManager.h"
#include "ObjectManager.h"
Stage1_Back::Stage1_Back()
{

}

Stage1_Back::~Stage1_Back()
{

}


void Stage1_Back::Initialize()
{
	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Direction = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(640.0f, 500.0f);

	TP = ObjectManager::GetInstance()->GetPlayer();
	strKey = "Stage1";
	Active = false;
}

int Stage1_Back::Update()
{
	if (TP->GetPhase() == 1)
	{
		strKey = "Spell1";
		TransInfo.Scale = Vector3(256.0f, 256.0f);
	}
	else if (TP->GetPhase() == 2)
	{
		strKey = "Spell2";
	}
	else if (TP->GetPhase() == 3)
	{
		strKey = "Spell3";
	}
	return 0;
}

void Stage1_Back::Render(HDC _hdc)
{
	

	StretchBlt(
		_hdc,
		0,
		0,
		640,
		500,
		ImageList[strKey]->GetMemDC(),
		0,
		0,
		TransInfo.Scale.x,
		TransInfo.Scale.y,
		SRCCOPY
	);
	/*
	BitBlt(_hdc,
		0, 0,
		WindowsWidth,
		WindowsHeight,
		ImageList[strKey]->GetMemDC(),
		0, 0,
		SRCCOPY);
	*/
	

}

void Stage1_Back::Release()
{

}