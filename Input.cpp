#include "Input.h"

#define MAX_KEYS 256

static short gOldKeys[MAX_KEYS];
static short gKeys[MAX_KEYS];

// ゲームパッドの状態を取得
XINPUT_STATE state_1P;		// 1P
XINPUT_STATE state_2P;		// 2P
XINPUT_STATE state_3P;		// 3P
XINPUT_STATE state_4P;		// 4P

// ゲームパッドの振動
XINPUT_VIBRATION vibration_1P;	// 1P
XINPUT_VIBRATION vibration_2P;	// 2P
XINPUT_VIBRATION vibration_3P;	// 3P
XINPUT_VIBRATION vibration_4P;	// 4P



//------------------------------------------------------------
// ボタンを長押しで使用する際の関数
//
// int PushButton に GP_A を入れると Aボタン が使用できる
//------------------------------------------------------------
// 1Pコントローラー
bool Input::LongPushButton_1P(int PushButton)
{

	// 入力の取得
	XInputGetState(0, &state_1P);

	// ボタン 【判定処理】
	if (state_1P.Gamepad.wButtons & PushButton)
	{
		return true;
	}

	// 判定無し
	else
	{
		return false;
	}
}

// 2Pコントローラー
bool Input::LongPushButton_2P(int PushButton)
{

	// 入力の取得
	XInputGetState(1, &state_2P);

	// ボタン 【判定処理】
	if (state_2P.Gamepad.wButtons & PushButton)
	{
		return true;
	}

	// 判定無し
	else
	{
		return false;
	}
}

// 3Pコントローラー
bool Input::LongPushButton_3P(int PushButton)
{

	// 入力の取得
	XInputGetState(2, &state_3P);

	// ボタン 【判定処理】
	if (state_3P.Gamepad.wButtons & PushButton)
	{
		return true;
	}

	// 判定無し
	else
	{
		return false;
	}
}

// 4Pコントローラー
bool Input::LongPushButton_4P(int PushButton)
{

	// 入力の取得
	XInputGetState(3, &state_4P);

	// ボタン 【判定処理】
	if (state_4P.Gamepad.wButtons & PushButton)
	{
		return true;
	}

	// 判定無し
	else
	{
		return false;
	}
}



//------------------------------------------------------------
// ボタンを短押しで使用する際の関数
//
// int PushButton に GP_A を入れると Aボタン が使用できる
//------------------------------------------------------------
// 1Pコントローラー
bool Input::ShortPushButton_1P(int PushButton)
{

	// 入力の取得
	XInputGetState(0, &state_1P);

	// ボタン 【判定処理】
	if (state_1P.Gamepad.wButtons & PushButton)
	{
		while (state_1P.Gamepad.wButtons & PushButton)
		{
			// 入力の取得
			XInputGetState(0, &state_1P);

			if (!(state_1P.Gamepad.wButtons & PushButton))
			{
				return true;
			}
		}
	}

	// 判定無し
	else
	{
		return false;
	}
}

// 2Pコントローラー
bool Input::ShortPushButton_2P(int PushButton)
{

	// 入力の取得
	XInputGetState(1, &state_2P);

	// ボタン 【判定処理】
	if (state_2P.Gamepad.wButtons & PushButton)
	{
		while (state_2P.Gamepad.wButtons & PushButton)
		{
			// 入力の取得
			XInputGetState(1, &state_2P);

			if (!(state_2P.Gamepad.wButtons & PushButton))
			{
				return true;
			}
		}
	}

	// 判定無し
	else
	{
		return false;
	}
}

// 3Pコントローラー
bool Input::ShortPushButton_3P(int PushButton)
{

	// 入力の取得
	XInputGetState(2, &state_3P);

	// ボタン 【判定処理】
	if (state_3P.Gamepad.wButtons & PushButton)
	{
		while (state_3P.Gamepad.wButtons & PushButton)
		{
			// 入力の取得
			XInputGetState(2, &state_3P);

			if (!(state_3P.Gamepad.wButtons & PushButton))
			{
				return true;
			}
		}
	}

	// 判定無し
	else
	{
		return false;
	}
}

// 4Pコントローラー
bool Input::ShortPushButton_4P(int PushButton)
{

	// 入力の取得
	XInputGetState(3, &state_4P);

	// ボタン 【判定処理】
	if (state_4P.Gamepad.wButtons & PushButton)
	{
		while (state_4P.Gamepad.wButtons & PushButton)
		{
			// 入力の取得
			XInputGetState(3, &state_4P);

			if (!(state_4P.Gamepad.wButtons & PushButton))
			{
				return true;
			}
		}
	}

	// 判定無し
	else
	{
		return false;
	}
}



