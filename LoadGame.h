#pragma once
#include "Scene.h"

#define BUTTONSIZEX 1.6f
#define BUTTONSIZEY 1.0f

class LoadGame : public Scene
{
public:
	void Init();
	bool Update();
	void Draw();
private:
	CSprite* background;
	CSprite** loadMenu;

	Input* inputObj;

	int arrowPos = 0;
};