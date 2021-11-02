#include "Input.h"

#define MAX_KEYS 256

static short gOldKeys[MAX_KEYS];
static short gKeys[MAX_KEYS];

// �Q�[���p�b�h�̏�Ԃ��擾
XINPUT_STATE state_1P;		// 1P
XINPUT_STATE state_2P;		// 2P
XINPUT_STATE state_3P;		// 3P
XINPUT_STATE state_4P;		// 4P

// �Q�[���p�b�h�̐U��
XINPUT_VIBRATION vibration_1P;	// 1P
XINPUT_VIBRATION vibration_2P;	// 2P
XINPUT_VIBRATION vibration_3P;	// 3P
XINPUT_VIBRATION vibration_4P;	// 4P



//------------------------------------------------------------
// �{�^���𒷉����Ŏg�p����ۂ̊֐�
//
// int PushButton �� GP_A ������� A�{�^�� ���g�p�ł���
//------------------------------------------------------------
// 1P�R���g���[���[
bool Input::LongPushButton_1P(int PushButton)
{

	// ���͂̎擾
	XInputGetState(0, &state_1P);

	// �{�^�� �y���菈���z
	if (state_1P.Gamepad.wButtons & PushButton)
	{
		return true;
	}

	// ���薳��
	else
	{
		return false;
	}
}

// 2P�R���g���[���[
bool Input::LongPushButton_2P(int PushButton)
{

	// ���͂̎擾
	XInputGetState(1, &state_2P);

	// �{�^�� �y���菈���z
	if (state_2P.Gamepad.wButtons & PushButton)
	{
		return true;
	}

	// ���薳��
	else
	{
		return false;
	}
}

// 3P�R���g���[���[
bool Input::LongPushButton_3P(int PushButton)
{

	// ���͂̎擾
	XInputGetState(2, &state_3P);

	// �{�^�� �y���菈���z
	if (state_3P.Gamepad.wButtons & PushButton)
	{
		return true;
	}

	// ���薳��
	else
	{
		return false;
	}
}

// 4P�R���g���[���[
bool Input::LongPushButton_4P(int PushButton)
{

	// ���͂̎擾
	XInputGetState(3, &state_4P);

	// �{�^�� �y���菈���z
	if (state_4P.Gamepad.wButtons & PushButton)
	{
		return true;
	}

	// ���薳��
	else
	{
		return false;
	}
}



//------------------------------------------------------------
// �{�^����Z�����Ŏg�p����ۂ̊֐�
//
// int PushButton �� GP_A ������� A�{�^�� ���g�p�ł���
//------------------------------------------------------------
// 1P�R���g���[���[
bool Input::ShortPushButton_1P(int PushButton)
{

	// ���͂̎擾
	XInputGetState(0, &state_1P);

	// �{�^�� �y���菈���z
	if (state_1P.Gamepad.wButtons & PushButton)
	{
		while (state_1P.Gamepad.wButtons & PushButton)
		{
			// ���͂̎擾
			XInputGetState(0, &state_1P);

			if (!(state_1P.Gamepad.wButtons & PushButton))
			{
				return true;
			}
		}
	}

	// ���薳��
	else
	{
		return false;
	}
}

// 2P�R���g���[���[
bool Input::ShortPushButton_2P(int PushButton)
{

	// ���͂̎擾
	XInputGetState(1, &state_2P);

	// �{�^�� �y���菈���z
	if (state_2P.Gamepad.wButtons & PushButton)
	{
		while (state_2P.Gamepad.wButtons & PushButton)
		{
			// ���͂̎擾
			XInputGetState(1, &state_2P);

			if (!(state_2P.Gamepad.wButtons & PushButton))
			{
				return true;
			}
		}
	}

	// ���薳��
	else
	{
		return false;
	}
}

// 3P�R���g���[���[
bool Input::ShortPushButton_3P(int PushButton)
{

	// ���͂̎擾
	XInputGetState(2, &state_3P);

	// �{�^�� �y���菈���z
	if (state_3P.Gamepad.wButtons & PushButton)
	{
		while (state_3P.Gamepad.wButtons & PushButton)
		{
			// ���͂̎擾
			XInputGetState(2, &state_3P);

			if (!(state_3P.Gamepad.wButtons & PushButton))
			{
				return true;
			}
		}
	}

	// ���薳��
	else
	{
		return false;
	}
}

// 4P�R���g���[���[
bool Input::ShortPushButton_4P(int PushButton)
{

	// ���͂̎擾
	XInputGetState(3, &state_4P);

	// �{�^�� �y���菈���z
	if (state_4P.Gamepad.wButtons & PushButton)
	{
		while (state_4P.Gamepad.wButtons & PushButton)
		{
			// ���͂̎擾
			XInputGetState(3, &state_4P);

			if (!(state_4P.Gamepad.wButtons & PushButton))
			{
				return true;
			}
		}
	}

	// ���薳��
	else
	{
		return false;
	}
}



