#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include "Save_Load.h"

using namespace std;

void Save_Load::Save(int world_num, int stage_num, bool Clear_FLG ,bool Del_FLG)
{
	/*
		ワールド１
	*/
	// ステージ１
	if ((world_num == 1)&&(stage_num ==1))
		data.World1.Stage1 = Clear_FLG;

	// ステージ２
	if ((world_num == 1) && (stage_num == 2))
		data.World1.Stage2 = Clear_FLG;

	// ステージ３
	if ((world_num == 1) && (stage_num == 3))
		data.World1.Stage3 = Clear_FLG;

	/*
		ワールド２
	*/
	// ステージ１
	if ((world_num == 2) && (stage_num == 1))
		data.World2.Stage1 = Clear_FLG;

	// ステージ２
	if ((world_num == 2) && (stage_num == 2))
		data.World2.Stage2 = Clear_FLG;

	// ステージ３
	if ((world_num == 2) && (stage_num == 3))
		data.World2.Stage3 = Clear_FLG;

	/*
		ワールド３
	*/
	// ステージ１
	if ((world_num == 3) && (stage_num == 1))
		data.World3.Stage1 = Clear_FLG;

	// ステージ２
	if ((world_num == 3) && (stage_num == 2))
		data.World3.Stage2 = Clear_FLG;

	// ステージ３
	if ((world_num == 3) && (stage_num == 3))
		data.World3.Stage3 = Clear_FLG;

	/*
		ワールド４
	*/
	// ステージ１
	if ((world_num == 4) && (stage_num == 1))
		data.World4.Stage1 = Clear_FLG;

	// ステージ２
	if ((world_num == 4) && (stage_num == 2))
		data.World4.Stage2 = Clear_FLG;

	// ステージ３
	if ((world_num == 4) && (stage_num == 3))
		data.World4.Stage3 = Clear_FLG;

	/*
		ワールド５
	*/
	// ステージ１
	if ((world_num == 5) && (stage_num == 1))
		data.World5.Stage1 = Clear_FLG;

	// ステージ２
	if ((world_num == 5) && (stage_num == 2))
		data.World5.Stage2 = Clear_FLG;

	// ステージ３
	if ((world_num == 5) && (stage_num == 3))
		data.World5.Stage3 = Clear_FLG;

	/*
		ワールド６
	*/
	// ステージ１
	if ((world_num == 6) && (stage_num == 1))
		data.World6.Stage1 = Clear_FLG;

	// ステージ２
	if ((world_num == 6) && (stage_num == 2))
		data.World6.Stage2 = Clear_FLG;

	// ステージ３
	if ((world_num == 6) && (stage_num == 3))
		data.World6.Stage3 = Clear_FLG;

	// 新規
	if (Del_FLG == false)
		data.Del = false;

	// 削除
	if (Del_FLG == true)
		data.Del = true;

	FILE *fp = fopen("セーブデータ.dat", "wb");//バイナリファイルを開く
	fwrite(&data, sizeof(data), 1, fp); // SAVE_DATA構造体の中身を入力
	fclose(fp);//ファイルを閉じる
}

char Save_Load::Load()
{
	FILE *fp;

	if ((fp = fopen("セーブデータ.dat", "rb")) == NULL)
	{
		cout << "セーブデータがないです" << endl;
	};

	//バイナリファイルを読み込む
	if (fp = fopen("セーブデータ.dat", "rb"))
	{
		fread(&data, sizeof(data), 1, fp); // SAVE_DATA構造体の中身を出力
		fclose(fp);//ファイルを閉じる

		// 削除フラグが建っていない
		if (data.Del == false)
		{
			Save_Load::Answer();
			Save_Load::WS_true();
		}

		// 削除フラグが建っている
		if (data.Del == true)
		{
			cout << "セーブデータの中身が削除されてます。" << endl;
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
	cout << "ワールド１" << endl;
	cout << "ステージ１：" << data.World1.Stage1 << endl;
	cout << "ステージ２：" << data.World1.Stage2 << endl;
	cout << "ステージ３：" << data.World1.Stage3 << endl;

	cout << "ワールド２" << endl;
	cout << "ステージ１：" << data.World2.Stage1 << endl;
	cout << "ステージ２：" << data.World2.Stage2 << endl;
	cout << "ステージ３：" << data.World2.Stage3 << endl;

	cout << "ワールド３" << endl;
	cout << "ステージ１：" << data.World3.Stage1 << endl;
	cout << "ステージ２：" << data.World3.Stage2 << endl;
	cout << "ステージ３：" << data.World3.Stage3 << endl;

	cout << "ワールド４" << endl;
	cout << "ステージ１：" << data.World4.Stage1 << endl;
	cout << "ステージ２：" << data.World4.Stage2 << endl;
	cout << "ステージ３：" << data.World4.Stage3 << endl;

	cout << "ワールド５" << endl;
	cout << "ステージ１：" << data.World5.Stage1 << endl;
	cout << "ステージ２：" << data.World5.Stage2 << endl;
	cout << "ステージ３：" << data.World5.Stage3 << endl;

	cout << "ワールド６" << endl;
	cout << "ステージ１：" << data.World6.Stage1 << endl;
	cout << "ステージ２：" << data.World6.Stage2 << endl;
	cout << "ステージ３：" << data.World6.Stage3 << endl;
}

void Save_Load::Initialize_Date(bool Del_FLG)
{
	// 削除フラグが建っていない
	if (Del_FLG == false)
	{
		cout << "新規セーブデータを作成します" << endl;
	}
	
	// 削除フラグが建っている
	if (Del_FLG == true)
	{
		cout << "セーブデータをリセットします" << endl;
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
	cout << "クリア場所を指定するか？" << endl;
	cout << "1：する　　0：しない" << endl;
	cin >> loop;

	while (loop)
	{
		cout << "クリアを指定したいワールドを選択" << endl;
		cin >> world_num;

		cout << "クリアを指定したいステージを選択" << endl;
		cin >> stage_num;

		Save_Load::Save(world_num, stage_num, true, false);
		Save_Load::Load();
	}
}