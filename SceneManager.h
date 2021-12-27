#pragma once
#include <Windows.h>

//シーンの名前欄
enum SCENENAME
{
	TITLE,
	LOADGAME,
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
	// シーン移行する際に 使用している
	void	ChoiceSWS(	// SelectClass.cppで 使用している
		int STAR,		// ChoiceSWSの 第一引数に STAR_CHOICEを 渡している
		int WORLD,		// ChoiceSWSの 第二引数に WORLD_CHOICEを 渡している
		int STAGE);		// ChoiceSWSの 第三引数に STAGE_CHOICEを 渡している

	// シーン移行した際に 使用している
	int		ChoiceStar();	// 移行した際に 指定する スター関数
	int		ChoiceWorld();	// 移行した際に 指定する ワールド関数
	int		ChoiceStage();	// 移行した際に 指定する ステージ関数

private:
	SCENENAME sceneNum;			//シーンの情報を持ってる変数

	int SceneStar = 0;	// 移行する際に 使用する スター値
	int SceneWorld = 0;	// 移行する際に 使用する ワールド値
	int SceneStage = 0;	// 移行する際に 使用する ステージ値
};

extern SceneManager sceneManager;