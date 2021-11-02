#pragma once

#include <math.h>
#include "direct3d.h"

// ****************************************
// プリプロセッサ定数・マクロ定義
// ****************************************

// COMオブジェクトをNULLチェックしてからReleaseする
#define COM_SAFE_RELEASE(o)   if(NULL!=o){o->Release();o=NULL;}

#define MAXSPRITE 64

#define GRAVITY 0.8f
#define GROUND_Y -0.9f
#define MOVESPEED 1.0f

#define LEFTBORDER -1.0f
#define RIGHTBORDER 3.0f

#define TELEPORTSIZE 2

/*
分割画像ファイル対応の描画クラス。

スプライトサイズの初期値は0x0なので、
描画するまでにSetSizeを呼び出してサイズを指定する必要がある。

game.cppの
Direct3D_GetSwapChain()->Present(0, 0);
の直前でDrawを呼び出すことで描画できる。

ゲームオブジェクトに持たせて使用すると良い。

最小使用例: 画面右下にドラゴンの二列目の二番目の画像を表示する

game.cpp

...いろいろ

Sprite sprite("assets/parts/dora01.png", 3, 4);
sprite.SetSize(1, 1);
sprite.SetPart(1, 1);
sprite.Draw();

Direct3D_GetSwapChain()->Present(0, 0);
*/

//*****************************************************************************
// 構造体定義
//*****************************************************************************

struct VERTEX_POSTEX {
	float x, y, z;  // 頂点の位置

	float r, g, b, a; //色と透明度

	float u, v;  // テクスチャのUV座標
};

class CSprite {
public:
	// texturePath=画像パス
	// horizontalPartNum=横に何分割するか
	// verticalPartNum=縦に何分割するか
	// PosX, PosY X座標Y座標
	//SizeX,SizeY Xの大きさYの大きさ
	CSprite(const char* texturePath, int horizontalPartNum, int verticalPartNum, float PosX, float PosY, float SizeX, float SizeY);

	//描画の際にずれが生じて不都合が起こる際は使用する画像の横のサイズを PixelSizeX,縦のサイズを PixelSizeYに入れる
	CSprite(const char* texturePath, int horizontalPartNum, int verticalPartNum, float PosX, float PosY, float SizeX, float SizeY, float PixelSizeX, float PixelSizeY);

	~CSprite();

	void Draw();

	void SetPos(float x, float y);
	void SetPosX(float x);
	void SetSize(float width, float height);
	void SetColor(float r, float g, float b, float a);
	void SetPart(int x, int y);
	float GetPos(char coord);

	void SinJump();

	void Gravity();       // 重力処理(重力でのジャンプの時はこれ)
	void SmallGravity();  // 小さい重力(三角関数でのジャンプの時はこれ)

	//この変数の位置を中心に描画する
	static float mCameraPosX;
	static float mCameraPosY;

	bool enabled = false;

protected:
	int mHorizontalPartNum;
	int mVerticalPartNum;

	float mPosX = 0;
	float mPosY = 0;
	float mSizeWidth = 0;
	float mSizeHeight = 0;


	float mR = 1.0f;
	float mG = 1.0f;
	float mB = 1.0f;
	float mA = 1.0f;

	float mPixelSizeX = 0.0f;			//描画に使用するテクスチャ画像の横のピクセルサイズをUV座標に変換した際の数値
	float mPixelSizeY = 0.0f;			//描画に使用するテクスチャ画像の縦のピクセルサイズをUV座標に変換した際の数値

	bool nowJump = false;  // ジャンプ中かどうか
	float jumpV = 0.01f;    // ジャンプの初速度
	float jumpY = 0.0008f;    // ジャンプの高さ
	float jumpTime = 0.0f;    // ジャンプ時間

	bool nowAir = true;    // 空中にいるかどうか
	float airTime = 0.0f;     // 空中にいる時間

	// 分割されたテクスチャのどれを描画するのか。
	int mPartX = 0; // 0～horizontalPartNum - 1
	int mPartY = 0; // 0～verticalPartNum - 1

	ID3D11Buffer* mpVertexBuffer = nullptr; // = nullptr;
	ID3D11ShaderResourceView* mpTexture = nullptr; // = nullptr;
};