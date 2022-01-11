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
// ��Βl��32768
//
//  �p�x	 ����		X�l		�@Y�l	|	X�l		|	Y�l
//   0.0	�k		�@  +128	+32767	|			|
//										|	DEADZONE_MIN
//  22.5	�k�k��	�@+18889	+28655	|		  128
//  45.0	�k��	�@+29426	+21459	|			|
//  67.5	���k��	�@+32767	 +7581	|DEADZONE1	|DEADZONE1
//										|  6040		|  3469
//  90.0	��		�@+32767	  +128	| 10922		|  7581
//										| 15292		|  9124
// 112.5	���쓌	�@+32767	-12465	| 18889		| 12465
// 135.0	�쓌	  +28141	-24287	|			|
// 157.5	��쓌	�@+10922	-32768	|DEADZONE2	|DEADZONE2
//										| 22745		| 17862
// 180.0	��		�@  +128	-32767	| 28141		| 21459
//										| 29170		| 24287
// 202.5	��쐼	�@-15292	-29684	| 29426		| 27113
// 225.0	�쐼	�@-29170	-17862	|			|
// 247.5	���쐼	�@-30198	 -9124	|DEADZONE3	|DEADZONE3
//										| 30198		| 28655
// 270.0	��		�@-32767	  +128	| 32767		| 29684
//										| 32768		| 32767
// 292,5	���k��	�@-32768	 +3469	|			| 32768
// 315.0	�k��	�@-22745	+27113	|	DEADZONE_MAX
// 337.5	�k�k��	�@ -6040	+32767	|		32768
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

	//   0.0 �k
	if ((PushDirection == DIR::UP) &&
		(-DEADZONE_MIN <= state_1P.Gamepad.sThumbLX) &&	// X��������
		(state_1P.Gamepad.sThumbLX <= DEADZONE_MIN) &&	// X�����܂�
		(DEADZONE2_Y <= state_1P.Gamepad.sThumbLY) &&	// Y��������
		(state_1P.Gamepad.sThumbLY <= DEADZONE_MAX))	// Y�����܂�
	{
		return true;
	}

	//  22.5 �k�k��
	if ((PushDirection == DIR::R22d5) &&
		(DEADZONE_MIN <= state_1P.Gamepad.sThumbLX) &&	// X��������
		(state_1P.Gamepad.sThumbLX <= DEADZONE1_X) &&	// X�����܂�
		(DEADZONE2_Y <= state_1P.Gamepad.sThumbLY) &&	// Y��������
		(state_1P.Gamepad.sThumbLY <= DEADZONE_MAX))	// Y�����܂�
	{
		return true;
	}

	//  45.0 �k��
	if ((PushDirection == DIR::UPPER_RIGHT) &&
		(DEADZONE1_X <= state_1P.Gamepad.sThumbLX) &&	// X��������
		(state_1P.Gamepad.sThumbLX <= DEADZONE2_X) &&	// X�����܂�
		(DEADZONE1_Y <= state_1P.Gamepad.sThumbLY) &&	// Y��������
		(state_1P.Gamepad.sThumbLY <= DEADZONE2_Y))		// Y�����܂�
	{
		return true;
	}

	//  67.5 ���k��
	if ((PushDirection == DIR::R67d5) &&
		(DEADZONE2_X <= state_1P.Gamepad.sThumbLX) &&	// X��������
		(state_1P.Gamepad.sThumbLX <= DEADZONE_MAX) &&	// X�����܂�
		(DEADZONE_MIN <= state_1P.Gamepad.sThumbLY) &&	// Y��������
		(state_1P.Gamepad.sThumbLY <= DEADZONE1_Y))		// Y�����܂�
	{
		return true;
	}

	//  90.0 ��
	if ((PushDirection == DIR::RIGHT) &&
		(DEADZONE2_X <= state_1P.Gamepad.sThumbLX) &&	// X��������
		(state_1P.Gamepad.sThumbLX <= DEADZONE_MAX) &&	// X�����܂�
		(-DEADZONE_MIN <= state_1P.Gamepad.sThumbLY) &&	// Y��������
		(state_1P.Gamepad.sThumbLY <= DEADZONE_MIN))	// Y�����܂�
	{
		return true;
	}

	// 112.5 ���쓌
	if ((PushDirection == DIR::R112d5) &&
		(DEADZONE2_X <= state_1P.Gamepad.sThumbLX) &&	// X��������
		(state_1P.Gamepad.sThumbLX <= DEADZONE_MAX) &&	// X�����܂�
		(-DEADZONE1_Y <= state_1P.Gamepad.sThumbLY) &&	// Y��������
		(state_1P.Gamepad.sThumbLY <= -DEADZONE_MIN))	// Y�����܂�
	{
		return true;
	}

	// 135.0 �쓌
	if ((PushDirection == DIR::LOWER_RIGHT) &&
		(DEADZONE1_X <= state_1P.Gamepad.sThumbLX) &&	// X��������
		(state_1P.Gamepad.sThumbLX <= DEADZONE2_X) &&	// X�����܂�
		(-DEADZONE2_Y <= state_1P.Gamepad.sThumbLY) &&	// Y��������
		(state_1P.Gamepad.sThumbLY <= -DEADZONE1_Y))	// Y�����܂�
	{
		return true;
	}

	// 157.5 ��쓌
	if ((PushDirection == DIR::R157d5) &&
		(DEADZONE_MIN <= state_1P.Gamepad.sThumbLX) &&	// X��������
		(state_1P.Gamepad.sThumbLX <= DEADZONE1_X) &&	// X�����܂�
		(-DEADZONE_MAX <= state_1P.Gamepad.sThumbLY) &&	// Y��������
		(state_1P.Gamepad.sThumbLY <= -DEADZONE2_Y))	// Y�����܂�
	{
		return true;
	}

	// 180.0 ��
	if ((PushDirection == DIR::DOWN) &&
		(-DEADZONE_MIN <= state_1P.Gamepad.sThumbLX) &&	// X��������
		(state_1P.Gamepad.sThumbLX <= DEADZONE_MIN) &&	// X�����܂�
		(-DEADZONE_MAX <= state_1P.Gamepad.sThumbLY) &&	// Y��������
		(state_1P.Gamepad.sThumbLY <= -DEADZONE2_Y))	// Y�����܂�
	{
		return true;
	}

	// 202.5 ��쐼
	if ((PushDirection == DIR::R202d5) &&
		(-DEADZONE1_X <= state_1P.Gamepad.sThumbLX) &&	// X��������
		(state_1P.Gamepad.sThumbLX <= -DEADZONE_MIN) &&	// X�����܂�
		(-DEADZONE_MAX <= state_1P.Gamepad.sThumbLY) &&	// Y��������
		(state_1P.Gamepad.sThumbLY <= -DEADZONE2_Y))	// Y�����܂�
	{
		return true;
	}

	// 225.0 �쐼
	if ((PushDirection == DIR::LOWER_LEFT) &&
		(-DEADZONE2_X <= state_1P.Gamepad.sThumbLX) &&	// X��������
		(state_1P.Gamepad.sThumbLX <= -DEADZONE1_X) &&	// X�����܂�
		(-DEADZONE2_Y <= state_1P.Gamepad.sThumbLY) &&	// Y��������
		(state_1P.Gamepad.sThumbLY <= -DEADZONE1_Y))	// Y�����܂�
	{
		return true;
	}

	// 247.5 ���쐼
	if ((PushDirection == DIR::R247d5) &&
		(-DEADZONE_MAX <= state_1P.Gamepad.sThumbLX) &&	// X��������
		(state_1P.Gamepad.sThumbLX <= -DEADZONE2_X) &&	// X�����܂�
		(-DEADZONE1_Y <= state_1P.Gamepad.sThumbLY) &&	// Y��������
		(state_1P.Gamepad.sThumbLY <= -DEADZONE_MIN))	// Y�����܂�
	{
		return true;
	}

	// 270.0 ��
	if ((PushDirection == DIR::LEFT) &&
		(-DEADZONE_MAX <= state_1P.Gamepad.sThumbLX) &&	// X��������
		(state_1P.Gamepad.sThumbLX <= -DEADZONE2_X) &&	// X�����܂�
		(-DEADZONE_MIN <= state_1P.Gamepad.sThumbLY) &&	// Y��������
		(state_1P.Gamepad.sThumbLY <= DEADZONE_MIN))	// Y�����܂�
	{
		return true;
	}

	// 292.5 ���k��
	if ((PushDirection == DIR::R292d5) &&
		(-DEADZONE_MAX <= state_1P.Gamepad.sThumbLX) &&	// X��������
		(state_1P.Gamepad.sThumbLX <= -DEADZONE2_X) &&	// X�����܂�
		(DEADZONE_MIN <= state_1P.Gamepad.sThumbLY) &&	// Y��������
		(state_1P.Gamepad.sThumbLY <= DEADZONE1_Y))		// Y�����܂�
	{
		return true;
	}

	// 315.0 �k��
	if ((PushDirection == DIR::UPPER_LEFT) &&
		(-DEADZONE2_X <= state_1P.Gamepad.sThumbLX) &&	// X��������
		(state_1P.Gamepad.sThumbLX <= -DEADZONE1_X) &&	// X�����܂�
		(DEADZONE1_Y <= state_1P.Gamepad.sThumbLY) &&	// Y��������	
		(state_1P.Gamepad.sThumbLY <= DEADZONE2_Y))		// Y�����܂�	
	{
		return true;
	}

	// 337.5 �k�k��
	if ((PushDirection == DIR::R337d5) &&
		(-DEADZONE1_X <= state_1P.Gamepad.sThumbLX) &&	// X��������
		(state_1P.Gamepad.sThumbLX <= -DEADZONE_MIN) &&	// X�����܂�
		(DEADZONE2_Y <= state_1P.Gamepad.sThumbLY) &&	// Y��������
		(state_1P.Gamepad.sThumbLY <= DEADZONE_MAX))	// Y�����܂�
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

	//   0.0 �k
	if ((PushDirection == DIR::UP) &&
		(-DEADZONE_MIN <= state_2P.Gamepad.sThumbLX) &&	// X��������
		(state_2P.Gamepad.sThumbLX <= DEADZONE_MIN) &&	// X�����܂�
		(DEADZONE2_Y <= state_2P.Gamepad.sThumbLY) &&	// Y��������
		(state_2P.Gamepad.sThumbLY <= DEADZONE_MAX))	// Y�����܂�
	{
		return true;
	}

	//  22.5 �k�k��
	if ((PushDirection == DIR::R22d5) &&
		(DEADZONE_MIN <= state_2P.Gamepad.sThumbLX) &&	// X��������
		(state_2P.Gamepad.sThumbLX <= DEADZONE1_X) &&	// X�����܂�
		(DEADZONE2_Y <= state_2P.Gamepad.sThumbLY) &&	// Y��������
		(state_2P.Gamepad.sThumbLY <= DEADZONE_MAX))	// Y�����܂�
	{
		return true;
	}

	//  45.0 �k��
	if ((PushDirection == DIR::UPPER_RIGHT) &&
		(DEADZONE1_X <= state_2P.Gamepad.sThumbLX) &&	// X��������
		(state_2P.Gamepad.sThumbLX <= DEADZONE2_X) &&	// X�����܂�
		(DEADZONE1_Y <= state_2P.Gamepad.sThumbLY) &&	// Y��������
		(state_2P.Gamepad.sThumbLY <= DEADZONE2_Y))		// Y�����܂�
	{
		return true;
	}

	//  67.5 ���k��
	if ((PushDirection == DIR::R67d5) &&
		(DEADZONE2_X <= state_2P.Gamepad.sThumbLX) &&	// X��������
		(state_2P.Gamepad.sThumbLX <= DEADZONE_MAX) &&	// X�����܂�
		(DEADZONE_MIN <= state_2P.Gamepad.sThumbLY) &&	// Y��������
		(state_2P.Gamepad.sThumbLY <= DEADZONE1_Y))		// Y�����܂�
	{
		return true;
	}

	//  90.0 ��
	if ((PushDirection == DIR::RIGHT) &&
		(DEADZONE2_X <= state_2P.Gamepad.sThumbLX) &&	// X��������
		(state_2P.Gamepad.sThumbLX <= DEADZONE_MAX) &&	// X�����܂�
		(-DEADZONE_MIN <= state_2P.Gamepad.sThumbLY) &&	// Y��������
		(state_2P.Gamepad.sThumbLY <= DEADZONE_MIN))	// Y�����܂�
	{
		return true;
	}

	// 112.5 ���쓌
	if ((PushDirection == DIR::R112d5) &&
		(DEADZONE2_X <= state_2P.Gamepad.sThumbLX) &&	// X��������
		(state_2P.Gamepad.sThumbLX <= DEADZONE_MAX) &&	// X�����܂�
		(-DEADZONE1_Y <= state_2P.Gamepad.sThumbLY) &&	// Y��������
		(state_2P.Gamepad.sThumbLY <= -DEADZONE_MIN))	// Y�����܂�
	{
		return true;
	}

	// 135.0 �쓌
	if ((PushDirection == DIR::LOWER_RIGHT) &&
		(DEADZONE1_X <= state_2P.Gamepad.sThumbLX) &&	// X��������
		(state_2P.Gamepad.sThumbLX <= DEADZONE2_X) &&	// X�����܂�
		(-DEADZONE2_Y <= state_2P.Gamepad.sThumbLY) &&	// Y��������
		(state_2P.Gamepad.sThumbLY <= -DEADZONE1_Y))	// Y�����܂�
	{
		return true;
	}

	// 157.5 ��쓌
	if ((PushDirection == DIR::R157d5) &&
		(DEADZONE_MIN <= state_2P.Gamepad.sThumbLX) &&	// X��������
		(state_2P.Gamepad.sThumbLX <= DEADZONE1_X) &&	// X�����܂�
		(-DEADZONE_MAX <= state_2P.Gamepad.sThumbLY) &&	// Y��������
		(state_2P.Gamepad.sThumbLY <= -DEADZONE2_Y))	// Y�����܂�
	{
		return true;
	}

	// 180.0 ��
	if ((PushDirection == DIR::DOWN) &&
		(-DEADZONE_MIN <= state_2P.Gamepad.sThumbLX) &&	// X��������
		(state_2P.Gamepad.sThumbLX <= DEADZONE_MIN) &&	// X�����܂�
		(-DEADZONE_MAX <= state_2P.Gamepad.sThumbLY) &&	// Y��������
		(state_2P.Gamepad.sThumbLY <= -DEADZONE2_Y))	// Y�����܂�
	{
		return true;
	}

	// 202.5 ��쐼
	if ((PushDirection == DIR::R202d5) &&
		(-DEADZONE1_X <= state_2P.Gamepad.sThumbLX) &&	// X��������
		(state_2P.Gamepad.sThumbLX <= -DEADZONE_MIN) &&	// X�����܂�
		(-DEADZONE_MAX <= state_2P.Gamepad.sThumbLY) &&	// Y��������
		(state_2P.Gamepad.sThumbLY <= -DEADZONE2_Y))	// Y�����܂�
	{
		return true;
	}

	// 225.0 �쐼
	if ((PushDirection == DIR::LOWER_LEFT) &&
		(-DEADZONE2_X <= state_2P.Gamepad.sThumbLX) &&	// X��������
		(state_2P.Gamepad.sThumbLX <= -DEADZONE1_X) &&	// X�����܂�
		(-DEADZONE2_Y <= state_2P.Gamepad.sThumbLY) &&	// Y��������
		(state_2P.Gamepad.sThumbLY <= -DEADZONE1_Y))	// Y�����܂�
	{
		return true;
	}

	// 247.5 ���쐼
	if ((PushDirection == DIR::R247d5) &&
		(-DEADZONE_MAX <= state_2P.Gamepad.sThumbLX) &&	// X��������
		(state_2P.Gamepad.sThumbLX <= -DEADZONE2_X) &&	// X�����܂�
		(-DEADZONE1_Y <= state_2P.Gamepad.sThumbLY) &&	// Y��������
		(state_2P.Gamepad.sThumbLY <= -DEADZONE_MIN))	// Y�����܂�
	{
		return true;
	}

	// 270.0 ��
	if ((PushDirection == DIR::LEFT) &&
		(-DEADZONE_MAX <= state_2P.Gamepad.sThumbLX) &&	// X��������
		(state_2P.Gamepad.sThumbLX <= -DEADZONE2_X) &&	// X�����܂�
		(-DEADZONE_MIN <= state_2P.Gamepad.sThumbLY) &&	// Y��������
		(state_2P.Gamepad.sThumbLY <= DEADZONE_MIN))	// Y�����܂�
	{
		return true;
	}

	// 292.5 ���k��
	if ((PushDirection == DIR::R292d5) &&
		(-DEADZONE_MAX <= state_2P.Gamepad.sThumbLX) &&	// X��������
		(state_2P.Gamepad.sThumbLX <= -DEADZONE2_X) &&	// X�����܂�
		(DEADZONE_MIN <= state_2P.Gamepad.sThumbLY) &&	// Y��������
		(state_2P.Gamepad.sThumbLY <= DEADZONE1_Y))		// Y�����܂�
	{
		return true;
	}

	// 315.0 �k��
	if ((PushDirection == DIR::UPPER_LEFT) &&
		(-DEADZONE2_X <= state_2P.Gamepad.sThumbLX) &&	// X��������
		(state_2P.Gamepad.sThumbLX <= -DEADZONE1_X) &&	// X�����܂�
		(DEADZONE1_Y <= state_2P.Gamepad.sThumbLY) &&	// Y��������	
		(state_2P.Gamepad.sThumbLY <= DEADZONE2_Y))		// Y�����܂�	
	{
		return true;
	}

	// 337.5 �k�k��
	if ((PushDirection == DIR::R337d5) &&
		(-DEADZONE1_X <= state_2P.Gamepad.sThumbLX) &&	// X��������
		(state_2P.Gamepad.sThumbLX <= -DEADZONE_MIN) &&	// X�����܂�
		(DEADZONE2_Y <= state_2P.Gamepad.sThumbLY) &&	// Y��������
		(state_2P.Gamepad.sThumbLY <= DEADZONE_MAX))	// Y�����܂�
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

	//   0.0 �k
	if ((PushDirection == DIR::UP) &&
		(-DEADZONE_MIN <= state_3P.Gamepad.sThumbLX) &&	// X��������
		(state_3P.Gamepad.sThumbLX <= DEADZONE_MIN) &&	// X�����܂�
		(DEADZONE2_Y <= state_3P.Gamepad.sThumbLY) &&	// Y��������
		(state_3P.Gamepad.sThumbLY <= DEADZONE_MAX))	// Y�����܂�
	{
		return true;
	}

	//  22.5 �k�k��
	if ((PushDirection == DIR::R22d5) &&
		(DEADZONE_MIN <= state_3P.Gamepad.sThumbLX) &&	// X��������
		(state_3P.Gamepad.sThumbLX <= DEADZONE1_X) &&	// X�����܂�
		(DEADZONE2_Y <= state_3P.Gamepad.sThumbLY) &&	// Y��������
		(state_3P.Gamepad.sThumbLY <= DEADZONE_MAX))	// Y�����܂�
	{
		return true;
	}

	//  45.0 �k��
	if ((PushDirection == DIR::UPPER_RIGHT) &&
		(DEADZONE1_X <= state_3P.Gamepad.sThumbLX) &&	// X��������
		(state_3P.Gamepad.sThumbLX <= DEADZONE2_X) &&	// X�����܂�
		(DEADZONE1_Y <= state_3P.Gamepad.sThumbLY) &&	// Y��������
		(state_3P.Gamepad.sThumbLY <= DEADZONE2_Y))		// Y�����܂�
	{
		return true;
	}

	//  67.5 ���k��
	if ((PushDirection == DIR::R67d5) &&
		(DEADZONE2_X <= state_3P.Gamepad.sThumbLX) &&	// X��������
		(state_3P.Gamepad.sThumbLX <= DEADZONE_MAX) &&	// X�����܂�
		(DEADZONE_MIN <= state_3P.Gamepad.sThumbLY) &&	// Y��������
		(state_3P.Gamepad.sThumbLY <= DEADZONE1_Y))		// Y�����܂�
	{
		return true;
	}

	//  90.0 ��
	if ((PushDirection == DIR::RIGHT) &&
		(DEADZONE2_X <= state_3P.Gamepad.sThumbLX) &&	// X��������
		(state_3P.Gamepad.sThumbLX <= DEADZONE_MAX) &&	// X�����܂�
		(-DEADZONE_MIN <= state_3P.Gamepad.sThumbLY) &&	// Y��������
		(state_3P.Gamepad.sThumbLY <= DEADZONE_MIN))	// Y�����܂�
	{
		return true;
	}

	// 112.5 ���쓌
	if ((PushDirection == DIR::R112d5) &&
		(DEADZONE2_X <= state_3P.Gamepad.sThumbLX) &&	// X��������
		(state_3P.Gamepad.sThumbLX <= DEADZONE_MAX) &&	// X�����܂�
		(-DEADZONE1_Y <= state_3P.Gamepad.sThumbLY) &&	// Y��������
		(state_3P.Gamepad.sThumbLY <= -DEADZONE_MIN))	// Y�����܂�
	{
		return true;
	}

	// 135.0 �쓌
	if ((PushDirection == DIR::LOWER_RIGHT) &&
		(DEADZONE1_X <= state_3P.Gamepad.sThumbLX) &&	// X��������
		(state_3P.Gamepad.sThumbLX <= DEADZONE2_X) &&	// X�����܂�
		(-DEADZONE2_Y <= state_3P.Gamepad.sThumbLY) &&	// Y��������
		(state_3P.Gamepad.sThumbLY <= -DEADZONE1_Y))	// Y�����܂�
	{
		return true;
	}

	// 157.5 ��쓌
	if ((PushDirection == DIR::R157d5) &&
		(DEADZONE_MIN <= state_3P.Gamepad.sThumbLX) &&	// X��������
		(state_3P.Gamepad.sThumbLX <= DEADZONE1_X) &&	// X�����܂�
		(-DEADZONE_MAX <= state_3P.Gamepad.sThumbLY) &&	// Y��������
		(state_3P.Gamepad.sThumbLY <= -DEADZONE2_Y))	// Y�����܂�
	{
		return true;
	}

	// 180.0 ��
	if ((PushDirection == DIR::DOWN) &&
		(-DEADZONE_MIN <= state_3P.Gamepad.sThumbLX) &&	// X��������
		(state_3P.Gamepad.sThumbLX <= DEADZONE_MIN) &&	// X�����܂�
		(-DEADZONE_MAX <= state_3P.Gamepad.sThumbLY) &&	// Y��������
		(state_3P.Gamepad.sThumbLY <= -DEADZONE2_Y))	// Y�����܂�
	{
		return true;
	}

	// 202.5 ��쐼
	if ((PushDirection == DIR::R202d5) &&
		(-DEADZONE1_X <= state_3P.Gamepad.sThumbLX) &&	// X��������
		(state_3P.Gamepad.sThumbLX <= -DEADZONE_MIN) &&	// X�����܂�
		(-DEADZONE_MAX <= state_3P.Gamepad.sThumbLY) &&	// Y��������
		(state_3P.Gamepad.sThumbLY <= -DEADZONE2_Y))	// Y�����܂�
	{
		return true;
	}

	// 225.0 �쐼
	if ((PushDirection == DIR::LOWER_LEFT) &&
		(-DEADZONE2_X <= state_3P.Gamepad.sThumbLX) &&	// X��������
		(state_3P.Gamepad.sThumbLX <= -DEADZONE1_X) &&	// X�����܂�
		(-DEADZONE2_Y <= state_3P.Gamepad.sThumbLY) &&	// Y��������
		(state_3P.Gamepad.sThumbLY <= -DEADZONE1_Y))	// Y�����܂�
	{
		return true;
	}

	// 247.5 ���쐼
	if ((PushDirection == DIR::R247d5) &&
		(-DEADZONE_MAX <= state_3P.Gamepad.sThumbLX) &&	// X��������
		(state_3P.Gamepad.sThumbLX <= -DEADZONE2_X) &&	// X�����܂�
		(-DEADZONE1_Y <= state_3P.Gamepad.sThumbLY) &&	// Y��������
		(state_3P.Gamepad.sThumbLY <= -DEADZONE_MIN))	// Y�����܂�
	{
		return true;
	}

	// 270.0 ��
	if ((PushDirection == DIR::LEFT) &&
		(-DEADZONE_MAX <= state_3P.Gamepad.sThumbLX) &&	// X��������
		(state_3P.Gamepad.sThumbLX <= -DEADZONE2_X) &&	// X�����܂�
		(-DEADZONE_MIN <= state_3P.Gamepad.sThumbLY) &&	// Y��������
		(state_3P.Gamepad.sThumbLY <= DEADZONE_MIN))	// Y�����܂�
	{
		return true;
	}

	// 292.5 ���k��
	if ((PushDirection == DIR::R292d5) &&
		(-DEADZONE_MAX <= state_3P.Gamepad.sThumbLX) &&	// X��������
		(state_3P.Gamepad.sThumbLX <= -DEADZONE2_X) &&	// X�����܂�
		(DEADZONE_MIN <= state_3P.Gamepad.sThumbLY) &&	// Y��������
		(state_3P.Gamepad.sThumbLY <= DEADZONE1_Y))		// Y�����܂�
	{
		return true;
	}

	// 315.0 �k��
	if ((PushDirection == DIR::UPPER_LEFT) &&
		(-DEADZONE2_X <= state_3P.Gamepad.sThumbLX) &&	// X��������
		(state_3P.Gamepad.sThumbLX <= -DEADZONE1_X) &&	// X�����܂�
		(DEADZONE1_Y <= state_3P.Gamepad.sThumbLY) &&	// Y��������	
		(state_3P.Gamepad.sThumbLY <= DEADZONE2_Y))		// Y�����܂�	
	{
		return true;
	}

	// 337.5 �k�k��
	if ((PushDirection == DIR::R337d5) &&
		(-DEADZONE1_X <= state_3P.Gamepad.sThumbLX) &&	// X��������
		(state_3P.Gamepad.sThumbLX <= -DEADZONE_MIN) &&	// X�����܂�
		(DEADZONE2_Y <= state_3P.Gamepad.sThumbLY) &&	// Y��������
		(state_3P.Gamepad.sThumbLY <= DEADZONE_MAX))	// Y�����܂�
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

	//   0.0 �k
	if ((PushDirection == DIR::UP) &&
		(-DEADZONE_MIN <= state_4P.Gamepad.sThumbLX) &&	// X��������
		(state_4P.Gamepad.sThumbLX <= DEADZONE_MIN) &&	// X�����܂�
		(DEADZONE2_Y <= state_4P.Gamepad.sThumbLY) &&	// Y��������
		(state_4P.Gamepad.sThumbLY <= DEADZONE_MAX))	// Y�����܂�
	{
		return true;
	}

	//  22.5 �k�k��
	if ((PushDirection == DIR::R22d5) &&
		(DEADZONE_MIN <= state_4P.Gamepad.sThumbLX) &&	// X��������
		(state_4P.Gamepad.sThumbLX <= DEADZONE1_X) &&	// X�����܂�
		(DEADZONE2_Y <= state_4P.Gamepad.sThumbLY) &&	// Y��������
		(state_4P.Gamepad.sThumbLY <= DEADZONE_MAX))	// Y�����܂�
	{
		return true;
	}

	//  45.0 �k��
	if ((PushDirection == DIR::UPPER_RIGHT) &&
		(DEADZONE1_X <= state_4P.Gamepad.sThumbLX) &&	// X��������
		(state_4P.Gamepad.sThumbLX <= DEADZONE2_X) &&	// X�����܂�
		(DEADZONE1_Y <= state_4P.Gamepad.sThumbLY) &&	// Y��������
		(state_4P.Gamepad.sThumbLY <= DEADZONE2_Y))		// Y�����܂�
	{
		return true;
	}

	//  67.5 ���k��
	if ((PushDirection == DIR::R67d5) &&
		(DEADZONE2_X <= state_4P.Gamepad.sThumbLX) &&	// X��������
		(state_4P.Gamepad.sThumbLX <= DEADZONE_MAX) &&	// X�����܂�
		(DEADZONE_MIN <= state_4P.Gamepad.sThumbLY) &&	// Y��������
		(state_4P.Gamepad.sThumbLY <= DEADZONE1_Y))		// Y�����܂�
	{
		return true;
	}

	//  90.0 ��
	if ((PushDirection == DIR::RIGHT) &&
		(DEADZONE2_X <= state_4P.Gamepad.sThumbLX) &&	// X��������
		(state_4P.Gamepad.sThumbLX <= DEADZONE_MAX) &&	// X�����܂�
		(-DEADZONE_MIN <= state_4P.Gamepad.sThumbLY) &&	// Y��������
		(state_4P.Gamepad.sThumbLY <= DEADZONE_MIN))	// Y�����܂�
	{
		return true;
	}

	// 112.5 ���쓌
	if ((PushDirection == DIR::R112d5) &&
		(DEADZONE2_X <= state_4P.Gamepad.sThumbLX) &&	// X��������
		(state_4P.Gamepad.sThumbLX <= DEADZONE_MAX) &&	// X�����܂�
		(-DEADZONE1_Y <= state_4P.Gamepad.sThumbLY) &&	// Y��������
		(state_4P.Gamepad.sThumbLY <= -DEADZONE_MIN))	// Y�����܂�
	{
		return true;
	}

	// 135.0 �쓌
	if ((PushDirection == DIR::LOWER_RIGHT) &&
		(DEADZONE1_X <= state_4P.Gamepad.sThumbLX) &&	// X��������
		(state_4P.Gamepad.sThumbLX <= DEADZONE2_X) &&	// X�����܂�
		(-DEADZONE2_Y <= state_4P.Gamepad.sThumbLY) &&	// Y��������
		(state_4P.Gamepad.sThumbLY <= -DEADZONE1_Y))	// Y�����܂�
	{
		return true;
	}

	// 157.5 ��쓌
	if ((PushDirection == DIR::R157d5) &&
		(DEADZONE_MIN <= state_4P.Gamepad.sThumbLX) &&	// X��������
		(state_4P.Gamepad.sThumbLX <= DEADZONE1_X) &&	// X�����܂�
		(-DEADZONE_MAX <= state_4P.Gamepad.sThumbLY) &&	// Y��������
		(state_4P.Gamepad.sThumbLY <= -DEADZONE2_Y))	// Y�����܂�
	{
		return true;
	}

	// 180.0 ��
	if ((PushDirection == DIR::DOWN) &&
		(-DEADZONE_MIN <= state_4P.Gamepad.sThumbLX) &&	// X��������
		(state_4P.Gamepad.sThumbLX <= DEADZONE_MIN) &&	// X�����܂�
		(-DEADZONE_MAX <= state_4P.Gamepad.sThumbLY) &&	// Y��������
		(state_4P.Gamepad.sThumbLY <= -DEADZONE2_Y))	// Y�����܂�
	{
		return true;
	}

	// 202.5 ��쐼
	if ((PushDirection == DIR::R202d5) &&
		(-DEADZONE1_X <= state_4P.Gamepad.sThumbLX) &&	// X��������
		(state_4P.Gamepad.sThumbLX <= -DEADZONE_MIN) &&	// X�����܂�
		(-DEADZONE_MAX <= state_4P.Gamepad.sThumbLY) &&	// Y��������
		(state_4P.Gamepad.sThumbLY <= -DEADZONE2_Y))	// Y�����܂�
	{
		return true;
	}

	// 225.0 �쐼
	if ((PushDirection == DIR::LOWER_LEFT) &&
		(-DEADZONE2_X <= state_4P.Gamepad.sThumbLX) &&	// X��������
		(state_4P.Gamepad.sThumbLX <= -DEADZONE1_X) &&	// X�����܂�
		(-DEADZONE2_Y <= state_4P.Gamepad.sThumbLY) &&	// Y��������
		(state_4P.Gamepad.sThumbLY <= -DEADZONE1_Y))	// Y�����܂�
	{
		return true;
	}

	// 247.5 ���쐼
	if ((PushDirection == DIR::R247d5) &&
		(-DEADZONE_MAX <= state_4P.Gamepad.sThumbLX) &&	// X��������
		(state_4P.Gamepad.sThumbLX <= -DEADZONE2_X) &&	// X�����܂�
		(-DEADZONE1_Y <= state_4P.Gamepad.sThumbLY) &&	// Y��������
		(state_4P.Gamepad.sThumbLY <= -DEADZONE_MIN))	// Y�����܂�
	{
		return true;
	}

	// 270.0 ��
	if ((PushDirection == DIR::LEFT) &&
		(-DEADZONE_MAX <= state_4P.Gamepad.sThumbLX) &&	// X��������
		(state_4P.Gamepad.sThumbLX <= -DEADZONE2_X) &&	// X�����܂�
		(-DEADZONE_MIN <= state_4P.Gamepad.sThumbLY) &&	// Y��������
		(state_4P.Gamepad.sThumbLY <= DEADZONE_MIN))	// Y�����܂�
	{
		return true;
	}

	// 292.5 ���k��
	if ((PushDirection == DIR::R292d5) &&
		(-DEADZONE_MAX <= state_4P.Gamepad.sThumbLX) &&	// X��������
		(state_4P.Gamepad.sThumbLX <= -DEADZONE2_X) &&	// X�����܂�
		(DEADZONE_MIN <= state_4P.Gamepad.sThumbLY) &&	// Y��������
		(state_4P.Gamepad.sThumbLY <= DEADZONE1_Y))		// Y�����܂�
	{
		return true;
	}

	// 315.0 �k��
	if ((PushDirection == DIR::UPPER_LEFT) &&
		(-DEADZONE2_X <= state_4P.Gamepad.sThumbLX) &&	// X��������
		(state_4P.Gamepad.sThumbLX <= -DEADZONE1_X) &&	// X�����܂�
		(DEADZONE1_Y <= state_4P.Gamepad.sThumbLY) &&	// Y��������	
		(state_4P.Gamepad.sThumbLY <= DEADZONE2_Y))		// Y�����܂�	
	{
		return true;
	}

	// 337.5 �k�k��
	if ((PushDirection == DIR::R337d5) &&
		(-DEADZONE1_X <= state_4P.Gamepad.sThumbLX) &&	// X��������
		(state_4P.Gamepad.sThumbLX <= -DEADZONE_MIN) &&	// X�����܂�
		(DEADZONE2_Y <= state_4P.Gamepad.sThumbLY) &&	// Y��������
		(state_4P.Gamepad.sThumbLY <= DEADZONE_MAX))	// Y�����܂�
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

	//   0.0 �k
	if ((PushDirection == DIR::UP) &&
		(-DEADZONE_MIN <= state_1P.Gamepad.sThumbRX) &&	// X��������
		(state_1P.Gamepad.sThumbRX <= DEADZONE_MIN) &&	// X�����܂�
		(DEADZONE2_Y <= state_1P.Gamepad.sThumbRY) &&	// Y��������
		(state_1P.Gamepad.sThumbRY <= DEADZONE_MAX))	// Y�����܂�
	{
		return true;
	}

	//  22.5 �k�k��
	if ((PushDirection == DIR::R22d5) &&
		(DEADZONE_MIN <= state_1P.Gamepad.sThumbRX) &&	// X��������
		(state_1P.Gamepad.sThumbRX <= DEADZONE1_X) &&	// X�����܂�
		(DEADZONE2_Y <= state_1P.Gamepad.sThumbRY) &&	// Y��������
		(state_1P.Gamepad.sThumbRY <= DEADZONE_MAX))	// Y�����܂�
	{
		return true;
	}

	//  45.0 �k��
	if ((PushDirection == DIR::UPPER_RIGHT) &&
		(DEADZONE1_X <= state_1P.Gamepad.sThumbRX) &&	// X��������
		(state_1P.Gamepad.sThumbRX <= DEADZONE2_X) &&	// X�����܂�
		(DEADZONE1_Y <= state_1P.Gamepad.sThumbRY) &&	// Y��������
		(state_1P.Gamepad.sThumbRY <= DEADZONE2_Y))		// Y�����܂�
	{
		return true;
	}

	//  67.5 ���k��
	if ((PushDirection == DIR::R67d5) &&
		(DEADZONE2_X <= state_1P.Gamepad.sThumbRX) &&	// X��������
		(state_1P.Gamepad.sThumbRX <= DEADZONE_MAX) &&	// X�����܂�
		(DEADZONE_MIN <= state_1P.Gamepad.sThumbRY) &&	// Y��������
		(state_1P.Gamepad.sThumbRY <= DEADZONE1_Y))		// Y�����܂�
	{
		return true;
	}

	//  90.0 ��
	if ((PushDirection == DIR::RIGHT) &&
		(DEADZONE2_X <= state_1P.Gamepad.sThumbRX) &&	// X��������
		(state_1P.Gamepad.sThumbRX <= DEADZONE_MAX) &&	// X�����܂�
		(-DEADZONE_MIN <= state_1P.Gamepad.sThumbRY) &&	// Y��������
		(state_1P.Gamepad.sThumbRY <= DEADZONE_MIN))	// Y�����܂�
	{
		return true;
	}

	// 112.5 ���쓌
	if ((PushDirection == DIR::R112d5) &&
		(DEADZONE2_X <= state_1P.Gamepad.sThumbRX) &&	// X��������
		(state_1P.Gamepad.sThumbRX <= DEADZONE_MAX) &&	// X�����܂�
		(-DEADZONE1_Y <= state_1P.Gamepad.sThumbRY) &&	// Y��������
		(state_1P.Gamepad.sThumbRY <= -DEADZONE_MIN))	// Y�����܂�
	{
		return true;
	}

	// 135.0 �쓌
	if ((PushDirection == DIR::LOWER_RIGHT) &&
		(DEADZONE1_X <= state_1P.Gamepad.sThumbRX) &&	// X��������
		(state_1P.Gamepad.sThumbRX <= DEADZONE2_X) &&	// X�����܂�
		(-DEADZONE2_Y <= state_1P.Gamepad.sThumbRY) &&	// Y��������
		(state_1P.Gamepad.sThumbRY <= -DEADZONE1_Y))	// Y�����܂�
	{
		return true;
	}

	// 157.5 ��쓌
	if ((PushDirection == DIR::R157d5) &&
		(DEADZONE_MIN <= state_1P.Gamepad.sThumbRX) &&	// X��������
		(state_1P.Gamepad.sThumbRX <= DEADZONE1_X) &&	// X�����܂�
		(-DEADZONE_MAX <= state_1P.Gamepad.sThumbRY) &&	// Y��������
		(state_1P.Gamepad.sThumbRY <= -DEADZONE2_Y))	// Y�����܂�
	{
		return true;
	}

	// 180.0 ��
	if ((PushDirection == DIR::DOWN) &&
		(-DEADZONE_MIN <= state_1P.Gamepad.sThumbRX) &&	// X��������
		(state_1P.Gamepad.sThumbRX <= DEADZONE_MIN) &&	// X�����܂�
		(-DEADZONE_MAX <= state_1P.Gamepad.sThumbRY) &&	// Y��������
		(state_1P.Gamepad.sThumbRY <= -DEADZONE2_Y))	// Y�����܂�
	{
		return true;
	}

	// 202.5 ��쐼
	if ((PushDirection == DIR::R202d5) &&
		(-DEADZONE1_X <= state_1P.Gamepad.sThumbRX) &&	// X��������
		(state_1P.Gamepad.sThumbRX <= -DEADZONE_MIN) &&	// X�����܂�
		(-DEADZONE_MAX <= state_1P.Gamepad.sThumbRY) &&	// Y��������
		(state_1P.Gamepad.sThumbRY <= -DEADZONE2_Y))	// Y�����܂�
	{
		return true;
	}

	// 225.0 �쐼
	if ((PushDirection == DIR::LOWER_LEFT) &&
		(-DEADZONE2_X <= state_1P.Gamepad.sThumbRX) &&	// X��������
		(state_1P.Gamepad.sThumbRX <= -DEADZONE1_X) &&	// X�����܂�
		(-DEADZONE2_Y <= state_1P.Gamepad.sThumbRY) &&	// Y��������
		(state_1P.Gamepad.sThumbRY <= -DEADZONE1_Y))	// Y�����܂�
	{
		return true;
	}

	// 247.5 ���쐼
	if ((PushDirection == DIR::R247d5) &&
		(-DEADZONE_MAX <= state_1P.Gamepad.sThumbRX) &&	// X��������
		(state_1P.Gamepad.sThumbRX <= -DEADZONE2_X) &&	// X�����܂�
		(-DEADZONE1_Y <= state_1P.Gamepad.sThumbRY) &&	// Y��������
		(state_1P.Gamepad.sThumbRY <= -DEADZONE_MIN))	// Y�����܂�
	{
		return true;
	}

	// 270.0 ��
	if ((PushDirection == DIR::LEFT) &&
		(-DEADZONE_MAX <= state_1P.Gamepad.sThumbRX) &&	// X��������
		(state_1P.Gamepad.sThumbRX <= -DEADZONE2_X) &&	// X�����܂�
		(-DEADZONE_MIN <= state_1P.Gamepad.sThumbRY) &&	// Y��������
		(state_1P.Gamepad.sThumbRY <= DEADZONE_MIN))	// Y�����܂�
	{
		return true;
	}

	// 292.5 ���k��
	if ((PushDirection == DIR::R292d5) &&
		(-DEADZONE_MAX <= state_1P.Gamepad.sThumbRX) &&	// X��������
		(state_1P.Gamepad.sThumbRX <= -DEADZONE2_X) &&	// X�����܂�
		(DEADZONE_MIN <= state_1P.Gamepad.sThumbRY) &&	// Y��������
		(state_1P.Gamepad.sThumbRY <= DEADZONE1_Y))		// Y�����܂�
	{
		return true;
	}

	// 315.0 �k��
	if ((PushDirection == DIR::UPPER_LEFT) &&
		(-DEADZONE2_X <= state_1P.Gamepad.sThumbRX) &&	// X��������
		(state_1P.Gamepad.sThumbRX <= -DEADZONE1_X) &&	// X�����܂�
		(DEADZONE1_Y <= state_1P.Gamepad.sThumbRY) &&	// Y��������	
		(state_1P.Gamepad.sThumbRY <= DEADZONE2_Y))		// Y�����܂�	
	{
		return true;
	}

	// 337.5 �k�k��
	if ((PushDirection == DIR::R337d5) &&
		(-DEADZONE1_X <= state_1P.Gamepad.sThumbRX) &&	// X��������
		(state_1P.Gamepad.sThumbRX <= -DEADZONE_MIN) &&	// X�����܂�
		(DEADZONE2_Y <= state_1P.Gamepad.sThumbRY) &&	// Y��������
		(state_1P.Gamepad.sThumbRY <= DEADZONE_MAX))	// Y�����܂�
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

	//   0.0 �k
	if ((PushDirection == DIR::UP) &&
		(-DEADZONE_MIN <= state_2P.Gamepad.sThumbRX) &&	// X��������
		(state_2P.Gamepad.sThumbRX <= DEADZONE_MIN) &&	// X�����܂�
		(DEADZONE2_Y <= state_2P.Gamepad.sThumbRY) &&	// Y��������
		(state_2P.Gamepad.sThumbRY <= DEADZONE_MAX))	// Y�����܂�
	{
		return true;
	}

	//  22.5 �k�k��
	if ((PushDirection == DIR::R22d5) &&
		(DEADZONE_MIN <= state_2P.Gamepad.sThumbRX) &&	// X��������
		(state_2P.Gamepad.sThumbRX <= DEADZONE1_X) &&	// X�����܂�
		(DEADZONE2_Y <= state_2P.Gamepad.sThumbRY) &&	// Y��������
		(state_2P.Gamepad.sThumbRY <= DEADZONE_MAX))	// Y�����܂�
	{
		return true;
	}

	//  45.0 �k��
	if ((PushDirection == DIR::UPPER_RIGHT) &&
		(DEADZONE1_X <= state_2P.Gamepad.sThumbRX) &&	// X��������
		(state_2P.Gamepad.sThumbRX <= DEADZONE2_X) &&	// X�����܂�
		(DEADZONE1_Y <= state_2P.Gamepad.sThumbRY) &&	// Y��������
		(state_2P.Gamepad.sThumbRY <= DEADZONE2_Y))		// Y�����܂�
	{
		return true;
	}

	//  67.5 ���k��
	if ((PushDirection == DIR::R67d5) &&
		(DEADZONE2_X <= state_2P.Gamepad.sThumbRX) &&	// X��������
		(state_2P.Gamepad.sThumbRX <= DEADZONE_MAX) &&	// X�����܂�
		(DEADZONE_MIN <= state_2P.Gamepad.sThumbRY) &&	// Y��������
		(state_2P.Gamepad.sThumbRY <= DEADZONE1_Y))		// Y�����܂�
	{
		return true;
	}

	//  90.0 ��
	if ((PushDirection == DIR::RIGHT) &&
		(DEADZONE2_X <= state_2P.Gamepad.sThumbRX) &&	// X��������
		(state_2P.Gamepad.sThumbRX <= DEADZONE_MAX) &&	// X�����܂�
		(-DEADZONE_MIN <= state_2P.Gamepad.sThumbRY) &&	// Y��������
		(state_2P.Gamepad.sThumbRY <= DEADZONE_MIN))	// Y�����܂�
	{
		return true;
	}

	// 112.5 ���쓌
	if ((PushDirection == DIR::R112d5) &&
		(DEADZONE2_X <= state_2P.Gamepad.sThumbRX) &&	// X��������
		(state_2P.Gamepad.sThumbRX <= DEADZONE_MAX) &&	// X�����܂�
		(-DEADZONE1_Y <= state_2P.Gamepad.sThumbRY) &&	// Y��������
		(state_2P.Gamepad.sThumbRY <= -DEADZONE_MIN))	// Y�����܂�
	{
		return true;
	}

	// 135.0 �쓌
	if ((PushDirection == DIR::LOWER_RIGHT) &&
		(DEADZONE1_X <= state_2P.Gamepad.sThumbRX) &&	// X��������
		(state_2P.Gamepad.sThumbRX <= DEADZONE2_X) &&	// X�����܂�
		(-DEADZONE2_Y <= state_2P.Gamepad.sThumbRY) &&	// Y��������
		(state_2P.Gamepad.sThumbRY <= -DEADZONE1_Y))	// Y�����܂�
	{
		return true;
	}

	// 157.5 ��쓌
	if ((PushDirection == DIR::R157d5) &&
		(DEADZONE_MIN <= state_2P.Gamepad.sThumbRX) &&	// X��������
		(state_2P.Gamepad.sThumbRX <= DEADZONE1_X) &&	// X�����܂�
		(-DEADZONE_MAX <= state_2P.Gamepad.sThumbRY) &&	// Y��������
		(state_2P.Gamepad.sThumbRY <= -DEADZONE2_Y))	// Y�����܂�
	{
		return true;
	}

	// 180.0 ��
	if ((PushDirection == DIR::DOWN) &&
		(-DEADZONE_MIN <= state_2P.Gamepad.sThumbRX) &&	// X��������
		(state_2P.Gamepad.sThumbRX <= DEADZONE_MIN) &&	// X�����܂�
		(-DEADZONE_MAX <= state_2P.Gamepad.sThumbRY) &&	// Y��������
		(state_2P.Gamepad.sThumbRY <= -DEADZONE2_Y))	// Y�����܂�
	{
		return true;
	}

	// 202.5 ��쐼
	if ((PushDirection == DIR::R202d5) &&
		(-DEADZONE1_X <= state_2P.Gamepad.sThumbRX) &&	// X��������
		(state_2P.Gamepad.sThumbRX <= -DEADZONE_MIN) &&	// X�����܂�
		(-DEADZONE_MAX <= state_2P.Gamepad.sThumbRY) &&	// Y��������
		(state_2P.Gamepad.sThumbRY <= -DEADZONE2_Y))	// Y�����܂�
	{
		return true;
	}

	// 225.0 �쐼
	if ((PushDirection == DIR::LOWER_LEFT) &&
		(-DEADZONE2_X <= state_2P.Gamepad.sThumbRX) &&	// X��������
		(state_2P.Gamepad.sThumbRX <= -DEADZONE1_X) &&	// X�����܂�
		(-DEADZONE2_Y <= state_2P.Gamepad.sThumbRY) &&	// Y��������
		(state_2P.Gamepad.sThumbRY <= -DEADZONE1_Y))	// Y�����܂�
	{
		return true;
	}

	// 247.5 ���쐼
	if ((PushDirection == DIR::R247d5) &&
		(-DEADZONE_MAX <= state_2P.Gamepad.sThumbRX) &&	// X��������
		(state_2P.Gamepad.sThumbRX <= -DEADZONE2_X) &&	// X�����܂�
		(-DEADZONE1_Y <= state_2P.Gamepad.sThumbRY) &&	// Y��������
		(state_2P.Gamepad.sThumbRY <= -DEADZONE_MIN))	// Y�����܂�
	{
		return true;
	}

	// 270.0 ��
	if ((PushDirection == DIR::LEFT) &&
		(-DEADZONE_MAX <= state_2P.Gamepad.sThumbRX) &&	// X��������
		(state_2P.Gamepad.sThumbRX <= -DEADZONE2_X) &&	// X�����܂�
		(-DEADZONE_MIN <= state_2P.Gamepad.sThumbRY) &&	// Y��������
		(state_2P.Gamepad.sThumbRY <= DEADZONE_MIN))	// Y�����܂�
	{
		return true;
	}

	// 292.5 ���k��
	if ((PushDirection == DIR::R292d5) &&
		(-DEADZONE_MAX <= state_2P.Gamepad.sThumbRX) &&	// X��������
		(state_2P.Gamepad.sThumbRX <= -DEADZONE2_X) &&	// X�����܂�
		(DEADZONE_MIN <= state_2P.Gamepad.sThumbRY) &&	// Y��������
		(state_2P.Gamepad.sThumbRY <= DEADZONE1_Y))		// Y�����܂�
	{
		return true;
	}

	// 315.0 �k��
	if ((PushDirection == DIR::UPPER_LEFT) &&
		(-DEADZONE2_X <= state_2P.Gamepad.sThumbRX) &&	// X��������
		(state_2P.Gamepad.sThumbRX <= -DEADZONE1_X) &&	// X�����܂�
		(DEADZONE1_Y <= state_2P.Gamepad.sThumbRY) &&	// Y��������	
		(state_2P.Gamepad.sThumbRY <= DEADZONE2_Y))		// Y�����܂�	
	{
		return true;
	}

	// 337.5 �k�k��
	if ((PushDirection == DIR::R337d5) &&
		(-DEADZONE1_X <= state_2P.Gamepad.sThumbRX) &&	// X��������
		(state_2P.Gamepad.sThumbRX <= -DEADZONE_MIN) &&	// X�����܂�
		(DEADZONE2_Y <= state_2P.Gamepad.sThumbRY) &&	// Y��������
		(state_2P.Gamepad.sThumbRY <= DEADZONE_MAX))	// Y�����܂�
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

	//   0.0 �k
	if ((PushDirection == DIR::UP) &&
		(-DEADZONE_MIN <= state_3P.Gamepad.sThumbRX) &&	// X��������
		(state_3P.Gamepad.sThumbRX <= DEADZONE_MIN) &&	// X�����܂�
		(DEADZONE2_Y <= state_3P.Gamepad.sThumbRY) &&	// Y��������
		(state_3P.Gamepad.sThumbRY <= DEADZONE_MAX))	// Y�����܂�
	{
		return true;
	}

	//  22.5 �k�k��
	if ((PushDirection == DIR::R22d5) &&
		(DEADZONE_MIN <= state_3P.Gamepad.sThumbRX) &&	// X��������
		(state_3P.Gamepad.sThumbRX <= DEADZONE1_X) &&	// X�����܂�
		(DEADZONE2_Y <= state_3P.Gamepad.sThumbRY) &&	// Y��������
		(state_3P.Gamepad.sThumbRY <= DEADZONE_MAX))	// Y�����܂�
	{
		return true;
	}

	//  45.0 �k��
	if ((PushDirection == DIR::UPPER_RIGHT) &&
		(DEADZONE1_X <= state_3P.Gamepad.sThumbRX) &&	// X��������
		(state_3P.Gamepad.sThumbRX <= DEADZONE2_X) &&	// X�����܂�
		(DEADZONE1_Y <= state_3P.Gamepad.sThumbRY) &&	// Y��������
		(state_3P.Gamepad.sThumbRY <= DEADZONE2_Y))		// Y�����܂�
	{
		return true;
	}

	//  67.5 ���k��
	if ((PushDirection == DIR::R67d5) &&
		(DEADZONE2_X <= state_3P.Gamepad.sThumbRX) &&	// X��������
		(state_3P.Gamepad.sThumbRX <= DEADZONE_MAX) &&	// X�����܂�
		(DEADZONE_MIN <= state_3P.Gamepad.sThumbRY) &&	// Y��������
		(state_3P.Gamepad.sThumbRY <= DEADZONE1_Y))		// Y�����܂�
	{
		return true;
	}

	//  90.0 ��
	if ((PushDirection == DIR::RIGHT) &&
		(DEADZONE2_X <= state_3P.Gamepad.sThumbRX) &&	// X��������
		(state_3P.Gamepad.sThumbRX <= DEADZONE_MAX) &&	// X�����܂�
		(-DEADZONE_MIN <= state_3P.Gamepad.sThumbRY) &&	// Y��������
		(state_3P.Gamepad.sThumbRY <= DEADZONE_MIN))	// Y�����܂�
	{
		return true;
	}

	// 112.5 ���쓌
	if ((PushDirection == DIR::R112d5) &&
		(DEADZONE2_X <= state_3P.Gamepad.sThumbRX) &&	// X��������
		(state_3P.Gamepad.sThumbRX <= DEADZONE_MAX) &&	// X�����܂�
		(-DEADZONE1_Y <= state_3P.Gamepad.sThumbRY) &&	// Y��������
		(state_3P.Gamepad.sThumbRY <= -DEADZONE_MIN))	// Y�����܂�
	{
		return true;
	}

	// 135.0 �쓌
	if ((PushDirection == DIR::LOWER_RIGHT) &&
		(DEADZONE1_X <= state_3P.Gamepad.sThumbRX) &&	// X��������
		(state_3P.Gamepad.sThumbRX <= DEADZONE2_X) &&	// X�����܂�
		(-DEADZONE2_Y <= state_3P.Gamepad.sThumbRY) &&	// Y��������
		(state_3P.Gamepad.sThumbRY <= -DEADZONE1_Y))	// Y�����܂�
	{
		return true;
	}

	// 157.5 ��쓌
	if ((PushDirection == DIR::R157d5) &&
		(DEADZONE_MIN <= state_3P.Gamepad.sThumbRX) &&	// X��������
		(state_3P.Gamepad.sThumbRX <= DEADZONE1_X) &&	// X�����܂�
		(-DEADZONE_MAX <= state_3P.Gamepad.sThumbRY) &&	// Y��������
		(state_3P.Gamepad.sThumbRY <= -DEADZONE2_Y))	// Y�����܂�
	{
		return true;
	}

	// 180.0 ��
	if ((PushDirection == DIR::DOWN) &&
		(-DEADZONE_MIN <= state_3P.Gamepad.sThumbRX) &&	// X��������
		(state_3P.Gamepad.sThumbRX <= DEADZONE_MIN) &&	// X�����܂�
		(-DEADZONE_MAX <= state_3P.Gamepad.sThumbRY) &&	// Y��������
		(state_3P.Gamepad.sThumbRY <= -DEADZONE2_Y))	// Y�����܂�
	{
		return true;
	}

	// 202.5 ��쐼
	if ((PushDirection == DIR::R202d5) &&
		(-DEADZONE1_X <= state_3P.Gamepad.sThumbRX) &&	// X��������
		(state_3P.Gamepad.sThumbRX <= -DEADZONE_MIN) &&	// X�����܂�
		(-DEADZONE_MAX <= state_3P.Gamepad.sThumbRY) &&	// Y��������
		(state_3P.Gamepad.sThumbRY <= -DEADZONE2_Y))	// Y�����܂�
	{
		return true;
	}

	// 225.0 �쐼
	if ((PushDirection == DIR::LOWER_LEFT) &&
		(-DEADZONE2_X <= state_3P.Gamepad.sThumbRX) &&	// X��������
		(state_3P.Gamepad.sThumbRX <= -DEADZONE1_X) &&	// X�����܂�
		(-DEADZONE2_Y <= state_3P.Gamepad.sThumbRY) &&	// Y��������
		(state_3P.Gamepad.sThumbRY <= -DEADZONE1_Y))	// Y�����܂�
	{
		return true;
	}

	// 247.5 ���쐼
	if ((PushDirection == DIR::R247d5) &&
		(-DEADZONE_MAX <= state_3P.Gamepad.sThumbRX) &&	// X��������
		(state_3P.Gamepad.sThumbRX <= -DEADZONE2_X) &&	// X�����܂�
		(-DEADZONE1_Y <= state_3P.Gamepad.sThumbRY) &&	// Y��������
		(state_3P.Gamepad.sThumbRY <= -DEADZONE_MIN))	// Y�����܂�
	{
		return true;
	}

	// 270.0 ��
	if ((PushDirection == DIR::LEFT) &&
		(-DEADZONE_MAX <= state_3P.Gamepad.sThumbRX) &&	// X��������
		(state_3P.Gamepad.sThumbRX <= -DEADZONE2_X) &&	// X�����܂�
		(-DEADZONE_MIN <= state_3P.Gamepad.sThumbRY) &&	// Y��������
		(state_3P.Gamepad.sThumbRY <= DEADZONE_MIN))	// Y�����܂�
	{
		return true;
	}

	// 292.5 ���k��
	if ((PushDirection == DIR::R292d5) &&
		(-DEADZONE_MAX <= state_3P.Gamepad.sThumbRX) &&	// X��������
		(state_3P.Gamepad.sThumbRX <= -DEADZONE2_X) &&	// X�����܂�
		(DEADZONE_MIN <= state_3P.Gamepad.sThumbRY) &&	// Y��������
		(state_3P.Gamepad.sThumbRY <= DEADZONE1_Y))		// Y�����܂�
	{
		return true;
	}

	// 315.0 �k��
	if ((PushDirection == DIR::UPPER_LEFT) &&
		(-DEADZONE2_X <= state_3P.Gamepad.sThumbRX) &&	// X��������
		(state_3P.Gamepad.sThumbRX <= -DEADZONE1_X) &&	// X�����܂�
		(DEADZONE1_Y <= state_3P.Gamepad.sThumbRY) &&	// Y��������	
		(state_3P.Gamepad.sThumbRY <= DEADZONE2_Y))		// Y�����܂�	
	{
		return true;
	}

	// 337.5 �k�k��
	if ((PushDirection == DIR::R337d5) &&
		(-DEADZONE1_X <= state_3P.Gamepad.sThumbRX) &&	// X��������
		(state_3P.Gamepad.sThumbRX <= -DEADZONE_MIN) &&	// X�����܂�
		(DEADZONE2_Y <= state_3P.Gamepad.sThumbRY) &&	// Y��������
		(state_3P.Gamepad.sThumbRY <= DEADZONE_MAX))	// Y�����܂�
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

	//   0.0 �k
	if ((PushDirection == DIR::UP) &&
		(-DEADZONE_MIN <= state_4P.Gamepad.sThumbRX) &&	// X��������
		(state_4P.Gamepad.sThumbRX <= DEADZONE_MIN) &&	// X�����܂�
		(DEADZONE2_Y <= state_4P.Gamepad.sThumbRY) &&	// Y��������
		(state_4P.Gamepad.sThumbRY <= DEADZONE_MAX))	// Y�����܂�
	{
		return true;
	}

	//  22.5 �k�k��
	if ((PushDirection == DIR::R22d5) &&
		(DEADZONE_MIN <= state_4P.Gamepad.sThumbRX) &&	// X��������
		(state_4P.Gamepad.sThumbRX <= DEADZONE1_X) &&	// X�����܂�
		(DEADZONE2_Y <= state_4P.Gamepad.sThumbRY) &&	// Y��������
		(state_4P.Gamepad.sThumbRY <= DEADZONE_MAX))	// Y�����܂�
	{
		return true;
	}

	//  45.0 �k��
	if ((PushDirection == DIR::UPPER_RIGHT) &&
		(DEADZONE1_X <= state_4P.Gamepad.sThumbRX) &&	// X��������
		(state_4P.Gamepad.sThumbRX <= DEADZONE2_X) &&	// X�����܂�
		(DEADZONE1_Y <= state_4P.Gamepad.sThumbRY) &&	// Y��������
		(state_4P.Gamepad.sThumbRY <= DEADZONE2_Y))		// Y�����܂�
	{
		return true;
	}

	//  67.5 ���k��
	if ((PushDirection == DIR::R67d5) &&
		(DEADZONE2_X <= state_4P.Gamepad.sThumbRX) &&	// X��������
		(state_4P.Gamepad.sThumbRX <= DEADZONE_MAX) &&	// X�����܂�
		(DEADZONE_MIN <= state_4P.Gamepad.sThumbRY) &&	// Y��������
		(state_4P.Gamepad.sThumbRY <= DEADZONE1_Y))		// Y�����܂�
	{
		return true;
	}

	//  90.0 ��
	if ((PushDirection == DIR::RIGHT) &&
		(DEADZONE2_X <= state_4P.Gamepad.sThumbRX) &&	// X��������
		(state_4P.Gamepad.sThumbRX <= DEADZONE_MAX) &&	// X�����܂�
		(-DEADZONE_MIN <= state_4P.Gamepad.sThumbRY) &&	// Y��������
		(state_4P.Gamepad.sThumbRY <= DEADZONE_MIN))	// Y�����܂�
	{
		return true;
	}

	// 112.5 ���쓌
	if ((PushDirection == DIR::R112d5) &&
		(DEADZONE2_X <= state_4P.Gamepad.sThumbRX) &&	// X��������
		(state_4P.Gamepad.sThumbRX <= DEADZONE_MAX) &&	// X�����܂�
		(-DEADZONE1_Y <= state_4P.Gamepad.sThumbRY) &&	// Y��������
		(state_4P.Gamepad.sThumbRY <= -DEADZONE_MIN))	// Y�����܂�
	{
		return true;
	}

	// 135.0 �쓌
	if ((PushDirection == DIR::LOWER_RIGHT) &&
		(DEADZONE1_X <= state_4P.Gamepad.sThumbRX) &&	// X��������
		(state_4P.Gamepad.sThumbRX <= DEADZONE2_X) &&	// X�����܂�
		(-DEADZONE2_Y <= state_4P.Gamepad.sThumbRY) &&	// Y��������
		(state_4P.Gamepad.sThumbRY <= -DEADZONE1_Y))	// Y�����܂�
	{
		return true;
	}

	// 157.5 ��쓌
	if ((PushDirection == DIR::R157d5) &&
		(DEADZONE_MIN <= state_4P.Gamepad.sThumbRX) &&	// X��������
		(state_4P.Gamepad.sThumbRX <= DEADZONE1_X) &&	// X�����܂�
		(-DEADZONE_MAX <= state_4P.Gamepad.sThumbRY) &&	// Y��������
		(state_4P.Gamepad.sThumbRY <= -DEADZONE2_Y))	// Y�����܂�
	{
		return true;
	}

	// 180.0 ��
	if ((PushDirection == DIR::DOWN) &&
		(-DEADZONE_MIN <= state_4P.Gamepad.sThumbRX) &&	// X��������
		(state_4P.Gamepad.sThumbRX <= DEADZONE_MIN) &&	// X�����܂�
		(-DEADZONE_MAX <= state_4P.Gamepad.sThumbRY) &&	// Y��������
		(state_4P.Gamepad.sThumbRY <= -DEADZONE2_Y))	// Y�����܂�
	{
		return true;
	}

	// 202.5 ��쐼
	if ((PushDirection == DIR::R202d5) &&
		(-DEADZONE1_X <= state_4P.Gamepad.sThumbRX) &&	// X��������
		(state_4P.Gamepad.sThumbRX <= -DEADZONE_MIN) &&	// X�����܂�
		(-DEADZONE_MAX <= state_4P.Gamepad.sThumbRY) &&	// Y��������
		(state_4P.Gamepad.sThumbRY <= -DEADZONE2_Y))	// Y�����܂�
	{
		return true;
	}

	// 225.0 �쐼
	if ((PushDirection == DIR::LOWER_LEFT) &&
		(-DEADZONE2_X <= state_4P.Gamepad.sThumbRX) &&	// X��������
		(state_4P.Gamepad.sThumbRX <= -DEADZONE1_X) &&	// X�����܂�
		(-DEADZONE2_Y <= state_4P.Gamepad.sThumbRY) &&	// Y��������
		(state_4P.Gamepad.sThumbRY <= -DEADZONE1_Y))	// Y�����܂�
	{
		return true;
	}

	// 247.5 ���쐼
	if ((PushDirection == DIR::R247d5) &&
		(-DEADZONE_MAX <= state_4P.Gamepad.sThumbRX) &&	// X��������
		(state_4P.Gamepad.sThumbRX <= -DEADZONE2_X) &&	// X�����܂�
		(-DEADZONE1_Y <= state_4P.Gamepad.sThumbRY) &&	// Y��������
		(state_4P.Gamepad.sThumbRY <= -DEADZONE_MIN))	// Y�����܂�
	{
		return true;
	}

	// 270.0 ��
	if ((PushDirection == DIR::LEFT) &&
		(-DEADZONE_MAX <= state_4P.Gamepad.sThumbRX) &&	// X��������
		(state_4P.Gamepad.sThumbRX <= -DEADZONE2_X) &&	// X�����܂�
		(-DEADZONE_MIN <= state_4P.Gamepad.sThumbRY) &&	// Y��������
		(state_4P.Gamepad.sThumbRY <= DEADZONE_MIN))	// Y�����܂�
	{
		return true;
	}

	// 292.5 ���k��
	if ((PushDirection == DIR::R292d5) &&
		(-DEADZONE_MAX <= state_4P.Gamepad.sThumbRX) &&	// X��������
		(state_4P.Gamepad.sThumbRX <= -DEADZONE2_X) &&	// X�����܂�
		(DEADZONE_MIN <= state_4P.Gamepad.sThumbRY) &&	// Y��������
		(state_4P.Gamepad.sThumbRY <= DEADZONE1_Y))		// Y�����܂�
	{
		return true;
	}

	// 315.0 �k��
	if ((PushDirection == DIR::UPPER_LEFT) &&
		(-DEADZONE2_X <= state_4P.Gamepad.sThumbRX) &&	// X��������
		(state_4P.Gamepad.sThumbRX <= -DEADZONE1_X) &&	// X�����܂�
		(DEADZONE1_Y <= state_4P.Gamepad.sThumbRY) &&	// Y��������	
		(state_4P.Gamepad.sThumbRY <= DEADZONE2_Y))		// Y�����܂�	
	{
		return true;
	}

	// 337.5 �k�k��
	if ((PushDirection == DIR::R337d5) &&
		(-DEADZONE1_X <= state_4P.Gamepad.sThumbRX) &&	// X��������
		(state_4P.Gamepad.sThumbRX <= -DEADZONE_MIN) &&	// X�����܂�
		(DEADZONE2_Y <= state_4P.Gamepad.sThumbRY) &&	// Y��������
		(state_4P.Gamepad.sThumbRY <= DEADZONE_MAX))	// Y�����܂�
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
	gKeys[VK_LSHIFT] = GetAsyncKeyState(VK_LSHIFT);		//��SHIFT�L�[
	gKeys['W'] = GetAsyncKeyState('W');					//W
	gKeys['A'] = GetAsyncKeyState('A');					//A
	gKeys['S'] = GetAsyncKeyState('S');					//S
	gKeys['D'] = GetAsyncKeyState('D');					//D
	gKeys['O'] = GetAsyncKeyState('O');
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
	case UP:
		if (Input_GetKeyPress('W') || Input_GetKeyPress(VK_UP) || LeftStick8_1P(UP))
			result = true;
		break;
	case RIGHT:
		if (Input_GetKeyPress('D') || Input_GetKeyPress(VK_RIGHT) || LeftStick8_1P(RIGHT))
			result = true;
		break;
	case DOWN:
		if (Input_GetKeyPress('S') || Input_GetKeyPress(VK_DOWN) || LeftStick8_1P(DOWN))
			result = true;
		break;
	case LEFT:
		if (Input_GetKeyPress('A') || Input_GetKeyPress(VK_LEFT) || LeftStick8_1P(LEFT))
			result = true;
		break;
	case UPPER_RIGHT:
		if ((Input_GetKeyPress('W') && Input_GetKeyPress('D')) || (Input_GetKeyPress(VK_UP) && Input_GetKeyPress(VK_RIGHT)) || LeftStick8_1P(UPPER_RIGHT))
			result = true;
		break;
	case LOWER_LEFT:
		if ((Input_GetKeyPress('S') && Input_GetKeyPress('A')) || (Input_GetKeyPress(VK_DOWN) && Input_GetKeyPress(VK_LEFT)) || LeftStick8_1P(LOWER_LEFT))
			result = true;
		break;
	case LOWER_RIGHT:
		if ((Input_GetKeyPress('S') && Input_GetKeyPress('D')) || (Input_GetKeyPress(VK_DOWN) && Input_GetKeyPress(VK_RIGHT)) || LeftStick8_1P(LOWER_RIGHT))
			result = true;
		break;
	case UPPER_LEFT:
		if ((Input_GetKeyPress('W') && Input_GetKeyPress('A')) || (Input_GetKeyPress(VK_UP) && Input_GetKeyPress(VK_LEFT)) || LeftStick8_1P(UPPER_LEFT))
			result = true;
		break;
	case R22d5:
		if (LeftStick8_1P(R22d5))
			result = true;

	}

	return result;
}

