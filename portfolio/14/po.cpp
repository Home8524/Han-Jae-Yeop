#include "po.h"
#include "boss.h"
#include "setDefine.h"
USING_NS_CC;

cocos2d::Scene * po::createScene()
{
	return po::create();
}

bool po::init()
{

	if (!Scene::init()) return false;
	

	//ĳ���� �̵� ����
	layer1 = Layer::create();
	this->addChild(layer1);
	repeat_nop = 0;

	//���
	auto back1 = Sprite::create("kirby/map/map1.png");
	back1->setPosition(Vec2(1280, 360));
	back1->setScaleX(3.0f);
	back1->setScaleY(3.75f);
	layer1->addChild(back1);


#pragma region �浹�� ���̾�
	layer2 = LayerColor::create(Color4B::WHITE);
	layer2->setContentSize(Size(1200 * 2, 103));
	layer2->setPosition(Vec2(0, 0));
	layer1->addChild(layer2);
	layer2->setVisible(false);
	//�浹���� ���̾� 1

	layer3 = LayerColor::create(Color4B::BLUE);
	layer3->setContentSize(Size(250, 285));
	layer3->setPosition(Vec2(1176, 0));
	layer1->addChild(layer3);
	layer3->setVisible(false);
	//�浹���� ���̾� 2
	layer4 = LayerColor::create(Color4B::GREEN);
	layer4->setContentSize(Size(70, 360));
	layer4->setPosition(Vec2(1390, 0));
	layer1->addChild(layer4);
	layer4->setVisible(false);
	//�浹���� ���̾� 3
	layer5 = LayerColor::create(Color4B::GREEN);
	layer5->setContentSize(Size(70, 360));
	layer5->setPosition(Vec2(1680, 0));
	layer1->addChild(layer5);
	layer5->setVisible(false);
	//�浹���� ���̾� 4
	layer6 = LayerColor::create(Color4B::WHITE);
	layer6->setContentSize(Size(700, 285));
	layer6->setPosition(Vec2(1750, 0));
	layer1->addChild(layer6);
	layer6->setVisible(false);
	//�浹���� ���̾� 4

	playerlayer = LayerColor::create(Color4B::WHITE);
	playerlayer->setContentSize(Size(250, 200));
	playerlayer->setPosition(Vec2(0, 60));
	layer1->addChild(playerlayer);
	playerlayer->setVisible(false);
	//�÷��̾� �ֺ� ���̾�
	
#pragma endregion


	//�÷��̾� ĳ����
	PLAYER = PO2->make1();
	PLAYER->setPosition(Vec2(100, 142));
	layer1->addChild(PLAYER);

	//normal Ŀ�� ��������Ʈ �������� �浹 �Ǵ�
	PLAYER2 = PO2->make1();
	PLAYER2->setPosition(Vec2(100, 142));
	layer1->addChild(PLAYER2);
	PLAYER2->setVisible(false);
	//����������
	
#pragma region ����������Ʈ
	
	for (int i = 0; i < 3; i++) {
		mob_hi[i] = LayerColor::create(Color4B::WHITE);
		hit[i] = LayerColor::create(Color4B::GREEN);
		mob_hi[i]->setContentSize(Size(200, 170));
		hit[i]->setContentSize(Size(100, 100));
		layer1->addChild(hit[i]);
		layer1->addChild(mob_hi[i]);
		mob_hi[i]->setVisible(false);
		hit[i]->setVisible(false);
		Mob[i] = PO2->mob_createwalk();
		layer1->addChild(Mob[i]);
		mob_alive[i] = true;
		m_n[i] = 0;
		mob_hp[i] = 4;
	}
	Mob[0]->setPosition(Vec2(400, 142));
	mob_hi[0]->setPosition(Vec2(300, 80));
	Mob[1]->setPosition(Vec2(700, 142));
	mob_hi[1]->setPosition(Vec2(600, 80));
	Mob[2]->setPosition(Vec2(1900, 324));
	mob_hi[2]->setPosition(Vec2(1800, 262));

	hit[0]->setPosition(Vec2(350, 100));
	hit[1]->setPosition(Vec2(650, 100));
	hit[2]->setPosition(Vec2(1850, 282));

	mob_timer1 = 0;
	mob_timer2 = 0;
	mob_timer3 = 0;
	b_num = 0;
	
	this->schedule(schedule_selector(po::walkloading));
#pragma endregion
	
	//�׵θ� �� hp ǥ��â
	auto backsprite = Sprite::create("kirby/map/test_hp.png");
	backsprite->setPosition(Vec2(640, 360));
	backsprite->setScaleY(3.8f);
	backsprite->setScaleX(5.0f);
	this->addChild(backsprite);

	//hp ��
	hp_layer = LayerColor::create(Color4B::GREEN);
	hp_layer->setPosition(Vec2(655, 687));
	hp_layer->setContentSize(Size(HP,33));
	this->addChild(hp_layer);

	next = LayerColor::create(Color4B::GREEN);
	next->setPosition(Vec2(2230, 282));
	next->setContentSize(Size(100, 100));
	next->setVisible(false);
	layer1->addChild(next);

	return true;
}

