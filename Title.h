#pragma once

#include "Scene.h"

#define BUTTONSIZEX 0.3f
#define BUTTONSIZEY 0.2f

class Title : public Scene
{
public:
	bool Init();
	bool Update();
	void Draw();
	bool SceneChange();

private:
	CSprite* background;
	CSprite **sprite;
	CSprite* playerObj;

	Input* inputObj;

	int arrowPos = 0;

	bool changeScene = false;
};