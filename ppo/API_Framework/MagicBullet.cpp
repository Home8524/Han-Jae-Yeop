#include "MagicBullet.h"
#include "Object.h"
MagicBullet::MagicBullet()
{

}

MagicBullet::~MagicBullet()
{

}


void MagicBullet::Initialize()
{
	Speed = 3.0f;
	DrawKey = "Bullet1";

	ImageList = Object::GetImageList();
}

int MagicBullet::Update(Transform& _rTransInfo)
{
	_rTransInfo.Position.y += _rTransInfo.Direction.y * Speed;
	if (_rTransInfo.Position.y > WindowsHeight)
		return 1;



	return 0;
}


void MagicBullet::Render(HDC _hdc)
{


	TransparentBlt(_hdc, // ** 최종 출력 위치
		3 + int(RealObject->GetPosition().x - (RealObject->GetScale().x / 2)),
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

void MagicBullet::Release()
{

}