//------------------------------------------------------------
// ���g���K�[���g�p����ۂ̊֐�
//
// int PushLevel �� ���l ������� ���s� �������ł���
//------------------------------------------------------------
// 1P�R���g���[���[
bool Input::LeftTrigger_1P(int PushLevel)
{

	// ���͂̎擾
	XInputGetState(0, &state_1P);

	// �E�g���K�[ �y���菈���z
	if (state_1P.Gamepad.bLeftTrigger >= XINPUT_GAMEPAD_TRIGGER_THRESHOLD * PushLevel)
	{
		return true;
	}

	// ���薳��
	else
	{
		return false;
	}
}

// 2P�R���g���[���[
bool Input::LeftTrigger_2P(int PushLevel)
{

	// ���͂̎擾
	XInputGetState(1, &state_2P);

	// �E�g���K�[ �y���菈���z
	if (state_2P.Gamepad.bLeftTrigger >= XINPUT_GAMEPAD_TRIGGER_THRESHOLD * PushLevel)
	{
		return true;
	}

	// ���薳��
	else
	{
		return false;
	}
}

// 3P�R���g���[���[
bool Input::LeftTrigger_3P(int PushLevel)
{

	// ���͂̎擾
	XInputGetState(2, &state_3P);

	// �E�g���K�[ �y���菈���z
	if (state_3P.Gamepad.bLeftTrigger >= XINPUT_GAMEPAD_TRIGGER_THRESHOLD * PushLevel)
	{
		return true;
	}

	// ���薳��
	else
	{
		return false;
	}
}

// 4P�R���g���[���[
bool Input::LeftTrigger_4P(int PushLevel)
{

	// ���͂̎擾
	XInputGetState(3, &state_4P);

	// �E�g���K�[ �y���菈���z
	if (state_4P.Gamepad.bLeftTrigger >= XINPUT_GAMEPAD_TRIGGER_THRESHOLD * PushLevel)
	{
		return true;
	}

	// ���薳��
	else
	{
		return false;
	}
}



//------------------------------------------------------------
// �E�g���K�[���g�p����ۂ̊֐�
//
// int PushLevel �� ���l ������� ���s� �������ł���
//------------------------------------------------------------
// 1P�R���g���[���[
bool Input::RightTrigger_1P(int PushLevel)
{

	// ���͂̎擾
	XInputGetState(0, &state_1P);

	// ���g���K�[ �y���菈���z
	if (state_1P.Gamepad.bRightTrigger >= XINPUT_GAMEPAD_TRIGGER_THRESHOLD * PushLevel)
	{
		return true;
	}

	// ���薳��
	else
	{
		return false;
	}
}

// 2P�R���g���[���[
bool Input::RightTrigger_2P(int PushLevel)
{

	// ���͂̎擾
	XInputGetState(1, &state_2P);

	// ���g���K�[ �y���菈���z
	if (state_2P.Gamepad.bRightTrigger >= XINPUT_GAMEPAD_TRIGGER_THRESHOLD * PushLevel)
	{
		return true;
	}

	// ���薳��
	else
	{
		return false;
	}
}

// 3P�R���g���[���[
bool Input::RightTrigger_3P(int PushLevel)
{

	// ���͂̎擾
	XInputGetState(2, &state_3P);

	// ���g���K�[ �y���菈���z
	if (state_3P.Gamepad.bRightTrigger >= XINPUT_GAMEPAD_TRIGGER_THRESHOLD * PushLevel)
	{
		return true;
	}

	// ���薳��
	else
	{
		return false;
	}
}

// 4P�R���g���[���[
bool Input::RightTrigger_4P(int PushLevel)
{

	// ���͂̎擾
	XInputGetState(3, &state_4P);

	// ���g���K�[ �y���菈���z
	if (state_4P.Gamepad.bRightTrigger >= XINPUT_GAMEPAD_TRIGGER_THRESHOLD * PushLevel)
	{
		return true;
	}

	// ���薳��
	else
	{
		return false;
	}
}



