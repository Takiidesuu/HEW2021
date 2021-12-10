#pragma once
#include <Windows.h>
#include <Xinput.h>
#include <stdio.h>
#include <string>
#pragma comment (lib, "xinput.lib")

#define DEADZONE_LX 4
#define DEADZONE_LY 3
#define DEADZONE_RX 3.75f
#define DEADZONE_RY 2.75f

//------------------------------------------------------------
// Input.h�ȊO�Ŏg�p����ۂ̒�`
//------------------------------------------------------------
#define GP_UP		XINPUT_GAMEPAD_DPAD_UP			// �\���L�[		��
#define GP_DOWN		XINPUT_GAMEPAD_DPAD_DOWN		// �\���L�[		��
#define GP_LEFT		XINPUT_GAMEPAD_DPAD_LEFT		// �\���L�[		��
#define GP_RIGHT	XINPUT_GAMEPAD_DPAD_RIGHT		// �\���L�[		�E
#define GP_START	XINPUT_GAMEPAD_START			// �X�^�[�g		�{�^��
#define GP_BACK		XINPUT_GAMEPAD_BACK				// �o�b�N		�{�^��
#define	GP_LS		XINPUT_GAMEPAD_LEFT_SHOULDER	// ��			�{�^��
#define	GP_RS		XINPUT_GAMEPAD_RIGHT_SHOULDER	// �E			�{�^��
#define GP_A		XINPUT_GAMEPAD_A				// �`			�{�^��
#define GP_B		XINPUT_GAMEPAD_B				// �a			�{�^��
#define GP_X		XINPUT_GAMEPAD_X				// �b			�{�^��
#define GP_Y		XINPUT_GAMEPAD_Y				// �c			�{�^��

//------------------------------------------------------------
// �X�e�B�b�N���g�p����ۂ̕����w��
//------------------------------------------------------------
enum DIR
{
	UP,		// ��
	DOWN,	// ��
	LEFT,	// ��
	RIGHT,	// �E

	UPPER_LEFT,		// ����
	UPPER_RIGHT,	// �E��
	LOWER_LEFT,		// ����
	LOWER_RIGHT,	// �E��
};

enum ACTION
{
	SHOWCIRCLESMALL,		//�������͈͕\��
	SHOWCIRCLEBIG,			//�傫���͈͕\��
	OK,						//�I�ԃA�N�V�����iENTER�L�[�AA�{�^���j
	BACK,					//�߂�A�N�V�����iESC�L�[�AB�L�[�j
	RESTART,				//���X�^�[�g�i�f�o�b�O�p�j
};



//------------------------------------------------------------
// �֐��ꗗ�i���g�� Input.cpp �ɏ����Ă���j
//------------------------------------------------------------

class Input
{
public:
	// 1P�R���g���[���[
	bool LongPushButton_1P(int PushButton);
	bool ShortPushButton_1P(int PushButton);
	bool LeftTrigger_1P(int PushLevel);
	bool RightTrigger_1P(int PushLevel);
	bool LeftStick8_1P(int PushDirection);
	bool RightStick8_1P(int PushDirection);
	bool LeftVibrationStart_1P(int VibrationLevel);
	bool RightVibrationStart_1P(int VibrationLevel);
	bool LeftVibrationStop_1P();
	bool RightVibrationStop_1P();

	// 2P�R���g���[���[
	bool LongPushButton_2P(int PushButton);
	bool ShortPushButton_2P(int PushButton);
	bool LeftTrigger_2P(int PushLevel);
	bool RightTrigger_2P(int PushLevel);
	bool LeftStick8_2P(int PushDirection);
	bool RightStick8_2P(int PushDirection);
	bool LeftVibrationStart_2P(int VibrationLevel);
	bool RightVibrationStart_2P(int VibrationLevel);
	bool LeftVibrationStop_2P();
	bool RightVibrationStop_2P();

	// 3P�R���g���[���[
	bool LongPushButton_3P(int PushButton);
	bool ShortPushButton_3P(int PushButton);
	bool LeftTrigger_3P(int PushLevel);
	bool RightTrigger_3P(int PushLevel);
	bool LeftStick8_3P(int PushDirection);
	bool RightStick8_3P(int PushDirection);
	bool LeftVibrationStart_3P(int VibrationLevel);
	bool RightVibrationStart_3P(int VibrationLevel);
	bool LeftVibrationStop_3P();
	bool RightVibrationStop_3P();

	// 4P�R���g���[���[
	bool LongPushButton_4P(int PushButton);
	bool ShortPushButton_4P(int PushButton);
	bool LeftTrigger_4P(int PushLevel);
	bool RightTrigger_4P(int PushLevel);
	bool LeftStick8_4P(int PushDirection);
	bool RightStick8_4P(int PushDirection);
	bool LeftVibrationStart_4P(int VibrationLevel);
	bool RightVibrationStart_4P(int VibrationLevel);
	bool LeftVibrationStop_4P();
	bool RightVibrationStop_4P();

	//�L�[�{�[�h����
	void Input_Update();
	bool Input_GetKeyPress(int vkey);
	bool Input_GetKeyTrigger(int vkey);

	bool GetAxis(DIR direction);				//�����C���v�b�g�i�������j
	bool GetAxisShort(DIR direction);			//�����C���v�b�g�i���j
	bool isInput();								//�C���v�b�g�����邩�ǂ���
	bool GetButtonPress(ACTION action);			//�A�N�V�����̃C���v�b�g
};