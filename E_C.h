#pragma once

#include "Enemy.h"

#define E_C_SPEED 0.0009f
#define E_C_TRACKING_SPEED 0.0016f
#define E_C_SARCH_DISTANCE_X 0.8f
#define E_C_SARCH_DISTANCE_Y 0.3f
#define E_C_ABLE_BLOKEN_NUM 5

class CE_C :public CEnemy
{
public:
	CE_C(float PosX, float PosY);

	void mAnim();

	void mAttack();
};