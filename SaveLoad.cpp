#include "SaveLoad.h"

void SaveLoad::Save(int completedStage)
{
	data.stage_id = completedStage;

	FILE *fp = fopen("�Z�[�u�f�[�^.dat", "wb");
	fwrite(&data, sizeof(data), 1, fp);
	fclose(fp);
}

int SaveLoad::Load()
{
	FILE *fp = fopen("�Z�[�u�f�[�^.dat", "rb");
	fread(&data, sizeof(data), 1, fp);
	fclose(fp);

	return data.stage_id;
}