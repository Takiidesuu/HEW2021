#include "Sprite.h"

float CSprite::mCameraPosX = 0.0f;
float CSprite::mCameraPosY = 0.0f;

CSprite::CSprite(const char* texturePath, int horizontalPartNum, int verticalPartNum, float PosX, float PosY, float SizeX, float SizeY) {

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
}

CSprite::CSprite(const char * texturePath, int horizontalPartNum, int verticalPartNum, float PosX, float PosY, float SizeX, float SizeY, float PixcelSizeX, float PixcelSizeY)
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

	mPixelSizeX = 1.0f / PixcelSizeX;			//描画に使用するテクスチャ画像の横のピクセルサイズをUV座標に変換した際の数値
	mPixelSizeY = 1.0f / PixcelSizeY;			//描画に使用するテクスチャ画像の縦のピクセルサイズをUV座標に変換した際の数値
}

//relese
CSprite::~CSprite() {
	COM_SAFE_RELEASE(mpTexture);
	COM_SAFE_RELEASE(mpVertexBuffer);
}


void CSprite::Draw() {
	//画面外のオブジェクトは描画処理を行わない
	if ((this->mPosX + this->mSizeWidth / 2 - this->mCameraPosX > -1.0) && (this->mPosX - this->mSizeWidth / 2 - this->mCameraPosX < 1.0) && (this->mPosY + this->mSizeHeight / 2 - this->mCameraPosY > -1.0) && (this->mPosY - this->mSizeHeight / 2 - this->mCameraPosY < 1.0))
	{
		// 描画で使うテクスチャをセット。
		Direct3D_GetContext()->PSSetShaderResources(0, 1, &mpTexture);

		// 描画で使う頂点バッファをセット。
		UINT strides = sizeof(VERTEX_POSTEX);
		UINT offsets = 0;
		Direct3D_GetContext()->IASetVertexBuffers(0, 1, &mpVertexBuffer, &strides, &offsets);

		//カメラの位置でXY座標を補正する
		float DrawX = (mPosX - mCameraPosX);
		float DrawY = (mPosY - mCameraPosY);

		// 頂点シェーダーの情報を組み立てる。
		float Left = DrawX - mSizeWidth / 2;		//左座標
		float Right = DrawX + mSizeWidth / 2;		//右座標
		float Top = DrawY + mSizeHeight / 2;		//上座標
		float Bottum = DrawY - mSizeHeight / 2;		//下座標

		// テクスチャの一分割分のuv値を割り出す。
		float SizeU = 1.0 / mHorizontalPartNum;
		float SizeV = 1.0 / mVerticalPartNum;

		// 指定した描画部分のuv値を計算する。
		float LeftU = mPartX * SizeU + mPixelSizeX;					//テクスチャ左座標
		float RightU = (mPartX + 1) * SizeU - mPixelSizeX;			//テクスチャ右座標
		float TopV = mPartY * SizeV + mPixelSizeY;					//テクスチャ上座標
		float BottumV = (mPartY + 1) *SizeV - mPixelSizeY;			//テクスチャ下座標


		VERTEX_POSTEX vertexData[] = {
			{Left, Top, 0,
			mR,mG,mB,mA,
			LeftU, TopV},

			{Right, Top, 0,
			mR,mG,mB,mA,
			RightU, TopV},

			{Right, Bottum, 0,
			mR,mG,mB,mA,
			RightU, BottumV},

			{Right, Bottum, 0,
			mR,mG,mB,mA,
			RightU, BottumV},

			{Left, Bottum, 0,
			mR,mG,mB,mA,
			LeftU, BottumV},

			{Left, Top, 0,
			mR,mG,mB,mA,
			LeftU, TopV},
		};

		// 頂点バッファを更新
		Direct3D_GetContext()->UpdateSubresource(mpVertexBuffer, 0, NULL, vertexData, 0, 0);

		// スプライト描画。
		Direct3D_GetContext()->Draw(6, 0);
	}
}

//位置を設定（ｘ、ｙ）
void CSprite::SetPos(float x, float y) {
	mPosX = x;
	mPosY = y;
}

//位置を設定（ｘのみ）
void CSprite::SetPosX(float x)
{
	mPosX = x;
}

//サイズ設定
void CSprite::SetSize(float width, float height) {
	mSizeWidth = width;
	mSizeHeight = height;
}


void CSprite::SetColor(float r, float g, float b, float a)
{
	this->mR = r;
	this->mG = g;
	this->mB = b;
	this->mA = a;
}

//アニメーション用（画像のパーツを設定）
void CSprite::SetPart(int x, int y) {
	mPartX = x;
	mPartY = y;
}

float CSprite::GetPos(char coord)
{
	if (coord == 'x')
		return this->mPosX;
	if (coord == 'y')
		return this->mPosY;
}


void CSprite::SinJump()
{
	float pi = 3.14159265358979f;

	if (!this->nowAir)
	{
		this->nowJump = true;
	}

	if (this->nowJump)
	{
		this->mPosY += this->jumpY * sin(pi * jumpTime);
		this->jumpTime += 0.0005f;
	}

	if (this->jumpTime >= 2.0f)
	{
		this->jumpTime = 0.0f;
		this->nowJump = false;
	}
}

void CSprite::Gravity()
{
	if (this->mPosY - (this->mSizeHeight / 2) < GROUND_Y)
	{
		this->mPosY = GROUND_Y + (this->mSizeHeight / 2);
		this->nowAir = false;
	}

	if (!this->nowAir)
	{
		this->airTime = 0.0f;
	}
	else
	{
		this->mPosY -= 0.5 * GRAVITY * this->airTime * this->airTime;
		this->airTime += 0.00008f * 5.0f;
	}
}

void CSprite::SmallGravity()
{
	if (this->mPosY - this->mSizeHeight < GROUND_Y)
	{
		this->mPosY = GROUND_Y - this->mSizeHeight;
		this->nowAir = false;
	}

	if (this->nowAir)
	{
		this->mPosY -= 0.00078f;
	}
}