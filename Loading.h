#pragma once
#include <future>
#include "Scene.h"

#define SLOW 50		//���[�f�B���O�o�[�̑��x��x������l�i�傫����Βx���j

class Loading
{
public:
	typedef std::function<void()> Func;				//function�|�C���^�[�ϐ�

	bool Init();									//������
	void Load(Func, Func, Func, Func, Func);		//���[�f�B���O

	void Count();			//�i�s�̃J�E���g

	void Draw();			//�`��

private:
	CSprite* enemy;			//�G�X�v���C�g
	CSprite* loadingBar;	//���[�f�B���O�o�[
	CSprite* background;	//�w�i

	int progress = 0;		//�i�s��
	int progressGoal = 0;	//�i�s�󋵂�`�悷�邽�߂̕ϐ�
	int num = 0;			//���[�h���镨�̐�
	int goalIncrement = 0;	//�����̎��s�Ń��[�f�B���O�o�[�̐i�ދ���
	float posX = 2.3f;		//���[�f�B���O�o�[�ƓG�X�v���C�g��X�ʒu

	void Reset();			//�l�̃��Z�b�g�֐�
};