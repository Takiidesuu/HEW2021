#include "SaveLoad.h"

using namespace std;

/*

クリア率を答える関数

*/
void Save_Load::Percent1()
{
	FILE *fp;

	if ((fp = fopen("セーブデータ1.dat", "rb")) == NULL)
	{
		cout << "セーブデータ１がないです" << endl;
		cout << endl;
	}

	//バイナリファイルを読み込む
	if (fp = fopen("セーブデータ1.dat", "rb"))
	{
		fread(&data1, sizeof(data1), 1, fp); // SAVE_DATA構造体の中身を出力
		fclose(fp);//ファイルを閉じる

		if (data1.Del == false)
		{
			// スター１
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

			// スター２
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

			// スター３
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

			cout << "セーブデータ１合計数： " << Clear1.Plus << " ／ 18" << endl;
			Clear1.Percent = Clear1.Plus * 0.05 * 100;

			if (Clear1.Plus >= 18)
				cout << "セーブデータ１クリア率： 100 %" << endl;
			else
				cout << "セーブデータ１クリア率： " << Clear1.Percent << " %" << endl;

			cout << endl;
		}

		if (data1.Del == true)
		{
			cout << "セーブデータ１は消されています" << endl;
			cout << endl;
		}
	}
}

void Save_Load::Percent2()
{
	FILE *fp;

	if ((fp = fopen("セーブデータ2.dat", "rb")) == NULL)
	{
		cout << "セーブデータ２がないです" << endl;
		cout << endl;
	}

	//バイナリファイルを読み込む
	if (fp = fopen("セーブデータ2.dat", "rb"))
	{
		fread(&data2, sizeof(data2), 1, fp); // SAVE_DATA構造体の中身を出力
		fclose(fp);//ファイルを閉じる

		if (data2.Del == false)
		{
			// スター１
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

			// スター２
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

			// スター３
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

			cout << "セーブデータ２合計数： " << Clear2.Plus << " ／ 18" << endl;
			Clear2.Percent = Clear2.Plus * 0.05 * 100;

			if (Clear2.Plus >= 18)
				cout << "セーブデータ２クリア率： 100 %" << endl;
			else
				cout << "セーブデータ２クリア率： " << Clear2.Percent << " %" << endl;

			cout << endl;
		}

		if (data2.Del == true)
		{
			cout << "セーブデータ２は消されています" << endl;
			cout << endl;
		}
	}
}

void Save_Load::Percent3()
{
	FILE *fp;

	if ((fp = fopen("セーブデータ3.dat", "rb")) == NULL)
	{
		cout << "セーブデータ３がないです" << endl;
	}

	//バイナリファイルを読み込む
	if (fp = fopen("セーブデータ3.dat", "rb"))
	{
		fread(&data3, sizeof(data3), 1, fp); // SAVE_DATA構造体の中身を出力
		fclose(fp);//ファイルを閉じる

		if (data3.Del == false)
		{
			// スター１
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

			// スター２
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

			// スター３
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

			cout << "セーブデータ３合計数： " << Clear3.Plus << " ／ 18" << endl;
			Clear3.Percent = Clear3.Plus * 0.05 * 100;

			if (Clear3.Plus >= 18)
				cout << "セーブデータ３クリア率： 100 %" << endl;
			else
				cout << "セーブデータ３クリア率： " << Clear3.Percent << " %" << endl;

			cout << endl;
		}

		if (data3.Del == true)
		{
			cout << "セーブデータ３は消されています" << endl;
			cout << endl;
		}
	}
}



