#include "CEfectPanel.h"

CEfectPanel::CEfectPanel() :CSprite("assets/EfectPanel.png", 1, 1, 0.0f, 0.0f, 3.6f, 2.0f)
{
}
void CEfectPanel::Update()
{
	switch (Status)
	{
	case InFadein:
		FadeIn();
		break;
	case InFadeout:
		FadeOut();
		break;
	case InFlash:
		break;
	default:

		break;
	}

}
void CEfectPanel::FadeIn()
{
	if (mA > 0.0f) {
		mA -= 0.005f;
		Status = InFadein;
	}

	else {
		Status = FadeinCompleted;
	}
}
void CEfectPanel::FadeOut()
{
	if (mA < 1.0f) {
		mA += 0.005f;
		Status = InFadeout;
	}
	else {
		Status = FadeoutCompleted;
	}
}
void CEfectPanel::Flash()
{
	static bool flashflg = false;

	if (!flashflg) {
		mA = 1.0;
	}

	else {
		if (mA < 0.0f) {
			mA -= 0.001f;
			Status = InFlash;
		}

		else {
			Status = FlashCompleted;
			flashflg = false;
		}
	}
};
