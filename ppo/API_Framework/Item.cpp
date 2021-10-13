#include "Item.h"
Item::Item()
{

}

Item::~Item()
{

}

void Item::Initialize()
{
	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(16.0f, 16.0f);

	Collider.Position = Vector3(0.0f, 0.0f);
	Collider.Scale = Vector3(16.0f, 16.0f);

	Offset = Vector3(16.0f, 16.0f);

	Active = false;
	strKey = "Power";
	Speed = 1.5f;
}

int Item::Update()
{
	
	TransInfo.Position.y += 1.5f;
	if (TransInfo.Position.y > WindowsHeight) return 1;
	return 0;
}

void Item::Render(HDC _hdc)
{
	TransparentBlt(_hdc, // ** 최종 출력 위치
		int(TransInfo.Position.x - (TransInfo.Scale.x / 2)),
		int(TransInfo.Position.y + (TransInfo.Scale.x / 2)),
		int(TransInfo.Scale.x),
		int(Offset.y),
		ImageList[strKey]->GetMemDC(),
		0, 0,
		16,
		16,
		RGB(255, 0, 255));
}

void Item::Release()
{

}
