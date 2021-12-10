#include "Game.h"

VECTOR moveV[8];  // 移動用ベクトル

RectShape rectA(1.0f, 1.0f, 1.0f, 1.0f);  // 当たり判定用の矩形
RectShape rectB(1.0f, 1.0f, 1.0f, 1.0f);  // 当たり判定用の矩形
RectShape rectC(1.0f, 1.0f, 1.0f, 1.0f);  // 当たり判定用の矩形

int Savehitmaphipnum[100][3];			//当たり判定のあるマップチップの配列番号を保存する配列
int hitmapchipnum = 0;					//当たり判定のあるマップチップの数

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

	MapChips = new CGameObject**[MAPCHIP_NUM_HEIGHT];

	for (int i = 0; i < MAPCHIP_NUM_HEIGHT; i++) {
		MapChips[i] = new CGameObject*[MAPCHIP_NUM_WIDTH];
		for (int j = 0; j < MAPCHIP_NUM_WIDTH; j++) {
			MapChips[i][j] = new CGameObject("assets/MapChip.png", 4, 1, -1 + j * 2 * (float)MAPCHIP_SIZE_WIDTH / (float)RESOLUTIONX + ((float)MAPCHIP_SIZE_WIDTH / (float)RESOLUTIONX), 1 - i * 2 * (float)MAPCHIP_SIZE_HEIGHT / (float)RESOLUTIONY - ((float)MAPCHIP_SIZE_HEIGHT / (float)RESOLUTIONY), (float)MAPCHIP_SIZE_WIDTH / (float)RESOLUTIONX * 2, (float)MAPCHIP_SIZE_HEIGHT / (float)RESOLUTIONY * 2, 80.0f, 16.0f);
			MapChips[i][j]->SetPart(MapChipDate[i][j], 0);
			if (MapChipDate[i][j]) {
				Savehitmaphipnum[hitmapchipnum][0] = i;
				Savehitmaphipnum[hitmapchipnum][1] = j;
				Savehitmaphipnum[hitmapchipnum][2] = MapChipDate[i][j];
				hitmapchipnum++;
			}
		}
	}

	circleSizeReal = circleSize;

	//それぞれのオブジェクト配列に画像のデータを読み込んで、初期化する

	//プレイヤー
	sprite[0] = new CGameObject("assets/player.png", 7, 1, -0.25f, -0.7 + 0.15f / 2.0f, 0.15f * (float)RESOLUTIONY / (float)RESOLUTIONX, 0.15f);


	sprite[1] = new CGameObject("assets/effect001.png", 1, 1, 0.0f, 0.0f, 0.15f, 0.15f);

	sprite[3] = new CGameObject("assets/circle.png", 1, 1, 0.0f, 0.0f, circleSize * (float)RESOLUTIONY / (float)RESOLUTIONX, circleSize);
	sprite[3]->enabled = false;

	sprite[6] = new CGameObject("assets/enemy.png", 7, 1, 0.25f, 0.0f, 0.15f, 0.15f);
	sprite[6]->enabled = true;

	sprite[10] = new CGameObject("assets/tpEffect1.png", 1, 1, 0.0f, 0.0f, 0.15f, 0.15f);
	sprite[11] = new CGameObject("assets/tpEffect2.png", 1, 1, 0.0f, 0.0f, 0.15f, 0.15f);
	sprite[12] = new CGameObject("assets/tpEffect3.png", 1, 1, 0.0f, 0.0f, 0.15f, 0.15f);

	// 燃料の座標指定
	fuelPosX[0] = -0.5f;
	fuelPosY[0] = 0.0f;

	fuelPosX[1] = 0.0f;
	fuelPosY[1] = 0.0f;

	fuelPosX[2] = 0.5f;
	fuelPosY[2] = 0.0f;

	sprite[13] = new CGameObject("assets/MoE.png", 1, 1, fuelPosX[0], fuelPosY[0], fuelSizeX, fuelSizeY);
	sprite[14] = new CGameObject("assets/MoE.png", 1, 1, fuelPosX[1], fuelPosY[1], fuelSizeX, fuelSizeY);
	sprite[15] = new CGameObject("assets/MoE.png", 1, 1, fuelPosX[2], fuelPosY[2], fuelSizeX, fuelSizeY);
	sprite[13]->enabled = true;
	sprite[14]->enabled = true;
	sprite[15]->enabled = true;

	sprite[16] = new CGameObject("assets/stageClear.png", 1, 1, 0.0f, 0.0f, 1.0f, 0.5f);

	BlackoutPanel = new CSprite("assets/EfectPanel.png", 1, 1, 0.0f, 0.0f, 2.0f, 2.0f);
	BlackoutPanel->SetColor(0.0f, 0.0f, 0.0f, 0.0f);

	background = new CGameObject("assets/BG_haisouko_ver02.png", 1, 1, 0.0f, 0.0f, 2.0f, 2.0f);

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
	if (showCircle) {
		slowcnt++;

		BlackoutPanel->SetColor(0.0f, 0.0f, 0.0f, SLOW_DARKNESS);

		if (slowcnt > SLOW_SPEED) {
			slowcnt = 0;
		}
	}

	if ((!showCircle) || (slowcnt == SLOW_SPEED)) {

		if (!showCircle)
			BlackoutPanel->SetColor(0.0f, 0.0f, 0.0f, 0.0f);

		slowcnt = 0;

		//インプットオブジェクトをアップデート
		inputObj->Input_Update();

		//ESCキー押したら、プログラム強制終了
		if (inputObj->Input_GetKeyTrigger(VK_ESCAPE))
			return false;

		if (inputObj->GetButtonPress(RESTART))
			Init();

		//プレイヤーの座標を取得
		DragonPosX = playerObj->GetPos('x');
		DragonPosY = playerObj->GetPos('y');

		GhostPosX = sprite[6]->GetPos('x');
		GhostPosY = sprite[6]->GetPos('y');

		//瞬間移動できるかどうかのフラグ
		static bool Teleport_flg = false;

		if (!stageClear)
		{
			//移動できる場合（瞬間移動してない場合）
			if (tpAnim == 0 && !tpAnimFlg)
			{
				if (inputObj->isInput())	//インプットがあったら
				{
					if (Teleport_flg == false)
					{
						if (inputObj->GetAxis(UP))
						{
							DragonDirection = 0;
						}
						if (inputObj->GetAxis(RIGHT))
						{
							DragonDirection = 1;
						}
						if (inputObj->GetAxis(DOWN))
						{
							DragonDirection = 2;
						}
						if (inputObj->GetAxis(LEFT))
						{
							DragonDirection = 3;
						}
						if (inputObj->GetAxis(UPPER_LEFT))
						{
							DragonDirection = 4;
						}
						if (inputObj->GetAxis(UPPER_RIGHT))
						{
							DragonDirection = 5;
						}
						if (inputObj->GetAxis(LOWER_LEFT))
						{
							DragonDirection = 6;
						}
						if (inputObj->GetAxis(LOWER_RIGHT))
						{
							DragonDirection = 7;
						}

						stick_flg = true;

						circleSizeReal += CIRCLE_SIZE_ADDITIONAL_SPEED;

						if (circleSizeReal >= CIRCLE_SIZE_MAXIMUM) {
							circleSizeReal = CIRCLE_SIZE_MAXIMUM;
						}

						showCircle = true;

						sprite[3]->SetSize(circleSizeReal, circleSizeReal);
						sprite[3]->enabled = showCircle;
					}


				}
				else if (stick_flg) {
					showCircle = false;
					sprite[3]->enabled = showCircle;
					stick_flg = false;
					Teleport_flg = true;
					tpAnimFlg = true;
					tpAnimPart = 9;
				}

			}

			if (Teleport_flg == true) {
				static int cnt = 0;
				cnt++;
				if (cnt >= 100) {
					Teleport_flg = false;
					cnt = 0;
				}
			}

			//瞬間移動アニメーションフラグがtrueの場合、カウント始まる
			if (tpAnimFlg)
			{
				tpAnim++;
			}

			//Teleport();

			NewMove();

			// ゴーストの移動処理
			if (GhostNowMove) {
				EnemyMove();
			}

			playerObj->SetPos(DragonPosX, DragonPosY);

			for (int a = 0; a < 2; a++)
				sprite[a]->SetPos(DragonPosX, DragonPosY);

			sprite[6]->SetPos(GhostPosX, GhostPosY);

			//敵が地面となるマップチップに接地しているかの処理
			if (!GhostNowMove) {
				sprite[6]->nowAir = true;
				for (int i = 0; i < hitmapchipnum; i++) {
					if ((Collision::RectAndRectHit(sprite[6]->GetPosAndSize(), MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize())) && (sprite[6]->nowAir)) {
						sprite[6]->nowAir = false;
						GhostPosY = MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize().posy + (MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize().sizey + sprite[6]->GetPosAndSize().sizey) / 2;
						sprite[6]->SetPos(GhostPosX, GhostPosY);
					}
				}
			}


			sprite[6]->Gravity();	//敵の重力


		//コンボ中断時の処理
			if (!GhostNowMove) {
				EnemyCombo = 0;
				if (ENEMY_SIZE_INITIALIZE) {
					GhostSizeX = 0.15f;
					GhostSizeY = 0.15f;
				}
			}

			sprite[6]->SetSize(GhostSizeX, GhostSizeY);

			sprite[3]->SetPos(playerObj->GetPos('x'), playerObj->GetPos('y'));	//範囲表示オブジェクトの位置を設定
		}
		else 
		{
			sprite[16]->enabled = true;

			cnt++;

			if (cnt >= 500)
			{
				remainingFuel = 3;
				cnt = 0;
				stageClear = false;
				Init();
				sceneManager.LoadScene(RESULT);
			}
		}

		playerAnimCnt++;

		if (playerAnimCnt >= 50 && !tpAnimFlg)
		{
			playerAnimPart++;

			if (playerAnimPart > 6)
				playerAnimPart = 0;

			sprite[0]->SetPart(playerAnimPart, 0);

			playerAnimCnt = 0;
		}

		enemyAnimCnt++;

		if (enemyAnimCnt >= 75 && !GhostNowMove)
		{
			enemyAnimPart++;

			if (enemyAnimPart > 6)
				enemyAnimPart = 0;

			sprite[6]->SetPart(enemyAnimPart, 0);

			enemyAnimCnt = 0;
		}

		Draw();
	}

	return true;
}

