////////////////////////////////////////////////
////	FILENAME: System.h
////////////////////////////////////////////////

#pragma once

///////////////////////////////
// �����̑O�̃f�B���N�e�B�u //
///////////////////////////////
#define WIN32_LEAN_AND_MEAN
#define no_init_all

////////////////////////////////////////////////
////	INCLUDE
////////////////////////////////////////////////

#include <Windows.h>
#include <tchar.h>

#include "Game.h"
#include "SaveLoad.h"
#include "Title.h"
#include "StageSelect.h"
#include "Scene.h"
#include "SelectClass.h"
#include "Loading.h"
#include "Result.h"
#include "LoadGame.h"

const bool FULL_SCREEN = false;	//�t���X�N���[��

class System
{
public:
	System();		//�R���X�g���N�^�[
	~System();		//�f�X�g���N�^�[

	bool Init();		//������
	void Update();		//�E�C���h�E�Y�̃��b�Z�[�W�Ǘ��֐�
	bool Processes();	//�Q�[�����[�v
	void Uninit();		//����֐�

	//���̊֐��Ŏ��s���̃A�v���Ɏw���𑗂�
	LRESULT CALLBACK MessageHandler(HWND, UINT, WPARAM, LPARAM);

private:
	LPCWSTR m_applicationName;			//�A�v����
	HINSTANCE m_hinstance;				//�C���X�^���X
	HWND m_hwnd;						//�E�C���h�E

	Title* titleObj = 0;				//�^�C�g���I�u�W�F�N�g
	LoadGame* loadGameObj = 0;			//�Z�[�u�t�@�C���\����ʃI�u�W�F�N�g
	SelectClass* stageObj = 0;			//�X�e�[�W�Z���N�g�I�u�W�F�N�g
	GameClass* gameObj = 0;				//�Q�[���I�u�W�F�N�g
	Save_Load* saveloadObj = 0;			//�Z�[�u���[�h�p�I�u�W�F�N�g
	Loading* loadingObj = 0;			//���[�f�B���O��ʃI�u�W�F�N�g
	CResult* resultObj = 0;				//���U���g��ʃI�u�W�F�N�g

	//�E�C���h�E�Y�̏�����
	void InitializeWindows(int& screenWidth, int& screenHeight);

	bool first = true;
	bool gameInit = false;
};

//���b�Z�[�W��Ǘp�֐�
static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//�O���[�o���I�u�W�F�N�g�֐�
static System* ApplicationHandle = 0;