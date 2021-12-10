#pragma once
#include "Sprite.h"

enum EfectPanelStatus {
	None,
	InFadein,
	FadeinCompleted,
	InFadeout,
	FadeoutCompleted,
	InFlash,
	FlashCompleted,

};

class CEfectPanel :
	public CSprite
{
public:
	CEfectPanel();

	void Update();

	void FadeIn();
	void FadeOut();
	void Flash();

	EfectPanelStatus Status = None;
};