void GameClass::Draw()
{
	float clearColor[4] = { 0.0f, 0.0f, 0.0f, 1.0f };

	Direct3D_GetContext()->ClearRenderTargetView(Direct3D_GetRenderTargetView(), clearColor);

	background->Draw();

	for (int i = 0; i < hitmapchipnum; i++) {
		MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->Draw();
	}

	BlackoutPanel->Draw();

	playerObj->Draw();

	for (int a = 0; a < MAXSPRITE; a++)
	{
		if (sprite[a] && sprite[a]->enabled)
			sprite[a]->Draw();
	}

	Direct3D_GetSwapChain()->Present(0, 0);
}

void GameClass::Uninit()
{
	for (int i = 0; i < MAPCHIP_NUM_HEIGHT; i++) {
		for (int j = 0; j < MAPCHIP_NUM_WIDTH; j++) {
			delete MapChips[i][j];
		}
	}

	for (int i = 0; i < MAPCHIP_NUM_HEIGHT; i++) {
		delete MapChips[i];
	}

	delete[] MapChips;

	delete background;
	delete playerObj;

	/*for (int i = 0; i < MAXSPRITE; i++) {
		delete sprite[i];
	}

	delete[] sprite;*/
}

float Angle(float x1, float y1, float x2, float y2)
{
	double radian = atan2((double)(y1 - y2), (double)(x1 - x2));

	return (float)radian;
}

