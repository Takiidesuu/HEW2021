#include "GameTimer.h"
#include <mmsystem.h>  // timeGetTime関数を使うのに必要

#pragma comment (lib, "winmm.lib")  // timeGetTime関数を使うのに必要

//*****************************************************************************
// グローバル変数
//*****************************************************************************

static DWORD gFps = 60;  // デフォルトは60FPS
static DWORD gLastFrameStartTime; // １つ前のフレーム実行開始時の時間を保存する変数
static float gDeltaTime;

//*****************************************************************************
// 関数の定義　ここから　↓
//*****************************************************************************

void GameTimer_Initialize(int fps)
{
	gFps = fps;
	GameTimer_ReachedNextFrame();  // デルタタイム計測の初期化のため
}

float GameTimer_GetDeltaTime()
{
	return gDeltaTime;
}

BOOL GameTimer_ReachedNextFrame()
{
	timeBeginPeriod(1);  // timeGetTime関数を1ミリ秒単位で値を返すように設定する
	DWORD currentTime = timeGetTime();  // Windows起動からの時間をミリ秒単位で返す
	timeEndPeriod(1);  // timeBeginPeriod関数で設定した状態をデフォルトに戻す

	BOOL reached = currentTime - gLastFrameStartTime >= 1000 / gFps;

	if (reached) {  // 次のフレームを実行すべき時間に達していれば
		gDeltaTime = (float)(currentTime - gLastFrameStartTime) / 1000.0f;
		gLastFrameStartTime = currentTime;
	}

	return reached;
}

void GameTimer_OnResume()
{
	GameTimer_ReachedNextFrame();
	gDeltaTime = 16.0f / 1000.0f;
}
