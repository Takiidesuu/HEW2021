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
	SOUND_BGM001,
	SOUNDFILEMAX,
}SOUNDLABEL;

class SoundClass
{
public:
	HRESULT Init(void);				//������
	void Shutdown(void);			//�V���b�g�_�E��
	void Play(SOUNDLABEL label);	//�Đ�
	void Pause(SOUNDLABEL label);	//�ꎞ��~
	void Stop(SOUNDLABEL label);	//��~
};

#endif