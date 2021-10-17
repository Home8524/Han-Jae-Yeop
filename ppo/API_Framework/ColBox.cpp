#include "ColBox.h"
ColBox::ColBox()
{

}

ColBox::~ColBox()
{

}

void ColBox::Initialize()
{
	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(32.0f, 34.0f);

	Collider.Position = Vector3(0.0f, 0.0f);
	Collider.Scale = Vector3(16.0f, 16.0f);

	Offset = Vector3(32.0f, 34.0f);

	
}

int ColBox::Update()
{
	
	return 0;
}

void ColBox::Render(HDC _hdc)
{
	
}

void ColBox::Release()
{

}