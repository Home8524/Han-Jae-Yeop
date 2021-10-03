#pragma once
#include "Object.h"

class Enemy : public Object
{
public:
	vector<Object*>* BulletList;
	ULONGLONG Time;
	ULONGLONG Time2;
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

	virtual Object* Clone()override { return new Enemy(*this); }
	template <typename T>
	Object* CreateBullet();
public:
	Enemy();
	Enemy(const Transform& _rTransInfo) : Object(_rTransInfo) { }
	virtual ~Enemy();
};
