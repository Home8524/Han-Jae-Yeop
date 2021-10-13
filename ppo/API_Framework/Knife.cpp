#include "Knife.h"
#include "Object.h"
Knife::Knife()
{

}

Knife::~Knife()
{

}


void Knife::Initialize()
{
	Speed = 3.0f;
	DrawKey = "Knife";

	ImageList = Object::GetImageList();
	Ran = rand() % 6;
}

int Knife::Update(Transform& _rTransInfo)
{
	_rTransInfo.Position.y += 1.0f* Speed;
	if (_rTransInfo.Position.y > WindowsHeight)
		return 1;



	return 0;
}


void Knife::Render(HDC _hdc)
{

	for (int i = 0; i < 6; i++)
	{
		if (i == Ran) continue;
		TransparentBlt(_hdc, // ** 최종 출력 위치
			-90+(i*30)+int(RealObject->GetPosition().x - (RealObject->GetScale().x / 2)),
			int(RealObject->GetPosition().y - (RealObject->GetScale().y / 2)),
			26,
			32,
			ImageList[DrawKey]->GetMemDC(),
			0,
			0,
			26,
			32,
			RGB(255, 0, 255));
	}

}

void Knife::Release()
{

}