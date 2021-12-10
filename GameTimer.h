#pragma once

#include <Windows.h>

// ゲーム時間の初期化を行う関数
// FPSの設定とデルタタイムの計測開始処理
// ※計測制度の問題でFPSは10-120の範囲を推奨
void GameTimer_Initialize(int fps);

// デルタタイムを取得する
// デルタタイム　→　前のフレーム開始時から今のフレーム開始時までの時間
// ※単位は秒。小数点以下あり。
float GameTimer_GetDeltaTime();

// 設定されたFPSをもとに、次のフレームを実行する時間に到達したらTRUEを返す
BOOL GameTimer_ReachedNextFrame();

// ゲームループ停止から復帰する際に呼び出す関数
void GameTimer_OnResume();

