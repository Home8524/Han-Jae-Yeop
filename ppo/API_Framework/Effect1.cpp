#include "Effect1.h"
Effect1::Effect1()
{

}

Effect1::~Effect1()
{

}

void Effect1::Initialize()
{
	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(32.0f, 34.0f);

	Collider.Position = Vector3(0.0f, 0.0f);
	Collider.Scale = Vector3(16.0f, 16.0f);

	Offset = Vector3(32.0f, 34.0f);

	Active = false;
	strKey = "Fire";
	Speed = 1.5f;
	Frame = 30;
	Time = GetTickCount64();
}

int Effect1::Update()
{
	if (Active)	Frame--;
	
	if (Frame==0) Active = false;
	return 0;
}

void Effect1::Render(HDC _hdc)
{
	TransparentBlt(_hdc, // ** 최종 출력 위치
		int(TransInfo.Position.x - (TransInfo.Scale.x / 2)),
		int(TransInfo.Position.y + (TransInfo.Scale.x / 2)),
		int(TransInfo.Scale.x),
		int(Offset.y),
		ImageList[strKey]->GetMemDC(),
		32*(Frame/10), 0,
		32,
		34,
		RGB(255, 0, 255));
}

void Effect1::Release()
{
	
}