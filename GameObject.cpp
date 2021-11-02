#include "GameObject.h"

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

//ƒWƒƒƒ“ƒv
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
	if (this->mPosY - this->mSizeHeight < GROUND_Y)
	{
		this->mPosY = GROUND_Y + this->mSizeHeight;
		this->nowAir = false;
	}

	if (!this->nowAir)
	{
		this->airTime = 0.0f;
	}

	if (nowAir)
	{
		this->mPosY -= 0.5 * GRAVITY * this->airTime * this->airTime;
		this->airTime += 0.00008f * 10.0f;
	}
}

bool CGameObject::GetNowJump() const
{
	return this->nowJump;
}

bool CGameObject::GetNowAir() const
{
	return this->nowAir;
}