
#include "Result.h"

bool CResult::Init()
{
	//インプットオブジェクトを作る
	inputObj = new Input;

	//インプットオブジェクトの作成に失敗したら
	if (!inputObj)
	{
		MessageBoxA(nullptr, "インプットオブジェクト作れませんでした", "インプットエラー", MB_OK);
		return false;
	}

	sprite = new CSprite*[RESULT_SPRITE_NUM];

	sprite[0] = new CSprite("assets/BG_haisouko_ver02.png", 1, 1, 0.0f, 0.0f, 2.0f, 2.0f);		//背景
	sprite[0]->SetColor(0.5f, 0.5f, 0.5f, 1.0f);

	sprite[1] = new CSprite("assets/BG_haisouko_ver02.png", 1, 1, -0.75f, -0.5f, 0.5f, 0.25f);		//Select
	sprite[2] = new CSprite("assets/BG_haisouko_ver02.png", 1, 1, 0.0f, -0.5f, 0.5f, 0.25f);		//Retry
	sprite[3] = new CSprite("assets/BG_haisouko_ver02.png", 1, 1, 0.75f, -0.5f, 0.5f, 0.25f);		//Next

	sprite[4] = new CSprite("assets/BG_haisouko_ver02.png", 1, 1, 0.0f, 0.5f, 0.75f, 0.75f);		//リザルト

	inputflg = false;

	return true;
}

bool CResult::Update()
{
	//インプットオブジェクトをアップデート
	inputObj->Input_Update();

	//ESCキー押したら、プログラム強制終了
	if (inputObj->Input_GetKeyTrigger(VK_ESCAPE))
		return false;

	if (inputObj->isInput())	//インプットがあったら
	{
		if (inputflg == false) {
			if ((inputObj->GetAxisShort(RIGHT)) && (select < NEXT)) {
				select += 1;
			}
			if ((inputObj->GetAxisShort(LEFT)) && (select > STAGE_SELECT)) {
				select -= 1;
			}
		}
		inputflg = true;
	}

	if (inputObj->GetButtonPress(OK))
		sceneManager.LoadScene(TITLE);

	else {
		inputflg = false;
	}

	switch (select)
	{
		default:
			sprite[STAGE_SELECT]->SetColor(0.5f, 0.5f, 0.5f, 1.0f);
			sprite[RETRY]->SetColor(0.5f, 0.5f, 0.5f, 1.0f);
			sprite[NEXT]->SetColor(0.5f, 0.5f, 0.5f, 1.0f);
			break;
		case STAGE_SELECT:
			sprite[STAGE_SELECT]->SetColor(1.0f, 1.0f, 1.0f, 1.0f);
			sprite[RETRY]->SetColor(0.5f, 0.5f, 0.5f, 1.0f);
			sprite[NEXT]->SetColor(0.5f, 0.5f, 0.5f, 1.0f);

			break;
		case RETRY:
			sprite[STAGE_SELECT]->SetColor(0.5f, 0.5f, 0.5f, 1.0f);
			sprite[RETRY]->SetColor(1.0f, 1.0f, 1.0f, 1.0f);
			sprite[NEXT]->SetColor(0.5f, 0.5f, 0.5f, 1.0f);

			break;
		case NEXT:
			sprite[STAGE_SELECT]->SetColor(0.5f, 0.5f, 0.5f, 1.0f);
			sprite[RETRY]->SetColor(0.5f, 0.5f, 0.5f, 1.0f);
			sprite[NEXT]->SetColor(1.0f, 1.0f, 1.0f, 1.0f);

			break;
	}

	Draw();

	return true;
}

void CResult::Draw() {

	float clearColor[4] = { 0.0f, 0.0f, 0.0f, 1.0f };

	Direct3D_GetContext()->ClearRenderTargetView(Direct3D_GetRenderTargetView(), clearColor);

	for (int i = 0; i < RESULT_SPRITE_NUM; i++) {
		sprite[i]->Draw();
	}

	Direct3D_GetSwapChain()->Present(0, 0);
}
