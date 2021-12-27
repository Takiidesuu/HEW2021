#pragma once

#include "Scene.h"

#define BUTTONSIZEX 0.75f
#define BUTTONSIZEY 0.3f

class Title : public Scene
{
public:
	void Init();
	bool Update();
	void Draw();

private:
	CSprite* Teamlogo;
	CSprite* background;
	CSprite **sprite;
	CSprite* playerObj;
	CEfectPanel* Efectpanel;

	bool logoflg = true;

	bool PressAnyKeyflg = false;

	const int returnTeamlogoTime = 80000;

	Input* inputObj;

	int arrowPos = 0;

	bool changeScene = false;
};