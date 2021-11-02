#include "Sound.h"

typedef struct
{
	LPCSTR filename;	//ファイル名（パス）
	bool loop;			//ループさせるか
}PARAM;

PARAM paramObj[SOUNDFILEMAX] = 
{
	{"assets/BGM001.wav", true},
};

#ifdef _XBOX //Big-Endian
#define fourccRIFF 'RIFF'
#define fourccDATA 'data'
#define fourccFMT 'fmt '
#define fourccWAVE 'WAVE'
#define fourccXWMA 'XWMA'
#define fourccDPDS 'dpds'
#endif
#ifndef _XBOX //Little-Endian
#define fourccRIFF 'FFIR'
#define fourccDATA 'atad'
#define fourccFMT ' tmf'
#define fourccWAVE 'EVAW'
#define fourccXWMA 'AMWX'
#define fourccDPDS 'sdpd'
#endif

IXAudio2 *g_pXAudio2 = NULL;		
IXAudio2MasteringVoice *g_pMasteringVoice = NULL;
IXAudio2SourceVoice *g_pSourceVoice[SOUNDFILEMAX];

WAVEFORMATEXTENSIBLE g_wfx[SOUNDFILEMAX];			//WAVフォーマット
XAUDIO2_BUFFER g_buffer[SOUNDFILEMAX];
BYTE *g_DataBuffer[SOUNDFILEMAX];

HRESULT FindChunk(HANDLE, DWORD, DWORD&, DWORD&);
HRESULT ReadChunkData(HANDLE, void*, DWORD, DWORD);

//初期化
HRESULT SoundClass::Init()
{
	HRESULT hr;

	HANDLE hFile;
	DWORD dwChunkSize;
	DWORD dwChunkPosition;
	DWORD filetype;

	//COMの初期化
	CoInitializeEx(NULL, COINIT_MULTITHREADED);

	//XAudioオブジェクトを作る
	hr = XAudio2Create(&g_pXAudio2, 0);

	//失敗
	if (FAILED(hr))
	{
		CoUninitialize();	//解放
		return -1;
	}

	//MasteringVoice（音声を出せるようにしてくれる）オブジェクトを作る
	hr = g_pXAudio2->CreateMasteringVoice(&g_pMasteringVoice);

	//失敗
	if (FAILED(hr))
	{
		if (g_pXAudio2)	//XAudio2のオブジェクトがあったら
			g_pXAudio2->Release();	//消す
		CoUninitialize();
		return -1;
	}

	//それぞれの音声ファイルを初期化
	for (int i = 0; i < SOUNDFILEMAX; i++)
	{
		memset(&g_wfx[i], 0, sizeof(WAVEFORMATEXTENSIBLE));
		memset(&g_buffer[i], 0, sizeof(XAUDIO2_BUFFER));

		hFile = CreateFileA(paramObj[i].filename, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);

		if (hFile == INVALID_HANDLE_VALUE)
			return HRESULT_FROM_WIN32(GetLastError());
		if (SetFilePointer(hFile, 0, NULL, FILE_BEGIN) == INVALID_SET_FILE_POINTER)
			return HRESULT_FROM_WIN32(GetLastError());

		//ファイルタイプをチェックする
		FindChunk(hFile, fourccRIFF, dwChunkSize, dwChunkPosition);
		ReadChunkData(hFile, &filetype, sizeof(DWORD), dwChunkPosition);

		if (filetype != fourccWAVE)
			return S_FALSE;

		FindChunk(hFile, fourccFMT, dwChunkSize, dwChunkPosition);
		ReadChunkData(hFile, &g_wfx[i], dwChunkSize, dwChunkPosition);

		//音声データバッファにfourccDATAチャンクを入れる
		FindChunk(hFile, fourccDATA, dwChunkSize, dwChunkPosition);
		g_DataBuffer[i] = new BYTE[dwChunkSize];
		ReadChunkData(hFile, g_DataBuffer[i], dwChunkSize, dwChunkPosition);

		CloseHandle(hFile);

		//サブミットボイスで利用するサブミットバッファの設定
		g_buffer[i].AudioBytes = dwChunkSize;
		g_buffer[i].pAudioData = g_DataBuffer[i];
		g_buffer[i].Flags = XAUDIO2_END_OF_STREAM;
		
		if (paramObj[i].loop)
			g_buffer[i].LoopCount = XAUDIO2_LOOP_INFINITE;
		else
			g_buffer[i].LoopCount = 0;

		//ソース音声を作る
		g_pXAudio2->CreateSourceVoice(&g_pSourceVoice[i], &(g_wfx[i].Format));
	}

	return hr;
}