void po::onEnter()
{
	Scene::onEnter();

	//�̱� ��ġ ���� �̺�Ʈ ������ �ʱ�ȭ
	_listener = EventListenerTouchOneByOne::create();

	_listener->setSwallowTouches(true);
	_listener->onTouchBegan = CC_CALLBACK_2(po::onTouchBegan, this);
	
	
	//Ű���� �̺�Ʈ ������
	_listener2 = EventListenerKeyboard::create();

	

	//�̺�Ʈ �ݹ��Լ��� �Ҵ�
	_listener2->onKeyPressed = CC_CALLBACK_2(po::onKeyPressed, this);
	_listener2->onKeyReleased = CC_CALLBACK_2(po::onKeyReleased, this);
	
	

	//��ġ �̺�Ʈ�� �켱 ������ ȭ�鿡 �׷��� ������� �Ѵ�.
	_eventDispatcher->addEventListenerWithSceneGraphPriority(_listener, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(_listener2, this);
}

void po::onExit()
{
	//�ش� Scene���� ��� �� �̺�Ʈ �����ʸ� ����
	_eventDispatcher->removeEventListener(_listener);
	_eventDispatcher->removeEventListener(_listener2);
	Scene::onExit();
}

bool po::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * event)
{
	auto touchPoint = touch->getLocation();
	log("PosX = %.1f, PosY = %.1f", touchPoint.x, touchPoint.y);
	return true;
}
void po::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event)
{

	switch (keyCode)
	{

		//�����̵�
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		flag_left = true;
		left_stay = true;

		//������ �̵��� �߻��Ҽ� �־� �ߺ�ȣ���� �����ϱ� ���� ������ ��ȣ��
		this->unschedule(schedule_selector(po::startmoveing));
		this->schedule(schedule_selector(po::startmoveing));
		break;

		//�����̵�
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		flag_right = true;
		left_stay = false;

		this->unschedule(schedule_selector(po::startmoveing));
		this->schedule(schedule_selector(po::startmoveing));
		break;
	case EventKeyboard::KeyCode::KEY_UP_ARROW:
		this->nextscene();
		
		break;
		//���̾�ǥ��
	case EventKeyboard::KeyCode::KEY_F3:
		layer_sight++;
		this->layerscan();
		break;

#pragma region ����
	case EventKeyboard::KeyCode::KEY_SPACE:
		//jump_stay : �������� �ѹ� ������ ������ ��� �ȵ����Ϸ������
		//flag_jump�� �Ʊ� �����ؼ� true�� jump stay�� ���������״� true�� ��
		if (flag_jump) jump_stay = true;
		else jump_stay = false;

		//���� ��������Ʈ�� ����
		
		PLAYER->removeFromParent();
		if (Trans == 2) PLAYER = PO2->c_create3();
		else if(Trans ==0) PLAYER = PO2->make3();
		PLAYER->setPosition(PLAYER2->getPosition());
		layer1->addChild(PLAYER);

		flag_jump = true;
		GRA = 0.0f;
		PLAYER->setPositionY(PLAYER->getPositionY() + 50);
		PLAYER2->setPositionY(PLAYER2->getPositionY() + 50);

		//�������� �ѹ��� ������ ���� jump_stay�� false�϶�(ó��������)
		if(!jump_stay)	this->schedule(schedule_selector(po::fly));
		break;
#pragma endregion
		//�Ա�
	case EventKeyboard::KeyCode::KEY_Z:
		this->eatStart();
		break;

#pragma region ���ݸ��
	case EventKeyboard::KeyCode::KEY_X:
		if (Trans==2) {

			PLAYER->removeFromParent();
			PLAYER = PO2->c_create4();
			PLAYER->setPosition(PLAYER2->getPosition());
			layer1->addChild(PLAYER);

			this->slash();
		}
		break;
#pragma endregion
#pragma region ���ݸ��2
	case EventKeyboard::KeyCode::KEY_C:
		if (Trans==2) {

			PLAYER->removeFromParent();
			PLAYER = PO2->c_create5();
			PLAYER->setPosition(PLAYER2->getPosition());
			layer1->addChild(PLAYER);

			effect2[b_num] = Sprite::create("kirby/effect/kunai.png");
			effect2[b_num]->setPosition(PLAYER->getPosition());
			effect2[b_num]->setScale(2.5f);
			layer1->addChild(effect2[b_num]);

			if (!left_stay) {
				effect2[b_num]->setPositionX(effect2[b_num]->getPositionX() + 100);
				auto myActionBy = MoveBy::create(3.0f, Vec2(3000, 0));
				effect2[b_num]->runAction(myActionBy);
			}
			else {
				effect2[b_num]->setPositionX(effect2[b_num]->getPositionX() - 100);
				effect2[b_num]->setFlipX(true);
				auto myActionBy = MoveBy::create(3.0f, Vec2(-3000, 0));
				effect2[b_num]->runAction(myActionBy);
			}
			b_num++;
			if (b_num == 10) b_num = 0;
			this->unschedule(schedule_selector(po::bullet2));
			this->schedule(schedule_selector(po::bullet2));
		}
		break;
#pragma endregion
	}
}

