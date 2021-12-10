#pragma once
#include <Windows.h>

//シーンの名前欄
enum SCENENAME
{
	TITLE,
	STAGESELECT,
	GAME,
	RESULT,
	LOADING
};

class SceneManager
{
public:
	SCENENAME nowScene();
	void LoadScene(SCENENAME scene);	//指定したシーンに変える

private:
	SCENENAME sceneNum;			//シーンの情報を持ってる変数
};

extern SceneManager sceneManager;