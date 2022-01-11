#pragma once
#include "Scene.h"

#define OPTBUTTONSIZEX 1.6f
#define OPTBUTTONSIZEY 1.0f  / 3.0f

class Option : public Scene
{
public:
	void Init();
	bool Update();
	void Draw();
private:
	CSprite* background;
	CSprite** sprite;

	Input* inputObj;

	int arrowPos = 0;
};