void po::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event)
{
	flag_left = false;
	flag_right = false;
	NUM = 0;

	this->stopmoveing();
}

void po::startmoveing(float dt)
{
	
	if (!coltest()) { 
		Move->movemove();
	}
}

void po::stopmoveing()
{
	if (!flag_jump&&!flag_eat) {
	
	PLAYER->removeFromParent();
	if(Trans==0)PLAYER = PO2->make1();
	else if(Trans==2) PLAYER = PO2->c_create1();
	if(left_stay) PLAYER->setFlipX(true);
	PLAYER->setPosition(PLAYER2->getPosition());
	layer1->addChild(PLAYER);
	this->unschedule(schedule_selector(po::startmoveing));
	}
}

//���� ����
void po::walkloading(float dt)
{
	//�������� ������ ����
	if (!mob_alive[0] && !mob_alive[1] && !mob_alive[2]) this->unschedule(schedule_selector(po::walkloading));
	int temp1 = mob_timer1;
	int temp2 = mob_timer2;
	int temp3 = mob_timer3;

	
	Point x1 = Mob[0]->getPosition();
	Point x2 = Mob[1]->getPosition();
	Point x3 = Mob[2]->getPosition();

	
	for (int i = 0; i < 3; i++)
	{
		mob_hi[i]->setPositionX(Mob[i]->getPositionX() - 100);
		hit[i]->setPositionX(Mob[i]->getPositionX() - 50);
	}
	
	bool col1 = mob_hi[0]->getBoundingBox().intersectsRect(PLAYER->getBoundingBox());
	bool col2 = mob_hi[1]->getBoundingBox().intersectsRect(PLAYER->getBoundingBox());
	bool col3 = mob_hi[2]->getBoundingBox().intersectsRect(PLAYER->getBoundingBox());
	
	if (col1&&mob_alive[0]) {
		//�÷��̾�� ������ ��ġ�� ���ؼ� �¿������
		int ck1 = Mob[0]->getPositionX();
		int ck2 = PLAYER->getPositionX();
		//���Ͱ� ����ְ� ���ͷ��̾�� �÷��̾ �浹�ߴٸ�
		//���͸� ���ݸ��� ��ȯ
		if (m_n[0] != 1) {
			Mob[0]->removeFromParent();
			Mob[0] = PO2->mob_createatk();
			Mob[0]->setPosition(x1);
			layer1->addChild(Mob[0]);
			if (ck2 < ck1) Mob[0]->setFlippedX(true);
			else Mob[0]->setFlippedX(false);
			m_n[0] = 1;
		}
		//���ݸ���϶� �浹��
		bool dmg = hit[0]->getBoundingBox().intersectsRect(PLAYER->getBoundingBox());
		if (dmg)
		{
			if (HP != 0) HP -= 5;
			hp_layer->setContentSize(Size(HP, 33));
		}
	}
	
	 else if (!col1&&mob_alive[0]) {
		//���Ͱ� �������,���浹�� �̵����� ��ȯ
		if (m_n[0]!= 0) {
			Mob[0]->removeFromParent();
			Mob[0] = PO2->mob_createwalk();
			Mob[0]->setPosition(x1);
			layer1->addChild(Mob[0]);
			m_n[0]= 0;
		}
		temp1 = PO2->mob_walk(Mob[0], mob_timer1);
	}
	
	if (col2&&mob_alive[1]) {
		//�÷��̾�� ������ ��ġ�� ���ؼ� �¿������
		int ck1 = Mob[1]->getPositionX();
		int ck2 = PLAYER->getPositionX();

		//���Ͱ� ����ְ� ���ͷ��̾�� �÷��̾ �浹�ߴٸ�
		//���͸� ���ݸ��� ��ȯ
		if (m_n[1] != 1) {
			Mob[1]->removeFromParent();
			Mob[1] = PO2->mob_createatk();
			Mob[1]->setPosition(x2);
			layer1->addChild(Mob[1]);
			m_n[1] = 1;
			if (ck2 < ck1) Mob[1]->setFlippedX(true);
			else Mob[1]->setFlippedX(false);
		}
		//���ݸ���϶� �浹��
		bool dmg = hit[1]->getBoundingBox().intersectsRect(PLAYER->getBoundingBox());
		if (dmg)
		{
			if (HP != 0) HP -= 5;
			hp_layer->setContentSize(Size(HP, 33));
		}
	}
	else if (!col2&&mob_alive[1]) {
		//���Ͱ� �������,���浹�� �̵����� ��ȯ
		if (m_n[1] != 0) {
			Mob[1]->removeFromParent();
			Mob[1] = PO2->mob_createwalk();
			Mob[1]->setPosition(x2);
			m_n[1] = 0;
			layer1->addChild(Mob[1]);
		}
		temp2 = PO2->mob_walk(Mob[1], mob_timer2);
	}

	if (col3&&mob_alive[2]) {
		//�÷��̾�� ������ ��ġ�� ���ؼ� �¿������
		int ck1 = Mob[2]->getPositionX();
		int ck2 = PLAYER->getPositionX();

		//���Ͱ� ����ְ� ���ͷ��̾�� �÷��̾ �浹�ߴٸ�
		//���͸� ���ݸ��� ��ȯ
		if (m_n[2] != 1) {
			Mob[2]->removeFromParent();
			Mob[2] = PO2->mob_createatk();
			Mob[2]->setPosition(x3);
			layer1->addChild(Mob[2]);
			m_n[2] = 1;
			if (ck2 < ck1) Mob[2]->setFlippedX(true);
			else Mob[2]->setFlippedX(false);
		}
		//���ݸ���϶� �浹��
		bool dmg = hit[2]->getBoundingBox().intersectsRect(PLAYER->getBoundingBox());
		if (dmg)
		{
			if (HP != 0) HP -= 5;
			hp_layer->setContentSize(Size(HP, 33));
		}

	}
	else if (!col3&&mob_alive[2]) {
		//���Ͱ� �������,���浹�� �̵����� ��ȯ
		if (m_n[2] != 0) {
			Mob[2]->removeFromParent();
			Mob[2] = PO2->mob_createwalk();
			Mob[2]->setPosition(x3);
			layer1->addChild(Mob[2]);
			m_n[2] = 0;
		}
		temp3 = PO2->mob_walk(Mob[2], mob_timer3);
	}
	

	mob_timer1 = temp1;
	mob_timer2 = temp2;
	mob_timer3 = temp3;

}