/*

セーブする関数

*/
void Save_Load::Save1(int Star_FLG, int World_FLG, int Stage_FLG, bool Clear_FLG, bool Del_FLG)
{
	/*

	スター１

	*/
	/*	ワールド１	*/
	// ステージ１
	if ((Star_FLG == 1) && (World_FLG == 1) && (Stage_FLG == 1))
	{
		data1.Star1.World1.Stage1 = Clear_FLG;
		data1.Last = LAST_NUM::LAST_111;
	}

	// ステージ２
	if ((Star_FLG == 1) && (World_FLG == 1) && (Stage_FLG == 2))
	{
		data1.Star1.World1.Stage2 = Clear_FLG;
		data1.Last = LAST_NUM::LAST_112;
	}

	// ステージ３
	if ((Star_FLG == 1) && (World_FLG == 1) && (Stage_FLG == 3))
	{
		data1.Star1.World1.Stage3 = Clear_FLG;
		data1.Last = LAST_NUM::LAST_113;
	}

	/*	ワールド２	*/
	// ステージ１
	if ((Star_FLG == 1) && (World_FLG == 2) && (Stage_FLG == 1))
	{
		data1.Star1.World2.Stage1 = Clear_FLG;
		data1.Last = LAST_NUM::LAST_121;
	}

	// ステージ２
	if ((Star_FLG == 1) && (World_FLG == 2) && (Stage_FLG == 2))
	{
		data1.Star1.World2.Stage2 = Clear_FLG;
		data1.Last = LAST_NUM::LAST_122;
	}

	// ステージ３
	if ((Star_FLG == 1) && (World_FLG == 2) && (Stage_FLG == 3))
	{
		data1.Star1.World2.Stage3 = Clear_FLG;
		data1.Last = LAST_NUM::LAST_123;
	}



	/*

	スター２

	*/
	/*	ワールド１	*/
	// ステージ１
	if ((Star_FLG == 2) && (World_FLG == 1) && (Stage_FLG == 1))
	{
		data1.Star2.World1.Stage1 = Clear_FLG;
		data1.Last = LAST_NUM::LAST_211;
	}

	// ステージ２
	if ((Star_FLG == 2) && (World_FLG == 1) && (Stage_FLG == 2))
	{
		data1.Star2.World1.Stage2 = Clear_FLG;
		data1.Last = LAST_NUM::LAST_212;
	}

	// ステージ３
	if ((Star_FLG == 2) && (World_FLG == 1) && (Stage_FLG == 3))
	{
		data1.Star2.World1.Stage3 = Clear_FLG;
		data1.Last = LAST_NUM::LAST_213;
	}

	/*	ワールド２	*/
	// ステージ１
	if ((Star_FLG == 2) && (World_FLG == 2) && (Stage_FLG == 1))
	{
		data1.Star2.World2.Stage1 = Clear_FLG;
		data1.Last = LAST_NUM::LAST_221;
	}

	// ステージ２
	if ((Star_FLG == 2) && (World_FLG == 2) && (Stage_FLG == 2))
	{
		data1.Star2.World2.Stage2 = Clear_FLG;
		data1.Last = LAST_NUM::LAST_222;
	}

	// ステージ３
	if ((Star_FLG == 2) && (World_FLG == 2) && (Stage_FLG == 3))
	{
		data1.Star2.World2.Stage3 = Clear_FLG;
		data1.Last = LAST_NUM::LAST_223;
	}



	/*

	スター３

	*/
	/*	ワールド１	*/
	// ステージ１
	if ((Star_FLG == 3) && (World_FLG == 1) && (Stage_FLG == 1))
	{
		data1.Star3.World1.Stage1 = Clear_FLG;
		data1.Last = LAST_NUM::LAST_311;
	}

	// ステージ２
	if ((Star_FLG == 3) && (World_FLG == 1) && (Stage_FLG == 2))
	{
		data1.Star3.World1.Stage2 = Clear_FLG;
		data1.Last = LAST_NUM::LAST_312;
	}

	// ステージ３
	if ((Star_FLG == 3) && (World_FLG == 1) && (Stage_FLG == 3))
	{
		data1.Star3.World1.Stage3 = Clear_FLG;
		data1.Last = LAST_NUM::LAST_313;
	}

	/*	ワールド２	*/
	// ステージ１
	if ((Star_FLG == 3) && (World_FLG == 2) && (Stage_FLG == 1))
	{
		data1.Star3.World2.Stage1 = Clear_FLG;
		data1.Last = LAST_NUM::LAST_321;
	}

	// ステージ２
	if ((Star_FLG == 3) && (World_FLG == 2) && (Stage_FLG == 2))
	{
		data1.Star3.World2.Stage2 = Clear_FLG;
		data1.Last = LAST_NUM::LAST_322;
	}

	// ステージ３
	if ((Star_FLG == 3) && (World_FLG == 2) && (Stage_FLG == 3))
	{
		data1.Star3.World2.Stage3 = Clear_FLG;
		data1.Last = LAST_NUM::LAST_323;
	}



	// 新規
	if (Del_FLG == false)
		data1.Del = false;

	// 削除
	if (Del_FLG == true)
		data1.Del = true;



	FILE *fp = fopen("セーブデータ1.dat", "wb");//バイナリファイルを開く
	fwrite(&data1, sizeof(data1), 1, fp); // SAVE_DATA構造体の中身を入力
	fclose(fp);//ファイルを閉じる
}

