#include "GameObject.h"

float CGameObject::mCameraPosX = 0.0f;
float CGameObject::mCameraPosY = 0.0f;

CGameObject::CGameObject(const char* texturePath, int horizontalPartNum, int verticalPartNum, float PosX, float PosY, float SizeX, float mSizeHeight) :CSprite(texturePath, horizontalPartNum, verticalPartNum, PosX, PosY, SizeX, mSizeHeight) {

}

CGameObject::CGameObject(const char* texturePath, int horizontalPartNum, int verticalPartNum, float PosX, float PosY, float SizeX, float mSizeHeight, float PixelSizeX, float PixelmSizeHeight) : CSprite(texturePath, horizontalPartNum, verticalPartNum, PosX, PosY, SizeX, mSizeHeight, PixelSizeX, PixelmSizeHeight) {

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