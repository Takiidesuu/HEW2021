#pragma once

#include <math.h>
#include <d3d11.h>	// マイクロソフト提供のDirectX11ヘッダーファイルをインクルード

struct TPos {
	float x, y;
};

// ****************************************
// プリプロセッサ定数・マクロ定義
// ****************************************

// COMオブジェクトをNULLチェックしてからReleaseする
#define COM_SAFE_RELEASE(o)   if(NULL!=o){o->Release();o=NULL;}

#define MAXSPRITE 64

#define RESOLUTIONX 1920
#define RESOLUTIONY 1080

// ****************************************
// 公開する関数のプロトタイプ宣言
// ****************************************

// Direct3D11 Device*を返す
ID3D11Device* Direct3D_GetDevice();

// Direct3D11 Immidiate Context*を返す
ID3D11DeviceContext* Direct3D_GetContext();

// Direct3D11 SwapChain*を返す
IDXGISwapChain* Direct3D_GetSwapChain();

// Direct3D11 RenderTargetView*を返す
ID3D11RenderTargetView* Direct3D_GetRenderTargetView();

// DirextX11の初期化を担当する関数（の定義）
HRESULT Direct3D_Initialize(HWND hWnd);

// Direct3D関連で作成したオブジェクトをすべて開放する
void Direct3D_Release();

// 指定したファイル名のテクスチャファイル（画像ファイル）を読み込む
HRESULT Direct3D_LoadTexture(const char* pFileName, ID3D11ShaderResourceView** pOupSRV);

//*****************************************************************************
// 構造体定義
//*****************************************************************************

struct VERTEX_POSTEX {
	float x, y, z;  // 頂点の位置

	float r, g, b, a; //色と透明度

	float u, v;  // テクスチャのUV座標
};


//Spriteクラスの定義
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

	virtual void Draw();								//描画処理

	bool reverse_flg = false;							//反転フラグ

	float rotationAngle = 0.0f;                         //回転角度

	void SetPos(float x, float y);						//マップ上の座標を指定する
	void SetPosX(float x);								//X座標の指定
	void SetPosY(float y);								//Y座標の指定
	void SetSize(float width, float height);			//オブジェクトのサイズを指定する
	void SetColor(float r, float g, float b, float a);	//オブジェクトの透明度と色の倍率を指定する
	void SetPart(int x, int y);							//使用するテクスチャの位置を指定する
	TPos GetPos();
	virtual void Update();

	bool enabled = false;

protected:
	int mHorizontalPartNum;				//横に何分割するか
	int mVerticalPartNum;				//横に何分割するか

	float mPosX = 0;					//マップ上でのX座標
	float mPosY = 0;					//マップ上でのY座標
	float mSizeWidth = 0;				//横のサイズ
	float mSizeHeight = 0;				//縦のサイズ

	float mR = 1.0f;					//赤色の強さの倍率
	float mG = 1.0f;					//緑色の強さの倍率
	float mB = 1.0f;					//青色の強さの倍率
	float mA = 1.0f;					//透明度

	float mPixelSizeX = 0.0f;			//描画に使用するテクスチャ画像の横のピクセルサイズをUV座標に変換した際の数値
	float mPixelSizeY = 0.0f;			//描画に使用するテクスチャ画像の縦のピクセルサイズをUV座標に変換した際の数値

	// 分割されたテクスチャのどれを描画するのか
	int mPartX = 0;
	int mPartY = 0;

	bool fixedCamera = false;

	float fixedCameraPosX;
	float fixedCameraPosY;

	ID3D11Buffer* mpVertexBuffer = nullptr;
	ID3D11ShaderResourceView* mpTexture = nullptr;
};