//���� , star ���
void po::eatStart()
{
	//�Ա���
	if (Trans!=0)
	{
		this->c_reset();
	}
	//�Ա���
	else {
		if (!flag_eat) {
			flag_eat = true;
			PLAYER->removeFromParent();
			PLAYER = PO2->make4();
			if (left_stay) PLAYER->setFlipX(true);
			PLAYER->setPosition(PLAYER2->getPosition());
			layer1->addChild(PLAYER);
			this->schedule(schedule_selector(po::eatMob));
		}
		else {
			flag_eat = false;
			this->unschedule(schedule_selector(po::eatMob));
		}
	}
}
//������ �������� �ð�ȿ���� �ֱ����� �׼��Լ� ����
void po::cmp(int a, int b, int i)
{
	mob_hi[i]->setContentSize(Size(1, 1));
	Trans = 2;

	this->unschedule(schedule_selector(po::walkloading));
	int sum;
	if (a < b) sum = -5;
	else sum = 5;
	auto act1 = MoveBy::create(0.5f, Vec2(sum, 0));
	auto act2 = RotateBy::create(0.5f, 360);
	auto act3 = Sequence::create(act2, act1, nullptr);
	Mob[i]->runAction(act3);
}

//�Ա� ����
void po::eatMob(float dt)
{
	bool col1 = playerlayer->getBoundingBox().intersectsRect(Mob[0]->getBoundingBox());
	bool col2 = playerlayer->getBoundingBox().intersectsRect(Mob[1]->getBoundingBox());
	bool col3 = playerlayer->getBoundingBox().intersectsRect(Mob[2]->getBoundingBox());
	int a = PLAYER->getPositionX();
	int b = Mob[0]->getPositionX();
	int c = Mob[1]->getPositionX();
	int d = Mob[2]->getPositionX();

	if (col1)
	{
		this->cmp(a, b, 0);
		bool tmp = PLAYER->getBoundingBox().intersectsRect(Mob[0]->getBoundingBox());
		if (tmp) {
			this->c_reset2(0);
		}
	}
	else if (col2)
	{
		this->cmp(a, b, 1);
		bool tmp = PLAYER->getBoundingBox().intersectsRect(Mob[1]->getBoundingBox());
		if (tmp) {
			this->c_reset2(1);
		}
	}
	else if (col3)
	{
		this->cmp(a, b, 2);
		bool tmp = PLAYER->getBoundingBox().intersectsRect(Mob[2]->getBoundingBox());
		if (tmp) {
			this->c_reset2(2);
		}
	}

}

