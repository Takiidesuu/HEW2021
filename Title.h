#pragma once

#include "Scene.h"

#define BUTTONSIZEX 0.75f
#define BUTTONSIZEY 0.3f

#define OPTBUTTONSIZEX 1.6f
#define OPTBUTTONSIZEY 1.0f  / 3.0f

class Title : public Scene
{
public:
	void Init();
	bool Update();
	void Draw();

	void LoadingScreen();
	void Option();

private:
	CSprite* Teamlogo;
	CSprite** back;
	CSprite* background;
	CSprite **sprite;
	CSprite* playerObj;
	CEfectPanel* Efectpanel;

	bool logoflg = true;

	bool PressAnyKeyflg = false;

	const int returnTeamlogoTime = 80000;

	Input* inputObj;

	int arrowPos = 0;

	bool playMusic = true;

	int menu = 0;
};