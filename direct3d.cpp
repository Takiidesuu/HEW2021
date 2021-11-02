//*****************************************************************************
// DX21�@�T���v���\�[�X
// Direct3D�̋��ʏ���
// ���̃\�[�X�̓��e�͊�{�I�ɕύX����K�v�͂Ȃ����A
// �����Ǝ��̉������������ꍇ�͎��R�ɕύX���Ă��悢�B
//*****************************************************************************

#include "direct3d.h"
#include "directxtex/include/WICTextureLoader.h"
#include <locale.h>

// ���C�u�����̃����N���w�肷��v���v���Z�b�T����
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")	

// ****************************************
// �v���v���Z�b�T�萔�E�}�N����`
// ****************************************

// ���s����PC�ɂ���ĉ��̃p�^�[����1�܂���2�Ŏ����B2�̕����T�|�[�g���������H
#define DIRECT3D_INIT_PATTERN  2

// ****************************************
// �O���[�o���ϐ��錾
// ****************************************

static ID3D11Device*           gpD3d11Device;
static ID3D11DeviceContext*    gpImmediateContext;
static IDXGISwapChain*         gpSwapChain;
static ID3D11RenderTargetView* gpRenderTargetView;
static ID3D11Texture2D*        gpDepthStencilTexture;
static ID3D11DepthStencilView* gpDepthStencilView;
static ID3D11InputLayout*      gpInputLayout;
static ID3D11VertexShader*     gpVertexShader;
static ID3D11PixelShader*      gpPixelShader;
static ID3D11SamplerState*     gpSampler;
static ID3D11BlendState*	   gpBlendAlphaEnable;

static UINT gScreenWidth;
static UINT gScreenHeight;

#include "vs.h"
#include "ps.h"



// Direct3D11 Device*��Ԃ�
ID3D11Device* Direct3D_GetDevice() {
	return gpD3d11Device;
}


// Direct3D11 Immidiate Context*��Ԃ�
ID3D11DeviceContext* Direct3D_GetContext() {
	return gpImmediateContext;
}


// Direct3D11 SwapChain*��Ԃ�
IDXGISwapChain * Direct3D_GetSwapChain()
{
	return gpSwapChain;
}


// Direct3D11 RenderTargetView*��Ԃ�
ID3D11RenderTargetView * Direct3D_GetRenderTargetView()
{
	return gpRenderTargetView;
}