//��������,���Ż��¿��� �����Ǿ� �������·� ���ƿ��� ���ϳ� ������ �Լ�
void po::c_reset()
{
	//����Ʈ ���� �� �߻�
	effect1 = Sprite::create("kirby/effect/star_effect.png");
	effect1->setPosition(PLAYER->getPosition());
	effect1->setScale(2.5f);
	layer1->addChild(effect1);
	if (!left_stay) {
		effect1->setPositionX(effect1->getPositionX() + 100);
		auto myActionBy = MoveBy::create(3.0f, Vec2(3000, 0));
		effect1->runAction(myActionBy);
	}
	else {
		effect1->setPositionX(effect1->getPositionX() - 100);
		auto myActionBy = MoveBy::create(3.0f, Vec2(-3000, 0));
		effect1->runAction(myActionBy);
	}

	auto myActionBy2 = RotateBy::create(2.0f, 1080);

	effect1->runAction(myActionBy2);
	this->schedule(schedule_selector(po::bullet1));
	this->unschedule(schedule_selector(po::walkloading));
	Trans = 0;
	
	this->schedule(schedule_selector(po::walkloading));
}

//���͸� �Ծ��� �� ���͸� ����ó���ϰ� ����
void po::c_reset2(int i)
{
	mob_alive[i] = false;
	//���� ��������Ʈ ���
	Mob[i]->setPosition(Vec2(-1000, -1000));

	//���� ��ġ ��ǥ ����
	

	PLAYER->removeFromParent();
	PLAYER = PO2->c_create1();

	PLAYER->setPosition(PLAYER2->getPosition());
	PLAYER->setPositionY(PLAYER->getPositionY() + 10);

	layer1->addChild(PLAYER);

	flag_eat = false;
	this->schedule(schedule_selector(po::walkloading));
	this->unschedule(schedule_selector(po::eatMob));
}

