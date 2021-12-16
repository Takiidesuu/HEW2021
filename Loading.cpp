#include "Loading.h"

bool Loading::Init()
{
	//�`�悷����̂̏������i�摜�ǂݍ��݁j
	enemy = new CSprite("assets/enemy.png", 7, 1, posX - 1.35f, -0.8f, 0.3f * (float)RESOLUTIONY / (float)RESOLUTIONX, 0.4f);
	loadingBar = new CSprite("assets/loading/loadingBar.png", 1, 1, posX, -0.8f, 2.5f, 0.2f);
	background = new CSprite("assets/loading/background.png", 1, 1, 0.0f, 0.0f, 2.0f, 2.0f);

	return true;		//������������������񍐂���
}

void Loading::Load(Func func1, Func func2, Func func3, Func func4, Func func5)
{
	Reset();	//�l�����Z�b�g����

	Count();	//������Ԃ�`�悷��

	Func funcStr[5];	//function�|�C���^�[�̔z��

	//�������ŁA��ɂ���
	for (int a = 0; a < 5; a++)
		funcStr[a] = NULL;

	//�z��Ƀ��[�h����֐�������
	funcStr[0] = func1;
	funcStr[1] = func2;
	funcStr[2] = func3;
	funcStr[3] = func4;
	funcStr[4] = func5;

	//���[�h����֐��ǂꂮ�炢���邩���`�F�b�N����
	for (int a = 0; a < 5; a++)
	{
		if (funcStr[a] != NULL)		//�󂶂�Ȃ�������A�J�E���g�A�b�v
			num++;
		else
			;
	}

	//���̎��s�ɂ��A���[�f�B���O�o�[�̐i�ދ������v�Z����
	goalIncrement = 100 / num;

	//���[�f�B���O���s
	for (int a = 0; a < num; a++)
	{
		if (funcStr[a] != NULL)		//�󂶂�Ȃ�������
		{
			//�֐������s���A���̏���foo�ɓ����
			std::future<void> foo = std::async(std::launch::async, funcStr[a]);

			//���i�ދ����̃S�[���ɏ�Ōv�Z���������𑫂�
			progressGoal += goalIncrement;
			Count();		//�`��
		}
	}
}

void Loading::Count()
{
	//�`�惋�[�v
	for (int a = progress; a <= progressGoal; a++)
	{
		posX -= 0.021f;		//���ɂ���������

		//�X�v���C�g�̈ʒu��ݒ肷��
		enemy->SetPosX(posX - 1.35f);
		loadingBar->SetPosX(posX);

		Draw();		//�`��

		Sleep(SLOW);	//������ƍs���Ȃ��悤�ɁA��U�x�܂���
	}

	//�I��������_�̋�����ۑ�����
	progress = progressGoal;
}

void Loading::Draw()
{
	float clearColor[4] = { 0.0f, 0.0f, 0.0f, 1.0f };

	Direct3D_GetContext()->ClearRenderTargetView(Direct3D_GetRenderTargetView(), clearColor);

	//�X�v���C�g�̕`��
	background->Draw();
	enemy->Draw();
	loadingBar->Draw();

	Direct3D_GetSwapChain()->Present(0, 0);
}

void Loading::Reset()
{
	//�l�̕ϐ������Z�b�g����
	progress = 0;
	progressGoal = 0;
	goalIncrement = 0;
	num = 0;
	posX = 2.3f;
}