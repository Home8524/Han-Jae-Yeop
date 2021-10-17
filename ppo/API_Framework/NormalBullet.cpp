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
	RealObject->SetPosition(3 + int(RealObject->GetPosition().x), -40 + int(RealObject->GetPosition().y));
}

int NormalBullet::Update(Transform& _rTransInfo)
{
	_rTransInfo.Position.x += _rTransInfo.Direction.x * Speed;
	_rTransInfo.Position.y += _rTransInfo.Direction.y * Speed;
	if (_rTransInfo.Position.y < 0)
		return 1;
	
	

	return 0;
}


void NormalBullet::Render(HDC _hdc)
{
	
	
	TransparentBlt(_hdc, // ** 최종 출력 위치
		int(RealObject->GetPosition().x - (RealObject->GetScale().x / 2)),
		int(RealObject->GetPosition().y - (RealObject->GetScale().y / 2)),
		17,
		16,
		ImageList[DrawKey]->GetMemDC(),
		0,
		0,
		17,
		16,
		RGB(255, 0, 255));

}

void NormalBullet::Release()
{

}
