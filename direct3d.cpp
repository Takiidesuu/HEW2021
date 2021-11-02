//*****************************************************************************
// DX21　サンプルソース
// Direct3Dの共通処理
// このソースの内容は基本的に変更する必要はないが、
// もし独自の改造をしたい場合は自由に変更してもよい。
//*****************************************************************************

#include "direct3d.h"
#include "directxtex/include/WICTextureLoader.h"
#include <locale.h>

// ライブラリのリンクを指定するプリプロセッサ命令
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")	

// ****************************************
// プリプロセッサ定数・マクロ定義
// ****************************************

// 実行するPCによって下のパターンを1または2で試す。2の方がサポート率が高い？
#define DIRECT3D_INIT_PATTERN  2

// ****************************************
// グローバル変数宣言
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



// Direct3D11 Device*を返す
ID3D11Device* Direct3D_GetDevice() {
	return gpD3d11Device;
}


// Direct3D11 Immidiate Context*を返す
ID3D11DeviceContext* Direct3D_GetContext() {
	return gpImmediateContext;
}


// Direct3D11 SwapChain*を返す
IDXGISwapChain * Direct3D_GetSwapChain()
{
	return gpSwapChain;
}


// Direct3D11 RenderTargetView*を返す
ID3D11RenderTargetView * Direct3D_GetRenderTargetView()
{
	return gpRenderTargetView;
}


