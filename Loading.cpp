#include "Loading.h"

bool Loading::Init()
{
	//描画するものの初期化（画像読み込み）
	enemy = new CSprite("assets/enemy.png", 7, 1, posX - 1.35f, -0.8f, 0.3f * (float)RESOLUTIONY / (float)RESOLUTIONX, 0.4f);
	loadingBar = new CSprite("assets/loading/loadingBar.png", 1, 1, posX, -0.8f, 2.5f, 0.2f);
	background = new CSprite("assets/loading/background.png", 1, 1, 0.0f, 0.0f, 2.0f, 2.0f);

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

	//一回の実行につき、ローディングバーの進む距離を計算する
	goalIncrement = 100 / num;

	//ローディング実行
	for (int a = 0; a < num; a++)
	{
		if (funcStr[a] != NULL)		//空じゃなかったら
		{
			//関数を実行し、その情報をfooに入れる
			std::future<void> foo = std::async(std::launch::async, funcStr[a]);

			//今進む距離のゴールに上で計算した距離を足す
			progressGoal += goalIncrement;
			Count();		//描画
		}
	}
}

void Loading::Count()
{
	//描画ループ
	for (int a = progress; a <= progressGoal; a++)
	{
		posX -= 0.021f;		//一回につき動く距離

		//スプライトの位置を設定する
		enemy->SetPosX(posX - 1.35f);
		loadingBar->SetPosX(posX);

		Draw();		//描画

		Sleep(SLOW);	//さらっと行かないように、一旦休ませる
	}

	//終わった時点の距離を保存する
	progress = progressGoal;
}

void Loading::Draw()
{
	float clearColor[4] = { 0.0f, 0.0f, 0.0f, 1.0f };

	Direct3D_GetContext()->ClearRenderTargetView(Direct3D_GetRenderTargetView(), clearColor);

	//スプライトの描画
	background->Draw();
	enemy->Draw();
	loadingBar->Draw();

	Direct3D_GetSwapChain()->Present(0, 0);
}

void Loading::Reset()
{
	//値の変数をリセットする
	progress = 0;
	progressGoal = 0;
	goalIncrement = 0;
	num = 0;
	posX = 2.3f;
}