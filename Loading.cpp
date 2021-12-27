#include "Loading.h"

bool Loading::Init()
{
	//描画するものの初期化（画像読み込み）
	enemy = new CSprite("assets/enemy.png", 7, 1, posX - 0.6f, -0.8f, 0.4f, 0.4f);
	loadingBar = new CSprite("assets/loading/loadingBar.png", 3, 1, posX, -0.85f, 1.0f, 1.0f);
	return true;		//初期化成功した事を報告する
}

void Loading::Load(Func func1, Func func2, Func func3, Func func4, Func func5)
{
	Reset();	//値をリセットする

	Count();	//初期状態を描画する

	Func funcStr[5];	//functionポインターの配列

	//初期化で、空にする
	for (int a = 0; a < 5; a++)
		funcStr[a] = NULL;

	//配列にロードする関数を入れる
	funcStr[0] = func1;
	funcStr[1] = func2;
	funcStr[2] = func3;
	funcStr[3] = func4;
	funcStr[4] = func5;

	//ロードする関数どれぐらいあるかをチェックする
	for (int a = 0; a < 5; a++)
	{
		if (funcStr[a] != NULL)		//空じゃなかったら、カウントアップ
			num++;
		else
			;
	}

	//ローディング実行
	for (int a = 0; a < num; a++)
	{
		if (funcStr[a] != NULL)		//空じゃなかったら
		{
			//関数を実行し、その情報をfooに入れる
			std::future<void> foo = std::async(std::launch::async, funcStr[a]);

			foo.wait_for(std::chrono::milliseconds(1000));

			Count();		//描画
		}
	}
}

void Loading::Count()
{
	int part = 0;
	int enemyPart = 0;

	//描画ループ
	for (int a = 0; a <= 8; a++)
	{
		if (a % 3 == 0)
			part++;

		if (part >= 3)
			part = 0;

		loadingBar->SetPart(part, 0);

		enemyPart++;

		if (enemyPart >= 7)
			enemyPart = 0;

		enemy->SetPart(enemyPart, 0);

		Draw();		//描画

		Sleep(SLOW);	//さらっと行かないように、一旦休ませる
	}
}

void Loading::Draw()
{
	float clearColor[4] = { 0.0f, 0.0f, 0.0f, 1.0f };

	Direct3D_GetContext()->ClearRenderTargetView(Direct3D_GetRenderTargetView(), clearColor);

	//スプライトの描画
	enemy->Draw();
	loadingBar->Draw();

	Direct3D_GetSwapChain()->Present(0, 0);
}

void Loading::Reset()
{
	//値の変数をリセットする
	num = 0;
}