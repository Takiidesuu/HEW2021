#include "SaveLoad.h"

using namespace std;

/*

�N���A���𓚂���֐�

*/
void Save_Load::Percent1()
{
	FILE *fp;

	if ((fp = fopen("�Z�[�u�f�[�^1.dat", "rb")) == NULL)
	{
		cout << "�Z�[�u�f�[�^�P���Ȃ��ł�" << endl;
		cout << endl;
	}

	//�o�C�i���t�@�C����ǂݍ���
	if (fp = fopen("�Z�[�u�f�[�^1.dat", "rb"))
	{
		fread(&data1, sizeof(data1), 1, fp); // SAVE_DATA�\���̂̒��g���o��
		fclose(fp);//�t�@�C�������

		if (data1.Del == false)
		{
			// �X�^�[�P
			if (data1.Star1.World1.Stage1 == true)
				Clear1.Plus = Clear1.Plus++;
			if (data1.Star1.World1.Stage2 == true)
				Clear1.Plus = Clear1.Plus++;
			if (data1.Star1.World1.Stage3 == true)
				Clear1.Plus = Clear1.Plus++;

			if (data1.Star1.World2.Stage1 == true)
				Clear1.Plus = Clear1.Plus++;
			if (data1.Star1.World2.Stage2 == true)
				Clear1.Plus = Clear1.Plus++;
			if (data1.Star1.World2.Stage3 == true)
				Clear1.Plus = Clear1.Plus++;

			// �X�^�[�Q
			if (data1.Star2.World1.Stage1 == true)
				Clear1.Plus = Clear1.Plus++;
			if (data1.Star2.World1.Stage2 == true)
				Clear1.Plus = Clear1.Plus++;
			if (data1.Star2.World1.Stage3 == true)
				Clear1.Plus = Clear1.Plus++;

			if (data1.Star2.World2.Stage1 == true)
				Clear1.Plus = Clear1.Plus++;
			if (data1.Star2.World2.Stage2 == true)
				Clear1.Plus = Clear1.Plus++;
			if (data1.Star2.World2.Stage3 == true)
				Clear1.Plus = Clear1.Plus++;

			// �X�^�[�R
			if (data1.Star3.World1.Stage1 == true)
				Clear1.Plus = Clear1.Plus++;
			if (data1.Star3.World1.Stage2 == true)
				Clear1.Plus = Clear1.Plus++;
			if (data1.Star3.World1.Stage3 == true)
				Clear1.Plus = Clear1.Plus++;

			if (data1.Star3.World2.Stage1 == true)
				Clear1.Plus = Clear1.Plus++;
			if (data1.Star3.World2.Stage2 == true)
				Clear1.Plus = Clear1.Plus++;
			if (data1.Star3.World2.Stage3 == true)
				Clear1.Plus = Clear1.Plus++;

			cout << "�Z�[�u�f�[�^�P���v���F " << Clear1.Plus << " �^ 18" << endl;
			Clear1.Percent = Clear1.Plus * 0.05 * 100;

			if (Clear1.Plus >= 18)
				cout << "�Z�[�u�f�[�^�P�N���A���F 100 %" << endl;
			else
				cout << "�Z�[�u�f�[�^�P�N���A���F " << Clear1.Percent << " %" << endl;

			cout << endl;
		}

		if (data1.Del == true)
		{
			cout << "�Z�[�u�f�[�^�P�͏�����Ă��܂�" << endl;
			cout << endl;
		}
	}
}

void Save_Load::Percent2()
{
	FILE *fp;

	if ((fp = fopen("�Z�[�u�f�[�^2.dat", "rb")) == NULL)
	{
		cout << "�Z�[�u�f�[�^�Q���Ȃ��ł�" << endl;
		cout << endl;
	}

	//�o�C�i���t�@�C����ǂݍ���
	if (fp = fopen("�Z�[�u�f�[�^2.dat", "rb"))
	{
		fread(&data2, sizeof(data2), 1, fp); // SAVE_DATA�\���̂̒��g���o��
		fclose(fp);//�t�@�C�������

		if (data2.Del == false)
		{
			// �X�^�[�P
			if (data2.Star1.World1.Stage1 == true)
				Clear2.Plus = Clear2.Plus++;
			if (data2.Star1.World1.Stage2 == true)
				Clear2.Plus = Clear2.Plus++;
			if (data2.Star1.World1.Stage3 == true)
				Clear2.Plus = Clear2.Plus++;

			if (data2.Star1.World2.Stage1 == true)
				Clear2.Plus = Clear2.Plus++;
			if (data2.Star1.World2.Stage2 == true)
				Clear2.Plus = Clear2.Plus++;
			if (data2.Star1.World2.Stage3 == true)
				Clear2.Plus = Clear2.Plus++;

			// �X�^�[�Q
			if (data2.Star2.World1.Stage1 == true)
				Clear2.Plus = Clear2.Plus++;
			if (data2.Star2.World1.Stage2 == true)
				Clear2.Plus = Clear2.Plus++;
			if (data2.Star2.World1.Stage3 == true)
				Clear2.Plus = Clear2.Plus++;

			if (data2.Star2.World2.Stage1 == true)
				Clear2.Plus = Clear2.Plus++;
			if (data2.Star2.World2.Stage2 == true)
				Clear2.Plus = Clear2.Plus++;
			if (data2.Star2.World2.Stage3 == true)
				Clear2.Plus = Clear2.Plus++;

			// �X�^�[�R
			if (data2.Star3.World1.Stage1 == true)
				Clear2.Plus = Clear2.Plus++;
			if (data2.Star3.World1.Stage2 == true)
				Clear2.Plus = Clear2.Plus++;
			if (data2.Star3.World1.Stage3 == true)
				Clear2.Plus = Clear2.Plus++;

			if (data2.Star3.World2.Stage1 == true)
				Clear2.Plus = Clear2.Plus++;
			if (data2.Star3.World2.Stage2 == true)
				Clear2.Plus = Clear2.Plus++;
			if (data2.Star3.World2.Stage3 == true)
				Clear2.Plus = Clear2.Plus++;

			cout << "�Z�[�u�f�[�^�Q���v���F " << Clear2.Plus << " �^ 18" << endl;
			Clear2.Percent = Clear2.Plus * 0.05 * 100;

			if (Clear2.Plus >= 18)
				cout << "�Z�[�u�f�[�^�Q�N���A���F 100 %" << endl;
			else
				cout << "�Z�[�u�f�[�^�Q�N���A���F " << Clear2.Percent << " %" << endl;

			cout << endl;
		}

		if (data2.Del == true)
		{
			cout << "�Z�[�u�f�[�^�Q�͏�����Ă��܂�" << endl;
			cout << endl;
		}
	}
}

