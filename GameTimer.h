#pragma once

#include <Windows.h>

// �Q�[�����Ԃ̏��������s���֐�
// FPS�̐ݒ�ƃf���^�^�C���̌v���J�n����
// ���v�����x�̖���FPS��10-120�͈̔͂𐄏�
void GameTimer_Initialize(int fps);

// �f���^�^�C�����擾����
// �f���^�^�C���@���@�O�̃t���[���J�n�����獡�̃t���[���J�n���܂ł̎���
// ���P�ʂ͕b�B�����_�ȉ�����B
float GameTimer_GetDeltaTime();

// �ݒ肳�ꂽFPS�����ƂɁA���̃t���[�������s���鎞�Ԃɓ��B������TRUE��Ԃ�
BOOL GameTimer_ReachedNextFrame();

// �Q�[�����[�v��~���畜�A����ۂɌĂяo���֐�
void GameTimer_OnResume();