// DirextX11�̏�������S������֐��i�̒�`�j
// ���@���̊֐��̒��̏��������������s���邱�ƂŁADirectX11���g����悤�ɂȂ�B
// �֐��̒�`�@���@���̖��O�̊֐��́A���ł����������������܂��Ƃ����̂���������
HRESULT Direct3D_Initialize(HWND hWnd) {
	HRESULT  hr;

	D3D_FEATURE_LEVEL level;
	RECT                rect;

	GetClientRect(hWnd, &rect);
	gScreenWidth = (UINT)(rect.right - rect.left);
	gScreenHeight = (UINT)(rect.bottom - rect.top);

#if DIRECT3D_INIT_PATTERN==1
	// DirectX11�f�o�C�X�̍쐬�@���f�o�C�X��DirectX11�̗l�X�ȋ@�\���Ăяo�����߂̃I�u�W�F�N�g
	UINT flags = 0;
#ifdef _DEBUG
	flags |= D3D11_CREATE_DEVICE_DEBUG;
#endif
	D3D_FEATURE_LEVEL pLevels[] = { D3D_FEATURE_LEVEL_11_0 };


	DXGI_SWAP_CHAIN_DESC scDesc;


	ZeroMemory(&scDesc, sizeof(scDesc));



	scDesc.BufferCount = 1;
	scDesc.BufferDesc.Width = gScreenWidth;
	scDesc.BufferDesc.Height = gScreenHeight;
	scDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	scDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	scDesc.OutputWindow = hWnd;
	scDesc.SampleDesc.Count = 1;
	scDesc.SampleDesc.Quality = 0;
	scDesc.Windowed = TRUE;

	// DirectX11�f�o�C�X�̍쐬�@���f�o�C�X��DirectX11�̗l�X�ȋ@�\���Ăяo�����߂̃I�u�W�F�N�g
	hr = D3D11CreateDeviceAndSwapChain(NULL,
		D3D_DRIVER_TYPE_HARDWARE,
		NULL,
		flags,
		pLevels,
		1,
		D3D11_SDK_VERSION,
		&scDesc,
		&gpSwapChain,
		&gpD3d11Device,
		&level,
		&gpImmediateContext);

	if (FAILED(hr))
		return hr;

#elif DIRECT3D_INIT_PATTERN==2

	IDXGIFactory* factory;				// factory
	IDXGIAdapter* adapter;				// videocard
	IDXGIOutput* adapterOutput;			// monitor
	unsigned int numModes;
	unsigned int numerator = 60;			// ���q
	unsigned int denominator = 1;			// ����
	DXGI_MODE_DESC* displayModeList;
	//	D3D11_BLEND_DESC blendStateDescription;

	//	gScreenWidth = Width;
	//	gScreenHeight = Height;

		// �h���C�o�̎��
	D3D_DRIVER_TYPE driverTypes[] =
	{
		D3D_DRIVER_TYPE_HARDWARE,
		D3D_DRIVER_TYPE_WARP,					// Windows Advanced Rasterizer
		D3D_DRIVER_TYPE_REFERENCE,
		D3D_DRIVER_TYPE_SOFTWARE,
	};
	unsigned int numDriverTypes = ARRAYSIZE(driverTypes);

	unsigned int createDeviceFlags = 0;
	//   createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;

	   // �@�\���x��
	D3D_FEATURE_LEVEL featureLevels[] =
	{
		D3D_FEATURE_LEVEL_11_1,					// DirectX11.1�Ή�GPU���x��
		D3D_FEATURE_LEVEL_11_0,					// DirectX11�Ή�GPU���x��
		D3D_FEATURE_LEVEL_10_1,					// DirectX10.1�Ή�GPU���x��
		D3D_FEATURE_LEVEL_10_0,					// DirectX10�Ή�GPU���x��
		D3D_FEATURE_LEVEL_9_3,					// DirectX9.3�Ή�GPU���x��
		D3D_FEATURE_LEVEL_9_2,					// DirectX9.2�Ή�GPU���x��
		D3D_FEATURE_LEVEL_9_1					// Direct9.1�Ή�GPU���x��
	};
	UINT numFeatureLevels = ARRAYSIZE(featureLevels);

	// Create a DirectX graphics interface factory
	hr = CreateDXGIFactory(__uuidof(IDXGIFactory), (void**)&factory);
	if (FAILED(hr)) {
		return hr;
	}

	// use the factory to create an adpter for the primary graphics interface(video card)
	hr = factory->EnumAdapters(0, &adapter);
	if (FAILED(hr)) {
		return hr;
	}

	// enumerrate primary adapter output(monitor)
	hr = adapter->EnumOutputs(0, &adapterOutput);
	if (FAILED(hr)) {
		return hr;
	}

	// get the number of modes that fit the DXGI_FORMAT_R8G8B8_UNORM display format forthe adapter output(monitor)
	hr = adapterOutput->GetDisplayModeList(DXGI_FORMAT_R8G8B8A8_UNORM, DXGI_ENUM_MODES_INTERLACED, &numModes, NULL);
	if (FAILED(hr)) {
		return hr;
	}

	// create alist to hold all possible display modes for this monitor/video card combination
	displayModeList = new DXGI_MODE_DESC[numModes];
	if (!displayModeList) {
		return E_FAIL;
	}

	// now fill the display mode list structures
	hr = adapterOutput->GetDisplayModeList(DXGI_FORMAT_R8G8B8A8_UNORM, DXGI_ENUM_MODES_INTERLACED, &numModes, displayModeList);
	if (FAILED(hr)) {
		return hr;
	}

	// now go through all the display modes and find the one that matches the screen width and height
	// when a match is found store the numerator and denominator of the refresh rate for that monitor
	for (unsigned int i = 0; i < numModes; i++) {
		if (displayModeList[i].Width == gScreenWidth) {
			if (displayModeList[i].Height == gScreenHeight) {
				numerator = displayModeList[i].RefreshRate.Numerator;
				denominator = displayModeList[i].RefreshRate.Denominator;
			}
		}
	}

	delete[] displayModeList;
	displayModeList = NULL;

	adapterOutput->Release();
	adapterOutput = NULL;

	adapter->Release();
	adapter = NULL;

	factory->Release();
	factory = NULL;

	// �X���b�v�`�F�C���̐ݒ�
	// �X���b�v�`�F�C���Ƃ́A�E�C���h�E�ւ̕\���_�u���o�b�t�@���Ǘ�����
	// �N���X�@�}���`�T���v�����O�A���t���b�V�����[�g���ݒ�ł���
	DXGI_SWAP_CHAIN_DESC sd;
	ZeroMemory(&sd, sizeof(sd));					// �[���N���A
	sd.BufferCount = 1;									// �o�b�N�o�b�t�@�̐�
	sd.BufferDesc.Width = gScreenWidth;						// �o�b�N�o�b�t�@�̕�
	sd.BufferDesc.Height = gScreenHeight;						// �o�b�N�o�b�t�@�̍���
	sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;	// �o�b�N�o�b�t�@�t�H�[�}�b�g(R,G,B �͈͂O�D�O����P�D�O)
	sd.BufferDesc.RefreshRate.Numerator = numerator;			// ���t���b�V�����[�g�i����j
	sd.BufferDesc.RefreshRate.Denominator = denominator;			// ���t���b�V�����[�g�i���q�j
	sd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	sd.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;	// �o�b�N�o�b�t�@�̎g�p���@
	sd.OutputWindow = hWnd;			// �֘A�t����E�C���h�E
	sd.SampleDesc.Count = 1;		// �}���`�T���v���̐�
	sd.SampleDesc.Quality = 0;		// �}���`�T���v���̃N�I���e�B
	sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

	// �E�C���h�E���[�h�E�t���X�N���[�����[�h�ؑ֗p�B
	// �O���[�o���ϐ��ɂ���Ȃǂ��āA���I�ɐ؂�ւ�����悤�ɂ���̂��ǂ��B
	BOOL fullscreen = FALSE;

	if (fullscreen) {
		sd.Windowed = FALSE;				// �E�C���h�E���[�h
	}
	else {
		sd.Windowed = TRUE;				// �E�C���h�E���[�h
	}
	sd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;		// ���[�h�̎����؂�ւ�

	for (UINT driverTypeIndex = 0; driverTypeIndex < numDriverTypes; driverTypeIndex++)
	{
		//m_DriverType = driverTypes[driverTypeIndex];
		hr = D3D11CreateDeviceAndSwapChain(NULL,				// �f�B�X�v���C�f�o�C�X�̃A�_�v�^�i�m�t�k�k�̏ꍇ�ŏ��Ɍ��������A�_�v�^�j
			driverTypes[driverTypeIndex],		// �f�o�C�X�h���C�o�̃^�C�v
			NULL,				// �\�t�g�E�F�A���X�^���C�U���g�p����ꍇ�Ɏw�肷��
			createDeviceFlags,	// �f�o�C�X�t���O
			featureLevels,		// �@�\���x��
			numFeatureLevels,	// �@�\���x����
			D3D11_SDK_VERSION,	// 
			&sd,				// �X���b�v�`�F�C���̐ݒ�
			&gpSwapChain,		// IDXGIDwapChain�C���^�t�F�[�X	
			&gpD3d11Device,		// ID3D11Device�C���^�t�F�[�X
			&level,	// �T�|�[�g����Ă���@�\���x��
			&gpImmediateContext);	// �f�o�C�X�R���e�L�X�g
		if (SUCCEEDED(hr))
			break;
	}
	if (FAILED(hr)) {
		return hr;
	}

#endif

	// �o�b�N�o�b�t�@�֌W�̐ݒ菈��
	ID3D11Texture2D* pBackBuffer;

	hr = Direct3D_GetSwapChain()->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);

	if (FAILED(hr))
		return hr;

	hr = Direct3D_GetDevice()->CreateRenderTargetView(pBackBuffer, NULL, &gpRenderTargetView);
	pBackBuffer->Release();

	if (FAILED(hr))
		return hr;

	//�[�x�X�e���V���o�b�t�@�쐬
	D3D11_TEXTURE2D_DESC txDesc;

	ZeroMemory(&txDesc, sizeof(txDesc));
	txDesc.Width = gScreenWidth;
	txDesc.Height = gScreenHeight;
	txDesc.MipLevels = 1;
	txDesc.ArraySize = 1;
	txDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
	txDesc.SampleDesc.Count = 1;
	txDesc.SampleDesc.Quality = 0;
	txDesc.Usage = D3D11_USAGE_DEFAULT;
	txDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;
	txDesc.CPUAccessFlags = 0;
	txDesc.MiscFlags = 0;

	hr = Direct3D_GetDevice()->CreateTexture2D(&txDesc, NULL, &gpDepthStencilTexture);

	if (SUCCEEDED(hr)) {
		D3D11_DEPTH_STENCIL_VIEW_DESC dsDesc;
		ZeroMemory(&dsDesc, sizeof(dsDesc));
		dsDesc.Format = txDesc.Format;
		dsDesc.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
		dsDesc.Texture2D.MipSlice = 0;
		hr = Direct3D_GetDevice()->CreateDepthStencilView(gpDepthStencilTexture, &dsDesc, &gpDepthStencilView);
	}

	if (FAILED(hr))
		return hr;
	
	// �����_�����O�^�[�Q�b�g��ݒ�@�i���j����2D�Ȃ̂�Z�o�b�t�@�����ɂ��Ă���
	Direct3D_GetContext()->OMSetRenderTargets(1, &gpRenderTargetView, /*dx->pDepthStencilView*/NULL);

	//���_�V�F�[�_�[����
	hr = Direct3D_GetDevice()->CreateVertexShader(&g_vs_main, sizeof(g_vs_main), NULL, &gpVertexShader);
	
	if (FAILED(hr))
		return hr;

	//�s�N�Z���V�F�[�_�[����
	hr = Direct3D_GetDevice()->CreatePixelShader(&g_ps_main, sizeof(g_ps_main), NULL, &gpPixelShader);
	
	if (FAILED(hr))
		return hr;

	//���_���C�A�E�g�쐬
	D3D11_INPUT_ELEMENT_DESC vertexDesc[] = {
	 { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	 { "COLOR",    0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	 { "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	};

	//���_���C�A�E�g�쐬
	hr = Direct3D_GetDevice()->CreateInputLayout(vertexDesc, ARRAYSIZE(vertexDesc),
		g_vs_main, sizeof(g_vs_main), &gpInputLayout);

	if (FAILED(hr))
		return hr;

	//�r���[�|�[�g�ݒ�
	D3D11_VIEWPORT viewport;
	viewport.TopLeftX = 0;
	viewport.TopLeftY = 0;
	viewport.Width = (FLOAT)gScreenWidth;
	viewport.Height = (FLOAT)gScreenHeight;
	viewport.MinDepth = 0.0f;
	viewport.MaxDepth = 1.0f;

	Direct3D_GetContext()->RSSetViewports(1, &viewport);

	// �e�N�X�`���E�T���v���[�̍쐬
	D3D11_SAMPLER_DESC smpDesc;

	ZeroMemory(&smpDesc, sizeof(D3D11_SAMPLER_DESC));
	smpDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_POINT;
	smpDesc.AddressU = D3D11_TEXTURE_ADDRESS_BORDER;
	smpDesc.AddressV = D3D11_TEXTURE_ADDRESS_BORDER;
	smpDesc.AddressW = D3D11_TEXTURE_ADDRESS_BORDER;

	hr = Direct3D_GetDevice()->CreateSamplerState(&smpDesc, &gpSampler);

	if (FAILED(hr))
		return hr;

	// ���_�V�F�[�_�[�̃p�����[�^�Z�b�g
	Direct3D_GetContext()->VSSetShader(gpVertexShader, NULL, 0);

	// �s�N�Z���V�F�[�_�[�̃p�����[�^�Z�b�g
	Direct3D_GetContext()->PSSetShader(gpPixelShader, NULL, 0);
	Direct3D_GetContext()->PSSetSamplers(0, 1, &gpSampler);

	// ���_���C�A�E�g�ƃv���~�e�B�u�^�C�v���Z�b�g
	Direct3D_GetContext()->IASetInputLayout(gpInputLayout);
	Direct3D_GetContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	// �u�����h�X�e�[�g�ݒ�
	D3D11_BLEND_DESC BlendDesc;

	// �e�N�X�`�����ߏ������s����悤�ɐݒ�
	ZeroMemory(&BlendDesc, sizeof(BlendDesc));
	BlendDesc.AlphaToCoverageEnable = FALSE;
	BlendDesc.IndependentBlendEnable = FALSE;
	BlendDesc.RenderTarget[0].BlendEnable = TRUE;
	BlendDesc.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;
	BlendDesc.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
	BlendDesc.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;
	BlendDesc.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ZERO;
	BlendDesc.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ONE;
	BlendDesc.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;
	BlendDesc.RenderTarget[0].RenderTargetWriteMask = 0x0f;

	float blendFactor[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
	hr = Direct3D_GetDevice()->CreateBlendState(&BlendDesc, &gpBlendAlphaEnable);

	if (SUCCEEDED(hr)) {
		Direct3D_GetContext()->OMSetBlendState(gpBlendAlphaEnable, blendFactor, 0xffffffff);
	}

	if (FAILED(hr))
		return hr;

	return hr;
}


// Direct3D�֘A�ō쐬�����I�u�W�F�N�g�����ׂĊJ������
void Direct3D_Release()
{
	COM_SAFE_RELEASE(gpBlendAlphaEnable);
	COM_SAFE_RELEASE(gpSwapChain);
	COM_SAFE_RELEASE(gpRenderTargetView);
	COM_SAFE_RELEASE(gpDepthStencilTexture);
	COM_SAFE_RELEASE(gpDepthStencilView);
	COM_SAFE_RELEASE(gpInputLayout);
	COM_SAFE_RELEASE(gpVertexShader);
	COM_SAFE_RELEASE(gpPixelShader);
	COM_SAFE_RELEASE(gpSampler);
	COM_SAFE_RELEASE(gpImmediateContext);
	COM_SAFE_RELEASE(gpD3d11Device);
}

HRESULT Direct3D_LoadTexture(const char * pFileName, ID3D11ShaderResourceView ** pOupSRV)
{
	wchar_t wc_path[256];

	char* localeInfo = setlocale(LC_ALL, "Japanese_Japan.932");
	mbstowcs_s(NULL, wc_path, 256, pFileName, 255);

	return DirectX::CreateWICTextureFromFile(
		Direct3D_GetDevice(),
		wc_path,
		NULL,
		pOupSRV);
}