void Save_Load::Percent3()
{
	FILE *fp;

	if ((fp = fopen("�Z�[�u�f�[�^3.dat", "rb")) == NULL)
	{
		cout << "�Z�[�u�f�[�^�R���Ȃ��ł�" << endl;
	}

	//�o�C�i���t�@�C����ǂݍ���
	if (fp = fopen("�Z�[�u�f�[�^3.dat", "rb"))
	{
		fread(&data3, sizeof(data3), 1, fp); // SAVE_DATA�\���̂̒��g���o��
		fclose(fp);//�t�@�C�������

		if (data3.Del == false)
		{
			// �X�^�[�P
			if (data3.Star1.World1.Stage1 == true)
				Clear3.Plus = Clear3.Plus++;
			if (data3.Star1.World1.Stage2 == true)
				Clear3.Plus = Clear3.Plus++;
			if (data3.Star1.World1.Stage3 == true)
				Clear3.Plus = Clear3.Plus++;

			if (data3.Star1.World2.Stage1 == true)
				Clear3.Plus = Clear3.Plus++;
			if (data3.Star1.World2.Stage2 == true)
				Clear3.Plus = Clear3.Plus++;
			if (data3.Star1.World2.Stage3 == true)
				Clear3.Plus = Clear3.Plus++;

			// �X�^�[�Q
			if (data3.Star2.World1.Stage1 == true)
				Clear3.Plus = Clear3.Plus++;
			if (data3.Star2.World1.Stage2 == true)
				Clear3.Plus = Clear3.Plus++;
			if (data3.Star2.World1.Stage3 == true)
				Clear3.Plus = Clear3.Plus++;

			if (data3.Star2.World2.Stage1 == true)
				Clear3.Plus = Clear3.Plus++;
			if (data3.Star2.World2.Stage2 == true)
				Clear3.Plus = Clear3.Plus++;
			if (data3.Star2.World2.Stage3 == true)
				Clear3.Plus = Clear3.Plus++;

			// �X�^�[�R
			if (data3.Star3.World1.Stage1 == true)
				Clear3.Plus = Clear3.Plus++;
			if (data3.Star3.World1.Stage2 == true)
				Clear3.Plus = Clear3.Plus++;
			if (data3.Star3.World1.Stage3 == true)
				Clear3.Plus = Clear3.Plus++;

			if (data3.Star3.World2.Stage1 == true)
				Clear3.Plus = Clear3.Plus++;
			if (data3.Star3.World2.Stage2 == true)
				Clear3.Plus = Clear3.Plus++;
			if (data3.Star3.World2.Stage3 == true)
				Clear3.Plus = Clear3.Plus++;

			cout << "�Z�[�u�f�[�^�R���v���F " << Clear3.Plus << " �^ 18" << endl;
			Clear3.Percent = Clear3.Plus * 0.05 * 100;

			if (Clear3.Plus >= 18)
				cout << "�Z�[�u�f�[�^�R�N���A���F 100 %" << endl;
			else
				cout << "�Z�[�u�f�[�^�R�N���A���F " << Clear3.Percent << " %" << endl;

			cout << endl;
		}

		if (data3.Del == true)
		{
			cout << "�Z�[�u�f�[�^�R�͏�����Ă��܂�" << endl;
			cout << endl;
		}
	}
}



/*

�Z�[�u����֐�

*/
void Save_Load::Save1(int Star_FLG, int World_FLG, int Stage_FLG, bool Clear_FLG, bool Del_FLG)
{
	/*

	�X�^�[�P

	*/
	/*	���[���h�P	*/
	// �X�e�[�W�P
	if ((Star_FLG == 1) && (World_FLG == 1) && (Stage_FLG == 1))
	{
		data1.Star1.World1.Stage1 = Clear_FLG;
		data1.Last = LAST_NUM::LAST_111;
	}

	// �X�e�[�W�Q
	if ((Star_FLG == 1) && (World_FLG == 1) && (Stage_FLG == 2))
	{
		data1.Star1.World1.Stage2 = Clear_FLG;
		data1.Last = LAST_NUM::LAST_112;
	}

	// �X�e�[�W�R
	if ((Star_FLG == 1) && (World_FLG == 1) && (Stage_FLG == 3))
	{
		data1.Star1.World1.Stage3 = Clear_FLG;
		data1.Last = LAST_NUM::LAST_113;
	}

	/*	���[���h�Q	*/
	// �X�e�[�W�P
	if ((Star_FLG == 1) && (World_FLG == 2) && (Stage_FLG == 1))
	{
		data1.Star1.World2.Stage1 = Clear_FLG;
		data1.Last = LAST_NUM::LAST_121;
	}

	// �X�e�[�W�Q
	if ((Star_FLG == 1) && (World_FLG == 2) && (Stage_FLG == 2))
	{
		data1.Star1.World2.Stage2 = Clear_FLG;
		data1.Last = LAST_NUM::LAST_122;
	}

	// �X�e�[�W�R
	if ((Star_FLG == 1) && (World_FLG == 2) && (Stage_FLG == 3))
	{
		data1.Star1.World2.Stage3 = Clear_FLG;
		data1.Last = LAST_NUM::LAST_123;
	}



	/*

	�X�^�[�Q

	*/
	/*	���[���h�P	*/
	// �X�e�[�W�P
	if ((Star_FLG == 2) && (World_FLG == 1) && (Stage_FLG == 1))
	{
		data1.Star2.World1.Stage1 = Clear_FLG;
		data1.Last = LAST_NUM::LAST_211;
	}

	// �X�e�[�W�Q
	if ((Star_FLG == 2) && (World_FLG == 1) && (Stage_FLG == 2))
	{
		data1.Star2.World1.Stage2 = Clear_FLG;
		data1.Last = LAST_NUM::LAST_212;
	}

	// �X�e�[�W�R
	if ((Star_FLG == 2) && (World_FLG == 1) && (Stage_FLG == 3))
	{
		data1.Star2.World1.Stage3 = Clear_FLG;
		data1.Last = LAST_NUM::LAST_213;
	}

	/*	���[���h�Q	*/
	// �X�e�[�W�P
	if ((Star_FLG == 2) && (World_FLG == 2) && (Stage_FLG == 1))
	{
		data1.Star2.World2.Stage1 = Clear_FLG;
		data1.Last = LAST_NUM::LAST_221;
	}

	// �X�e�[�W�Q
	if ((Star_FLG == 2) && (World_FLG == 2) && (Stage_FLG == 2))
	{
		data1.Star2.World2.Stage2 = Clear_FLG;
		data1.Last = LAST_NUM::LAST_222;
	}

	// �X�e�[�W�R
	if ((Star_FLG == 2) && (World_FLG == 2) && (Stage_FLG == 3))
	{
		data1.Star2.World2.Stage3 = Clear_FLG;
		data1.Last = LAST_NUM::LAST_223;
	}



	/*

	�X�^�[�R

	*/
	/*	���[���h�P	*/
	// �X�e�[�W�P
	if ((Star_FLG == 3) && (World_FLG == 1) && (Stage_FLG == 1))
	{
		data1.Star3.World1.Stage1 = Clear_FLG;
		data1.Last = LAST_NUM::LAST_311;
	}

	// �X�e�[�W�Q
	if ((Star_FLG == 3) && (World_FLG == 1) && (Stage_FLG == 2))
	{
		data1.Star3.World1.Stage2 = Clear_FLG;
		data1.Last = LAST_NUM::LAST_312;
	}

	// �X�e�[�W�R
	if ((Star_FLG == 3) && (World_FLG == 1) && (Stage_FLG == 3))
	{
		data1.Star3.World1.Stage3 = Clear_FLG;
		data1.Last = LAST_NUM::LAST_313;
	}

	/*	���[���h�Q	*/
	// �X�e�[�W�P
	if ((Star_FLG == 3) && (World_FLG == 2) && (Stage_FLG == 1))
	{
		data1.Star3.World2.Stage1 = Clear_FLG;
		data1.Last = LAST_NUM::LAST_321;
	}

	// �X�e�[�W�Q
	if ((Star_FLG == 3) && (World_FLG == 2) && (Stage_FLG == 2))
	{
		data1.Star3.World2.Stage2 = Clear_FLG;
		data1.Last = LAST_NUM::LAST_322;
	}

	// �X�e�[�W�R
	if ((Star_FLG == 3) && (World_FLG == 2) && (Stage_FLG == 3))
	{
		data1.Star3.World2.Stage3 = Clear_FLG;
		data1.Last = LAST_NUM::LAST_323;
	}



	// �V�K
	if (Del_FLG == false)
		data1.Del = false;

	// �폜
	if (Del_FLG == true)
		data1.Del = true;



	FILE *fp = fopen("�Z�[�u�f�[�^1.dat", "wb");//�o�C�i���t�@�C�����J��
	fwrite(&data1, sizeof(data1), 1, fp); // SAVE_DATA�\���̂̒��g�����
	fclose(fp);//�t�@�C�������
}