void Save_Load::Save2(int Star_FLG, int World_FLG, int Stage_FLG, bool Clear_FLG, bool Del_FLG)
{
	/*

	スター１

	*/
	/*	ワールド１	*/
	// ステージ１
	if ((Star_FLG == 1) && (World_FLG == 1) && (Stage_FLG == 1))
	{
		data2.Star1.World1.Stage1 = Clear_FLG;
		data2.Last = LAST_NUM::LAST_111;
	}

	// ステージ２
	if ((Star_FLG == 1) && (World_FLG == 1) && (Stage_FLG == 2))
	{
		data2.Star1.World1.Stage2 = Clear_FLG;
		data2.Last = LAST_NUM::LAST_112;
	}

	// ステージ３
	if ((Star_FLG == 1) && (World_FLG == 1) && (Stage_FLG == 3))
	{
		data2.Star1.World1.Stage3 = Clear_FLG;
		data2.Last = LAST_NUM::LAST_113;
	}

	/*	ワールド２	*/
	// ステージ１
	if ((Star_FLG == 1) && (World_FLG == 2) && (Stage_FLG == 1))
	{
		data2.Star1.World2.Stage1 = Clear_FLG;
		data2.Last = LAST_NUM::LAST_121;
	}

	// ステージ２
	if ((Star_FLG == 1) && (World_FLG == 2) && (Stage_FLG == 2))
	{
		data2.Star1.World2.Stage2 = Clear_FLG;
		data2.Last = LAST_NUM::LAST_122;
	}

	// ステージ３
	if ((Star_FLG == 1) && (World_FLG == 2) && (Stage_FLG == 3))
	{
		data2.Star1.World2.Stage3 = Clear_FLG;
		data2.Last = LAST_NUM::LAST_123;
	}



	/*

	スター２

	*/
	/*	ワールド１	*/
	// ステージ１
	if ((Star_FLG == 2) && (World_FLG == 1) && (Stage_FLG == 1))
	{
		data2.Star2.World1.Stage1 = Clear_FLG;
		data2.Last = LAST_NUM::LAST_211;
	}

	// ステージ２
	if ((Star_FLG == 2) && (World_FLG == 1) && (Stage_FLG == 2))
	{
		data2.Star2.World1.Stage2 = Clear_FLG;
		data2.Last = LAST_NUM::LAST_212;
	}

	// ステージ３
	if ((Star_FLG == 2) && (World_FLG == 1) && (Stage_FLG == 3))
	{
		data2.Star2.World1.Stage3 = Clear_FLG;
		data2.Last = LAST_NUM::LAST_213;
	}

	/*	ワールド２	*/
	// ステージ１
	if ((Star_FLG == 2) && (World_FLG == 2) && (Stage_FLG == 1))
	{
		data2.Star2.World2.Stage1 = Clear_FLG;
		data2.Last = LAST_NUM::LAST_221;
	}

	// ステージ２
	if ((Star_FLG == 2) && (World_FLG == 2) && (Stage_FLG == 2))
	{
		data2.Star2.World2.Stage2 = Clear_FLG;
		data2.Last = LAST_NUM::LAST_222;
	}

	// ステージ３
	if ((Star_FLG == 2) && (World_FLG == 2) && (Stage_FLG == 3))
	{
		data2.Star2.World2.Stage3 = Clear_FLG;
		data2.Last = LAST_NUM::LAST_223;
	}



	/*

	スター３

	*/
	/*	ワールド１	*/
	// ステージ１
	if ((Star_FLG == 3) && (World_FLG == 1) && (Stage_FLG == 1))
	{
		data2.Star3.World1.Stage1 = Clear_FLG;
		data2.Last = LAST_NUM::LAST_311;
	}

	// ステージ２
	if ((Star_FLG == 3) && (World_FLG == 1) && (Stage_FLG == 2))
	{
		data2.Star3.World1.Stage2 = Clear_FLG;
		data2.Last = LAST_NUM::LAST_312;
	}

	// ステージ３
	if ((Star_FLG == 3) && (World_FLG == 1) && (Stage_FLG == 3))
	{
		data2.Star3.World1.Stage3 = Clear_FLG;
		data2.Last = LAST_NUM::LAST_313;
	}

	/*	ワールド２	*/
	// ステージ１
	if ((Star_FLG == 3) && (World_FLG == 2) && (Stage_FLG == 1))
	{
		data2.Star3.World2.Stage1 = Clear_FLG;
		data2.Last = LAST_NUM::LAST_321;
	}

	// ステージ２
	if ((Star_FLG == 3) && (World_FLG == 2) && (Stage_FLG == 2))
	{
		data2.Star3.World2.Stage2 = Clear_FLG;
		data2.Last = LAST_NUM::LAST_322;
	}

	// ステージ３
	if ((Star_FLG == 3) && (World_FLG == 2) && (Stage_FLG == 3))
	{
		data2.Star3.World2.Stage3 = Clear_FLG;
		data2.Last = LAST_NUM::LAST_323;
	}



	// 新規
	if (Del_FLG == false)
		data2.Del = false;

	// 削除
	if (Del_FLG == true)
		data2.Del = true;



	FILE *fp = fopen("セーブデータ2.dat", "wb");//バイナリファイルを開く
	fwrite(&data2, sizeof(data2), 1, fp); // SAVE_DATA構造体の中身を入力
	fclose(fp);//ファイルを閉じる
}

