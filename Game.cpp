#include "Game.h"

VECTOR moveV[8];  // 移動用ベクトル

RectShape rectA(1.0f, 1.0f, 1.0f, 1.0f);  // 当たり判定用の矩形
RectShape rectB(1.0f, 1.0f, 1.0f, 1.0f);  // 当たり判定用の矩形

bool GameClass::Init()
{
	//インプットオブジェクトを作る
	inputObj = new Input;

	//インプットオブジェクトの作成に失敗したら
	if (!inputObj)
	{
		MessageBoxA(nullptr, "インプットオブジェクト作れませんでした", "インプットエラー", MB_OK);
		return false;
	}

	//画像系のオブジェクトを作る
	sprite = new CGameObject*[64];

	for (int a = 0; a < MAXSPRITE; a++)
	{
		sprite[a] = NULL;
	}

	MapChips = new CSprite**[MAP_SIZE_HEIGHT];

	//それぞれのオブジェクト配列に画像のデータを読み込んで、初期化する
	sprite[0] = new CGameObject("assets/char.png", 8, 4, 0.0f, 0.0f, 0.15f, 0.15f);
	sprite[1] = new CGameObject("assets/effect001.png", 1, 1, 0.0f, 0.0f, 0.15f, 0.15f);

	sprite[2] = new CGameObject("assets/ground.png", 1, 1, 0.0f, GROUND_Y, 4.0f, 0.2f);
	sprite[2]->enabled = true;

	sprite[3] = new CGameObject("assets/circle.png", 1, 1, 0.0f, 0.0f, 2.6f, 2.6f);
	sprite[3]->enabled = true;

	sprite[6] = new CGameObject("assets/slime.png", 9, 6, 0.0f, 0.0f, 0.15f, 0.15f);
	sprite[6]->enabled = true;

	sprite[10] = new CGameObject("assets/tpEffect1.png", 1, 1, 0.0f, 0.0f, 0.15f, 0.15f);
	sprite[11] = new CGameObject("assets/tpEffect2.png", 1, 1, 0.0f, 0.0f, 0.15f, 0.15f);
	sprite[12] = new CGameObject("assets/tpEffect3.png", 1, 1, 0.0f, 0.0f, 0.15f, 0.15f);

	background = new CSprite("assets/background.jpg", 1, 1, 1.0f, 1.0f, 4.0f, 4.0f);

	playerObj = sprite[0];

	// 移動用ベクトルを8方向分作成
	for (int i = 0; i < 8; i++) {
		moveV[i].vx = cosf((float)i * PI / 4.0f);
		moveV[i].vy = sinf((float)i * PI / 4.0f);
	}

	return true;
}