void Save_Load::Save2(int Star_FLG, int World_FLG, int Stage_FLG, bool Clear_FLG, bool Del_FLG)
{
	/*

	�X�^�[�P

	*/
	/*	���[���h�P	*/
	// �X�e�[�W�P
	if ((Star_FLG == 1) && (World_FLG == 1) && (Stage_FLG == 1))
	{
		data2.Star1.World1.Stage1 = Clear_FLG;
		data2.Last = LAST_NUM::LAST_111;
	}

	// �X�e�[�W�Q
	if ((Star_FLG == 1) && (World_FLG == 1) && (Stage_FLG == 2))
	{
		data2.Star1.World1.Stage2 = Clear_FLG;
		data2.Last = LAST_NUM::LAST_112;
	}

	// �X�e�[�W�R
	if ((Star_FLG == 1) && (World_FLG == 1) && (Stage_FLG == 3))
	{
		data2.Star1.World1.Stage3 = Clear_FLG;
		data2.Last = LAST_NUM::LAST_113;
	}

	/*	���[���h�Q	*/
	// �X�e�[�W�P
	if ((Star_FLG == 1) && (World_FLG == 2) && (Stage_FLG == 1))
	{
		data2.Star1.World2.Stage1 = Clear_FLG;
		data2.Last = LAST_NUM::LAST_121;
	}

	// �X�e�[�W�Q
	if ((Star_FLG == 1) && (World_FLG == 2) && (Stage_FLG == 2))
	{
		data2.Star1.World2.Stage2 = Clear_FLG;
		data2.Last = LAST_NUM::LAST_122;
	}

	// �X�e�[�W�R
	if ((Star_FLG == 1) && (World_FLG == 2) && (Stage_FLG == 3))
	{
		data2.Star1.World2.Stage3 = Clear_FLG;
		data2.Last = LAST_NUM::LAST_123;
	}



	/*

	�X�^�[�Q

	*/
	/*	���[���h�P	*/
	// �X�e�[�W�P
	if ((Star_FLG == 2) && (World_FLG == 1) && (Stage_FLG == 1))
	{
		data2.Star2.World1.Stage1 = Clear_FLG;
		data2.Last = LAST_NUM::LAST_211;
	}

	// �X�e�[�W�Q
	if ((Star_FLG == 2) && (World_FLG == 1) && (Stage_FLG == 2))
	{
		data2.Star2.World1.Stage2 = Clear_FLG;
		data2.Last = LAST_NUM::LAST_212;
	}

	// �X�e�[�W�R
	if ((Star_FLG == 2) && (World_FLG == 1) && (Stage_FLG == 3))
	{
		data2.Star2.World1.Stage3 = Clear_FLG;
		data2.Last = LAST_NUM::LAST_213;
	}

	/*	���[���h�Q	*/
	// �X�e�[�W�P
	if ((Star_FLG == 2) && (World_FLG == 2) && (Stage_FLG == 1))
	{
		data2.Star2.World2.Stage1 = Clear_FLG;
		data2.Last = LAST_NUM::LAST_221;
	}

	// �X�e�[�W�Q
	if ((Star_FLG == 2) && (World_FLG == 2) && (Stage_FLG == 2))
	{
		data2.Star2.World2.Stage2 = Clear_FLG;
		data2.Last = LAST_NUM::LAST_222;
	}

	// �X�e�[�W�R
	if ((Star_FLG == 2) && (World_FLG == 2) && (Stage_FLG == 3))
	{
		data2.Star2.World2.Stage3 = Clear_FLG;
		data2.Last = LAST_NUM::LAST_223;
	}



	/*

	�X�^�[�R

	*/
	/*	���[���h�P	*/
	// �X�e�[�W�P
	if ((Star_FLG == 3) && (World_FLG == 1) && (Stage_FLG == 1))
	{
		data2.Star3.World1.Stage1 = Clear_FLG;
		data2.Last = LAST_NUM::LAST_311;
	}

	// �X�e�[�W�Q
	if ((Star_FLG == 3) && (World_FLG == 1) && (Stage_FLG == 2))
	{
		data2.Star3.World1.Stage2 = Clear_FLG;
		data2.Last = LAST_NUM::LAST_312;
	}

	// �X�e�[�W�R
	if ((Star_FLG == 3) && (World_FLG == 1) && (Stage_FLG == 3))
	{
		data2.Star3.World1.Stage3 = Clear_FLG;
		data2.Last = LAST_NUM::LAST_313;
	}

	/*	���[���h�Q	*/
	// �X�e�[�W�P
	if ((Star_FLG == 3) && (World_FLG == 2) && (Stage_FLG == 1))
	{
		data2.Star3.World2.Stage1 = Clear_FLG;
		data2.Last = LAST_NUM::LAST_321;
	}

	// �X�e�[�W�Q
	if ((Star_FLG == 3) && (World_FLG == 2) && (Stage_FLG == 2))
	{
		data2.Star3.World2.Stage2 = Clear_FLG;
		data2.Last = LAST_NUM::LAST_322;
	}

	// �X�e�[�W�R
	if ((Star_FLG == 3) && (World_FLG == 2) && (Stage_FLG == 3))
	{
		data2.Star3.World2.Stage3 = Clear_FLG;
		data2.Last = LAST_NUM::LAST_323;
	}



	// �V�K
	if (Del_FLG == false)
		data2.Del = false;

	// �폜
	if (Del_FLG == true)
		data2.Del = true;



	FILE *fp = fopen("�Z�[�u�f�[�^2.dat", "wb");//�o�C�i���t�@�C�����J��
	fwrite(&data2, sizeof(data2), 1, fp); // SAVE_DATA�\���̂̒��g�����
	fclose(fp);//�t�@�C�������
}