//音声シャットダウン関数
void SoundClass::Shutdown()
{
	for (int i = 0; i < SOUNDFILEMAX; i++)
	{
		if (g_pSourceVoice[i])
		{
			g_pSourceVoice[i]->Stop(0);
			g_pSourceVoice[i]->FlushSourceBuffers();
			g_pSourceVoice[i]->DestroyVoice();		//ソースボイスを削除
			delete[] g_DataBuffer[i];
		}
	}

	//MasteringVoiceを削除
	g_pMasteringVoice->DestroyVoice();

	//XAudio2オブジェクトがあったら
	if (g_pXAudio2)
	{
		g_pXAudio2->Release();	//削除
	}

	CoUninitialize();
}

//再生
void SoundClass::Play(SOUNDLABEL label)
{
	//ソースボイス作成
	g_pXAudio2->CreateSourceVoice(&(g_pSourceVoice[(int)label]), &(g_wfx[(int)label].Format));
	g_pSourceVoice[(int)label]->SubmitSourceBuffer(&(g_buffer[(int)label]));

	//再生
	g_pSourceVoice[(int)label]->Start(0);
}

//一時停止
void SoundClass::Pause(SOUNDLABEL label)
{

}

//停止
void SoundClass::Stop(SOUNDLABEL label)
{
	if (g_pSourceVoice[(int)label] == NULL)
		return;

	XAUDIO2_VOICE_STATE xa2state;
	g_pSourceVoice[(int)label]->GetState(&xa2state);
	if (xa2state.BuffersQueued)
		g_pSourceVoice[(int)label]->Stop(0);
}

//////////////////////////////
//この下は気にしなくてもいいです//
/////////////////////////////

HRESULT FindChunk(HANDLE hFile, DWORD fourcc, DWORD & dwChunkSize, DWORD & dwChunkDataPosition)
{
	HRESULT hr = S_OK;
	if (INVALID_SET_FILE_POINTER == SetFilePointer(hFile, 0, NULL, FILE_BEGIN))
		return HRESULT_FROM_WIN32(GetLastError());
	DWORD dwChunkType;
	DWORD dwChunkDataSize;
	DWORD dwRIFFDataSize = 0;
	DWORD dwFileType;
	DWORD bytesRead = 0;
	DWORD dwOffset = 0;
	while (hr == S_OK)
	{
		DWORD dwRead;
		if (0 == ReadFile(hFile, &dwChunkType, sizeof(DWORD), &dwRead, NULL))
			hr = HRESULT_FROM_WIN32(GetLastError());
		if (0 == ReadFile(hFile, &dwChunkDataSize, sizeof(DWORD), &dwRead, NULL))
			hr = HRESULT_FROM_WIN32(GetLastError());
		
		switch (dwChunkType)
		{
		case fourccRIFF:
			dwRIFFDataSize = dwChunkDataSize;
			dwChunkDataSize = 4;
			if (0 == ReadFile(hFile, &dwFileType, sizeof(DWORD), &dwRead, NULL))
				hr = HRESULT_FROM_WIN32(GetLastError());
			break;

		default:
			if (INVALID_SET_FILE_POINTER == SetFilePointer(hFile, dwChunkDataSize, NULL, FILE_CURRENT))
				return HRESULT_FROM_WIN32(GetLastError());
		}

		dwOffset += sizeof(DWORD) * 2;
		
		if (dwChunkType == fourcc)
		{
			dwChunkSize = dwChunkDataSize;
			dwChunkDataPosition = dwOffset;
			return S_OK;
		}

		dwOffset += dwChunkDataSize;
		if (bytesRead >= dwRIFFDataSize)
			return S_FALSE;
	}

	return S_OK;
}

HRESULT ReadChunkData(HANDLE hFile, void * buffer, DWORD buffersize, DWORD bufferoffset)
{
	HRESULT hr = S_OK;

	if (INVALID_SET_FILE_POINTER == SetFilePointer(hFile, bufferoffset, NULL, FILE_BEGIN))
		return HRESULT_FROM_WIN32(GetLastError());

	DWORD dwRead;

	if (0 == ReadFile(hFile, buffer, buffersize, &dwRead, NULL))
		hr = HRESULT_FROM_WIN32(GetLastError());

	return hr;
}