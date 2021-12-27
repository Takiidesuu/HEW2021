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
	SOUND_BGM001,	// 1-1のBGM
	//SOUND_SE01,		// テレポート１番
	//SOUND_SE02,		// テレポート２番
	//SOUND_SE03,		// テレポート３番
	//SOUND_SE04,		// テレポート４番
	//SOUND_SE05,		// テレポート５番
	//SOUND_SE06,		// テレポート６番
	SOUNDFILEMAX,	// これ以上はないよ
}SOUNDLABEL;

class SoundClass
{
public:
	bool Init(void);				//初期化
	void Shutdown(void);			//シャットダウン
	void Play(SOUNDLABEL label);	//再生
	void Pause(SOUNDLABEL label);	//一時停止
	void Replay(SOUNDLABEL label);	//リプレイ
	void Stop(SOUNDLABEL label);	//停止
};

#endif