void Save_Load::Save3(int Star_FLG, int World_FLG, int Stage_FLG, bool Clear_FLG, bool Del_FLG)
{
	/*

	�X�^�[�P

	*/
	/*	���[���h�P	*/
	// �X�e�[�W�P
	if ((Star_FLG == 1) && (World_FLG == 1) && (Stage_FLG == 1))
	{
		data3.Star1.World1.Stage1 = Clear_FLG;
		data3.Last = LAST_NUM::LAST_111;
	}

	// �X�e�[�W�Q
	if ((Star_FLG == 1) && (World_FLG == 1) && (Stage_FLG == 2))
	{
		data3.Star1.World1.Stage2 = Clear_FLG;
		data3.Last = LAST_NUM::LAST_112;
	}

	// �X�e�[�W�R
	if ((Star_FLG == 1) && (World_FLG == 1) && (Stage_FLG == 3))
	{
		data3.Star1.World1.Stage3 = Clear_FLG;
		data3.Last = LAST_NUM::LAST_113;
	}

	/*	���[���h�Q	*/
	// �X�e�[�W�P
	if ((Star_FLG == 1) && (World_FLG == 2) && (Stage_FLG == 1))
	{
		data3.Star1.World2.Stage1 = Clear_FLG;
		data3.Last = LAST_NUM::LAST_121;
	}

	// �X�e�[�W�Q
	if ((Star_FLG == 1) && (World_FLG == 2) && (Stage_FLG == 2))
	{
		data3.Star1.World2.Stage2 = Clear_FLG;
		data3.Last = LAST_NUM::LAST_122;
	}

	// �X�e�[�W�R
	if ((Star_FLG == 1) && (World_FLG == 2) && (Stage_FLG == 3))
	{
		data3.Star1.World2.Stage3 = Clear_FLG;
		data3.Last = LAST_NUM::LAST_123;
	}



	/*

	�X�^�[�Q

	*/
	/*	���[���h�P	*/
	// �X�e�[�W�P
	if ((Star_FLG == 2) && (World_FLG == 1) && (Stage_FLG == 1))
	{
		data3.Star2.World1.Stage1 = Clear_FLG;
		data3.Last = LAST_NUM::LAST_211;
	}

	// �X�e�[�W�Q
	if ((Star_FLG == 2) && (World_FLG == 1) && (Stage_FLG == 2))
	{
		data3.Star2.World1.Stage2 = Clear_FLG;
		data3.Last = LAST_NUM::LAST_212;
	}

	// �X�e�[�W�R
	if ((Star_FLG == 2) && (World_FLG == 1) && (Stage_FLG == 3))
	{
		data3.Star2.World1.Stage3 = Clear_FLG;
		data3.Last = LAST_NUM::LAST_213;
	}

	/*	���[���h�Q	*/
	// �X�e�[�W�P
	if ((Star_FLG == 2) && (World_FLG == 2) && (Stage_FLG == 1))
	{
		data3.Star2.World2.Stage1 = Clear_FLG;
		data3.Last = LAST_NUM::LAST_221;
	}

	// �X�e�[�W�Q
	if ((Star_FLG == 2) && (World_FLG == 2) && (Stage_FLG == 2))
	{
		data3.Star2.World2.Stage2 = Clear_FLG;
		data3.Last = LAST_NUM::LAST_222;
	}

	// �X�e�[�W�R
	if ((Star_FLG == 2) && (World_FLG == 2) && (Stage_FLG == 3))
	{
		data3.Star2.World2.Stage3 = Clear_FLG;
		data3.Last = LAST_NUM::LAST_223;
	}



	/*

	�X�^�[�R

	*/
	/*	���[���h�P	*/
	// �X�e�[�W�P
	if ((Star_FLG == 3) && (World_FLG == 1) && (Stage_FLG == 1))
	{
		data3.Star3.World1.Stage1 = Clear_FLG;
		data3.Last = LAST_NUM::LAST_311;
	}

	// �X�e�[�W�Q
	if ((Star_FLG == 3) && (World_FLG == 1) && (Stage_FLG == 2))
	{
		data3.Star3.World1.Stage2 = Clear_FLG;
		data3.Last = LAST_NUM::LAST_312;
	}

	// �X�e�[�W�R
	if ((Star_FLG == 3) && (World_FLG == 1) && (Stage_FLG == 3))
	{
		data3.Star3.World1.Stage3 = Clear_FLG;
		data3.Last = LAST_NUM::LAST_313;
	}

	/*	���[���h�Q	*/
	// �X�e�[�W�P
	if ((Star_FLG == 3) && (World_FLG == 2) && (Stage_FLG == 1))
	{
		data3.Star3.World2.Stage1 = Clear_FLG;
		data3.Last = LAST_NUM::LAST_321;
	}

	// �X�e�[�W�Q
	if ((Star_FLG == 3) && (World_FLG == 2) && (Stage_FLG == 2))
	{
		data3.Star3.World2.Stage2 = Clear_FLG;
		data3.Last = LAST_NUM::LAST_322;
	}

	// �X�e�[�W�R
	if ((Star_FLG == 3) && (World_FLG == 2) && (Stage_FLG == 3))
	{
		data3.Star3.World2.Stage3 = Clear_FLG;
		data3.Last = LAST_NUM::LAST_323;
	}



	// �V�K
	if (Del_FLG == false)
		data3.Del = false;

	// �폜
	if (Del_FLG == true)
		data3.Del = true;



	FILE *fp = fopen("�Z�[�u�f�[�^3.dat", "wb");//�o�C�i���t�@�C�����J��
	fwrite(&data3, sizeof(data3), 1, fp); // SAVE_DATA�\���̂̒��g�����
	fclose(fp);//�t�@�C�������
}



