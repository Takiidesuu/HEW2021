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

	bool nowAir = true;		// �󒆂ɂ��邩�ǂ���

	bool GetNowJump() const;
	bool GetNowAir() const;  // �󒆂ɂ��邩�擾

	//���̕ϐ��̈ʒu�𒆐S�ɕ`�悷��
	static float mCameraPosX;
	static float mCameraPosY;


protected:
	bool nowJump = false;  // �W�����v�����ǂ���
	float jumpV = 0.01f;    // �W�����v�̏����x
	float jumpY = 0.0008f;    // �W�����v�̍���
	float jumpTime = 0.0f;    // �W�����v����

	float airTime = 0.0f;		// �󒆂ɂ��鎞��
};