#pragma once

#define E_A_SPEED 0.0003f
#define E_A_TRACKING_SPEED 0.0006f
#define E_A_SARCH_DISTANCE_X 0.8f
#define E_A_SARCH_DISTANCE_Y 0.5
#define E_A_ABLE_BLOKEN_NUM 5

#include "Enemy.h"

class CE_A :public CEnemy
{
public:
	CE_A(float PosX, float PosY);

	void mAnim();

	void mAttack();
};