#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include "Save_Load.h"

using namespace std;

void Save_Load::Save(int world_num, int stage_num, bool Clear_FLG ,bool Del_FLG)
{
	/*
		���[���h�P
	*/
	// �X�e�[�W�P
	if ((world_num == 1)&&(stage_num ==1))
		data.World1.Stage1 = Clear_FLG;

	// �X�e�[�W�Q
	if ((world_num == 1) && (stage_num == 2))
		data.World1.Stage2 = Clear_FLG;

	// �X�e�[�W�R
	if ((world_num == 1) && (stage_num == 3))
		data.World1.Stage3 = Clear_FLG;

	/*
		���[���h�Q
	*/
	// �X�e�[�W�P
	if ((world_num == 2) && (stage_num == 1))
		data.World2.Stage1 = Clear_FLG;

	// �X�e�[�W�Q
	if ((world_num == 2) && (stage_num == 2))
		data.World2.Stage2 = Clear_FLG;

	// �X�e�[�W�R
	if ((world_num == 2) && (stage_num == 3))
		data.World2.Stage3 = Clear_FLG;

	/*
		���[���h�R
	*/
	// �X�e�[�W�P
	if ((world_num == 3) && (stage_num == 1))
		data.World3.Stage1 = Clear_FLG;

	// �X�e�[�W�Q
	if ((world_num == 3) && (stage_num == 2))
		data.World3.Stage2 = Clear_FLG;

	// �X�e�[�W�R
	if ((world_num == 3) && (stage_num == 3))
		data.World3.Stage3 = Clear_FLG;

	/*
		���[���h�S
	*/
	// �X�e�[�W�P
	if ((world_num == 4) && (stage_num == 1))
		data.World4.Stage1 = Clear_FLG;

	// �X�e�[�W�Q
	if ((world_num == 4) && (stage_num == 2))
		data.World4.Stage2 = Clear_FLG;

	// �X�e�[�W�R
	if ((world_num == 4) && (stage_num == 3))
		data.World4.Stage3 = Clear_FLG;

	/*
		���[���h�T
	*/
	// �X�e�[�W�P
	if ((world_num == 5) && (stage_num == 1))
		data.World5.Stage1 = Clear_FLG;

	// �X�e�[�W�Q
	if ((world_num == 5) && (stage_num == 2))
		data.World5.Stage2 = Clear_FLG;

	// �X�e�[�W�R
	if ((world_num == 5) && (stage_num == 3))
		data.World5.Stage3 = Clear_FLG;

	/*
		���[���h�U
	*/
	// �X�e�[�W�P
	if ((world_num == 6) && (stage_num == 1))
		data.World6.Stage1 = Clear_FLG;

	// �X�e�[�W�Q
	if ((world_num == 6) && (stage_num == 2))
		data.World6.Stage2 = Clear_FLG;

	// �X�e�[�W�R
	if ((world_num == 6) && (stage_num == 3))
		data.World6.Stage3 = Clear_FLG;

	// �V�K
	if (Del_FLG == false)
		data.Del = false;

	// �폜
	if (Del_FLG == true)
		data.Del = true;

	FILE *fp = fopen("�Z�[�u�f�[�^.dat", "wb");//�o�C�i���t�@�C�����J��
	fwrite(&data, sizeof(data), 1, fp); // SAVE_DATA�\���̂̒��g�����
	fclose(fp);//�t�@�C�������
}

