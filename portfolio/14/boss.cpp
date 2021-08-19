#include "boss.h"
USING_NS_CC;

cocos2d::Scene * boss::createScene()
{
	return boss::create();
}

bool boss::init()
{
	if(!Scene::init()) return false;

	auto logo2 = Sprite::create("kirby/map/map4.png");
	logo2->setPosition(Vec2(640, 360));
	logo2->setContentSize(Size(1280, 720));
	this->addChild(logo2);

	auto logo1 = Sprite::create("kirby/map/map3.png");
	logo1->setPosition(Vec2(640, 360));
	logo1->setContentSize(Size(1280, 720));
	this->addChild(logo1);

	return true;
}
