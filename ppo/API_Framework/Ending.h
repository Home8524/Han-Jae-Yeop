#pragma once
#include "Scene.h"

class Object;
class Ending : public Scene
{
public:
	ULONGLONG Time;
	map<string, int> ScoreList;
private:
	Object* MenuBack;
	map<string, Bitmap*> ImageList;
public:
	void SaveDate(const char* _FileName);
	int LoadDate(const char* _FileName);
public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;
public:
	Ending();
	virtual ~Ending();
};