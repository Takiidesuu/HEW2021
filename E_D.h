#pragma once

#include "Enemy.h"

#define E_D_SPEED 0.0009f
#define E_D_TRACKING_SPEED 0.0016f
#define E_D_SARCH_DISTANCE_X 0.8f
#define E_D_SARCH_DISTANCE_Y 0.3f
#define E_D_ABLE_BLOKEN_NUM 5

class CE_D :public CEnemy
{
public:
	CE_D(float PosX, float PosY);

	void mAnim();

	void mAttack();
};