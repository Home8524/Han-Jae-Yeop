#pragma once
#include "Scene.h"

class Object;
class Level : public Scene
{
private:
	Object* State_Back;
	map<string, Bitmap*> ImageList;
	ULONGLONG Time;
public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;
public:
	Level();
	virtual ~Level();
};