//------------------------------------------------------------
// ���X�e�B�b�N���g�p����ۂ̊֐�
//
// int PushDirection �� DIR::�Z�Z ������� �����w�� ���ݒ�ł���
//------------------------------------------------------------
// 1P�R���g���[���[
bool Input::LeftStick8_1P(int PushDirection)
{

	// ���͂̎擾
	XInputGetState(0, &state_1P);

	//------------------------------------------------------------
	// ���X�e�B�b�N�̃f�b�h�]�[������
	//------------------------------------------------------------
	if ((state_1P.Gamepad.sThumbLX < XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE && state_1P.Gamepad.sThumbLX > -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE) &&
		(state_1P.Gamepad.sThumbLY < XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE && state_1P.Gamepad.sThumbLY > -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE))
	{
		state_1P.Gamepad.sThumbLX = 0;
		state_1P.Gamepad.sThumbLY = 0;
	}

	// ������ �y���菈���z
	if ((PushDirection == DIR::LEFT) && (state_1P.Gamepad.sThumbLX <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE * DEADZONE_LX))
	{
		return true;
	}

	// �E���� �y���菈���z
	if ((PushDirection == DIR::RIGHT) && (state_1P.Gamepad.sThumbLX >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE * DEADZONE_LX))
	{
		return true;
	}

	// ����� �y���菈���z
	if ((PushDirection == DIR::UP) && (state_1P.Gamepad.sThumbLY >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE * DEADZONE_LY))
	{
		return true;
	}

	// ������ �y���菈���z
	if ((PushDirection == DIR::DOWN) && (state_1P.Gamepad.sThumbLY <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE * DEADZONE_LY))
	{
		return true;
	}

	// ������� �y���菈���z
	if ((PushDirection == DIR::UPPER_LEFT) && (state_1P.Gamepad.sThumbLX <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
		&& (state_1P.Gamepad.sThumbLY >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE))
	{
		return true;
	}

	// �E����� �y���菈���z
	if ((PushDirection == DIR::UPPER_RIGHT) && (state_1P.Gamepad.sThumbLX >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
		&& (state_1P.Gamepad.sThumbLY >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE))
	{
		return true;
	}

	// �������� �y���菈���z
	if ((PushDirection == DIR::LOWER_LEFT) && (state_1P.Gamepad.sThumbLX <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
		&& (state_1P.Gamepad.sThumbLY <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE))
	{
		return true;
	}

	// �E������ �y���菈���z
	if ((PushDirection == DIR::LOWER_RIGHT) && (state_1P.Gamepad.sThumbLX >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
		&& (state_1P.Gamepad.sThumbLY <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE))
	{
		return true;
	}

	// ���薳��
	else
	{
		return false;
	}
}

// 2P�R���g���[���[
bool Input::LeftStick8_2P(int PushDirection)
{

	// ���͂̎擾
	XInputGetState(1, &state_2P);

	//------------------------------------------------------------
	// ���X�e�B�b�N�̃f�b�h�]�[������
	//------------------------------------------------------------
	if ((state_2P.Gamepad.sThumbLX < XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE && state_2P.Gamepad.sThumbLX > -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE) &&
		(state_2P.Gamepad.sThumbLY < XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE && state_2P.Gamepad.sThumbLY > -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE))
	{
		state_2P.Gamepad.sThumbLX = 0;
		state_2P.Gamepad.sThumbLY = 0;
	}

	// ������ �y���菈���z
	if ((PushDirection == DIR::LEFT) && (state_2P.Gamepad.sThumbLX <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE * DEADZONE_LX))
	{
		return true;
	}

	// �E���� �y���菈���z
	if ((PushDirection == DIR::RIGHT) && (state_2P.Gamepad.sThumbLX >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE * DEADZONE_LX))
	{
		return true;
	}

	// ����� �y���菈���z
	if ((PushDirection == DIR::UP) && (state_2P.Gamepad.sThumbLY >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE * DEADZONE_LY))
	{
		return true;
	}

	// ������ �y���菈���z
	if ((PushDirection == DIR::DOWN) && (state_2P.Gamepad.sThumbLY <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE * DEADZONE_LY))
	{
		return true;
	}

	// ������� �y���菈���z
	if ((PushDirection == DIR::UPPER_LEFT) && (state_2P.Gamepad.sThumbLX <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
		&& (state_2P.Gamepad.sThumbLY >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE))
	{
		return true;
	}

	// �E����� �y���菈���z
	if ((PushDirection == DIR::UPPER_RIGHT) && (state_2P.Gamepad.sThumbLX >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
		&& (state_2P.Gamepad.sThumbLY >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE))
	{
		return true;
	}

	// �������� �y���菈���z
	if ((PushDirection == DIR::LOWER_LEFT) && (state_2P.Gamepad.sThumbLX <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
		&& (state_2P.Gamepad.sThumbLY <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE))
	{
		return true;
	}

	// �E������ �y���菈���z
	if ((PushDirection == DIR::LOWER_RIGHT) && (state_2P.Gamepad.sThumbLX >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
		&& (state_2P.Gamepad.sThumbLY <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE))
	{
		return true;
	}

	// ���薳��
	else
	{
		return false;
	}
}

// 3P�R���g���[���[
bool Input::LeftStick8_3P(int PushDirection)
{

	// ���͂̎擾
	XInputGetState(2, &state_3P);

	//------------------------------------------------------------
	// ���X�e�B�b�N�̃f�b�h�]�[������
	//------------------------------------------------------------
	if ((state_3P.Gamepad.sThumbLX < XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE && state_3P.Gamepad.sThumbLX > -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE) &&
		(state_3P.Gamepad.sThumbLY < XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE && state_3P.Gamepad.sThumbLY > -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE))
	{
		state_3P.Gamepad.sThumbLX = 0;
		state_3P.Gamepad.sThumbLY = 0;
	}

	// ������ �y���菈���z
	if ((PushDirection == DIR::LEFT) && (state_3P.Gamepad.sThumbLX <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE * DEADZONE_LX))
	{
		return true;
	}

	// �E���� �y���菈���z
	if ((PushDirection == DIR::RIGHT) && (state_3P.Gamepad.sThumbLX >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE * DEADZONE_LX))
	{
		return true;
	}

	// ����� �y���菈���z
	if ((PushDirection == DIR::UP) && (state_3P.Gamepad.sThumbLY >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE * DEADZONE_LY))
	{
		return true;
	}

	// ������ �y���菈���z
	if ((PushDirection == DIR::DOWN) && (state_3P.Gamepad.sThumbLY <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE * DEADZONE_LY))
	{
		return true;
	}

	// ������� �y���菈���z
	if ((PushDirection == DIR::UPPER_LEFT) && (state_3P.Gamepad.sThumbLX <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
		&& (state_3P.Gamepad.sThumbLY >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE))
	{
		return true;
	}

	// �E����� �y���菈���z
	if ((PushDirection == DIR::UPPER_RIGHT) && (state_3P.Gamepad.sThumbLX >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
		&& (state_3P.Gamepad.sThumbLY >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE))
	{
		return true;
	}

	// �������� �y���菈���z
	if ((PushDirection == DIR::LOWER_LEFT) && (state_3P.Gamepad.sThumbLX <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
		&& (state_3P.Gamepad.sThumbLY <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE))
	{
		return true;
	}

	// �E������ �y���菈���z
	if ((PushDirection == DIR::LOWER_RIGHT) && (state_3P.Gamepad.sThumbLX >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
		&& (state_3P.Gamepad.sThumbLY <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE))
	{
		return true;
	}

	// ���薳��
	else
	{
		return false;
	}
}

// 4P�R���g���[���[
bool Input::LeftStick8_4P(int PushDirection)
{

	// ���͂̎擾
	XInputGetState(3, &state_4P);

	//------------------------------------------------------------
	// ���X�e�B�b�N�̃f�b�h�]�[������
	//------------------------------------------------------------
	if ((state_4P.Gamepad.sThumbLX < XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE && state_4P.Gamepad.sThumbLX > -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE) &&
		(state_4P.Gamepad.sThumbLY < XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE && state_4P.Gamepad.sThumbLY > -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE))
	{
		state_4P.Gamepad.sThumbLX = 0;
		state_4P.Gamepad.sThumbLY = 0;
	}

	// ������ �y���菈���z
	if ((PushDirection == DIR::LEFT) && (state_4P.Gamepad.sThumbLX <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE * DEADZONE_LX))
	{
		return true;
	}

	// �E���� �y���菈���z
	if ((PushDirection == DIR::RIGHT) && (state_4P.Gamepad.sThumbLX >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE * DEADZONE_LX))
	{
		return true;
	}

	// ����� �y���菈���z
	if ((PushDirection == DIR::UP) && (state_4P.Gamepad.sThumbLY >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE * DEADZONE_LY))
	{
		return true;
	}

	// ������ �y���菈���z
	if ((PushDirection == DIR::DOWN) && (state_4P.Gamepad.sThumbLY <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE * DEADZONE_LY))
	{
		return true;
	}

	// ������� �y���菈���z
	if ((PushDirection == DIR::UPPER_LEFT) && (state_4P.Gamepad.sThumbLX <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE * DEADZONE_LX)
		&& (state_4P.Gamepad.sThumbLY >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE * DEADZONE_LY))
	{
		return true;
	}

	// �E����� �y���菈���z
	if ((PushDirection == DIR::UPPER_RIGHT) && (state_4P.Gamepad.sThumbLX >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE * DEADZONE_LX)
		&& (state_4P.Gamepad.sThumbLY >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE * DEADZONE_LY))
	{
		return true;
	}

	// �������� �y���菈���z
	if ((PushDirection == DIR::LOWER_LEFT) && (state_4P.Gamepad.sThumbLX <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE * DEADZONE_LX)
		&& (state_4P.Gamepad.sThumbLY <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE * DEADZONE_LY))
	{
		return true;
	}

	// �E������ �y���菈���z
	if ((PushDirection == DIR::LOWER_RIGHT) && (state_4P.Gamepad.sThumbLX >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE * DEADZONE_LX)
		&& (state_4P.Gamepad.sThumbLY <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE * DEADZONE_LY))
	{
		return true;
	}

	// ���薳��
	else
	{
		return false;
	}
}



//------------------------------------------------------------
// �E�X�e�B�b�N���g�p����ۂ̊֐�
//
// int PushDirection �� DIR::�Z�Z ������� �����w�� ���ݒ�ł���
//------------------------------------------------------------
// 1P�R���g���[���[
bool Input::RightStick8_1P(int PushDirection)
{

	// ���͂̎擾
	XInputGetState(0, &state_1P);

	//------------------------------------------------------------
	// �E�X�e�B�b�N�̃f�b�h�]�[������
	//------------------------------------------------------------
	if ((state_1P.Gamepad.sThumbRX < XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE && state_1P.Gamepad.sThumbRX > -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE) &&
		(state_1P.Gamepad.sThumbRY < XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE && state_1P.Gamepad.sThumbRY > -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE))
	{
		state_1P.Gamepad.sThumbRX = 0;
		state_1P.Gamepad.sThumbRY = 0;
	}

	// ������ �y���菈���z
	if ((PushDirection == DIR::LEFT) && (state_1P.Gamepad.sThumbRX <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE * DEADZONE_RX))
	{
		return true;
	}

	// �E���� �y���菈���z
	if ((PushDirection == DIR::RIGHT) && (state_1P.Gamepad.sThumbRX >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE * DEADZONE_RX))
	{
		return true;
	}

	// ����� �y���菈���z
	if ((PushDirection == DIR::UP) && (state_1P.Gamepad.sThumbRY >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE * DEADZONE_RY))
	{
		return true;
	}

	// ������ �y���菈���z
	if ((PushDirection == DIR::DOWN) && (state_1P.Gamepad.sThumbRY <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE * DEADZONE_RY))
	{
		return true;
	}

	// ������� �y���菈���z
	if ((PushDirection == DIR::UPPER_LEFT) && (state_1P.Gamepad.sThumbRX <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE)
		&& (state_1P.Gamepad.sThumbRY >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE))
	{
		return true;
	}

	// �E����� �y���菈���z
	if ((PushDirection == DIR::UPPER_RIGHT) && (state_1P.Gamepad.sThumbRX >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE)
		&& (state_1P.Gamepad.sThumbRY >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE))
	{
		return true;
	}

	// �������� �y���菈���z
	if ((PushDirection == DIR::LOWER_LEFT) && (state_1P.Gamepad.sThumbRX <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE)
		&& (state_1P.Gamepad.sThumbRY <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE))
	{
		return true;
	}

	// �E������ �y���菈���z
	if ((PushDirection == DIR::LOWER_RIGHT) && (state_1P.Gamepad.sThumbRX >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE)
		&& (state_1P.Gamepad.sThumbRY <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE))
	{
		return true;
	}

	// ���薳��
	else
	{
		return false;
	}
}

// 2P�R���g���[���[
bool Input::RightStick8_2P(int PushDirection)
{

	// ���͂̎擾
	XInputGetState(1, &state_2P);

	//------------------------------------------------------------
	// �E�X�e�B�b�N�̃f�b�h�]�[������
	//------------------------------------------------------------
	if ((state_2P.Gamepad.sThumbRX < XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE && state_2P.Gamepad.sThumbRX > -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE) &&
		(state_2P.Gamepad.sThumbRY < XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE && state_2P.Gamepad.sThumbRY > -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE))
	{
		state_2P.Gamepad.sThumbRX = 0;
		state_2P.Gamepad.sThumbRY = 0;
	}

	// ������ �y���菈���z
	if ((PushDirection == DIR::LEFT) && (state_2P.Gamepad.sThumbRX <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE * DEADZONE_RX))
	{
		return true;
	}

	// �E���� �y���菈���z
	if ((PushDirection == DIR::RIGHT) && (state_2P.Gamepad.sThumbRX >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE * DEADZONE_RX))
	{
		return true;
	}

	// ����� �y���菈���z
	if ((PushDirection == DIR::UP) && (state_2P.Gamepad.sThumbRY >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE * DEADZONE_RY))
	{
		return true;
	}

	// ������ �y���菈���z
	if ((PushDirection == DIR::DOWN) && (state_2P.Gamepad.sThumbRY <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE * DEADZONE_RY))
	{
		return true;
	}

	// ������� �y���菈���z
	if ((PushDirection == DIR::UPPER_LEFT) && (state_2P.Gamepad.sThumbRX <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE)
		&& (state_2P.Gamepad.sThumbRY >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE))
	{
		return true;
	}

	// �E����� �y���菈���z
	if ((PushDirection == DIR::UPPER_RIGHT) && (state_2P.Gamepad.sThumbRX >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE)
		&& (state_2P.Gamepad.sThumbRY >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE))
	{
		return true;
	}

	// �������� �y���菈���z
	if ((PushDirection == DIR::LOWER_LEFT) && (state_2P.Gamepad.sThumbRX <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE)
		&& (state_2P.Gamepad.sThumbRY <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE))
	{
		return true;
	}

	// �E������ �y���菈���z
	if ((PushDirection == DIR::LOWER_RIGHT) && (state_2P.Gamepad.sThumbRX >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE)
		&& (state_2P.Gamepad.sThumbRY <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE))
	{
		return true;
	}

	// ���薳��
	else
	{
		return false;
	}
}

// 3P�R���g���[���[
bool Input::RightStick8_3P(int PushDirection)
{

	// ���͂̎擾
	XInputGetState(2, &state_3P);

	//------------------------------------------------------------
	// �E�X�e�B�b�N�̃f�b�h�]�[������
	//------------------------------------------------------------
	if ((state_3P.Gamepad.sThumbRX < XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE && state_3P.Gamepad.sThumbRX > -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE) &&
		(state_3P.Gamepad.sThumbRY < XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE && state_3P.Gamepad.sThumbRY > -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE))
	{
		state_3P.Gamepad.sThumbRX = 0;
		state_3P.Gamepad.sThumbRY = 0;
	}

	// ������ �y���菈���z
	if ((PushDirection == DIR::LEFT) && (state_3P.Gamepad.sThumbRX <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE * DEADZONE_RX))
	{
		return true;
	}

	// �E���� �y���菈���z
	if ((PushDirection == DIR::RIGHT) && (state_3P.Gamepad.sThumbRX >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE * DEADZONE_RX))
	{
		return true;
	}

	// ����� �y���菈���z
	if ((PushDirection == DIR::UP) && (state_3P.Gamepad.sThumbRY >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE * DEADZONE_RY))
	{
		return true;
	}

	// ������ �y���菈���z
	if ((PushDirection == DIR::DOWN) && (state_3P.Gamepad.sThumbRY <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE * DEADZONE_RY))
	{
		return true;
	}

	// ������� �y���菈���z
	if ((PushDirection == DIR::UPPER_LEFT) && (state_3P.Gamepad.sThumbRX <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE)
		&& (state_3P.Gamepad.sThumbRY >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE))
	{
		return true;
	}

	// �E����� �y���菈���z
	if ((PushDirection == DIR::UPPER_RIGHT) && (state_3P.Gamepad.sThumbRX >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE)
		&& (state_3P.Gamepad.sThumbRY >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE))
	{
		return true;
	}

	// �������� �y���菈���z
	if ((PushDirection == DIR::LOWER_LEFT) && (state_3P.Gamepad.sThumbRX <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE)
		&& (state_3P.Gamepad.sThumbRY <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE))
	{
		return true;
	}

	// �E������ �y���菈���z
	if ((PushDirection == DIR::LOWER_RIGHT) && (state_3P.Gamepad.sThumbRX >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE)
		&& (state_3P.Gamepad.sThumbRY <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE))
	{
		return true;
	}

	// ���薳��
	else
	{
		return false;
	}
}

// 4P�R���g���[���[
bool Input::RightStick8_4P(int PushDirection)
{

	// ���͂̎擾
	XInputGetState(3, &state_4P);

	//------------------------------------------------------------
	// �E�X�e�B�b�N�̃f�b�h�]�[������
	//------------------------------------------------------------
	if ((state_4P.Gamepad.sThumbRX < XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE && state_4P.Gamepad.sThumbRX > -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE) &&
		(state_4P.Gamepad.sThumbRY < XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE && state_4P.Gamepad.sThumbRY > -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE))
	{
		state_4P.Gamepad.sThumbRX = 0;
		state_4P.Gamepad.sThumbRY = 0;
	}

	// ������ �y���菈���z
	if ((PushDirection == DIR::LEFT) && (state_4P.Gamepad.sThumbRX <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE * DEADZONE_RX))
	{
		return true;
	}

	// �E���� �y���菈���z
	if ((PushDirection == DIR::RIGHT) && (state_4P.Gamepad.sThumbRX >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE * DEADZONE_RX))
	{
		return true;
	}

	// ����� �y���菈���z
	if ((PushDirection == DIR::UP) && (state_4P.Gamepad.sThumbRY >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE * DEADZONE_RY))
	{
		return true;
	}

	// ������ �y���菈���z
	if ((PushDirection == DIR::DOWN) && (state_4P.Gamepad.sThumbRY <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE * DEADZONE_RY))
	{
		return true;
	}

	// ������� �y���菈���z
	if ((PushDirection == DIR::UPPER_LEFT) && (state_4P.Gamepad.sThumbRX <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE)
		&& (state_4P.Gamepad.sThumbRY >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE))
	{
		return true;
	}

	// �E����� �y���菈���z
	if ((PushDirection == DIR::UPPER_RIGHT) && (state_4P.Gamepad.sThumbRX >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE)
		&& (state_4P.Gamepad.sThumbRY >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE))
	{
		return true;
	}

	// �������� �y���菈���z
	if ((PushDirection == DIR::LOWER_LEFT) && (state_4P.Gamepad.sThumbRX <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE)
		&& (state_4P.Gamepad.sThumbRY <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE))
	{
		return true;
	}

	// �E������ �y���菈���z
	if ((PushDirection == DIR::LOWER_RIGHT) && (state_4P.Gamepad.sThumbRX >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE)
		&& (state_4P.Gamepad.sThumbRY <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE))
	{
		return true;
	}

	// ���薳��
	else
	{
		return false;
	}
}



//------------------------------------------------------------
// ���o�C�u���[�V�������g�p����ۂ̊֐�
//
// int VibrationLevel �� ���l ������� �U���̋��� �������ł���
//------------------------------------------------------------
// 1P�R���g���[���[
bool Input::LeftVibrationStart_1P(int VibrationLevel)
{
	// ���o�C�u���[�V���� �y�쓮�����z
	vibration_1P.wLeftMotorSpeed = VibrationLevel;
	XInputSetState(0, &vibration_1P);
	return true;
}

// 2P�R���g���[���[
bool Input::LeftVibrationStart_2P(int VibrationLevel)
{
	// ���o�C�u���[�V���� �y�쓮�����z
	vibration_2P.wLeftMotorSpeed = VibrationLevel;
	XInputSetState(1, &vibration_2P);
	return true;
}

// 3P�R���g���[���[
bool Input::LeftVibrationStart_3P(int VibrationLevel)
{
	// ���o�C�u���[�V���� �y�쓮�����z
	vibration_3P.wLeftMotorSpeed = VibrationLevel;
	XInputSetState(2, &vibration_3P);
	return true;
}

// 4P�R���g���[���[
bool Input::LeftVibrationStart_4P(int VibrationLevel)
{
	// ���o�C�u���[�V���� �y�쓮�����z
	vibration_4P.wLeftMotorSpeed = VibrationLevel;
	XInputSetState(3, &vibration_4P);
	return true;
}



//------------------------------------------------------------
// �E�o�C�u���[�V�������g�p����ۂ̊֐�
//
// int VibrationLevel �� ���l ������� �U���̋��� �������ł���
//------------------------------------------------------------
// 1P�R���g���[���[
bool Input::RightVibrationStart_1P(int VibrationLevel)
{
	// �E�o�C�u���[�V���� �y�쓮�����z
	vibration_1P.wRightMotorSpeed = VibrationLevel;
	XInputSetState(0, &vibration_1P);
	return true;
}

// 2P�R���g���[���[
bool Input::RightVibrationStart_2P(int VibrationLevel)
{
	// �E�o�C�u���[�V���� �y�쓮�����z
	vibration_2P.wRightMotorSpeed = VibrationLevel;
	XInputSetState(1, &vibration_2P);
	return true;
}

// 3P�R���g���[���[
bool Input::RightVibrationStart_3P(int VibrationLevel)
{
	// �E�o�C�u���[�V���� �y�쓮�����z
	vibration_3P.wRightMotorSpeed = VibrationLevel;
	XInputSetState(2, &vibration_3P);
	return true;
}

// 4P�R���g���[���[
bool Input::RightVibrationStart_4P(int VibrationLevel)
{
	// �E�o�C�u���[�V���� �y�쓮�����z
	vibration_4P.wRightMotorSpeed = VibrationLevel;
	XInputSetState(3, &vibration_4P);
	return true;
}



//------------------------------------------------------------
// ���o�C�u���[�V�������~����ۂ̊֐�
//------------------------------------------------------------
// 1P�R���g���[���[
bool Input::LeftVibrationStop_1P()
{
	// ���o�C�u���[�V���� �y��~�����z
	vibration_1P.wLeftMotorSpeed = false;
	XInputSetState(0, &vibration_1P);
	return true;
}

// 2P�R���g���[���[
bool Input::LeftVibrationStop_2P()
{
	// ���o�C�u���[�V���� �y��~�����z
	vibration_2P.wLeftMotorSpeed = false;
	XInputSetState(1, &vibration_2P);
	return true;
}

// 3P�R���g���[���[
bool Input::LeftVibrationStop_3P()
{
	// ���o�C�u���[�V���� �y��~�����z
	vibration_3P.wLeftMotorSpeed = false;
	XInputSetState(2, &vibration_3P);
	return true;
}

// 4P�R���g���[���[
bool Input::LeftVibrationStop_4P()
{
	// ���o�C�u���[�V���� �y��~�����z
	vibration_4P.wLeftMotorSpeed = false;
	XInputSetState(3, &vibration_4P);
	return true;
}



//------------------------------------------------------------
// �E�o�C�u���[�V�������~����ۂ̊֐�
//------------------------------------------------------------
// 1P�R���g���[���[
bool Input::RightVibrationStop_1P()
{
	// �E�o�C�u���[�V���� �y��~�����z
	vibration_1P.wRightMotorSpeed = false;
	XInputSetState(0, &vibration_1P);
	return true;
}

// 2P�R���g���[���[
bool Input::RightVibrationStop_2P()
{
	// �E�o�C�u���[�V���� �y��~�����z
	vibration_2P.wRightMotorSpeed = false;
	XInputSetState(1, &vibration_2P);
	return true;
}

// 3P�R���g���[���[
bool Input::RightVibrationStop_3P()
{
	// �E�o�C�u���[�V���� �y��~�����z
	vibration_3P.wRightMotorSpeed = false;
	XInputSetState(2, &vibration_3P);
	return true;
}

// 4P�R���g���[���[
bool Input::RightVibrationStop_4P()
{
	// �E�o�C�u���[�V���� �y��~�����z
	vibration_4P.wRightMotorSpeed = false;
	XInputSetState(3, &vibration_4P);
	return true;
}

void Input::Input_Update()
{
	//���݂̃L�[�����Â��L�[�ϐ��ɃR�s�[����
	memcpy_s(gOldKeys, sizeof(gOldKeys), gKeys, sizeof(gKeys));

	//���݂̃L�[�����擾
	gKeys[VK_UP] = GetAsyncKeyState(VK_UP);				//��
	gKeys[VK_DOWN] = GetAsyncKeyState(VK_DOWN);			//��
	gKeys[VK_LEFT] = GetAsyncKeyState(VK_LEFT);			//��
	gKeys[VK_RIGHT] = GetAsyncKeyState(VK_RIGHT);		//�E
	gKeys[VK_LBUTTON] = GetAsyncKeyState(VK_LBUTTON);	//���N���b�N�i�}�E�X�j
	gKeys[VK_RBUTTON] = GetAsyncKeyState(VK_RBUTTON);	//�E�N���b�N�i�}�E�X�j
	gKeys[VK_RETURN] = GetAsyncKeyState(VK_RETURN);		//ENTER�L�[
	gKeys[VK_ESCAPE] = GetAsyncKeyState(VK_ESCAPE);		//ESC�L�[
	gKeys[VK_SPACE] = GetAsyncKeyState(VK_SPACE);		//�X�y�[�X�L�[
	gKeys['W'] = GetAsyncKeyState('W');					//W
	gKeys['A'] = GetAsyncKeyState('A');					//A
	gKeys['S'] = GetAsyncKeyState('S');					//S
	gKeys['D'] = GetAsyncKeyState('D');					//D
	gKeys['P'] = GetAsyncKeyState('P');					//P
}

//�������p�̊֐�
bool Input::Input_GetKeyPress(int vkey)
{
	return gKeys[vkey] & 0x8000;
}

//�P�������p�̊֐�
bool Input::Input_GetKeyTrigger(int vkey)
{
	return (gKeys[vkey] & 0x8000) != 0 && (gOldKeys[vkey] & 0x8000) == 0;
}

bool Input::GetAxis(DIR direction)
{
	bool result = false;

	switch (direction)
	{
	case RIGHT:
		if (Input_GetKeyPress('D') || LeftStick8_1P(RIGHT))
			result = true;
		break;
	case LEFT:
		if (Input_GetKeyPress('A') || LeftStick8_1P(LEFT))
			result = true;
		break;
	}

	return result;
}

bool Input::isInput()
{
	bool result = false;

	if (GetAxis(LEFT) || GetAxis(RIGHT))
		result = true;
	else
		result = false;

	return result;
}