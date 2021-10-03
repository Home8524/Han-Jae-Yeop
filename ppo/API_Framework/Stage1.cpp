#include "Stage1.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"
#include "Stage1_Back.h"
#include "Player.h"
#include "Enemy.h"
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

	EnemyList = ObjectManager::GetInstance()->GetEnemyList();
	// ** 적 생성
	for (int i = 0; i < 12; ++i)
	{
		Object* pObj = new Enemy;
		pObj->Initialize();

		Vector3 RandomPos = Vector3(
			float(rand() % (WindowsWidth - 120) + 60),
			float(rand()%200+1)*-1);

		pObj->SetPosition(RandomPos.x, RandomPos.y);
		pObj->SetColliderPosition(RandomPos.x, RandomPos.y);

		EnemyList->push_back(pObj);
	}
	
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

	for (vector<Object*>::iterator iter = EnemyBulletList->begin();
		iter != EnemyBulletList->end(); ++iter)
		(*iter)->Update();

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
				printf("%d", tmp);
				(*iter2)->SetHp(tmp);
				if (tmp == 0)
				{
				// ** 몬스터 삭제
				iter2 = EnemyList->erase(iter2);

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