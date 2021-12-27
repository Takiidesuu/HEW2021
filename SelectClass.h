#pragma once

#include "Scene.h"
#define STAGE_SELECT_SPRITE_NUM 9	// ï`âÊÇµÇΩÇ¢êî

#define STARSIZEWIDTH 0.8f
#define STARSIZEHEIGHT 0.5f

#define WORLDSIZEWIDTH 1.2f
#define WORLDSIZEHEIGHT 0.5f

#define STAGEICONWIDTH 1.6f / 1.4f
#define STAGEICONHEIGHT 0.5f / 1.4f

#define MOVESPEED 0.001f * 5.0f

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

private:
	Input* inputObj;
	CSprite* background;
	CSprite **sprite;
	CSprite **starName;
	CSprite ***worldIcon;
	CSprite ****stageIcon;

	int arrowPos = -1;
	int dir = 0;

	CSprite **starPos;

	bool changeScene = false;

	int SELECT_CHOICE	= 0;
	int STAR_CHOICE		= 0;
	int WORLD_CHOICE	= 0;
	int STAGE_CHOICE	= 0;

	void MoveAnim();
	bool anim = true;
	bool moveAnim = false;
};