#pragma once

#include <stdio.h>
#include <iostream>

typedef struct {
	typedef struct {
		bool Stage1;
		bool Stage2;
		bool Stage3;
	}WORLD;

	WORLD	World1;
	WORLD	World2;
	WORLD	World3;
	WORLD	World4;
	WORLD	World5;
	WORLD	World6;

	bool Del;

}SAVE_DATA;

class Save_Load
{
public:
	// �Z�[�u����֐��i���[���h�l	�X�e�[�W�l	�N���A����	�폜����j
	void Save(int world_num, int stage_num, bool Clear_FLG, bool Del_FLG);
	char Load();							// ���[�h����֐�
	void Answer();							// ���[�h�������l�𓚂���֐�
	void Initialize_Date(bool New_or_Del);	// �Z�[�u�f�[�^������������֐�
	void WS_true();							// �ǂ���true���邩���͂���֐�

private:
	SAVE_DATA	data;	// 
	int world_num;		// WS_true�֐��Ń��[���h���w�肷�鐔�l
	int stage_num;		// WS_true�֐��ŃX�e�[�W���w�肷�鐔�l
	bool loop;			// WS_true�֐��̍ۂɃ��[�v����t���O
};
