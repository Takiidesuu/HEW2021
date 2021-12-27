#include "LoadGame.h"

void LoadGame::Init()
{
	inputObj = new Input;

	loadMenu = new CSprite*[3];

	background = new CSprite("assets/loadscreen/background.png", 1, 1, 0.0f, 0.0f, BACKGROUNDWIDTH, BACKGROUNDWIDTH);
	loadMenu[0] = new CSprite("assets/loadscreen/saveData1.png", 2, 1, -0.5f, 0.5f, BUTTONSIZEX, BUTTONSIZEY);
	loadMenu[1] = new CSprite("assets/loadscreen/saveData2.png", 2, 1, -0.5f, 0.0f, BUTTONSIZEX, BUTTONSIZEY);
	loadMenu[2] = new CSprite("assets/loadscreen/saveData3.png", 2, 1, -0.5f, -0.5f, BUTTONSIZEX, BUTTONSIZEY);
}

bool LoadGame::Update()
{
	inputObj->Input_Update();

	for (int a = 0; a < 3; a++)
	{
		if (a == arrowPos)
			loadMenu[a]->SetPart(1, 0);
		else
			loadMenu[a]->SetPart(0, 0);
	}

	if (inputObj->GetAxisShort(DOWN))
		arrowPos++;
	if (inputObj->GetAxisShort(UP))
		arrowPos--;

	if (arrowPos >= 2)
		arrowPos = 2;
	if (arrowPos <= 0)
		arrowPos = 0;

	if (inputObj->GetButtonPress(OK))
		sceneManager.LoadScene(TITLE);

	Draw();

	return true;
}

void LoadGame::Draw()
{
	float clearColor[4] = { 0.0f, 0.0f, 0.0f, 1.0f };

	Direct3D_GetContext()->ClearRenderTargetView(Direct3D_GetRenderTargetView(), clearColor);

	background->Draw();

	for (int a = 0; a < 3; a++)
		loadMenu[a]->Draw();

	Direct3D_GetSwapChain()->Present(0, 0);
}