/*

���[�h����֐�

*/
char Save_Load::Load1()
{
	FILE *fp;

	if ((fp = fopen("�Z�[�u�f�[�^1.dat", "rb")) == NULL)
	{
		cout << "�Z�[�u�f�[�^���Ȃ��ł�" << endl;
	};

	//�o�C�i���t�@�C����ǂݍ���
	if (fp = fopen("�Z�[�u�f�[�^1.dat", "rb"))
	{
		fread(&data1, sizeof(data1), 1, fp); // SAVE_DATA�\���̂̒��g���o��
		fclose(fp);//�t�@�C�������

		// �폜�t���O�������Ă��Ȃ�
		if (data1.Del == false)
		{
			Save_Load::Answer1();
			Save_Load::SWS_true1();
		}

		// �폜�t���O�������Ă���
		if (data1.Del == true)
		{
			cout << "�Z�[�u�f�[�^�̒��g���폜����Ă܂��B" << endl;
			system("pause");
		}

	};

	return
		// �X�^�[�P
		data1.Star1.World1.Stage1, data1.Star1.World1.Stage2, data1.Star1.World1.Stage3,
		data1.Star1.World2.Stage1, data1.Star1.World2.Stage2, data1.Star1.World2.Stage3,

		// �X�^�[�Q
		data1.Star2.World1.Stage1, data1.Star2.World1.Stage2, data1.Star2.World1.Stage3,
		data1.Star2.World2.Stage1, data1.Star2.World2.Stage2, data1.Star2.World2.Stage3,

		// �X�^�[�R
		data1.Star3.World1.Stage1, data1.Star3.World1.Stage2, data1.Star3.World1.Stage3,
		data1.Star3.World2.Stage1, data1.Star3.World2.Stage2, data1.Star3.World2.Stage3,

		// �폜����
		data1.Del;
}

char Save_Load::Load2()
{
	FILE *fp;

	if ((fp = fopen("�Z�[�u�f�[�^2.dat", "rb")) == NULL)
	{
		cout << "�Z�[�u�f�[�^���Ȃ��ł�" << endl;
	};

	//�o�C�i���t�@�C����ǂݍ���
	if (fp = fopen("�Z�[�u�f�[�^2.dat", "rb"))
	{
		fread(&data2, sizeof(data2), 1, fp); // SAVE_DATA�\���̂̒��g���o��
		fclose(fp);//�t�@�C�������

		// �폜�t���O�������Ă��Ȃ�
		if (data2.Del == false)
		{
			Save_Load::Answer2();
			Save_Load::SWS_true2();
		}

		// �폜�t���O�������Ă���
		if (data2.Del == true)
		{
			cout << "�Z�[�u�f�[�^�̒��g���폜����Ă܂��B" << endl;
			system("pause");
		}

	};

	return
		// �X�^�[�P
		data2.Star1.World1.Stage1, data2.Star1.World1.Stage2, data2.Star1.World1.Stage3,
		data2.Star1.World2.Stage1, data2.Star1.World2.Stage2, data2.Star1.World2.Stage3,

		// �X�^�[�Q
		data2.Star2.World1.Stage1, data2.Star2.World1.Stage2, data2.Star2.World1.Stage3,
		data2.Star2.World2.Stage1, data2.Star2.World2.Stage2, data2.Star2.World2.Stage3,

		// �X�^�[�R
		data2.Star3.World1.Stage1, data2.Star3.World1.Stage2, data2.Star3.World1.Stage3,
		data2.Star3.World2.Stage1, data2.Star3.World2.Stage2, data2.Star3.World2.Stage3,

		// �폜����
		data2.Del;
}

char Save_Load::Load3()
{
	FILE *fp;

	if ((fp = fopen("�Z�[�u�f�[�^3.dat", "rb")) == NULL)
	{
		cout << "�Z�[�u�f�[�^���Ȃ��ł�" << endl;
	};

	//�o�C�i���t�@�C����ǂݍ���
	if (fp = fopen("�Z�[�u�f�[�^3.dat", "rb"))
	{
		fread(&data3, sizeof(data3), 1, fp); // SAVE_DATA�\���̂̒��g���o��
		fclose(fp);//�t�@�C�������

		// �폜�t���O�������Ă��Ȃ�
		if (data3.Del == false)
		{
			Save_Load::Answer3();
			Save_Load::SWS_true3();
		}

		// �폜�t���O�������Ă���
		if (data3.Del == true)
		{
			cout << "�Z�[�u�f�[�^�̒��g���폜����Ă܂��B" << endl;
			system("pause");
		}

	};

	return
		// �X�^�[�P
		data3.Star1.World1.Stage1, data3.Star1.World1.Stage2, data3.Star1.World1.Stage3,
		data3.Star1.World2.Stage1, data3.Star1.World2.Stage2, data3.Star1.World2.Stage3,

		// �X�^�[�Q
		data3.Star2.World1.Stage1, data3.Star2.World1.Stage2, data3.Star2.World1.Stage3,
		data3.Star2.World2.Stage1, data3.Star2.World2.Stage2, data3.Star2.World2.Stage3,

		// �X�^�[�R
		data3.Star3.World1.Stage1, data3.Star3.World1.Stage2, data3.Star3.World1.Stage3,
		data3.Star3.World2.Stage1, data3.Star3.World2.Stage2, data3.Star3.World2.Stage3,

		// �폜����
		data3.Del;
}