void Save_Load::Save3(int Star_FLG, int World_FLG, int Stage_FLG, bool Clear_FLG, bool Del_FLG)
{
	/*

	スター１

	*/
	/*	ワールド１	*/
	// ステージ１
	if ((Star_FLG == 1) && (World_FLG == 1) && (Stage_FLG == 1))
	{
		data3.Star1.World1.Stage1 = Clear_FLG;
		data3.Last = LAST_NUM::LAST_111;
	}

	// ステージ２
	if ((Star_FLG == 1) && (World_FLG == 1) && (Stage_FLG == 2))
	{
		data3.Star1.World1.Stage2 = Clear_FLG;
		data3.Last = LAST_NUM::LAST_112;
	}

	// ステージ３
	if ((Star_FLG == 1) && (World_FLG == 1) && (Stage_FLG == 3))
	{
		data3.Star1.World1.Stage3 = Clear_FLG;
		data3.Last = LAST_NUM::LAST_113;
	}

	/*	ワールド２	*/
	// ステージ１
	if ((Star_FLG == 1) && (World_FLG == 2) && (Stage_FLG == 1))
	{
		data3.Star1.World2.Stage1 = Clear_FLG;
		data3.Last = LAST_NUM::LAST_121;
	}

	// ステージ２
	if ((Star_FLG == 1) && (World_FLG == 2) && (Stage_FLG == 2))
	{
		data3.Star1.World2.Stage2 = Clear_FLG;
		data3.Last = LAST_NUM::LAST_122;
	}

	// ステージ３
	if ((Star_FLG == 1) && (World_FLG == 2) && (Stage_FLG == 3))
	{
		data3.Star1.World2.Stage3 = Clear_FLG;
		data3.Last = LAST_NUM::LAST_123;
	}



	/*

	スター２

	*/
	/*	ワールド１	*/
	// ステージ１
	if ((Star_FLG == 2) && (World_FLG == 1) && (Stage_FLG == 1))
	{
		data3.Star2.World1.Stage1 = Clear_FLG;
		data3.Last = LAST_NUM::LAST_211;
	}

	// ステージ２
	if ((Star_FLG == 2) && (World_FLG == 1) && (Stage_FLG == 2))
	{
		data3.Star2.World1.Stage2 = Clear_FLG;
		data3.Last = LAST_NUM::LAST_212;
	}

	// ステージ３
	if ((Star_FLG == 2) && (World_FLG == 1) && (Stage_FLG == 3))
	{
		data3.Star2.World1.Stage3 = Clear_FLG;
		data3.Last = LAST_NUM::LAST_213;
	}

	/*	ワールド２	*/
	// ステージ１
	if ((Star_FLG == 2) && (World_FLG == 2) && (Stage_FLG == 1))
	{
		data3.Star2.World2.Stage1 = Clear_FLG;
		data3.Last = LAST_NUM::LAST_221;
	}

	// ステージ２
	if ((Star_FLG == 2) && (World_FLG == 2) && (Stage_FLG == 2))
	{
		data3.Star2.World2.Stage2 = Clear_FLG;
		data3.Last = LAST_NUM::LAST_222;
	}

	// ステージ３
	if ((Star_FLG == 2) && (World_FLG == 2) && (Stage_FLG == 3))
	{
		data3.Star2.World2.Stage3 = Clear_FLG;
		data3.Last = LAST_NUM::LAST_223;
	}



	/*

	スター３

	*/
	/*	ワールド１	*/
	// ステージ１
	if ((Star_FLG == 3) && (World_FLG == 1) && (Stage_FLG == 1))
	{
		data3.Star3.World1.Stage1 = Clear_FLG;
		data3.Last = LAST_NUM::LAST_311;
	}

	// ステージ２
	if ((Star_FLG == 3) && (World_FLG == 1) && (Stage_FLG == 2))
	{
		data3.Star3.World1.Stage2 = Clear_FLG;
		data3.Last = LAST_NUM::LAST_312;
	}

	// ステージ３
	if ((Star_FLG == 3) && (World_FLG == 1) && (Stage_FLG == 3))
	{
		data3.Star3.World1.Stage3 = Clear_FLG;
		data3.Last = LAST_NUM::LAST_313;
	}

	/*	ワールド２	*/
	// ステージ１
	if ((Star_FLG == 3) && (World_FLG == 2) && (Stage_FLG == 1))
	{
		data3.Star3.World2.Stage1 = Clear_FLG;
		data3.Last = LAST_NUM::LAST_321;
	}

	// ステージ２
	if ((Star_FLG == 3) && (World_FLG == 2) && (Stage_FLG == 2))
	{
		data3.Star3.World2.Stage2 = Clear_FLG;
		data3.Last = LAST_NUM::LAST_322;
	}

	// ステージ３
	if ((Star_FLG == 3) && (World_FLG == 2) && (Stage_FLG == 3))
	{
		data3.Star3.World2.Stage3 = Clear_FLG;
		data3.Last = LAST_NUM::LAST_323;
	}



	// 新規
	if (Del_FLG == false)
		data3.Del = false;

	// 削除
	if (Del_FLG == true)
		data3.Del = true;



	FILE *fp = fopen("セーブデータ3.dat", "wb");//バイナリファイルを開く
	fwrite(&data3, sizeof(data3), 1, fp); // SAVE_DATA構造体の中身を入力
	fclose(fp);//ファイルを閉じる
}



/*

ロードする関数

*/
char Save_Load::Load1()
{
	FILE *fp;

	if ((fp = fopen("セーブデータ1.dat", "rb")) == NULL)
	{
		cout << "セーブデータがないです" << endl;
	};

	//バイナリファイルを読み込む
	if (fp = fopen("セーブデータ1.dat", "rb"))
	{
		fread(&data1, sizeof(data1), 1, fp); // SAVE_DATA構造体の中身を出力
		fclose(fp);//ファイルを閉じる

		// 削除フラグが建っていない
		if (data1.Del == false)
		{
			Save_Load::Answer1();
			Save_Load::SWS_true1();
		}

		// 削除フラグが建っている
		if (data1.Del == true)
		{
			cout << "セーブデータの中身が削除されてます。" << endl;
			system("pause");
		}

	};

	return
		// スター１
		data1.Star1.World1.Stage1, data1.Star1.World1.Stage2, data1.Star1.World1.Stage3,
		data1.Star1.World2.Stage1, data1.Star1.World2.Stage2, data1.Star1.World2.Stage3,

		// スター２
		data1.Star2.World1.Stage1, data1.Star2.World1.Stage2, data1.Star2.World1.Stage3,
		data1.Star2.World2.Stage1, data1.Star2.World2.Stage2, data1.Star2.World2.Stage3,

		// スター３
		data1.Star3.World1.Stage1, data1.Star3.World1.Stage2, data1.Star3.World1.Stage3,
		data1.Star3.World2.Stage1, data1.Star3.World2.Stage2, data1.Star3.World2.Stage3,

		// 削除判定
		data1.Del;
}

