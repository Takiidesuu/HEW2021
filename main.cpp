////////////////////////////////////////////////
////	FILENAME: main.cpp
////////////////////////////////////////////////

////////////////////////////////////////////////
////	INCLUDE
////////////////////////////////////////////////

#include "System.h"

//#ifdef _DEBUG
int main()
{
//#else
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pScmdline, int iCmdshow)
//{
//#endif
	System* systemObj;		//�V�X�e���ϐ������

	bool result;			//�������ǂ����𔻒f����p�̕ϐ�

	systemObj = new System;	//�ϐ��ɃI�u�W�F�N�g������

	//���Ȃ�������
	if (!systemObj)
	{
		MessageBoxA(NULL, "�I�u�W�F�N�g���܂���ł���", "�I�u�W�F�N�g�G���[", MB_OK | MB_ICONERROR);	//�G���[�\��
		return 0;	//�I���
	}

	//�V�X�e���̏�����
	result = systemObj->Init();

	//�s������
	if (result)
	{
		systemObj->Update();	//�S�̓I�̃Q�[�����[�v
	}

	systemObj->Uninit();	//�Q�[���f�[�^���
	delete systemObj;		//�I�u�W�F�N�g������
	systemObj = 0;			//�ϐ�����ɂ���

	//�I���
	return 0;
}