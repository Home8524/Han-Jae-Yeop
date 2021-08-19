#pragma once
#include "setDefine.h"

using namespace cocos2d;
class cha1
{

public:

	cha1();
	~cha1();

	static cha1 *getInstance();
	
	//�÷��̾� ��������Ʈ
	Sprite* Player = Sprite::create("kirby/effect/star_effect.png");

	//�������� �浹��
	Sprite* Unit = Sprite::create("kirby/effect/star_effect.png");

	//po2 �ҷ������ /ĳ���ͽ�������Ʈ �����
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
	int trans_num = 0; //0 �⺻, 1 ����, 2 ����

	//����Ʈ
	cocos2d::Sprite* ef1;
	cocos2d::Sprite* ef2[10];
	int bullet_num = 0;

	//hp��
	int hp = 500;
	Layer* hp_bar;
};


