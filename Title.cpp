#include "Title.h"

bool Title::Init()
{
	inputObj = new Input;

	if (!inputObj)
	{
		MessageBoxA(nullptr, "インプットオブジェクト初期化できませんでした", "インプットエラー", MB_OK | MB_ICONERROR);
		return false;
	}

	sprite = new CSprite*[MAXSPRITE];

	for (int a = 0; a < MAXSPRITE; a++)
	{
		sprite[a] = NULL;
	}

	background = new CSprite("assets/title/titleBack.jpg", 1, 1, 0.0f, 0.0f, 2.0f, 2.0f);
	sprite[0] = new CSprite("assets/title/titleText.png", 1, 1, 0.0f, 0.5f, 1.0f, 1.0f);

	sprite[1] = new CSprite("assets/title/startButton.png", 1, 1, 0.0f, -0.2f, BUTTONSIZEX, BUTTONSIZEY);
	sprite[2] = new CSprite("assets/title/exitButton.png", 1, 1, 0.0f, -0.6f, BUTTONSIZEX, BUTTONSIZEY);

	changeScene = false;

	return true;
}

bool Title::Update()
{
	inputObj->Input_Update();

	if (inputObj->Input_GetKeyTrigger(VK_DOWN) && arrowPos == 0)
		arrowPos = 1;
	if (inputObj->Input_GetKeyTrigger(VK_UP) && arrowPos == 1)
		arrowPos = 0;

	if (inputObj->Input_GetKeyTrigger(VK_RETURN))
		this->changeScene = true;

	switch (arrowPos)
	{
	case 0:
		sprite[1]->SetSize(BUTTONSIZEX * 1.5f, BUTTONSIZEY * 1.5f);
		sprite[2]->SetSize(BUTTONSIZEX, BUTTONSIZEY);
		break;
	case 1:
		sprite[1]->SetSize(BUTTONSIZEX, BUTTONSIZEY);
		sprite[2]->SetSize(BUTTONSIZEX * 1.5f, BUTTONSIZEY * 1.5f);
		break;
	}

	this->Draw();

	return true;
}

void Title::Draw()
{
	float clearColor[4] = { 0.0f, 0.0f, 0.0f, 1.0f };

	Direct3D_GetContext()->ClearRenderTargetView(Direct3D_GetRenderTargetView(), clearColor);

	background->Draw();

	for (int a = 0; a < MAXSPRITE; a++)
	{
		if (sprite[a])
			sprite[a]->Draw();
	}

	Direct3D_GetSwapChain()->Present(0, 0);
}

bool Title::SceneChange()
{
	return changeScene;
}