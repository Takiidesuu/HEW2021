#pragma once

#include "Enemy.h"

#define E_B_SPEED 0.0009f
#define E_B_TRACKING_SPEED 0.0016f
#define E_B_SARCH_DISTANCE_X 0.8f
#define E_B_SARCH_DISTANCE_Y 0.3f
#define E_B_ABLE_BLOKEN_NUM 5

class CE_B :public CEnemy
{
public:
	CE_B(float PosX, float PosY);

	void mAnim();

	void mAttack();
};