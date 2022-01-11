#include "E_D.h"

CE_D::CE_D(float PosX, float PosY) :CEnemy("assets/ED.png", 9, 6, PosX, PosY, 0.15f, 0.15f)
{
	mSpeed = E_D_SPEED;
	mTracking_Speed = E_D_TRACKING_SPEED;
	mSearch_DistanceX = E_D_SARCH_DISTANCE_X;
	mSearch_DistanceY = E_D_SARCH_DISTANCE_Y;
	mAbleBroken_Num = E_D_ABLE_BLOKEN_NUM;

	mMoveDir = MOVE_DIR_LEFT;
}

void CE_D::mAnim()
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

		if (!mDiscovery_flg && mPartX == 6) {
			mPartX = 0;
		}
		else if (mDiscovery_flg && (mPartX == 5 || mPartX == 6)) {
			mPartX = 0;
		}
	}
}

void CE_D::mAttack()
{
	if (mDiscovery_flg) {

	}
}