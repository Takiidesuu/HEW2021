#pragma once

#include <stdio.h>

typedef struct {
	int stage_id;
}SAVE_DATA;

class SaveLoad
{
public:
	void Save(int completedStage);
	int Load();
private:
	SAVE_DATA data;
};