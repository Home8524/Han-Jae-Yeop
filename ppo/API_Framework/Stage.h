#pragma once
#include "Scene.h"


class Object;
class Stage : public Scene
{
private:
	Object* State_Back;
	Object* m_pPlayer;
	Object* m_pEffect;
	vector<Object*>* EnemyList;
	vector<Object*>* BulletList;

	map<string, Bitmap*> ImageList;

	// ** Ÿ�� ���� ����
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