// DirextX11の初期化を担当する関数（の定義）
// →　この関数の中の初期化処理を実行することで、DirectX11が使えるようになる。
// 関数の定義　→　この名前の関数は、中でこういう処理をしますというのを書くこと
HRESULT Direct3D_Initialize(HWND hWnd) {
	HRESULT  hr;

	D3D_FEATURE_LEVEL level;
	RECT                rect;

	GetClientRect(hWnd, &rect);
	gScreenWidth = (UINT)(rect.right - rect.left);
	gScreenHeight = (UINT)(rect.bottom - rect.top);

#if DIRECT3D_INIT_PATTERN==1
	// DirectX11デバイスの作成　※デバイスはDirectX11の様々な機能を呼び出すためのオブジェクト
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

	// DirectX11デバイスの作成　※デバイスはDirectX11の様々な機能を呼び出すためのオブジェクト
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
	unsigned int numerator = 60;			// 分子
	unsigned int denominator = 1;			// 分母
	DXGI_MODE_DESC* displayModeList;
	//	D3D11_BLEND_DESC blendStateDescription;

	//	gScreenWidth = Width;
	//	gScreenHeight = Height;

		// ドライバの種類
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

	   // 機能レベル
	D3D_FEATURE_LEVEL featureLevels[] =
	{
		D3D_FEATURE_LEVEL_11_1,					// DirectX11.1対応GPUレベル
		D3D_FEATURE_LEVEL_11_0,					// DirectX11対応GPUレベル
		D3D_FEATURE_LEVEL_10_1,					// DirectX10.1対応GPUレベル
		D3D_FEATURE_LEVEL_10_0,					// DirectX10対応GPUレベル
		D3D_FEATURE_LEVEL_9_3,					// DirectX9.3対応GPUレベル
		D3D_FEATURE_LEVEL_9_2,					// DirectX9.2対応GPUレベル
		D3D_FEATURE_LEVEL_9_1					// Direct9.1対応GPUレベル
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

	// スワップチェインの設定
	// スワップチェインとは、ウインドウへの表示ダブルバッファを管理する
	// クラス　マルチサンプリング、リフレッシュレートが設定できる
	DXGI_SWAP_CHAIN_DESC sd;
	ZeroMemory(&sd, sizeof(sd));					// ゼロクリア
	sd.BufferCount = 1;									// バックバッファの数
	sd.BufferDesc.Width = gScreenWidth;						// バックバッファの幅
	sd.BufferDesc.Height = gScreenHeight;						// バックバッファの高さ
	sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;	// バックバッファフォーマット(R,G,B 範囲０．０から１．０)
	sd.BufferDesc.RefreshRate.Numerator = numerator;			// リフレッシュレート（分母）
	sd.BufferDesc.RefreshRate.Denominator = denominator;			// リフレッシュレート（分子）
	sd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	sd.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;	// バックバッファの使用方法
	sd.OutputWindow = hWnd;			// 関連付けるウインドウ
	sd.SampleDesc.Count = 1;		// マルチサンプルの数
	sd.SampleDesc.Quality = 0;		// マルチサンプルのクオリティ
	sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

	// ウインドウモード・フルスクリーンモード切替用。
	// グローバル変数にするなどして、動的に切り替えられるようにするのも良い。
	BOOL fullscreen = FALSE;

	if (fullscreen) {
		sd.Windowed = FALSE;				// ウインドウモード
	}
	else {
		sd.Windowed = TRUE;				// ウインドウモード
	}
	sd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;		// モードの自動切り替え

	for (UINT driverTypeIndex = 0; driverTypeIndex < numDriverTypes; driverTypeIndex++)
	{
		//m_DriverType = driverTypes[driverTypeIndex];
		hr = D3D11CreateDeviceAndSwapChain(NULL,				// ディスプレイデバイスのアダプタ（ＮＵＬＬの場合最初に見つかったアダプタ）
			driverTypes[driverTypeIndex],		// デバイスドライバのタイプ
			NULL,				// ソフトウェアラスタライザを使用する場合に指定する
			createDeviceFlags,	// デバイスフラグ
			featureLevels,		// 機能レベル
			numFeatureLevels,	// 機能レベル数
			D3D11_SDK_VERSION,	// 
			&sd,				// スワップチェインの設定
			&gpSwapChain,		// IDXGIDwapChainインタフェース	
			&gpD3d11Device,		// ID3D11Deviceインタフェース
			&level,	// サポートされている機能レベル
			&gpImmediateContext);	// デバイスコンテキスト
		if (SUCCEEDED(hr))
			break;
	}
	if (FAILED(hr)) {
		return hr;
	}

#endif

	// バックバッファ関係の設定処理
	ID3D11Texture2D* pBackBuffer;

	hr = Direct3D_GetSwapChain()->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);

	if (FAILED(hr))
		return hr;

	hr = Direct3D_GetDevice()->CreateRenderTargetView(pBackBuffer, NULL, &gpRenderTargetView);
	pBackBuffer->Release();

	if (FAILED(hr))
		return hr;

	//深度ステンシルバッファ作成
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
	
	// レンダリングターゲットを設定　（注）今は2DなのでZバッファ無効にしておく
	Direct3D_GetContext()->OMSetRenderTargets(1, &gpRenderTargetView, /*dx->pDepthStencilView*/NULL);

	//頂点シェーダー生成
	hr = Direct3D_GetDevice()->CreateVertexShader(&g_vs_main, sizeof(g_vs_main), NULL, &gpVertexShader);
	
	if (FAILED(hr))
		return hr;

	//ピクセルシェーダー生成
	hr = Direct3D_GetDevice()->CreatePixelShader(&g_ps_main, sizeof(g_ps_main), NULL, &gpPixelShader);
	
	if (FAILED(hr))
		return hr;

	//頂点レイアウト作成
	D3D11_INPUT_ELEMENT_DESC vertexDesc[] = {
	 { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	 { "COLOR",    0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	 { "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	};

	//頂点レイアウト作成
	hr = Direct3D_GetDevice()->CreateInputLayout(vertexDesc, ARRAYSIZE(vertexDesc),
		g_vs_main, sizeof(g_vs_main), &gpInputLayout);

	if (FAILED(hr))
		return hr;

	//ビューポート設定
	D3D11_VIEWPORT viewport;
	viewport.TopLeftX = 0;
	viewport.TopLeftY = 0;
	viewport.Width = (FLOAT)gScreenWidth;
	viewport.Height = (FLOAT)gScreenHeight;
	viewport.MinDepth = 0.0f;
	viewport.MaxDepth = 1.0f;

	Direct3D_GetContext()->RSSetViewports(1, &viewport);

	// テクスチャ・サンプラーの作成
	D3D11_SAMPLER_DESC smpDesc;

	ZeroMemory(&smpDesc, sizeof(D3D11_SAMPLER_DESC));
	smpDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_POINT;
	smpDesc.AddressU = D3D11_TEXTURE_ADDRESS_BORDER;
	smpDesc.AddressV = D3D11_TEXTURE_ADDRESS_BORDER;
	smpDesc.AddressW = D3D11_TEXTURE_ADDRESS_BORDER;

	hr = Direct3D_GetDevice()->CreateSamplerState(&smpDesc, &gpSampler);

	if (FAILED(hr))
		return hr;

	// 頂点シェーダーのパラメータセット
	Direct3D_GetContext()->VSSetShader(gpVertexShader, NULL, 0);

	// ピクセルシェーダーのパラメータセット
	Direct3D_GetContext()->PSSetShader(gpPixelShader, NULL, 0);
	Direct3D_GetContext()->PSSetSamplers(0, 1, &gpSampler);

	// 頂点レイアウトとプリミティブタイプをセット
	Direct3D_GetContext()->IASetInputLayout(gpInputLayout);
	Direct3D_GetContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	// ブレンドステート設定
	D3D11_BLEND_DESC BlendDesc;

	// テクスチャ透過処理が行われるように設定
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


// Direct3D関連で作成したオブジェクトをすべて開放する
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