/*

�Ō�Ƀv���C�������[���h���X�e�[�W�𓚂���֐�

*/
void Save_Load::Last1()
{
	cout << "�Ō�Ƀv���C�������[���h���X�e�[�W" << endl;

	/*

	�X�^�[�P

	*/
	/*	���[���h�P	*/
	// �X�e�[�W�P
	if (data1.Last == LAST_NUM::LAST_111)
		cout << "�X�^�[�P�@���[���h�P�@�X�e�[�W�P" << endl << endl;
	// �X�e�[�W�Q
	if (data1.Last == LAST_NUM::LAST_112)
		cout << "�X�^�[�P�@���[���h�P�@�X�e�[�W�Q" << endl << endl;
	// �X�e�[�W�R
	if (data1.Last == LAST_NUM::LAST_113)
		cout << "�X�^�[�P�@���[���h�P�@�X�e�[�W�R" << endl << endl;

	/*	���[���h�Q	*/
	// �X�e�[�W�P
	if (data1.Last == LAST_NUM::LAST_121)
		cout << "�X�^�[�P�@���[���h�Q�@�X�e�[�W�P" << endl << endl;
	// �X�e�[�W�Q
	if (data1.Last == LAST_NUM::LAST_122)
		cout << "�X�^�[�P�@���[���h�Q�@�X�e�[�W�Q" << endl << endl;
	// �X�e�[�W�R
	if (data1.Last == LAST_NUM::LAST_123)
		cout << "�X�^�[�P�@���[���h�Q�@�X�e�[�W�R" << endl << endl;



	/*

	�X�^�[�Q

	*/
	/*	���[���h�P	*/
	// �X�e�[�W�P
	if (data1.Last == LAST_NUM::LAST_211)
		cout << "�X�^�[�Q�@���[���h�P�@�X�e�[�W�P" << endl << endl;
	// �X�e�[�W�Q
	if (data1.Last == LAST_NUM::LAST_212)
		cout << "�X�^�[�Q�@���[���h�P�@�X�e�[�W�Q" << endl << endl;
	// �X�e�[�W�R
	if (data1.Last == LAST_NUM::LAST_213)
		cout << "�X�^�[�Q�@���[���h�P�@�X�e�[�W�R" << endl << endl;

	/*	���[���h�Q	*/
	// �X�e�[�W�P
	if (data1.Last == LAST_NUM::LAST_221)
		cout << "�X�^�[�Q�@���[���h�Q�@�X�e�[�W�P" << endl << endl;
	// �X�e�[�W�Q
	if (data1.Last == LAST_NUM::LAST_222)
		cout << "�X�^�[�Q�@���[���h�Q�@�X�e�[�W�Q" << endl << endl;
	// �X�e�[�W�R
	if (data1.Last == LAST_NUM::LAST_223)
		cout << "�X�^�[�Q�@���[���h�Q�@�X�e�[�W�R" << endl << endl;



	/*

	�X�^�[�R

	*/
	/*	���[���h�P	*/
	// �X�e�[�W�P
	if (data1.Last == LAST_NUM::LAST_311)
		cout << "�X�^�[�R�@���[���h�P�@�X�e�[�W�P" << endl << endl;
	// �X�e�[�W�Q
	if (data1.Last == LAST_NUM::LAST_312)
		cout << "�X�^�[�R�@���[���h�P�@�X�e�[�W�Q" << endl << endl;
	// �X�e�[�W�R
	if (data1.Last == LAST_NUM::LAST_313)
		cout << "�X�^�[�R�@���[���h�P�@�X�e�[�W�R" << endl << endl;

	/*	���[���h�Q	*/
	// �X�e�[�W�P
	if (data1.Last == LAST_NUM::LAST_321)
		cout << "�X�^�[�R�@���[���h�Q�@�X�e�[�W�P" << endl << endl;
	// �X�e�[�W�Q
	if (data1.Last == LAST_NUM::LAST_322)
		cout << "�X�^�[�R�@���[���h�Q�@�X�e�[�W�Q" << endl << endl;
	// �X�e�[�W�R
	if (data1.Last == LAST_NUM::LAST_323)
		cout << "�X�^�[�R�@���[���h�Q�@�X�e�[�W�R" << endl << endl;
}

void Save_Load::Last2()
{
	cout << "�Ō�Ƀv���C�������[���h���X�e�[�W" << endl;

	/*

	�X�^�[�P

	*/
	/*	���[���h�P	*/
	// �X�e�[�W�P
	if (data2.Last == LAST_NUM::LAST_111)
		cout << "�X�^�[�P�@���[���h�P�@�X�e�[�W�P" << endl << endl;
	// �X�e�[�W�Q
	if (data2.Last == LAST_NUM::LAST_112)
		cout << "�X�^�[�P�@���[���h�P�@�X�e�[�W�Q" << endl << endl;
	// �X�e�[�W�R
	if (data2.Last == LAST_NUM::LAST_113)
		cout << "�X�^�[�P�@���[���h�P�@�X�e�[�W�R" << endl << endl;

	/*	���[���h�Q	*/
	// �X�e�[�W�P
	if (data2.Last == LAST_NUM::LAST_121)
		cout << "�X�^�[�P�@���[���h�Q�@�X�e�[�W�P" << endl << endl;
	// �X�e�[�W�Q
	if (data2.Last == LAST_NUM::LAST_122)
		cout << "�X�^�[�P�@���[���h�Q�@�X�e�[�W�Q" << endl << endl;
	// �X�e�[�W�R
	if (data2.Last == LAST_NUM::LAST_123)
		cout << "�X�^�[�P�@���[���h�Q�@�X�e�[�W�R" << endl << endl;



	/*

	�X�^�[�Q

	*/
	/*	���[���h�P	*/
	// �X�e�[�W�P
	if (data2.Last == LAST_NUM::LAST_211)
		cout << "�X�^�[�Q�@���[���h�P�@�X�e�[�W�P" << endl << endl;
	// �X�e�[�W�Q
	if (data2.Last == LAST_NUM::LAST_212)
		cout << "�X�^�[�Q�@���[���h�P�@�X�e�[�W�Q" << endl << endl;
	// �X�e�[�W�R
	if (data2.Last == LAST_NUM::LAST_213)
		cout << "�X�^�[�Q�@���[���h�P�@�X�e�[�W�R" << endl << endl;

	/*	���[���h�Q	*/
	// �X�e�[�W�P
	if (data2.Last == LAST_NUM::LAST_221)
		cout << "�X�^�[�Q�@���[���h�Q�@�X�e�[�W�P" << endl << endl;
	// �X�e�[�W�Q
	if (data2.Last == LAST_NUM::LAST_222)
		cout << "�X�^�[�Q�@���[���h�Q�@�X�e�[�W�Q" << endl << endl;
	// �X�e�[�W�R
	if (data2.Last == LAST_NUM::LAST_223)
		cout << "�X�^�[�Q�@���[���h�Q�@�X�e�[�W�R" << endl << endl;



	/*

	�X�^�[�R

	*/
	/*	���[���h�P	*/
	// �X�e�[�W�P
	if (data2.Last == LAST_NUM::LAST_311)
		cout << "�X�^�[�R�@���[���h�P�@�X�e�[�W�P" << endl << endl;
	// �X�e�[�W�Q
	if (data2.Last == LAST_NUM::LAST_312)
		cout << "�X�^�[�R�@���[���h�P�@�X�e�[�W�Q" << endl << endl;
	// �X�e�[�W�R
	if (data2.Last == LAST_NUM::LAST_313)
		cout << "�X�^�[�R�@���[���h�P�@�X�e�[�W�R" << endl << endl;

	/*	���[���h�Q	*/
	// �X�e�[�W�P
	if (data2.Last == LAST_NUM::LAST_321)
		cout << "�X�^�[�R�@���[���h�Q�@�X�e�[�W�P" << endl << endl;
	// �X�e�[�W�Q
	if (data2.Last == LAST_NUM::LAST_322)
		cout << "�X�^�[�R�@���[���h�Q�@�X�e�[�W�Q" << endl << endl;
	// �X�e�[�W�R
	if (data2.Last == LAST_NUM::LAST_323)
		cout << "�X�^�[�R�@���[���h�Q�@�X�e�[�W�R" << endl << endl;
}

