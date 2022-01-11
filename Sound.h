#pragma once

#ifndef _XAUDIO2_H_
#define _XAUDIO2_H_

#include <windows.h>
#include <xaudio2.h>

//音声を使えるように、ラベルを付ける
typedef enum
{
	// BGM
	BGM_TITLE,		//タイトルBGM
	BGM_TITLE2,		//タイトルBGM
	BGM_SELECT,		//セレクトBGM

	// SE
	SE_CANCEL,		// キャンセル音
	SE_DECISION,	// 決定音
	SE_SWING,		// 攻撃音

	SOUND_BGM001,	// 1-1のBGM
	SOUND_BGM000_VER2,

	SOUND_SE01,		// テレポート１番
	SOUND_SE02,		// テレポート２番
	SOUND_SE03,		// テレポート３番
	SOUND_SE04,		// テレポート４番
	SOUND_SE05,		// テレポート５番
	SOUND_SE06,		// テレポート６番
	SOUND_SE_CIRCLE01,

	SOUNDFILEMAX,	// これ以上はないよ
}SOUNDLABEL;

class SoundClass
{
public:
	HRESULT Init(void);					//初期化
	void Shutdown(void);				//シャットダウン
	void Play(SOUNDLABEL label);		//再生
	void Pause(SOUNDLABEL label);		//一時停止
	void Replay(SOUNDLABEL label);		//リプレイ
	void Stop(SOUNDLABEL label);		//停止
	void Volume(SOUNDLABEL label,		//音量調整
	float VolumeLevel);					//0.0fが無音	1.0fが最大音量
	//void PlayPos(SOUNDLABEL label);	//再生位置
};

#endif