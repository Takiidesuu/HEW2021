#pragma once
#include <Windows.h>

//�V�[���̖��O��
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
	void LoadScene(SCENENAME scene);	//�w�肵���V�[���ɕς���
	// �V�[���ڍs����ۂ� �g�p���Ă���
	void	ChoiceSWS(	// SelectClass.cpp�� �g�p���Ă���
		int STAR,		// ChoiceSWS�� �������� STAR_CHOICE�� �n���Ă���
		int WORLD,		// ChoiceSWS�� �������� WORLD_CHOICE�� �n���Ă���
		int STAGE);		// ChoiceSWS�� ��O������ STAGE_CHOICE�� �n���Ă���

	// �V�[���ڍs�����ۂ� �g�p���Ă���
	int		ChoiceStar();	// �ڍs�����ۂ� �w�肷�� �X�^�[�֐�
	int		ChoiceWorld();	// �ڍs�����ۂ� �w�肷�� ���[���h�֐�
	int		ChoiceStage();	// �ڍs�����ۂ� �w�肷�� �X�e�[�W�֐�

private:
	SCENENAME sceneNum;			//�V�[���̏��������Ă�ϐ�

	int SceneStar = 0;	// �ڍs����ۂ� �g�p���� �X�^�[�l
	int SceneWorld = 0;	// �ڍs����ۂ� �g�p���� ���[���h�l
	int SceneStage = 0;	// �ڍs����ۂ� �g�p���� �X�e�[�W�l
};

extern SceneManager sceneManager;