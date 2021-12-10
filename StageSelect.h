#pragma once

#include "Scene.h"

class StageSelect
{
public:
	bool Init();
	bool Update();
	void Draw();
	bool SceneChange();
private:
	CSprite* background;
	CSprite **world;
	CSprite **stage;
	CSprite* player;

	Input* inputObj;

	int arrowPos = 0;
	int prevArrowPos = 0;

	int selectedStage = 0;
	int selectScreen = 0;

	bool changeScene = false;

	float worldSize = 0.4f;

	//プレイヤーアニメーション用
	int playerAnimCnt = 0;
	int playerAnimPart = 0;
};