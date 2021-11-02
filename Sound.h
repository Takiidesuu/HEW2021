#pragma once

#ifndef _XAUDIO2_H_
#define _XAUDIO2_H_

#include <xaudio2.h>

/*SOUND_BGM002,
SOUND_SE01,
SOUND_SE02,*/

//音声を使えるように、ラベルを付ける
typedef enum
{
	SOUND_BGM001,
	SOUNDFILEMAX,
}SOUNDLABEL;

class SoundClass
{
public:
	HRESULT Init(void);				//初期化
	void Shutdown(void);			//シャットダウン
	void Play(SOUNDLABEL label);	//再生
	void Pause(SOUNDLABEL label);	//一時停止
	void Stop(SOUNDLABEL label);	//停止
};

#endif