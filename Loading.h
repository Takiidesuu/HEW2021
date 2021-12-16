#pragma once
#include <future>
#include "Scene.h"

#define SLOW 50		//ローディングバーの速度を遅くする値（大きければ遅い）

class Loading
{
public:
	typedef std::function<void()> Func;				//functionポインター変数

	bool Init();									//初期化
	void Load(Func, Func, Func, Func, Func);		//ローディング

	void Count();			//進行のカウント

	void Draw();			//描画

private:
	CSprite* enemy;			//敵スプライト
	CSprite* loadingBar;	//ローディングバー
	CSprite* background;	//背景

	int progress = 0;		//進行状況
	int progressGoal = 0;	//進行状況を描画するための変数
	int num = 0;			//ロードする物の数
	int goalIncrement = 0;	//毎物の実行でローディングバーの進む距離
	float posX = 2.3f;		//ローディングバーと敵スプライトのX位置

	void Reset();			//値のリセット関数
};