#pragma once

#include <stdio.h>
#include <iostream>

enum LAST_NUM
{
	/*　スター１　*/
	// ワールド１
	LAST_111, LAST_112, LAST_113,

	// ワールド２
	LAST_121, LAST_122, LAST_123,

	/*　スター２　*/
	// ワールド１
	LAST_211, LAST_212, LAST_213,

	// ワールド２
	LAST_221, LAST_222, LAST_223,

	/*　スター３　*/
	// ワールド１
	LAST_311, LAST_312, LAST_313,

	// ワールド２
	LAST_321, LAST_322, LAST_323,
};

// セーブデータの中身
typedef struct {

	// スターの中身
	typedef struct {

		// ワールドの中身
		typedef struct {

			bool	Stage1;	// ステージ１
			bool	Stage2;	// ステージ２ 
			bool	Stage3;	// ステージ３

		}WORLD;

		WORLD	World1;	// ワールド１
		WORLD	World2;	// ワールド２

	}STAR;

	STAR	Star1;	// スター１
	STAR	Star2;	// スター２
	STAR	Star3;	// スター３

	int		Last;
	bool	Del;

}SAVE_DATA;

class Save_Load
{
public:
	void Percent1();						// クリア率を答える関数
	void Percent2();						// クリア率を答える関数
	void Percent3();						// クリア率を答える関数

	// セーブする関数
	void Save1(
		int		star_num,	// スター値
		int		world_num,	// ワールド値
		int		stage_num,	// ステージ値
		bool	Clear_FLG,	// クリア判定
		bool	Del_FLG		// 削除判定
	);
	// セーブする関数
	void Save2(
		int		star_num,	// スター値
		int		world_num,	// ワールド値
		int		stage_num,	// ステージ値
		bool	Clear_FLG,	// クリア判定
		bool	Del_FLG		// 削除判定
	);
	// セーブする関数
	void Save3(
		int		star_num,	// スター値
		int		world_num,	// ワールド値
		int		stage_num,	// ステージ値
		bool	Clear_FLG,	// クリア判定
		bool	Del_FLG		// 削除判定
	);

	char Load1();							// ロードする関数
	char Load2();							// ロードする関数
	char Load3();							// ロードする関数

	void Last1();							// 最後にプレイしたワールド・ステージを答える関数
	void Last2();							// 最後にプレイしたワールド・ステージを答える関数
	void Last3();							// 最後にプレイしたワールド・ステージを答える関数

	void Answer1();							// ロードした数値を答える関数
	void Answer2();							// ロードした数値を答える関数
	void Answer3();							// ロードした数値を答える関数

	void Initialize_Data1(bool New_or_Del);	// セーブデータを初期化する関数
	void Initialize_Data2(bool New_or_Del);	// セーブデータを初期化する関数
	void Initialize_Data3(bool New_or_Del);	// セーブデータを初期化する関数

	void SWS_true1();						// どこをtrueするか入力する関数
	void SWS_true2();						// どこをtrueするか入力する関数
	void SWS_true3();						// どこをtrueするか入力する関数

private:
	SAVE_DATA	data1;		// 1番目セーブデータ
	SAVE_DATA	data2;		// 2番目セーブデータ
	SAVE_DATA	data3;		// 3番目セーブデータ

	typedef struct {
		int Plus = 0;		// Percent関数でクリア数を合計する数値
		float Percent = 0;	// Percent関数でクリア割合を合計する数値
	}CLEAR;

	CLEAR Clear1;
	CLEAR Clear2;
	CLEAR Clear3;

	int star_num;			// WS_true関数でスターを指定する数値
	int world_num;			// WS_true関数でワールドを指定する数値
	int stage_num;			// WS_true関数でステージを指定する数値
	bool loop;				// WS_true関数の際にループするフラグ
};

extern Save_Load* saveloadObj;