//------------------------------------------------------------
// 左トリガーを使用する際の関数
//
// int PushLevel に 数値 を入れると 奥行具合 が調整できる
//------------------------------------------------------------
// 1Pコントローラー
bool Input::LeftTrigger_1P(int PushLevel)
{

	// 入力の取得
	XInputGetState(0, &state_1P);

	// 右トリガー 【判定処理】
	if (state_1P.Gamepad.bLeftTrigger >= XINPUT_GAMEPAD_TRIGGER_THRESHOLD * PushLevel)
	{
		return true;
	}

	// 判定無し
	else
	{
		return false;
	}
}

// 2Pコントローラー
bool Input::LeftTrigger_2P(int PushLevel)
{

	// 入力の取得
	XInputGetState(1, &state_2P);

	// 右トリガー 【判定処理】
	if (state_2P.Gamepad.bLeftTrigger >= XINPUT_GAMEPAD_TRIGGER_THRESHOLD * PushLevel)
	{
		return true;
	}

	// 判定無し
	else
	{
		return false;
	}
}

// 3Pコントローラー
bool Input::LeftTrigger_3P(int PushLevel)
{

	// 入力の取得
	XInputGetState(2, &state_3P);

	// 右トリガー 【判定処理】
	if (state_3P.Gamepad.bLeftTrigger >= XINPUT_GAMEPAD_TRIGGER_THRESHOLD * PushLevel)
	{
		return true;
	}

	// 判定無し
	else
	{
		return false;
	}
}

// 4Pコントローラー
bool Input::LeftTrigger_4P(int PushLevel)
{

	// 入力の取得
	XInputGetState(3, &state_4P);

	// 右トリガー 【判定処理】
	if (state_4P.Gamepad.bLeftTrigger >= XINPUT_GAMEPAD_TRIGGER_THRESHOLD * PushLevel)
	{
		return true;
	}

	// 判定無し
	else
	{
		return false;
	}
}



//------------------------------------------------------------
// 右トリガーを使用する際の関数
//
// int PushLevel に 数値 を入れると 奥行具合 が調整できる
//------------------------------------------------------------
// 1Pコントローラー
bool Input::RightTrigger_1P(int PushLevel)
{

	// 入力の取得
	XInputGetState(0, &state_1P);

	// 左トリガー 【判定処理】
	if (state_1P.Gamepad.bRightTrigger >= XINPUT_GAMEPAD_TRIGGER_THRESHOLD * PushLevel)
	{
		return true;
	}

	// 判定無し
	else
	{
		return false;
	}
}

// 2Pコントローラー
bool Input::RightTrigger_2P(int PushLevel)
{

	// 入力の取得
	XInputGetState(1, &state_2P);

	// 左トリガー 【判定処理】
	if (state_2P.Gamepad.bRightTrigger >= XINPUT_GAMEPAD_TRIGGER_THRESHOLD * PushLevel)
	{
		return true;
	}

	// 判定無し
	else
	{
		return false;
	}
}

// 3Pコントローラー
bool Input::RightTrigger_3P(int PushLevel)
{

	// 入力の取得
	XInputGetState(2, &state_3P);

	// 左トリガー 【判定処理】
	if (state_3P.Gamepad.bRightTrigger >= XINPUT_GAMEPAD_TRIGGER_THRESHOLD * PushLevel)
	{
		return true;
	}

	// 判定無し
	else
	{
		return false;
	}
}

// 4Pコントローラー
bool Input::RightTrigger_4P(int PushLevel)
{

	// 入力の取得
	XInputGetState(3, &state_4P);

	// 左トリガー 【判定処理】
	if (state_4P.Gamepad.bRightTrigger >= XINPUT_GAMEPAD_TRIGGER_THRESHOLD * PushLevel)
	{
		return true;
	}

	// 判定無し
	else
	{
		return false;
	}
}



