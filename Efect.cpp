#include "Efect.h"

int CEfect::EfectCnt = 0;

CEfect::CEfect(bool loopflg, const char* texturePath, int horizontalPartNum, int verticalPartNum, float PosX, float PosY, float SizeX, float SizeY) :CGameObject(texturePath, horizontalPartNum, verticalPartNum, PosX, PosY, SizeX, SizeY)
{
	HRESULT hr;

	// 頂点バッファ用意。
	D3D11_BUFFER_DESC bufferDesc;
	bufferDesc.ByteWidth = sizeof(VERTEX_POSTEX) * 6;
	bufferDesc.Usage = D3D11_USAGE_DEFAULT;
	bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bufferDesc.CPUAccessFlags = 0;
	bufferDesc.MiscFlags = 0;
	bufferDesc.StructureByteStride = 0;

	hr = Direct3D_GetDevice()->CreateBuffer(&bufferDesc, NULL, &mpVertexBuffer);
	if (FAILED(hr)) {
		MessageBoxA(nullptr, "頂点バッファー作成失敗。", "Error", MB_OK);
		exit(-1);
	}

	// テクスチャ読み込み。
	hr = Direct3D_LoadTexture(texturePath, &mpTexture);
	if (FAILED(hr)) {
		char errorMsg[256] = "テクスチャ読み込み失敗: ";
		strcat_s(errorMsg, texturePath);
		MessageBoxA(nullptr, errorMsg, "Error", MB_OK);
		exit(-1);
	}

	mHorizontalPartNum = horizontalPartNum;		//使用するテクスチャの横の分割数
	mVerticalPartNum = verticalPartNum;			//使用するテクスチャの縦の分割数

	this->mPosX = PosX;							//X座標
	this->mPosY = PosY;							//Y座標
	mSizeWidth = SizeX;							//Xのサイズ
	mSizeHeight = SizeY;						//Yのサイズ

	loop_reproducing = loopflg;
	EfectCnt++;
}

CEfect::CEfect(bool loopflg, const char * texturePath, int horizontalPartNum, int verticalPartNum, float PosX, float PosY, float SizeX, float SizeY, float PixelSizeX, float PixelSizeY) :CGameObject(texturePath, horizontalPartNum, verticalPartNum, PosX, PosY, SizeX, SizeY, PixelSizeX, PixelSizeY)
{
	HRESULT hr;

	// 頂点バッファ用意。
	D3D11_BUFFER_DESC bufferDesc;
	bufferDesc.ByteWidth = sizeof(VERTEX_POSTEX) * 6;
	bufferDesc.Usage = D3D11_USAGE_DEFAULT;
	bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bufferDesc.CPUAccessFlags = 0;
	bufferDesc.MiscFlags = 0;
	bufferDesc.StructureByteStride = 0;

	hr = Direct3D_GetDevice()->CreateBuffer(&bufferDesc, NULL, &mpVertexBuffer);
	if (FAILED(hr)) {
		MessageBoxA(nullptr, "頂点バッファー作成失敗。", "Error", MB_OK);
		exit(-1);
	}

	// テクスチャ読み込み。
	hr = Direct3D_LoadTexture(texturePath, &mpTexture);
	if (FAILED(hr)) {
		char errorMsg[256] = "テクスチャ読み込み失敗: ";
		strcat_s(errorMsg, texturePath);
		MessageBoxA(nullptr, errorMsg, "Error", MB_OK);
		exit(-1);
	}

	mHorizontalPartNum = horizontalPartNum;		//使用するテクスチャの横の分割数
	mVerticalPartNum = verticalPartNum;			//使用するテクスチャの縦の分割数

	this->mPosX = PosX;							//X座標
	this->mPosY = PosY;							//Y座標
	mSizeWidth = SizeX;							//Xのサイズ
	mSizeHeight = SizeY;						//Yのサイズ

	mPixelSizeX = 1.0f / PixelSizeX;			//描画に使用するテクスチャ画像の横のピクセルサイズをUV座標に変換した際の数値
	mPixelSizeY = 1.0f / PixelSizeY;			//描画に使用するテクスチャ画像の縦のピクセルサイズをUV座標に変換した際の数値

	loop_reproducing = loopflg;
	EfectCnt++;
}

CEfect::~CEfect()
{
	//テクスチャと頂点バッファの解放処理
	COM_SAFE_RELEASE(mpTexture);
	COM_SAFE_RELEASE(mpVertexBuffer);

	EfectCnt--;
}

void CEfect::Anim()
{
	//横の分割数（mHorizontalPartNum）をアニメーションのコマの数として扱う
	if (reproducing_complete == false) {

		static int animtest = 0;
		
		animtest++;
		
		if (animtest == 30) {
			SetPart(anim_num, 0);
			anim_num++;
			if (anim_num == mHorizontalPartNum) {//一周したら 
				anim_num = 0;
				if (loop_reproducing == false) {//ルール再生しない場合
					reproducing_complete = true;
					mA = 0.0f;
				}

			}
			animtest = 0;
		}
	}
}


