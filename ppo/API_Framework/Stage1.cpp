#include "Stage1.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"
#include "Stage1_Back.h"
#include "Player.h"
#include "Enemy.h"
#include "Enemy2.h"
#include "Boss.h"
#include "CollisionManager.h"

Stage1::Stage1()
{

}

Stage1::~Stage1()
{
	Release();
}

void Stage1::Initialize()
{
	State_Back = new Stage1_Back;
	State_Back->Initialize();
	int a = 0;
	Object::SetMobNum(a);
	EnemyList = ObjectManager::GetInstance()->GetEnemyList();
	// ** �� ����
	for (int i = 0; i < 8; ++i)
	{
		Object* pObj = new Enemy;
		pObj->Initialize();

		Vector3 RandomPos = Vector3(
			float(rand() % (WindowsWidth-120) + 60),
			float(rand()%200+1)*-1);

		pObj->SetPosition(RandomPos.x, RandomPos.y);
		pObj->SetColliderPosition(RandomPos.x, RandomPos.y);

		EnemyList->push_back(pObj);
	}
	MobCnt = 8;
	//StageCnt = 0~2 ->mob1 , 3~5 -> mob2 6> boss
	StageCnt = 7;
	Time = GetTickCount64();
	ImageList = Object::GetImageList();
	m_pPlayer = ObjectManager::GetInstance()->GetPlayer();
	BulletList = ObjectManager::GetInstance()->GetBulletList();
	EnemyBulletList = ObjectManager::GetInstance()->GetEnemyBulletList();
}

void Stage1::Update()
{
	int tmp;
	tmp = State_Back->Update();

	m_pPlayer->Update();

	if (GetAsyncKeyState('Z') && tmp == 1 && Time + 100 < GetTickCount64()) {

		SceneManager::GetInstance()->SetScene(SCENEID::LEVEL);
		Time = GetTickCount64();
	}


	for (vector<Object*>::iterator iter = EnemyList->begin();
		iter != EnemyList->end(); ++iter)
		(*iter)->Update();

	// ** �Ѿ� ����Ʈ�� progress
	for (vector<Object*>::iterator iter = EnemyBulletList->begin();
		iter != EnemyBulletList->end(); )
	{
		// ** �Ѿ��� ȭ�� ���� �Ѿ�� �Ǹ� reutrn 1 �� ��ȯ �ϰ�, 
		// ** iResult == 1�̸� �Ѿ��� ������.
		int iResult = (*iter)->Update();
		// ** Enemy ����Ʈ�� progress
		// ** �浹 ó��
			if (CollisionManager::EllipseCollision((*iter), m_pPlayer))
			{
				
				iResult = 1;
			}
		

		// ** �Ѿ��� �����ϴ� ����.
		if (iResult == 1)
			iter = EnemyBulletList->erase(iter);
		else
			++iter;
	}

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
				int tmp = (*iter2)->GetHp();
				tmp--;
				(*iter2)->SetHp(tmp);
				if (tmp == 0)
				{
				// ** ���� ����
				iter2 = EnemyList->erase(iter2);
				MobCnt--;

				}
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

	if (MobCnt == 0)
	{
		//mob1
		if (StageCnt >= 0 && StageCnt < 3)
		{
			for (int i = 0; i < 8; ++i)
			{
				Object* pObj = new Enemy;
				pObj->Initialize();

				Vector3 RandomPos = Vector3(
					float(rand() % (WindowsWidth-120) + 60),
					float(rand() % 200 + 1) * -1);

				pObj->SetPosition(RandomPos.x, RandomPos.y);
				pObj->SetColliderPosition(RandomPos.x, RandomPos.y);

				EnemyList->push_back(pObj);
			}
		}
		//mob2
		else if (StageCnt >= 3 && StageCnt < 6)
		{
			int a = 1;
			Object::SetMobNum(a);
			for (int i = 0; i < 8; ++i)
			{
				Object* pObj = new Enemy2;
				pObj->Initialize();

				Vector3 RandomPos = Vector3(
					float(rand() % (WindowsWidth+100)),
					float(rand() % 200 + 50));

				pObj->SetPosition(RandomPos.x, RandomPos.y);
				pObj->SetColliderPosition(RandomPos.x, RandomPos.y);

				EnemyList->push_back(pObj);
			}
		}
		MobCnt = 8;
		//boss
		if (StageCnt ==7)
		{
			MobCnt = 1;
			Object* pObj = new Boss;
			pObj->Initialize();
			EnemyList->push_back(pObj);
		}
		StageCnt++;
	}
}

void Stage1::Render(HDC _hdc)
{
	State_Back->Render(ImageList["Buffer"]->GetMemDC());
	m_pPlayer->Render(ImageList["Buffer"]->GetMemDC());
	for (vector<Object*>::iterator iter = BulletList->begin();
		iter != BulletList->end(); ++iter)
		(*iter)->Render(ImageList["Buffer"]->GetMemDC());

	for (vector<Object*>::iterator iter = EnemyList->begin();
		iter != EnemyList->end(); ++iter)
		(*iter)->Render(ImageList["Buffer"]->GetMemDC());

	for (vector<Object*>::iterator iter = EnemyBulletList->begin();
		iter != EnemyBulletList->end(); ++iter)
		(*iter)->Render(ImageList["Buffer"]->GetMemDC());

	BitBlt(_hdc,
		0, 0,
		WindowsWidth,
		WindowsHeight,
		ImageList["Buffer"]->GetMemDC(),
		0, 0,
		SRCCOPY);
}

void Stage1::Release()
{

}