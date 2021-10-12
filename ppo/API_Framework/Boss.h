#include "Object.h"

class Boss : public Object
{
public:
	vector<Object*>* BulletList;
	ULONGLONG Time;
	ULONGLONG Time2;
	ULONGLONG Time3;
	ULONGLONG Time4;
	int Frame;
	int MoveTerm;
	int Cnt;
	bool Left;
	bool HpBar;
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

	virtual Object* Clone()override { return new Boss(*this); }
	template <typename T>
	Object* CreateBullet();
public:
	Boss();
	Boss(const Transform& _rTransInfo) : Object(_rTransInfo) { }
	virtual ~Boss();
};
