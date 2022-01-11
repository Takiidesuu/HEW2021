#pragma once
#include "GameObject.h"

#define PLAYER_INVINCIBLE_COUNT	500  // プレイヤーのダメージ後の無敵カウント
#define ANIMSPEED 50	//コリーかアニメーションスピード

class Player : public CGameObject
{
public:
	Player(float posX, float posY);

	void Move();
	void anim();

	float x = 0;
	float y = 0;

	int hp = 3;
private:
	int playerAnimCnt = 0;
	int animSpeed = ANIMSPEED;

	bool animStat = false;

	int dir = 1;
	int oldDir = 8;

	float oldX = 0.0f;
	float oldY = 0.0f;

	CGameObject** sprite;
};