//�� �߻�(����� ����������)
void po::bullet1(float dt)
{
	bool col1 = effect1->getBoundingBox().intersectsRect(Mob[0]->getBoundingBox());
	bool col2 = effect1->getBoundingBox().intersectsRect(Mob[1]->getBoundingBox());
	bool col3 = effect1->getBoundingBox().intersectsRect(Mob[2]->getBoundingBox());
	int tmp = effect1->getPositionX();
	if (tmp < 0 && tmp>3000) {
		layer1->removeChild(effect1);
		this->unschedule(schedule_selector(po::bullet1));
	}

	if (col1) {
		auto act1 = Place::create(Vec2(-1000, -1000));
		auto act2 = Blink::create(1.0f, 2);
		auto act3 = Sequence::create(act2, act1, nullptr);
		Mob[0]->runAction(act3);

		mob_alive[0] = false;
		layer1->removeChild(effect1);
		this->unschedule(schedule_selector(po::bullet1));
	}
	if (col2) {
		auto act1 = Place::create(Vec2(-1000, -1000));
		auto act2 = Blink::create(1.0f, 2);
		auto act3 = Sequence::create(act2, act1, nullptr);
		Mob[1]->runAction(act3);

		mob_alive[1] = false;
		layer1->removeChild(effect1);
		this->unschedule(schedule_selector(po::bullet1));
	}
	if (col3) {
		auto act1 = Place::create(Vec2(-1000, -1000));
		auto act2 = Blink::create(1.0f, 2);
		auto act3 = Sequence::create(act2, act1, nullptr);
		Mob[2]->runAction(act3);

		mob_alive[2] = false;
		layer1->removeChild(effect1);
		this->unschedule(schedule_selector(po::bullet1));
	}

}

//ǥâ �߻�
void po::bullet2(float dt)
{
	bool col1 = false;
	bool col2 = false;
	bool col3 = false;

	for (int i = 0; i < b_num; i++) {
	if(mob_alive[0]) col1 = effect2[i]->getBoundingBox().intersectsRect(Mob[0]->getBoundingBox());
	if(mob_alive[1]) col2 = effect2[i]->getBoundingBox().intersectsRect(Mob[1]->getBoundingBox());
	if(mob_alive[2]) col3 = effect2[i]->getBoundingBox().intersectsRect(Mob[2]->getBoundingBox());

	int tmp = effect2[i]->getPositionX();
	if (tmp < 0 && tmp>3000) {
		effect2[i]->setPosition(Vec2(-1000, -1000));
		this->unschedule(schedule_selector(po::bullet2));
	}
	if (col1) {
		mob_hp[0] -= 1;
		auto myAction = Blink::create(1.0f, 2);
		Mob[0]->runAction(myAction);
		if (mob_hp[0] == 0)
		{
			mob_alive[0] = false;
			Mob[0]->setPosition(Vec2(-1000, -1000));
		}
		effect2[i]->setPosition(Vec2(-1000, -1000));
		this->unschedule(schedule_selector(po::bullet2));
	}
	if (col2) {
		//log("hp :%d ", mob_hp[1]);
		mob_hp[1] -= 1;
		auto myAction = Blink::create(1.0f, 2);
		Mob[1]->runAction(myAction);
		if (mob_hp[1] == 0)
		{
			mob_alive[1] = false;
			Mob[1]->setPosition(Vec2(-1000, -1000));
		}
		effect2[i]->setPosition(Vec2(-1000, -1000));
		this->unschedule(schedule_selector(po::bullet2));
	}
	if (col3) {
		mob_hp[2] -= 1;
		auto myAction = Blink::create(1.0f, 2);
		Mob[2]->runAction(myAction);
		if (mob_hp[2] == 0)
		{
			mob_alive[2] = false;
			Mob[2]->setPosition(Vec2(-1000, -1000));
		}
		effect2[i]->setPosition(Vec2(-1000, -1000));
		this->unschedule(schedule_selector(po::bullet2));
	}
	}
	
}

