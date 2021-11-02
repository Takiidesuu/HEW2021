#include "System.h"

System::System()
{
	
}

System::~System()
{

}

bool System::Init()
{
	int screenWidth, screenHeight;	//画面の解像度
	bool result;	//処理確認用
	HRESULT hr;		//処理確認用

	//解像度変数の初期化
	screenWidth = 0;
	screenHeight = 0;

	//ウインドウズ初期化
	InitializeWindows(screenWidth, screenHeight);

	//サウンドオブジェクトを作る
	soundObj = new SoundClass;

	//サウンドオブジェクト初期化
	hr = soundObj->Init();

	//サウンドオブジェクトの作成に失敗したら
	if (FAILED(hr))
	{
		//エラー表示して、falseを渡す
		MessageBoxA(m_hwnd, "サウンド初期化できませんでした", "サウンドエラー", MB_OK | MB_ICONERROR);
		return false;
	}

	//タイトルオブジェクトを作る
	titleObj = new Title;

	result = titleObj->Init();

	if (!result)
	{
		MessageBoxA(m_hwnd, "タイトルオブジェクト初期化できませんでした", "タイトルエラー", MB_OK | MB_ICONERROR);
		return false;
	}

	////ステージセレクトオブジェクトを作る
	//stageObj = new StageSelect;

	//result = stageObj->Init();

	//if (!result)
	//{
	//	MessageBoxA(m_hwnd, "ステージセレクト初期化できませんでした", "システム", MB_OK | MB_ICONERROR);
	//	return false;
	//}

	//ゲームオブジェクトを作る
	gameObj = new GameClass;

	result = gameObj->Init();

	if (!result)
	{
		//エラー表示して、falseを渡す
		MessageBoxA(m_hwnd, "ゲーム初期化出来ませんでした", "ゲームエラー（システム）", MB_OK | MB_ICONERROR);
		return false;
	}

	saveloadObj = new SaveLoad;

	gameObj->completedLevel = saveloadObj->Load();

	return true;
}

void System::InitializeWindows(int& screenWidth, int& screenHeight)
{
	WNDCLASSEX wc;
	DEVMODE screenSettings;
	int posX, posY;

	ApplicationHandle = this;

	m_hinstance = GetModuleHandle(NULL);

	m_applicationName = L"Prototype";

	wc.style = CS_CLASSDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = m_hinstance;
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wc.hIconSm = wc.hIcon;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = m_applicationName;
	wc.cbSize = sizeof(WNDCLASSEX);

	RegisterClassEx(&wc);

	screenWidth = GetSystemMetrics(SM_CXSCREEN);
	screenHeight = GetSystemMetrics(SM_CYSCREEN);

	if (FULL_SCREEN)
	{
		memset(&screenSettings, 0, sizeof(screenSettings));
		screenSettings.dmSize = sizeof(screenSettings);
		screenSettings.dmPelsWidth = (unsigned long)screenWidth;
		screenSettings.dmPelsHeight = (unsigned long)screenHeight;
		screenSettings.dmBitsPerPel = 32;
		screenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		ChangeDisplaySettings(&screenSettings, CDS_FULLSCREEN);

		posX = posY = 0;
	}
	else
	{
		screenWidth = RESOLUTIONX;
		screenHeight = RESOLUTIONY;

		posX = (GetSystemMetrics(SM_CXSCREEN) - screenWidth) / 2;
		posY = (GetSystemMetrics(SM_CYSCREEN) - screenHeight) / 2;
	}

	m_hwnd = CreateWindowEx(WS_EX_APPWINDOW, 
		m_applicationName, 
		m_applicationName,
		WS_CAPTION | WS_SYSMENU | WS_OVERLAPPEDWINDOW,
		posX, 
		posY, 
		screenWidth, 
		screenHeight, 
		NULL, 
		NULL, 
		m_hinstance, 
		NULL);

	//Direct3Dオブジェクトの初期化
	Direct3D_Initialize(m_hwnd);

	//ウインドウズ表示
	ShowWindow(m_hwnd, SW_SHOW);

	SetForegroundWindow(m_hwnd);	//画面の最前面に出す
	SetFocus(m_hwnd);				//フォーカスにする

	ShowCursor(true);		//マウスカーソルを表示

	return;
}

void System::Update()
{
	MSG msg;
	bool done, result;

	ZeroMemory(&msg, sizeof(MSG));

	done = false;
	while (!done)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		if (msg.message == WM_QUIT)
		{
			done = true;
		}
		else
		{
			result = Processes();
			if (!result)
			{
				done = true;
			}
		}
	}
}

bool System::Processes()
{
	bool result;
	bool sceneCheck = false;

	switch (scene)
	{
	case 0:
		result = titleObj->Update();
		sceneCheck = titleObj->SceneChange();
		break;
	/*case 1: 
		result = stageObj->Update();
		break;*/
	case 1: 
		result = gameObj->Update();
		break;
	}

	if (sceneCheck)
	{
		scene++;
		sceneCheck = false;
	}

	if (!result)
		return false;

	return true;
}

void System::Uninit()
{
	saveloadObj->Save(gameObj->completedLevel);

	if (FULL_SCREEN)
	{
		ChangeDisplaySettings(NULL, 0);
	}

	DestroyWindow(m_hwnd);
	m_hwnd = NULL;

	UnregisterClass(m_applicationName, m_hinstance);
	m_hinstance = NULL;

	ApplicationHandle = NULL;

	return;
}

LRESULT CALLBACK System::MessageHandler(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam)
{
	switch (umsg)
	{
	default:
		return DefWindowProc(hwnd, umsg, wparam, lparam);
	}

}

LRESULT CALLBACK WndProc(HWND hwnd, UINT umessage, WPARAM wparam, LPARAM lparam)
{
	switch (umessage)
	{
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		return 0;
	}

	case WM_CLOSE:
	{
		int ans = MessageBoxA(hwnd, "終了しますか？", "終了確認", MB_YESNO);
		if (ans == IDYES)
		{
			PostQuitMessage(0);
			return 0;
		}
		else
			break;
	}

	default:
		return ApplicationHandle->MessageHandler(hwnd, umessage, wparam, lparam);
	}
}