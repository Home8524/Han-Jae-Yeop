#include "BossBullet8.h"
#include "Object.h"
BossBullet8::BossBullet8()
{

}

BossBullet8::~BossBullet8()
{

}


void BossBullet8::Initialize()
{
	Speed = 2.0f;
	DrawKey = "BossBullet1";
	ImageList = Object::GetImageList();
}

int BossBullet8::Update(Transform& _rTransInfo)
{


	_rTransInfo.Position.x += 1.0f * Speed;
	_rTransInfo.Position.y += 1.0f * Speed;

	if (_rTransInfo.Position.x >= (WindowsWidth - 100) || _rTransInfo.Position.x < 0)
		return 1;
	else if (_rTransInfo.Position.y >= WindowsHeight || _rTransInfo.Position.y < 0)
		return 1;
	return 0;
}


void BossBullet8::Render(HDC _hdc)
{


	TransparentBlt(_hdc, // ** 최종 출력 위치
		int(RealObject->GetPosition().x - (RealObject->GetScale().x / 2)),
		int(RealObject->GetPosition().y - (RealObject->GetScale().y / 2)),
		32,
		32,
		ImageList[DrawKey]->GetMemDC(),
		0,
		0,
		32,
		32,
		RGB(255, 0, 255));

}

void BossBullet8::Release()
{

}