#pragma once

#include "Scene.h"

#define PI 3.1415926535f  // 円周率

#define SCREENBOUNDRIGHT 1.0f
#define SCREENBOUNDLEFT -1.0f
#define SCREENBOUNDUP 1.0f
#define SCREENBOUNDDOWN -1.0f


#define CIRCLE_SIZE_ADDITIONAL_SPEED 0.10f  // 円の大きくなる速さ
#define CIRCLE_SIZE_MINIMUM           0.5f  // 円の最小サイズ
#define CIRCLE_SIZE_MAXIMUM           6.0f  // 円の最大サイズ

#define PLAYER_PUNCH_POWER_MINIMUM     0.003f  // プレイヤーの最小吹っ飛ばし力
#define PLAYER_PUNCH_POWER_MAXIMUM      0.03f  // プレイヤーの最大吹っ飛ばし力
#define ENEMY_ATTENUATION           0.000001f  // 敵の吹っ飛ばされた後の減衰力
#define PLAYER_PUNCH_ADDITIONAL_POWER 0.0006f  // 吹っ飛ばす度にどのくらい敵が速くなるか

#define ENEMY_EXPAND_SIZE    0.04f  // 敵を殴る度にどのくらい大きくなるか
#define ENEMY_SIZE_MAXIMUM   0.44f  // 敵の最大サイズ
#define ENEMY_SIZE_INITIALIZE true  // コンボが切れたときサイズを戻すかどうか（true：戻す　false：戻さない）

#define SLOW_SPEED   40000  // スロー速度（数値が大きいほど遅くなる）
#define SLOW_DARKNESS 0.5f  // スロー時の暗さ（数値が大きいほど暗くなる（0.0f～1.0f））

// 2点を結んだ直線の角度を計算する関数
float Angle(float x1, float y1, float x2, float y2);

// float型のベクトル用構造体
struct VECTOR {
	float vx;
	float vy;
};

// 移動方向用の定数
enum {
	MOVE_DIR_NONE,
	MOVE_DIR_RIGHT,
	MOVE_DIR_UPPER_RIGHT,
	MOVE_DIR_UP,
	MOVE_DIR_UPPER_LEFT,
	MOVE_DIR_LEFT,
	MOVE_DIR_LOWER_LEFT,
	MOVE_DIR_DOWN,
	MOVE_DIR_LOWER_RIGHT,
};

class GameClass : public Scene
{
public:
	void Init();		//初期化
	bool Update();		//ゲームループ
	void Draw();

	void EnemyMove();

	void NewMove();

	void Uninit();

	int completedLevel = 0;		//レベル番号（成功した）

private:
	int Star_Num = 0;
	int World_Num = 0;
	int Stage_Num = 0;

	Input* inputObj;		//インプットオブジェクト

	//描画する物
	CGameObject **sprite;
	CGameObject* background;
	CGameObject ***MapChips;

	CGameObject* playerObj;

	CSprite* BlackoutPanel;

	int level = 0;		//レベル番号
	int speed = 3;

	int slowcnt = 0;

	bool showCircle = false;
	bool smallCircle = false;
	float circleSize = CIRCLE_SIZE_MINIMUM;
	float circleSizeReal = 0.0f;

	//プレイヤーの向き
	int DragonDirection = 1;
	int OldDragonDirection = 8;

	//瞬間移動用
	int tpAnim = 0;				//フレーム数
	bool tpAnimFlg = false;		//瞬間移動アニメーションフラグ（実行するかどうか）
	int tpAnimPart = 9;
	int tpAnimSize = 99 / TELEPORTSIZE;
	int tpPlaceHolder = 0;

	//プレイヤーの座標
	float DragonPosX;
	float DragonPosY;

	//敵の座標
	float GhostPosX;
	float GhostPosY;

	//敵のサイズ
	float GhostSizeX = 0.15f;
	float GhostSizeY = 0.15f;

	bool GhostCanMove = false;  // 敵が移動できるかどうか
	bool GhostNowMove = false;  // 敵が移動中かどうか
	int GhostMoveDir0 = MOVE_DIR_NONE;  // 敵の移動方向を仮保存するための変数
	int GhostMoveDir = MOVE_DIR_NONE;  // 敵の移動方向を保存する変数
	float GhostMoveCoefficient = PLAYER_PUNCH_POWER_MINIMUM;  // 敵の移動量の係数
	int GhostMoveCnt = 0;		//敵の動く時間を管理する変数

	int EnemyCombo = 0;  // その敵に対するコンボ数

	bool hit_flg = false;  // 敵との当たり判定用の変数

	bool stick_flg = false;

	// 反射用の変数
	float dirX = 1.0f;
	float dirY = 1.0f;

	bool PlayerAlive = true;
	bool EnemyAlive = true;

	//瞬間移動前の位置
	float Old_Player_PosX = 0.0f;
	float Old_Player_PosY = 0.0f;

	// 瞬間移動したときの敵の位置
	float TeleEnemyPosX = 0.0f;
	float TeleEnemyPosY = 0.0f;

	float previousPosX = 0.0f;
	float previousPosY = 0.0f;

	int block = 3;

	bool hitMapchip_Player_flg = false;

	// ステージクリアしたかどうか
	bool stageClear = false;
	// ステージに残ってる燃料の数
	int remainingFuel = 3;
	// 燃料の位置
	float fuelPosX[3] = { 0.0f, 0.0f, 0.0f };
	float fuelPosY[3] = { 0.0f, 0.0f, 0.0f };
	// 燃料のサイズ
	float fuelSizeX = 0.15f;
	float fuelSizeY = 0.15f;

	// クリア処理がonかoffか
	bool clearProcess = true;
	// 当たり判定を可視化するか
	bool collisionAppear = true;
	// 敵の吹っ飛ばしパターン
	int blowOffPattern = 1;
	// 回り込むかどうか
	bool goAround = false;
	// 敵の当たり判定が矩形か円か（1：矩形 2：円）
	int enemyCollisionShape = 1;

	int cnt = 0;    //終了時にリザルトまでの待ち時間

	int playerAnimCnt = 0;
	int playerAnimPart = 0;
	int enemyAnimCnt = 0;
	int enemyAnimPart = 0;
};

extern int Savehitmaphipnum[300][6];			//当たり判定のあるマップチップの配列番号を保存する配列