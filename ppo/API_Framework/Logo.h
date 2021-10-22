#pragma once
#include "Scene.h"

class Object;
class Logo : public Scene
{
public:
	int Bgmstart;
private:
	map<string, Bitmap*> ImageList;
	Object* LogoBack;
public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;
public:
	Logo();
	virtual ~Logo();
};