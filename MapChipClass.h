#pragma once
#include "GameObject.h"

enum MAP_CHIP_TYPE {
	NONE_MAPCHIP,
	FLOOR,
	PIPE_FLOOR,
	AN_BLOKEN_BLOCK,
	BROKEN_BLOCK,
};

class CMapChip :public CGameObject
{
public:
	CMapChip(const char* texturePath, int horizontalPartNum, int verticalPartNum, float PosX, float PosY, float SizeX, float SizeY, float PixcelSizeX, float PixcelSizeY);

	void mBroak();

	void SetPart(int, int);

	MAP_CHIP_TYPE mMapChipType;
protected:
	int mBreakLevel = 0;
};