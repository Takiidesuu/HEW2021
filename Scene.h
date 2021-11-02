#pragma once

#include "GameObject.h"
#include "Input.h"
#include "MapChip.h"
#include "Collision.h"
#include "Shape.h"

class Scene
{
public:
	bool Init();
	bool Update();
	void Draw();
	bool SceneChange();
private:
	CSprite* background;
	CGameObject **sprite;
	CSprite ***MapChips;

	CGameObject* playerObj;

	Input* inputObj;

	bool changeScene = false;
};