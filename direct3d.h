#pragma once

//*****************************************************************************
// DX21�@�T���v���\�[�X
// Direct3D�ɋ��ʂ��鏈���ŁA�A�v������Ăяo���K�v�̂���֐��Ȃǂ�
// �v���g�^�C�v�錾���L�q���Ă���B
// �����Ńv���g�^�C�v�錾���ꂽ�֐����Ăяo���āADirect3D���g���Ă����B
//*****************************************************************************

#include <d3d11.h>	// �}�C�N���\�t�g�񋟂�DirectX11�w�b�_�[�t�@�C�����C���N���[�h


// ****************************************
// �v���v���Z�b�T�萔�E�}�N����`
// ****************************************

// COM�I�u�W�F�N�g��NULL�`�F�b�N���Ă���Release����
#define COM_SAFE_RELEASE(o)   if(NULL!=o){o->Release();o=NULL;}


// ****************************************
// ���J����֐��̃v���g�^�C�v�錾
// ****************************************

// Direct3D11 Device*��Ԃ�
ID3D11Device* Direct3D_GetDevice();

// Direct3D11 Immidiate Context*��Ԃ�
ID3D11DeviceContext* Direct3D_GetContext();

// Direct3D11 SwapChain*��Ԃ�
IDXGISwapChain* Direct3D_GetSwapChain();

// Direct3D11 RenderTargetView*��Ԃ�
ID3D11RenderTargetView* Direct3D_GetRenderTargetView();



// DirextX11�̏�������S������֐��i�̒�`�j
HRESULT Direct3D_Initialize(HWND hWnd);

// Direct3D�֘A�ō쐬�����I�u�W�F�N�g�����ׂĊJ������
void Direct3D_Release();

// �w�肵���t�@�C�����̃e�N�X�`���t�@�C���i�摜�t�@�C���j��ǂݍ���
HRESULT Direct3D_LoadTexture(const char* pFileName, ID3D11ShaderResourceView** pOupSRV);

