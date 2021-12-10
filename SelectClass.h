#pragma once

#include "Scene.h"
#define STAGE_SELECT_SPRITE_NUM 9	// ï`âÊÇµÇΩÇ¢êî

enum STAR_SELECT
{
	STAR1,
	STAR2,
	STAR3
};

enum WORLD_SELECT
{
	WORLD1,
	WORLD2
};

enum STAGE_SELECT
{
	STAGE1,
	STAGE2,
	STAGE3
};

class SelectClass : public Scene
{
public:
	bool Init();
	int Update();
	void Draw();
	bool SceneChange();

private:
	Input* inputObj;
	CSprite **sprite;

	int arrowPos = -1;

	bool changeScene = false;

	int SELECT_CHOICE	= 0;
	int STAR_CHOICE		= 0;
	int WORLD_CHOICE	= 0;
	int STAGE_CHOICE	= 0;
};
