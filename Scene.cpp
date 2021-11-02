#include "Scene.h"

bool Scene::Init()
{
	this->inputObj = new Input;

	if (!inputObj)
	{
		MessageBoxA(nullptr, "インプットオブジェクト初期化できませんでした", "シーンエラー", MB_OK | MB_ICONERROR);
		return false;
	}

	this->sprite = new CGameObject*[64];

	this->changeScene = false;

	return true;
}

void Scene::Draw()
{
	float clearColor[4] = { 0.0f, 0.0f, 0.0f, 1.0f };

	Direct3D_GetContext()->ClearRenderTargetView(Direct3D_GetRenderTargetView(), clearColor);

	background->Draw();

	playerObj->Draw();

	for (int a = 0; a < MAXSPRITE; a++)
	{
		if (sprite[a])
			sprite[a]->Draw();
	}

	Direct3D_GetSwapChain()->Present(0, 0);
}

bool Scene::SceneChange()
{
	return changeScene;
}