#include "Option.h"

void Option::Init()
{
	inputObj = new Input;

	sprite = new CSprite*[MAXSPRITE];

	for (int a = 0; a < MAXSPRITE; a++)
	{
		sprite[a] = NULL;
	}

	background = new CSprite("assets/option/background.png", 1, 1, 0.0f, 0.0f, BACKGROUNDWIDTH, BACKGROUNDHEIGHT);

	sprite[0] = new CSprite("assets/option/deleteData.png", 2, 1, 0.0f, 0.4f, OPTBUTTONSIZEX, OPTBUTTONSIZEY);
	sprite[1] = new CSprite("assets/option/staffRoll.png", 2, 1, 0.0f, -0.4f, OPTBUTTONSIZEX, OPTBUTTONSIZEY);
}

bool Option::Update()
{
	inputObj->Input_Update();

	for (int a = 0; a < 2; a++)
	{
		if (a == arrowPos)
			sprite[a]->SetPart(1, 0);
		else
			sprite[a]->SetPart(0, 0);
	}

	if (inputObj->GetAxisShort(DOWN))
		arrowPos++;
	if (inputObj->GetAxisShort(UP))
		arrowPos--;

	if (arrowPos >= 1)
		arrowPos = 1;
	if (arrowPos <= 0)
		arrowPos = 0;

	if (inputObj->GetButtonPress(OK))
		sceneManager.LoadScene(TITLE);

	Draw();

	return true;
}

void Option::Draw()
{
	float clearColor[4] = { 0.0f, 0.0f, 0.0f, 1.0f };

	Direct3D_GetContext()->ClearRenderTargetView(Direct3D_GetRenderTargetView(), clearColor);

	background->Draw();

	for (int a = 0; a < MAXSPRITE; a++)
	{
		if (sprite[a] != NULL)
			sprite[a]->Draw();
	}

	Direct3D_GetSwapChain()->Present(0, 0);
}