bool GameClass::Update()
{
	//インプットオブジェクトをアップデート
	inputObj->Input_Update();

	//ESCキー押したら、プログラム強制終了
	if (inputObj->Input_GetKeyTrigger(VK_ESCAPE))
		return false;

	//プレイヤーの座標を取得
	float DragonPosX = playerObj->GetPos('x');
	float DragonPosY = playerObj->GetPos('y');

	//プレイヤーの向き
	static int DragonDirection = 1;
	static int moveAnim = 1;
	static bool isMoving = false;

	//瞬間移動用
	static int tpAnim = 0;				//フレーム数
	static bool tpAnimFlg = false;		//瞬間移動アニメーションフラグ（実行するかどうか）
	static int tpAnimPart = 9;
	static int tpAnimSize = 99 / TELEPORTSIZE;
	static int tpPlaceHolder = 0;

	static float GhostPosX = 0.0f;
	static float GhostPosY = 0.0f;
	static float GhostSizeX = 0.15f;
	static float GhostSizeY = 0.15f;
	static bool GhostCanMove = false;  // ゴーストが移動できるかどうか
	static bool GhostNowMove = false;  // ゴーストが移動中かどうか
	static int GhostMoveDir0 = MOVE_DIR_NONE;  // ゴーストの移動方向を仮保存するための変数
	static int GhostMoveDir = MOVE_DIR_NONE;  // ゴーストの移動方向を保存する変数
	static float GhostMoveCoefficient = 0.0003f;  // ゴーストの移動量の係数

	static bool hit_flg = false;  // 当たり判定用の変数

	//瞬間移動できるかどうかのフラグ
	static bool Teleport_flg = false;

	// 当たり判定用の矩形にドラゴンとゴーストの大きさを渡す
	rectA.SetSize(0.15f, 0.15f);
	rectB.SetSize(GhostSizeX, GhostSizeY);

	//移動できる場合（瞬間移動してない場合）
	if (tpAnim == 0 && !tpAnimFlg)
	{
		if (inputObj->isInput())	//インプットがあったら
		{
			//左方向に行ったら
			if (inputObj->GetAxis(LEFT)) {
				DragonPosX -= 0.0006f * MOVESPEED;
				DragonDirection = 0;
				if ((inputObj->Input_GetKeyTrigger(VK_LBUTTON)) && (Teleport_flg == false)) {
					Teleport_flg = true;
					tpAnimFlg = true;
					tpAnimPart = 9;
				}
			}

			if (inputObj->GetAxis(RIGHT)) {
				DragonPosX += 0.0006f * MOVESPEED;
				DragonDirection = 1;
				if ((inputObj->Input_GetKeyTrigger(VK_LBUTTON)) && (Teleport_flg == false)) {
					tpAnimFlg = true;
					Teleport_flg = true;
					tpAnimPart = 9;
				}
			}

			isMoving = true;
		}
		else
			isMoving = false;
	}

	if (Teleport_flg == true) {
		static int cnt = 0;
		cnt++;
		if (cnt >= 1000) {
			Teleport_flg = false;
			cnt = 0;
		}
	}

	//瞬間移動アニメーションフラグがtrueの場合、カウント始まる
	if (tpAnimFlg)
	{
		tpAnim++;
	}

	//瞬間移動アニメーション処理
	if (tpAnim <= 0)					//通常の時
		playerObj = sprite[0];
	if (tpAnim >= 1 && tpAnim <= 99)	//瞬間移動アニメーション入る
	{
		if (tpAnim == 1 || tpAnim == tpPlaceHolder)
		{
			tpAnimPart++;
			playerObj = sprite[tpAnimPart];
			tpPlaceHolder = tpAnim + tpAnimSize;
		}
	}
	if (tpAnim >= 100 && tpAnim <= 199)					//瞬間移動
	{
		if ((tpAnim - 100) % 11 == 0)
		{
			//向きによって、移動する方向が変わる
			switch (DragonDirection)
			{
			case 0: DragonPosX -= 0.05f;
				break;
			case 1: DragonPosX += 0.05f;
				break;
			}
		}
	}
	if (tpAnim >= 200 && tpAnim <= 299)	//瞬間移動アニメーション入る（出る）
	{
		if (tpAnim == 200 || tpAnim == tpPlaceHolder)
		{
			playerObj = sprite[tpAnimPart];
			tpAnimPart--;
			tpPlaceHolder = tpAnim + tpAnimSize;
		}
	}
	if (tpAnim == 300)					//通常の状態に戻す
	{
		playerObj = sprite[0];
		tpAnimFlg = false;
		tpAnimPart = 9;
		tpAnim = 0;

		// 当たり判定用の矩形にそれぞれの大きさを渡す
		rectA.SetPos(DragonPosX, DragonPosY);
		rectB.SetPos(GhostPosX, GhostPosY);

		// 矩形同士で当たり判定をとる
		hit_flg = Collision::RectAndRectTest(rectA, rectB);

		if (hit_flg) {  // 当たってたら

			float rad = Angle(DragonPosX, DragonPosY, GhostPosX, GhostPosY);  // ドラゴンとゴーストの中心同士を結んだ線の角度を計算

			// 角度によってドラゴンの位置を補正する
			if ((rad >= -PI && rad <= -PI * 7.0f / 8.0f) || (rad >= PI * 7.0f / 8.0f && rad <= PI)) {
				DragonPosX = GhostPosX - GhostSizeX * 0.6f;
				DragonPosY = GhostPosY - 0.0f;

				GhostMoveDir0 = MOVE_DIR_RIGHT;
			}
			else if (rad > -PI * 7.0f / 8.0f && rad < -PI * 5.0f / 8.0f) {
				DragonPosX = GhostPosX - GhostSizeX * 0.6f;
				DragonPosY = GhostPosY - GhostSizeY * 0.6f;

				GhostMoveDir0 = MOVE_DIR_UPPER_RIGHT;
			}
			else if (rad >= -PI * 5.0f / 8.0f && rad <= -PI * 3.0f / 8.0f) {
				DragonPosX = GhostPosX - 0.0f;
				DragonPosY = GhostPosY - GhostSizeY * 0.6f;

				GhostMoveDir0 = MOVE_DIR_UP;
			}
			else if (rad > -PI * 3.0f / 8.0f && rad < -PI * 1.0f / 8.0f) {
				DragonPosX = GhostPosX + GhostSizeX * 0.6f;
				DragonPosY = GhostPosY - GhostSizeY * 0.6f;

				GhostMoveDir0 = MOVE_DIR_UPPER_LEFT;
			}
			else if (rad >= -PI * 1.0f / 8.0f && rad <= PI * 1.0f / 8.0f) {
				DragonPosX = GhostPosX + GhostSizeX * 0.6f;
				DragonPosY = GhostPosY + 0.0f;

				GhostMoveDir0 = MOVE_DIR_LEFT;
			}
			else if (rad > PI * 1.0f / 8.0f && rad < PI * 3.0f / 8.0f) {
				DragonPosX = GhostPosX + GhostSizeX * 0.6f;
				DragonPosY = GhostPosY + GhostSizeY * 0.6f;

				GhostMoveDir0 = MOVE_DIR_LOWER_LEFT;
			}
			else if (rad >= PI * 3.0f / 8.0f && rad <= PI * 5.0f / 8.0f) {
				DragonPosX = GhostPosX - 0.0f;
				DragonPosY = GhostPosY + GhostSizeY * 0.6f;

				GhostMoveDir0 = MOVE_DIR_DOWN;
			}
			else if (rad > PI * 5.0f / 8.0f && rad < PI * 7.0f / 8.0f) {
				DragonPosX = GhostPosX - GhostSizeX * 0.6f;
				DragonPosY = GhostPosY + GhostSizeY * 0.6f;

				GhostMoveDir0 = MOVE_DIR_LOWER_RIGHT;
			}

			// ゴーストが移動中なら先回りするように少し先に移動する
			if (GhostNowMove) {
				switch (GhostMoveDir) {
				case MOVE_DIR_RIGHT:
					DragonPosX += GhostMoveCoefficient * moveV[0].vx * 252.0f;
					DragonPosY += GhostMoveCoefficient * moveV[0].vy * 252.0f;

					break;

				case MOVE_DIR_UPPER_RIGHT:
					DragonPosX += GhostMoveCoefficient * moveV[1].vx * 252.0f;
					DragonPosY += GhostMoveCoefficient * moveV[1].vy * 252.0f;

					break;

				case MOVE_DIR_UP:
					DragonPosX += GhostMoveCoefficient * moveV[2].vx * 252.0f;
					DragonPosY += GhostMoveCoefficient * moveV[2].vy * 252.0f;

					break;

				case MOVE_DIR_UPPER_LEFT:
					DragonPosX += GhostMoveCoefficient * moveV[3].vx * 252.0f;
					DragonPosY += GhostMoveCoefficient * moveV[3].vy * 252.0f;

					break;

				case MOVE_DIR_LEFT:
					DragonPosX += GhostMoveCoefficient * moveV[4].vx * 252.0f;
					DragonPosY += GhostMoveCoefficient * moveV[4].vy * 252.0f;

					break;

				case MOVE_DIR_LOWER_LEFT:
					DragonPosX += GhostMoveCoefficient * moveV[5].vx * 252.0f;
					DragonPosY += GhostMoveCoefficient * moveV[5].vy * 252.0f;

					break;

				case MOVE_DIR_DOWN:
					DragonPosX += GhostMoveCoefficient * moveV[6].vx * 252.0f;
					DragonPosY += GhostMoveCoefficient * moveV[6].vy * 252.0f;

					break;

				case MOVE_DIR_LOWER_RIGHT:
					DragonPosX += GhostMoveCoefficient * moveV[7].vx * 252.0f;
					DragonPosY += GhostMoveCoefficient * moveV[7].vy * 252.0f;

					break;
				}
			}

			GhostCanMove = true;
		}

		if (GhostCanMove) {  // ゴーストに当たってたらゴーストの移動処理を始める
			GhostNowMove = true;
			GhostCanMove = false;
			GhostMoveCoefficient += 0.00001f;
			GhostMoveDir = GhostMoveDir0;
			GhostMoveDir0 = MOVE_DIR_NONE;
		}
	}

	// ゴーストの移動処理
	if (GhostNowMove) {
		// はじかれた方向に移動する
		switch (GhostMoveDir)
		{
		case MOVE_DIR_RIGHT:
			GhostPosX += GhostMoveCoefficient * moveV[0].vx;
			GhostPosY += GhostMoveCoefficient * moveV[0].vy;

			break;

		case MOVE_DIR_UPPER_RIGHT:
			GhostPosX += GhostMoveCoefficient * moveV[1].vx;
			GhostPosY += GhostMoveCoefficient * moveV[1].vy;

			break;

		case MOVE_DIR_UP:
			GhostPosX += GhostMoveCoefficient * moveV[2].vx;
			GhostPosY += GhostMoveCoefficient * moveV[2].vy;

			break;

		case MOVE_DIR_UPPER_LEFT:
			GhostPosX += GhostMoveCoefficient * moveV[3].vx;
			GhostPosY += GhostMoveCoefficient * moveV[3].vy;

			break;

		case MOVE_DIR_LEFT:
			GhostPosX += GhostMoveCoefficient * moveV[4].vx;
			GhostPosY += GhostMoveCoefficient * moveV[4].vy;

			break;

		case MOVE_DIR_LOWER_LEFT:
			GhostPosX += GhostMoveCoefficient * moveV[5].vx;
			GhostPosY += GhostMoveCoefficient * moveV[5].vy;

			break;

		case MOVE_DIR_DOWN:
			GhostPosX += GhostMoveCoefficient * moveV[6].vx;
			GhostPosY += GhostMoveCoefficient * moveV[6].vy;

			break;

		case MOVE_DIR_LOWER_RIGHT:
			GhostPosX += GhostMoveCoefficient * moveV[7].vx;
			GhostPosY += GhostMoveCoefficient * moveV[7].vy;

			break;
		}
	}

	////カメラの位置をプレイヤーと合わせる
	//CSprite::mCameraPosX = DragonPosX; //カメラの位置を操作キャラクターに追従させる
	//CSprite::mCameraPosY = DragonPosY;

	playerObj->SetPos(DragonPosX, DragonPosY);

	for (int a = 0; a < 2; a++)
		sprite[a]->SetPos(DragonPosX, DragonPosY);

	static bool canJump = true;
	static bool isJumping = false;

	if (inputObj->Input_GetKeyTrigger(VK_SPACE) && canJump)
	{
		canJump = false;
		isJumping = true;
	}

	if (inputObj->Input_GetKeyTrigger(VK_RETURN))
		completedLevel++;

	if (isJumping)
	{
		if (!sprite[0]->GetNowAir() || sprite[0]->GetNowJump())
		{
			sprite[0]->GravityJump();  // 重力でのジャンプ
			//player.SinJump();  // 三角関数でのジャンプ
		}
		else
		{
			isJumping = false;
			canJump = true;
		}
	}

	sprite[6]->SetPos(GhostPosX, GhostPosY);

	playerObj->Gravity();	//重力でのジャンプのときの重力



	sprite[6]->Gravity();	//敵の重力

	sprite[3]->SetPos(playerObj->GetPos('x'), playerObj->GetPos('y'));	//範囲表示オブジェクトの位置を設定

	static int cnt = 0;			//アニメーション用のカウンター
	static int animPart = 0;	//アニメーションのパーツ

	if (isMoving && !tpAnimFlg)
	{
		cnt++;

		if (cnt % 100 == 0)
		{
			animPart++;
			if (animPart > 7)
				animPart = 1;
		}

		playerObj->SetPart(animPart, DragonDirection + 1);
	}
	else
	{
		cnt = 0;
		animPart = 0;

		playerObj->SetPart(0, 0);
	}

	Draw();

	return true;
}

void GameClass::Draw()
{
	float clearColor[4] = { 0.0f, 0.0f, 0.0f, 1.0f };

	Direct3D_GetContext()->ClearRenderTargetView(Direct3D_GetRenderTargetView(), clearColor);

	background->Draw();

	playerObj->Draw();

	for (int a = 0; a < MAXSPRITE; a++)
	{
		if (sprite[a] && sprite[a]->enabled)
			sprite[a]->Draw();
	}

	Direct3D_GetSwapChain()->Present(0, 0);
}

float Angle(float x1, float y1, float x2, float y2)
{
	double radian = atan2((double)(y1 - y2), (double)(x1 - x2));

	return (float)radian;
}