bool Input::GetAxisShort(DIR direction)
{
	bool result = false;

	switch (direction)
	{
	case UP:
		if (Input_GetKeyTrigger('W') || Input_GetKeyTrigger(VK_UP) || LeftStick8_1P(UP))
			result = true;
		break;
	case RIGHT:
		if (Input_GetKeyTrigger('D') || Input_GetKeyTrigger(VK_RIGHT) || LeftStick8_1P(RIGHT))
			result = true;
		break;
	case DOWN:
		if (Input_GetKeyTrigger('S') || Input_GetKeyTrigger(VK_DOWN) || LeftStick8_1P(DOWN))
			result = true;
		break;
	case LEFT:
		if (Input_GetKeyTrigger('A') || Input_GetKeyTrigger(VK_LEFT) || LeftStick8_1P(LEFT))
			result = true;
		break;
	case UPPER_RIGHT:
		if ((Input_GetKeyTrigger('W') && Input_GetKeyTrigger('D')) || (Input_GetKeyTrigger(VK_UP) && Input_GetKeyTrigger(VK_RIGHT)) || LeftStick8_1P(UPPER_RIGHT))
			result = true;
		break;
	case LOWER_LEFT:
		if ((Input_GetKeyTrigger('S') && Input_GetKeyTrigger('A')) || (Input_GetKeyTrigger(VK_DOWN) && Input_GetKeyTrigger(VK_LEFT)) || LeftStick8_1P(LOWER_LEFT))
			result = true;
		break;
	case LOWER_RIGHT:
		if ((Input_GetKeyTrigger('S') && Input_GetKeyTrigger('D')) || (Input_GetKeyTrigger(VK_DOWN) && Input_GetKeyTrigger(VK_RIGHT)) || LeftStick8_1P(LOWER_RIGHT))
			result = true;
		break;
	case UPPER_LEFT:
		if ((Input_GetKeyTrigger('W') && Input_GetKeyTrigger('A')) || (Input_GetKeyTrigger(VK_UP) && Input_GetKeyTrigger(VK_LEFT)) || LeftStick8_1P(UPPER_LEFT))
			result = true;
		break;
	}

	return result;
}

