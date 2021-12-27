#pragma once

#include "Sprite.h"

#define GRAVITY 0.8f
#define JUMPPOWER 5.0f
#define GROUND_Y -0.8f
#define MOVESPEED 1.0f

#define TELEPORTSIZE 2

struct TPos_and_Size {
	float posx, posy;
	float sizex, sizey;
};

class CGameObject : public CSprite {
public:
	CGameObject(const char* texturePath, int horizontalPartNum, int verticalPartNum, float PosX, float PosY, float SizeX, float SizeY);
	CGameObject(const char* texturePath, int horizontalPartNum, int verticalPartNum, float PosX, float PosY, float SizeX, float SizeY, float PixcelSizeX, float PixcelSizeY);

	virtual void Update();
	TPos_and_Size GetPosAndSize();

	void SinJump();

	void GravityJump();
	void Gravity();

	void SetAirTime(float t);
	void SetNowAir(bool air);

	bool nowAir = true;		// 空中にいるかどうか

	bool GetNowJump() const;
	bool GetNowAir() const;  // 空中にいるか取得

	//この変数の位置を中心に描画する
	static float mCameraPosX;
	static float mCameraPosY;


protected:
	bool nowJump = false;  // ジャンプ中かどうか
	float jumpV = 0.01f;    // ジャンプの初速度
	float jumpY = 0.0008f;    // ジャンプの高さ
	float jumpTime = 0.0f;    // ジャンプ時間

	float airTime = 0.0f;		// 空中にいる時間
};