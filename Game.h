#pragma once

#include "Scene.h"
#include "Efect.h"

#define PI 3.1415926535f  // �~����

#define SCREENBOUNDRIGHT 1.0f
#define SCREENBOUNDLEFT -1.0f
#define SCREENBOUNDUP 1.0f
#define SCREENBOUNDDOWN -1.0f

#define CIRCLE_SIZE_ADDITIONAL_SPEED 0.10f  // �~�̑傫���Ȃ鑬��
#define CIRCLE_SIZE_MINIMUM           0.5f  // �~�̍ŏ��T�C�Y
#define CIRCLE_SIZE_MAXIMUM           6.0f  // �~�̍ő�T�C�Y

#define PLAYER_INVINCIBLE_COUNT	500  // �v���C���[�̃_���[�W��̖��G�J�E���g

#define ENEMY_SIZE_INITIALIZE true  // �R���{���؂ꂽ�Ƃ��T�C�Y��߂����ǂ����itrue�F�߂��@false�F�߂��Ȃ��j
#define CAN_EXPLODE_ENEMY_COUNT  5  // �G�𔚔j�ł���悤�ɂȂ��

#define SLOW_SPEED   50000  // �X���[���x�i���l���傫���قǒx���Ȃ�j
#define SLOW_DARKNESS 0.5f  // �X���[���̈Â��i���l���傫���قǈÂ��Ȃ�i0.0f�`1.0f�j�j

#define ANIMSPEED 50	//�R���[���A�j���[�V�����X�s�[�h

#define GIMMICKNUM 10		//�M�~�b�N�}�b�N�X��
#define GIMMICKSIZEX 0.15f
#define GIMMICKSIZEY 0.15f

// 2�_�����񂾒����̊p�x���v�Z����֐�
float Angle(float x1, float y1, float x2, float y2);

class GameClass : public Scene
{
public:
	void Init();		//������
	bool Update();		//�Q�[�����[�v
	void Draw();

	void EnemyBlow(int);

	void NewMove();
	void StageReset();
	void Uninit();

	int completedLevel = 0;		//���x���ԍ��i���������j

private:
	int Star_Num = 0;
	int World_Num = 0;
	int Stage_Num = 0;

	Input* inputObj;		//�C���v�b�g�I�u�W�F�N�g

	CEnemy **enemy;
	int EnemyNum;

	//�`�悷�镨
	CGameObject **sprite;
	CSprite **background;
	CMapChip ***MapChips;
	CGameObject **gimmick;

	CGameObject* playerObj;

	CSprite* BlackoutPanel;

	CGameObject** fuel;

	int level = 0;		//���x���ԍ�
	int speed = 3;

	int slowcnt = 0;

	bool Blackout = true;
	float BlackoutPanelAlpha = 0.0f;

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

	bool hit_flg = false;  // �G�Ƃ̓����蔻��p�̕ϐ�

	bool stick_flg = false;

	bool PlayerAlive = true;
	//bool EnemyAlive = true;

	//�u�Ԉړ��O�̈ʒu
	float Old_Player_PosX = 0.0f;
	float Old_Player_PosY = 0.0f;

	// �u�Ԉړ������Ƃ��̓G�̈ʒu
	float TeleEnemyPosX = 0.0f;
	float TeleEnemyPosY = 0.0f;

	float previousPosX = 0.0f;
	float previousPosY = 0.0f;

	bool hitMapchip_Player_flg = false;

	// �X�e�[�W�N���A�������ǂ���
	bool stageClear = false;
	// �X�e�[�W�Ɏc���Ă�R���̐�
	int getFuel = 0;
	// �R���̈ʒu
	float fuelPosX[3] = { 0.0f, 0.0f, 0.0f };
	float fuelPosY[3] = { 0.0f, 0.0f, 0.0f };
	// �R���̃T�C�Y
	float fuelSizeX = 0.15f;
	float fuelSizeY = 0.15f;

	// �N���A������on��off��
	bool clearProcess = true;
	// �����蔻����������邩
	bool collisionAppear = true;
	// �G�̐�����΂��p�^�[��
	int blowOffPattern = 1;
	// ��荞�ނ��ǂ���
	bool goAround = false;
	// �G�̓����蔻�肪��`���~���i1�F��` 2�F�~�j
	int enemyCollisionShape = 2;

	// �G��j��ł��邩�ǂ���
	bool enemyCanBreak = false;
	// �G��j�󂷂邩�ǂ���
	bool enemyBreak = false;
	// �X�e�[�W�Ɏc���Ă�G�̐�
	int remainingEnemy = 1;

	// �G��ǔ����邩
	bool enemyHoming = true;
	// �~�ɓ�������ǔ�����悤�ɂ��邩
	bool circleHoming = true;

	// �v���C���[��HP
	int playerHp = 3;
	// �_���[�W������������ォ
	bool justAfterDamage = false;
	// ���G��Ԃ̃J�E���g
	int invincibleCnt = 0;
	// �Q�[���I�[�o�[���ǂ���
	bool gameover = false;

	// �~�o���̉����Ȃ炷���ǂ���
	bool circleSound = true;
	// �e���|�[�g�̉����Ȃ炷���ǂ���
	bool teleportSound = true;
	// �e���|�[�g�̉��p�^�[��
	int teleportSoundPattern = 1;

	int playerAnimCnt = 0;
	int playerAnimPartX = 0;
	int playerAnimPartY = 0;
	int animSpeed = ANIMSPEED;
	bool playerBlowAnim = false;
};

extern int Savehitmaphipnum[200][3];			//�����蔻��̂���}�b�v�`�b�v�̔z��ԍ���ۑ�����z��