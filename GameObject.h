#pragma once

#include "Sprite.h"
#include "MapChip.h"

#define GRAVITY 0.8f        // �d��
//#define JUMPPOWER 5.0f
//#define GROUND_Y -0.8f
//#define MOVESPEED 1.0f

#define PI 3.1415926535f	// �~����

#define TELEPORTSIZE 2

// �ړ������p�̒萔
enum {
	MOVE_DIR_NONE,
	MOVE_DIR_RIGHT,
	MOVE_DIR_UPPER_RIGHT,
	MOVE_DIR_UP,
	MOVE_DIR_UPPER_LEFT,
	MOVE_DIR_LEFT,
	MOVE_DIR_LOWER_LEFT,
	MOVE_DIR_DOWN,
	MOVE_DIR_LOWER_RIGHT,
};

//�ʒu�Ƒ傫���@�����蔻��Ŏg�p����
struct TPos_and_Size {
	float posx, posy;
	float sizex, sizey;
};

// float�^�̃x�N�g���p�\����
struct VECTOR {
	float vx;
	float vy;
};

struct MapChipPosNum {
	int NumY;
	int NumX;
};


class CGameObject : public CSprite {
public:
	static VECTOR moveV[8];  // �ړ��p�x�N�g��

	static void Init_moveV();

	CGameObject(const char* texturePath, int horizontalPartNum, int verticalPartNum, float PosX, float PosY, float SizeX, float SizeY);
	CGameObject(const char* texturePath, int horizontalPartNum, int verticalPartNum, float PosX, float PosY, float SizeX, float SizeY, float PixcelSizeX, float PixcelSizeY);

	virtual void Update();
	TPos_and_Size GetPosAndSize();

	MapChipPosNum GetMapChipPos();

	void Gravity();

	void SetAirTime(float t);
	void SetNowAir(bool air);

	bool nowAir = true;		// �󒆂ɂ��邩�ǂ���

	bool GetNowJump() const;

protected:
	bool nowJump = false;  // �W�����v�����ǂ���
	float jumpV = 0.01f;    // �W�����v�̏����x
	float jumpY = 0.0008f;    // �W�����v�̍���
	float jumpTime = 0.0f;    // �W�����v����

	float airTime = 0.0f;		// �󒆂ɂ��鎞��
};