void Save_Load::Last3()
{
	cout << "�Ō�Ƀv���C�������[���h���X�e�[�W" << endl;

	/*

	�X�^�[�P

	*/
	/*	���[���h�P	*/
	// �X�e�[�W�P
	if (data3.Last == LAST_NUM::LAST_111)
		cout << "�X�^�[�P�@���[���h�P�@�X�e�[�W�P" << endl << endl;
	// �X�e�[�W�Q
	if (data3.Last == LAST_NUM::LAST_112)
		cout << "�X�^�[�P�@���[���h�P�@�X�e�[�W�Q" << endl << endl;
	// �X�e�[�W�R
	if (data3.Last == LAST_NUM::LAST_113)
		cout << "�X�^�[�P�@���[���h�P�@�X�e�[�W�R" << endl << endl;

	/*	���[���h�Q	*/
	// �X�e�[�W�P
	if (data3.Last == LAST_NUM::LAST_121)
		cout << "�X�^�[�P�@���[���h�Q�@�X�e�[�W�P" << endl << endl;
	// �X�e�[�W�Q
	if (data3.Last == LAST_NUM::LAST_122)
		cout << "�X�^�[�P�@���[���h�Q�@�X�e�[�W�Q" << endl << endl;
	// �X�e�[�W�R
	if (data3.Last == LAST_NUM::LAST_123)
		cout << "�X�^�[�P�@���[���h�Q�@�X�e�[�W�R" << endl << endl;



	/*

	�X�^�[�Q

	*/
	/*	���[���h�P	*/
	// �X�e�[�W�P
	if (data3.Last == LAST_NUM::LAST_211)
		cout << "�X�^�[�Q�@���[���h�P�@�X�e�[�W�P" << endl << endl;
	// �X�e�[�W�Q
	if (data3.Last == LAST_NUM::LAST_212)
		cout << "�X�^�[�Q�@���[���h�P�@�X�e�[�W�Q" << endl << endl;
	// �X�e�[�W�R
	if (data3.Last == LAST_NUM::LAST_213)
		cout << "�X�^�[�Q�@���[���h�P�@�X�e�[�W�R" << endl << endl;

	/*	���[���h�Q	*/
	// �X�e�[�W�P
	if (data3.Last == LAST_NUM::LAST_221)
		cout << "�X�^�[�Q�@���[���h�Q�@�X�e�[�W�P" << endl << endl;
	// �X�e�[�W�Q
	if (data3.Last == LAST_NUM::LAST_222)
		cout << "�X�^�[�Q�@���[���h�Q�@�X�e�[�W�Q" << endl << endl;
	// �X�e�[�W�R
	if (data3.Last == LAST_NUM::LAST_223)
		cout << "�X�^�[�Q�@���[���h�Q�@�X�e�[�W�R" << endl << endl;



	/*

	�X�^�[�R

	*/
	/*	���[���h�P	*/
	// �X�e�[�W�P
	if (data3.Last == LAST_NUM::LAST_311)
		cout << "�X�^�[�R�@���[���h�P�@�X�e�[�W�P" << endl << endl;
	// �X�e�[�W�Q
	if (data3.Last == LAST_NUM::LAST_312)
		cout << "�X�^�[�R�@���[���h�P�@�X�e�[�W�Q" << endl << endl;
	// �X�e�[�W�R
	if (data3.Last == LAST_NUM::LAST_313)
		cout << "�X�^�[�R�@���[���h�P�@�X�e�[�W�R" << endl << endl;

	/*	���[���h�Q	*/
	// �X�e�[�W�P
	if (data3.Last == LAST_NUM::LAST_321)
		cout << "�X�^�[�R�@���[���h�Q�@�X�e�[�W�P" << endl << endl;
	// �X�e�[�W�Q
	if (data3.Last == LAST_NUM::LAST_322)
		cout << "�X�^�[�R�@���[���h�Q�@�X�e�[�W�Q" << endl << endl;
	// �X�e�[�W�R
	if (data3.Last == LAST_NUM::LAST_323)
		cout << "�X�^�[�R�@���[���h�Q�@�X�e�[�W�R" << endl << endl;
}



/*

�N���A����𓚂���֐�

*/
void Save_Load::Answer1()
{
	cout << "�X�^�[�P" << endl;
	cout << "���[���h�P" << endl;
	cout << "�X�e�[�W�P�F" << data1.Star1.World1.Stage1 << endl;
	cout << "�X�e�[�W�Q�F" << data1.Star1.World1.Stage2 << endl;
	cout << "�X�e�[�W�R�F" << data1.Star1.World1.Stage3 << endl;
	cout << "���[���h�Q" << endl;
	cout << "�X�e�[�W�P�F" << data1.Star1.World2.Stage1 << endl;
	cout << "�X�e�[�W�Q�F" << data1.Star1.World2.Stage2 << endl;
	cout << "�X�e�[�W�R�F" << data1.Star1.World2.Stage3 << endl;
	cout << endl;

	cout << "�X�^�[�Q" << endl;
	cout << "���[���h�P" << endl;
	cout << "�X�e�[�W�P�F" << data1.Star2.World1.Stage1 << endl;
	cout << "�X�e�[�W�Q�F" << data1.Star2.World1.Stage2 << endl;
	cout << "�X�e�[�W�R�F" << data1.Star2.World1.Stage3 << endl;
	cout << "���[���h�Q" << endl;
	cout << "�X�e�[�W�P�F" << data1.Star2.World2.Stage1 << endl;
	cout << "�X�e�[�W�Q�F" << data1.Star2.World2.Stage2 << endl;
	cout << "�X�e�[�W�R�F" << data1.Star2.World2.Stage3 << endl;
	cout << endl;

	cout << "�X�^�[�R" << endl;
	cout << "���[���h�P" << endl;
	cout << "�X�e�[�W�P�F" << data1.Star3.World1.Stage1 << endl;
	cout << "�X�e�[�W�Q�F" << data1.Star3.World1.Stage2 << endl;
	cout << "�X�e�[�W�R�F" << data1.Star3.World1.Stage3 << endl;
	cout << "���[���h�Q" << endl;
	cout << "�X�e�[�W�P�F" << data1.Star3.World2.Stage1 << endl;
	cout << "�X�e�[�W�Q�F" << data1.Star3.World2.Stage2 << endl;
	cout << "�X�e�[�W�R�F" << data1.Star3.World2.Stage3 << endl;
	cout << endl;
}

