#include "E_A.h"

CE_A::CE_A(float PosX, float PosY) :CEnemy("assets/EA.png", 7, 3, PosX, PosY, 0.15f, 0.15f) {
	mSpeed = E_A_SPEED;
	mTracking_Speed = E_A_TRACKING_SPEED;
	mSearch_DistanceX = E_A_SARCH_DISTANCE_X;
	mSearch_DistanceY = E_A_SARCH_DISTANCE_Y;
	mAbleBroken_Num = E_A_ABLE_BLOKEN_NUM;

	mMoveDir = MOVE_DIR_RIGHT;
}

void CE_A::mAnim() {

	if (mDiscovery_flg) {
		mPartY = 2;
	}
	else {
		mPartY = 1;
	}

	switch (mMoveDir)
	{
	case MOVE_DIR_RIGHT:
		reverse_flg = true;
		break;
	case MOVE_DIR_LEFT:
		reverse_flg = false;
		break;
	default:
		break;
	}

	mAnimCnt++;

	if ((!mDiscovery_flg && mAnimCnt == 500) || (mDiscovery_flg &&  mAnimCnt == 1000)) {
		mPartX++;
		mAnimCnt = 0;

		if (mPartX == 7) {
			mPartX = 0;
		}
	}
}

void CE_A::mAttack()
{
}