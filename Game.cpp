#include "Game.h"

VECTOR moveV[8];  // �ړ��p�x�N�g��

RectShape rectA(1.0f, 1.0f, 1.0f, 1.0f);  // �����蔻��p�̋�`
RectShape rectB(1.0f, 1.0f, 1.0f, 1.0f);  // �����蔻��p�̋�`

bool GameClass::Init()
{
	//�C���v�b�g�I�u�W�F�N�g�����
	inputObj = new Input;

	//�C���v�b�g�I�u�W�F�N�g�̍쐬�Ɏ��s������
	if (!inputObj)
	{
		MessageBoxA(nullptr, "�C���v�b�g�I�u�W�F�N�g���܂���ł���", "�C���v�b�g�G���[", MB_OK);
		return false;
	}

	//�摜�n�̃I�u�W�F�N�g�����
	sprite = new CGameObject*[64];

	for (int a = 0; a < MAXSPRITE; a++)
	{
		sprite[a] = NULL;
	}

	MapChips = new CSprite**[MAP_SIZE_HEIGHT];

	//���ꂼ��̃I�u�W�F�N�g�z��ɉ摜�̃f�[�^��ǂݍ���ŁA����������
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

	// �ړ��p�x�N�g����8�������쐬
	for (int i = 0; i < 8; i++) {
		moveV[i].vx = cosf((float)i * PI / 4.0f);
		moveV[i].vy = sinf((float)i * PI / 4.0f);
	}

	return true;
}

