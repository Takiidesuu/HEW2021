#pragma once
#include "GameObject.h"

#define PLAYER_PUNCH_POWER_MINIMUM     0.003f  // �v���C���[�̍ŏ�������΂���
#define PLAYER_PUNCH_POWER_MAXIMUM      0.03f  // �v���C���[�̍ő吁����΂���
#define ENEMY_ATTENUATION           0.000001f  // �G�̐�����΂��ꂽ��̌�����
#define PLAYER_PUNCH_ADDITIONAL_POWER 0.0006f  // ������΂��x�ɂǂ̂��炢�G�������Ȃ邩

#define ENEMY_EXPAND_SIZE    0.04f  // �G������x�ɂǂ̂��炢�傫���Ȃ邩
#define ENEMY_SIZE_MAXIMUM   0.44f  // �G�̍ő�T�C�Y

//������΂�������p�̒萔
enum E_BLOW_DIR {
	BLOW_DIR_NONE,
	BLOW_DIR_RIGHT,
	BLOW_DIR_UPPER_RIGHT,
	BLOW_DIR_UP,
	BLOW_DIR_UPPER_LEFT,
	BLOW_DIR_LEFT,
	BLOW_DIR_LOWER_LEFT,
	BLOW_DIR_DOWN,
	BLOW_DIR_LOWER_RIGHT,
};

class CEnemy :public CGameObject
{
public:
	CEnemy(const char* texturePath, int horizontalPartNum, int verticalPartNum, float PosX, float PosY, float SizeX, float SizeY);

	virtual void mMove();						//�ړ��֐�

	virtual void mSearch(TPos);					//���G�֐��@�����ɍ��G�Ώۂ�GetPos()�֐�������

	virtual void mAttack() = 0;					//�U���֐��@

	virtual void mAnim() = 0;					//�A�j���[�V�����֐�

	void mAttacked();							//�U�����󂯂��ۂ̏���



	bool mAtk_flg = false;						//�U�������ۂ�

	int mEnemyCombo = 0;						//�A���Ő�����΂��ꂽ��
	bool mStartBlown_flg = false;				//������΂��ꂽ�ۂ̃t���O
	bool mNow_Blown_flg = false;				//������΂���Ă�ۂ̃t���O
	E_BLOW_DIR mBlownDir0 = BLOW_DIR_NONE;		//�G�̈ړ����������ۑ����邽�߂̕ϐ�
	E_BLOW_DIR mBlownDir = BLOW_DIR_NONE;		//�G�̈ړ�������ۑ�����ϐ�
	float mBlownCoefficient = 0.003f;			//�G�̈ړ��ʂ̌W��
	int mBlownCnt = 0;							//�G�̓������Ԃ��Ǘ�����ϐ�

	bool mEnemyHit_flg = false;                 //�G�ƃv���C���[�̓����蔻��

	float mBlown_DirX = 1.0f;					//X���̔��˗p�̕ϐ�
	float mBlown_DirY = 1.0f;					//Y���̔��˗p�̕ϐ�

	void mBlowm();								//�������

	bool mEnemyAlive = true;					//�����t���O

	int mAbleBroken_Num;						//�j��\�ɂȂ�U����

	bool mAbleBroken = false;					//�j��\�t���O

	bool mMoveflg = true;						//�ړ������̃t���O

	int mMoveDir = MOVE_DIR_NONE;				//�ړ�����

protected:
	int mAnimCnt = 0;							//�A�j���[�V�����X�V�p�x�Ǘ��p�ϐ�

	bool mAnimFlg = true;						//�A�j���[�V�������邩�̊֐�

	float mSpeed;								//�ʏ�ړ����x
	float mTracking_Speed;						//�ǐՎ��ړ����x

	bool mDiscovery_flg = false;				//�v���C���[�����t���O

	float mSearch_DistanceX;					//�v���C���[��������X
	float mSearch_DistanceY;					//�v���C���[��������Y
};