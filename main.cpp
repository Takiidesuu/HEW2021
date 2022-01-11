////////////////////////////////////////////////
////	FILENAME: main.cpp
////////////////////////////////////////////////

////////////////////////////////////////////////
////	INCLUDE
////////////////////////////////////////////////

#include "System.h"

//#ifdef _DEBUG
int main()
{
//#else
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pScmdline, int iCmdshow)
//{
//#endif
	System* systemObj;		//システム変数を作る

	bool result;			//成功かどうかを判断する用の変数

	systemObj = new System;	//変数にオブジェクトを入れる

	//作れなかったら
	if (!systemObj)
	{
		MessageBoxA(NULL, "オブジェクト作れませんでした", "オブジェクトエラー", MB_OK | MB_ICONERROR);	//エラー表示
		return 0;	//終わる
	}

	//システムの初期化
	result = systemObj->Init();

	//行けたら
	if (result)
	{
		systemObj->Update();	//全体的のゲームループ
	}

	systemObj->Uninit();	//ゲームデータ解放
	delete systemObj;		//オブジェクトを消す
	systemObj = 0;			//変数を空にする

	//終わる
	return 0;
}