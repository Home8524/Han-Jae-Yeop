#pragma once
#include "Scene.h"


class Object;
class Stage : public Scene
{
private:
	Object* State_Back;

	map<string, Bitmap*> ImageList;
	ULONGLONG Time;
	// ** 타일 생성 개수
	int TileWidthCnt;
	int TileHeightCnt;
	int Cnt;
	int Cnt_max;
public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;
public:
	Stage();
	virtual ~Stage();
};