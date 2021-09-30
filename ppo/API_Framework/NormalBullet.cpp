#include "NormalBullet.h"
#include "Object.h"
NormalBullet::NormalBullet()
{

}

NormalBullet::~NormalBullet()
{

}


void NormalBullet::Initialize()
{
	Speed = 3.0f;
	DrawKey = "Bullet1";
	
	ImageList = Object::GetImageList();
}

int NormalBullet::Update(Transform& _rTransInfo)
{
	_rTransInfo.Position.x += _rTransInfo.Direction.x * Speed;
	_rTransInfo.Position.y += _rTransInfo.Direction.y * Speed;

	if (_rTransInfo.Position.x >= (WindowsWidth - 100))
		return 1;

	return 0;
}


void NormalBullet::Render(HDC _hdc)
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

	
	/*
	Ellipse(_hdc,
		4+int(RealObject->GetPosition().x - (RealObject->GetScale().x / 2)),
		-30+int(RealObject->GetPosition().y - (RealObject->GetScale().y / 2)),
		4+int(RealObject->GetPosition().x + (RealObject->GetScale().x / 2)),
		-30+int(RealObject->GetPosition().y + (RealObject->GetScale().y / 2)));
	*/
	

}

void NormalBullet::Release()
{

}