char Save_Load::Load()
{
	FILE *fp;

	if ((fp = fopen("�Z�[�u�f�[�^.dat", "rb")) == NULL)
	{
		cout << "�Z�[�u�f�[�^���Ȃ��ł�" << endl;
	};

	//�o�C�i���t�@�C����ǂݍ���
	if (fp = fopen("�Z�[�u�f�[�^.dat", "rb"))
	{
		fread(&data, sizeof(data), 1, fp); // SAVE_DATA�\���̂̒��g���o��
		fclose(fp);//�t�@�C�������

		// �폜�t���O�������Ă��Ȃ�
		if (data.Del == false)
		{
			Save_Load::Answer();
			Save_Load::WS_true();
		}

		// �폜�t���O�������Ă���
		if (data.Del == true)
		{
			cout << "�Z�[�u�f�[�^�̒��g���폜����Ă܂��B" << endl;
			system("pause");
		}

	};

	return	data.World1.Stage1, data.World1.Stage2, data.World1.Stage3,
			data.World2.Stage1, data.World2.Stage2, data.World2.Stage3,
			data.World3.Stage1, data.World3.Stage2, data.World3.Stage3,
			data.World4.Stage1, data.World4.Stage2, data.World4.Stage3,
			data.World5.Stage1, data.World5.Stage2, data.World5.Stage3,
			data.World6.Stage1, data.World6.Stage2, data.World6.Stage3,
			data.Del;
}

void Save_Load::Answer()
{
	cout << "���[���h�P" << endl;
	cout << "�X�e�[�W�P�F" << data.World1.Stage1 << endl;
	cout << "�X�e�[�W�Q�F" << data.World1.Stage2 << endl;
	cout << "�X�e�[�W�R�F" << data.World1.Stage3 << endl;

	cout << "���[���h�Q" << endl;
	cout << "�X�e�[�W�P�F" << data.World2.Stage1 << endl;
	cout << "�X�e�[�W�Q�F" << data.World2.Stage2 << endl;
	cout << "�X�e�[�W�R�F" << data.World2.Stage3 << endl;

	cout << "���[���h�R" << endl;
	cout << "�X�e�[�W�P�F" << data.World3.Stage1 << endl;
	cout << "�X�e�[�W�Q�F" << data.World3.Stage2 << endl;
	cout << "�X�e�[�W�R�F" << data.World3.Stage3 << endl;

	cout << "���[���h�S" << endl;
	cout << "�X�e�[�W�P�F" << data.World4.Stage1 << endl;
	cout << "�X�e�[�W�Q�F" << data.World4.Stage2 << endl;
	cout << "�X�e�[�W�R�F" << data.World4.Stage3 << endl;

	cout << "���[���h�T" << endl;
	cout << "�X�e�[�W�P�F" << data.World5.Stage1 << endl;
	cout << "�X�e�[�W�Q�F" << data.World5.Stage2 << endl;
	cout << "�X�e�[�W�R�F" << data.World5.Stage3 << endl;

	cout << "���[���h�U" << endl;
	cout << "�X�e�[�W�P�F" << data.World6.Stage1 << endl;
	cout << "�X�e�[�W�Q�F" << data.World6.Stage2 << endl;
	cout << "�X�e�[�W�R�F" << data.World6.Stage3 << endl;
}

void Save_Load::Initialize_Date(bool Del_FLG)
{
	// �폜�t���O�������Ă��Ȃ�
	if (Del_FLG == false)
	{
		cout << "�V�K�Z�[�u�f�[�^���쐬���܂�" << endl;
	}
	
	// �폜�t���O�������Ă���
	if (Del_FLG == true)
	{
		cout << "�Z�[�u�f�[�^�����Z�b�g���܂�" << endl;
		system("pause");
	}

	for (stage_num = 1; stage_num <= 3; stage_num++)
	{
		for (world_num = 1; world_num <= 6; world_num++)
		{
			Save_Load::Save(world_num, stage_num, false, Del_FLG);
		}
	}
}

void Save_Load::WS_true()
{
	cout << "�N���A�ꏊ���w�肷�邩�H" << endl;
	cout << "1�F����@�@0�F���Ȃ�" << endl;
	cin >> loop;

	while (loop)
	{
		cout << "�N���A���w�肵�������[���h��I��" << endl;
		cin >> world_num;

		cout << "�N���A���w�肵�����X�e�[�W��I��" << endl;
		cin >> stage_num;

		Save_Load::Save(world_num, stage_num, true, false);
		Save_Load::Load();
	}
}