bool GameClass::Update()
{
	//�C���v�b�g�I�u�W�F�N�g���A�b�v�f�[�g
	inputObj->Input_Update();

	//ESC�L�[��������A�v���O���������I��
	if (inputObj->Input_GetKeyTrigger(VK_ESCAPE))
		return false;

	//�v���C���[�̍��W���擾
	float DragonPosX = playerObj->GetPos('x');
	float DragonPosY = playerObj->GetPos('y');

	//�v���C���[�̌���
	static int DragonDirection = 1;
	static int moveAnim = 1;
	static bool isMoving = false;

	//�u�Ԉړ��p
	static int tpAnim = 0;				//�t���[����
	static bool tpAnimFlg = false;		//�u�Ԉړ��A�j���[�V�����t���O�i���s���邩�ǂ����j
	static int tpAnimPart = 9;
	static int tpAnimSize = 99 / TELEPORTSIZE;
	static int tpPlaceHolder = 0;

	static float GhostPosX = 0.0f;
	static float GhostPosY = 0.0f;
	static float GhostSizeX = 0.15f;
	static float GhostSizeY = 0.15f;
	static bool GhostCanMove = false;  // �S�[�X�g���ړ��ł��邩�ǂ���
	static bool GhostNowMove = false;  // �S�[�X�g���ړ������ǂ���
	static int GhostMoveDir0 = MOVE_DIR_NONE;  // �S�[�X�g�̈ړ����������ۑ����邽�߂̕ϐ�
	static int GhostMoveDir = MOVE_DIR_NONE;  // �S�[�X�g�̈ړ�������ۑ�����ϐ�
	static float GhostMoveCoefficient = 0.0003f;  // �S�[�X�g�̈ړ��ʂ̌W��

	static bool hit_flg = false;  // �����蔻��p�̕ϐ�

	//�u�Ԉړ��ł��邩�ǂ����̃t���O
	static bool Teleport_flg = false;

	// �����蔻��p�̋�`�Ƀh���S���ƃS�[�X�g�̑傫����n��
	rectA.SetSize(0.15f, 0.15f);
	rectB.SetSize(GhostSizeX, GhostSizeY);

	//�ړ��ł���ꍇ�i�u�Ԉړ����ĂȂ��ꍇ�j
	if (tpAnim == 0 && !tpAnimFlg)
	{
		if (inputObj->isInput())	//�C���v�b�g����������
		{
			//�������ɍs������
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

	//�u�Ԉړ��A�j���[�V�����t���O��true�̏ꍇ�A�J�E���g�n�܂�
	if (tpAnimFlg)
	{
		tpAnim++;
	}

	//�u�Ԉړ��A�j���[�V��������
	if (tpAnim <= 0)					//�ʏ�̎�
		playerObj = sprite[0];
	if (tpAnim >= 1 && tpAnim <= 99)	//�u�Ԉړ��A�j���[�V��������
	{
		if (tpAnim == 1 || tpAnim == tpPlaceHolder)
		{
			tpAnimPart++;
			playerObj = sprite[tpAnimPart];
			tpPlaceHolder = tpAnim + tpAnimSize;
		}
	}
	if (tpAnim >= 100 && tpAnim <= 199)					//�u�Ԉړ�
	{
		if ((tpAnim - 100) % 11 == 0)
		{
			//�����ɂ���āA�ړ�����������ς��
			switch (DragonDirection)
			{
			case 0: DragonPosX -= 0.05f;
				break;
			case 1: DragonPosX += 0.05f;
				break;
			}
		}
	}
	if (tpAnim >= 200 && tpAnim <= 299)	//�u�Ԉړ��A�j���[�V��������i�o��j
	{
		if (tpAnim == 200 || tpAnim == tpPlaceHolder)
		{
			playerObj = sprite[tpAnimPart];
			tpAnimPart--;
			tpPlaceHolder = tpAnim + tpAnimSize;
		}
	}
	if (tpAnim == 300)					//�ʏ�̏�Ԃɖ߂�
	{
		playerObj = sprite[0];
		tpAnimFlg = false;
		tpAnimPart = 9;
		tpAnim = 0;

		// �����蔻��p�̋�`�ɂ��ꂼ��̑傫����n��
		rectA.SetPos(DragonPosX, DragonPosY);
		rectB.SetPos(GhostPosX, GhostPosY);

		// ��`���m�œ����蔻����Ƃ�
		hit_flg = Collision::RectAndRectTest(rectA, rectB);

		if (hit_flg) {  // �������Ă���

			float rad = Angle(DragonPosX, DragonPosY, GhostPosX, GhostPosY);  // �h���S���ƃS�[�X�g�̒��S���m�����񂾐��̊p�x���v�Z

			// �p�x�ɂ���ăh���S���̈ʒu��␳����
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

			// �S�[�X�g���ړ����Ȃ���肷��悤�ɏ�����Ɉړ�����
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

		if (GhostCanMove) {  // �S�[�X�g�ɓ������Ă���S�[�X�g�̈ړ��������n�߂�
			GhostNowMove = true;
			GhostCanMove = false;
			GhostMoveCoefficient += 0.00001f;
			GhostMoveDir = GhostMoveDir0;
			GhostMoveDir0 = MOVE_DIR_NONE;
		}
	}

	// �S�[�X�g�̈ړ�����
	if (GhostNowMove) {
		// �͂����ꂽ�����Ɉړ�����
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

	////�J�����̈ʒu���v���C���[�ƍ��킹��
	//CSprite::mCameraPosX = DragonPosX; //�J�����̈ʒu�𑀍�L�����N�^�[�ɒǏ]������
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
			sprite[0]->GravityJump();  // �d�͂ł̃W�����v
			//player.SinJump();  // �O�p�֐��ł̃W�����v
		}
		else
		{
			isJumping = false;
			canJump = true;
		}
	}

	sprite[6]->SetPos(GhostPosX, GhostPosY);

	playerObj->Gravity();	//�d�͂ł̃W�����v�̂Ƃ��̏d��



	sprite[6]->Gravity();	//�G�̏d��

	sprite[3]->SetPos(playerObj->GetPos('x'), playerObj->GetPos('y'));	//�͈͕\���I�u�W�F�N�g�̈ʒu��ݒ�

	static int cnt = 0;			//�A�j���[�V�����p�̃J�E���^�[
	static int animPart = 0;	//�A�j���[�V�����̃p�[�c

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