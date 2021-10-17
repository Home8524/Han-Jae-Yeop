#pragma once
#include "Scene.h"

class Object;
class Ending : public Scene
{
	ULONGLONG Time;
private:
	Object* MenuBack;
	map<string, Bitmap*> ImageList;
public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;
public:
	Ending();
	virtual ~Ending();
};