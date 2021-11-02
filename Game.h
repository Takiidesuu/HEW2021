#pragma once

#include "Scene.h"

#define PI 3.1415926535f  // �~����

// 2�_�����񂾒����̊p�x���v�Z����֐�
float Angle(float x1, float y1, float x2, float y2);

// float�^�̃x�N�g���p�\����
struct VECTOR {
	float vx;
	float vy;
};

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

class GameClass : public Scene
{
public:
	bool Init();		//������
	bool Update();		//�Q�[�����[�v
	void Draw();

	int completedLevel = 0;		//���x���ԍ��i���������j

private:
	Input* inputObj;		//�C���v�b�g�I�u�W�F�N�g

	//�`�悷�镨
	CGameObject **sprite;
	CSprite* background;
	CSprite ***MapChips;

	CGameObject* playerObj;

	int level = 0;		//���x���ԍ�
	int speed = 3;
};