//������ ���ݽ� ������ ����
void po::slash()
{
	bool col1 = PLAYER->getBoundingBox().intersectsRect(Mob[0]->getBoundingBox());
	bool col2 = PLAYER->getBoundingBox().intersectsRect(Mob[1]->getBoundingBox());
	bool col3 = PLAYER->getBoundingBox().intersectsRect(Mob[2]->getBoundingBox());
	if (col1) {
		mob_hp[0] -= 2;
		auto myAction = Blink::create(1.0f, 3);
		Mob[0]->runAction(myAction);
		if (mob_hp[0] == 0)
		{
		mob_alive[0] = false;
		Mob[0]->setPosition(Vec2(-1000, -1000));
		}
	}
	else if (col2) {
		mob_hp[1] -= 2;
		auto myAction = Blink::create(1.0f, 3);
		Mob[1]->runAction(myAction);
		if (mob_hp[1] == 0)
		{
			mob_alive[1] = false;
			Mob[1]->setPosition(Vec2(-1000, -1000));
		}
	}
	else if (col3) {
		mob_hp[2] -= 2;
		auto myAction = Blink::create(1.0f, 3);
		Mob[2]->runAction(myAction);
		if (mob_hp[2] == 0)
		{
			mob_alive[2] = false;
			Mob[2]->setPosition(Vec2(-1000, -1000));
		}
	}

}

//�¿� �̵��� ���̾�� �浹�ϸ� �������
bool po::coltest()
{

	bool col1 = layer2->getBoundingBox().intersectsRect(PLAYER2->getBoundingBox());
	bool col2 = layer3->getBoundingBox().intersectsRect(PLAYER2->getBoundingBox());
	bool col3 = layer4->getBoundingBox().intersectsRect(PLAYER2->getBoundingBox());
	bool col4 = layer5->getBoundingBox().intersectsRect(PLAYER2->getBoundingBox());
	bool col5 = layer6->getBoundingBox().intersectsRect(PLAYER2->getBoundingBox());

	//�÷��̾ �浹üũ�� ���̾�� �浹�� ���� true �ƴҽ� false

	
	//���� x �� �浹����
	
		if (col1||col2 || col3 || col4||col5)
		{
			int sb;
			if (flag_right) sb = -3;
			else sb = 3;
			if (col2&&PLAYER->getPositionY() < 285) {
				int  tmp = PLAYER->getPositionX();
				PLAYER->setPositionX(tmp + sb);
				PLAYER2->setPositionX(tmp + sb);
				return true;
			}
			else if (col3 || col4) {
				if (PLAYER->getPositionY() < 360) {
				int  tmp = PLAYER->getPositionX();
				PLAYER->setPositionX(tmp + sb);
				PLAYER2->setPositionX(tmp + sb);
				return true;
				}
			}
		} //�¿� ���� �΋H���� ƨ�ܳ�
		else if (!col1 && !col2 && !col3 && !col4 && !col5)
		{
			if (repeat_nop==0&&!flag_jump)
			{
				//log("col pro");
				//log("%d %d %d %d %d", col1, col2, col3, col4, col5);
				
				PLAYER->removeFromParent();
				if (Trans == 2) PLAYER = PO2->c_create3();
				else PLAYER = PO2->make3();
				PLAYER->setPosition(PLAYER2->getPosition());
				layer1->addChild(PLAYER);
				flag_jump = true;
				GRA = 0.0f;

				this->unschedule(schedule_selector(po::startmoveing));
				this->schedule(schedule_selector(po::fly));
				repeat_nop = 1;
			}
		}//���߿���
	
	return false;
}

