#include "Game.h"

VECTOR moveV[8];  // 移動用ベクトル

RectShape rectA(1.0f, 1.0f, 1.0f, 1.0f);  // 当たり判定用の矩形
RectShape rectB(1.0f, 1.0f, 1.0f, 1.0f);  // 当たり判定用の矩形
RectShape rectC(1.0f, 1.0f, 1.0f, 1.0f);  // 当たり判定用の矩形
CircleShape circleA(1.0f, 1.0f, 1.0f);  // 当たり判定用の円
CircleShape circleB(1.0f, 1.0f, 1.0f);  // 当たり判定用の円

int Savehitmaphipnum[200][3];			//当たり判定のあるマップチップの配列番号を保存する配列
int hitmapchipnum = 0;					//当たり判定のあるマップチップの数

CEfect **EffectTest = new CEfect*[16];  // エフェクト用

void GameClass::Init()
{
	//インプットオブジェクトを作る
	inputObj = new Input;

	//画像系のオブジェクトを作る
	sprite = new CGameObject*[MAXSPRITE];

	Star_Num = sceneManager.ChoiceStar();
	World_Num = sceneManager.ChoiceWorld();
	Stage_Num = sceneManager.ChoiceStage();

	for (int a = 0; a < MAXSPRITE; a++)
		sprite[a] = NULL;

	EnemyNum = 0;

	enemy = new CEnemy*[5];
	fuel = new CGameObject*[3];
	gimmick = new CGameObject*[GIMMICKNUM];

	for (int a = 0; a < GIMMICKNUM; a++)
		gimmick[a] = NULL;

	MapChips = new CMapChip**[MAPCHIP_NUM_HEIGHT];

	for (int i = 0; i < MAPCHIP_NUM_HEIGHT; i++) {
		static int fuelNum = 0;
		static int fuelOrder = 0;
		static int gimmickNum = 0;

		MapChips[i] = new CMapChip*[MAPCHIP_NUM_WIDTH];
		for (int j = 0; j < MAPCHIP_NUM_WIDTH; j++) 
		{
			switch ((World_Num + 1) * (Star_Num + 1))
			{
			case 1:
				MapChips[i][j] = new CMapChip("assets/mapchip/MapChipW1.png", 7, 1, -1.777 + j * MAPCHIP_SIZE + MAPCHIP_SIZE / 2, 1 - i * MAPCHIP_SIZE - MAPCHIP_SIZE / 2, MAPCHIP_SIZE, MAPCHIP_SIZE, 80.0f, 16.0f);
				break;
			case 2:
				MapChips[i][j] = new CMapChip("assets/mapchip/MapChipW2.png", 7, 1, -1.777 + j * MAPCHIP_SIZE + MAPCHIP_SIZE / 2, 1 - i * MAPCHIP_SIZE - MAPCHIP_SIZE / 2, MAPCHIP_SIZE, MAPCHIP_SIZE, 80.0f, 16.0f);
				break;
			case 3:
				MapChips[i][j] = new CMapChip("assets/mapchip/MapChipW3.png", 7, 1, -1.777 + j * MAPCHIP_SIZE + MAPCHIP_SIZE / 2, 1 - i * MAPCHIP_SIZE - MAPCHIP_SIZE / 2, MAPCHIP_SIZE, MAPCHIP_SIZE, 80.0f, 16.0f);
				break;
			case 4:
				MapChips[i][j] = new CMapChip("assets/mapchip/MapChipW4.png", 9, 1, -1.777 + j * MAPCHIP_SIZE + MAPCHIP_SIZE / 2, 1 - i * MAPCHIP_SIZE - MAPCHIP_SIZE / 2, MAPCHIP_SIZE, MAPCHIP_SIZE, 80.0f, 16.0f);
				break;
			case 5:
				MapChips[i][j] = new CMapChip("assets/mapchip/MapChipW5.png", 7, 1, -1.777 + j * MAPCHIP_SIZE + MAPCHIP_SIZE / 2, 1 - i * MAPCHIP_SIZE - MAPCHIP_SIZE / 2, MAPCHIP_SIZE, MAPCHIP_SIZE, 80.0f, 16.0f);
				break;
			case 6:
				MapChips[i][j] = new CMapChip("assets/mapchip/MapChipW6.png", 7, 1, -1.777 + j * MAPCHIP_SIZE + MAPCHIP_SIZE / 2, 1 - i * MAPCHIP_SIZE - MAPCHIP_SIZE / 2, MAPCHIP_SIZE, MAPCHIP_SIZE, 80.0f, 16.0f);
				break;
			default: 
				MapChips[i][j] = new CMapChip("assets/mapchip/MapChipW1.png", 7, 1, -1.777 + j * MAPCHIP_SIZE + MAPCHIP_SIZE / 2, 1 - i * MAPCHIP_SIZE - MAPCHIP_SIZE / 2, MAPCHIP_SIZE, MAPCHIP_SIZE, 80.0f, 16.0f);
				break;
			}
			
			if (MapChipDate[Star_Num][World_Num][Stage_Num][i][j] < 10)
			{
				MapChips[i][j]->SetPart(MapChipDate[Star_Num][World_Num][Stage_Num][i][j], 0);
				if (MapChipDate[Star_Num][World_Num][Stage_Num][i][j]) {
					Savehitmaphipnum[hitmapchipnum][0] = i;
					Savehitmaphipnum[hitmapchipnum][1] = j;
					Savehitmaphipnum[hitmapchipnum][2] = MapChipDate[Star_Num][World_Num][Stage_Num][i][j];
					hitmapchipnum++;
				}
			}
			else
			{
				MapChips[i][j]->SetPart(0, 0);

				switch (MapChipDate[Star_Num][World_Num][Stage_Num][i][j])
				{
				case P:
					//プレイヤー
					sprite[0] = new CGameObject("assets/player.png", 14, 4, -1.77777777 + j * MAPCHIP_SIZE + MAPCHIP_SIZE / 2, 1 - i * MAPCHIP_SIZE - MAPCHIP_SIZE / 2, 0.15f, 0.15f);
					break;
				case M:
					fuel[fuelNum] = new CGameObject("assets/MoE.png", 1, 1, -1.77777777 + j * MAPCHIP_SIZE + MAPCHIP_SIZE / 2, 1 - i * MAPCHIP_SIZE - MAPCHIP_SIZE / 2, fuelSizeX, fuelSizeY);
					fuelPosX[fuelOrder] = -1.77777777 + j * MAPCHIP_SIZE + MAPCHIP_SIZE / 2;
					fuelPosY[fuelOrder] = 1 - i * MAPCHIP_SIZE - MAPCHIP_SIZE / 2;
					fuelOrder++;
					fuelNum++;
					break;
				case A:
					enemy[EnemyNum] = new CE_A(-1.77777777 + j * MAPCHIP_SIZE + MAPCHIP_SIZE / 2, 1 - i * MAPCHIP_SIZE - MAPCHIP_SIZE / 2);
					EnemyNum++;
					break;
				case B:
					//enemy[enemynum] = new CE_B(-1.77777777 + j * MAPCHIP_SIZE + MAPCHIP_SIZE / 2, 1 - i * MAPCHIP_SIZE - MAPCHIP_SIZE / 2);
					//enemynum++;
					break;

				case C:
					//enemy[enemynum] = new CE_C(-1.77777777 + j * MAPCHIP_SIZE + MAPCHIP_SIZE / 2, 1 - i * MAPCHIP_SIZE - MAPCHIP_SIZE / 2);
					//enemynum++;
					break;
				case D:
					//enemy[enemynum] = new CE_D(-1.77777777 + j * MAPCHIP_SIZE + MAPCHIP_SIZE / 2, 1 - i * MAPCHIP_SIZE - MAPCHIP_SIZE / 2);
					//enemynum++;
					break;
				case T:
					gimmick[gimmickNum] = new CGameObject("assets/turara.png", 1, 1, -1.77777777 + j * MAPCHIP_SIZE + MAPCHIP_SIZE / 2, 1 - i * MAPCHIP_SIZE - MAPCHIP_SIZE / 2, GIMMICKSIZEX, GIMMICKSIZEY);
					gimmickNum++;
					break;
				case G:
					gimmick[gimmickNum] = new CGameObject("assets/gareki.png", 1, 1, -1.77777777 + j * MAPCHIP_SIZE + MAPCHIP_SIZE / 2, (1 - i * MAPCHIP_SIZE - MAPCHIP_SIZE / 2) - 0.05f, GIMMICKSIZEX, GIMMICKSIZEY);
					gimmickNum++;
					break;
				}
			}
		}
	}

	circleSizeReal = circleSize;

	//それぞれのオブジェクト配列に画像のデータを読み込んで、初期化する

	//プレイヤー
	playerObj = sprite[0];
	playerObj->SetPart(0, 0);

	sprite[3] = new CGameObject("assets/moveCircle.png", 1, 1, 0.0f, 0.0f, circleSize, circleSize);
	sprite[3]->enabled = false;
	sprite[3]->SetColor(0.0f, 1.0f, 0.0f, 1.0f);

	sprite[10] = new CGameObject("assets/tpEffect1.png", 1, 1, 0.0f, 0.0f, 0.15f, 0.15f);
	sprite[11] = new CGameObject("assets/tpEffect2.png", 1, 1, 0.0f, 0.0f, 0.15f, 0.15f);
	sprite[12] = new CGameObject("assets/tpEffect3.png", 1, 1, 0.0f, 0.0f, 0.15f, 0.15f);

	sprite[16] = new CGameObject("assets/stageClear.png", 1, 1, 0.0f, 0.0f, 1.0f, 0.5f);

	// 移動の当たり判定
	sprite[17] = new CGameObject("assets/rect.png", 1, 1, 0, 0, 0, 0);
	sprite[17]->SetColor(157.0f / 255.0f, 204.0f / 255.0f, 224.0f / 255.0f, 0.9f);

	// 敵の当たり判定（矩形）
	sprite[18] = new CGameObject("assets/rect.png", 1, 1, 0.25f, 0.0f, 0.15f, 0.15f);
	sprite[18]->SetColor(0.0f, 1.0f, 0.0f, 0.3f);
	sprite[18]->enabled = true;

	// プレイヤーの当たり判定
	sprite[19] = new CGameObject("assets/rect.png", 1, 1, -0.25f, -0.7 + 0.15f / 2.0f, 0.15f * 0.8f, 0.15f * 0.8f);
	sprite[19]->SetColor(1.0f, 0.0f, 0.0f, 0.3f);
	sprite[19]->enabled = true;

	sprite[20] = new CGameObject("assets/UI_CLEAR_BG.png", 1, 1, 0.0f, 0.0f, 2.0f * (float)RESOLUTIONX / (float)RESOLUTIONY, 2.0f);

	// 敵の当たり判定（円）
	sprite[23] = new CGameObject("assets/collisionCircle.png", 1, 1, 0.25f, 0.0f, 0.15f, 0.15f);
	sprite[23]->SetColor(0.0f, 1.0f, 0.0f, 0.3f);
	sprite[23]->enabled = true;

	// 敵の当たり判定（円）
	sprite[24] = new CGameObject("assets/collisionCircle.png", 1, 1, 0.25f, 0.0f, 0.15f, 0.15f);
	sprite[24]->SetColor(0.0f, 1.0f, 0.0f, 0.3f);
	sprite[24]->enabled = true;

	// 体力のハート
	sprite[25] = new CGameObject("assets/UI_HP.png", 2, 1, -1.61f, 0.945f, 0.09f, 0.09f);
	sprite[26] = new CGameObject("assets/UI_HP.png", 2, 1, -1.51f, 0.945f, 0.09f, 0.09f);
	sprite[27] = new CGameObject("assets/UI_HP.png", 2, 1, -1.41f, 0.945f, 0.09f, 0.09f);
	sprite[25]->enabled = true;
	sprite[26]->enabled = true;
	sprite[27]->enabled = true;

	// 数字の画像
	sprite[28] = new CGameObject("assets/UI_number.png", 15, 1, 1.61f, 0.945f, 0.09f, 0.09f);
	sprite[28]->SetPart(1, 0);
	sprite[28]->enabled = true;

	BlackoutPanel = new CSprite("assets/EfectPanel.png", 1, 1, 0.0f, 0.0f, BACKGROUNDWIDTH, BACKGROUNDHEIGHT);
	BlackoutPanel->SetColor(0.0f, 0.0f, 0.0f, 0.0f);

	background = new CSprite*[6];
	background[0] = new CSprite("assets/background/BG_haisouko.png", 1, 1, 0.0f, 0.0f, BACKGROUNDWIDTH, BACKGROUNDHEIGHT);
	background[1] = new CSprite("assets/background/BG_iseki.png", 1, 1, 0.0f, 0.0f, BACKGROUNDWIDTH, BACKGROUNDHEIGHT);
	background[2] = new CSprite("assets/background/BG_icehaisouko.png", 1, 1, 0.0f, 0.0f, BACKGROUNDWIDTH, BACKGROUNDHEIGHT);
	background[3] = new CSprite("assets/background/BG_iceiseki.png", 1, 1, 0.0f, 0.0f, BACKGROUNDWIDTH, BACKGROUNDHEIGHT);
	background[4] = new CSprite("assets/background/BG_firehaisouko.png", 1, 1, 0.0f, 0.0f, BACKGROUNDWIDTH, BACKGROUNDHEIGHT);
	background[5] = new CSprite("assets/background/BG_fireiseki.png", 1, 1, 0.0f, 0.0f, BACKGROUNDWIDTH, BACKGROUNDHEIGHT);

	EffectTest[0] = new CEfect(false, "assets/bakuhatsutest.png", 6, 1, 0, 0, 0, 0);
	EffectTest[1] = new CEfect(false, "assets/EF_ExplosionSmall.png", 6, 1, 0, 0, 0, 0);
	EffectTest[2] = new CEfect(false, "assets/EF_ExplosionSmall_2.png", 6, 1, 0, 0, 0, 0);
	EffectTest[3] = new CEfect(false, "assets/EF_ExplosionBig_2.png", 10, 1, 0, 0, 0, 0);
	EffectTest[4] = new CEfect(false, "assets/EF_ExplosionBig.png", 10, 1, 0, 0, 0, 0);

	CGameObject::Init_moveV();

	soundObj->Play(SOUND_BGM000_VER2);

	stageClear = false;
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

		// Rキーでリセット
		if (inputObj->GetButtonPress(RESTART))
		{
			StageReset();
			Blackout = true;
			gameover = false;
			PlayerAlive = true;
			BlackoutPanelAlpha = 0.0f;
		}

		//プレイヤーの座標を取得
		DragonPosX = playerObj->GetPos().x;
		DragonPosY = playerObj->GetPos().y;

		//敵の更新処理
		for (int E = 0; E < EnemyNum; E++) {
			if (enemy[E]) 
			{
				enemy[E]->mSearch(playerObj->GetPos());

				//敵の移動判定
				enemy[E]->mMove();

				enemy[E]->mAnim();

				if (!enemy[E]->mNow_Blown_flg) {
					enemy[E]->Gravity();	//敵の重力

					enemy[E]->nowAir = true;

					//敵とマップチップとの当たり判定
					for (int i = 0; i < hitmapchipnum; i++) {

						if (Collision::RectAndRectHit(enemy[E]->GetPosAndSize(), MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize())) {

							int NowMapPosY = enemy[E]->GetMapChipPos().NumY;

							int NowMapPosX = enemy[E]->GetMapChipPos().NumX;

							if (Savehitmaphipnum[i][0] - 1 == NowMapPosY && Savehitmaphipnum[i][1] == NowMapPosX) {
								enemy[E]->SetPosY(MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize().posy + (MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize().sizey + enemy[E]->GetPosAndSize().sizey) / 2);
								enemy[E]->mMoveflg = true;
							}
							if ((Savehitmaphipnum[i][0] == NowMapPosY) && (Savehitmaphipnum[i][1] + 1 == NowMapPosX) && (enemy[E]->mMoveDir == MOVE_DIR_LEFT)) {
								enemy[E]->SetPosX(MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize().posx + (MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize().sizex + enemy[E]->GetPosAndSize().sizex) / 2 + 0.0001f);

								enemy[E]->mMoveDir = MOVE_DIR_RIGHT;
							}

							else if ((Savehitmaphipnum[i][0] == NowMapPosY) && (Savehitmaphipnum[i][1] - 1 == NowMapPosX) && (enemy[E]->mMoveDir == MOVE_DIR_RIGHT)) {
								enemy[E]->SetPosX(MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize().posx - (MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize().sizex + enemy[E]->GetPosAndSize().sizex) / 2 + 0.0001f);

								enemy[E]->mMoveDir = MOVE_DIR_LEFT;
							}

							enemy[E]->nowAir = false;
						}
					}
				}
			}
		}

		//瞬間移動できるかどうかのフラグ
		static bool Teleport_flg = false;

		// Rボタンで爆破可能状態にする
		// Lボタンで敵の追尾をオフにする
		if (inputObj->GetButtonPress(BREAKCIRCLE)) {
			sprite[3]->SetColor(1.0f, 0.0f, 0.0f, 1.0f);
			enemyBreak = true;
			enemyHoming = true;
		}
		else if (inputObj->GetButtonPress(HOMINGOFF)) {
			sprite[3]->SetColor(0.0f, 0.0f, 1.0f, 1.0f);
			enemyBreak = false;
			enemyHoming = false;
		}
		else {
			sprite[3]->SetColor(0.0f, 1.0f, 0.0f, 1.0f);
			enemyBreak = false;
			enemyHoming = true;
		}

		if (!stageClear) {
			//移動できる場合（瞬間移動してない場合）
			if (tpAnim == 0 && !tpAnimFlg && !gameover && !playerBlowAnim)
			{
				if (inputObj->isInput())	//インプットがあったら
				{
					if (circleSound) {
						soundObj->Play(SOUND_SE_CIRCLE01);
						circleSound = false;
					}

					if (Teleport_flg == false)
					{
						if (inputObj->GetAxis(UP))
						{
							DragonDirection = 0;

							sprite[17]->SetPos(DragonPosX, DragonPosY + circleSizeReal * 0.27f / 2.0f + 0.15f / 2.0f * 0.8f);
							sprite[17]->SetSize(0.005f, circleSizeReal * 0.27f);
							sprite[17]->rotationAngle = 0.0f;
						}
						if (inputObj->GetAxis(RIGHT))
						{
							DragonDirection = 1;

							sprite[17]->SetPos(DragonPosX + circleSizeReal * 0.27f / 2.0f + 0.15f / 2.0f * 0.8f, DragonPosY);
							sprite[17]->SetSize(circleSizeReal * 0.27f, 0.005f);
							sprite[17]->rotationAngle = 0.0f;
						}
						if (inputObj->GetAxis(DOWN))
						{
							DragonDirection = 2;

							sprite[17]->SetPos(DragonPosX, DragonPosY - circleSizeReal * 0.27f / 2.0f - 0.15f / 2.0f * 0.8f);
							sprite[17]->SetSize(0.005f, circleSizeReal * 0.27f);
							sprite[17]->rotationAngle = 0.0f;
						}
						if (inputObj->GetAxis(LEFT))
						{
							DragonDirection = 3;

							sprite[17]->SetPos(DragonPosX - circleSizeReal * 0.27f / 2.0f - 0.15f / 2.0f * 0.8f, DragonPosY);
							sprite[17]->SetSize(circleSizeReal * 0.27f, 0.005f);
							sprite[17]->rotationAngle = 0.0f;
						}
						if (inputObj->GetAxis(UPPER_LEFT))
						{
							DragonDirection = 4;

							sprite[17]->SetPos(DragonPosX + (circleSizeReal * 0.27f / 2.0f + 0.15f / 2.0f * 0.8f) * CGameObject::moveV[3].vx, DragonPosY + (circleSizeReal * 0.27f / 2.0f + 0.15f / 2.0f * 0.8f) * CGameObject::moveV[3].vy);
							sprite[17]->SetSize(circleSizeReal * 0.27f, 0.005f);
							sprite[17]->rotationAngle = PI * 3.0f / 4.0f;
						}
						if (inputObj->GetAxis(UPPER_RIGHT))
						{
							DragonDirection = 5;

							sprite[17]->SetPos(DragonPosX + (circleSizeReal * 0.27f / 2.0f + 0.15f / 2.0f * 0.8f) * CGameObject::moveV[1].vx, DragonPosY + (circleSizeReal * 0.27f / 2.0f + 0.15f / 2.0f * 0.8f) * CGameObject::moveV[1].vy);
							sprite[17]->SetSize(circleSizeReal * 0.27f, 0.005f);
							sprite[17]->rotationAngle = PI * 1.0f / 4.0f;
						}
						if (inputObj->GetAxis(LOWER_LEFT))
						{
							DragonDirection = 6;

							sprite[17]->SetPos(DragonPosX + (circleSizeReal * 0.27f / 2.0f + 0.15f / 2.0f * 0.8f) * CGameObject::moveV[5].vx, DragonPosY + (circleSizeReal * 0.27f / 2.0f + 0.15f / 2.0f * 0.8f) * CGameObject::moveV[5].vy);
							sprite[17]->SetSize(circleSizeReal * 0.27f, 0.005f);
							sprite[17]->rotationAngle = PI * 5.0f / 4.0f;
						}
						if (inputObj->GetAxis(LOWER_RIGHT))
						{
							DragonDirection = 7;

							sprite[17]->SetPos(DragonPosX + (circleSizeReal * 0.27f / 2.0f + 0.15f / 2.0f * 0.8f) * CGameObject::moveV[7].vx, DragonPosY + (circleSizeReal * 0.27f / 2.0f + 0.15f / 2.0f * 0.8f) * CGameObject::moveV[7].vy);
							sprite[17]->SetSize(circleSizeReal * 0.27f, 0.005f);
							sprite[17]->rotationAngle = PI * 7.0f / 4.0f;
						}
						if (inputObj->GetAxis(R22d5))
						{
							sprite[17]->SetPos(DragonPosX, DragonPosY);
							sprite[17]->SetSize(circleSizeReal * 0.27f, 0.005f);
							sprite[17]->rotationAngle = PI / 8.0f;
						}
						if (inputObj->GetAxis(R67d5))
						{
							sprite[17]->SetPos(DragonPosX, DragonPosY);
							sprite[17]->SetSize(circleSizeReal * 0.27f, 0.005f);
							sprite[17]->rotationAngle = PI * 3.0f / 8.0f;
						}
						if (inputObj->GetAxis(R112d5))
						{
							sprite[17]->SetPos(DragonPosX, DragonPosY);
							sprite[17]->SetSize(circleSizeReal * 0.27f, 0.005f);
							sprite[17]->rotationAngle = PI * 5.0f / 8.0f;
						}
						if (inputObj->GetAxis(R157d5))
						{
							sprite[17]->SetPos(DragonPosX, DragonPosY);
							sprite[17]->SetSize(circleSizeReal * 0.27f, 0.005f);
							sprite[17]->rotationAngle = PI * 7.0f / 8.0f;
						}
						if (inputObj->GetAxis(R202d5))
						{
							sprite[17]->SetPos(DragonPosX, DragonPosY);
							sprite[17]->SetSize(circleSizeReal * 0.27f, 0.005f);
							sprite[17]->rotationAngle = PI * 9.0f / 8.0f;
						}
						if (inputObj->GetAxis(R247d5))
						{
							sprite[17]->SetPos(DragonPosX, DragonPosY);
							sprite[17]->SetSize(circleSizeReal * 0.27f, 0.005f);
							sprite[17]->rotationAngle = PI * 11.0f / 8.0f;
						}
						if (inputObj->GetAxis(R292d5))
						{
							sprite[17]->SetPos(DragonPosX, DragonPosY);
							sprite[17]->SetSize(circleSizeReal * 0.27f, 0.005f);
							sprite[17]->rotationAngle = PI * 13.0f / 8.0f;
						}
						if (inputObj->GetAxis(R337d5))
						{
							sprite[17]->SetPos(DragonPosX, DragonPosY);
							sprite[17]->SetSize(circleSizeReal * 0.27f, 0.005f);
							sprite[17]->rotationAngle = PI * 15.0f / 8.0f;
						}

						stick_flg = true;

						circleSizeReal += CIRCLE_SIZE_ADDITIONAL_SPEED;

						if (circleSizeReal >= CIRCLE_SIZE_MAXIMUM) {
							circleSizeReal = CIRCLE_SIZE_MAXIMUM;
						}

						showCircle = true;

						sprite[3]->SetSize(circleSizeReal * 0.566f, circleSizeReal * 0.566f);
						sprite[3]->enabled = showCircle;


					}

					if (collisionAppear)
						sprite[17]->enabled = true;
				}
				else if (stick_flg) {
					showCircle = false;
					sprite[3]->enabled = showCircle;
					stick_flg = false;
					Teleport_flg = true;
					tpAnimFlg = true;
					tpAnimPart = 9;

					// テレポート音再生
					switch (teleportSoundPattern)
					{
					case 1:
						soundObj->Play(SOUND_SE01);
						break;
					case 2:
						soundObj->Play(SOUND_SE02);
						break;
					case 3:
						soundObj->Play(SOUND_SE03);
						break;
					case 4:
						soundObj->Play(SOUND_SE04);
						break;
					case 5:
						soundObj->Play(SOUND_SE05);
						break;
					case 6:
						soundObj->Play(SOUND_SE06);
						break;
					}


					sprite[17]->enabled = false;

					circleSound = true;
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

			// プレイヤーのテレポート処理
			if (PlayerAlive) {
				NewMove();
			}

			// 敵の吹っ飛び処理
			for (int i = 0; i < EnemyNum; i++) {
				if (enemy[i] && enemy[i]->mNow_Blown_flg) {
					EnemyBlow(i);
				}
			}

			playerObj->SetPos(DragonPosX, DragonPosY);

			//範囲表示オブジェクトの位置を設定
			sprite[3]->SetPos(playerObj->GetPos().x, playerObj->GetPos().y);

			sprite[20]->enabled = false;

			// ダメージ処理
			for (int E = 0; E < EnemyNum; E++) {
				if (!tpAnimFlg && !playerBlowAnim) 
				{
					rectA.SetPos(DragonPosX, DragonPosY);
					rectA.SetSize(0.15f * 0.8f, 0.15f * 0.8f);
					circleA.SetPos(enemy[E]->GetPos().x, enemy[E]->GetPos().y);
					circleA.SetSize(enemy[E]->GetSize().x * 0.8f / 2.0f);

					if (!justAfterDamage) {
						enemy[E]->mEnemyHit_flg = Collision::CircleAndRectTest(circleA, rectA);
					}
					else {
						enemy[E]->mEnemyHit_flg = false;

						invincibleCnt++;

						if (invincibleCnt % 40 >= 0 && invincibleCnt % 40 <= 19) {
							playerObj->SetColor(1.0f, 1.0f, 1.0f, 0.0f);
							switch (playerHp) {
							case 2:
								sprite[27]->SetColor(1.0f, 1.0f, 1.0f, 0.0f);
								break;
							case 1:
								sprite[26]->SetColor(1.0f, 1.0f, 1.0f, 0.0f);
								break;
							case 0:
								sprite[25]->SetColor(1.0f, 1.0f, 1.0f, 0.0f);
								break;
							}
						}
						else if (invincibleCnt % 40 >= 20 && invincibleCnt % 40 <= 39) {
							playerObj->SetColor(1.0f, 1.0f, 1.0f, 1.0f);
							switch (playerHp) {
							case 2:
								sprite[27]->SetColor(1.0f, 1.0f, 1.0f, 1.0f);
								break;
							case 1:
								sprite[26]->SetColor(1.0f, 1.0f, 1.0f, 1.0f);
								break;
							case 0:
								sprite[25]->SetColor(1.0f, 1.0f, 1.0f, 1.0f);
								break;
							}
						}

						if (invincibleCnt > PLAYER_INVINCIBLE_COUNT) {
							justAfterDamage = false;
							invincibleCnt = 0;
							playerObj->SetColor(1.0f, 1.0f, 1.0f, 1.0f);
							switch (playerHp) {
							case 2:
								sprite[27]->SetColor(1.0f, 1.0f, 1.0f, 1.0f);
								break;
							case 1:
								sprite[26]->SetColor(1.0f, 1.0f, 1.0f, 1.0f);
								break;
							case 0:
								sprite[25]->SetColor(1.0f, 1.0f, 1.0f, 1.0f);
								break;
							}
						}
					}

					if (enemy[E]->mEnemyHit_flg) {
						playerHp--;
						justAfterDamage = true;
					}

					if (playerHp <= 0) {
						PlayerAlive = false;
					}
				}
			}

			// HPの表示
			switch (playerHp) {
			case 3:
				sprite[25]->SetPart(0, 0);
				sprite[26]->SetPart(0, 0);
				sprite[27]->SetPart(0, 0);
				break;
			case 2:
				sprite[25]->SetPart(0, 0);
				sprite[26]->SetPart(0, 0);
				sprite[27]->SetPart(1, 0);
				break;
			case 1:
				sprite[25]->SetPart(0, 0);
				sprite[26]->SetPart(1, 0);
				sprite[27]->SetPart(1, 0);
				break;
			case 0:
				sprite[25]->SetPart(1, 0);
				sprite[26]->SetPart(1, 0);
				sprite[27]->SetPart(1, 0);
				break;
			}
		}
		else {
			sprite[20]->enabled = true;
		}

		// ゲームオーバー処理
		if (!PlayerAlive) {
			if (!gameover) {
				EffectTest[0]->SetPos(DragonPosX, DragonPosY);
				EffectTest[0]->SetSize(0.15f, 0.15f);
				DragonPosX = -10.0f;
				DragonPosY = -10.0f;
				playerObj->SetPos(DragonPosX, DragonPosY);
				gameover = true;
				Blackout = true;
			}
			else {
				if (Blackout) {
					BlackoutPanelAlpha += 0.003f;
					if (BlackoutPanelAlpha >= 1.0f) {
						BlackoutPanelAlpha = 1.0f;
						Blackout = false;
					}
				}
				else {
					if (BlackoutPanelAlpha == 1.0f) {
						StageReset();
					}
					BlackoutPanelAlpha -= 0.003f;
					if (BlackoutPanelAlpha <= 0.0f) {
						BlackoutPanelAlpha = 0.0f;
						Blackout = true;
						gameover = false;
						PlayerAlive = true;
					}
				}

				BlackoutPanel->SetColor(0.0f, 0.0f, 0.0f, BlackoutPanelAlpha);
			}
		}

		for (int E = 0; E < EnemyNum; E++) {
			if (enemyCollisionShape == 1) {
				sprite[18]->SetPos(enemy[E]->GetPos().x, enemy[E]->GetPos().y);
				sprite[18]->SetSize(enemy[E]->GetSize().x * 0.8f, enemy[E]->GetSize().y * 0.8f);
			}
			else if (enemyCollisionShape == 2) {
				sprite[24]->SetPos(enemy[E]->GetPos().x, enemy[E]->GetPos().y);
				sprite[24]->SetSize(enemy[E]->GetSize().x * 0.8f, enemy[E]->GetSize().y * 0.8f);
			}
		}

		sprite[19]->SetPos(DragonPosX, DragonPosY);

		if (collisionAppear) {
			if (enemyCollisionShape == 1) {
				sprite[18]->enabled = true;
			}
			else if (enemyCollisionShape == 2) {
				sprite[24]->enabled = true;
			}
			sprite[19]->enabled = true;
		}
		else {
			sprite[17]->enabled = false;
			sprite[18]->enabled = false;
			sprite[19]->enabled = false;
			sprite[24]->enabled = false;
		}

		for (int E = 0; E < EnemyNum; E++) {
			if (!enemy[E]->mEnemyAlive)
			{
				switch (getFuel) {
				case 0:
					if (CEfect::EfectCnt != 0) {
						EffectTest[1]->Anim();
					}
					break;
				case 1:
					if (CEfect::EfectCnt != 0) {
						EffectTest[2]->Anim();
					}
					break;
				case 2:
					if (CEfect::EfectCnt != 0) {
						EffectTest[3]->Anim();
					}
					break;
				case 3:
					if (CEfect::EfectCnt != 0) {
						EffectTest[4]->Anim();
					}
					break;
				}
			}
		}

		playerAnimCnt++;

		if (playerAnimCnt >= animSpeed && !tpAnimFlg)
		{
			playerAnimPartX++;

			int holder = 0;

			switch (playerAnimPartY)
			{
			case 0: holder = 7;
				break;
			case 1: holder = 14;
				break;
			case 2: holder = 11;
				break;
			case 3: holder = 11;
				break;
			}

			if (playerAnimPartX == 8 && playerAnimPartY != 0)
				soundObj->Play(SE_SWING);

			if (playerAnimPartX >= holder)
			{
				playerAnimPartX = 0;
				playerAnimPartY = 0;
				animSpeed = ANIMSPEED;
				playerBlowAnim = false;
			}

			playerObj->SetPart(playerAnimPartX, playerAnimPartY);

			playerAnimCnt = 0;
		}

		if (!PlayerAlive)
		{
			if (CEfect::EfectCnt != 0) {
				EffectTest[0]->Anim();
			}
		}

		if (!stageClear)
			Draw();
		else
			Uninit();
	}

	return true;
}

void GameClass::Draw()
{
	float clearColor[4] = { 0.0f, 0.0f, 0.0f, 1.0f };

	Direct3D_GetContext()->ClearRenderTargetView(Direct3D_GetRenderTargetView(), clearColor);

	background[((World_Num + 1) * (Star_Num + 1)) - 1]->Draw();

	for (int i = 0; i < hitmapchipnum; i++) {
		MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->Draw();
	}

	if (PlayerAlive) {
		BlackoutPanel->Draw();
	}

	for (int i = 0; i < EnemyNum; i++) {
		if (enemy[i])
			enemy[i]->Draw();
	}

	playerObj->Draw();

	for (int a = 0; a < MAXSPRITE; a++)
	{
		if (sprite[a] && sprite[a]->enabled)
			sprite[a]->Draw();
	}

	for (int i = 0; i < 5; i++) {
		if (CEfect::EfectCnt != 0) {
			if (!EffectTest[i]->reproducing_complete) {
				EffectTest[i]->Draw();
			}
		}
	}

	for (int a = 0; a < GIMMICKNUM; a++)
	{
		if (gimmick[a] != NULL)
			gimmick[a]->Draw();
	}

	for (int i = 0; i < 3; i++)
		fuel[i]->Draw();

	if (!PlayerAlive) {
		BlackoutPanel->Draw();
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

	for (int i = 0; i < EnemyNum; i++) {
		if (enemy[i])
			delete enemy[i];
	}

	delete[] enemy;

	for (int i = 1; i < MAXSPRITE; i++) {
		if (sprite[i])
			delete sprite[i];
	}

	delete[] sprite;
}

float Angle(float x1, float y1, float x2, float y2)
{
	double radian = atan2((double)(y1 - y2), (double)(x1 - x2));

	return (float)radian;
}

void GameClass::NewMove()
{
	if (tpAnim <= 0)					//通常の時
		playerObj = sprite[0];

	if (tpAnim == 1) {
		for (int E = 0; E < EnemyNum; E++) {
			TeleEnemyPosX = enemy[E]->GetPos().x;
			TeleEnemyPosY = enemy[E]->GetPos().y;

			if (enemyCollisionShape == 1) {
				rectB.SetPos(enemy[E]->GetPos().x, enemy[E]->GetPos().y);
				rectB.SetSize(enemy[E]->GetSize().x * 0.8f, enemy[E]->GetSize().y * 0.8f);
				circleB.SetPos(DragonPosX, DragonPosY);
				circleB.SetSize(circleSizeReal * 0.27f);

				if (enemyHoming) {
					if (circleHoming) {
						enemy[E]->mEnemyHit_flg = Collision::CircleAndRectTest(circleB, rectB);
					}
					else {
						switch (DragonDirection)
						{
							//up
						case 0:
							enemy[E]->mEnemyHit_flg = Collision::RectAndLineTest(rectB, DragonPosX, DragonPosY + 0.15f / 2.0f * 0.8f, DragonPosX, DragonPosY + circleSizeReal * 0.27f + 0.15f / 2.0f * 0.8f);
							break;

							//right
						case 1:
							enemy[E]->mEnemyHit_flg = Collision::RectAndLineTest(rectB, DragonPosX + 0.15f / 2.0f * 0.8f, DragonPosY, DragonPosX + circleSizeReal * 0.27f + 0.15f / 2.0f * 0.8f, DragonPosY);
							break;

							//down
						case 2:
							enemy[E]->mEnemyHit_flg = Collision::RectAndLineTest(rectB, DragonPosX, DragonPosY - 0.15f / 2.0f * 0.8f, DragonPosX, DragonPosY - circleSizeReal * 0.27f - 0.15f / 2.0f * 0.8f);
							break;

							//left
						case 3:
							enemy[E]->mEnemyHit_flg = Collision::RectAndLineTest(rectB, DragonPosX - 0.15f / 2.0f * 0.8f, DragonPosY, DragonPosX - circleSizeReal * 0.27f - 0.15f / 2.0f * 0.8f, DragonPosY);
							break;

							// 左上
						case 4:
							enemy[E]->mEnemyHit_flg = Collision::RectAndLineTest(rectB, DragonPosX + 0.15f / 2.0f * 0.8f * CGameObject::moveV[3].vx, DragonPosY + 0.15f / 2.0f * 0.8f * CGameObject::moveV[3].vy, DragonPosX + circleSizeReal * 0.27f * CGameObject::moveV[3].vx + 0.15f / 2.0f * 0.8f * CGameObject::moveV[3].vx, DragonPosY + circleSizeReal * 0.27f * CGameObject::moveV[3].vy + 0.15f / 2.0f * 0.8f * CGameObject::moveV[3].vy);
							break;

							// 右上
						case 5:
							enemy[E]->mEnemyHit_flg = Collision::RectAndLineTest(rectB, DragonPosX + 0.15f / 2.0f * 0.8f * CGameObject::moveV[1].vx, DragonPosY + 0.15f / 2.0f * 0.8f * CGameObject::moveV[1].vy, DragonPosX + circleSizeReal * 0.27f * CGameObject::moveV[1].vx + 0.15f / 2.0f * 0.8f * CGameObject::moveV[1].vx, DragonPosY + circleSizeReal * 0.27f * CGameObject::moveV[1].vy + 0.15f / 2.0f * 0.8f * CGameObject::moveV[1].vy);
							break;

							// 左下
						case 6:
							enemy[E]->mEnemyHit_flg = Collision::RectAndLineTest(rectB, DragonPosX + 0.15f / 2.0f * 0.8f * CGameObject::moveV[5].vx, DragonPosY + 0.15f / 2.0f * 0.8f * CGameObject::moveV[5].vy, DragonPosX + circleSizeReal * 0.27f * CGameObject::moveV[5].vx + 0.15f / 2.0f * 0.8f * CGameObject::moveV[5].vx, DragonPosY + circleSizeReal * 0.27f * CGameObject::moveV[5].vy + 0.15f / 2.0f * 0.8f * CGameObject::moveV[5].vy);
							break;

							// 右下
						case 7:
							enemy[E]->mEnemyHit_flg = Collision::RectAndLineTest(rectB, DragonPosX + 0.15f / 2.0f * 0.8f * CGameObject::moveV[7].vx, DragonPosY + 0.15f / 2.0f * 0.8f * CGameObject::moveV[7].vy, DragonPosX + circleSizeReal * 0.27f * CGameObject::moveV[7].vx + 0.15f / 2.0f * 0.8f * CGameObject::moveV[7].vx, DragonPosY + circleSizeReal * 0.27f * CGameObject::moveV[7].vy + 0.15f / 2.0f * 0.8f * CGameObject::moveV[7].vy);
							break;
						}
					}
				}
			}
			else if (enemyCollisionShape == 2) {
				circleA.SetPos(enemy[E]->GetPos().x, enemy[E]->GetPos().y);
				circleA.SetSize(enemy[E]->GetSize().x * 0.8f / 2.0f);
				circleB.SetPos(DragonPosX, DragonPosY);
				circleB.SetSize(circleSizeReal * 0.27f);

				if (enemyHoming) {
					if (circleHoming) {
						enemy[E]->mEnemyHit_flg = Collision::CircleAndCircleTest(circleA, circleB);
					}
					else {
						switch (DragonDirection)
						{
							//up
						case 0:
							enemy[E]->mEnemyHit_flg = Collision::CircleAndLineTest(circleA, DragonPosX, DragonPosY + 0.15f / 2.0f * 0.8f, DragonPosX, DragonPosY + circleSizeReal * 0.27f + 0.15f / 2.0f * 0.8f);
							break;

							//right
						case 1:
							enemy[E]->mEnemyHit_flg = Collision::CircleAndLineTest(circleA, DragonPosX + 0.15f / 2.0f * 0.8f, DragonPosY, DragonPosX + circleSizeReal * 0.27f + 0.15f / 2.0f * 0.8f, DragonPosY);
							break;

							//down
						case 2:
							enemy[E]->mEnemyHit_flg = Collision::CircleAndLineTest(circleA, DragonPosX, DragonPosY - 0.15f / 2.0f * 0.8f, DragonPosX, DragonPosY - circleSizeReal * 0.27f - 0.15f / 2.0f * 0.8f);
							break;

							//left
						case 3:
							enemy[E]->mEnemyHit_flg = Collision::CircleAndLineTest(circleA, DragonPosX - 0.15f / 2.0f * 0.8f, DragonPosY, DragonPosX - circleSizeReal * 0.27f - 0.15f / 2.0f * 0.8f, DragonPosY);
							break;

							// 左上
						case 4:
							enemy[E]->mEnemyHit_flg = Collision::CircleAndLineTest(circleA, DragonPosX + 0.15f / 2.0f * 0.8f * CGameObject::moveV[3].vx, DragonPosY + 0.15f / 2.0f * 0.8f * CGameObject::moveV[3].vy, DragonPosX + circleSizeReal * 0.27f * CGameObject::moveV[3].vx + 0.15f / 2.0f * 0.8f * CGameObject::moveV[3].vx, DragonPosY + circleSizeReal * 0.27f * CGameObject::moveV[3].vy + 0.15f / 2.0f * 0.8f * CGameObject::moveV[3].vy);
							break;

							// 右上
						case 5:
							enemy[E]->mEnemyHit_flg = Collision::CircleAndLineTest(circleA, DragonPosX + 0.15f / 2.0f * 0.8f * CGameObject::moveV[1].vx, DragonPosY + 0.15f / 2.0f * 0.8f * CGameObject::moveV[1].vy, DragonPosX + circleSizeReal * 0.27f * CGameObject::moveV[1].vx + 0.15f / 2.0f * 0.8f * CGameObject::moveV[1].vx, DragonPosY + circleSizeReal * 0.27f * CGameObject::moveV[1].vy + 0.15f / 2.0f * 0.8f * CGameObject::moveV[1].vy);
							break;

							// 左下
						case 6:
							enemy[E]->mEnemyHit_flg = Collision::CircleAndLineTest(circleA, DragonPosX + 0.15f / 2.0f * 0.8f * CGameObject::moveV[5].vx, DragonPosY + 0.15f / 2.0f * 0.8f * CGameObject::moveV[5].vy, DragonPosX + circleSizeReal * 0.27f * CGameObject::moveV[5].vx + 0.15f / 2.0f * 0.8f * CGameObject::moveV[5].vx, DragonPosY + circleSizeReal * 0.27f * CGameObject::moveV[5].vy + 0.15f / 2.0f * 0.8f * CGameObject::moveV[5].vy);
							break;

							// 右下
						case 7:
							enemy[E]->mEnemyHit_flg = Collision::CircleAndLineTest(circleA, DragonPosX + 0.15f / 2.0f * 0.8f * CGameObject::moveV[7].vx, DragonPosY + 0.15f / 2.0f * 0.8f * CGameObject::moveV[7].vy, DragonPosX + circleSizeReal * 0.27f * CGameObject::moveV[7].vx + 0.15f / 2.0f * 0.8f * CGameObject::moveV[7].vx, DragonPosY + circleSizeReal * 0.27f * CGameObject::moveV[7].vy + 0.15f / 2.0f * 0.8f * CGameObject::moveV[7].vy);
							break;
						}
					}
				}
			}

			if (enemy[E]->mEnemyHit_flg) {
				enemy[E]->mBlownDir = BLOW_DIR_NONE;

				if (enemyBreak && enemy[E]->mEnemyCombo >= CAN_EXPLODE_ENEMY_COUNT) {
					enemy[E]->mAbleBroken = true;
				}
			}
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
		for (int E = 0; E < EnemyNum; E++) {
			Old_Player_PosX = DragonPosX;
			Old_Player_PosY = DragonPosY;

			if (!enemy[E]->mAbleBroken) {
				switch (DragonDirection)
				{
					//up
				case 0:
					if (enemy[E]->mEnemyHit_flg) {
						if (blowOffPattern == 3) {
							if (TeleEnemyPosY + enemy[E]->GetSize().y / 2.0f >= DragonPosY + circleSizeReal * 0.27f + 0.15f / 2.0f * 0.8f) {
								goAround = false;
							}
							else {
								goAround = true;
							}
						}

						if (blowOffPattern == 1 || (blowOffPattern == 3 && !goAround)) {
							DragonPosX = enemy[E]->GetPos().x;
							DragonPosY = enemy[E]->GetPos().y - enemy[E]->GetSize().y / 2.0f;

							enemy[E]->mBlownDir0 = BLOW_DIR_UP;
						}
						else if (blowOffPattern == 2 || (blowOffPattern == 3 && goAround)) {
							DragonPosX = enemy[E]->GetPos().x;
							DragonPosY = enemy[E]->GetPos().y + enemy[E]->GetSize().y / 2.0f;

							enemy[E]->mBlownDir0 = BLOW_DIR_DOWN;
						}

						//GhostMoveDir = MOVE_DIR_NONE;
						enemy[E]->mStartBlown_flg = true;
					}
					else {
						DragonPosY += circleSizeReal * 0.27f;
					}
					break;

					//right
				case 1:
					if (enemy[E]->mEnemyHit_flg) {
						if (blowOffPattern == 3) {
							if (TeleEnemyPosX + enemy[E]->GetSize().x / 2.0f >= DragonPosX + circleSizeReal * 0.27f + 0.15f / 2.0f * 0.8f) {
								goAround = false;
							}
							else {
								goAround = true;
							}
						}

						if (blowOffPattern == 1 || (blowOffPattern == 3 && !goAround)) {
							DragonPosX = enemy[E]->GetPos().x - enemy[E]->GetSize().x / 2.0f;
							DragonPosY = enemy[E]->GetPos().y;

							enemy[E]->mBlownDir0 = BLOW_DIR_RIGHT;
						}
						else if (blowOffPattern == 2 || (blowOffPattern == 3 && goAround)) {
							DragonPosX = enemy[E]->GetPos().x + enemy[E]->GetSize().x / 2.0f;
							DragonPosY = enemy[E]->GetPos().y;

							enemy[E]->mBlownDir0 = BLOW_DIR_LEFT;
						}

						//GhostMoveDir = MOVE_DIR_NONE;
						enemy[E]->mStartBlown_flg = true;
					}
					else {
						DragonPosX += circleSizeReal * 0.27f;
					}
					break;

					//down
				case 2:
					if (enemy[E]->mEnemyHit_flg) {
						if (blowOffPattern == 3) {
							if (TeleEnemyPosY - enemy[E]->GetSize().y / 2.0f <= DragonPosY - circleSizeReal * 0.27f - 0.15f / 2.0f * 0.8f) {
								goAround = false;
							}
							else {
								goAround = true;
							}
						}

						if (blowOffPattern == 1 || (blowOffPattern == 3 && !goAround)) {
							DragonPosX = enemy[E]->GetPos().x;
							DragonPosY = enemy[E]->GetPos().y + enemy[E]->GetSize().y / 2.0f;

							enemy[E]->mBlownDir0 = BLOW_DIR_DOWN;
						}
						else if (blowOffPattern == 2 || (blowOffPattern == 3 && goAround)) {
							DragonPosX = enemy[E]->GetPos().x;
							DragonPosY = enemy[E]->GetPos().y - enemy[E]->GetSize().y / 2.0f;

							enemy[E]->mBlownDir0 = BLOW_DIR_UP;
						}

						//GhostMoveDir = MOVE_DIR_NONE;
						enemy[E]->mStartBlown_flg = true;
					}
					else {
						DragonPosY -= circleSizeReal * 0.27f;
					}
					break;

					//left
				case 3:
					if (enemy[E]->mEnemyHit_flg) {
						if (blowOffPattern == 3) {
							if (TeleEnemyPosX - enemy[E]->GetSize().x / 2.0f <= DragonPosX - circleSizeReal * 0.27f - 0.15f / 2.0f * 0.8f) {
								goAround = false;
							}
							else {
								goAround = true;
							}
						}

						if (blowOffPattern == 1 || (blowOffPattern == 3 && !goAround)) {
							DragonPosX = enemy[E]->GetPos().x + enemy[E]->GetSize().x / 2.0f;
							DragonPosY = enemy[E]->GetPos().y;

							enemy[E]->mBlownDir0 = BLOW_DIR_LEFT;
						}
						else if (blowOffPattern == 2 || (blowOffPattern == 3 && goAround)) {
							DragonPosX = enemy[E]->GetPos().x - enemy[E]->GetSize().x / 2.0f;
							DragonPosY = enemy[E]->GetPos().y;

							enemy[E]->mBlownDir0 = BLOW_DIR_RIGHT;
						}

						//GhostMoveDir = MOVE_DIR_NONE;
						enemy[E]->mStartBlown_flg = true;
					}
					else {
						DragonPosX -= circleSizeReal * 0.27f;
					}
					break;

					// 左上
				case 4:
					if (enemy[E]->mEnemyHit_flg) {
						if (blowOffPattern == 3) {
							if (enemyCollisionShape == 1) {
								if (TeleEnemyPosX - enemy[E]->GetSize().x / 2.0f <= DragonPosX + circleSizeReal * 0.27f * CGameObject::moveV[3].vx + 0.15f / 2.0f * 0.8f * CGameObject::moveV[3].vx || TeleEnemyPosY + enemy[E]->GetSize().y / 2.0f >= DragonPosY + circleSizeReal * 0.27f * CGameObject::moveV[3].vy + 0.15f / 2.0f * 0.8f * CGameObject::moveV[3].vy) {
									goAround = false;
								}
								else {
									goAround = true;
								}
							}
							else if (enemyCollisionShape == 2) {
								if (TeleEnemyPosX - enemy[E]->GetSize().x / 2.0f * CGameObject::moveV[3].vx <= DragonPosX + circleSizeReal * 0.27f * CGameObject::moveV[3].vx + 0.15f / 2.0f * 0.8f * CGameObject::moveV[3].vx || TeleEnemyPosY + enemy[E]->GetSize().y / 2.0f * CGameObject::moveV[3].vy >= DragonPosY + circleSizeReal * 0.27f * CGameObject::moveV[3].vy + 0.15f / 2.0f * 0.8f * CGameObject::moveV[3].vy) {
									goAround = false;
								}
								else {
									goAround = true;
								}
							}
						}

						if (blowOffPattern == 1 || (blowOffPattern == 3 && !goAround)) {
							DragonPosX = enemy[E]->GetPos().x + enemy[E]->GetSize().x / 2.0f;
							DragonPosY = enemy[E]->GetPos().y - enemy[E]->GetSize().y / 2.0f;

							enemy[E]->mBlownDir0 = BLOW_DIR_UPPER_LEFT;
						}
						else if (blowOffPattern == 2 || (blowOffPattern == 3 && goAround)) {
							DragonPosX = enemy[E]->GetPos().x - enemy[E]->GetSize().x / 2.0f;
							DragonPosY = enemy[E]->GetPos().y + enemy[E]->GetSize().y / 2.0f;

							enemy[E]->mBlownDir0 = BLOW_DIR_LOWER_RIGHT;
						}

						//GhostMoveDir = MOVE_DIR_NONE;
						enemy[E]->mStartBlown_flg = true;
					}
					else {
						DragonPosX += circleSizeReal * 0.27f * CGameObject::moveV[3].vx;
						DragonPosY += circleSizeReal * 0.27f * CGameObject::moveV[3].vy;
					}
					break;

					// 右上
				case 5:
					if (enemy[E]->mEnemyHit_flg) {
						if (blowOffPattern == 3) {
							if (enemyCollisionShape == 1) {
								if (TeleEnemyPosX + enemy[E]->GetSize().x / 2.0f >= DragonPosX + circleSizeReal * 0.27f * CGameObject::moveV[1].vx + 0.15f / 2.0f * 0.8f * CGameObject::moveV[1].vx || TeleEnemyPosY + enemy[E]->GetSize().y / 2.0f >= DragonPosY + circleSizeReal * 0.27f * CGameObject::moveV[1].vy + 0.15f / 2.0f * 0.8f * CGameObject::moveV[1].vy) {
									goAround = false;
								}
								else {
									goAround = true;
								}
							}
							else if (enemyCollisionShape == 2) {
								if (TeleEnemyPosX + enemy[E]->GetSize().x / 2.0f * CGameObject::moveV[1].vx >= DragonPosX + circleSizeReal * 0.27f * CGameObject::moveV[1].vx + 0.15f / 2.0f * 0.8f * CGameObject::moveV[1].vx || TeleEnemyPosY + enemy[E]->GetSize().y / 2.0f * CGameObject::moveV[1].vy >= DragonPosY + circleSizeReal * 0.27f * CGameObject::moveV[1].vy + 0.15f / 2.0f * 0.8f * CGameObject::moveV[1].vy) {
									goAround = false;
								}
								else {
									goAround = true;
								}
							}
						}

						if (blowOffPattern == 1 || (blowOffPattern == 3 && !goAround)) {
							DragonPosX = enemy[E]->GetPos().x - enemy[E]->GetSize().x / 2.0f;
							DragonPosY = enemy[E]->GetPos().y - enemy[E]->GetSize().y / 2.0f;

							enemy[E]->mBlownDir0 = BLOW_DIR_UPPER_RIGHT;
						}
						else if (blowOffPattern == 2 || (blowOffPattern == 3 && goAround)) {
							DragonPosX = enemy[E]->GetPos().x + enemy[E]->GetSize().x / 2.0f;
							DragonPosY = enemy[E]->GetPos().y + enemy[E]->GetSize().y / 2.0f;

							enemy[E]->mBlownDir0 = BLOW_DIR_LOWER_LEFT;
						}

						//GhostMoveDir = MOVE_DIR_NONE;
						enemy[E]->mStartBlown_flg = true;
					}
					else {
						DragonPosX += circleSizeReal * 0.27f * CGameObject::moveV[1].vx;
						DragonPosY += circleSizeReal * 0.27f * CGameObject::moveV[1].vy;
					}
					break;

					// 左下
				case 6:
					if (enemy[E]->mEnemyHit_flg) {
						if (blowOffPattern == 3) {
							if (enemyCollisionShape == 1) {
								if (TeleEnemyPosX - enemy[E]->GetSize().x / 2.0f <= DragonPosX + circleSizeReal * 0.27f * CGameObject::moveV[5].vx + 0.15f / 2.0f * 0.8f * CGameObject::moveV[5].vx || TeleEnemyPosY - enemy[E]->GetSize().y / 2.0f <= DragonPosY + circleSizeReal * 0.27f * CGameObject::moveV[5].vy + 0.15f / 2.0f * 0.8f * CGameObject::moveV[5].vy) {
									goAround = false;
								}
								else {
									goAround = true;
								}
							}
							else if (enemyCollisionShape == 2) {
								if (TeleEnemyPosX - enemy[E]->GetSize().x / 2.0f * CGameObject::moveV[5].vx <= DragonPosX + circleSizeReal * 0.27f * CGameObject::moveV[5].vx + 0.15f / 2.0f * 0.8f * CGameObject::moveV[5].vx || TeleEnemyPosY - enemy[E]->GetSize().y / 2.0f * CGameObject::moveV[5].vy <= DragonPosY + circleSizeReal * 0.27f * CGameObject::moveV[5].vy + 0.15f / 2.0f * 0.8f * CGameObject::moveV[5].vy) {
									goAround = false;
								}
								else {
									goAround = true;
								}
							}
						}

						if (blowOffPattern == 1 || (blowOffPattern == 3 && !goAround)) {
							DragonPosX = enemy[E]->GetPos().x + enemy[E]->GetSize().x / 2.0f;
							DragonPosY = enemy[E]->GetPos().y + enemy[E]->GetSize().y / 2.0f;

							enemy[E]->mBlownDir0 = BLOW_DIR_LOWER_LEFT;
						}
						else if (blowOffPattern == 2 || (blowOffPattern == 3 && goAround)) {
							DragonPosX = enemy[E]->GetPos().x - enemy[E]->GetSize().x / 2.0f;
							DragonPosY = enemy[E]->GetPos().y - enemy[E]->GetSize().y / 2.0f;

							enemy[E]->mBlownDir0 = BLOW_DIR_UPPER_RIGHT;
						}

						//GhostMoveDir = MOVE_DIR_NONE;
						enemy[E]->mStartBlown_flg = true;
					}
					else {
						DragonPosX += circleSizeReal * 0.27f * CGameObject::moveV[5].vx;
						DragonPosY += circleSizeReal * 0.27f * CGameObject::moveV[5].vy;
					}
					break;

					// 右下
				case 7:
					if (enemy[E]->mEnemyHit_flg) {
						if (blowOffPattern == 3) {
							if (enemyCollisionShape == 1) {
								if (TeleEnemyPosX + enemy[E]->GetSize().x / 2.0f >= DragonPosX + circleSizeReal * 0.27f * CGameObject::moveV[7].vx + 0.15f / 2.0f * 0.8f * CGameObject::moveV[7].vx || TeleEnemyPosY - enemy[E]->GetSize().y / 2.0f <= DragonPosY + circleSizeReal * 0.27f * CGameObject::moveV[7].vy + 0.15f / 2.0f * 0.8f * CGameObject::moveV[7].vy) {
									goAround = false;
								}
								else {
									goAround = true;
								}
							}
							else if (enemyCollisionShape == 2) {
								if (TeleEnemyPosX + enemy[E]->GetSize().x / 2.0f * CGameObject::moveV[7].vx >= DragonPosX + circleSizeReal * 0.27f * CGameObject::moveV[7].vx + 0.15f / 2.0f * 0.8f * CGameObject::moveV[7].vx || TeleEnemyPosY - enemy[E]->GetSize().y / 2.0f * CGameObject::moveV[7].vy <= DragonPosY + circleSizeReal * 0.27f * CGameObject::moveV[7].vy + 0.15f / 2.0f * 0.8f * CGameObject::moveV[7].vy) {
									goAround = false;
								}
								else {
									goAround = true;
								}
							}
						}

						if (blowOffPattern == 1 || (blowOffPattern == 3 && !goAround)) {
							DragonPosX = enemy[E]->GetPos().x - enemy[E]->GetSize().x / 2.0f;
							DragonPosY = enemy[E]->GetPos().y + enemy[E]->GetSize().y / 2.0f;

							enemy[E]->mBlownDir0 = BLOW_DIR_LOWER_RIGHT;
						}
						else if (blowOffPattern == 2 || (blowOffPattern == 3 && goAround)) {
							DragonPosX = enemy[E]->GetPos().x + enemy[E]->GetSize().x / 2.0f;
							DragonPosY = enemy[E]->GetPos().y - enemy[E]->GetSize().y / 2.0f;

							enemy[E]->mBlownDir0 = BLOW_DIR_UPPER_LEFT;
						}

						//GhostMoveDir = MOVE_DIR_NONE;
						enemy[E]->mStartBlown_flg = true;
					}
					else {
						DragonPosX += circleSizeReal * 0.27f * CGameObject::moveV[7].vx;
						DragonPosY += circleSizeReal * 0.27f * CGameObject::moveV[7].vy;
					}
					break;
				}
			}
			else {
				DragonPosX = enemy[E]->GetPos().x;
				DragonPosY = enemy[E]->GetPos().y;
			}

			playerObj->SetPos(DragonPosX, DragonPosY);
		}
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
		tpAnimPart = 9;
		circleSizeReal = circleSize;
		tpAnimFlg = false;
		tpAnim = 0;

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
				getFuel++;
			}

			//// 残ってる燃料がなくなったらクリア
			//if (remainingFuel == 0 && clearProcess) {
			//	stageClear = true;
			//}
		}

		for (int E = 0; E < EnemyNum; E++) {
			if (enemy[E]->mStartBlown_flg) {  // 敵に当たってたらゴーストの移動処理を始める

				switch (DragonDirection)
				{
				case 0:
				case 4:
				case 5:
					playerAnimPartY = 2;
					break;
				case 2:
				case 6:
				case 7:
					playerAnimPartY = 3;
					break;
				case 1:
				case 3:
					playerAnimPartY = 1;
					break;
				}

				animSpeed = ANIMSPEED / 3;
				playerBlowAnim = true;

				switch (DragonDirection)
				{
				case 3:
				case 4:
				case 6:
					playerObj->reverse_flg = false;
					break;
				case 1:
				case 5:
				case 7:
					playerObj->reverse_flg = true;
					break;
				default:
					break;
				}

				enemy[E]->mAttacked();

				//サイズ変更によるマップチップとの被りを無くす処理
				for (int i = 0; i < hitmapchipnum; i++) {
					if (Collision::RectAndRectHit(enemy[E]->GetPosAndSize(), MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize())) {
						float range_with_ground = ((enemy[E]->GetPosAndSize().posy - enemy[E]->GetPosAndSize().sizey / 2) - (MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize().posy + MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize().sizey / 2));

						float range_with_ceiling = ((enemy[E]->GetPosAndSize().posy + enemy[E]->GetPosAndSize().sizey / 2) - (MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize().posy - MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize().sizey / 2));

						float range_with_rightwall = ((enemy[E]->GetPosAndSize().posx + enemy[E]->GetPosAndSize().sizex / 2) - (MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize().posx - MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize().sizex / 2));

						float range_with_leftwall = ((enemy[E]->GetPosAndSize().posx - enemy[E]->GetPosAndSize().sizex / 2) - (MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize().posx + MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize().sizex / 2));

						if ((range_with_ground >= -ENEMY_EXPAND_SIZE) && (range_with_ground <= ENEMY_EXPAND_SIZE)) {
							enemy[E]->SetPosY(MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize().posy + (MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize().sizey + enemy[E]->GetPosAndSize().sizey) / 2 + 0.00001f);
						}
						else if ((range_with_ceiling >= -ENEMY_EXPAND_SIZE) && (range_with_ceiling <= ENEMY_EXPAND_SIZE)) {
							enemy[E]->SetPosY(MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize().posy - (MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize().sizey + enemy[E]->GetPosAndSize().sizey) / 2 - 0.00001f);
						}

						if ((range_with_rightwall >= -ENEMY_EXPAND_SIZE) && (range_with_rightwall <= ENEMY_EXPAND_SIZE)) {
							enemy[E]->SetPosX(MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize().posx - (MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize().sizex + enemy[E]->GetPosAndSize().sizex) / 2 - 0.00001f);
						}
						else if ((range_with_leftwall >= -ENEMY_EXPAND_SIZE) && (range_with_leftwall <= ENEMY_EXPAND_SIZE)) {
							enemy[E]->SetPosX(MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize().posx + (MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize().sizex + enemy[E]->GetPosAndSize().sizex) / 2 + 0.00001f);
						}
					}
				}
			}
			else if (enemy[E]->mAbleBroken) { // 敵を破壊する
				enemy[E]->mEnemyAlive = false;
				remainingEnemy--;

				// 取った燃料の数で爆発の大きさを変える
				switch (getFuel) {
				case 0:
					EffectTest[1]->SetPos(enemy[E]->GetPos().x, enemy[E]->GetPos().y);
					EffectTest[1]->SetSize(enemy[E]->GetSize().x * 0.8f, enemy[E]->GetSize().y * 0.8f);
					break;
				case 1:
					EffectTest[2]->SetPos(enemy[E]->GetPos().x, enemy[E]->GetPos().y);
					EffectTest[2]->SetSize(enemy[E]->GetSize().x * 0.8f * 1.3f, enemy[E]->GetSize().y * 0.8f * 1.3f);
					break;
				case 2:
					EffectTest[3]->SetPos(enemy[E]->GetPos().x, enemy[E]->GetPos().y);
					EffectTest[3]->SetSize(enemy[E]->GetSize().x * 0.8f * 1.3f * 1.3f, enemy[E]->GetSize().y * 0.8f * 1.3f * 1.3f);
					break;
				case 3:
					EffectTest[4]->SetPos(enemy[E]->GetPos().x, enemy[E]->GetPos().y);
					EffectTest[4]->SetSize(enemy[E]->GetSize().x * 0.8f * 1.3f * 1.3f * 1.3f, enemy[E]->GetSize().y * 0.8f * 1.3f * 1.3f * 1.3f);
					break;
				}

				enemy[E]->SetPos(10.0f, 10.0f);

				// ステージ上の敵を全て破壊するとクリア
				if (remainingEnemy == 0 && clearProcess) {
					soundObj->Stop(SOUND_BGM000_VER2);	// 一時停止

					stageClear = true;
				}
			}
		}
	}
}

void GameClass::StageReset()
{
	DragonPosX = -0.25f;
	DragonPosY = -0.7 + 0.15f / 2.0f;
	playerObj->SetPos(DragonPosX, DragonPosY);
	for (int E = 0; E < EnemyNum; E++) {
		enemy[E]->SetPos(0.25f, 0.0f);
		enemy[E]->SetSize(0.15f, 0.15f);
		enemy[E]->mStartBlown_flg = false;
		enemy[E]->mNow_Blown_flg = false;
		enemy[E]->mBlownDir0 = BLOW_DIR_NONE;
		enemy[E]->mBlownDir = BLOW_DIR_NONE;
		enemy[E]->mBlownCoefficient = PLAYER_PUNCH_POWER_MINIMUM;
		enemy[E]->mBlownCnt = 0;
		enemy[E]->mBlown_DirX = 1.0f;
		enemy[E]->mBlown_DirY = 1.0f;
		enemy[E]->SetAirTime(0.0f);
		enemy[E]->SetNowAir(true);
		enemy[E]->mEnemyHit_flg = false;
		enemy[E]->mEnemyCombo = 0;
		enemy[E]->mEnemyAlive = true;
		enemy[E]->mAbleBroken = false;
	}
	fuel[0]->SetPos(-0.5f, 0.0f);
	fuel[1]->SetPos(0.0f, 0.0f);
	fuel[2]->SetPos(0.5f, 0.0f);
	tpAnimFlg = false;
	tpAnimPart = 9;
	tpAnim = 0;
	slowcnt = 0;
	showCircle = false;
	hit_flg = false;
	stick_flg = false;
	stageClear = false;
	getFuel = 0;
	enemyBreak = false;
	remainingEnemy = 1;
	playerHp = 3;
	justAfterDamage = false;
	invincibleCnt = 0;
	sprite[25]->SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	sprite[26]->SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	sprite[27]->SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	playerObj->SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	showCircle = false;
	sprite[3]->enabled = false;
	circleSize = CIRCLE_SIZE_MINIMUM;
	circleSizeReal = CIRCLE_SIZE_MINIMUM;
	//EfectTest[0] = new CEfect(false, "assets/bakuhatsutest.png", 6, 1, 0, 0, 0, 0);
	//EfectTest[1] = new CEfect(false, "assets/EF_ExplosionSmall.png", 6, 1, 0, 0, 0, 0);
	//EfectTest[2] = new CEfect(false, "assets/EF_ExplosionSmall_2.png", 6, 1, 0, 0, 0, 0);
	//EfectTest[3] = new CEfect(false, "assets/EF_ExplosionBig_2.png", 10, 1, 0, 0, 0, 0);
	//EfectTest[4] = new CEfect(false, "assets/EF_ExplosionBig.png", 10, 1, 0, 0, 0, 0);
	soundObj->Replay(SOUND_BGM000_VER2);
	hitmapchipnum = 0;
	for (int i = 0; i < MAPCHIP_NUM_HEIGHT; i++) {
		for (int j = 0; j < MAPCHIP_NUM_WIDTH; j++) {
			MapChips[i][j]->SetPart(MapChipDate[Star_Num][World_Num][Stage_Num][i][j], 0);
			if (MapChipDate[Star_Num][World_Num][Stage_Num][i][j]) {
				Savehitmaphipnum[hitmapchipnum][0] = i;
				Savehitmaphipnum[hitmapchipnum][1] = j;
				Savehitmaphipnum[hitmapchipnum][2] = MapChipDate[Star_Num][World_Num][Stage_Num][i][j];
				hitmapchipnum++;
			}
		}
	}
	playerAnimCnt = 0;
	playerAnimPartX = 0;
	playerAnimPartY = 0;
	animSpeed = ANIMSPEED;
	playerBlowAnim = false;
}

void GameClass::EnemyBlow(int E)
{
	if (enemy[E]) {
		bool hitMapchip_Enemy = false;
		//マップチップと敵との当たり判定
		for (int i = 0; i < hitmapchipnum; i++) {

			if ((Collision::RectAndRectHit(enemy[E]->GetPosAndSize(), MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize())) && (!hitMapchip_Enemy)) {

				float range_with_ground = ((enemy[E]->GetPosAndSize().posy + enemy[E]->GetPosAndSize().sizey / 2) - (MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize().posy - MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize().sizey / 2));

				float range_with_ceiling = ((enemy[E]->GetPosAndSize().posy - enemy[E]->GetPosAndSize().sizey / 2) - (MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize().posy + MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize().sizey / 2));

				float range_with_rightwall = ((enemy[E]->GetPosAndSize().posx + enemy[E]->GetPosAndSize().sizex / 2) - (MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize().posx - MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize().sizex / 2));

				float range_with_leftwall = ((enemy[E]->GetPosAndSize().posx - enemy[E]->GetPosAndSize().sizex / 2) - (MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize().posx + MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->GetPosAndSize().sizex / 2));

				if (range_with_ground < 0)
					range_with_ground *= -1.0f;

				if (range_with_ceiling < 0)
					range_with_ceiling *= -1.0f;

				if (range_with_rightwall < 0)
					range_with_rightwall *= -1.0f;

				if (range_with_leftwall < 0)
					range_with_leftwall *= -1.0f;

				switch (enemy[E]->mBlownDir)
				{
				case BLOW_DIR_RIGHT:
				case BLOW_DIR_LEFT:
					enemy[E]->mBlown_DirX *= -1.0f;


					break;

				case BLOW_DIR_UP:
				case BLOW_DIR_DOWN:
					enemy[E]->mBlown_DirY *= -1.0f;
					break;

				case BLOW_DIR_UPPER_RIGHT:
				case BLOW_DIR_UPPER_LEFT:
				case BLOW_DIR_LOWER_LEFT:
				case BLOW_DIR_LOWER_RIGHT:

					if ((range_with_leftwall < 0.003) || (range_with_rightwall < 0.003))
						enemy[E]->mBlown_DirX *= -1.0f;

					if ((range_with_ceiling < 0.003) || (range_with_ground < 0.003))
						enemy[E]->mBlown_DirY *= -1.0f;
					break;
				}

				hitMapchip_Enemy = true;

				if (MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->mMapChipType == BROKEN_BLOCK) {
					MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->mBroak();
					if (MapChips[Savehitmaphipnum[i][0]][Savehitmaphipnum[i][1]]->mMapChipType == NONE_MAPCHIP) {
						for (int j = i; j != hitmapchipnum; ++j) {
							Savehitmaphipnum[j][0] = Savehitmaphipnum[j + 1][0];
							Savehitmaphipnum[j][1] = Savehitmaphipnum[j + 1][1];
							Savehitmaphipnum[j][2] = Savehitmaphipnum[j + 1][2];
						}

						hitmapchipnum--;
					}
				}
			}
		}

		enemy[E]->mBlowm();
	}
}