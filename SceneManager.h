#pragma once
#include <Windows.h>

//�V�[���̖��O��
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
	void LoadScene(SCENENAME scene);	//�w�肵���V�[���ɕς���

private:
	SCENENAME sceneNum;			//�V�[���̏��������Ă�ϐ�
};

extern SceneManager sceneManager;