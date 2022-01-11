#include "E_C.h"

CE_C::CE_C(float PosX, float PosY) :CEnemy("assets/EC.png", 12, 6, PosX, PosY, 0.15f, 0.15f)
{
	mSpeed = E_C_SPEED;
	mTracking_Speed = E_C_TRACKING_SPEED;
	mSearch_DistanceX = E_C_SARCH_DISTANCE_X;
	mSearch_DistanceY = E_C_SARCH_DISTANCE_Y;
	mAbleBroken_Num = E_C_ABLE_BLOKEN_NUM;

	mMoveDir = MOVE_DIR_LEFT;
}

void CE_C::mAnim()
{
	if (mDiscovery_flg) {
		mPartY = 2;
	}
	else {
		mPartY = 4;
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

void CE_C::mAttack()
{
	if (mDiscovery_flg) {

	}
}