#pragma once

#include <stdio.h>
#include <iostream>

enum LAST_NUM
{
	/*�@�X�^�[�P�@*/
	// ���[���h�P
	LAST_111, LAST_112, LAST_113,

	// ���[���h�Q
	LAST_121, LAST_122, LAST_123,

	/*�@�X�^�[�Q�@*/
	// ���[���h�P
	LAST_211, LAST_212, LAST_213,

	// ���[���h�Q
	LAST_221, LAST_222, LAST_223,

	/*�@�X�^�[�R�@*/
	// ���[���h�P
	LAST_311, LAST_312, LAST_313,

	// ���[���h�Q
	LAST_321, LAST_322, LAST_323,
};

// �Z�[�u�f�[�^�̒��g
typedef struct {

	// �X�^�[�̒��g
	typedef struct {

		// ���[���h�̒��g
		typedef struct {

			bool	Stage1;	// �X�e�[�W�P
			bool	Stage2;	// �X�e�[�W�Q 
			bool	Stage3;	// �X�e�[�W�R

		}WORLD;

		WORLD	World1;	// ���[���h�P
		WORLD	World2;	// ���[���h�Q

	}STAR;

	STAR	Star1;	// �X�^�[�P
	STAR	Star2;	// �X�^�[�Q
	STAR	Star3;	// �X�^�[�R

	int		Last;
	bool	Del;

}SAVE_DATA;

class Save_Load
{
public:
	void Percent1();						// �N���A���𓚂���֐�
	void Percent2();						// �N���A���𓚂���֐�
	void Percent3();						// �N���A���𓚂���֐�

	// �Z�[�u����֐�
	void Save1(
		int		star_num,	// �X�^�[�l
		int		world_num,	// ���[���h�l
		int		stage_num,	// �X�e�[�W�l
		bool	Clear_FLG,	// �N���A����
		bool	Del_FLG		// �폜����
	);
	// �Z�[�u����֐�
	void Save2(
		int		star_num,	// �X�^�[�l
		int		world_num,	// ���[���h�l
		int		stage_num,	// �X�e�[�W�l
		bool	Clear_FLG,	// �N���A����
		bool	Del_FLG		// �폜����
	);
	// �Z�[�u����֐�
	void Save3(
		int		star_num,	// �X�^�[�l
		int		world_num,	// ���[���h�l
		int		stage_num,	// �X�e�[�W�l
		bool	Clear_FLG,	// �N���A����
		bool	Del_FLG		// �폜����
	);

	char Load1();							// ���[�h����֐�
	char Load2();							// ���[�h����֐�
	char Load3();							// ���[�h����֐�

	void Last1();							// �Ō�Ƀv���C�������[���h�E�X�e�[�W�𓚂���֐�
	void Last2();							// �Ō�Ƀv���C�������[���h�E�X�e�[�W�𓚂���֐�
	void Last3();							// �Ō�Ƀv���C�������[���h�E�X�e�[�W�𓚂���֐�

	void Answer1();							// ���[�h�������l�𓚂���֐�
	void Answer2();							// ���[�h�������l�𓚂���֐�
	void Answer3();							// ���[�h�������l�𓚂���֐�

	void Initialize_Data1(bool New_or_Del);	// �Z�[�u�f�[�^������������֐�
	void Initialize_Data2(bool New_or_Del);	// �Z�[�u�f�[�^������������֐�
	void Initialize_Data3(bool New_or_Del);	// �Z�[�u�f�[�^������������֐�

	void SWS_true1();						// �ǂ���true���邩���͂���֐�
	void SWS_true2();						// �ǂ���true���邩���͂���֐�
	void SWS_true3();						// �ǂ���true���邩���͂���֐�

private:
	SAVE_DATA	data1;		// 1�ԖڃZ�[�u�f�[�^
	SAVE_DATA	data2;		// 2�ԖڃZ�[�u�f�[�^
	SAVE_DATA	data3;		// 3�ԖڃZ�[�u�f�[�^

	typedef struct {
		int Plus = 0;		// Percent�֐��ŃN���A�������v���鐔�l
		float Percent = 0;	// Percent�֐��ŃN���A���������v���鐔�l
	}CLEAR;

	CLEAR Clear1;
	CLEAR Clear2;
	CLEAR Clear3;

	int star_num;			// WS_true�֐��ŃX�^�[���w�肷�鐔�l
	int world_num;			// WS_true�֐��Ń��[���h���w�肷�鐔�l
	int stage_num;			// WS_true�֐��ŃX�e�[�W���w�肷�鐔�l
	bool loop;				// WS_true�֐��̍ۂɃ��[�v����t���O
};

extern Save_Load* saveloadObj;