#pragma once

#include <stdio.h>
#include <iostream>

typedef struct {
	typedef struct {
		bool Stage1;
		bool Stage2;
		bool Stage3;
	}WORLD;

	WORLD	World1;
	WORLD	World2;
	WORLD	World3;
	WORLD	World4;
	WORLD	World5;
	WORLD	World6;

	bool Del;

}SAVE_DATA;

class Save_Load
{
public:
	// セーブする関数（ワールド値	ステージ値	クリア判定	削除判定）
	void Save(int world_num, int stage_num, bool Clear_FLG, bool Del_FLG);
	char Load();							// ロードする関数
	void Answer();							// ロードした数値を答える関数
	void Initialize_Date(bool New_or_Del);	// セーブデータを初期化する関数
	void WS_true();							// どこをtrueするか入力する関数

private:
	SAVE_DATA	data;	// 
	int world_num;		// WS_true関数でワールドを指定する数値
	int stage_num;		// WS_true関数でステージを指定する数値
	bool loop;			// WS_true関数の際にループするフラグ
};
