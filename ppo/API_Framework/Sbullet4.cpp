#include "Sbullet4.h"
#include "Object.h"
Sbullet4::Sbullet4()
{

}

Sbullet4::~Sbullet4()
{

}


void Sbullet4::Initialize()
{
	Speed = 3.0f;
	DrawKey = "BossBullet1";
	ImageList = Object::GetImageList();
}

int Sbullet4::Update(Transform& _rTransInfo)
{


	_rTransInfo.Position.x += 1.0f * Speed;
	_rTransInfo.Position.y += 0.6f * Speed;

	if (_rTransInfo.Position.x >= (WindowsWidth) || _rTransInfo.Position.x < 0)
		return 1;
	else if (_rTransInfo.Position.y >= WindowsHeight || _rTransInfo.Position.y < 0)
		return 1;
	return 0;
}


void Sbullet4::Render(HDC _hdc)
{


	TransparentBlt(_hdc, // ** ���� ��� ��ġ
		int(RealObject->GetPosition().x - (RealObject->GetScale().x / 2)),
		int(RealObject->GetPosition().y - (RealObject->GetScale().y / 2)),
		16,
		16,
		ImageList[DrawKey]->GetMemDC(),
		0,
		0,
		32,
		32,
		RGB(255, 0, 255));

}

void Sbullet4::Release()
{

}