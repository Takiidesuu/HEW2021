#include "Efect.h"

int CEfect::EfectCnt = 0;

CEfect::CEfect(bool loopflg, const char* texturePath, int horizontalPartNum, int verticalPartNum, float PosX, float PosY, float SizeX, float SizeY) :CGameObject(texturePath, horizontalPartNum, verticalPartNum, PosX, PosY, SizeX, SizeY)
{
	HRESULT hr;

	// ���_�o�b�t�@�p�ӁB
	D3D11_BUFFER_DESC bufferDesc;
	bufferDesc.ByteWidth = sizeof(VERTEX_POSTEX) * 6;
	bufferDesc.Usage = D3D11_USAGE_DEFAULT;
	bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bufferDesc.CPUAccessFlags = 0;
	bufferDesc.MiscFlags = 0;
	bufferDesc.StructureByteStride = 0;

	hr = Direct3D_GetDevice()->CreateBuffer(&bufferDesc, NULL, &mpVertexBuffer);
	if (FAILED(hr)) {
		MessageBoxA(nullptr, "���_�o�b�t�@�[�쐬���s�B", "Error", MB_OK);
		exit(-1);
	}

	// �e�N�X�`���ǂݍ��݁B
	hr = Direct3D_LoadTexture(texturePath, &mpTexture);
	if (FAILED(hr)) {
		char errorMsg[256] = "�e�N�X�`���ǂݍ��ݎ��s: ";
		strcat_s(errorMsg, texturePath);
		MessageBoxA(nullptr, errorMsg, "Error", MB_OK);
		exit(-1);
	}

	mHorizontalPartNum = horizontalPartNum;		//�g�p����e�N�X�`���̉��̕�����
	mVerticalPartNum = verticalPartNum;			//�g�p����e�N�X�`���̏c�̕�����

	this->mPosX = PosX;							//X���W
	this->mPosY = PosY;							//Y���W
	mSizeWidth = SizeX;							//X�̃T�C�Y
	mSizeHeight = SizeY;						//Y�̃T�C�Y

	loop_reproducing = loopflg;
	EfectCnt++;
}

CEfect::CEfect(bool loopflg, const char * texturePath, int horizontalPartNum, int verticalPartNum, float PosX, float PosY, float SizeX, float SizeY, float PixelSizeX, float PixelSizeY) :CGameObject(texturePath, horizontalPartNum, verticalPartNum, PosX, PosY, SizeX, SizeY, PixelSizeX, PixelSizeY)
{
	HRESULT hr;

	// ���_�o�b�t�@�p�ӁB
	D3D11_BUFFER_DESC bufferDesc;
	bufferDesc.ByteWidth = sizeof(VERTEX_POSTEX) * 6;
	bufferDesc.Usage = D3D11_USAGE_DEFAULT;
	bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bufferDesc.CPUAccessFlags = 0;
	bufferDesc.MiscFlags = 0;
	bufferDesc.StructureByteStride = 0;

	hr = Direct3D_GetDevice()->CreateBuffer(&bufferDesc, NULL, &mpVertexBuffer);
	if (FAILED(hr)) {
		MessageBoxA(nullptr, "���_�o�b�t�@�[�쐬���s�B", "Error", MB_OK);
		exit(-1);
	}

	// �e�N�X�`���ǂݍ��݁B
	hr = Direct3D_LoadTexture(texturePath, &mpTexture);
	if (FAILED(hr)) {
		char errorMsg[256] = "�e�N�X�`���ǂݍ��ݎ��s: ";
		strcat_s(errorMsg, texturePath);
		MessageBoxA(nullptr, errorMsg, "Error", MB_OK);
		exit(-1);
	}

	mHorizontalPartNum = horizontalPartNum;		//�g�p����e�N�X�`���̉��̕�����
	mVerticalPartNum = verticalPartNum;			//�g�p����e�N�X�`���̏c�̕�����

	this->mPosX = PosX;							//X���W
	this->mPosY = PosY;							//Y���W
	mSizeWidth = SizeX;							//X�̃T�C�Y
	mSizeHeight = SizeY;						//Y�̃T�C�Y

	mPixelSizeX = 1.0f / PixelSizeX;			//�`��Ɏg�p����e�N�X�`���摜�̉��̃s�N�Z���T�C�Y��UV���W�ɕϊ������ۂ̐��l
	mPixelSizeY = 1.0f / PixelSizeY;			//�`��Ɏg�p����e�N�X�`���摜�̏c�̃s�N�Z���T�C�Y��UV���W�ɕϊ������ۂ̐��l

	loop_reproducing = loopflg;
	EfectCnt++;
}

CEfect::~CEfect()
{
	//�e�N�X�`���ƒ��_�o�b�t�@�̉������
	COM_SAFE_RELEASE(mpTexture);
	COM_SAFE_RELEASE(mpVertexBuffer);

	EfectCnt--;
}

void CEfect::Anim()
{
	//���̕������imHorizontalPartNum�j���A�j���[�V�����̃R�}�̐��Ƃ��Ĉ���
	if (reproducing_complete == false) {

		static int animtest = 0;
		
		animtest++;
		
		if (animtest == 30) {
			SetPart(anim_num, 0);
			anim_num++;
			if (anim_num == mHorizontalPartNum) {//��������� 
				anim_num = 0;
				if (loop_reproducing == false) {//���[���Đ����Ȃ��ꍇ
					reproducing_complete = true;
					mA = 0.0f;
				}

			}
			animtest = 0;
		}
	}
}


