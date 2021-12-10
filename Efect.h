#pragma once

#include "GameObject.h"

class CEfect :public CGameObject {
public:
	static int EfectCnt;						//エフェクトの数

	//第一引数にループ再生の有無を渡し、それ以降の引数はCGameObjectと同様
	CEfect(bool loopflg, const char* texturePath, int horizontalPartNum, int verticalPartNum, float PosX, float PosY, float SizeX, float SizeY);
	CEfect(bool loopflg, const char* texturePath, int horizontalPartNum, int verticalPartNum, float PosX, float PosY, float SizeX, float SizeY, float PixcelSizeX, float PixcelSizeY);
	~CEfect();

	bool reproducing_complete = false;			//アニメーション再生終了
	void Anim();								//アニメーション更新処理

private:
	bool loop_reproducing = false;				//ループ再生するか否か
	int anim_num = 0;							//アニメーション番号
};