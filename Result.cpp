#include "Result.h"

void CResult::Init()
{
	//�C���v�b�g�I�u�W�F�N�g�����
	mInputObj = new Input;

	mSprite = new CSprite*[RESULT_SPRITE_NUM];

	mSprite[0] = new CSprite("assets/BG_haisouko_ver02.png", 1, 1, 0.0f, 0.0f, 2.0f, 2.0f);		//�w�i
	mSprite[0]->SetColor(0.5f, 0.5f, 0.5f, 1.0f);

	mSprite[1] = new CSprite("assets/Select.png", 1, 1, 0.5f, 0.5f, 0.5f, 0.25f);		//Select
	mSprite[2] = new CSprite("assets/Retry.png", 1, 1, 0.5f, -0.0f, 0.5f, 0.25f);		//Retry
	mSprite[3] = new CSprite("assets/Next.png", 1, 1, 0.5f, -0.5f, 0.5f, 0.25f);		//Next

	mSprite[4] = new CSprite("assets/Achieve.png", 1, 1, -0.5f, 0.0f, 0.75f, 1.2f);		//���U���g�\��

	mSprite[5] = new CSprite("assets/ClearTime.png", 1, 1, 0.0f, 0.25f, 1.0f, 1.0f);		//�N���A�^�C���\��

	mSprite[6] = new CSprite("assets/Next.png", 1, 1, 0.5f, -0.5f, 0.5f, 0.25f);		//Next

	mInputflg = false;
}

bool CResult::Update()
{
	//�C���v�b�g�I�u�W�F�N�g���A�b�v�f�[�g
	mInputObj->Input_Update();

	//ESC�L�[��������A�v���O���������I��
	if (mInputObj->Input_GetKeyTrigger(VK_ESCAPE))
		sceneManager.LoadScene(TITLE);

	switch (mResultScene)
	{
	case TIME:
		if (mInputObj->GetButtonPress(OK))
			mResultScene = ACHIEVE;
		break;
	case ACHIEVE:
		if (mInputObj->isInput())	//�C���v�b�g����������
		{
			if (!mInputflg) {
				if ((mInputObj->GetAxis(DOWN)) && (mSelect < NEXT)) {
					mSelect += 1;
				}
				if ((mInputObj->GetAxis(UP)) && ((mSelect > STAGE_SELECT) || (mSelect == NONE))) {
					mSelect -= 1;
					if (mSelect < STAGE_SELECT) {
						mSelect = STAGE_SELECT;
					}
				}
			}
			mInputflg = true;
		}
		else {
			mInputflg = false;
		}

		if (mInputObj->GetButtonPress(OK))
			sceneManager.LoadScene(STAGESELECT);

		//���݂̑I�����ŋ�������{�^����ς���
		for (int i = STAGE_SELECT; i <= NEXT; i++) {
			if (i == mSelect)
				mSprite[i]->SetColor(1.0f, 1.0f, 1.0f, 1.0f);
			else
				mSprite[i]->SetColor(0.5f, 0.5f, 0.5f, 1.0f);
		}
		break;
	default:
		break;
	}



	Draw();

	return true;
}

void CResult::Draw() {

	float clearColor[4] = { 0.0f, 0.0f, 0.0f, 1.0f };

	Direct3D_GetContext()->ClearRenderTargetView(Direct3D_GetRenderTargetView(), clearColor);

	switch (mResultScene)
	{
	case TIME:

		mSprite[0]->Draw();
		mSprite[5]->Draw();
		mSprite[6]->Draw();


		break;
	case ACHIEVE:
		for (int i = 0; i < 5; i++) {
			mSprite[i]->Draw();
		}
		break;
	}

	Direct3D_GetSwapChain()->Present(0, 0);
}
