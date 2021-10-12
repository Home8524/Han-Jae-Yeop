#include "Magic.h"
#include "Object.h"
Magic::Magic()
{

}

Magic::~Magic()
{

}


void Magic::Initialize()
{
	Speed = 3.0f;
	DrawKey = "Magic1";
	ImageList = Object::GetImageList();
	Time = GetTickCount64();
	Flag = 0;
}

int Magic::Update(Transform& _rTransInfo)
{

	if (Time + 1000 < GetTickCount64())
	{
		Flag = 1;
	}
	if (Time + 2000 < GetTickCount64())
	{
		Flag = 2;
	}
	
	if (Time + 3000 < GetTickCount64())
	{
		Flag = 3;
	}
	
	if (Time + 5000 < GetTickCount64())
		return 1;
	
	_rTransInfo.Position.y += 1.0f * Speed ;

	return 0;
}


void Magic::Render(HDC _hdc)
{
	TransparentBlt(_hdc, // ** 최종 출력 위치
		int(RealObject->GetPosition().x - (RealObject->GetScale().x / 2)),
		int(RealObject->GetPosition().y - (RealObject->GetScale().y / 2)),
		16,
		16,
		ImageList["EnemyBullet1"]->GetMemDC(),
		0,
		0,
		16,
		16,
		RGB(255, 0, 255));

	for (int i = 1; i <8; i++)
	{
		if (i == 3) continue;
		int j = 0;
		int k = 0;
		if (i >= 6)
		{
			k = 30;
			j = 100+360*(i-6)- 40 + ((i-5)*120);
		}
		TransparentBlt(_hdc, // ** 최종 출력 위치
			WindowsWidth-(120*i)+j,
			50-k,
			66,
			66,
			ImageList[DrawKey]->GetMemDC(),
			0,
			0,
			66,
			66,
			RGB(255, 0, 255));
		if (Flag == 2)
		{
			TransparentBlt(_hdc, // ** 최종 출력 위치
				WindowsWidth - (120 * i) + j + 24,
				50 - k + 30,
				16,
				500,
				ImageList["Magic3"]->GetMemDC(),
				0,
				0,
				16,
				16,
				RGB(255, 0, 255));

		}
		else if (Flag == 3)
		{
			TransparentBlt(_hdc, // ** 최종 출력 위치
				WindowsWidth - (120 * i) + j + 24,
				50 - k + 30,
				16,
				500,
				ImageList["Magic3"]->GetMemDC(),
				16,
				0,
				16,
				16,
				RGB(255, 0, 255));

		}

		if (Flag >= 1)
		{
			TransparentBlt(_hdc, // ** 최종 출력 위치
				WindowsWidth - (120 * i) + j+18,
				50 - k+18,
				32,
				32,
				ImageList["Magic2"]->GetMemDC(),
				0,
				0,
				32,
				32,
				RGB(255, 0, 255));
		}
		
	}


}

void Magic::Release()
{

}