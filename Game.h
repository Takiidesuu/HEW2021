#pragma once

#include "Scene.h"

#define PI 3.1415926535f  // 円周率

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
	bool Init();		//初期化
	bool Update();		//ゲームループ
	void Draw();

	int completedLevel = 0;		//レベル番号（成功した）

private:
	Input* inputObj;		//インプットオブジェクト

	//描画する物
	CGameObject **sprite;
	CSprite* background;
	CSprite ***MapChips;

	CGameObject* playerObj;

	int level = 0;		//レベル番号
	int speed = 3;
};