char Save_Load::Load2()
{
	FILE *fp;

	if ((fp = fopen("セーブデータ2.dat", "rb")) == NULL)
	{
		cout << "セーブデータがないです" << endl;
	};

	//バイナリファイルを読み込む
	if (fp = fopen("セーブデータ2.dat", "rb"))
	{
		fread(&data2, sizeof(data2), 1, fp); // SAVE_DATA構造体の中身を出力
		fclose(fp);//ファイルを閉じる

		// 削除フラグが建っていない
		if (data2.Del == false)
		{
			Save_Load::Answer2();
			Save_Load::SWS_true2();
		}

		// 削除フラグが建っている
		if (data2.Del == true)
		{
			cout << "セーブデータの中身が削除されてます。" << endl;
			system("pause");
		}

	};

	return
		// スター１
		data2.Star1.World1.Stage1, data2.Star1.World1.Stage2, data2.Star1.World1.Stage3,
		data2.Star1.World2.Stage1, data2.Star1.World2.Stage2, data2.Star1.World2.Stage3,

		// スター２
		data2.Star2.World1.Stage1, data2.Star2.World1.Stage2, data2.Star2.World1.Stage3,
		data2.Star2.World2.Stage1, data2.Star2.World2.Stage2, data2.Star2.World2.Stage3,

		// スター３
		data2.Star3.World1.Stage1, data2.Star3.World1.Stage2, data2.Star3.World1.Stage3,
		data2.Star3.World2.Stage1, data2.Star3.World2.Stage2, data2.Star3.World2.Stage3,

		// 削除判定
		data2.Del;
}

char Save_Load::Load3()
{
	FILE *fp;

	if ((fp = fopen("セーブデータ3.dat", "rb")) == NULL)
	{
		cout << "セーブデータがないです" << endl;
	};

	//バイナリファイルを読み込む
	if (fp = fopen("セーブデータ3.dat", "rb"))
	{
		fread(&data3, sizeof(data3), 1, fp); // SAVE_DATA構造体の中身を出力
		fclose(fp);//ファイルを閉じる

		// 削除フラグが建っていない
		if (data3.Del == false)
		{
			Save_Load::Answer3();
			Save_Load::SWS_true3();
		}

		// 削除フラグが建っている
		if (data3.Del == true)
		{
			cout << "セーブデータの中身が削除されてます。" << endl;
			system("pause");
		}

	};

	return
		// スター１
		data3.Star1.World1.Stage1, data3.Star1.World1.Stage2, data3.Star1.World1.Stage3,
		data3.Star1.World2.Stage1, data3.Star1.World2.Stage2, data3.Star1.World2.Stage3,

		// スター２
		data3.Star2.World1.Stage1, data3.Star2.World1.Stage2, data3.Star2.World1.Stage3,
		data3.Star2.World2.Stage1, data3.Star2.World2.Stage2, data3.Star2.World2.Stage3,

		// スター３
		data3.Star3.World1.Stage1, data3.Star3.World1.Stage2, data3.Star3.World1.Stage3,
		data3.Star3.World2.Stage1, data3.Star3.World2.Stage2, data3.Star3.World2.Stage3,

		// 削除判定
		data3.Del;
}



/*

最後にプレイしたワールド＆ステージを答える関数

*/
void Save_Load::Last1()
{
	cout << "最後にプレイしたワールド＆ステージ" << endl;

	/*

	スター１

	*/
	/*	ワールド１	*/
	// ステージ１
	if (data1.Last == LAST_NUM::LAST_111)
		cout << "スター１　ワールド１　ステージ１" << endl << endl;
	// ステージ２
	if (data1.Last == LAST_NUM::LAST_112)
		cout << "スター１　ワールド１　ステージ２" << endl << endl;
	// ステージ３
	if (data1.Last == LAST_NUM::LAST_113)
		cout << "スター１　ワールド１　ステージ３" << endl << endl;

	/*	ワールド２	*/
	// ステージ１
	if (data1.Last == LAST_NUM::LAST_121)
		cout << "スター１　ワールド２　ステージ１" << endl << endl;
	// ステージ２
	if (data1.Last == LAST_NUM::LAST_122)
		cout << "スター１　ワールド２　ステージ２" << endl << endl;
	// ステージ３
	if (data1.Last == LAST_NUM::LAST_123)
		cout << "スター１　ワールド２　ステージ３" << endl << endl;



	/*

	スター２

	*/
	/*	ワールド１	*/
	// ステージ１
	if (data1.Last == LAST_NUM::LAST_211)
		cout << "スター２　ワールド１　ステージ１" << endl << endl;
	// ステージ２
	if (data1.Last == LAST_NUM::LAST_212)
		cout << "スター２　ワールド１　ステージ２" << endl << endl;
	// ステージ３
	if (data1.Last == LAST_NUM::LAST_213)
		cout << "スター２　ワールド１　ステージ３" << endl << endl;

	/*	ワールド２	*/
	// ステージ１
	if (data1.Last == LAST_NUM::LAST_221)
		cout << "スター２　ワールド２　ステージ１" << endl << endl;
	// ステージ２
	if (data1.Last == LAST_NUM::LAST_222)
		cout << "スター２　ワールド２　ステージ２" << endl << endl;
	// ステージ３
	if (data1.Last == LAST_NUM::LAST_223)
		cout << "スター２　ワールド２　ステージ３" << endl << endl;



	/*

	スター３

	*/
	/*	ワールド１	*/
	// ステージ１
	if (data1.Last == LAST_NUM::LAST_311)
		cout << "スター３　ワールド１　ステージ１" << endl << endl;
	// ステージ２
	if (data1.Last == LAST_NUM::LAST_312)
		cout << "スター３　ワールド１　ステージ２" << endl << endl;
	// ステージ３
	if (data1.Last == LAST_NUM::LAST_313)
		cout << "スター３　ワールド１　ステージ３" << endl << endl;

	/*	ワールド２	*/
	// ステージ１
	if (data1.Last == LAST_NUM::LAST_321)
		cout << "スター３　ワールド２　ステージ１" << endl << endl;
	// ステージ２
	if (data1.Last == LAST_NUM::LAST_322)
		cout << "スター３　ワールド２　ステージ２" << endl << endl;
	// ステージ３
	if (data1.Last == LAST_NUM::LAST_323)
		cout << "スター３　ワールド２　ステージ３" << endl << endl;
}

