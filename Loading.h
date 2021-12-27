#pragma once
#include <future>
#include "Scene.h"

#define SLOW 100		//���[�f�B���O�o�[�̑��x��x������l�i�傫����Βx���j

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

	int num = 0;			//���[�h���镨�̐�
	float posX = 1.25f;		//���[�f�B���O�o�[�ƓG�X�v���C�g��X�ʒu

	void Reset();			//�l�̃��Z�b�g�֐�
};