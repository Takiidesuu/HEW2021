#include "Enemy.h"

CEnemy::CEnemy(const char* texturePath, int horizontalPartNum, int verticalPartNum, float PosX, float PosY, float SizeX, float SizeY) :CGameObject(texturePath, horizontalPartNum, verticalPartNum, PosX, PosY, SizeX, SizeY) {

}

void CEnemy::mMove()
{
	if (mMoveflg && !nowAir) {
		switch (mMoveDir)
		{
		case MOVE_DIR_RIGHT:
			if (!mDiscovery_flg)
				mPosX += mSpeed;

			else
				mPosX += mTracking_Speed;

			break;

		case MOVE_DIR_LEFT:
			if (!mDiscovery_flg)
				mPosX -= mSpeed;

			else
				mPosX -= mTracking_Speed;

			break;
		default:
			break;
		}
	}
}

void CEnemy::mSearch(TPos PlayerPos)
{
	if (!mNow_Blown_flg) {
		switch (mMoveDir)
		{
		case MOVE_DIR_RIGHT:

			if ((PlayerPos.x > mPosX) && ((PlayerPos.x - mPosX) <= mSearch_DistanceX) && ((PlayerPos.x - mPosX) >= -1 * mSearch_DistanceX) && ((PlayerPos.y - mPosY < mSearch_DistanceY) && (PlayerPos.y - mPosY > -1 * mSearch_DistanceY))) {
				mDiscovery_flg = true;
			}

			else {
				mDiscovery_flg = false;
			}

			break;

		case MOVE_DIR_LEFT:
			if ((PlayerPos.x < mPosX) && ((PlayerPos.x - mPosX) <= mSearch_DistanceX) && ((PlayerPos.x - mPosX) >= -1 * mSearch_DistanceX) && ((PlayerPos.y - mPosY <= mSearch_DistanceY) && (PlayerPos.y - mPosY > -1 * mSearch_DistanceY))) {
				mDiscovery_flg = true;
			}

			else {
				mDiscovery_flg = false;
			}

			break;

		default:
			break;
		}

		if (mDiscovery_flg && (PlayerPos.x - mPosX < 0.1f) && (PlayerPos.x - mPosX > -0.1f)) {
			mMoveflg = false;
		}

		else {
			mMoveflg = true;
		}

	}
}

void CEnemy::mAttacked()
{
	mNow_Blown_flg = true;
	mStartBlown_flg = false;
	mBlownDir = mBlownDir0;
	mBlownDir0 = BLOW_DIR_NONE;
	mBlownCnt = 0;
	mSizeWidth += ENEMY_EXPAND_SIZE;
	mSizeHeight += ENEMY_EXPAND_SIZE;
	if (mSizeWidth >= ENEMY_SIZE_MAXIMUM) {
		mSizeWidth = ENEMY_SIZE_MAXIMUM;
	}
	if (mSizeHeight >= ENEMY_SIZE_MAXIMUM) {
		mSizeHeight = ENEMY_SIZE_MAXIMUM;
	}
	mBlown_DirX = 1.0f;
	mBlown_DirY = 1.0f;

	mBlownCoefficient = PLAYER_PUNCH_POWER_MINIMUM + mEnemyCombo * PLAYER_PUNCH_ADDITIONAL_POWER;
	if (mBlownCoefficient >= PLAYER_PUNCH_POWER_MAXIMUM) {
		mBlownCoefficient = PLAYER_PUNCH_POWER_MAXIMUM;
	}

	mMoveflg = false;
	mAnimFlg = false;

	//nowAir = false;

	mEnemyCombo++;
}

void CEnemy::mBlowm()
{
	if (mNow_Blown_flg) {
		// ‚Í‚¶‚©‚ê‚½•ûŒü‚ÉˆÚ“®‚·‚é
		if (mBlownCoefficient > 0.0f) {

			mBlownCoefficient -= ENEMY_ATTENUATION;

			switch (mBlownDir)
			{
			case BLOW_DIR_RIGHT:
				mPosX += mBlownCoefficient * moveV[0].vx * mBlown_DirX * 0.4f;
				mPosY += mBlownCoefficient * moveV[0].vy * mBlown_DirY * 0.4f;

				break;

			case BLOW_DIR_UPPER_RIGHT:
				mPosX += mBlownCoefficient * moveV[1].vx * mBlown_DirX * 0.4f;
				mPosY += mBlownCoefficient * moveV[1].vy * mBlown_DirY * 0.4f;

				break;

			case BLOW_DIR_UP:
				mPosX += mBlownCoefficient * moveV[2].vx * mBlown_DirX * 0.4f;
				mPosY += mBlownCoefficient * moveV[2].vy * mBlown_DirY * 0.4f;

				break;

			case BLOW_DIR_UPPER_LEFT:
				mPosX += mBlownCoefficient * moveV[3].vx * mBlown_DirX * 0.4f;
				mPosY += mBlownCoefficient * moveV[3].vy * mBlown_DirY * 0.4f;

				break;

			case BLOW_DIR_LEFT:
				mPosX += mBlownCoefficient * moveV[4].vx * mBlown_DirX * 0.4f;
				mPosY += mBlownCoefficient * moveV[4].vy * mBlown_DirY * 0.4f;

				break;

			case BLOW_DIR_LOWER_LEFT:
				mPosX += mBlownCoefficient * moveV[5].vx * mBlown_DirX * 0.4f;
				mPosY += mBlownCoefficient * moveV[5].vy * mBlown_DirY * 0.4f;

				break;

			case BLOW_DIR_DOWN:
				mPosX += mBlownCoefficient * moveV[6].vx * mBlown_DirX * 0.4f;
				mPosY += mBlownCoefficient * moveV[6].vy * mBlown_DirY * 0.4f;

				break;

			case BLOW_DIR_LOWER_RIGHT:
				mPosX += mBlownCoefficient * moveV[7].vx * mBlown_DirX * 0.4f;
				mPosY += mBlownCoefficient * moveV[7].vy * mBlown_DirY * 0.4f;

				break;
			}

			mBlownCnt++;

			//if (mEnemyCombo >= mAbleBroken_Num) {
			//	mAbleBroken = true;
			//}
		}

		else
		{
			mMoveflg = true;
			mAbleBroken = false;
			mNow_Blown_flg = false;
			mBlown_DirX = 1.0f;
			mBlown_DirY = 1.0f;
			airTime = 0.0f;
			mBlownCnt = 0;
			mBlownCoefficient = PLAYER_PUNCH_POWER_MINIMUM;
			nowAir = true;
			mEnemyCombo = 0;
			mSizeHeight = 0.15;
			mSizeWidth = 0.15;
		}
	}
}