#pragma once

#include "GameObject.h"

class CEfect :public CGameObject {
public:
	static int EfectCnt;						//�G�t�F�N�g�̐�

	//�������Ƀ��[�v�Đ��̗L����n���A����ȍ~�̈�����CGameObject�Ɠ��l
	CEfect(bool loopflg, const char* texturePath, int horizontalPartNum, int verticalPartNum, float PosX, float PosY, float SizeX, float SizeY);
	CEfect(bool loopflg, const char* texturePath, int horizontalPartNum, int verticalPartNum, float PosX, float PosY, float SizeX, float SizeY, float PixcelSizeX, float PixcelSizeY);
	~CEfect();

	bool reproducing_complete = false;			//�A�j���[�V�����Đ��I��
	void Anim();								//�A�j���[�V�����X�V����

private:
	bool loop_reproducing = false;				//���[�v�Đ����邩�ۂ�
	int anim_num = 0;							//�A�j���[�V�����ԍ�
};