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
	Speed = 4.0f;

	ImageList = Object::GetImageList();
	DrawKey = "BossBullet1";
}

int BigBullet::Update(Transform& _rTransInfo)
{
	/*
	_rTransInfo.Position.x -= _rTransInfo.Direction.x * Speed;
	_rTransInfo.Position.y -= _rTransInfo.Direction.y * Speed;
	*/
	if (_rTransInfo.Position.x - RealObject->GetPosition().x > 0)
		_rTransInfo.Position.x -= 1.0f*Speed;
	else if(_rTransInfo.Position.x - RealObject->GetPosition().x < 0)
		_rTransInfo.Position.x += 1.0f * Speed;

	if (_rTransInfo.Position.y - RealObject->GetPosition().y > 0)
		_rTransInfo.Position.y -= 1.0f * Speed;
	else if (_rTransInfo.Position.y - RealObject->GetPosition().y < 0)
		_rTransInfo.Position.y += 1.0f * Speed;

	if (_rTransInfo.Position.x >= (WindowsWidth - 100))
		return 1;

	return 0;
}


void BigBullet::Render(HDC _hdc)
{
	
	TransparentBlt(_hdc, // ** 최종 출력 위치
		int(RealObject->GetPosition().x - (RealObject->GetScale().x / 2)),
		int(RealObject->GetPosition().y - (RealObject->GetScale().y / 2)+10),
		32,
		32,
		ImageList[DrawKey]->GetMemDC(),
		0,
		0,
		32,
		32,
		RGB(255, 0, 255));

	
}

void BigBullet::Release()
{

}