#pragma once

enum MAPCHIP_TYPE {
	P = 10,			//ÉvÉåÉCÉÑÅ[
	M,				//MOE
	A,				//ìGA
	B,				//ìGB
	C,				//ìGC
	D,				//ìGD
	T,				//Ç¬ÇÁÇÁ
	G,				//Ç™ÇÍÇ´
};

#define RESOLUTIONX 1920
#define RESOLUTIONY 1080

#define MAPCHIP_SIZE_HEIGHT (60)
#define MAPCHIP_SIZE_WIDTH (60)

#define MAPCHIP_NUM_HEIGHT 18
#define MAPCHIP_NUM_WIDTH  32

#define MAPCHIP_SIZE 0.1111f

#define STARNUM 3
#define WORLDNUM 2
#define STAGENUM 3

extern int MapChipDate[STARNUM][WORLDNUM][STAGENUM][MAPCHIP_NUM_HEIGHT][MAPCHIP_NUM_WIDTH];