/*
		�񱳿����� �����ص� PLAYER2 (�⺻Ŀ��������Ʈ) �� ��
		ǳ��Ŀ������ ��������Ʈ ũ�����̶����� ������ �̷�����
*/
void po::fly(float dt)
{
	
	bool col1 = layer2->getBoundingBox().intersectsRect(PLAYER2->getBoundingBox());
	bool col2 = layer3->getBoundingBox().intersectsRect(PLAYER2->getBoundingBox());
	bool col3 = layer4->getBoundingBox().intersectsRect(PLAYER2->getBoundingBox());
	bool col4 = layer5->getBoundingBox().intersectsRect(PLAYER2->getBoundingBox());
	bool col5 = layer6->getBoundingBox().intersectsRect(PLAYER2->getBoundingBox());

	if (col1 || col2 || col3 || col4 || col5)
	{
		//log("fly");
		//log("%d %d %d %d %d", col1, col2, col3, col4, col5);
		flag_jump = false;
		jump_stay = false;

		repeat_nop = 0;
		
		PLAYER->removeFromParent();
		if(Trans==0) PLAYER = PO2->make1();
		else if(Trans==2)PLAYER = PO2->c_create1();
		if (left_stay) PLAYER->setFlipX(true);
		PLAYER->setPosition(PLAYER2->getPosition());
		layer1->addChild(PLAYER);
		this->unschedule(schedule_selector(po::fly));
	}//���̾�� �浹����
	else
	{
		GRA += 0.05;
		PLAYER->setPositionY(PLAYER->getPositionY() - GRA);
		PLAYER2->setPositionY(PLAYER2->getPositionY() - GRA);
	}
}

void po::nextscene()
{
	bool tex = next->getBoundingBox().intersectsRect(PLAYER->getBoundingBox());
	if(tex)	this->doPushScene();
}

//���̾� Ȯ�ο� �Լ�
void po::layerscan()
{
	if (layer_sight % 2 != 0)
	{
		layer2->setVisible(true);
		layer3->setVisible(true);
		layer4->setVisible(true);
		layer5->setVisible(true);
		layer6->setVisible(true);
		playerlayer->setVisible(true);
		for (int i = 0; i < 3; i++)
		{
			mob_hi[i]->setVisible(true);
		}
	}//���̰�
	else
	{
		layer2->setVisible(false);
		layer3->setVisible(false);
		layer4->setVisible(false);
		layer5->setVisible(false);
		layer6->setVisible(false);
		playerlayer->setVisible(false);
		for (int i = 0; i < 3; i++)
		{
			mob_hi[i]->setVisible(false);
		}
	}//�Ⱥ��̰�
}

//���̵�
void po::doPushScene()
{
	// PushScene
	/*
		- ���� Scene�� ������ �״�� ������ ä �ٸ� Scene���� �̵��Ѵ�.
		- �̵��� Scene���� �ǵ��ƿ͵� ������ �ҽǵ��� �ʴ� Ư¡�� �ִ�.
	*/

	//��� ��ȯ ȿ���� ����� ���� ����
	static int nIndex1 = 0;

	// Example_16_1�� �̵��ϴ� pushScene
	auto scene = boss::createScene();

	//Director Ŭ������ ����Ͽ� Scene �̵�
	Director::getInstance()->
		pushScene(createTransition(nIndex1, 1.0f, scene));

	//���� ���� ����

}


cocos2d::TransitionScene * po::createTransition(int nIndex, float t, cocos2d::Scene * s)
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
