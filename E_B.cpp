#include "E_B.h"

CE_B::CE_B(float PosX, float PosY) :CEnemy("assets/EB.png", 14, 6, PosX, PosY, 0.15f, 0.15f)
{
	mSpeed = E_B_SPEED;
	mTracking_Speed = E_B_TRACKING_SPEED;
	mSearch_DistanceX = E_B_SARCH_DISTANCE_X;
	mSearch_DistanceY = E_B_SARCH_DISTANCE_Y;
	mAbleBroken_Num = E_B_ABLE_BLOKEN_NUM;

	mMoveDir = MOVE_DIR_LEFT;
}

void CE_B::mAnim()
{
	if (mDiscovery_flg) {
		mPartY = 5;
	}
	else {
		mPartY = 2;
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

	if ((!mDiscovery_flg && mAnimCnt >= 100) || (mDiscovery_flg &&  mAnimCnt >= 50)) {
		mPartX++;
		mAnimCnt = 0;

		if (mPartX == 7) {
			mPartX = 0;
		}
	}
}

void CE_B::mAttack()
{
	if (mDiscovery_flg) {

	}
}