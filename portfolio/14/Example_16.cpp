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
		- ���� Scene�� ������ �״�� ������ ä �ٸ� Scene���� �̵��Ѵ�.
		- �̵��� Scene���� �ǵ��ƿ͵� ������ �ҽǵ��� �ʴ� Ư¡�� �ִ�.
	*/

	//��� ��ȯ ȿ���� ����� ���� ����
	static int nIndex1 = 0;
	
	// Example_16_1�� �̵��ϴ� pushScene
	auto scene = po::createScene();

	//Director Ŭ������ ����Ͽ� Scene �̵�
	Director::getInstance()->
		pushScene(createTransition(nIndex1, 1.0f, scene));

	//���� ���� ����
	
}


cocos2d::TransitionScene * Example_16::createTransition(int nIndex, float t, cocos2d::Scene * s)
{
	Director::getInstance()->setDepthTest(false);

	switch (nIndex)
	{
		//���̵��ξƿ� : ��
	case 1: return TransitionFade::create(t, s);
		//���̵��ξƿ� : ȭ��Ʈ
	case 0: return TransitionFade::create(t, s, Color3B::WHITE);


	default: break;

	}
}
