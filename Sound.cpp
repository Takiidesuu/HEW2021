#include "Sound.h"

typedef struct
{
	LPCSTR filename;	//�t�@�C�����i�p�X�j
	bool loop;			//���[�v�����邩
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

WAVEFORMATEXTENSIBLE g_wfx[SOUNDFILEMAX];			//WAV�t�H�[�}�b�g
XAUDIO2_BUFFER g_buffer[SOUNDFILEMAX];
BYTE *g_DataBuffer[SOUNDFILEMAX];

HRESULT FindChunk(HANDLE, DWORD, DWORD&, DWORD&);
HRESULT ReadChunkData(HANDLE, void*, DWORD, DWORD);

//������
HRESULT SoundClass::Init()
{
	HRESULT hr;

	HANDLE hFile;
	DWORD dwChunkSize;
	DWORD dwChunkPosition;
	DWORD filetype;

	//COM�̏�����
	CoInitializeEx(NULL, COINIT_MULTITHREADED);

	//XAudio�I�u�W�F�N�g�����
	hr = XAudio2Create(&g_pXAudio2, 0);

	//���s
	if (FAILED(hr))
	{
		CoUninitialize();	//���
		return -1;
	}

	//MasteringVoice�i�������o����悤�ɂ��Ă����j�I�u�W�F�N�g�����
	hr = g_pXAudio2->CreateMasteringVoice(&g_pMasteringVoice);

	//���s
	if (FAILED(hr))
	{
		if (g_pXAudio2)	//XAudio2�̃I�u�W�F�N�g����������
			g_pXAudio2->Release();	//����
		CoUninitialize();
		return -1;
	}

	//���ꂼ��̉����t�@�C����������
	for (int i = 0; i < SOUNDFILEMAX; i++)
	{
		memset(&g_wfx[i], 0, sizeof(WAVEFORMATEXTENSIBLE));
		memset(&g_buffer[i], 0, sizeof(XAUDIO2_BUFFER));

		hFile = CreateFileA(paramObj[i].filename, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);

		if (hFile == INVALID_HANDLE_VALUE)
			return HRESULT_FROM_WIN32(GetLastError());
		if (SetFilePointer(hFile, 0, NULL, FILE_BEGIN) == INVALID_SET_FILE_POINTER)
			return HRESULT_FROM_WIN32(GetLastError());

		//�t�@�C���^�C�v���`�F�b�N����
		FindChunk(hFile, fourccRIFF, dwChunkSize, dwChunkPosition);
		ReadChunkData(hFile, &filetype, sizeof(DWORD), dwChunkPosition);

		if (filetype != fourccWAVE)
			return S_FALSE;

		FindChunk(hFile, fourccFMT, dwChunkSize, dwChunkPosition);
		ReadChunkData(hFile, &g_wfx[i], dwChunkSize, dwChunkPosition);

		//�����f�[�^�o�b�t�@��fourccDATA�`�����N������
		FindChunk(hFile, fourccDATA, dwChunkSize, dwChunkPosition);
		g_DataBuffer[i] = new BYTE[dwChunkSize];
		ReadChunkData(hFile, g_DataBuffer[i], dwChunkSize, dwChunkPosition);

		CloseHandle(hFile);

		//�T�u�~�b�g�{�C�X�ŗ��p����T�u�~�b�g�o�b�t�@�̐ݒ�
		g_buffer[i].AudioBytes = dwChunkSize;
		g_buffer[i].pAudioData = g_DataBuffer[i];
		g_buffer[i].Flags = XAUDIO2_END_OF_STREAM;
		
		if (paramObj[i].loop)
			g_buffer[i].LoopCount = XAUDIO2_LOOP_INFINITE;
		else
			g_buffer[i].LoopCount = 0;

		//�\�[�X���������
		g_pXAudio2->CreateSourceVoice(&g_pSourceVoice[i], &(g_wfx[i].Format));
	}

	return hr;
}

//�����V���b�g�_�E���֐�
void SoundClass::Shutdown()
{
	for (int i = 0; i < SOUNDFILEMAX; i++)
	{
		if (g_pSourceVoice[i])
		{
			g_pSourceVoice[i]->Stop(0);
			g_pSourceVoice[i]->FlushSourceBuffers();
			g_pSourceVoice[i]->DestroyVoice();		//�\�[�X�{�C�X���폜
			delete[] g_DataBuffer[i];
		}
	}

	//MasteringVoice���폜
	g_pMasteringVoice->DestroyVoice();

	//XAudio2�I�u�W�F�N�g����������
	if (g_pXAudio2)
	{
		g_pXAudio2->Release();	//�폜
	}

	CoUninitialize();
}

//�Đ�
void SoundClass::Play(SOUNDLABEL label)
{
	//�\�[�X�{�C�X�쐬
	g_pXAudio2->CreateSourceVoice(&(g_pSourceVoice[(int)label]), &(g_wfx[(int)label].Format));
	g_pSourceVoice[(int)label]->SubmitSourceBuffer(&(g_buffer[(int)label]));

	//�Đ�
	g_pSourceVoice[(int)label]->Start(0);
}

//�ꎞ��~
void SoundClass::Pause(SOUNDLABEL label)
{

}

//��~
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
//���̉��͋C�ɂ��Ȃ��Ă������ł�//
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