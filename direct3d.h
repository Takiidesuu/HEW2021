#pragma once

//*****************************************************************************
// DX21　サンプルソース
// Direct3Dに共通する処理で、アプリから呼び出す必要のある関数などの
// プロトタイプ宣言を記述している。
// ここでプロトタイプ宣言された関数を呼び出して、Direct3Dを使っていく。
//*****************************************************************************

#include <d3d11.h>	// マイクロソフト提供のDirectX11ヘッダーファイルをインクルード


// ****************************************
// プリプロセッサ定数・マクロ定義
// ****************************************

// COMオブジェクトをNULLチェックしてからReleaseする
#define COM_SAFE_RELEASE(o)   if(NULL!=o){o->Release();o=NULL;}


// ****************************************
// 公開する関数のプロトタイプ宣言
// ****************************************

// Direct3D11 Device*を返す
ID3D11Device* Direct3D_GetDevice();

// Direct3D11 Immidiate Context*を返す
ID3D11DeviceContext* Direct3D_GetContext();

// Direct3D11 SwapChain*を返す
IDXGISwapChain* Direct3D_GetSwapChain();

// Direct3D11 RenderTargetView*を返す
ID3D11RenderTargetView* Direct3D_GetRenderTargetView();



// DirextX11の初期化を担当する関数（の定義）
HRESULT Direct3D_Initialize(HWND hWnd);

// Direct3D関連で作成したオブジェクトをすべて開放する
void Direct3D_Release();

// 指定したファイル名のテクスチャファイル（画像ファイル）を読み込む
HRESULT Direct3D_LoadTexture(const char* pFileName, ID3D11ShaderResourceView** pOupSRV);