bool Input::isInput()
{
	bool result = false;

	if (GetAxis(LEFT) || GetAxis(RIGHT) || GetAxis(UP) || GetAxis(DOWN) || GetAxis(UPPER_RIGHT) || 
		GetAxis(LOWER_LEFT) || GetAxis(LOWER_RIGHT) || GetAxis(UPPER_LEFT) || GetAxisShort(LEFT) || GetAxisShort(RIGHT) ||
		GetAxisShort(UP) || GetAxisShort(DOWN) || GetAxisShort(UPPER_RIGHT) || GetAxisShort(LOWER_LEFT) || 
		GetAxisShort(LOWER_RIGHT) || GetAxisShort(UPPER_LEFT))
		result = true;
	else
		result = false;

	return result;
}

bool Input::GetButtonPress(ACTION action)
{
	bool result = false;

	switch (action)
	{
	case OK:
		if (ShortPushButton_1P(GP_A) || Input_GetKeyTrigger(VK_RETURN))
			result = true;
		break;
	case BACK:
		if (ShortPushButton_1P(GP_B) || Input_GetKeyTrigger(VK_SPACE))
			result = true;
		break;
	case RESTART:
		if (ShortPushButton_1P(GP_BACK) || Input_GetKeyTrigger(VK_F1))
			result = true;
		break;
	case BREAKCIRCLE:
		if (LongPushButton_1P(GP_RS) || Input_GetKeyPress(VK_LBUTTON))
			result = true;
		break;
	case HOMINGOFF:
		if (LongPushButton_1P(GP_LS) || Input_GetKeyPress(VK_RBUTTON))
			result = true;
		break;
	}

	return result;
}