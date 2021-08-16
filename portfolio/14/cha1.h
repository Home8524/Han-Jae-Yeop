#pragma once
#include "setDefine.h"

using namespace cocos2d;
class cha1
{

public:

	cha1();
	~cha1();

	static cha1 *getInstance();
	
	//플레이어 스프라이트
	Sprite* Player = Sprite::create("kirby/effect/star_effect.png");

	//지형지물 충돌시
	Sprite* Unit = Sprite::create("kirby/effect/star_effect.png");

	//po2 불러오기용 /캐릭터스프라이트 저장소
	po2* po2_start = new po2();
	Moving* mov = new Moving();

	Layer* pl;
	Layer* worldlayer;
	
	bool flag_r = false;
	bool flag_l =false;
	bool flag_j = false; 
	bool flag_e =false;
	bool jmp_stay =false;
	bool left = false;
	float gravity = 0;
	int _num =0;
	int trans_num = 0; //0 기본, 1 돼지, 2 닌자

	//이펙트
	cocos2d::Sprite* ef1;
	cocos2d::Sprite* ef2[10];
	int bullet_num = 0;

	//hp바
	int hp = 500;
	Layer* hp_bar;
};


