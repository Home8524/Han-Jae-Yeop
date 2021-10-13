#include "NormalBullet3.h"
#include "Object.h"
NormalBullet3::NormalBullet3()
{

}

NormalBullet3::~NormalBullet3()
{

}


void NormalBullet3::Initialize()
{
	Speed = 3.0f;
	DrawKey = "Bullet1";

	ImageList = Object::GetImageList();
}

int NormalBullet3::Update(Transform& _rTransInfo)
{
	_rTransInfo.Position.x += _rTransInfo.Direction.x * Speed;
	_rTransInfo.Position.y += _rTransInfo.Direction.y * Speed;
	if (_rTransInfo.Position.y < 0)
		return 1;



	return 0;
}


void NormalBullet3::Render(HDC _hdc)
{


	TransparentBlt(_hdc, // ** 최종 출력 위치
		23 + int(RealObject->GetPosition().x - (RealObject->GetScale().x / 2)),
		-40 + int(RealObject->GetPosition().y - (RealObject->GetScale().y / 2)),
		17,
		16,
		ImageList[DrawKey]->GetMemDC(),
		0,
		0,
		17,
		16,
		RGB(255, 0, 255));

}

void NormalBullet3::Release()
{

}