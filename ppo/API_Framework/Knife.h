#pragma once
#include "BulletBridge.h"

class Knife : public BulletBridge
{
public:
	map<string, Bitmap*> ImageList;
	int Ran;
public:
	virtual void Initialize()override;
	virtual int Update(Transform& _rTransInfo)override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;
public:
	Knife();
	virtual ~Knife();
};

