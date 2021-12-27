#pragma once

#ifndef _XAUDIO2_H_
#define _XAUDIO2_H_

#include <xaudio2.h>

/*SOUND_BGM002,
SOUND_SE01,
SOUND_SE02,*/

//�������g����悤�ɁA���x����t����
typedef enum
{
	SOUND_BGM001,	// 1-1��BGM
	//SOUND_SE01,		// �e���|�[�g�P��
	//SOUND_SE02,		// �e���|�[�g�Q��
	//SOUND_SE03,		// �e���|�[�g�R��
	//SOUND_SE04,		// �e���|�[�g�S��
	//SOUND_SE05,		// �e���|�[�g�T��
	//SOUND_SE06,		// �e���|�[�g�U��
	SOUNDFILEMAX,	// ����ȏ�͂Ȃ���
}SOUNDLABEL;

class SoundClass
{
public:
	bool Init(void);				//������
	void Shutdown(void);			//�V���b�g�_�E��
	void Play(SOUNDLABEL label);	//�Đ�
	void Pause(SOUNDLABEL label);	//�ꎞ��~
	void Replay(SOUNDLABEL label);	//���v���C
	void Stop(SOUNDLABEL label);	//��~
};

#endif