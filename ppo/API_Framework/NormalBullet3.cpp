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
	Speed = 5.0f;
	DrawKey = "Bullet1";

	ImageList = Object::GetImageList();
	RealObject->SetPosition(18 + int(RealObject->GetPosition().x), -40 + int(RealObject->GetPosition().y));
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


	TransparentBlt(_hdc, // ** ���� ��� ��ġ
		int(RealObject->GetPosition().x - (RealObject->GetScale().x / 2)),
		int(RealObject->GetPosition().y - (RealObject->GetScale().y / 2)),
		14,
		16,
		ImageList[DrawKey]->GetMemDC(),
		0,
		0,
		14,
		16,
		RGB(255, 0, 255));

}

void NormalBullet3::Release()
{

}