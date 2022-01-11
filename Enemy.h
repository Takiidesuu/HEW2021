#pragma once
#include "GameObject.h"

#define PLAYER_PUNCH_POWER_MINIMUM     0.003f  // プレイヤーの最小吹っ飛ばし力
#define PLAYER_PUNCH_POWER_MAXIMUM      0.03f  // プレイヤーの最大吹っ飛ばし力
#define ENEMY_ATTENUATION           0.000001f  // 敵の吹っ飛ばされた後の減衰力
#define PLAYER_PUNCH_ADDITIONAL_POWER 0.0006f  // 吹っ飛ばす度にどのくらい敵が速くなるか

#define ENEMY_EXPAND_SIZE    0.04f  // 敵を殴る度にどのくらい大きくなるか
#define ENEMY_SIZE_MAXIMUM   0.44f  // 敵の最大サイズ

//吹っ飛ばされ方向用の定数
enum E_BLOW_DIR {
	BLOW_DIR_NONE,
	BLOW_DIR_RIGHT,
	BLOW_DIR_UPPER_RIGHT,
	BLOW_DIR_UP,
	BLOW_DIR_UPPER_LEFT,
	BLOW_DIR_LEFT,
	BLOW_DIR_LOWER_LEFT,
	BLOW_DIR_DOWN,
	BLOW_DIR_LOWER_RIGHT,
};

class CEnemy :public CGameObject
{
public:
	CEnemy(const char* texturePath, int horizontalPartNum, int verticalPartNum, float PosX, float PosY, float SizeX, float SizeY);

	virtual void mMove();						//移動関数

	virtual void mSearch(TPos);					//索敵関数　引数に索敵対象のGetPos()関数を入れる

	virtual void mAttack() = 0;					//攻撃関数　

	virtual void mAnim() = 0;					//アニメーション関数

	void mAttacked();							//攻撃を受けた際の処理



	bool mAtk_flg = false;						//攻撃中か否か

	int mEnemyCombo = 0;						//連続で吹っ飛ばされた回数
	bool mStartBlown_flg = false;				//吹っ飛ばされた際のフラグ
	bool mNow_Blown_flg = false;				//吹っ飛ばされてる際のフラグ
	E_BLOW_DIR mBlownDir0 = BLOW_DIR_NONE;		//敵の移動方向を仮保存するための変数
	E_BLOW_DIR mBlownDir = BLOW_DIR_NONE;		//敵の移動方向を保存する変数
	float mBlownCoefficient = 0.003f;			//敵の移動量の係数
	int mBlownCnt = 0;							//敵の動く時間を管理する変数

	bool mEnemyHit_flg = false;                 //敵とプレイヤーの当たり判定

	float mBlown_DirX = 1.0f;					//X軸の反射用の変数
	float mBlown_DirY = 1.0f;					//Y軸の反射用の変数

	void mBlowm();								//吹っ飛び

	bool mEnemyAlive = true;					//生存フラグ

	int mAbleBroken_Num;						//破壊可能になる攻撃回数

	bool mAbleBroken = false;					//破壊可能フラグ

	bool mMoveflg = true;						//移動中かのフラグ

	int mMoveDir = MOVE_DIR_NONE;				//移動方向

protected:
	int mAnimCnt = 0;							//アニメーション更新頻度管理用変数

	bool mAnimFlg = true;						//アニメーションするかの関数

	float mSpeed;								//通常移動速度
	float mTracking_Speed;						//追跡時移動速度

	bool mDiscovery_flg = false;				//プレイヤー発見フラグ

	float mSearch_DistanceX;					//プレイヤー発見距離X
	float mSearch_DistanceY;					//プレイヤー発見距離Y
};