void Save_Load::Last2()
{
	cout << "最後にプレイしたワールド＆ステージ" << endl;

	/*

	スター１

	*/
	/*	ワールド１	*/
	// ステージ１
	if (data2.Last == LAST_NUM::LAST_111)
		cout << "スター１　ワールド１　ステージ１" << endl << endl;
	// ステージ２
	if (data2.Last == LAST_NUM::LAST_112)
		cout << "スター１　ワールド１　ステージ２" << endl << endl;
	// ステージ３
	if (data2.Last == LAST_NUM::LAST_113)
		cout << "スター１　ワールド１　ステージ３" << endl << endl;

	/*	ワールド２	*/
	// ステージ１
	if (data2.Last == LAST_NUM::LAST_121)
		cout << "スター１　ワールド２　ステージ１" << endl << endl;
	// ステージ２
	if (data2.Last == LAST_NUM::LAST_122)
		cout << "スター１　ワールド２　ステージ２" << endl << endl;
	// ステージ３
	if (data2.Last == LAST_NUM::LAST_123)
		cout << "スター１　ワールド２　ステージ３" << endl << endl;



	/*

	スター２

	*/
	/*	ワールド１	*/
	// ステージ１
	if (data2.Last == LAST_NUM::LAST_211)
		cout << "スター２　ワールド１　ステージ１" << endl << endl;
	// ステージ２
	if (data2.Last == LAST_NUM::LAST_212)
		cout << "スター２　ワールド１　ステージ２" << endl << endl;
	// ステージ３
	if (data2.Last == LAST_NUM::LAST_213)
		cout << "スター２　ワールド１　ステージ３" << endl << endl;

	/*	ワールド２	*/
	// ステージ１
	if (data2.Last == LAST_NUM::LAST_221)
		cout << "スター２　ワールド２　ステージ１" << endl << endl;
	// ステージ２
	if (data2.Last == LAST_NUM::LAST_222)
		cout << "スター２　ワールド２　ステージ２" << endl << endl;
	// ステージ３
	if (data2.Last == LAST_NUM::LAST_223)
		cout << "スター２　ワールド２　ステージ３" << endl << endl;



	/*

	スター３

	*/
	/*	ワールド１	*/
	// ステージ１
	if (data2.Last == LAST_NUM::LAST_311)
		cout << "スター３　ワールド１　ステージ１" << endl << endl;
	// ステージ２
	if (data2.Last == LAST_NUM::LAST_312)
		cout << "スター３　ワールド１　ステージ２" << endl << endl;
	// ステージ３
	if (data2.Last == LAST_NUM::LAST_313)
		cout << "スター３　ワールド１　ステージ３" << endl << endl;

	/*	ワールド２	*/
	// ステージ１
	if (data2.Last == LAST_NUM::LAST_321)
		cout << "スター３　ワールド２　ステージ１" << endl << endl;
	// ステージ２
	if (data2.Last == LAST_NUM::LAST_322)
		cout << "スター３　ワールド２　ステージ２" << endl << endl;
	// ステージ３
	if (data2.Last == LAST_NUM::LAST_323)
		cout << "スター３　ワールド２　ステージ３" << endl << endl;
}

