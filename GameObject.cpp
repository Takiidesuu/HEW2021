#include "GameObject.h"

float CGameObject::mCameraPosX = 0.0f;
float CGameObject::mCameraPosY = 0.0f;

CGameObject::CGameObject(const char* texturePath, int horizontalPartNum, int verticalPartNum, float PosX, float PosY, float SizeX, float mSizeHeight) :CSprite(texturePath, horizontalPartNum, verticalPartNum, PosX, PosY, SizeX, mSizeHeight) {

}

CGameObject::CGameObject(const char* texturePath, int horizontalPartNum, int verticalPartNum, float PosX, float PosY, float SizeX, float mSizeHeight, float PixelSizeX, float PixelmSizeHeight) : CSprite(texturePath, horizontalPartNum, verticalPartNum, PosX, PosY, SizeX, mSizeHeight, PixelSizeX, PixelmSizeHeight) {

}

void CGameObject::Draw()
{
	//��ʊO�̃I�u�W�F�N�g�͕`�揈�����s��Ȃ�
	if ((this->mPosX + this->mSizeWidth / 2 - this->mCameraPosX > -1.0) && (this->mPosX - this->mSizeWidth / 2 - this->mCameraPosX < 1.0) && (this->mPosY + this->mSizeHeight / 2 - this->mCameraPosY > -1.0) && (this->mPosY - this->mSizeHeight / 2 - this->mCameraPosY < 1.0))
	{
		// �`��Ŏg���e�N�X�`�����Z�b�g�B
		Direct3D_GetContext()->PSSetShaderResources(0, 1, &mpTexture);

		// �`��Ŏg�����_�o�b�t�@���Z�b�g�B
		UINT strides = sizeof(VERTEX_POSTEX);
		UINT offsets = 0;
		Direct3D_GetContext()->IASetVertexBuffers(0, 1, &mpVertexBuffer, &strides, &offsets);

		//�J�����̈ʒu��XY���W��␳����
		float DrawX = (mPosX - mCameraPosX);
		float DrawY = (mPosY - mCameraPosY);

		// ���_�V�F�[�_�[�̏���g�ݗ��Ă�B
		float Left = DrawX - mSizeWidth / 2;		//�����W
		float Right = DrawX + mSizeWidth / 2;		//�E���W
		float Top = DrawY + mSizeHeight / 2;		//����W
		float Bottum = DrawY - mSizeHeight / 2;		//�����W

		// �e�N�X�`���̈ꕪ������uv�l������o���B
		float SizeU = 1.0 / mHorizontalPartNum;
		float SizeV = 1.0 / mVerticalPartNum;

		// �w�肵���`�敔����uv�l���v�Z����B
		float LeftU = mPartX * SizeU + mPixelSizeX;					//�e�N�X�`�������W
		float RightU = (mPartX + 1) * SizeU - mPixelSizeX;			//�e�N�X�`���E���W
		float TopV = mPartY * SizeV + mPixelSizeY;					//�e�N�X�`������W
		float BottumV = (mPartY + 1) *SizeV - mPixelSizeY;			//�e�N�X�`�������W


		VERTEX_POSTEX vertexData[] = {
			{Left, Top, 0,
			mR,mG,mB,mA,
			LeftU, TopV},

			{Right, Top, 0,
			mR,mG,mB,mA,
			RightU, TopV},

			{Right, Bottum, 0,
			mR,mG,mB,mA,
			RightU, BottumV},

			{Right, Bottum, 0,
			mR,mG,mB,mA,
			RightU, BottumV},

			{Left, Bottum, 0,
			mR,mG,mB,mA,
			LeftU, BottumV},

			{Left, Top, 0,
			mR,mG,mB,mA,
			LeftU, TopV},
		};

		// ���_�o�b�t�@���X�V
		Direct3D_GetContext()->UpdateSubresource(mpVertexBuffer, 0, NULL, vertexData, 0, 0);

		// �X�v���C�g�`��B
		Direct3D_GetContext()->Draw(6, 0);
	}
}

void CGameObject::Update(void)
{

}

TPos_and_Size CGameObject::GetPosAndSize()
{
	TPos_and_Size Pos_and_Size{ mPosX,mPosY,mSizeWidth,mSizeHeight };

	return Pos_and_Size;
}

void CGameObject::SinJump()
{
	float pi = 3.14159265358979f;

	if (!this->nowAir)
	{
		this->nowJump = true;
	}

	if (this->nowJump)
	{
		this->mPosY += this->jumpY * sin(pi * jumpTime);
		this->jumpTime += 0.0005f;
	}

	if (this->jumpTime >= 2.0f)
	{
		this->jumpTime = 0.0f;
		this->nowJump = false;
	}
}

//�W�����v
void CGameObject::GravityJump()
{
	if (!this->nowAir)
	{
		this->nowJump = true;
		this->nowAir = true;
	}

	if (this->nowJump)
	{
		this->mPosY += this->jumpV * this->jumpTime * 100.0f * JUMPPOWER;
		this->jumpTime += 0.00008f;

		if (this->jumpV * this->jumpTime <= 0.5f * GRAVITY * this->airTime * this->airTime)
		{
			this->nowJump = false;
			this->airTime = 0.0f;
			this->jumpTime = 0.0f;
		}
	}
}

void CGameObject::Gravity()
{
	//�󒆂ɂ��邩�ۂ�
	/*if (this->mPosY - this->mSizeHeight / 2.0f < GROUND_Y)
	{
		this->mPosY = GROUND_Y + this->mSizeHeight / 2.0f;
		this->nowAir = false;
	}
	else
	{
		nowAir = true;
	}*/

	//�ڒn�����ꍇ�󒆑؍ݎ��Ԃ����Z�b�g����
	if (!this->nowAir)
	{
		this->airTime = 0.0f;
	}

	if (this->nowAir)
	{
		this->mPosY -= 0.5 * GRAVITY * this->airTime * this->airTime;
		this->airTime += 0.00008f * 10.0f;
	}

}

void CGameObject::SetAirTime(float t)
{
	this->airTime = t;
}

void CGameObject::SetNowAir(bool air)
{
	this->nowAir = air;
}

bool CGameObject::GetNowJump() const
{
	return this->nowJump;
}

bool CGameObject::GetNowAir() const
{
	return this->nowAir;
}