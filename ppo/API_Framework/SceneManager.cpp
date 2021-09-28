#include "SceneManager.h"

#include "Logo.h"
#include "Menu.h"
#include "Stage.h"
#include "Level.h"
#include "Stage1.h"
SceneManager* SceneManager::Instance = nullptr;


void SceneManager::SetScene(SCENEID _SceneID)
{
	::Safe_Delete(pSceneState);
	
	switch (_SceneID)
	{
	case SCENEID::LOGO:
		pSceneState = new Logo;
		break;

	case SCENEID::MENU:
		pSceneState = new Menu;
		break;

	case SCENEID::STAGE:
		pSceneState = new Stage;
		break;
	
	case SCENEID::LEVEL:
		pSceneState = new Level;
		break;
	case SCENEID::STAGE1:
		pSceneState = new Stage1;
		break;
	case SCENEID::EXIT:
		exit(NULL);
		break;
	}

	pSceneState->Initialize();
}

void SceneManager::Update()
{
	pSceneState->Update();
}

void SceneManager::Render(HDC _hdc)
{
	pSceneState->Render(_hdc);
}

void SceneManager::Release()
{
	::Safe_Delete(pSceneState);
}