#include "Player.h"

Player::Player(float posX, float posY) : CGameObject("assets/player.png", 14, 4, posX, posY, 0.15f, 0.15f)
{
	sprite = new CGameObject*[5];

	sprite[0] = new CGameObject("assets/tpEffect1.png", 1, 1, 0.0f, 0.0f, 0.15f, 0.15f);
	sprite[1] = new CGameObject("assets/tpEffect2.png", 1, 1, 0.0f, 0.0f, 0.15f, 0.15f);
	sprite[2] = new CGameObject("assets/tpEffect3.png", 1, 1, 0.0f, 0.0f, 0.15f, 0.15f);
}

void Player::Move()
{

}

void Player::anim()
{
	playerAnimCnt++;

	if (playerAnimCnt >= animSpeed)
	{
		mPartX++;

		int holder = 0;

		switch (mPartY)
		{
		case 0: holder = 7;
			break;
		case 1: holder = 14;
			animStat = true;
			break;
		case 2: holder = 11;
			animStat = true;
			break;
		case 3: holder = 11;
			animStat = true;
			break;
		}

		if (mPartX >= holder)
		{
			mPartX = 0;
			mPartY = 0;
			animSpeed = ANIMSPEED;
			animStat = false;
		}

		playerAnimCnt = 0;
	}
}