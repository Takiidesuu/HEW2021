#pragma once
#include <future>
#include "Scene.h"

#define SLOW 100		//ローディングバーの速度を遅くする値（大きければ遅い）

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

	int num = 0;			//ロードする物の数
	float posX = 1.25f;		//ローディングバーと敵スプライトのX位置

	void Reset();			//値のリセット関数
};