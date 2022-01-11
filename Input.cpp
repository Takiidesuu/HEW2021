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
// 絶対値は32768
//
//  角度	 名称		X値		　Y値	|	X値		|	Y値
//   0.0	北		　  +128	+32767	|			|
//										|	DEADZONE_MIN
//  22.5	北北東	　+18889	+28655	|		  128
//  45.0	北東	　+29426	+21459	|			|
//  67.5	東北東	　+32767	 +7581	|DEADZONE1	|DEADZONE1
//										|  6040		|  3469
//  90.0	東		　+32767	  +128	| 10922		|  7581
//										| 15292		|  9124
// 112.5	東南東	　+32767	-12465	| 18889		| 12465
// 135.0	南東	  +28141	-24287	|			|
// 157.5	南南東	　+10922	-32768	|DEADZONE2	|DEADZONE2
//										| 22745		| 17862
// 180.0	南		　  +128	-32767	| 28141		| 21459
//										| 29170		| 24287
// 202.5	南南西	　-15292	-29684	| 29426		| 27113
// 225.0	南西	　-29170	-17862	|			|
// 247.5	西南西	　-30198	 -9124	|DEADZONE3	|DEADZONE3
//										| 30198		| 28655
// 270.0	西		　-32767	  +128	| 32767		| 29684
//										| 32768		| 32767
// 292,5	西北西	　-32768	 +3469	|			| 32768
// 315.0	北西	　-22745	+27113	|	DEADZONE_MAX
// 337.5	北北西	　 -6040	+32767	|		32768
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

	//   0.0 北
	if ((PushDirection == DIR::UP) &&
		(-DEADZONE_MIN <= state_1P.Gamepad.sThumbLX) &&	// Xここから
		(state_1P.Gamepad.sThumbLX <= DEADZONE_MIN) &&	// Xここまで
		(DEADZONE2_Y <= state_1P.Gamepad.sThumbLY) &&	// Yここから
		(state_1P.Gamepad.sThumbLY <= DEADZONE_MAX))	// Yここまで
	{
		return true;
	}

	//  22.5 北北東
	if ((PushDirection == DIR::R22d5) &&
		(DEADZONE_MIN <= state_1P.Gamepad.sThumbLX) &&	// Xここから
		(state_1P.Gamepad.sThumbLX <= DEADZONE1_X) &&	// Xここまで
		(DEADZONE2_Y <= state_1P.Gamepad.sThumbLY) &&	// Yここから
		(state_1P.Gamepad.sThumbLY <= DEADZONE_MAX))	// Yここまで
	{
		return true;
	}

	//  45.0 北東
	if ((PushDirection == DIR::UPPER_RIGHT) &&
		(DEADZONE1_X <= state_1P.Gamepad.sThumbLX) &&	// Xここから
		(state_1P.Gamepad.sThumbLX <= DEADZONE2_X) &&	// Xここまで
		(DEADZONE1_Y <= state_1P.Gamepad.sThumbLY) &&	// Yここから
		(state_1P.Gamepad.sThumbLY <= DEADZONE2_Y))		// Yここまで
	{
		return true;
	}

	//  67.5 東北東
	if ((PushDirection == DIR::R67d5) &&
		(DEADZONE2_X <= state_1P.Gamepad.sThumbLX) &&	// Xここから
		(state_1P.Gamepad.sThumbLX <= DEADZONE_MAX) &&	// Xここまで
		(DEADZONE_MIN <= state_1P.Gamepad.sThumbLY) &&	// Yここから
		(state_1P.Gamepad.sThumbLY <= DEADZONE1_Y))		// Yここまで
	{
		return true;
	}

	//  90.0 東
	if ((PushDirection == DIR::RIGHT) &&
		(DEADZONE2_X <= state_1P.Gamepad.sThumbLX) &&	// Xここから
		(state_1P.Gamepad.sThumbLX <= DEADZONE_MAX) &&	// Xここまで
		(-DEADZONE_MIN <= state_1P.Gamepad.sThumbLY) &&	// Yここから
		(state_1P.Gamepad.sThumbLY <= DEADZONE_MIN))	// Yここまで
	{
		return true;
	}

	// 112.5 東南東
	if ((PushDirection == DIR::R112d5) &&
		(DEADZONE2_X <= state_1P.Gamepad.sThumbLX) &&	// Xここから
		(state_1P.Gamepad.sThumbLX <= DEADZONE_MAX) &&	// Xここまで
		(-DEADZONE1_Y <= state_1P.Gamepad.sThumbLY) &&	// Yここから
		(state_1P.Gamepad.sThumbLY <= -DEADZONE_MIN))	// Yここまで
	{
		return true;
	}

	// 135.0 南東
	if ((PushDirection == DIR::LOWER_RIGHT) &&
		(DEADZONE1_X <= state_1P.Gamepad.sThumbLX) &&	// Xここから
		(state_1P.Gamepad.sThumbLX <= DEADZONE2_X) &&	// Xここまで
		(-DEADZONE2_Y <= state_1P.Gamepad.sThumbLY) &&	// Yここから
		(state_1P.Gamepad.sThumbLY <= -DEADZONE1_Y))	// Yここまで
	{
		return true;
	}

	// 157.5 南南東
	if ((PushDirection == DIR::R157d5) &&
		(DEADZONE_MIN <= state_1P.Gamepad.sThumbLX) &&	// Xここから
		(state_1P.Gamepad.sThumbLX <= DEADZONE1_X) &&	// Xここまで
		(-DEADZONE_MAX <= state_1P.Gamepad.sThumbLY) &&	// Yここから
		(state_1P.Gamepad.sThumbLY <= -DEADZONE2_Y))	// Yここまで
	{
		return true;
	}

	// 180.0 南
	if ((PushDirection == DIR::DOWN) &&
		(-DEADZONE_MIN <= state_1P.Gamepad.sThumbLX) &&	// Xここから
		(state_1P.Gamepad.sThumbLX <= DEADZONE_MIN) &&	// Xここまで
		(-DEADZONE_MAX <= state_1P.Gamepad.sThumbLY) &&	// Yここから
		(state_1P.Gamepad.sThumbLY <= -DEADZONE2_Y))	// Yここまで
	{
		return true;
	}

	// 202.5 南南西
	if ((PushDirection == DIR::R202d5) &&
		(-DEADZONE1_X <= state_1P.Gamepad.sThumbLX) &&	// Xここから
		(state_1P.Gamepad.sThumbLX <= -DEADZONE_MIN) &&	// Xここまで
		(-DEADZONE_MAX <= state_1P.Gamepad.sThumbLY) &&	// Yここから
		(state_1P.Gamepad.sThumbLY <= -DEADZONE2_Y))	// Yここまで
	{
		return true;
	}

	// 225.0 南西
	if ((PushDirection == DIR::LOWER_LEFT) &&
		(-DEADZONE2_X <= state_1P.Gamepad.sThumbLX) &&	// Xここから
		(state_1P.Gamepad.sThumbLX <= -DEADZONE1_X) &&	// Xここまで
		(-DEADZONE2_Y <= state_1P.Gamepad.sThumbLY) &&	// Yここから
		(state_1P.Gamepad.sThumbLY <= -DEADZONE1_Y))	// Yここまで
	{
		return true;
	}

	// 247.5 西南西
	if ((PushDirection == DIR::R247d5) &&
		(-DEADZONE_MAX <= state_1P.Gamepad.sThumbLX) &&	// Xここから
		(state_1P.Gamepad.sThumbLX <= -DEADZONE2_X) &&	// Xここまで
		(-DEADZONE1_Y <= state_1P.Gamepad.sThumbLY) &&	// Yここから
		(state_1P.Gamepad.sThumbLY <= -DEADZONE_MIN))	// Yここまで
	{
		return true;
	}

	// 270.0 西
	if ((PushDirection == DIR::LEFT) &&
		(-DEADZONE_MAX <= state_1P.Gamepad.sThumbLX) &&	// Xここから
		(state_1P.Gamepad.sThumbLX <= -DEADZONE2_X) &&	// Xここまで
		(-DEADZONE_MIN <= state_1P.Gamepad.sThumbLY) &&	// Yここから
		(state_1P.Gamepad.sThumbLY <= DEADZONE_MIN))	// Yここまで
	{
		return true;
	}

	// 292.5 西北西
	if ((PushDirection == DIR::R292d5) &&
		(-DEADZONE_MAX <= state_1P.Gamepad.sThumbLX) &&	// Xここから
		(state_1P.Gamepad.sThumbLX <= -DEADZONE2_X) &&	// Xここまで
		(DEADZONE_MIN <= state_1P.Gamepad.sThumbLY) &&	// Yここから
		(state_1P.Gamepad.sThumbLY <= DEADZONE1_Y))		// Yここまで
	{
		return true;
	}

	// 315.0 北西
	if ((PushDirection == DIR::UPPER_LEFT) &&
		(-DEADZONE2_X <= state_1P.Gamepad.sThumbLX) &&	// Xここから
		(state_1P.Gamepad.sThumbLX <= -DEADZONE1_X) &&	// Xここまで
		(DEADZONE1_Y <= state_1P.Gamepad.sThumbLY) &&	// Yここから	
		(state_1P.Gamepad.sThumbLY <= DEADZONE2_Y))		// Yここまで	
	{
		return true;
	}

	// 337.5 北北西
	if ((PushDirection == DIR::R337d5) &&
		(-DEADZONE1_X <= state_1P.Gamepad.sThumbLX) &&	// Xここから
		(state_1P.Gamepad.sThumbLX <= -DEADZONE_MIN) &&	// Xここまで
		(DEADZONE2_Y <= state_1P.Gamepad.sThumbLY) &&	// Yここから
		(state_1P.Gamepad.sThumbLY <= DEADZONE_MAX))	// Yここまで
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

	//   0.0 北
	if ((PushDirection == DIR::UP) &&
		(-DEADZONE_MIN <= state_2P.Gamepad.sThumbLX) &&	// Xここから
		(state_2P.Gamepad.sThumbLX <= DEADZONE_MIN) &&	// Xここまで
		(DEADZONE2_Y <= state_2P.Gamepad.sThumbLY) &&	// Yここから
		(state_2P.Gamepad.sThumbLY <= DEADZONE_MAX))	// Yここまで
	{
		return true;
	}

	//  22.5 北北東
	if ((PushDirection == DIR::R22d5) &&
		(DEADZONE_MIN <= state_2P.Gamepad.sThumbLX) &&	// Xここから
		(state_2P.Gamepad.sThumbLX <= DEADZONE1_X) &&	// Xここまで
		(DEADZONE2_Y <= state_2P.Gamepad.sThumbLY) &&	// Yここから
		(state_2P.Gamepad.sThumbLY <= DEADZONE_MAX))	// Yここまで
	{
		return true;
	}

	//  45.0 北東
	if ((PushDirection == DIR::UPPER_RIGHT) &&
		(DEADZONE1_X <= state_2P.Gamepad.sThumbLX) &&	// Xここから
		(state_2P.Gamepad.sThumbLX <= DEADZONE2_X) &&	// Xここまで
		(DEADZONE1_Y <= state_2P.Gamepad.sThumbLY) &&	// Yここから
		(state_2P.Gamepad.sThumbLY <= DEADZONE2_Y))		// Yここまで
	{
		return true;
	}

	//  67.5 東北東
	if ((PushDirection == DIR::R67d5) &&
		(DEADZONE2_X <= state_2P.Gamepad.sThumbLX) &&	// Xここから
		(state_2P.Gamepad.sThumbLX <= DEADZONE_MAX) &&	// Xここまで
		(DEADZONE_MIN <= state_2P.Gamepad.sThumbLY) &&	// Yここから
		(state_2P.Gamepad.sThumbLY <= DEADZONE1_Y))		// Yここまで
	{
		return true;
	}

	//  90.0 東
	if ((PushDirection == DIR::RIGHT) &&
		(DEADZONE2_X <= state_2P.Gamepad.sThumbLX) &&	// Xここから
		(state_2P.Gamepad.sThumbLX <= DEADZONE_MAX) &&	// Xここまで
		(-DEADZONE_MIN <= state_2P.Gamepad.sThumbLY) &&	// Yここから
		(state_2P.Gamepad.sThumbLY <= DEADZONE_MIN))	// Yここまで
	{
		return true;
	}

	// 112.5 東南東
	if ((PushDirection == DIR::R112d5) &&
		(DEADZONE2_X <= state_2P.Gamepad.sThumbLX) &&	// Xここから
		(state_2P.Gamepad.sThumbLX <= DEADZONE_MAX) &&	// Xここまで
		(-DEADZONE1_Y <= state_2P.Gamepad.sThumbLY) &&	// Yここから
		(state_2P.Gamepad.sThumbLY <= -DEADZONE_MIN))	// Yここまで
	{
		return true;
	}

	// 135.0 南東
	if ((PushDirection == DIR::LOWER_RIGHT) &&
		(DEADZONE1_X <= state_2P.Gamepad.sThumbLX) &&	// Xここから
		(state_2P.Gamepad.sThumbLX <= DEADZONE2_X) &&	// Xここまで
		(-DEADZONE2_Y <= state_2P.Gamepad.sThumbLY) &&	// Yここから
		(state_2P.Gamepad.sThumbLY <= -DEADZONE1_Y))	// Yここまで
	{
		return true;
	}

	// 157.5 南南東
	if ((PushDirection == DIR::R157d5) &&
		(DEADZONE_MIN <= state_2P.Gamepad.sThumbLX) &&	// Xここから
		(state_2P.Gamepad.sThumbLX <= DEADZONE1_X) &&	// Xここまで
		(-DEADZONE_MAX <= state_2P.Gamepad.sThumbLY) &&	// Yここから
		(state_2P.Gamepad.sThumbLY <= -DEADZONE2_Y))	// Yここまで
	{
		return true;
	}

	// 180.0 南
	if ((PushDirection == DIR::DOWN) &&
		(-DEADZONE_MIN <= state_2P.Gamepad.sThumbLX) &&	// Xここから
		(state_2P.Gamepad.sThumbLX <= DEADZONE_MIN) &&	// Xここまで
		(-DEADZONE_MAX <= state_2P.Gamepad.sThumbLY) &&	// Yここから
		(state_2P.Gamepad.sThumbLY <= -DEADZONE2_Y))	// Yここまで
	{
		return true;
	}

	// 202.5 南南西
	if ((PushDirection == DIR::R202d5) &&
		(-DEADZONE1_X <= state_2P.Gamepad.sThumbLX) &&	// Xここから
		(state_2P.Gamepad.sThumbLX <= -DEADZONE_MIN) &&	// Xここまで
		(-DEADZONE_MAX <= state_2P.Gamepad.sThumbLY) &&	// Yここから
		(state_2P.Gamepad.sThumbLY <= -DEADZONE2_Y))	// Yここまで
	{
		return true;
	}

	// 225.0 南西
	if ((PushDirection == DIR::LOWER_LEFT) &&
		(-DEADZONE2_X <= state_2P.Gamepad.sThumbLX) &&	// Xここから
		(state_2P.Gamepad.sThumbLX <= -DEADZONE1_X) &&	// Xここまで
		(-DEADZONE2_Y <= state_2P.Gamepad.sThumbLY) &&	// Yここから
		(state_2P.Gamepad.sThumbLY <= -DEADZONE1_Y))	// Yここまで
	{
		return true;
	}

	// 247.5 西南西
	if ((PushDirection == DIR::R247d5) &&
		(-DEADZONE_MAX <= state_2P.Gamepad.sThumbLX) &&	// Xここから
		(state_2P.Gamepad.sThumbLX <= -DEADZONE2_X) &&	// Xここまで
		(-DEADZONE1_Y <= state_2P.Gamepad.sThumbLY) &&	// Yここから
		(state_2P.Gamepad.sThumbLY <= -DEADZONE_MIN))	// Yここまで
	{
		return true;
	}

	// 270.0 西
	if ((PushDirection == DIR::LEFT) &&
		(-DEADZONE_MAX <= state_2P.Gamepad.sThumbLX) &&	// Xここから
		(state_2P.Gamepad.sThumbLX <= -DEADZONE2_X) &&	// Xここまで
		(-DEADZONE_MIN <= state_2P.Gamepad.sThumbLY) &&	// Yここから
		(state_2P.Gamepad.sThumbLY <= DEADZONE_MIN))	// Yここまで
	{
		return true;
	}

	// 292.5 西北西
	if ((PushDirection == DIR::R292d5) &&
		(-DEADZONE_MAX <= state_2P.Gamepad.sThumbLX) &&	// Xここから
		(state_2P.Gamepad.sThumbLX <= -DEADZONE2_X) &&	// Xここまで
		(DEADZONE_MIN <= state_2P.Gamepad.sThumbLY) &&	// Yここから
		(state_2P.Gamepad.sThumbLY <= DEADZONE1_Y))		// Yここまで
	{
		return true;
	}

	// 315.0 北西
	if ((PushDirection == DIR::UPPER_LEFT) &&
		(-DEADZONE2_X <= state_2P.Gamepad.sThumbLX) &&	// Xここから
		(state_2P.Gamepad.sThumbLX <= -DEADZONE1_X) &&	// Xここまで
		(DEADZONE1_Y <= state_2P.Gamepad.sThumbLY) &&	// Yここから	
		(state_2P.Gamepad.sThumbLY <= DEADZONE2_Y))		// Yここまで	
	{
		return true;
	}

	// 337.5 北北西
	if ((PushDirection == DIR::R337d5) &&
		(-DEADZONE1_X <= state_2P.Gamepad.sThumbLX) &&	// Xここから
		(state_2P.Gamepad.sThumbLX <= -DEADZONE_MIN) &&	// Xここまで
		(DEADZONE2_Y <= state_2P.Gamepad.sThumbLY) &&	// Yここから
		(state_2P.Gamepad.sThumbLY <= DEADZONE_MAX))	// Yここまで
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

	//   0.0 北
	if ((PushDirection == DIR::UP) &&
		(-DEADZONE_MIN <= state_3P.Gamepad.sThumbLX) &&	// Xここから
		(state_3P.Gamepad.sThumbLX <= DEADZONE_MIN) &&	// Xここまで
		(DEADZONE2_Y <= state_3P.Gamepad.sThumbLY) &&	// Yここから
		(state_3P.Gamepad.sThumbLY <= DEADZONE_MAX))	// Yここまで
	{
		return true;
	}

	//  22.5 北北東
	if ((PushDirection == DIR::R22d5) &&
		(DEADZONE_MIN <= state_3P.Gamepad.sThumbLX) &&	// Xここから
		(state_3P.Gamepad.sThumbLX <= DEADZONE1_X) &&	// Xここまで
		(DEADZONE2_Y <= state_3P.Gamepad.sThumbLY) &&	// Yここから
		(state_3P.Gamepad.sThumbLY <= DEADZONE_MAX))	// Yここまで
	{
		return true;
	}

	//  45.0 北東
	if ((PushDirection == DIR::UPPER_RIGHT) &&
		(DEADZONE1_X <= state_3P.Gamepad.sThumbLX) &&	// Xここから
		(state_3P.Gamepad.sThumbLX <= DEADZONE2_X) &&	// Xここまで
		(DEADZONE1_Y <= state_3P.Gamepad.sThumbLY) &&	// Yここから
		(state_3P.Gamepad.sThumbLY <= DEADZONE2_Y))		// Yここまで
	{
		return true;
	}

	//  67.5 東北東
	if ((PushDirection == DIR::R67d5) &&
		(DEADZONE2_X <= state_3P.Gamepad.sThumbLX) &&	// Xここから
		(state_3P.Gamepad.sThumbLX <= DEADZONE_MAX) &&	// Xここまで
		(DEADZONE_MIN <= state_3P.Gamepad.sThumbLY) &&	// Yここから
		(state_3P.Gamepad.sThumbLY <= DEADZONE1_Y))		// Yここまで
	{
		return true;
	}

	//  90.0 東
	if ((PushDirection == DIR::RIGHT) &&
		(DEADZONE2_X <= state_3P.Gamepad.sThumbLX) &&	// Xここから
		(state_3P.Gamepad.sThumbLX <= DEADZONE_MAX) &&	// Xここまで
		(-DEADZONE_MIN <= state_3P.Gamepad.sThumbLY) &&	// Yここから
		(state_3P.Gamepad.sThumbLY <= DEADZONE_MIN))	// Yここまで
	{
		return true;
	}

	// 112.5 東南東
	if ((PushDirection == DIR::R112d5) &&
		(DEADZONE2_X <= state_3P.Gamepad.sThumbLX) &&	// Xここから
		(state_3P.Gamepad.sThumbLX <= DEADZONE_MAX) &&	// Xここまで
		(-DEADZONE1_Y <= state_3P.Gamepad.sThumbLY) &&	// Yここから
		(state_3P.Gamepad.sThumbLY <= -DEADZONE_MIN))	// Yここまで
	{
		return true;
	}

	// 135.0 南東
	if ((PushDirection == DIR::LOWER_RIGHT) &&
		(DEADZONE1_X <= state_3P.Gamepad.sThumbLX) &&	// Xここから
		(state_3P.Gamepad.sThumbLX <= DEADZONE2_X) &&	// Xここまで
		(-DEADZONE2_Y <= state_3P.Gamepad.sThumbLY) &&	// Yここから
		(state_3P.Gamepad.sThumbLY <= -DEADZONE1_Y))	// Yここまで
	{
		return true;
	}

	// 157.5 南南東
	if ((PushDirection == DIR::R157d5) &&
		(DEADZONE_MIN <= state_3P.Gamepad.sThumbLX) &&	// Xここから
		(state_3P.Gamepad.sThumbLX <= DEADZONE1_X) &&	// Xここまで
		(-DEADZONE_MAX <= state_3P.Gamepad.sThumbLY) &&	// Yここから
		(state_3P.Gamepad.sThumbLY <= -DEADZONE2_Y))	// Yここまで
	{
		return true;
	}

	// 180.0 南
	if ((PushDirection == DIR::DOWN) &&
		(-DEADZONE_MIN <= state_3P.Gamepad.sThumbLX) &&	// Xここから
		(state_3P.Gamepad.sThumbLX <= DEADZONE_MIN) &&	// Xここまで
		(-DEADZONE_MAX <= state_3P.Gamepad.sThumbLY) &&	// Yここから
		(state_3P.Gamepad.sThumbLY <= -DEADZONE2_Y))	// Yここまで
	{
		return true;
	}

	// 202.5 南南西
	if ((PushDirection == DIR::R202d5) &&
		(-DEADZONE1_X <= state_3P.Gamepad.sThumbLX) &&	// Xここから
		(state_3P.Gamepad.sThumbLX <= -DEADZONE_MIN) &&	// Xここまで
		(-DEADZONE_MAX <= state_3P.Gamepad.sThumbLY) &&	// Yここから
		(state_3P.Gamepad.sThumbLY <= -DEADZONE2_Y))	// Yここまで
	{
		return true;
	}

	// 225.0 南西
	if ((PushDirection == DIR::LOWER_LEFT) &&
		(-DEADZONE2_X <= state_3P.Gamepad.sThumbLX) &&	// Xここから
		(state_3P.Gamepad.sThumbLX <= -DEADZONE1_X) &&	// Xここまで
		(-DEADZONE2_Y <= state_3P.Gamepad.sThumbLY) &&	// Yここから
		(state_3P.Gamepad.sThumbLY <= -DEADZONE1_Y))	// Yここまで
	{
		return true;
	}

	// 247.5 西南西
	if ((PushDirection == DIR::R247d5) &&
		(-DEADZONE_MAX <= state_3P.Gamepad.sThumbLX) &&	// Xここから
		(state_3P.Gamepad.sThumbLX <= -DEADZONE2_X) &&	// Xここまで
		(-DEADZONE1_Y <= state_3P.Gamepad.sThumbLY) &&	// Yここから
		(state_3P.Gamepad.sThumbLY <= -DEADZONE_MIN))	// Yここまで
	{
		return true;
	}

	// 270.0 西
	if ((PushDirection == DIR::LEFT) &&
		(-DEADZONE_MAX <= state_3P.Gamepad.sThumbLX) &&	// Xここから
		(state_3P.Gamepad.sThumbLX <= -DEADZONE2_X) &&	// Xここまで
		(-DEADZONE_MIN <= state_3P.Gamepad.sThumbLY) &&	// Yここから
		(state_3P.Gamepad.sThumbLY <= DEADZONE_MIN))	// Yここまで
	{
		return true;
	}

	// 292.5 西北西
	if ((PushDirection == DIR::R292d5) &&
		(-DEADZONE_MAX <= state_3P.Gamepad.sThumbLX) &&	// Xここから
		(state_3P.Gamepad.sThumbLX <= -DEADZONE2_X) &&	// Xここまで
		(DEADZONE_MIN <= state_3P.Gamepad.sThumbLY) &&	// Yここから
		(state_3P.Gamepad.sThumbLY <= DEADZONE1_Y))		// Yここまで
	{
		return true;
	}

	// 315.0 北西
	if ((PushDirection == DIR::UPPER_LEFT) &&
		(-DEADZONE2_X <= state_3P.Gamepad.sThumbLX) &&	// Xここから
		(state_3P.Gamepad.sThumbLX <= -DEADZONE1_X) &&	// Xここまで
		(DEADZONE1_Y <= state_3P.Gamepad.sThumbLY) &&	// Yここから	
		(state_3P.Gamepad.sThumbLY <= DEADZONE2_Y))		// Yここまで	
	{
		return true;
	}

	// 337.5 北北西
	if ((PushDirection == DIR::R337d5) &&
		(-DEADZONE1_X <= state_3P.Gamepad.sThumbLX) &&	// Xここから
		(state_3P.Gamepad.sThumbLX <= -DEADZONE_MIN) &&	// Xここまで
		(DEADZONE2_Y <= state_3P.Gamepad.sThumbLY) &&	// Yここから
		(state_3P.Gamepad.sThumbLY <= DEADZONE_MAX))	// Yここまで
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

	//   0.0 北
	if ((PushDirection == DIR::UP) &&
		(-DEADZONE_MIN <= state_4P.Gamepad.sThumbLX) &&	// Xここから
		(state_4P.Gamepad.sThumbLX <= DEADZONE_MIN) &&	// Xここまで
		(DEADZONE2_Y <= state_4P.Gamepad.sThumbLY) &&	// Yここから
		(state_4P.Gamepad.sThumbLY <= DEADZONE_MAX))	// Yここまで
	{
		return true;
	}

	//  22.5 北北東
	if ((PushDirection == DIR::R22d5) &&
		(DEADZONE_MIN <= state_4P.Gamepad.sThumbLX) &&	// Xここから
		(state_4P.Gamepad.sThumbLX <= DEADZONE1_X) &&	// Xここまで
		(DEADZONE2_Y <= state_4P.Gamepad.sThumbLY) &&	// Yここから
		(state_4P.Gamepad.sThumbLY <= DEADZONE_MAX))	// Yここまで
	{
		return true;
	}

	//  45.0 北東
	if ((PushDirection == DIR::UPPER_RIGHT) &&
		(DEADZONE1_X <= state_4P.Gamepad.sThumbLX) &&	// Xここから
		(state_4P.Gamepad.sThumbLX <= DEADZONE2_X) &&	// Xここまで
		(DEADZONE1_Y <= state_4P.Gamepad.sThumbLY) &&	// Yここから
		(state_4P.Gamepad.sThumbLY <= DEADZONE2_Y))		// Yここまで
	{
		return true;
	}

	//  67.5 東北東
	if ((PushDirection == DIR::R67d5) &&
		(DEADZONE2_X <= state_4P.Gamepad.sThumbLX) &&	// Xここから
		(state_4P.Gamepad.sThumbLX <= DEADZONE_MAX) &&	// Xここまで
		(DEADZONE_MIN <= state_4P.Gamepad.sThumbLY) &&	// Yここから
		(state_4P.Gamepad.sThumbLY <= DEADZONE1_Y))		// Yここまで
	{
		return true;
	}

	//  90.0 東
	if ((PushDirection == DIR::RIGHT) &&
		(DEADZONE2_X <= state_4P.Gamepad.sThumbLX) &&	// Xここから
		(state_4P.Gamepad.sThumbLX <= DEADZONE_MAX) &&	// Xここまで
		(-DEADZONE_MIN <= state_4P.Gamepad.sThumbLY) &&	// Yここから
		(state_4P.Gamepad.sThumbLY <= DEADZONE_MIN))	// Yここまで
	{
		return true;
	}

	// 112.5 東南東
	if ((PushDirection == DIR::R112d5) &&
		(DEADZONE2_X <= state_4P.Gamepad.sThumbLX) &&	// Xここから
		(state_4P.Gamepad.sThumbLX <= DEADZONE_MAX) &&	// Xここまで
		(-DEADZONE1_Y <= state_4P.Gamepad.sThumbLY) &&	// Yここから
		(state_4P.Gamepad.sThumbLY <= -DEADZONE_MIN))	// Yここまで
	{
		return true;
	}

	// 135.0 南東
	if ((PushDirection == DIR::LOWER_RIGHT) &&
		(DEADZONE1_X <= state_4P.Gamepad.sThumbLX) &&	// Xここから
		(state_4P.Gamepad.sThumbLX <= DEADZONE2_X) &&	// Xここまで
		(-DEADZONE2_Y <= state_4P.Gamepad.sThumbLY) &&	// Yここから
		(state_4P.Gamepad.sThumbLY <= -DEADZONE1_Y))	// Yここまで
	{
		return true;
	}

	// 157.5 南南東
	if ((PushDirection == DIR::R157d5) &&
		(DEADZONE_MIN <= state_4P.Gamepad.sThumbLX) &&	// Xここから
		(state_4P.Gamepad.sThumbLX <= DEADZONE1_X) &&	// Xここまで
		(-DEADZONE_MAX <= state_4P.Gamepad.sThumbLY) &&	// Yここから
		(state_4P.Gamepad.sThumbLY <= -DEADZONE2_Y))	// Yここまで
	{
		return true;
	}

	// 180.0 南
	if ((PushDirection == DIR::DOWN) &&
		(-DEADZONE_MIN <= state_4P.Gamepad.sThumbLX) &&	// Xここから
		(state_4P.Gamepad.sThumbLX <= DEADZONE_MIN) &&	// Xここまで
		(-DEADZONE_MAX <= state_4P.Gamepad.sThumbLY) &&	// Yここから
		(state_4P.Gamepad.sThumbLY <= -DEADZONE2_Y))	// Yここまで
	{
		return true;
	}

	// 202.5 南南西
	if ((PushDirection == DIR::R202d5) &&
		(-DEADZONE1_X <= state_4P.Gamepad.sThumbLX) &&	// Xここから
		(state_4P.Gamepad.sThumbLX <= -DEADZONE_MIN) &&	// Xここまで
		(-DEADZONE_MAX <= state_4P.Gamepad.sThumbLY) &&	// Yここから
		(state_4P.Gamepad.sThumbLY <= -DEADZONE2_Y))	// Yここまで
	{
		return true;
	}

	// 225.0 南西
	if ((PushDirection == DIR::LOWER_LEFT) &&
		(-DEADZONE2_X <= state_4P.Gamepad.sThumbLX) &&	// Xここから
		(state_4P.Gamepad.sThumbLX <= -DEADZONE1_X) &&	// Xここまで
		(-DEADZONE2_Y <= state_4P.Gamepad.sThumbLY) &&	// Yここから
		(state_4P.Gamepad.sThumbLY <= -DEADZONE1_Y))	// Yここまで
	{
		return true;
	}

	// 247.5 西南西
	if ((PushDirection == DIR::R247d5) &&
		(-DEADZONE_MAX <= state_4P.Gamepad.sThumbLX) &&	// Xここから
		(state_4P.Gamepad.sThumbLX <= -DEADZONE2_X) &&	// Xここまで
		(-DEADZONE1_Y <= state_4P.Gamepad.sThumbLY) &&	// Yここから
		(state_4P.Gamepad.sThumbLY <= -DEADZONE_MIN))	// Yここまで
	{
		return true;
	}

	// 270.0 西
	if ((PushDirection == DIR::LEFT) &&
		(-DEADZONE_MAX <= state_4P.Gamepad.sThumbLX) &&	// Xここから
		(state_4P.Gamepad.sThumbLX <= -DEADZONE2_X) &&	// Xここまで
		(-DEADZONE_MIN <= state_4P.Gamepad.sThumbLY) &&	// Yここから
		(state_4P.Gamepad.sThumbLY <= DEADZONE_MIN))	// Yここまで
	{
		return true;
	}

	// 292.5 西北西
	if ((PushDirection == DIR::R292d5) &&
		(-DEADZONE_MAX <= state_4P.Gamepad.sThumbLX) &&	// Xここから
		(state_4P.Gamepad.sThumbLX <= -DEADZONE2_X) &&	// Xここまで
		(DEADZONE_MIN <= state_4P.Gamepad.sThumbLY) &&	// Yここから
		(state_4P.Gamepad.sThumbLY <= DEADZONE1_Y))		// Yここまで
	{
		return true;
	}

	// 315.0 北西
	if ((PushDirection == DIR::UPPER_LEFT) &&
		(-DEADZONE2_X <= state_4P.Gamepad.sThumbLX) &&	// Xここから
		(state_4P.Gamepad.sThumbLX <= -DEADZONE1_X) &&	// Xここまで
		(DEADZONE1_Y <= state_4P.Gamepad.sThumbLY) &&	// Yここから	
		(state_4P.Gamepad.sThumbLY <= DEADZONE2_Y))		// Yここまで	
	{
		return true;
	}

	// 337.5 北北西
	if ((PushDirection == DIR::R337d5) &&
		(-DEADZONE1_X <= state_4P.Gamepad.sThumbLX) &&	// Xここから
		(state_4P.Gamepad.sThumbLX <= -DEADZONE_MIN) &&	// Xここまで
		(DEADZONE2_Y <= state_4P.Gamepad.sThumbLY) &&	// Yここから
		(state_4P.Gamepad.sThumbLY <= DEADZONE_MAX))	// Yここまで
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

	//   0.0 北
	if ((PushDirection == DIR::UP) &&
		(-DEADZONE_MIN <= state_1P.Gamepad.sThumbRX) &&	// Xここから
		(state_1P.Gamepad.sThumbRX <= DEADZONE_MIN) &&	// Xここまで
		(DEADZONE2_Y <= state_1P.Gamepad.sThumbRY) &&	// Yここから
		(state_1P.Gamepad.sThumbRY <= DEADZONE_MAX))	// Yここまで
	{
		return true;
	}

	//  22.5 北北東
	if ((PushDirection == DIR::R22d5) &&
		(DEADZONE_MIN <= state_1P.Gamepad.sThumbRX) &&	// Xここから
		(state_1P.Gamepad.sThumbRX <= DEADZONE1_X) &&	// Xここまで
		(DEADZONE2_Y <= state_1P.Gamepad.sThumbRY) &&	// Yここから
		(state_1P.Gamepad.sThumbRY <= DEADZONE_MAX))	// Yここまで
	{
		return true;
	}

	//  45.0 北東
	if ((PushDirection == DIR::UPPER_RIGHT) &&
		(DEADZONE1_X <= state_1P.Gamepad.sThumbRX) &&	// Xここから
		(state_1P.Gamepad.sThumbRX <= DEADZONE2_X) &&	// Xここまで
		(DEADZONE1_Y <= state_1P.Gamepad.sThumbRY) &&	// Yここから
		(state_1P.Gamepad.sThumbRY <= DEADZONE2_Y))		// Yここまで
	{
		return true;
	}

	//  67.5 東北東
	if ((PushDirection == DIR::R67d5) &&
		(DEADZONE2_X <= state_1P.Gamepad.sThumbRX) &&	// Xここから
		(state_1P.Gamepad.sThumbRX <= DEADZONE_MAX) &&	// Xここまで
		(DEADZONE_MIN <= state_1P.Gamepad.sThumbRY) &&	// Yここから
		(state_1P.Gamepad.sThumbRY <= DEADZONE1_Y))		// Yここまで
	{
		return true;
	}

	//  90.0 東
	if ((PushDirection == DIR::RIGHT) &&
		(DEADZONE2_X <= state_1P.Gamepad.sThumbRX) &&	// Xここから
		(state_1P.Gamepad.sThumbRX <= DEADZONE_MAX) &&	// Xここまで
		(-DEADZONE_MIN <= state_1P.Gamepad.sThumbRY) &&	// Yここから
		(state_1P.Gamepad.sThumbRY <= DEADZONE_MIN))	// Yここまで
	{
		return true;
	}

	// 112.5 東南東
	if ((PushDirection == DIR::R112d5) &&
		(DEADZONE2_X <= state_1P.Gamepad.sThumbRX) &&	// Xここから
		(state_1P.Gamepad.sThumbRX <= DEADZONE_MAX) &&	// Xここまで
		(-DEADZONE1_Y <= state_1P.Gamepad.sThumbRY) &&	// Yここから
		(state_1P.Gamepad.sThumbRY <= -DEADZONE_MIN))	// Yここまで
	{
		return true;
	}

	// 135.0 南東
	if ((PushDirection == DIR::LOWER_RIGHT) &&
		(DEADZONE1_X <= state_1P.Gamepad.sThumbRX) &&	// Xここから
		(state_1P.Gamepad.sThumbRX <= DEADZONE2_X) &&	// Xここまで
		(-DEADZONE2_Y <= state_1P.Gamepad.sThumbRY) &&	// Yここから
		(state_1P.Gamepad.sThumbRY <= -DEADZONE1_Y))	// Yここまで
	{
		return true;
	}

	// 157.5 南南東
	if ((PushDirection == DIR::R157d5) &&
		(DEADZONE_MIN <= state_1P.Gamepad.sThumbRX) &&	// Xここから
		(state_1P.Gamepad.sThumbRX <= DEADZONE1_X) &&	// Xここまで
		(-DEADZONE_MAX <= state_1P.Gamepad.sThumbRY) &&	// Yここから
		(state_1P.Gamepad.sThumbRY <= -DEADZONE2_Y))	// Yここまで
	{
		return true;
	}

	// 180.0 南
	if ((PushDirection == DIR::DOWN) &&
		(-DEADZONE_MIN <= state_1P.Gamepad.sThumbRX) &&	// Xここから
		(state_1P.Gamepad.sThumbRX <= DEADZONE_MIN) &&	// Xここまで
		(-DEADZONE_MAX <= state_1P.Gamepad.sThumbRY) &&	// Yここから
		(state_1P.Gamepad.sThumbRY <= -DEADZONE2_Y))	// Yここまで
	{
		return true;
	}

	// 202.5 南南西
	if ((PushDirection == DIR::R202d5) &&
		(-DEADZONE1_X <= state_1P.Gamepad.sThumbRX) &&	// Xここから
		(state_1P.Gamepad.sThumbRX <= -DEADZONE_MIN) &&	// Xここまで
		(-DEADZONE_MAX <= state_1P.Gamepad.sThumbRY) &&	// Yここから
		(state_1P.Gamepad.sThumbRY <= -DEADZONE2_Y))	// Yここまで
	{
		return true;
	}

	// 225.0 南西
	if ((PushDirection == DIR::LOWER_LEFT) &&
		(-DEADZONE2_X <= state_1P.Gamepad.sThumbRX) &&	// Xここから
		(state_1P.Gamepad.sThumbRX <= -DEADZONE1_X) &&	// Xここまで
		(-DEADZONE2_Y <= state_1P.Gamepad.sThumbRY) &&	// Yここから
		(state_1P.Gamepad.sThumbRY <= -DEADZONE1_Y))	// Yここまで
	{
		return true;
	}

	// 247.5 西南西
	if ((PushDirection == DIR::R247d5) &&
		(-DEADZONE_MAX <= state_1P.Gamepad.sThumbRX) &&	// Xここから
		(state_1P.Gamepad.sThumbRX <= -DEADZONE2_X) &&	// Xここまで
		(-DEADZONE1_Y <= state_1P.Gamepad.sThumbRY) &&	// Yここから
		(state_1P.Gamepad.sThumbRY <= -DEADZONE_MIN))	// Yここまで
	{
		return true;
	}

	// 270.0 西
	if ((PushDirection == DIR::LEFT) &&
		(-DEADZONE_MAX <= state_1P.Gamepad.sThumbRX) &&	// Xここから
		(state_1P.Gamepad.sThumbRX <= -DEADZONE2_X) &&	// Xここまで
		(-DEADZONE_MIN <= state_1P.Gamepad.sThumbRY) &&	// Yここから
		(state_1P.Gamepad.sThumbRY <= DEADZONE_MIN))	// Yここまで
	{
		return true;
	}

	// 292.5 西北西
	if ((PushDirection == DIR::R292d5) &&
		(-DEADZONE_MAX <= state_1P.Gamepad.sThumbRX) &&	// Xここから
		(state_1P.Gamepad.sThumbRX <= -DEADZONE2_X) &&	// Xここまで
		(DEADZONE_MIN <= state_1P.Gamepad.sThumbRY) &&	// Yここから
		(state_1P.Gamepad.sThumbRY <= DEADZONE1_Y))		// Yここまで
	{
		return true;
	}

	// 315.0 北西
	if ((PushDirection == DIR::UPPER_LEFT) &&
		(-DEADZONE2_X <= state_1P.Gamepad.sThumbRX) &&	// Xここから
		(state_1P.Gamepad.sThumbRX <= -DEADZONE1_X) &&	// Xここまで
		(DEADZONE1_Y <= state_1P.Gamepad.sThumbRY) &&	// Yここから	
		(state_1P.Gamepad.sThumbRY <= DEADZONE2_Y))		// Yここまで	
	{
		return true;
	}

	// 337.5 北北西
	if ((PushDirection == DIR::R337d5) &&
		(-DEADZONE1_X <= state_1P.Gamepad.sThumbRX) &&	// Xここから
		(state_1P.Gamepad.sThumbRX <= -DEADZONE_MIN) &&	// Xここまで
		(DEADZONE2_Y <= state_1P.Gamepad.sThumbRY) &&	// Yここから
		(state_1P.Gamepad.sThumbRY <= DEADZONE_MAX))	// Yここまで
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

	//   0.0 北
	if ((PushDirection == DIR::UP) &&
		(-DEADZONE_MIN <= state_2P.Gamepad.sThumbRX) &&	// Xここから
		(state_2P.Gamepad.sThumbRX <= DEADZONE_MIN) &&	// Xここまで
		(DEADZONE2_Y <= state_2P.Gamepad.sThumbRY) &&	// Yここから
		(state_2P.Gamepad.sThumbRY <= DEADZONE_MAX))	// Yここまで
	{
		return true;
	}

	//  22.5 北北東
	if ((PushDirection == DIR::R22d5) &&
		(DEADZONE_MIN <= state_2P.Gamepad.sThumbRX) &&	// Xここから
		(state_2P.Gamepad.sThumbRX <= DEADZONE1_X) &&	// Xここまで
		(DEADZONE2_Y <= state_2P.Gamepad.sThumbRY) &&	// Yここから
		(state_2P.Gamepad.sThumbRY <= DEADZONE_MAX))	// Yここまで
	{
		return true;
	}

	//  45.0 北東
	if ((PushDirection == DIR::UPPER_RIGHT) &&
		(DEADZONE1_X <= state_2P.Gamepad.sThumbRX) &&	// Xここから
		(state_2P.Gamepad.sThumbRX <= DEADZONE2_X) &&	// Xここまで
		(DEADZONE1_Y <= state_2P.Gamepad.sThumbRY) &&	// Yここから
		(state_2P.Gamepad.sThumbRY <= DEADZONE2_Y))		// Yここまで
	{
		return true;
	}

	//  67.5 東北東
	if ((PushDirection == DIR::R67d5) &&
		(DEADZONE2_X <= state_2P.Gamepad.sThumbRX) &&	// Xここから
		(state_2P.Gamepad.sThumbRX <= DEADZONE_MAX) &&	// Xここまで
		(DEADZONE_MIN <= state_2P.Gamepad.sThumbRY) &&	// Yここから
		(state_2P.Gamepad.sThumbRY <= DEADZONE1_Y))		// Yここまで
	{
		return true;
	}

	//  90.0 東
	if ((PushDirection == DIR::RIGHT) &&
		(DEADZONE2_X <= state_2P.Gamepad.sThumbRX) &&	// Xここから
		(state_2P.Gamepad.sThumbRX <= DEADZONE_MAX) &&	// Xここまで
		(-DEADZONE_MIN <= state_2P.Gamepad.sThumbRY) &&	// Yここから
		(state_2P.Gamepad.sThumbRY <= DEADZONE_MIN))	// Yここまで
	{
		return true;
	}

	// 112.5 東南東
	if ((PushDirection == DIR::R112d5) &&
		(DEADZONE2_X <= state_2P.Gamepad.sThumbRX) &&	// Xここから
		(state_2P.Gamepad.sThumbRX <= DEADZONE_MAX) &&	// Xここまで
		(-DEADZONE1_Y <= state_2P.Gamepad.sThumbRY) &&	// Yここから
		(state_2P.Gamepad.sThumbRY <= -DEADZONE_MIN))	// Yここまで
	{
		return true;
	}

	// 135.0 南東
	if ((PushDirection == DIR::LOWER_RIGHT) &&
		(DEADZONE1_X <= state_2P.Gamepad.sThumbRX) &&	// Xここから
		(state_2P.Gamepad.sThumbRX <= DEADZONE2_X) &&	// Xここまで
		(-DEADZONE2_Y <= state_2P.Gamepad.sThumbRY) &&	// Yここから
		(state_2P.Gamepad.sThumbRY <= -DEADZONE1_Y))	// Yここまで
	{
		return true;
	}

	// 157.5 南南東
	if ((PushDirection == DIR::R157d5) &&
		(DEADZONE_MIN <= state_2P.Gamepad.sThumbRX) &&	// Xここから
		(state_2P.Gamepad.sThumbRX <= DEADZONE1_X) &&	// Xここまで
		(-DEADZONE_MAX <= state_2P.Gamepad.sThumbRY) &&	// Yここから
		(state_2P.Gamepad.sThumbRY <= -DEADZONE2_Y))	// Yここまで
	{
		return true;
	}

	// 180.0 南
	if ((PushDirection == DIR::DOWN) &&
		(-DEADZONE_MIN <= state_2P.Gamepad.sThumbRX) &&	// Xここから
		(state_2P.Gamepad.sThumbRX <= DEADZONE_MIN) &&	// Xここまで
		(-DEADZONE_MAX <= state_2P.Gamepad.sThumbRY) &&	// Yここから
		(state_2P.Gamepad.sThumbRY <= -DEADZONE2_Y))	// Yここまで
	{
		return true;
	}

	// 202.5 南南西
	if ((PushDirection == DIR::R202d5) &&
		(-DEADZONE1_X <= state_2P.Gamepad.sThumbRX) &&	// Xここから
		(state_2P.Gamepad.sThumbRX <= -DEADZONE_MIN) &&	// Xここまで
		(-DEADZONE_MAX <= state_2P.Gamepad.sThumbRY) &&	// Yここから
		(state_2P.Gamepad.sThumbRY <= -DEADZONE2_Y))	// Yここまで
	{
		return true;
	}

	// 225.0 南西
	if ((PushDirection == DIR::LOWER_LEFT) &&
		(-DEADZONE2_X <= state_2P.Gamepad.sThumbRX) &&	// Xここから
		(state_2P.Gamepad.sThumbRX <= -DEADZONE1_X) &&	// Xここまで
		(-DEADZONE2_Y <= state_2P.Gamepad.sThumbRY) &&	// Yここから
		(state_2P.Gamepad.sThumbRY <= -DEADZONE1_Y))	// Yここまで
	{
		return true;
	}

	// 247.5 西南西
	if ((PushDirection == DIR::R247d5) &&
		(-DEADZONE_MAX <= state_2P.Gamepad.sThumbRX) &&	// Xここから
		(state_2P.Gamepad.sThumbRX <= -DEADZONE2_X) &&	// Xここまで
		(-DEADZONE1_Y <= state_2P.Gamepad.sThumbRY) &&	// Yここから
		(state_2P.Gamepad.sThumbRY <= -DEADZONE_MIN))	// Yここまで
	{
		return true;
	}

	// 270.0 西
	if ((PushDirection == DIR::LEFT) &&
		(-DEADZONE_MAX <= state_2P.Gamepad.sThumbRX) &&	// Xここから
		(state_2P.Gamepad.sThumbRX <= -DEADZONE2_X) &&	// Xここまで
		(-DEADZONE_MIN <= state_2P.Gamepad.sThumbRY) &&	// Yここから
		(state_2P.Gamepad.sThumbRY <= DEADZONE_MIN))	// Yここまで
	{
		return true;
	}

	// 292.5 西北西
	if ((PushDirection == DIR::R292d5) &&
		(-DEADZONE_MAX <= state_2P.Gamepad.sThumbRX) &&	// Xここから
		(state_2P.Gamepad.sThumbRX <= -DEADZONE2_X) &&	// Xここまで
		(DEADZONE_MIN <= state_2P.Gamepad.sThumbRY) &&	// Yここから
		(state_2P.Gamepad.sThumbRY <= DEADZONE1_Y))		// Yここまで
	{
		return true;
	}

	// 315.0 北西
	if ((PushDirection == DIR::UPPER_LEFT) &&
		(-DEADZONE2_X <= state_2P.Gamepad.sThumbRX) &&	// Xここから
		(state_2P.Gamepad.sThumbRX <= -DEADZONE1_X) &&	// Xここまで
		(DEADZONE1_Y <= state_2P.Gamepad.sThumbRY) &&	// Yここから	
		(state_2P.Gamepad.sThumbRY <= DEADZONE2_Y))		// Yここまで	
	{
		return true;
	}

	// 337.5 北北西
	if ((PushDirection == DIR::R337d5) &&
		(-DEADZONE1_X <= state_2P.Gamepad.sThumbRX) &&	// Xここから
		(state_2P.Gamepad.sThumbRX <= -DEADZONE_MIN) &&	// Xここまで
		(DEADZONE2_Y <= state_2P.Gamepad.sThumbRY) &&	// Yここから
		(state_2P.Gamepad.sThumbRY <= DEADZONE_MAX))	// Yここまで
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

	//   0.0 北
	if ((PushDirection == DIR::UP) &&
		(-DEADZONE_MIN <= state_3P.Gamepad.sThumbRX) &&	// Xここから
		(state_3P.Gamepad.sThumbRX <= DEADZONE_MIN) &&	// Xここまで
		(DEADZONE2_Y <= state_3P.Gamepad.sThumbRY) &&	// Yここから
		(state_3P.Gamepad.sThumbRY <= DEADZONE_MAX))	// Yここまで
	{
		return true;
	}

	//  22.5 北北東
	if ((PushDirection == DIR::R22d5) &&
		(DEADZONE_MIN <= state_3P.Gamepad.sThumbRX) &&	// Xここから
		(state_3P.Gamepad.sThumbRX <= DEADZONE1_X) &&	// Xここまで
		(DEADZONE2_Y <= state_3P.Gamepad.sThumbRY) &&	// Yここから
		(state_3P.Gamepad.sThumbRY <= DEADZONE_MAX))	// Yここまで
	{
		return true;
	}

	//  45.0 北東
	if ((PushDirection == DIR::UPPER_RIGHT) &&
		(DEADZONE1_X <= state_3P.Gamepad.sThumbRX) &&	// Xここから
		(state_3P.Gamepad.sThumbRX <= DEADZONE2_X) &&	// Xここまで
		(DEADZONE1_Y <= state_3P.Gamepad.sThumbRY) &&	// Yここから
		(state_3P.Gamepad.sThumbRY <= DEADZONE2_Y))		// Yここまで
	{
		return true;
	}

	//  67.5 東北東
	if ((PushDirection == DIR::R67d5) &&
		(DEADZONE2_X <= state_3P.Gamepad.sThumbRX) &&	// Xここから
		(state_3P.Gamepad.sThumbRX <= DEADZONE_MAX) &&	// Xここまで
		(DEADZONE_MIN <= state_3P.Gamepad.sThumbRY) &&	// Yここから
		(state_3P.Gamepad.sThumbRY <= DEADZONE1_Y))		// Yここまで
	{
		return true;
	}

	//  90.0 東
	if ((PushDirection == DIR::RIGHT) &&
		(DEADZONE2_X <= state_3P.Gamepad.sThumbRX) &&	// Xここから
		(state_3P.Gamepad.sThumbRX <= DEADZONE_MAX) &&	// Xここまで
		(-DEADZONE_MIN <= state_3P.Gamepad.sThumbRY) &&	// Yここから
		(state_3P.Gamepad.sThumbRY <= DEADZONE_MIN))	// Yここまで
	{
		return true;
	}

	// 112.5 東南東
	if ((PushDirection == DIR::R112d5) &&
		(DEADZONE2_X <= state_3P.Gamepad.sThumbRX) &&	// Xここから
		(state_3P.Gamepad.sThumbRX <= DEADZONE_MAX) &&	// Xここまで
		(-DEADZONE1_Y <= state_3P.Gamepad.sThumbRY) &&	// Yここから
		(state_3P.Gamepad.sThumbRY <= -DEADZONE_MIN))	// Yここまで
	{
		return true;
	}

	// 135.0 南東
	if ((PushDirection == DIR::LOWER_RIGHT) &&
		(DEADZONE1_X <= state_3P.Gamepad.sThumbRX) &&	// Xここから
		(state_3P.Gamepad.sThumbRX <= DEADZONE2_X) &&	// Xここまで
		(-DEADZONE2_Y <= state_3P.Gamepad.sThumbRY) &&	// Yここから
		(state_3P.Gamepad.sThumbRY <= -DEADZONE1_Y))	// Yここまで
	{
		return true;
	}

	// 157.5 南南東
	if ((PushDirection == DIR::R157d5) &&
		(DEADZONE_MIN <= state_3P.Gamepad.sThumbRX) &&	// Xここから
		(state_3P.Gamepad.sThumbRX <= DEADZONE1_X) &&	// Xここまで
		(-DEADZONE_MAX <= state_3P.Gamepad.sThumbRY) &&	// Yここから
		(state_3P.Gamepad.sThumbRY <= -DEADZONE2_Y))	// Yここまで
	{
		return true;
	}

	// 180.0 南
	if ((PushDirection == DIR::DOWN) &&
		(-DEADZONE_MIN <= state_3P.Gamepad.sThumbRX) &&	// Xここから
		(state_3P.Gamepad.sThumbRX <= DEADZONE_MIN) &&	// Xここまで
		(-DEADZONE_MAX <= state_3P.Gamepad.sThumbRY) &&	// Yここから
		(state_3P.Gamepad.sThumbRY <= -DEADZONE2_Y))	// Yここまで
	{
		return true;
	}

	// 202.5 南南西
	if ((PushDirection == DIR::R202d5) &&
		(-DEADZONE1_X <= state_3P.Gamepad.sThumbRX) &&	// Xここから
		(state_3P.Gamepad.sThumbRX <= -DEADZONE_MIN) &&	// Xここまで
		(-DEADZONE_MAX <= state_3P.Gamepad.sThumbRY) &&	// Yここから
		(state_3P.Gamepad.sThumbRY <= -DEADZONE2_Y))	// Yここまで
	{
		return true;
	}

	// 225.0 南西
	if ((PushDirection == DIR::LOWER_LEFT) &&
		(-DEADZONE2_X <= state_3P.Gamepad.sThumbRX) &&	// Xここから
		(state_3P.Gamepad.sThumbRX <= -DEADZONE1_X) &&	// Xここまで
		(-DEADZONE2_Y <= state_3P.Gamepad.sThumbRY) &&	// Yここから
		(state_3P.Gamepad.sThumbRY <= -DEADZONE1_Y))	// Yここまで
	{
		return true;
	}

	// 247.5 西南西
	if ((PushDirection == DIR::R247d5) &&
		(-DEADZONE_MAX <= state_3P.Gamepad.sThumbRX) &&	// Xここから
		(state_3P.Gamepad.sThumbRX <= -DEADZONE2_X) &&	// Xここまで
		(-DEADZONE1_Y <= state_3P.Gamepad.sThumbRY) &&	// Yここから
		(state_3P.Gamepad.sThumbRY <= -DEADZONE_MIN))	// Yここまで
	{
		return true;
	}

	// 270.0 西
	if ((PushDirection == DIR::LEFT) &&
		(-DEADZONE_MAX <= state_3P.Gamepad.sThumbRX) &&	// Xここから
		(state_3P.Gamepad.sThumbRX <= -DEADZONE2_X) &&	// Xここまで
		(-DEADZONE_MIN <= state_3P.Gamepad.sThumbRY) &&	// Yここから
		(state_3P.Gamepad.sThumbRY <= DEADZONE_MIN))	// Yここまで
	{
		return true;
	}

	// 292.5 西北西
	if ((PushDirection == DIR::R292d5) &&
		(-DEADZONE_MAX <= state_3P.Gamepad.sThumbRX) &&	// Xここから
		(state_3P.Gamepad.sThumbRX <= -DEADZONE2_X) &&	// Xここまで
		(DEADZONE_MIN <= state_3P.Gamepad.sThumbRY) &&	// Yここから
		(state_3P.Gamepad.sThumbRY <= DEADZONE1_Y))		// Yここまで
	{
		return true;
	}

	// 315.0 北西
	if ((PushDirection == DIR::UPPER_LEFT) &&
		(-DEADZONE2_X <= state_3P.Gamepad.sThumbRX) &&	// Xここから
		(state_3P.Gamepad.sThumbRX <= -DEADZONE1_X) &&	// Xここまで
		(DEADZONE1_Y <= state_3P.Gamepad.sThumbRY) &&	// Yここから	
		(state_3P.Gamepad.sThumbRY <= DEADZONE2_Y))		// Yここまで	
	{
		return true;
	}

	// 337.5 北北西
	if ((PushDirection == DIR::R337d5) &&
		(-DEADZONE1_X <= state_3P.Gamepad.sThumbRX) &&	// Xここから
		(state_3P.Gamepad.sThumbRX <= -DEADZONE_MIN) &&	// Xここまで
		(DEADZONE2_Y <= state_3P.Gamepad.sThumbRY) &&	// Yここから
		(state_3P.Gamepad.sThumbRY <= DEADZONE_MAX))	// Yここまで
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

	//   0.0 北
	if ((PushDirection == DIR::UP) &&
		(-DEADZONE_MIN <= state_4P.Gamepad.sThumbRX) &&	// Xここから
		(state_4P.Gamepad.sThumbRX <= DEADZONE_MIN) &&	// Xここまで
		(DEADZONE2_Y <= state_4P.Gamepad.sThumbRY) &&	// Yここから
		(state_4P.Gamepad.sThumbRY <= DEADZONE_MAX))	// Yここまで
	{
		return true;
	}

	//  22.5 北北東
	if ((PushDirection == DIR::R22d5) &&
		(DEADZONE_MIN <= state_4P.Gamepad.sThumbRX) &&	// Xここから
		(state_4P.Gamepad.sThumbRX <= DEADZONE1_X) &&	// Xここまで
		(DEADZONE2_Y <= state_4P.Gamepad.sThumbRY) &&	// Yここから
		(state_4P.Gamepad.sThumbRY <= DEADZONE_MAX))	// Yここまで
	{
		return true;
	}

	//  45.0 北東
	if ((PushDirection == DIR::UPPER_RIGHT) &&
		(DEADZONE1_X <= state_4P.Gamepad.sThumbRX) &&	// Xここから
		(state_4P.Gamepad.sThumbRX <= DEADZONE2_X) &&	// Xここまで
		(DEADZONE1_Y <= state_4P.Gamepad.sThumbRY) &&	// Yここから
		(state_4P.Gamepad.sThumbRY <= DEADZONE2_Y))		// Yここまで
	{
		return true;
	}

	//  67.5 東北東
	if ((PushDirection == DIR::R67d5) &&
		(DEADZONE2_X <= state_4P.Gamepad.sThumbRX) &&	// Xここから
		(state_4P.Gamepad.sThumbRX <= DEADZONE_MAX) &&	// Xここまで
		(DEADZONE_MIN <= state_4P.Gamepad.sThumbRY) &&	// Yここから
		(state_4P.Gamepad.sThumbRY <= DEADZONE1_Y))		// Yここまで
	{
		return true;
	}

	//  90.0 東
	if ((PushDirection == DIR::RIGHT) &&
		(DEADZONE2_X <= state_4P.Gamepad.sThumbRX) &&	// Xここから
		(state_4P.Gamepad.sThumbRX <= DEADZONE_MAX) &&	// Xここまで
		(-DEADZONE_MIN <= state_4P.Gamepad.sThumbRY) &&	// Yここから
		(state_4P.Gamepad.sThumbRY <= DEADZONE_MIN))	// Yここまで
	{
		return true;
	}

	// 112.5 東南東
	if ((PushDirection == DIR::R112d5) &&
		(DEADZONE2_X <= state_4P.Gamepad.sThumbRX) &&	// Xここから
		(state_4P.Gamepad.sThumbRX <= DEADZONE_MAX) &&	// Xここまで
		(-DEADZONE1_Y <= state_4P.Gamepad.sThumbRY) &&	// Yここから
		(state_4P.Gamepad.sThumbRY <= -DEADZONE_MIN))	// Yここまで
	{
		return true;
	}

	// 135.0 南東
	if ((PushDirection == DIR::LOWER_RIGHT) &&
		(DEADZONE1_X <= state_4P.Gamepad.sThumbRX) &&	// Xここから
		(state_4P.Gamepad.sThumbRX <= DEADZONE2_X) &&	// Xここまで
		(-DEADZONE2_Y <= state_4P.Gamepad.sThumbRY) &&	// Yここから
		(state_4P.Gamepad.sThumbRY <= -DEADZONE1_Y))	// Yここまで
	{
		return true;
	}

	// 157.5 南南東
	if ((PushDirection == DIR::R157d5) &&
		(DEADZONE_MIN <= state_4P.Gamepad.sThumbRX) &&	// Xここから
		(state_4P.Gamepad.sThumbRX <= DEADZONE1_X) &&	// Xここまで
		(-DEADZONE_MAX <= state_4P.Gamepad.sThumbRY) &&	// Yここから
		(state_4P.Gamepad.sThumbRY <= -DEADZONE2_Y))	// Yここまで
	{
		return true;
	}

	// 180.0 南
	if ((PushDirection == DIR::DOWN) &&
		(-DEADZONE_MIN <= state_4P.Gamepad.sThumbRX) &&	// Xここから
		(state_4P.Gamepad.sThumbRX <= DEADZONE_MIN) &&	// Xここまで
		(-DEADZONE_MAX <= state_4P.Gamepad.sThumbRY) &&	// Yここから
		(state_4P.Gamepad.sThumbRY <= -DEADZONE2_Y))	// Yここまで
	{
		return true;
	}

	// 202.5 南南西
	if ((PushDirection == DIR::R202d5) &&
		(-DEADZONE1_X <= state_4P.Gamepad.sThumbRX) &&	// Xここから
		(state_4P.Gamepad.sThumbRX <= -DEADZONE_MIN) &&	// Xここまで
		(-DEADZONE_MAX <= state_4P.Gamepad.sThumbRY) &&	// Yここから
		(state_4P.Gamepad.sThumbRY <= -DEADZONE2_Y))	// Yここまで
	{
		return true;
	}

	// 225.0 南西
	if ((PushDirection == DIR::LOWER_LEFT) &&
		(-DEADZONE2_X <= state_4P.Gamepad.sThumbRX) &&	// Xここから
		(state_4P.Gamepad.sThumbRX <= -DEADZONE1_X) &&	// Xここまで
		(-DEADZONE2_Y <= state_4P.Gamepad.sThumbRY) &&	// Yここから
		(state_4P.Gamepad.sThumbRY <= -DEADZONE1_Y))	// Yここまで
	{
		return true;
	}

	// 247.5 西南西
	if ((PushDirection == DIR::R247d5) &&
		(-DEADZONE_MAX <= state_4P.Gamepad.sThumbRX) &&	// Xここから
		(state_4P.Gamepad.sThumbRX <= -DEADZONE2_X) &&	// Xここまで
		(-DEADZONE1_Y <= state_4P.Gamepad.sThumbRY) &&	// Yここから
		(state_4P.Gamepad.sThumbRY <= -DEADZONE_MIN))	// Yここまで
	{
		return true;
	}

	// 270.0 西
	if ((PushDirection == DIR::LEFT) &&
		(-DEADZONE_MAX <= state_4P.Gamepad.sThumbRX) &&	// Xここから
		(state_4P.Gamepad.sThumbRX <= -DEADZONE2_X) &&	// Xここまで
		(-DEADZONE_MIN <= state_4P.Gamepad.sThumbRY) &&	// Yここから
		(state_4P.Gamepad.sThumbRY <= DEADZONE_MIN))	// Yここまで
	{
		return true;
	}

	// 292.5 西北西
	if ((PushDirection == DIR::R292d5) &&
		(-DEADZONE_MAX <= state_4P.Gamepad.sThumbRX) &&	// Xここから
		(state_4P.Gamepad.sThumbRX <= -DEADZONE2_X) &&	// Xここまで
		(DEADZONE_MIN <= state_4P.Gamepad.sThumbRY) &&	// Yここから
		(state_4P.Gamepad.sThumbRY <= DEADZONE1_Y))		// Yここまで
	{
		return true;
	}

	// 315.0 北西
	if ((PushDirection == DIR::UPPER_LEFT) &&
		(-DEADZONE2_X <= state_4P.Gamepad.sThumbRX) &&	// Xここから
		(state_4P.Gamepad.sThumbRX <= -DEADZONE1_X) &&	// Xここまで
		(DEADZONE1_Y <= state_4P.Gamepad.sThumbRY) &&	// Yここから	
		(state_4P.Gamepad.sThumbRY <= DEADZONE2_Y))		// Yここまで	
	{
		return true;
	}

	// 337.5 北北西
	if ((PushDirection == DIR::R337d5) &&
		(-DEADZONE1_X <= state_4P.Gamepad.sThumbRX) &&	// Xここから
		(state_4P.Gamepad.sThumbRX <= -DEADZONE_MIN) &&	// Xここまで
		(DEADZONE2_Y <= state_4P.Gamepad.sThumbRY) &&	// Yここから
		(state_4P.Gamepad.sThumbRY <= DEADZONE_MAX))	// Yここまで
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
	gKeys[VK_LSHIFT] = GetAsyncKeyState(VK_LSHIFT);		//左SHIFTキー
	gKeys['W'] = GetAsyncKeyState('W');					//W
	gKeys['A'] = GetAsyncKeyState('A');					//A
	gKeys['S'] = GetAsyncKeyState('S');					//S
	gKeys['D'] = GetAsyncKeyState('D');					//D
	gKeys['O'] = GetAsyncKeyState('O');
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