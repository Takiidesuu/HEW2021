#include "GameObject.h"

float CGameObject::mCameraPosX = 0.0f;
float CGameObject::mCameraPosY = 0.0f;

CGameObject::CGameObject(const char* texturePath, int horizontalPartNum, int verticalPartNum, float PosX, float PosY, float SizeX, float mSizeHeight) :CSprite(texturePath, horizontalPartNum, verticalPartNum, PosX, PosY, SizeX, mSizeHeight) {

}

CGameObject::CGameObject(const char* texturePath, int horizontalPartNum, int verticalPartNum, float PosX, float PosY, float SizeX, float mSizeHeight, float PixelSizeX, float PixelmSizeHeight) : CSprite(texturePath, horizontalPartNum, verticalPartNum, PosX, PosY, SizeX, mSizeHeight, PixelSizeX, PixelmSizeHeight) {

}

void CGameObject::Draw()
{
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

void CGameObject::Update(void)
{

}

TPos_and_Size CGameObject::GetPosAndSize()
{
	TPos_and_Size Pos_and_Size{ mPosX,mPosY,mSizeWidth,mSizeHeight };

	return Pos_and_Size;
}

void CGameObject::SinJump()
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

//ジャンプ
void CGameObject::GravityJump()
{
	if (!this->nowAir)
	{
		this->nowJump = true;
		this->nowAir = true;
	}

	if (this->nowJump)
	{
		this->mPosY += this->jumpV * this->jumpTime * 100.0f * JUMPPOWER;
		this->jumpTime += 0.00008f;

		if (this->jumpV * this->jumpTime <= 0.5f * GRAVITY * this->airTime * this->airTime)
		{
			this->nowJump = false;
			this->airTime = 0.0f;
			this->jumpTime = 0.0f;
		}
	}
}

void CGameObject::Gravity()
{
	//空中にいるか否か
	/*if (this->mPosY - this->mSizeHeight / 2.0f < GROUND_Y)
	{
		this->mPosY = GROUND_Y + this->mSizeHeight / 2.0f;
		this->nowAir = false;
	}
	else
	{
		nowAir = true;
	}*/

	//接地した場合空中滞在時間をリセットする
	if (!this->nowAir)
	{
		this->airTime = 0.0f;
	}

	if (this->nowAir)
	{
		this->mPosY -= 0.5 * GRAVITY * this->airTime * this->airTime;
		this->airTime += 0.00008f * 10.0f;
	}

}

void CGameObject::SetAirTime(float t)
{
	this->airTime = t;
}

void CGameObject::SetNowAir(bool air)
{
	this->nowAir = air;
}

bool CGameObject::GetNowJump() const
{
	return this->nowJump;
}

bool CGameObject::GetNowAir() const
{
	return this->nowAir;
}