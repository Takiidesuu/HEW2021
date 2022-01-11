#include "MapChipClass.h"

CMapChip::CMapChip(const char* texturePath, int horizontalPartNum, int verticalPartNum, float PosX, float PosY, float SizeX, float SizeY, float PixcelSizeX, float PixcelSizeY) :CGameObject(texturePath, horizontalPartNum, verticalPartNum, PosX, PosY, SizeX, SizeY, PixcelSizeX, PixcelSizeY)
{}

void CMapChip::mBroak()
{
	mPartX++;
	mBreakLevel++;

	if (mBreakLevel == 3) {
		mPartX = 0;
		mMapChipType = NONE_MAPCHIP;
	}
}

void CMapChip::SetPart(int partX, int partY)
{
	CSprite::SetPart(partX, partY);

	switch (partX)
	{
	case 0:
		mMapChipType = NONE_MAPCHIP;
		break;
	case 1:
		mMapChipType = FLOOR;
		break;
	case 2:
		mMapChipType = PIPE_FLOOR;
		break;
	case 3:
		mMapChipType = AN_BLOKEN_BLOCK;
		break;
	case 4:
		mMapChipType = BROKEN_BLOCK;

		mBreakLevel = 0;
		break;
	case 5:
		mMapChipType = BROKEN_BLOCK;
		mBreakLevel = 1;
		break;
	case 6:
		mMapChipType = BROKEN_BLOCK;
		mBreakLevel = 2;
		break;

	}
}
