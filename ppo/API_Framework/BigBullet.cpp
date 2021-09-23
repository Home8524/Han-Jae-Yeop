#include "BigBullet.h"
#include "Object.h"

BigBullet::BigBullet()
{

}

BigBullet::~BigBullet()
{

}


void BigBullet::Initialize()
{
	Speed = 5.0f;

	DrawKey = "BigBullet";
}

int BigBullet::Update(Transform& _rTransInfo)
{
	_rTransInfo.Position.x -= _rTransInfo.Direction.x * Speed;
	_rTransInfo.Position.y -= _rTransInfo.Direction.y * Speed;

	if (_rTransInfo.Position.x >= (WindowsWidth - 100))
		return 1;

	return 0;
}


void BigBullet::Render(HDC _hdc)
{
	/*
	TransparentBlt(_hdc, // ** 최종 출력 위치
		int(TransInfo.Position.x - (TransInfo.Scale.x / 2)),
		int(TransInfo.Position.y + (TransInfo.Scale.x / 2) - Offset.y - 50),
		int(TransInfo.Scale.x),
		int(Offset.y),
		ImageList[Drawkey]->GetMemDC(),
		0, 0,
		int(TransInfo.Scale.x),
		int(Offset.y),
		RGB(255, 0, 255));
	*/

	Rectangle(_hdc,
		int(RealObject->GetPosition().x - (RealObject->GetScale().x / 2)),
		int(RealObject->GetPosition().y - (RealObject->GetScale().y / 2)),
		int(RealObject->GetPosition().x + (RealObject->GetScale().x / 2)+10),
		int(RealObject->GetPosition().y + (RealObject->GetScale().y / 2))+10);
}

void BigBullet::Release()
{

}