#pragma once
#include "Headers.h"

class MainUpdate
{
private:
	HDC		m_hdc;
	int BgmNum;
public:
	void Initialize();
	void Update();
	void Render();
	void Release();
public:
	MainUpdate();
	~MainUpdate();
};



// ** UI
// ** ����
