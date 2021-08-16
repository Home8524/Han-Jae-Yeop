#include "Example_16.h"
#include "po.h"


USING_NS_CC;

cocos2d::Scene * Example_16::createScene()
{
	return Example_16::create();
}

bool Example_16::init()
{
	if(!Scene::init()) return false;

	auto logo1 = Sprite::create("logo/logo.png");
	auto logo2 = Sprite::create("logo/logo2.png");
	logo1->setPosition(Vec2(640, 360));
	logo1->setContentSize(Size(1280, 720));
	logo2->setPosition(Vec2(640, 360));
	this->addChild(logo1);
	this->addChild(logo2);
	logo2->setScale(2.0f);
	auto item1 = MenuItemFont::create
	("Press Game Start", CC_CALLBACK_1(Example_16::doPushScene, this));

	auto pMenu = Menu::create(item1,  nullptr);
	pMenu->alignItemsVertically();
	pMenu->setPosition(640, 100);
	this->addChild(pMenu);
	

	return true;
}

void Example_16::doPushScene(Ref * pSender)
{
	// PushScene
	/*
		- 현재 Scene의 정보를 그대로 유지한 채 다른 Scene으로 이동한다.
		- 이동한 Scene에서 되돌아와도 정보가 소실되지 않는 특징이 있다.
	*/

	//장면 전환 효과에 사용할 정적 변수
	static int nIndex1 = 0;
	
	// Example_16_1로 이동하는 pushScene
	auto scene = po::createScene();

	//Director 클래스를 사용하여 Scene 이동
	Director::getInstance()->
		pushScene(createTransition(nIndex1, 1.0f, scene));

	//변수 값을 조정
	
}


cocos2d::TransitionScene * Example_16::createTransition(int nIndex, float t, cocos2d::Scene * s)
{
	Director::getInstance()->setDepthTest(false);

	switch (nIndex)
	{
		//페이드인아웃 : 블랙
	case 1: return TransitionFade::create(t, s);
		//페이드인아웃 : 화이트
	case 0: return TransitionFade::create(t, s, Color3B::WHITE);


	default: break;

	}
}