void Save_Load::Answer2()
{
	cout << "�X�^�[�P" << endl;
	cout << "���[���h�P" << endl;
	cout << "�X�e�[�W�P�F" << data2.Star1.World1.Stage1 << endl;
	cout << "�X�e�[�W�Q�F" << data2.Star1.World1.Stage2 << endl;
	cout << "�X�e�[�W�R�F" << data2.Star1.World1.Stage3 << endl;
	cout << "���[���h�Q" << endl;
	cout << "�X�e�[�W�P�F" << data2.Star1.World2.Stage1 << endl;
	cout << "�X�e�[�W�Q�F" << data2.Star1.World2.Stage2 << endl;
	cout << "�X�e�[�W�R�F" << data2.Star1.World2.Stage3 << endl;
	cout << endl;

	cout << "�X�^�[�Q" << endl;
	cout << "���[���h�P" << endl;
	cout << "�X�e�[�W�P�F" << data2.Star2.World1.Stage1 << endl;
	cout << "�X�e�[�W�Q�F" << data2.Star2.World1.Stage2 << endl;
	cout << "�X�e�[�W�R�F" << data2.Star2.World1.Stage3 << endl;
	cout << "���[���h�Q" << endl;
	cout << "�X�e�[�W�P�F" << data2.Star2.World2.Stage1 << endl;
	cout << "�X�e�[�W�Q�F" << data2.Star2.World2.Stage2 << endl;
	cout << "�X�e�[�W�R�F" << data2.Star2.World2.Stage3 << endl;
	cout << endl;

	cout << "�X�^�[�R" << endl;
	cout << "���[���h�P" << endl;
	cout << "�X�e�[�W�P�F" << data2.Star3.World1.Stage1 << endl;
	cout << "�X�e�[�W�Q�F" << data2.Star3.World1.Stage2 << endl;
	cout << "�X�e�[�W�R�F" << data2.Star3.World1.Stage3 << endl;
	cout << "���[���h�Q" << endl;
	cout << "�X�e�[�W�P�F" << data2.Star3.World2.Stage1 << endl;
	cout << "�X�e�[�W�Q�F" << data2.Star3.World2.Stage2 << endl;
	cout << "�X�e�[�W�R�F" << data2.Star3.World2.Stage3 << endl;
	cout << endl;
}

void Save_Load::Answer3()
{
	cout << "�X�^�[�P" << endl;
	cout << "���[���h�P" << endl;
	cout << "�X�e�[�W�P�F" << data3.Star1.World1.Stage1 << endl;
	cout << "�X�e�[�W�Q�F" << data3.Star1.World1.Stage2 << endl;
	cout << "�X�e�[�W�R�F" << data3.Star1.World1.Stage3 << endl;
	cout << "���[���h�Q" << endl;
	cout << "�X�e�[�W�P�F" << data3.Star1.World2.Stage1 << endl;
	cout << "�X�e�[�W�Q�F" << data3.Star1.World2.Stage2 << endl;
	cout << "�X�e�[�W�R�F" << data3.Star1.World2.Stage3 << endl;
	cout << endl;

	cout << "�X�^�[�Q" << endl;
	cout << "���[���h�P" << endl;
	cout << "�X�e�[�W�P�F" << data3.Star2.World1.Stage1 << endl;
	cout << "�X�e�[�W�Q�F" << data3.Star2.World1.Stage2 << endl;
	cout << "�X�e�[�W�R�F" << data3.Star2.World1.Stage3 << endl;
	cout << "���[���h�Q" << endl;
	cout << "�X�e�[�W�P�F" << data3.Star2.World2.Stage1 << endl;
	cout << "�X�e�[�W�Q�F" << data3.Star2.World2.Stage2 << endl;
	cout << "�X�e�[�W�R�F" << data3.Star2.World2.Stage3 << endl;
	cout << endl;

	cout << "�X�^�[�R" << endl;
	cout << "���[���h�P" << endl;
	cout << "�X�e�[�W�P�F" << data3.Star3.World1.Stage1 << endl;
	cout << "�X�e�[�W�Q�F" << data3.Star3.World1.Stage2 << endl;
	cout << "�X�e�[�W�R�F" << data3.Star3.World1.Stage3 << endl;
	cout << "���[���h�Q" << endl;
	cout << "�X�e�[�W�P�F" << data3.Star3.World2.Stage1 << endl;
	cout << "�X�e�[�W�Q�F" << data3.Star3.World2.Stage2 << endl;
	cout << "�X�e�[�W�R�F" << data3.Star3.World2.Stage3 << endl;
	cout << endl;
}



/*

�f�[�^������������֐�

*/
void Save_Load::Initialize_Data1(bool Del_FLG)
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
		for (world_num = 1; world_num <= 2; world_num++)
		{
			for (star_num = 1; star_num <= 3; star_num++)
			{
				Save_Load::Save1(star_num, world_num, stage_num, false, Del_FLG);
			}
		}
	}
}

void Save_Load::Initialize_Data2(bool Del_FLG)
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
		for (world_num = 1; world_num <= 2; world_num++)
		{
			for (star_num = 1; star_num <= 3; star_num++)
			{
				Save_Load::Save2(star_num, world_num, stage_num, false, Del_FLG);
			}
		}
	}
}

void Save_Load::Initialize_Data3(bool Del_FLG)
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
		for (world_num = 1; world_num <= 2; world_num++)
		{
			for (star_num = 1; star_num <= 3; star_num++)
			{
				Save_Load::Save3(star_num, world_num, stage_num, false, Del_FLG);
			}
		}
	}
}



/*

�X�^�[�E���[���h�E�X�e�[�W��^����֐�

*/
void Save_Load::SWS_true1()
{
	cout << "�N���A�ꏊ���w�肷�邩�H" << endl;
	cout << "1�F����@�@0�F���Ȃ�" << endl;
	cin >> loop;

	while (loop)
	{
		cout << "�N���A���w�肵�����X�^�[��I��" << endl;
		cin >> star_num;

		cout << "�N���A���w�肵�������[���h��I��" << endl;
		cin >> world_num;

		cout << "�N���A���w�肵�����X�e�[�W��I��" << endl;
		cin >> stage_num;

		system("cls");
		Save_Load::Save1(star_num, world_num, stage_num, true, false);
		Save_Load::Last1();
		Save_Load::Load1();
	}
}

void Save_Load::SWS_true2()
{
	cout << "�N���A�ꏊ���w�肷�邩�H" << endl;
	cout << "1�F����@�@0�F���Ȃ�" << endl;
	cin >> loop;

	while (loop)
	{
		cout << "�N���A���w�肵�����X�^�[��I��" << endl;
		cin >> star_num;

		cout << "�N���A���w�肵�������[���h��I��" << endl;
		cin >> world_num;

		cout << "�N���A���w�肵�����X�e�[�W��I��" << endl;
		cin >> stage_num;

		system("cls");
		Save_Load::Save2(star_num, world_num, stage_num, true, false);
		Save_Load::Last2();
		Save_Load::Load2();
	}
}

void Save_Load::SWS_true3()
{
	cout << "�N���A�ꏊ���w�肷�邩�H" << endl;
	cout << "1�F����@�@0�F���Ȃ�" << endl;
	cin >> loop;

	while (loop)
	{
		cout << "�N���A���w�肵�����X�^�[��I��" << endl;
		cin >> star_num;

		cout << "�N���A���w�肵�������[���h��I��" << endl;
		cin >> world_num;

		cout << "�N���A���w�肵�����X�e�[�W��I��" << endl;
		cin >> stage_num;

		system("cls");
		Save_Load::Save3(star_num, world_num, stage_num, true, false);
		Save_Load::Last3();
		Save_Load::Load3();
	}
}