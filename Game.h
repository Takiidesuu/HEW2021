#pragma once

#include "Scene.h"

#define PI 3.1415926535f  // �~����

#define SCREENBOUNDRIGHT 1.0f
#define SCREENBOUNDLEFT -1.0f
#define SCREENBOUNDUP 1.0f
#define SCREENBOUNDDOWN -1.0f


#define CIRCLE_SIZE_ADDITIONAL_SPEED 0.02f  // �~�̑傫���Ȃ鑬��
#define CIRCLE_SIZE_MINIMUM           0.5f  // �~�̍ŏ��T�C�Y
#define CIRCLE_SIZE_MAXIMUM           2.0f  // �~�̍ő�T�C�Y

#define PLAYER_PUNCH_POWER_MINIMUM     0.003f  // �v���C���[�̍ŏ�������΂���
#define PLAYER_PUNCH_POWER_MAXIMUM      0.03f  // �v���C���[�̍ő吁����΂���
#define ENEMY_ATTENUATION           0.000001f  // �G�̐�����΂��ꂽ��̌�����
#define PLAYER_PUNCH_ADDITIONAL_POWER 0.0006f  // ������΂��x�ɂǂ̂��炢�G�������Ȃ邩

#define ENEMY_EXPAND_SIZE    0.03f  // �G������x�ɂǂ̂��炢�傫���Ȃ邩
#define ENEMY_SIZE_MAXIMUM   0.33f  // �G�̍ő�T�C�Y
#define ENEMY_SIZE_INITIALIZE true  // �R���{���؂ꂽ�Ƃ��T�C�Y��߂����ǂ����itrue�F�߂��@false�F�߂��Ȃ��j

#define SLOW_SPEED   10000  // �X���[���x�i���l���傫���قǒx���Ȃ�j
#define SLOW_DARKNESS 0.6f  // �X���[���̈Â��i���l���傫���قǈÂ��Ȃ�i0.0f�`1.0f�j�j

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

	void EnemyMove();

	void NewMove();

	void Uninit();

	int completedLevel = 0;		//���x���ԍ��i���������j

private:
	Input* inputObj;		//�C���v�b�g�I�u�W�F�N�g

	//�`�悷�镨
	CGameObject **sprite;
	CGameObject* background;
	CGameObject ***MapChips;

	CGameObject* playerObj;

	CSprite* BlackoutPanel;

	int level = 0;		//���x���ԍ�
	int speed = 3;

	int slowcnt = 0;

	bool showCircle = false;
	bool smallCircle = false;
	float circleSize = CIRCLE_SIZE_MINIMUM;
	float circleSizeReal = 0.0f;

	//�v���C���[�̌���
	int DragonDirection = 1;
	int OldDragonDirection = 8;

	//�u�Ԉړ��p
	int tpAnim = 0;				//�t���[����
	bool tpAnimFlg = false;		//�u�Ԉړ��A�j���[�V�����t���O�i���s���邩�ǂ����j
	int tpAnimPart = 9;
	int tpAnimSize = 99 / TELEPORTSIZE;
	int tpPlaceHolder = 0;

	//�v���C���[�̍��W
	float DragonPosX;
	float DragonPosY;

	//�G�̍��W
	float GhostPosX;
	float GhostPosY;

	//�G�̃T�C�Y
	float GhostSizeX = 0.15f;
	float GhostSizeY = 0.15f;

	bool GhostCanMove = false;  // �G���ړ��ł��邩�ǂ���
	bool GhostNowMove = false;  // �G���ړ������ǂ���
	int GhostMoveDir0 = MOVE_DIR_NONE;  // �G�̈ړ����������ۑ����邽�߂̕ϐ�
	int GhostMoveDir = MOVE_DIR_NONE;  // �G�̈ړ�������ۑ�����ϐ�
	float GhostMoveCoefficient = 0.003f;  // �G�̈ړ��ʂ̌W��
	int GhostMoveCnt = 0;		//�G�̓������Ԃ��Ǘ�����ϐ�

	int EnemyCombo = 0;  // ���̓G�ɑ΂���R���{��

	bool hit_flg = false;  // �G�Ƃ̓����蔻��p�̕ϐ�

	bool stick_flg = false;

	// ���˗p�̕ϐ�
	float dirX = 1.0f;
	float dirY = 1.0f;

	bool PlayerAlive = true;
	bool EnemyAlive = true;

	//�u�Ԉړ��O�̈ʒu
	float Old_Player_PosX = 0.0f;
	float Old_Player_PosY = 0.0f;

	bool hitMapchip_Player_flg = false;
};

extern int Savehitmaphipnum[100][3];			//�����蔻��̂���}�b�v�`�b�v�̔z��ԍ���ۑ�����z��