void Save_Load::Last3()
{
	cout << "最後にプレイしたワールド＆ステージ" << endl;

	/*

	スター１

	*/
	/*	ワールド１	*/
	// ステージ１
	if (data3.Last == LAST_NUM::LAST_111)
		cout << "スター１　ワールド１　ステージ１" << endl << endl;
	// ステージ２
	if (data3.Last == LAST_NUM::LAST_112)
		cout << "スター１　ワールド１　ステージ２" << endl << endl;
	// ステージ３
	if (data3.Last == LAST_NUM::LAST_113)
		cout << "スター１　ワールド１　ステージ３" << endl << endl;

	/*	ワールド２	*/
	// ステージ１
	if (data3.Last == LAST_NUM::LAST_121)
		cout << "スター１　ワールド２　ステージ１" << endl << endl;
	// ステージ２
	if (data3.Last == LAST_NUM::LAST_122)
		cout << "スター１　ワールド２　ステージ２" << endl << endl;
	// ステージ３
	if (data3.Last == LAST_NUM::LAST_123)
		cout << "スター１　ワールド２　ステージ３" << endl << endl;



	/*

	スター２

	*/
	/*	ワールド１	*/
	// ステージ１
	if (data3.Last == LAST_NUM::LAST_211)
		cout << "スター２　ワールド１　ステージ１" << endl << endl;
	// ステージ２
	if (data3.Last == LAST_NUM::LAST_212)
		cout << "スター２　ワールド１　ステージ２" << endl << endl;
	// ステージ３
	if (data3.Last == LAST_NUM::LAST_213)
		cout << "スター２　ワールド１　ステージ３" << endl << endl;

	/*	ワールド２	*/
	// ステージ１
	if (data3.Last == LAST_NUM::LAST_221)
		cout << "スター２　ワールド２　ステージ１" << endl << endl;
	// ステージ２
	if (data3.Last == LAST_NUM::LAST_222)
		cout << "スター２　ワールド２　ステージ２" << endl << endl;
	// ステージ３
	if (data3.Last == LAST_NUM::LAST_223)
		cout << "スター２　ワールド２　ステージ３" << endl << endl;



	/*

	スター３

	*/
	/*	ワールド１	*/
	// ステージ１
	if (data3.Last == LAST_NUM::LAST_311)
		cout << "スター３　ワールド１　ステージ１" << endl << endl;
	// ステージ２
	if (data3.Last == LAST_NUM::LAST_312)
		cout << "スター３　ワールド１　ステージ２" << endl << endl;
	// ステージ３
	if (data3.Last == LAST_NUM::LAST_313)
		cout << "スター３　ワールド１　ステージ３" << endl << endl;

	/*	ワールド２	*/
	// ステージ１
	if (data3.Last == LAST_NUM::LAST_321)
		cout << "スター３　ワールド２　ステージ１" << endl << endl;
	// ステージ２
	if (data3.Last == LAST_NUM::LAST_322)
		cout << "スター３　ワールド２　ステージ２" << endl << endl;
	// ステージ３
	if (data3.Last == LAST_NUM::LAST_323)
		cout << "スター３　ワールド２　ステージ３" << endl << endl;
}



/*

クリア判定を答える関数

*/
void Save_Load::Answer1()
{
	cout << "スター１" << endl;
	cout << "ワールド１" << endl;
	cout << "ステージ１：" << data1.Star1.World1.Stage1 << endl;
	cout << "ステージ２：" << data1.Star1.World1.Stage2 << endl;
	cout << "ステージ３：" << data1.Star1.World1.Stage3 << endl;
	cout << "ワールド２" << endl;
	cout << "ステージ１：" << data1.Star1.World2.Stage1 << endl;
	cout << "ステージ２：" << data1.Star1.World2.Stage2 << endl;
	cout << "ステージ３：" << data1.Star1.World2.Stage3 << endl;
	cout << endl;

	cout << "スター２" << endl;
	cout << "ワールド１" << endl;
	cout << "ステージ１：" << data1.Star2.World1.Stage1 << endl;
	cout << "ステージ２：" << data1.Star2.World1.Stage2 << endl;
	cout << "ステージ３：" << data1.Star2.World1.Stage3 << endl;
	cout << "ワールド２" << endl;
	cout << "ステージ１：" << data1.Star2.World2.Stage1 << endl;
	cout << "ステージ２：" << data1.Star2.World2.Stage2 << endl;
	cout << "ステージ３：" << data1.Star2.World2.Stage3 << endl;
	cout << endl;

	cout << "スター３" << endl;
	cout << "ワールド１" << endl;
	cout << "ステージ１：" << data1.Star3.World1.Stage1 << endl;
	cout << "ステージ２：" << data1.Star3.World1.Stage2 << endl;
	cout << "ステージ３：" << data1.Star3.World1.Stage3 << endl;
	cout << "ワールド２" << endl;
	cout << "ステージ１：" << data1.Star3.World2.Stage1 << endl;
	cout << "ステージ２：" << data1.Star3.World2.Stage2 << endl;
	cout << "ステージ３：" << data1.Star3.World2.Stage3 << endl;
	cout << endl;
}

