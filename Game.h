#pragma once

#include "Scene.h"
#include "Efect.h"

#define PI 3.1415926535f  // 円周率

#define SCREENBOUNDRIGHT 1.0f
#define SCREENBOUNDLEFT -1.0f
#define SCREENBOUNDUP 1.0f
#define SCREENBOUNDDOWN -1.0f

#define CIRCLE_SIZE_ADDITIONAL_SPEED 0.10f  // 円の大きくなる速さ
#define CIRCLE_SIZE_MINIMUM           0.5f  // 円の最小サイズ
#define CIRCLE_SIZE_MAXIMUM           6.0f  // 円の最大サイズ

#define PLAYER_INVINCIBLE_COUNT	500  // プレイヤーのダメージ後の無敵カウント

#define ENEMY_SIZE_INITIALIZE true  // コンボが切れたときサイズを戻すかどうか（true：戻す　false：戻さない）
#define CAN_EXPLODE_ENEMY_COUNT  5  // 敵を爆破できるようになる回数

#define SLOW_SPEED   50000  // スロー速度（数値が大きいほど遅くなる）
#define SLOW_DARKNESS 0.5f  // スロー時の暗さ（数値が大きいほど暗くなる（0.0f～1.0f））

#define ANIMSPEED 50	//コリーかアニメーションスピード

#define GIMMICKNUM 10		//ギミックマックス数
#define GIMMICKSIZEX 0.15f
#define GIMMICKSIZEY 0.15f

// 2点を結んだ直線の角度を計算する関数
float Angle(float x1, float y1, float x2, float y2);

class GameClass : public Scene
{
public:
	void Init();		//初期化
	bool Update();		//ゲームループ
	void Draw();

	void EnemyBlow(int);

	void NewMove();
	void StageReset();
	void Uninit();

	int completedLevel = 0;		//レベル番号（成功した）

private:
	int Star_Num = 0;
	int World_Num = 0;
	int Stage_Num = 0;

	Input* inputObj;		//インプットオブジェクト

	CEnemy **enemy;
	int EnemyNum;

	//描画する物
	CGameObject **sprite;
	CSprite **background;
	CMapChip ***MapChips;
	CGameObject **gimmick;

	CGameObject* playerObj;

	CSprite* BlackoutPanel;

	CGameObject** fuel;

	int level = 0;		//レベル番号
	int speed = 3;

	int slowcnt = 0;

	bool Blackout = true;
	float BlackoutPanelAlpha = 0.0f;

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

	bool hit_flg = false;  // 敵との当たり判定用の変数

	bool stick_flg = false;

	bool PlayerAlive = true;
	//bool EnemyAlive = true;

	//瞬間移動前の位置
	float Old_Player_PosX = 0.0f;
	float Old_Player_PosY = 0.0f;

	// 瞬間移動したときの敵の位置
	float TeleEnemyPosX = 0.0f;
	float TeleEnemyPosY = 0.0f;

	float previousPosX = 0.0f;
	float previousPosY = 0.0f;

	bool hitMapchip_Player_flg = false;

	// ステージクリアしたかどうか
	bool stageClear = false;
	// ステージに残ってる燃料の数
	int getFuel = 0;
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
	int enemyCollisionShape = 2;

	// 敵を破壊できるかどうか
	bool enemyCanBreak = false;
	// 敵を破壊するかどうか
	bool enemyBreak = false;
	// ステージに残ってる敵の数
	int remainingEnemy = 1;

	// 敵を追尾するか
	bool enemyHoming = true;
	// 円に入ったら追尾するようにするか
	bool circleHoming = true;

	// プレイヤーのHP
	int playerHp = 3;
	// ダメージをくらった直後か
	bool justAfterDamage = false;
	// 無敵状態のカウント
	int invincibleCnt = 0;
	// ゲームオーバーかどうか
	bool gameover = false;

	// 円出現の音をならすかどうか
	bool circleSound = true;
	// テレポートの音をならすかどうか
	bool teleportSound = true;
	// テレポートの音パターン
	int teleportSoundPattern = 1;

	int playerAnimCnt = 0;
	int playerAnimPartX = 0;
	int playerAnimPartY = 0;
	int animSpeed = ANIMSPEED;
	bool playerBlowAnim = false;
};

extern int Savehitmaphipnum[200][3];			//当たり判定のあるマップチップの配列番号を保存する配列