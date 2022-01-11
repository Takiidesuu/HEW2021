#include "GameObject.h"

VECTOR CGameObject::moveV[8];

void CGameObject::Init_moveV() {
	// 移動用ベクトルを8方向分作成
	for (int i = 0; i < 8; i++) {
		moveV[i].vx = cosf((float)i * PI / 4.0f);
		moveV[i].vy = sinf((float)i * PI / 4.0f);
	}
}

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

MapChipPosNum CGameObject::GetMapChipPos()
{
	MapChipPosNum mappos;

	//1 - i * MAPCHIP_SIZE - MAPCHIP_SIZE / 2

	mappos.NumY = 18 - ((mPosY + 1) / MAPCHIP_SIZE);

	mappos.NumX = (mPosX + 1.7777f) / MAPCHIP_SIZE;

	return mappos;
}

void CGameObject::Gravity()
{
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