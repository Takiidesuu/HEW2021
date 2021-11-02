#pragma once

#include "Sprite.h"

#define GRAVITY 0.09f
#define JUMPPOWER 5.0f
//
struct TPos_and_Size {
	float posx, posy;
	float sizex, sizey;
};

class CGameObject :public CSprite {
public:
	CGameObject(const char* texturePath, int horizontalPartNum, int verticalPartNum, float PosX, float PosY, float SizeX, float SizeY);
	CGameObject(const char* texturePath, int horizontalPartNum, int verticalPartNum, float PosX, float PosY, float SizeX, float SizeY, float PixcelSizeX, float PixcelSizeY);
	virtual void Update();
	TPos_and_Size GetPosAndSize();
	void GravityJump();
	void Gravity();

	bool GetNowJump() const;
	bool GetNowAir() const;  // �󒆂ɂ��邩�擾

protected:
	bool nowJump = false;  // �W�����v�����ǂ���
	float jumpV = 0.01f;    // �W�����v�̏����x
	float jumpY = 0.0008f;    // �W�����v�̍���
	float jumpTime = 0.0f;    // �W�����v����

	bool nowAir = true;		// �󒆂ɂ��邩�ǂ���
	float airTime = 0.0f;		// �󒆂ɂ��鎞��
};