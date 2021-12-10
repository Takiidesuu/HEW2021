#include "GameTimer.h"
#include <mmsystem.h>  // timeGetTime�֐����g���̂ɕK�v

#pragma comment (lib, "winmm.lib")  // timeGetTime�֐����g���̂ɕK�v

//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************

static DWORD gFps = 60;  // �f�t�H���g��60FPS
static DWORD gLastFrameStartTime; // �P�O�̃t���[�����s�J�n���̎��Ԃ�ۑ�����ϐ�
static float gDeltaTime;

//*****************************************************************************
// �֐��̒�`�@��������@��
//*****************************************************************************

void GameTimer_Initialize(int fps)
{
	gFps = fps;
	GameTimer_ReachedNextFrame();  // �f���^�^�C���v���̏������̂���
}

float GameTimer_GetDeltaTime()
{
	return gDeltaTime;
}

BOOL GameTimer_ReachedNextFrame()
{
	timeBeginPeriod(1);  // timeGetTime�֐���1�~���b�P�ʂŒl��Ԃ��悤�ɐݒ肷��
	DWORD currentTime = timeGetTime();  // Windows�N������̎��Ԃ��~���b�P�ʂŕԂ�
	timeEndPeriod(1);  // timeBeginPeriod�֐��Őݒ肵����Ԃ��f�t�H���g�ɖ߂�

	BOOL reached = currentTime - gLastFrameStartTime >= 1000 / gFps;

	if (reached) {  // ���̃t���[�������s���ׂ����ԂɒB���Ă����
		gDeltaTime = (float)(currentTime - gLastFrameStartTime) / 1000.0f;
		gLastFrameStartTime = currentTime;
	}

	return reached;
}

void GameTimer_OnResume()
{
	GameTimer_ReachedNextFrame();
	gDeltaTime = 16.0f / 1000.0f;
}
