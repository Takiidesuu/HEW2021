#pragma once

#include "Scene.h"

class StageSelect : public Scene
{
public:
	bool Init();
	int Update();
	void Draw();
	bool SceneChange();
private:
	CSprite* background;
	CSprite **sprite;

	Input* inputObj;

	int arrowPos = 0;

	bool changeScene = false;
};