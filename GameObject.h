#pragma once

#include "Sprite.h"
#include "MapChip.h"

#define GRAVITY 0.8f        // 重力
//#define JUMPPOWER 5.0f
//#define GROUND_Y -0.8f
//#define MOVESPEED 1.0f

#define PI 3.1415926535f	// 円周率

#define TELEPORTSIZE 2

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

//位置と大きさ　当たり判定で使用する
struct TPos_and_Size {
	float posx, posy;
	float sizex, sizey;
};

// float型のベクトル用構造体
struct VECTOR {
	float vx;
	float vy;
};

struct MapChipPosNum {
	int NumY;
	int NumX;
};


class CGameObject : public CSprite {
public:
	static VECTOR moveV[8];  // 移動用ベクトル

	static void Init_moveV();

	CGameObject(const char* texturePath, int horizontalPartNum, int verticalPartNum, float PosX, float PosY, float SizeX, float SizeY);
	CGameObject(const char* texturePath, int horizontalPartNum, int verticalPartNum, float PosX, float PosY, float SizeX, float SizeY, float PixcelSizeX, float PixcelSizeY);

	virtual void Update();
	TPos_and_Size GetPosAndSize();

	MapChipPosNum GetMapChipPos();

	void Gravity();

	void SetAirTime(float t);
	void SetNowAir(bool air);

	bool nowAir = true;		// 空中にいるかどうか

	bool GetNowJump() const;

protected:
	bool nowJump = false;  // ジャンプ中かどうか
	float jumpV = 0.01f;    // ジャンプの初速度
	float jumpY = 0.0008f;    // ジャンプの高さ
	float jumpTime = 0.0f;    // ジャンプ時間

	float airTime = 0.0f;		// 空中にいる時間
};