void GameClass::EnemyMove()
{
	/*dirX = 1.0f;
	dirX = 1.0f;*/

	if (GhostMoveCoefficient > 0.0f)
	{
		GhostMoveCoefficient -= ENEMY_ATTENUATION;

		bool hitMapchip_Enemy = false;
		//マップチップと敵との当たり判定
		for (int i = 0; i < hitmapchipnum; i++) {

			if ((Collision::RectAndRectHit(sprite[6]->GetPosAndSize(), MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize())) && (!hitMapchip_Enemy)) {

				float range_with_ground = ((sprite[6]->GetPosAndSize().posy + sprite[6]->GetPosAndSize().sizey / 2) - (MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize().posy - MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize().sizey / 2));

				float range_with_ceiling = ((sprite[6]->GetPosAndSize().posy - sprite[6]->GetPosAndSize().sizey / 2) - (MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize().posy + MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize().sizey / 2));

				float range_with_rightwall = ((sprite[6]->GetPosAndSize().posx + sprite[6]->GetPosAndSize().sizex / 2) - (MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize().posx - MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize().sizex / 2)) * (float)RESOLUTIONY / (float)RESOLUTIONX;

				float range_with_leftwall = ((sprite[6]->GetPosAndSize().posx - sprite[6]->GetPosAndSize().sizex / 2) - (MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize().posx + MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize().sizex / 2))  * (float)RESOLUTIONY / (float)RESOLUTIONX;

				if (range_with_ground < 0)
					range_with_ground *= -1.0f;

				if (range_with_ceiling < 0)
					range_with_ceiling *= -1.0f;

				if (range_with_rightwall < 0)
					range_with_rightwall *= -1.0f;

				if (range_with_leftwall < 0)
					range_with_leftwall *= -1.0f;

				switch (GhostMoveDir)
				{
				case MOVE_DIR_RIGHT:
				case MOVE_DIR_LEFT:
					dirX *= -1.0f;
					break;

				case MOVE_DIR_UP:
				case MOVE_DIR_DOWN:
					dirY *= -1.0f;
					break;

				case MOVE_DIR_UPPER_LEFT:
				case MOVE_DIR_UPPER_RIGHT:
				case MOVE_DIR_LOWER_LEFT:
				case MOVE_DIR_LOWER_RIGHT:

					if ((range_with_leftwall < 0.003) || (range_with_rightwall < 0.003))
						dirX *= -1.0f;

					if ((range_with_ceiling < 0.003) || (range_with_ground < 0.003))
						dirY *= -1.0f;

					break;
				}

				hitMapchip_Enemy = true;
			}
		}

		// はじかれた方向に移動する
		switch (GhostMoveDir)
		{
		case MOVE_DIR_RIGHT:
			GhostPosX += GhostMoveCoefficient * moveV[0].vx * dirX * 0.4f;
			GhostPosY += GhostMoveCoefficient * moveV[0].vy * dirY * 0.4f;

			break;

		case MOVE_DIR_UPPER_RIGHT:
			GhostPosX += GhostMoveCoefficient * moveV[1].vx * dirX * 0.4f;
			GhostPosY += GhostMoveCoefficient * moveV[1].vy * dirY * 0.4f;

			break;

		case MOVE_DIR_UP:
			GhostPosX += GhostMoveCoefficient * moveV[2].vx * dirX * 0.4f;
			GhostPosY += GhostMoveCoefficient * moveV[2].vy * dirY * 0.4f;

			break;

		case MOVE_DIR_UPPER_LEFT:
			GhostPosX += GhostMoveCoefficient * moveV[3].vx * dirX * 0.4f;
			GhostPosY += GhostMoveCoefficient * moveV[3].vy * dirY * 0.4f;

			break;

		case MOVE_DIR_LEFT:
			GhostPosX += GhostMoveCoefficient * moveV[4].vx * dirX * 0.4f;
			GhostPosY += GhostMoveCoefficient * moveV[4].vy * dirY * 0.4f;

			break;

		case MOVE_DIR_LOWER_LEFT:
			GhostPosX += GhostMoveCoefficient * moveV[5].vx * dirX * 0.4f;
			GhostPosY += GhostMoveCoefficient * moveV[5].vy * dirY * 0.4f;

			break;

		case MOVE_DIR_DOWN:
			GhostPosX += GhostMoveCoefficient * moveV[6].vx * dirX * 0.4f;
			GhostPosY += GhostMoveCoefficient * moveV[6].vy * dirY * 0.4f;

			break;

		case MOVE_DIR_LOWER_RIGHT:
			GhostPosX += GhostMoveCoefficient * moveV[7].vx * dirX * 0.4f;
			GhostPosY += GhostMoveCoefficient * moveV[7].vy * dirY * 0.4f;

			break;
		}

		GhostMoveCnt++;
	}
	else
	{
		GhostNowMove = false;
		dirX = 1.0f;
		dirY = 1.0f;
		sprite[6]->SetAirTime(0.0f);
		GhostMoveCnt = 0;
		GhostMoveCoefficient = PLAYER_PUNCH_POWER_MINIMUM;
		sprite[6]->SetNowAir(true);
	}
}

