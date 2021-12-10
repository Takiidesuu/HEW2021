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
	Input* inputObj;		//�C���v�b�g�I�u�W�F�N�g

	CSprite **sprite;

	bool inputflg;

	int select = 0;
};
