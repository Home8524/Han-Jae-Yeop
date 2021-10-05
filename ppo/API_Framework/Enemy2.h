#pragma once
#include "Object.h"

class Enemy2 : public Object
{
public:
	vector<Object*>* BulletList;
	ULONGLONG Time;
	ULONGLONG Time2;
	int Frame;
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

	virtual Object* Clone()override { return new Enemy2(*this); }
	template <typename T>
	Object* CreateBullet();
public:
	Enemy2();
	Enemy2(const Transform& _rTransInfo) : Object(_rTransInfo) { }
	virtual ~Enemy2();
};
