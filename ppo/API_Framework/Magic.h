#include "BulletBridge.h"

class Magic : public BulletBridge
{
public:
	map<string, Bitmap*> ImageList;
	ULONGLONG Time;
	int Flag;
	vector<Object*> T;
	ULONGLONG Time2;
public:
	virtual void Initialize()override;
	virtual int Update(Transform& _rTransInfo)override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;
public:
	Magic();
	virtual ~Magic();
};