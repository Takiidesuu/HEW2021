#include "Scene.h"

#define RESULT_SPRITE_NUM 5

enum ACT_SELECT {
	NONE,
	STAGE_SELECT,
	RETRY,
	NEXT
};

class CResult :public Scene
{
public:
	bool Init();
	bool Update();
	void Draw();

private:
	Input* inputObj;		//インプットオブジェクト

	CSprite **sprite;

	bool inputflg;

	int select = 0;
};
