#include "Stage.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "Player.h"
#include "EnemyHole.h"
#include "HammerEffect.h"
#include "ObjectFactory.h"
#include "CollisionManager.h"
#include "Stage_Back.h"


Stage::Stage() : m_pPlayer(nullptr)
{

}

Stage::~Stage()
{
	Release();
}

void Stage::Initialize()
{
	m_pPlayer = ObjectManager::GetInstance()->GetPlayer();

	// ** ������Ʈ �Ŵ������� �Ѿ� ����Ʈ�� �޾ƿ�. (�����ͷ�...)
	BulletList = ObjectManager::GetInstance()->GetBulletList();

	// ** ������Ʈ �Ŵ������� ���� ����Ʈ�� �޾ƿ�. (�����ͷ�...)
	EnemyList = ObjectManager::GetInstance()->GetEnemyList();
	
	State_Back = new Stage_Back;
	State_Back->Initialize();

	m_pEffect = new HammerEffect;
	m_pEffect->Initialize();
	Cnt = 0;
	Cnt_max = 16;
	TileHeightCnt = 4;
	TileWidthCnt = 4;
	/*
	// ** �� ����
	for (int i = 0; i < 8; ++i)
	{
		Object* pObj = new Enemy;
		pObj->Initialize();

		Vector3 RandomPos = Vector3(
			float(rand() % (WindowsWidth - 120) + 60),
			float(rand() % (WindowsHeight - 120) + 60));

		pObj->SetPosition(RandomPos.x, RandomPos.y);
		pObj->SetColliderPosition(RandomPos.x, RandomPos.y);

		EnemyList->push_back(pObj);
	}
	Vector3 Center = Vector3(WindowsWidth / 2.0f, WindowsHeight / 2.0f);

	for (int y = 0; y < TileHeightCnt; ++y)
	{
		for (int x = 0; x < TileWidthCnt; ++x)
		{
			Object* pObj = new EnemyHole;
			pObj->Initialize();

			pObj->SetPosition(
				(Center.x - ((TileWidthCnt / 2) * pObj->GetScale().x )) + pObj->GetScale().x * x,
				(Center.y - ((TileHeightCnt / 2) * pObj->GetScale().y)) + pObj->GetScale().y * y);

			EnemyList->push_back(pObj);
		}
	}

	*/
	
	ImageList = Object::GetImageList();
}

void Stage::Update()
{
	m_pPlayer->Update();

	if (m_pEffect->GetActive())
		m_pEffect->Update();
	if (((Player*)m_pPlayer)->GetSwing())
	{
		m_pEffect->SetActive(true);
		m_pEffect->Initialize();
	}
	/*
	
	for (vector<Object*>::iterator iter = EnemyList->begin();
		iter != EnemyList->end(); )
	{
		int Result = (*iter)->Update();

		if (CollisionManager::EllipseCollision(
			m_pPlayer->GetColliderTransform(),
			(*iter)->GetColliderTransform()))
		{
			if (((Player*)m_pPlayer)->GetSwing())
				Result = 1;
		}

		if (Result == 1)
			iter = EnemyList->erase(iter);
		else
			++iter;
	}
	*/

	for (vector<Object*>::iterator iter = EnemyList->begin();
		iter != EnemyList->end(); ++iter)
		(*iter)->Update();



	// ** �Ѿ� ����Ʈ�� progress
	for (vector<Object*>::iterator iter = BulletList->begin();
		iter != BulletList->end(); )
	{
		// ** �Ѿ��� ȭ�� ���� �Ѿ�� �Ǹ� reutrn 1 �� ��ȯ �ϰ�, 
		// ** iResult == 1�̸� �Ѿ��� ������.
		int iResult = (*iter)->Update();

		// ** Enemy ����Ʈ�� progress
		for (vector<Object*>::iterator iter2 = EnemyList->begin();
			iter2 != EnemyList->end(); )
		{
			// ** �浹 ó��
			if (CollisionManager::EllipseCollision((*iter), (*iter2)))
			{
				// ** ���� ����
				iter2 = EnemyList->erase(iter2);

				Cnt++;

				// ** ������ ������Ʈ�� �����ѵ�
				iResult = 1;

				// ** ���� �ݺ����� Ż��.
				// ** ���� : �Ѿ� 1���� ������ 1���� �����ϱ� ����. 
				break;

				//** break �� �ȵǸ� �Ѿ��� ������ ���������� �浹ü�� �������϶� ��� �浹�� ������.
			}
			else
				++iter2;
		}

		// ** �Ѿ��� �����ϴ� ����.
		if (iResult == 1)
			iter = BulletList->erase(iter);
		else
			++iter;
	}
	
}

void Stage::Render(HDC _hdc)
{
	State_Back->Render(ImageList["Buffer"]->GetMemDC());

	
	for (vector<Object*>::iterator iter = EnemyList->begin();
		iter != EnemyList->end(); ++iter)
		(*iter)->Render(ImageList["Buffer"]->GetMemDC());
	

	for (vector<Object*>::iterator iter = BulletList->begin();
		iter != BulletList->end(); ++iter)
		(*iter)->Render(ImageList["Buffer"]->GetMemDC());


	if (m_pEffect->GetActive())
		m_pEffect->Render(ImageList["Buffer"]->GetMemDC());


	m_pPlayer->Render(ImageList["Buffer"]->GetMemDC());



	BitBlt(_hdc,
		0, 0,
		WindowsWidth,
		WindowsHeight,
		ImageList["Buffer"]->GetMemDC(),
		0, 0, 
		SRCCOPY);
}

void Stage::Release()
{

}