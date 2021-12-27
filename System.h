////////////////////////////////////////////////
////	FILENAME: System.h
////////////////////////////////////////////////

#pragma once

///////////////////////////////
// 処理の前のディレクティブ //
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

const bool FULL_SCREEN = false;	//フルスクリーン

class System
{
public:
	System();		//コンストラクター
	~System();		//デストラクター

	bool Init();		//初期化
	void Update();		//ウインドウズのメッセージ管理関数
	bool Processes();	//ゲームループ
	void Uninit();		//解放関数

	//この関数で実行中のアプリに指示を送る
	LRESULT CALLBACK MessageHandler(HWND, UINT, WPARAM, LPARAM);

private:
	LPCWSTR m_applicationName;			//アプリ名
	HINSTANCE m_hinstance;				//インスタンス
	HWND m_hwnd;						//ウインドウ

	Title* titleObj = 0;				//タイトルオブジェクト
	LoadGame* loadGameObj = 0;			//セーブファイル表示画面オブジェクト
	SelectClass* stageObj = 0;			//ステージセレクトオブジェクト
	GameClass* gameObj = 0;				//ゲームオブジェクト
	Save_Load* saveloadObj = 0;			//セーブロード用オブジェクト
	Loading* loadingObj = 0;			//ローディング画面オブジェクト
	CResult* resultObj = 0;				//リザルト画面オブジェクト

	//ウインドウズの初期化
	void InitializeWindows(int& screenWidth, int& screenHeight);

	bool first = true;
	bool gameInit = false;
};

//メッセージ解読用関数
static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//グローバルオブジェクト関数
static System* ApplicationHandle = 0;