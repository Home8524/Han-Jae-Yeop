#include "BossBullet7.h"
#include "Object.h"
BossBullet7::BossBullet7()
{

}

BossBullet7::~BossBullet7()
{

}


void BossBullet7::Initialize()
{
	Speed = 2.0f;
	DrawKey = "BossBullet1";
	ImageList = Object::GetImageList();
}

int BossBullet7::Update(Transform& _rTransInfo)
{


	_rTransInfo.Position.x += -0.0f * Speed;
	_rTransInfo.Position.y += 1.0f * Speed;

	if (_rTransInfo.Position.x >= (WindowsWidth) || _rTransInfo.Position.x < 0)
		return 1;
	else if (_rTransInfo.Position.y >= WindowsHeight || _rTransInfo.Position.y < 0)
		return 1;
	return 0;
}


void BossBullet7::Render(HDC _hdc)
{


	TransparentBlt(_hdc, // ** 최종 출력 위치
		int(RealObject->GetPosition().x - (RealObject->GetScale().x / 2))-10,
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

void BossBullet7::Release()
{

}