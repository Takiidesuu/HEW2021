#include "Scene.h"

#define RESULT_SPRITE_NUM 7

enum ACT_SELECT {
	NONE,
	STAGE_SELECT,
	RETRY,
	NEXT
};

enum ResultSceane {
	TIME,
	ACHIEVE
};

class CResult :public Scene
{
public:
	bool Init();
	bool Update();
	void Draw();

private:
	Input* mInputObj;		//�C���v�b�g�I�u�W�F�N�g

	CSprite **mSprite;

	ResultSceane mResultScene = TIME;

	bool mInputflg;

	int mSelect = 0;
};