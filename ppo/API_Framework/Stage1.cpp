#include "Stage1.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"
#include "Stage1_Back.h"
#include "Player.h"
#include "Enemy.h"
#include "Item.h"
#include "Enemy2.h"
#include "Boss.h"
#include "CollisionManager.h"
#include "Effect1.h"

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
	// ** 적 생성
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
	StageCnt = 0;
	Time = GetTickCount64();
	Time2 = GetTickCount64();
	ImageList = Object::GetImageList();
	m_pPlayer = ObjectManager::GetInstance()->GetPlayer();
	int A = 3;
	m_pPlayer->SetHp(A);
	m_pPlayer->SetColliderPosition(Vector3(WindowsWidth / 2, WindowsHeight / 2 + 180.0f));
	m_pPlayer->SetPosition(Vector3(WindowsWidth / 2, WindowsHeight / 2+200.0f));
	BulletList = ObjectManager::GetInstance()->GetBulletList();
	EnemyBulletList = ObjectManager::GetInstance()->GetEnemyBulletList();
	ItemList = ObjectManager::GetInstance()->GetItemList();
	Flag = 0;
	Effect = new Effect1;
	Effect->Initialize();
}

void Stage1::Update()
{
	m_pPlayer->Update();
	Effect->Update();

	if (GetAsyncKeyState('X')  && Time + 100 < GetTickCount64()) {
		Flag = 1;
		SceneManager::GetInstance()->SetScene(SCENEID::LEVEL);
		Time = GetTickCount64();
	}
	if(Flag==1) SceneManager::GetInstance()->SetScene(SCENEID::STAGE);

	if (Flag == 0)
	{
		for (vector<Object*>::iterator iter = EnemyList->begin();
			iter != EnemyList->end(); ++iter)
			(*iter)->Update();

		// ** 총알 리스트의 progress
		for (vector<Object*>::iterator iter = EnemyBulletList->begin();
			iter != EnemyBulletList->end(); )
		{
			// ** 총알이 화면 밖을 넘어가게 되면 reutrn 1 을 반환 하고, 
			// ** iResult == 1이면 총알은 삭제됨.
			int iResult = (*iter)->Update();
			// ** Enemy 리스트의 progress
			// ** 충돌 처리
			if (CollisionManager::EllipseCollision((*iter), m_pPlayer))
			{
				if (Time2 + 3000 < GetTickCount64())
				{
					int Tmp = m_pPlayer->GetHp();
					Tmp--;
					m_pPlayer->SetHp(Tmp);
					Effect->SetPosition((*iter)->GetPosition());
					Effect->SetActive(true);
					if (Tmp == 0)
					{
						Flag = 1;
						break;
					}
					m_pPlayer->SetColliderPosition(Vector3(WindowsWidth / 2, WindowsHeight / 2 + 180.0f));
					m_pPlayer->SetPosition(Vector3(WindowsWidth / 2, WindowsHeight / 2 + 200.0f));
					Time2 = GetTickCount64();
				}
				//iResult = 1;
			}


			// ** 총알을 삭제하는 구간.
			if (iResult == 1)
				iter = EnemyBulletList->erase(iter);
			else
				++iter;
		}
		for (vector<Object*>::iterator iter = ItemList->begin();
			iter != ItemList->end(); )
		{
			// ** 총알이 화면 밖을 넘어가게 되면 reutrn 1 을 반환 하고, 
			// ** iResult == 1이면 총알은 삭제됨.
			int iResult = (*iter)->Update();
			// ** Enemy 리스트의 progress
			// ** 충돌 처리
			if (CollisionManager::EllipseCollision((*iter), m_pPlayer))
			{
				int Tmp;
				Tmp = m_pPlayer->GetPower();
				Tmp++;
				m_pPlayer->SetPower(Tmp);
				iResult = 1;
			}


			// ** 총알을 삭제하는 구간.
			if (iResult == 1)
				iter = ItemList->erase(iter);
			else
				++iter;
		}

		// ** 총알 리스트의 progress
		for (vector<Object*>::iterator iter = BulletList->begin();
			iter != BulletList->end(); )
		{
			// ** 총알이 화면 밖을 넘어가게 되면 reutrn 1 을 반환 하고, 
			// ** iResult == 1이면 총알은 삭제됨.
			int iResult = (*iter)->Update();
			// ** Enemy 리스트의 progress
			for (vector<Object*>::iterator iter2 = EnemyList->begin();
				iter2 != EnemyList->end(); )
			{
				// ** 충돌 처리
				if (CollisionManager::EllipseCollision((*iter), (*iter2)))
				{
					int tmp = (*iter2)->GetHp();
					tmp--;
					(*iter2)->SetHp(tmp);
					if (tmp == 0)
					{
						// ** 몬스터 삭제
						Object* pObj = new Item;
						pObj->Initialize();
						pObj->SetPosition((*iter2)->GetPosition().x, (*iter2)->GetPosition().y - 30);
						pObj->SetColliderPosition((*iter2)->GetPosition().x, (*iter2)->GetPosition().y - 30);
						ItemList->push_back(pObj);
						iter2 = EnemyList->erase(iter2);
						MobCnt--;

					}
					// ** 삭제할 오브젝트로 지정한뒤
					iResult = 1;
					// ** 현재 반복문을 탈출.
					// ** 이유 : 총알 1개에 오브젝 1개를 삭제하기 위함. 
					break;
					//** break 가 안되면 총알이 생성된 시점에에서 충돌체가 여러개일때 모두 충돌후 삭제됨.
				}
				else
					++iter2;
			}

			// ** 총알을 삭제하는 구간.
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
						float(rand() % (WindowsWidth - 120) + 60),
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
						float(rand() % (WindowsWidth + 100)),
						float(rand() % 200 + 50));

					pObj->SetPosition(RandomPos.x, RandomPos.y);
					pObj->SetColliderPosition(RandomPos.x, RandomPos.y);

					EnemyList->push_back(pObj);
				}
			}
			MobCnt = 8;
			//boss
			if (StageCnt == 6)
			{
				MobCnt = 1;
				Object* pObj = new Boss;
				pObj->Initialize();
				EnemyList->push_back(pObj);
			}
			StageCnt++;
		}
	}
}

void Stage1::Render(HDC _hdc)
{
	State_Back->Render(ImageList["Buffer"]->GetMemDC());
	m_pPlayer->Render(ImageList["Buffer"]->GetMemDC());
	bool Vis = Effect->GetActive();
	if(Vis)	Effect->Render(ImageList["Buffer"]->GetMemDC());

	for (vector<Object*>::iterator iter = BulletList->begin();
		iter != BulletList->end(); ++iter)
		(*iter)->Render(ImageList["Buffer"]->GetMemDC());

	for (vector<Object*>::iterator iter = EnemyList->begin();
		iter != EnemyList->end(); ++iter)
		(*iter)->Render(ImageList["Buffer"]->GetMemDC());

	for (vector<Object*>::iterator iter = ItemList->begin();
		iter != ItemList->end(); ++iter)
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
	EnemyList->clear();
	EnemyBulletList->clear();
	ItemList->clear();
	BulletList->clear();

	EnemyList->shrink_to_fit();
	EnemyBulletList->shrink_to_fit();
	ItemList->shrink_to_fit();
	BulletList->shrink_to_fit();
}