//------------------------------------------------------------
// 左スティックを使用する際の関数
//
// int PushDirection に DIR::〇〇 を入れると 方向指定 が設定できる
//------------------------------------------------------------
// 1Pコントローラー
bool Input::LeftStick8_1P(int PushDirection)
{

	// 入力の取得
	XInputGetState(0, &state_1P);

	//------------------------------------------------------------
	// 左スティックのデッドゾーン処理
	//------------------------------------------------------------
	if ((state_1P.Gamepad.sThumbLX < XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE && state_1P.Gamepad.sThumbLX > -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE) &&
		(state_1P.Gamepad.sThumbLY < XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE && state_1P.Gamepad.sThumbLY > -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE))
	{
		state_1P.Gamepad.sThumbLX = 0;
		state_1P.Gamepad.sThumbLY = 0;
	}

	// 左方向 【判定処理】
	if ((PushDirection == DIR::LEFT) && (state_1P.Gamepad.sThumbLX <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE * DEADZONE_LX))
	{
		return true;
	}

	// 右方向 【判定処理】
	if ((PushDirection == DIR::RIGHT) && (state_1P.Gamepad.sThumbLX >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE * DEADZONE_LX))
	{
		return true;
	}

	// 上方向 【判定処理】
	if ((PushDirection == DIR::UP) && (state_1P.Gamepad.sThumbLY >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE * DEADZONE_LY))
	{
		return true;
	}

	// 下方向 【判定処理】
	if ((PushDirection == DIR::DOWN) && (state_1P.Gamepad.sThumbLY <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE * DEADZONE_LY))
	{
		return true;
	}

	// 左上方向 【判定処理】
	if ((PushDirection == DIR::UPPER_LEFT) && (state_1P.Gamepad.sThumbLX <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
		&& (state_1P.Gamepad.sThumbLY >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE))
	{
		return true;
	}

	// 右上方向 【判定処理】
	if ((PushDirection == DIR::UPPER_RIGHT) && (state_1P.Gamepad.sThumbLX >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
		&& (state_1P.Gamepad.sThumbLY >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE))
	{
		return true;
	}

	// 左下方向 【判定処理】
	if ((PushDirection == DIR::LOWER_LEFT) && (state_1P.Gamepad.sThumbLX <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
		&& (state_1P.Gamepad.sThumbLY <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE))
	{
		return true;
	}

	// 右下方向 【判定処理】
	if ((PushDirection == DIR::LOWER_RIGHT) && (state_1P.Gamepad.sThumbLX >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
		&& (state_1P.Gamepad.sThumbLY <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE))
	{
		return true;
	}

	// 判定無し
	else
	{
		return false;
	}
}

// 2Pコントローラー
bool Input::LeftStick8_2P(int PushDirection)
{

	// 入力の取得
	XInputGetState(1, &state_2P);

	//------------------------------------------------------------
	// 左スティックのデッドゾーン処理
	//------------------------------------------------------------
	if ((state_2P.Gamepad.sThumbLX < XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE && state_2P.Gamepad.sThumbLX > -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE) &&
		(state_2P.Gamepad.sThumbLY < XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE && state_2P.Gamepad.sThumbLY > -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE))
	{
		state_2P.Gamepad.sThumbLX = 0;
		state_2P.Gamepad.sThumbLY = 0;
	}

	// 左方向 【判定処理】
	if ((PushDirection == DIR::LEFT) && (state_2P.Gamepad.sThumbLX <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE * DEADZONE_LX))
	{
		return true;
	}

	// 右方向 【判定処理】
	if ((PushDirection == DIR::RIGHT) && (state_2P.Gamepad.sThumbLX >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE * DEADZONE_LX))
	{
		return true;
	}

	// 上方向 【判定処理】
	if ((PushDirection == DIR::UP) && (state_2P.Gamepad.sThumbLY >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE * DEADZONE_LY))
	{
		return true;
	}

	// 下方向 【判定処理】
	if ((PushDirection == DIR::DOWN) && (state_2P.Gamepad.sThumbLY <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE * DEADZONE_LY))
	{
		return true;
	}

	// 左上方向 【判定処理】
	if ((PushDirection == DIR::UPPER_LEFT) && (state_2P.Gamepad.sThumbLX <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
		&& (state_2P.Gamepad.sThumbLY >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE))
	{
		return true;
	}

	// 右上方向 【判定処理】
	if ((PushDirection == DIR::UPPER_RIGHT) && (state_2P.Gamepad.sThumbLX >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
		&& (state_2P.Gamepad.sThumbLY >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE))
	{
		return true;
	}

	// 左下方向 【判定処理】
	if ((PushDirection == DIR::LOWER_LEFT) && (state_2P.Gamepad.sThumbLX <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
		&& (state_2P.Gamepad.sThumbLY <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE))
	{
		return true;
	}

	// 右下方向 【判定処理】
	if ((PushDirection == DIR::LOWER_RIGHT) && (state_2P.Gamepad.sThumbLX >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
		&& (state_2P.Gamepad.sThumbLY <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE))
	{
		return true;
	}

	// 判定無し
	else
	{
		return false;
	}
}

// 3Pコントローラー
bool Input::LeftStick8_3P(int PushDirection)
{

	// 入力の取得
	XInputGetState(2, &state_3P);

	//------------------------------------------------------------
	// 左スティックのデッドゾーン処理
	//------------------------------------------------------------
	if ((state_3P.Gamepad.sThumbLX < XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE && state_3P.Gamepad.sThumbLX > -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE) &&
		(state_3P.Gamepad.sThumbLY < XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE && state_3P.Gamepad.sThumbLY > -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE))
	{
		state_3P.Gamepad.sThumbLX = 0;
		state_3P.Gamepad.sThumbLY = 0;
	}

	// 左方向 【判定処理】
	if ((PushDirection == DIR::LEFT) && (state_3P.Gamepad.sThumbLX <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE * DEADZONE_LX))
	{
		return true;
	}

	// 右方向 【判定処理】
	if ((PushDirection == DIR::RIGHT) && (state_3P.Gamepad.sThumbLX >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE * DEADZONE_LX))
	{
		return true;
	}

	// 上方向 【判定処理】
	if ((PushDirection == DIR::UP) && (state_3P.Gamepad.sThumbLY >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE * DEADZONE_LY))
	{
		return true;
	}

	// 下方向 【判定処理】
	if ((PushDirection == DIR::DOWN) && (state_3P.Gamepad.sThumbLY <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE * DEADZONE_LY))
	{
		return true;
	}

	// 左上方向 【判定処理】
	if ((PushDirection == DIR::UPPER_LEFT) && (state_3P.Gamepad.sThumbLX <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
		&& (state_3P.Gamepad.sThumbLY >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE))
	{
		return true;
	}

	// 右上方向 【判定処理】
	if ((PushDirection == DIR::UPPER_RIGHT) && (state_3P.Gamepad.sThumbLX >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
		&& (state_3P.Gamepad.sThumbLY >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE))
	{
		return true;
	}

	// 左下方向 【判定処理】
	if ((PushDirection == DIR::LOWER_LEFT) && (state_3P.Gamepad.sThumbLX <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
		&& (state_3P.Gamepad.sThumbLY <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE))
	{
		return true;
	}

	// 右下方向 【判定処理】
	if ((PushDirection == DIR::LOWER_RIGHT) && (state_3P.Gamepad.sThumbLX >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
		&& (state_3P.Gamepad.sThumbLY <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE))
	{
		return true;
	}

	// 判定無し
	else
	{
		return false;
	}
}

// 4Pコントローラー
bool Input::LeftStick8_4P(int PushDirection)
{

	// 入力の取得
	XInputGetState(3, &state_4P);

	//------------------------------------------------------------
	// 左スティックのデッドゾーン処理
	//------------------------------------------------------------
	if ((state_4P.Gamepad.sThumbLX < XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE && state_4P.Gamepad.sThumbLX > -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE) &&
		(state_4P.Gamepad.sThumbLY < XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE && state_4P.Gamepad.sThumbLY > -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE))
	{
		state_4P.Gamepad.sThumbLX = 0;
		state_4P.Gamepad.sThumbLY = 0;
	}

	// 左方向 【判定処理】
	if ((PushDirection == DIR::LEFT) && (state_4P.Gamepad.sThumbLX <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE * DEADZONE_LX))
	{
		return true;
	}

	// 右方向 【判定処理】
	if ((PushDirection == DIR::RIGHT) && (state_4P.Gamepad.sThumbLX >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE * DEADZONE_LX))
	{
		return true;
	}

	// 上方向 【判定処理】
	if ((PushDirection == DIR::UP) && (state_4P.Gamepad.sThumbLY >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE * DEADZONE_LY))
	{
		return true;
	}

	// 下方向 【判定処理】
	if ((PushDirection == DIR::DOWN) && (state_4P.Gamepad.sThumbLY <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE * DEADZONE_LY))
	{
		return true;
	}

	// 左上方向 【判定処理】
	if ((PushDirection == DIR::UPPER_LEFT) && (state_4P.Gamepad.sThumbLX <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE * DEADZONE_LX)
		&& (state_4P.Gamepad.sThumbLY >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE * DEADZONE_LY))
	{
		return true;
	}

	// 右上方向 【判定処理】
	if ((PushDirection == DIR::UPPER_RIGHT) && (state_4P.Gamepad.sThumbLX >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE * DEADZONE_LX)
		&& (state_4P.Gamepad.sThumbLY >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE * DEADZONE_LY))
	{
		return true;
	}

	// 左下方向 【判定処理】
	if ((PushDirection == DIR::LOWER_LEFT) && (state_4P.Gamepad.sThumbLX <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE * DEADZONE_LX)
		&& (state_4P.Gamepad.sThumbLY <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE * DEADZONE_LY))
	{
		return true;
	}

	// 右下方向 【判定処理】
	if ((PushDirection == DIR::LOWER_RIGHT) && (state_4P.Gamepad.sThumbLX >= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE * DEADZONE_LX)
		&& (state_4P.Gamepad.sThumbLY <= -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE * DEADZONE_LY))
	{
		return true;
	}

	// 判定無し
	else
	{
		return false;
	}
}



//------------------------------------------------------------
// 右スティックを使用する際の関数
//
// int PushDirection に DIR::〇〇 を入れると 方向指定 が設定できる
//------------------------------------------------------------
// 1Pコントローラー
bool Input::RightStick8_1P(int PushDirection)
{

	// 入力の取得
	XInputGetState(0, &state_1P);

	//------------------------------------------------------------
	// 右スティックのデッドゾーン処理
	//------------------------------------------------------------
	if ((state_1P.Gamepad.sThumbRX < XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE && state_1P.Gamepad.sThumbRX > -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE) &&
		(state_1P.Gamepad.sThumbRY < XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE && state_1P.Gamepad.sThumbRY > -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE))
	{
		state_1P.Gamepad.sThumbRX = 0;
		state_1P.Gamepad.sThumbRY = 0;
	}

	// 左方向 【判定処理】
	if ((PushDirection == DIR::LEFT) && (state_1P.Gamepad.sThumbRX <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE * DEADZONE_RX))
	{
		return true;
	}

	// 右方向 【判定処理】
	if ((PushDirection == DIR::RIGHT) && (state_1P.Gamepad.sThumbRX >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE * DEADZONE_RX))
	{
		return true;
	}

	// 上方向 【判定処理】
	if ((PushDirection == DIR::UP) && (state_1P.Gamepad.sThumbRY >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE * DEADZONE_RY))
	{
		return true;
	}

	// 下方向 【判定処理】
	if ((PushDirection == DIR::DOWN) && (state_1P.Gamepad.sThumbRY <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE * DEADZONE_RY))
	{
		return true;
	}

	// 左上方向 【判定処理】
	if ((PushDirection == DIR::UPPER_LEFT) && (state_1P.Gamepad.sThumbRX <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE)
		&& (state_1P.Gamepad.sThumbRY >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE))
	{
		return true;
	}

	// 右上方向 【判定処理】
	if ((PushDirection == DIR::UPPER_RIGHT) && (state_1P.Gamepad.sThumbRX >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE)
		&& (state_1P.Gamepad.sThumbRY >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE))
	{
		return true;
	}

	// 左下方向 【判定処理】
	if ((PushDirection == DIR::LOWER_LEFT) && (state_1P.Gamepad.sThumbRX <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE)
		&& (state_1P.Gamepad.sThumbRY <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE))
	{
		return true;
	}

	// 右下方向 【判定処理】
	if ((PushDirection == DIR::LOWER_RIGHT) && (state_1P.Gamepad.sThumbRX >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE)
		&& (state_1P.Gamepad.sThumbRY <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE))
	{
		return true;
	}

	// 判定無し
	else
	{
		return false;
	}
}

// 2Pコントローラー
bool Input::RightStick8_2P(int PushDirection)
{

	// 入力の取得
	XInputGetState(1, &state_2P);

	//------------------------------------------------------------
	// 右スティックのデッドゾーン処理
	//------------------------------------------------------------
	if ((state_2P.Gamepad.sThumbRX < XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE && state_2P.Gamepad.sThumbRX > -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE) &&
		(state_2P.Gamepad.sThumbRY < XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE && state_2P.Gamepad.sThumbRY > -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE))
	{
		state_2P.Gamepad.sThumbRX = 0;
		state_2P.Gamepad.sThumbRY = 0;
	}

	// 左方向 【判定処理】
	if ((PushDirection == DIR::LEFT) && (state_2P.Gamepad.sThumbRX <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE * DEADZONE_RX))
	{
		return true;
	}

	// 右方向 【判定処理】
	if ((PushDirection == DIR::RIGHT) && (state_2P.Gamepad.sThumbRX >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE * DEADZONE_RX))
	{
		return true;
	}

	// 上方向 【判定処理】
	if ((PushDirection == DIR::UP) && (state_2P.Gamepad.sThumbRY >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE * DEADZONE_RY))
	{
		return true;
	}

	// 下方向 【判定処理】
	if ((PushDirection == DIR::DOWN) && (state_2P.Gamepad.sThumbRY <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE * DEADZONE_RY))
	{
		return true;
	}

	// 左上方向 【判定処理】
	if ((PushDirection == DIR::UPPER_LEFT) && (state_2P.Gamepad.sThumbRX <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE)
		&& (state_2P.Gamepad.sThumbRY >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE))
	{
		return true;
	}

	// 右上方向 【判定処理】
	if ((PushDirection == DIR::UPPER_RIGHT) && (state_2P.Gamepad.sThumbRX >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE)
		&& (state_2P.Gamepad.sThumbRY >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE))
	{
		return true;
	}

	// 左下方向 【判定処理】
	if ((PushDirection == DIR::LOWER_LEFT) && (state_2P.Gamepad.sThumbRX <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE)
		&& (state_2P.Gamepad.sThumbRY <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE))
	{
		return true;
	}

	// 右下方向 【判定処理】
	if ((PushDirection == DIR::LOWER_RIGHT) && (state_2P.Gamepad.sThumbRX >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE)
		&& (state_2P.Gamepad.sThumbRY <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE))
	{
		return true;
	}

	// 判定無し
	else
	{
		return false;
	}
}

// 3Pコントローラー
bool Input::RightStick8_3P(int PushDirection)
{

	// 入力の取得
	XInputGetState(2, &state_3P);

	//------------------------------------------------------------
	// 右スティックのデッドゾーン処理
	//------------------------------------------------------------
	if ((state_3P.Gamepad.sThumbRX < XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE && state_3P.Gamepad.sThumbRX > -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE) &&
		(state_3P.Gamepad.sThumbRY < XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE && state_3P.Gamepad.sThumbRY > -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE))
	{
		state_3P.Gamepad.sThumbRX = 0;
		state_3P.Gamepad.sThumbRY = 0;
	}

	// 左方向 【判定処理】
	if ((PushDirection == DIR::LEFT) && (state_3P.Gamepad.sThumbRX <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE * DEADZONE_RX))
	{
		return true;
	}

	// 右方向 【判定処理】
	if ((PushDirection == DIR::RIGHT) && (state_3P.Gamepad.sThumbRX >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE * DEADZONE_RX))
	{
		return true;
	}

	// 上方向 【判定処理】
	if ((PushDirection == DIR::UP) && (state_3P.Gamepad.sThumbRY >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE * DEADZONE_RY))
	{
		return true;
	}

	// 下方向 【判定処理】
	if ((PushDirection == DIR::DOWN) && (state_3P.Gamepad.sThumbRY <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE * DEADZONE_RY))
	{
		return true;
	}

	// 左上方向 【判定処理】
	if ((PushDirection == DIR::UPPER_LEFT) && (state_3P.Gamepad.sThumbRX <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE)
		&& (state_3P.Gamepad.sThumbRY >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE))
	{
		return true;
	}

	// 右上方向 【判定処理】
	if ((PushDirection == DIR::UPPER_RIGHT) && (state_3P.Gamepad.sThumbRX >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE)
		&& (state_3P.Gamepad.sThumbRY >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE))
	{
		return true;
	}

	// 左下方向 【判定処理】
	if ((PushDirection == DIR::LOWER_LEFT) && (state_3P.Gamepad.sThumbRX <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE)
		&& (state_3P.Gamepad.sThumbRY <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE))
	{
		return true;
	}

	// 右下方向 【判定処理】
	if ((PushDirection == DIR::LOWER_RIGHT) && (state_3P.Gamepad.sThumbRX >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE)
		&& (state_3P.Gamepad.sThumbRY <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE))
	{
		return true;
	}

	// 判定無し
	else
	{
		return false;
	}
}

// 4Pコントローラー
bool Input::RightStick8_4P(int PushDirection)
{

	// 入力の取得
	XInputGetState(3, &state_4P);

	//------------------------------------------------------------
	// 右スティックのデッドゾーン処理
	//------------------------------------------------------------
	if ((state_4P.Gamepad.sThumbRX < XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE && state_4P.Gamepad.sThumbRX > -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE) &&
		(state_4P.Gamepad.sThumbRY < XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE && state_4P.Gamepad.sThumbRY > -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE))
	{
		state_4P.Gamepad.sThumbRX = 0;
		state_4P.Gamepad.sThumbRY = 0;
	}

	// 左方向 【判定処理】
	if ((PushDirection == DIR::LEFT) && (state_4P.Gamepad.sThumbRX <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE * DEADZONE_RX))
	{
		return true;
	}

	// 右方向 【判定処理】
	if ((PushDirection == DIR::RIGHT) && (state_4P.Gamepad.sThumbRX >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE * DEADZONE_RX))
	{
		return true;
	}

	// 上方向 【判定処理】
	if ((PushDirection == DIR::UP) && (state_4P.Gamepad.sThumbRY >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE * DEADZONE_RY))
	{
		return true;
	}

	// 下方向 【判定処理】
	if ((PushDirection == DIR::DOWN) && (state_4P.Gamepad.sThumbRY <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE * DEADZONE_RY))
	{
		return true;
	}

	// 左上方向 【判定処理】
	if ((PushDirection == DIR::UPPER_LEFT) && (state_4P.Gamepad.sThumbRX <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE)
		&& (state_4P.Gamepad.sThumbRY >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE))
	{
		return true;
	}

	// 右上方向 【判定処理】
	if ((PushDirection == DIR::UPPER_RIGHT) && (state_4P.Gamepad.sThumbRX >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE)
		&& (state_4P.Gamepad.sThumbRY >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE))
	{
		return true;
	}

	// 左下方向 【判定処理】
	if ((PushDirection == DIR::LOWER_LEFT) && (state_4P.Gamepad.sThumbRX <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE)
		&& (state_4P.Gamepad.sThumbRY <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE))
	{
		return true;
	}

	// 右下方向 【判定処理】
	if ((PushDirection == DIR::LOWER_RIGHT) && (state_4P.Gamepad.sThumbRX >= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE)
		&& (state_4P.Gamepad.sThumbRY <= -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE))
	{
		return true;
	}

	// 判定無し
	else
	{
		return false;
	}
}



//------------------------------------------------------------
// 左バイブレーションを使用する際の関数
//
// int VibrationLevel に 数値 を入れると 振動の強弱 が調整できる
//------------------------------------------------------------
// 1Pコントローラー
bool Input::LeftVibrationStart_1P(int VibrationLevel)
{
	// 左バイブレーション 【作動処理】
	vibration_1P.wLeftMotorSpeed = VibrationLevel;
	XInputSetState(0, &vibration_1P);
	return true;
}

// 2Pコントローラー
bool Input::LeftVibrationStart_2P(int VibrationLevel)
{
	// 左バイブレーション 【作動処理】
	vibration_2P.wLeftMotorSpeed = VibrationLevel;
	XInputSetState(1, &vibration_2P);
	return true;
}

// 3Pコントローラー
bool Input::LeftVibrationStart_3P(int VibrationLevel)
{
	// 左バイブレーション 【作動処理】
	vibration_3P.wLeftMotorSpeed = VibrationLevel;
	XInputSetState(2, &vibration_3P);
	return true;
}

// 4Pコントローラー
bool Input::LeftVibrationStart_4P(int VibrationLevel)
{
	// 左バイブレーション 【作動処理】
	vibration_4P.wLeftMotorSpeed = VibrationLevel;
	XInputSetState(3, &vibration_4P);
	return true;
}



//------------------------------------------------------------
// 右バイブレーションを使用する際の関数
//
// int VibrationLevel に 数値 を入れると 振動の強弱 が調整できる
//------------------------------------------------------------
// 1Pコントローラー
bool Input::RightVibrationStart_1P(int VibrationLevel)
{
	// 右バイブレーション 【作動処理】
	vibration_1P.wRightMotorSpeed = VibrationLevel;
	XInputSetState(0, &vibration_1P);
	return true;
}

// 2Pコントローラー
bool Input::RightVibrationStart_2P(int VibrationLevel)
{
	// 右バイブレーション 【作動処理】
	vibration_2P.wRightMotorSpeed = VibrationLevel;
	XInputSetState(1, &vibration_2P);
	return true;
}

// 3Pコントローラー
bool Input::RightVibrationStart_3P(int VibrationLevel)
{
	// 右バイブレーション 【作動処理】
	vibration_3P.wRightMotorSpeed = VibrationLevel;
	XInputSetState(2, &vibration_3P);
	return true;
}

// 4Pコントローラー
bool Input::RightVibrationStart_4P(int VibrationLevel)
{
	// 右バイブレーション 【作動処理】
	vibration_4P.wRightMotorSpeed = VibrationLevel;
	XInputSetState(3, &vibration_4P);
	return true;
}



//------------------------------------------------------------
// 左バイブレーションを停止する際の関数
//------------------------------------------------------------
// 1Pコントローラー
bool Input::LeftVibrationStop_1P()
{
	// 左バイブレーション 【停止処理】
	vibration_1P.wLeftMotorSpeed = false;
	XInputSetState(0, &vibration_1P);
	return true;
}

// 2Pコントローラー
bool Input::LeftVibrationStop_2P()
{
	// 左バイブレーション 【停止処理】
	vibration_2P.wLeftMotorSpeed = false;
	XInputSetState(1, &vibration_2P);
	return true;
}

// 3Pコントローラー
bool Input::LeftVibrationStop_3P()
{
	// 左バイブレーション 【停止処理】
	vibration_3P.wLeftMotorSpeed = false;
	XInputSetState(2, &vibration_3P);
	return true;
}

// 4Pコントローラー
bool Input::LeftVibrationStop_4P()
{
	// 左バイブレーション 【停止処理】
	vibration_4P.wLeftMotorSpeed = false;
	XInputSetState(3, &vibration_4P);
	return true;
}



//------------------------------------------------------------
// 右バイブレーションを停止する際の関数
//------------------------------------------------------------
// 1Pコントローラー
bool Input::RightVibrationStop_1P()
{
	// 右バイブレーション 【停止処理】
	vibration_1P.wRightMotorSpeed = false;
	XInputSetState(0, &vibration_1P);
	return true;
}

// 2Pコントローラー
bool Input::RightVibrationStop_2P()
{
	// 右バイブレーション 【停止処理】
	vibration_2P.wRightMotorSpeed = false;
	XInputSetState(1, &vibration_2P);
	return true;
}

// 3Pコントローラー
bool Input::RightVibrationStop_3P()
{
	// 右バイブレーション 【停止処理】
	vibration_3P.wRightMotorSpeed = false;
	XInputSetState(2, &vibration_3P);
	return true;
}

// 4Pコントローラー
bool Input::RightVibrationStop_4P()
{
	// 右バイブレーション 【停止処理】
	vibration_4P.wRightMotorSpeed = false;
	XInputSetState(3, &vibration_4P);
	return true;
}

void Input::Input_Update()
{
	//現在のキー情報を古いキー変数にコピーする
	memcpy_s(gOldKeys, sizeof(gOldKeys), gKeys, sizeof(gKeys));

	//現在のキー情報を取得
	gKeys[VK_UP] = GetAsyncKeyState(VK_UP);				//上
	gKeys[VK_DOWN] = GetAsyncKeyState(VK_DOWN);			//下
	gKeys[VK_LEFT] = GetAsyncKeyState(VK_LEFT);			//左
	gKeys[VK_RIGHT] = GetAsyncKeyState(VK_RIGHT);		//右
	gKeys[VK_LBUTTON] = GetAsyncKeyState(VK_LBUTTON);	//左クリック（マウス）
	gKeys[VK_RBUTTON] = GetAsyncKeyState(VK_RBUTTON);	//右クリック（マウス）
	gKeys[VK_RETURN] = GetAsyncKeyState(VK_RETURN);		//ENTERキー
	gKeys[VK_ESCAPE] = GetAsyncKeyState(VK_ESCAPE);		//ESCキー
	gKeys[VK_SPACE] = GetAsyncKeyState(VK_SPACE);		//スペースキー
	gKeys['W'] = GetAsyncKeyState('W');					//W
	gKeys['A'] = GetAsyncKeyState('A');					//A
	gKeys['S'] = GetAsyncKeyState('S');					//S
	gKeys['D'] = GetAsyncKeyState('D');					//D
	gKeys['P'] = GetAsyncKeyState('P');					//P
}

//長押し用の関数
bool Input::Input_GetKeyPress(int vkey)
{
	return gKeys[vkey] & 0x8000;
}

//単発押し用の関数
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