void Save_Load::Answer2()
{
	cout << "スター１" << endl;
	cout << "ワールド１" << endl;
	cout << "ステージ１：" << data2.Star1.World1.Stage1 << endl;
	cout << "ステージ２：" << data2.Star1.World1.Stage2 << endl;
	cout << "ステージ３：" << data2.Star1.World1.Stage3 << endl;
	cout << "ワールド２" << endl;
	cout << "ステージ１：" << data2.Star1.World2.Stage1 << endl;
	cout << "ステージ２：" << data2.Star1.World2.Stage2 << endl;
	cout << "ステージ３：" << data2.Star1.World2.Stage3 << endl;
	cout << endl;

	cout << "スター２" << endl;
	cout << "ワールド１" << endl;
	cout << "ステージ１：" << data2.Star2.World1.Stage1 << endl;
	cout << "ステージ２：" << data2.Star2.World1.Stage2 << endl;
	cout << "ステージ３：" << data2.Star2.World1.Stage3 << endl;
	cout << "ワールド２" << endl;
	cout << "ステージ１：" << data2.Star2.World2.Stage1 << endl;
	cout << "ステージ２：" << data2.Star2.World2.Stage2 << endl;
	cout << "ステージ３：" << data2.Star2.World2.Stage3 << endl;
	cout << endl;

	cout << "スター３" << endl;
	cout << "ワールド１" << endl;
	cout << "ステージ１：" << data2.Star3.World1.Stage1 << endl;
	cout << "ステージ２：" << data2.Star3.World1.Stage2 << endl;
	cout << "ステージ３：" << data2.Star3.World1.Stage3 << endl;
	cout << "ワールド２" << endl;
	cout << "ステージ１：" << data2.Star3.World2.Stage1 << endl;
	cout << "ステージ２：" << data2.Star3.World2.Stage2 << endl;
	cout << "ステージ３：" << data2.Star3.World2.Stage3 << endl;
	cout << endl;
}

void Save_Load::Answer3()
{
	cout << "スター１" << endl;
	cout << "ワールド１" << endl;
	cout << "ステージ１：" << data3.Star1.World1.Stage1 << endl;
	cout << "ステージ２：" << data3.Star1.World1.Stage2 << endl;
	cout << "ステージ３：" << data3.Star1.World1.Stage3 << endl;
	cout << "ワールド２" << endl;
	cout << "ステージ１：" << data3.Star1.World2.Stage1 << endl;
	cout << "ステージ２：" << data3.Star1.World2.Stage2 << endl;
	cout << "ステージ３：" << data3.Star1.World2.Stage3 << endl;
	cout << endl;

	cout << "スター２" << endl;
	cout << "ワールド１" << endl;
	cout << "ステージ１：" << data3.Star2.World1.Stage1 << endl;
	cout << "ステージ２：" << data3.Star2.World1.Stage2 << endl;
	cout << "ステージ３：" << data3.Star2.World1.Stage3 << endl;
	cout << "ワールド２" << endl;
	cout << "ステージ１：" << data3.Star2.World2.Stage1 << endl;
	cout << "ステージ２：" << data3.Star2.World2.Stage2 << endl;
	cout << "ステージ３：" << data3.Star2.World2.Stage3 << endl;
	cout << endl;

	cout << "スター３" << endl;
	cout << "ワールド１" << endl;
	cout << "ステージ１：" << data3.Star3.World1.Stage1 << endl;
	cout << "ステージ２：" << data3.Star3.World1.Stage2 << endl;
	cout << "ステージ３：" << data3.Star3.World1.Stage3 << endl;
	cout << "ワールド２" << endl;
	cout << "ステージ１：" << data3.Star3.World2.Stage1 << endl;
	cout << "ステージ２：" << data3.Star3.World2.Stage2 << endl;
	cout << "ステージ３：" << data3.Star3.World2.Stage3 << endl;
	cout << endl;
}



/*

データを初期化する関数

*/
void Save_Load::Initialize_Data1(bool Del_FLG)
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

スター・ワールド・ステージを真する関数

*/
void Save_Load::SWS_true1()
{
	cout << "クリア場所を指定するか？" << endl;
	cout << "1：する　　0：しない" << endl;
	cin >> loop;

	while (loop)
	{
		cout << "クリアを指定したいスターを選択" << endl;
		cin >> star_num;

		cout << "クリアを指定したいワールドを選択" << endl;
		cin >> world_num;

		cout << "クリアを指定したいステージを選択" << endl;
		cin >> stage_num;

		system("cls");
		Save_Load::Save1(star_num, world_num, stage_num, true, false);
		Save_Load::Last1();
		Save_Load::Load1();
	}
}

void Save_Load::SWS_true2()
{
	cout << "クリア場所を指定するか？" << endl;
	cout << "1：する　　0：しない" << endl;
	cin >> loop;

	while (loop)
	{
		cout << "クリアを指定したいスターを選択" << endl;
		cin >> star_num;

		cout << "クリアを指定したいワールドを選択" << endl;
		cin >> world_num;

		cout << "クリアを指定したいステージを選択" << endl;
		cin >> stage_num;

		system("cls");
		Save_Load::Save2(star_num, world_num, stage_num, true, false);
		Save_Load::Last2();
		Save_Load::Load2();
	}
}

void Save_Load::SWS_true3()
{
	cout << "クリア場所を指定するか？" << endl;
	cout << "1：する　　0：しない" << endl;
	cin >> loop;

	while (loop)
	{
		cout << "クリアを指定したいスターを選択" << endl;
		cin >> star_num;

		cout << "クリアを指定したいワールドを選択" << endl;
		cin >> world_num;

		cout << "クリアを指定したいステージを選択" << endl;
		cin >> stage_num;

		system("cls");
		Save_Load::Save3(star_num, world_num, stage_num, true, false);
		Save_Load::Last3();
		Save_Load::Load3();
	}
}