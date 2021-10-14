#include "Object.h"

class Effect1 : public Object
{
public:
	int Frame;
	ULONGLONG Time;
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

	virtual Object* Clone()override { return new Effect1(*this); }
public:
	Effect1();
	Effect1(const Transform& _rTransInfo) : Object(_rTransInfo) { }
	virtual ~Effect1();
};