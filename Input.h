#pragma once
#include <Windows.h>
#include <Xinput.h>
#include <stdio.h>
#include <string>
#pragma comment (lib, "xinput.lib")

#define DEADZONE1_X		19000
#define DEADZONE2_X		29500

#define DEADZONE1_Y		12500
#define DEADZONE2_Y		27500

#define DEADZONE_MIN	  200
#define DEADZONE_MAX	32768

//------------------------------------------------------------
// Input.h以外で使用する際の定義
//------------------------------------------------------------
#define GP_UP		XINPUT_GAMEPAD_DPAD_UP			// 十字キー		上
#define GP_DOWN		XINPUT_GAMEPAD_DPAD_DOWN		// 十字キー		下
#define GP_LEFT		XINPUT_GAMEPAD_DPAD_LEFT		// 十字キー		左
#define GP_RIGHT	XINPUT_GAMEPAD_DPAD_RIGHT		// 十字キー		右
#define GP_START	XINPUT_GAMEPAD_START			// スタート		ボタン
#define GP_BACK		XINPUT_GAMEPAD_BACK				// バック		ボタン
#define	GP_LS		XINPUT_GAMEPAD_LEFT_SHOULDER	// 左			ボタン
#define	GP_RS		XINPUT_GAMEPAD_RIGHT_SHOULDER	// 右			ボタン
#define GP_A		XINPUT_GAMEPAD_A				// Ａ			ボタン
#define GP_B		XINPUT_GAMEPAD_B				// Ｂ			ボタン
#define GP_X		XINPUT_GAMEPAD_X				// Ｃ			ボタン
#define GP_Y		XINPUT_GAMEPAD_Y				// Ｄ			ボタン

//------------------------------------------------------------
// スティックを使用する際の方向指定
//------------------------------------------------------------
enum DIR
{
	UP,		// 上
	DOWN,	// 下
	LEFT,	// 左
	RIGHT,	// 右

	UPPER_LEFT,		// 左上
	UPPER_RIGHT,	// 右上
	LOWER_LEFT,		// 左下
	LOWER_RIGHT,	// 右下

	R22d5,  // 北北東
	R67d5,  // 東北東
	R112d5,  // 東南東
	R157d5,  // 南南東
	R202d5,  // 南南西
	R247d5,  // 西南西
	R292d5,  // 西北西
	R337d5,  // 北北西
};

enum ACTION
{
	OK,						//選ぶアクション（ENTERキー、Aボタン）
	BACK,					//戻るアクション（ESCキー、Bキー）
	RESTART,				//リスタート（デバッグ用）
	BREAKCIRCLE,
	HOMINGOFF
};



//------------------------------------------------------------
// 関数一覧（中身は Input.cpp に書いてある）
//------------------------------------------------------------

class Input
{
public:
	// 1Pコントローラー
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

	// 2Pコントローラー
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

	// 3Pコントローラー
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

	// 4Pコントローラー
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

	//キーボード周り
	void Input_Update();
	bool Input_GetKeyPress(int vkey);
	bool Input_GetKeyTrigger(int vkey);

	bool GetAxis(DIR direction);				//方向インプット（長押し）
	bool GetAxisShort(DIR direction);			//方向インプット（一回）
	bool isInput();								//インプットがあるかどうか
	bool GetButtonPress(ACTION action);			//アクションのインプット
};