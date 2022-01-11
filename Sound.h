#pragma once

#ifndef _XAUDIO2_H_
#define _XAUDIO2_H_

#include <windows.h>
#include <xaudio2.h>

//�������g����悤�ɁA���x����t����
typedef enum
{
	// BGM
	BGM_TITLE,		//�^�C�g��BGM
	BGM_TITLE2,		//�^�C�g��BGM
	BGM_SELECT,		//�Z���N�gBGM

	// SE
	SE_CANCEL,		// �L�����Z����
	SE_DECISION,	// ���艹
	SE_SWING,		// �U����

	SOUND_BGM001,	// 1-1��BGM
	SOUND_BGM000_VER2,

	SOUND_SE01,		// �e���|�[�g�P��
	SOUND_SE02,		// �e���|�[�g�Q��
	SOUND_SE03,		// �e���|�[�g�R��
	SOUND_SE04,		// �e���|�[�g�S��
	SOUND_SE05,		// �e���|�[�g�T��
	SOUND_SE06,		// �e���|�[�g�U��
	SOUND_SE_CIRCLE01,

	SOUNDFILEMAX,	// ����ȏ�͂Ȃ���
}SOUNDLABEL;

class SoundClass
{
public:
	HRESULT Init(void);					//������
	void Shutdown(void);				//�V���b�g�_�E��
	void Play(SOUNDLABEL label);		//�Đ�
	void Pause(SOUNDLABEL label);		//�ꎞ��~
	void Replay(SOUNDLABEL label);		//���v���C
	void Stop(SOUNDLABEL label);		//��~
	void Volume(SOUNDLABEL label,		//���ʒ���
	float VolumeLevel);					//0.0f������	1.0f���ő剹��
	//void PlayPos(SOUNDLABEL label);	//�Đ��ʒu
};

#endif