void GameClass::NewMove()
{
	if (tpAnim <= 0)					//通常の時
		playerObj = sprite[0];

	if (tpAnim == 1) {
		rectB.SetPos(GhostPosX, GhostPosY);
		rectB.SetSize(GhostSizeX, GhostSizeY);

		switch (DragonDirection)
		{
			//up
		case 0:
			hit_flg = Collision::RectAndLineTest(rectB, DragonPosX, DragonPosY, DragonPosX, DragonPosY + circleSizeReal * 0.23f);
			break;

			//right
		case 1:
			hit_flg = Collision::RectAndLineTest(rectB, DragonPosX, DragonPosY, DragonPosX + circleSizeReal * 0.23f, DragonPosY);
			break;

			//down
		case 2:
			hit_flg = Collision::RectAndLineTest(rectB, DragonPosX, DragonPosY, DragonPosX, DragonPosY - circleSizeReal * 0.23f);
			break;

			//left
		case 3:
			hit_flg = Collision::RectAndLineTest(rectB, DragonPosX, DragonPosY, DragonPosX - circleSizeReal * 0.23f, DragonPosY);
			break;

			// 左上
		case 4:
			hit_flg = Collision::RectAndLineTest(rectB, DragonPosX, DragonPosY, DragonPosX + circleSizeReal * 0.23f * moveV[3].vx, DragonPosY + circleSizeReal * 0.23f * moveV[3].vy);
			break;

			// 右上
		case 5:
			hit_flg = Collision::RectAndLineTest(rectB, DragonPosX, DragonPosY, DragonPosX + circleSizeReal * 0.23f * moveV[1].vx, DragonPosY + circleSizeReal * 0.23f * moveV[1].vy);
			break;

			// 左下
		case 6:
			hit_flg = Collision::RectAndLineTest(rectB, DragonPosX, DragonPosY, DragonPosX + circleSizeReal * 0.23f * moveV[5].vx, DragonPosY + circleSizeReal * 0.23f * moveV[5].vy);
			break;

			// 右下
		case 7:
			hit_flg = Collision::RectAndLineTest(rectB, DragonPosX, DragonPosY, DragonPosX + circleSizeReal * 0.23f * moveV[7].vx, DragonPosY + circleSizeReal * 0.23f * moveV[7].vy);
			break;
		}
	}

	if (tpAnim >= 2 && tpAnim <= 100)	//瞬間移動アニメーション入る
	{
		if (tpAnim == 2 || tpAnim - 1 == tpPlaceHolder)
		{
			tpAnimPart++;
			playerObj = sprite[tpAnimPart];
			tpPlaceHolder = tpAnim + tpAnimSize;
		}
	}

	if (tpAnim == 101)
	{
		Old_Player_PosX = DragonPosX;
		Old_Player_PosY = DragonPosY;

		switch (DragonDirection)
		{
			//up
		case 0:
			if (hit_flg) {
				DragonPosX = GhostPosX;
				DragonPosY = GhostPosY - GhostSizeY / 2.0f;

				GhostMoveDir0 = MOVE_DIR_UP;
				GhostMoveDir = MOVE_DIR_NONE;
				GhostCanMove = true;
			}
			else {
				DragonPosY += circleSizeReal * 0.23f;
			}
			break;

			//right
		case 1:
			if (hit_flg) {
				DragonPosX = GhostPosX - GhostSizeX / 2.0f;
				DragonPosY = GhostPosY;

				GhostMoveDir0 = MOVE_DIR_RIGHT;
				GhostMoveDir = MOVE_DIR_NONE;
				GhostCanMove = true;
			}
			else {
				DragonPosX += circleSizeReal * 0.23f;
			}
			break;

			//down
		case 2:
			if (hit_flg) {
				DragonPosX = GhostPosX;
				DragonPosY = GhostPosY + GhostSizeY / 2.0f;

				GhostMoveDir0 = MOVE_DIR_DOWN;
				GhostMoveDir = MOVE_DIR_NONE;
				GhostCanMove = true;
			}
			else {
				DragonPosY -= circleSizeReal * 0.23f;
			}
			break;

			//left
		case 3:
			if (hit_flg) {
				DragonPosX = GhostPosX + GhostSizeX / 2.0f;
				DragonPosY = GhostPosY;

				GhostMoveDir0 = MOVE_DIR_LEFT;
				GhostMoveDir = MOVE_DIR_NONE;
				GhostCanMove = true;
			}
			else {
				DragonPosX -= circleSizeReal * 0.23f;
			}
			break;

			// 左上
		case 4:
			if (hit_flg) {
				DragonPosX = GhostPosX + GhostSizeX / 2.0f;
				DragonPosY = GhostPosY - GhostSizeY / 2.0f;

				GhostMoveDir0 = MOVE_DIR_UPPER_LEFT;
				GhostMoveDir = MOVE_DIR_NONE;
				GhostCanMove = true;
			}
			else {
				DragonPosX += circleSizeReal * 0.23f * moveV[3].vx;
				DragonPosY += circleSizeReal * 0.23f * moveV[3].vy;
			}
			break;

			// 右上
		case 5:
			if (hit_flg) {
				DragonPosX = GhostPosX - GhostSizeX / 2.0f;
				DragonPosY = GhostPosY - GhostSizeY / 2.0f;

				GhostMoveDir0 = MOVE_DIR_UPPER_RIGHT;
				GhostMoveDir = MOVE_DIR_NONE;
				GhostCanMove = true;
			}
			else {
				DragonPosX += circleSizeReal * 0.23f * moveV[1].vx;
				DragonPosY += circleSizeReal * 0.23f * moveV[1].vy;
			}
			break;

			// 左下
		case 6:
			if (hit_flg) {
				DragonPosX = GhostPosX + GhostSizeX / 2.0f;
				DragonPosY = GhostPosY + GhostSizeY / 2.0f;

				GhostMoveDir0 = MOVE_DIR_LOWER_LEFT;
				GhostMoveDir = MOVE_DIR_NONE;
				GhostCanMove = true;
			}
			else {
				DragonPosX += circleSizeReal * 0.23f * moveV[5].vx;
				DragonPosY += circleSizeReal * 0.23f * moveV[5].vy;
			}
			break;

			// 右下
		case 7:
			if (hit_flg) {
				DragonPosX = GhostPosX - GhostSizeX / 2.0f;
				DragonPosY = GhostPosY + GhostSizeY / 2.0f;

				GhostMoveDir0 = MOVE_DIR_LOWER_RIGHT;
				GhostMoveDir = MOVE_DIR_NONE;
				GhostCanMove = true;
			}
			else {
				DragonPosX += circleSizeReal * 0.23f * moveV[7].vx;
				DragonPosY += circleSizeReal * 0.23f * moveV[7].vy;
			}
			break;
		}

		playerObj->SetPos(DragonPosX, DragonPosY);
	}

	if (tpAnim >= 102 && tpAnim <= 200)	//瞬間移動アニメーション入る（出る）
	{
		if (tpAnim == 102 || tpAnim - 1 == tpPlaceHolder)
		{
			playerObj = sprite[tpAnimPart];
			tpAnimPart--;
			tpPlaceHolder = tpAnim + tpAnimSize;
		}
	}

	if (tpAnim == 201)					//通常の状態に戻す
	{
		playerObj = sprite[0];
		tpAnimFlg = false;
		tpAnimPart = 9;
		tpAnim = 0;
		circleSizeReal = circleSize;

		// 燃料との当たり判定
		for (int i = 0; i < 3; i++) {
			// 矩形にプレイヤーと燃料の情報を渡す
			rectA.SetPos(DragonPosX, DragonPosY);
			rectA.SetSize(0.15f, 0.15f);
			rectB.SetPos(fuelPosX[i], fuelPosY[i]);
			rectB.SetSize(fuelSizeX, fuelSizeY);

			// 矩形同士で当たり判定をとる
			hit_flg = Collision::RectAndRectTest(rectB, rectA);

			// 当たってたら燃料を消す
			if (hit_flg) {
				fuelPosX[i] = 10.0f;
				fuelPosY[i] = 10.0f;
				sprite[i + 13]->SetPos(fuelPosX[i], fuelPosY[i]);
				remainingFuel--;
			}

			// 残ってる燃料がなくなったらクリア
			if (remainingFuel == 0) {
				stageClear = true;
			}
		}

		if (GhostCanMove) {  // 敵に当たってたらゴーストの移動処理を始める
			GhostNowMove = true;
			GhostCanMove = false;
			GhostMoveDir = GhostMoveDir0;
			GhostMoveDir0 = MOVE_DIR_NONE;
			GhostMoveCnt = 0;
			GhostSizeX += ENEMY_EXPAND_SIZE;
			GhostSizeY += ENEMY_EXPAND_SIZE;
			if (GhostSizeX >= ENEMY_SIZE_MAXIMUM) {
				GhostSizeX = ENEMY_SIZE_MAXIMUM;
			}
			if (GhostSizeY >= ENEMY_SIZE_MAXIMUM) {
				GhostSizeY = ENEMY_SIZE_MAXIMUM;
			}
			dirX = 1.0f;
			dirY = 1.0f;
			sprite[6]->SetSize(GhostSizeX, GhostSizeY);

			//サイズ変更によるマップチップとの被りを無くす処理
			for (int i = 0; i < hitmapchipnum; i++) {
				if (Collision::RectAndRectHit(sprite[6]->GetPosAndSize(), MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize())) {
					float range_with_ground = ((sprite[6]->GetPosAndSize().posy - sprite[6]->GetPosAndSize().sizey / 2) - (MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize().posy + MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize().sizey / 2));

					float range_with_ceiling = ((sprite[6]->GetPosAndSize().posy + sprite[6]->GetPosAndSize().sizey / 2) - (MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize().posy - MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize().sizey / 2));

					float range_with_rightwall = ((sprite[6]->GetPosAndSize().posx + sprite[6]->GetPosAndSize().sizex / 2) - (MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize().posx - MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize().sizex / 2));

					float range_with_leftwall = ((sprite[6]->GetPosAndSize().posx - sprite[6]->GetPosAndSize().sizex / 2) - (MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize().posx + MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize().sizex / 2));

					if ((range_with_ground >= -ENEMY_EXPAND_SIZE) && (range_with_ground <= ENEMY_EXPAND_SIZE)) {
						GhostPosY = MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize().posy + (MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize().sizey + sprite[6]->GetPosAndSize().sizey) / 2 + 0.001f;
					}
					else if ((range_with_ceiling >= -ENEMY_EXPAND_SIZE) && (range_with_ceiling <= ENEMY_EXPAND_SIZE)) {
						GhostPosY = MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize().posy - (MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize().sizey + sprite[6]->GetPosAndSize().sizey) / 2 - 0.001f;
					}
					sprite[6]->SetPos(GhostPosX, GhostPosY);

					if ((range_with_rightwall >= -ENEMY_EXPAND_SIZE) && (range_with_rightwall <= ENEMY_EXPAND_SIZE)) {
						GhostPosX = MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize().posx - (MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize().sizex + sprite[6]->GetPosAndSize().sizex) / 2 - 0.001f;
					}
					else if ((range_with_leftwall >= -ENEMY_EXPAND_SIZE) && (range_with_leftwall <= ENEMY_EXPAND_SIZE)) {
						GhostPosX = MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize().posx + (MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize().sizex + sprite[6]->GetPosAndSize().sizex) / 2 + 0.001f;
					}
					sprite[6]->SetPos(GhostPosX, GhostPosY);
				}
			}

			GhostMoveCoefficient = PLAYER_PUNCH_POWER_MINIMUM + EnemyCombo * PLAYER_PUNCH_ADDITIONAL_POWER;
			if (GhostMoveCoefficient >= PLAYER_PUNCH_POWER_MAXIMUM) {
				GhostMoveCoefficient = PLAYER_PUNCH_POWER_MAXIMUM;
			}
			//sprite[6]->SetAirTime(0.0f);
			sprite[6]->SetNowAir(false);
			EnemyCombo++;
		}
	}
}