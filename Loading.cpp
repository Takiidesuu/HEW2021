#include "Loading.h"

bool Loading::Init()
{
	//�`�悷����̂̏������i�摜�ǂݍ��݁j
	enemy = new CSprite("assets/enemy.png", 7, 1, posX - 0.6f, -0.8f, 0.4f, 0.4f);
	loadingBar = new CSprite("assets/loading/loadingBar.png", 3, 1, posX, -0.85f, 1.0f, 1.0f);
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

	//���[�f�B���O���s
	for (int a = 0; a < num; a++)
	{
		if (funcStr[a] != NULL)		//�󂶂�Ȃ�������
		{
			//�֐������s���A���̏���foo�ɓ����
			std::future<void> foo = std::async(std::launch::async, funcStr[a]);

			foo.wait_for(std::chrono::milliseconds(1000));

			Count();		//�`��
		}
	}
}

void Loading::Count()
{
	int part = 0;
	int enemyPart = 0;

	//�`�惋�[�v
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

		Draw();		//�`��

		Sleep(SLOW);	//������ƍs���Ȃ��悤�ɁA��U�x�܂���
	}
}

void Loading::Draw()
{
	float clearColor[4] = { 0.0f, 0.0f, 0.0f, 1.0f };

	Direct3D_GetContext()->ClearRenderTargetView(Direct3D_GetRenderTargetView(), clearColor);

	//�X�v���C�g�̕`��
	enemy->Draw();
	loadingBar->Draw();

	Direct3D_GetSwapChain()->Present(0, 0);
}

void Loading::Reset()
{
	//�l�̕ϐ������Z�b�g����
	num = 0;
}