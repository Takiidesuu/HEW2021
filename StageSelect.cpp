#include "StageSelect.h"

bool StageSelect::Init()
{
	inputObj = new Input;

	if (!inputObj)
	{
		MessageBoxA(nullptr, "インプットオブジェクト初期化できませんでした", "ステージセレクト", MB_OK | MB_ICONERROR);
		return false;
	}

	background = new CSprite("assets/stageselect/stageBackground.png", 1, 1, 0.0f, 0.0f, 2.0f, 2.0f);

	sprite = new CSprite*[64];

	sprite[0] = new CSprite("stage1.png", 1, 1, -0.5f, 0.5f, 0.5f, 0.5f);
	sprite[1] = new CSprite("stage2.png", 1, 1, 0.0f, 0.5f, 0.5f, 0.5f);
	sprite[2] = new CSprite("stage3.png", 1, 1, -0.5f, 0.5f, 0.5f, 0.5f);
	sprite[3] = new CSprite("stage4.png", 1, 1, -0.5f, 0.5f, 0.5f, 0.5f);
	sprite[4] = new CSprite("stage5.png", 1, 1, -0.5f, 0.5f, 0.5f, 0.5f);
	sprite[5] = new CSprite("stage6.png", 1, 1, -0.5f, 0.5f, 0.5f, 0.5f);
	
	changeScene = false;

	return true;
}

int StageSelect::Update()
{
	inputObj->Input_Update();

	static int selectedStage = 0;
	static int arrowPosX = 0;
	static int arrowPosY = 0;

	return selectedStage;
}