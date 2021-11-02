#pragma once

//--------------------------------------
// �`��̊��N���X
//--------------------------------------
class Shape
{

};

//--------------------------------------
// �~�`��N���X
//--------------------------------------
class CircleShape : public Shape
{
public:
	CircleShape(float centerX, float centerY, float radius);  // �������p�R���X�g���N�^

	float GetCenterX() const;  // ���S��X���W���擾
	float GetCenterY() const;  // ���S��Y���W���擾
	float GetRadius() const;   // ���a���擾

public:
	float centerX, centerY;  // ���S�̍��W
	float radius;            // ���a
};

//--------------------------------------
// ��`�`��N���X
//--------------------------------------
class RectShape : public Shape
{
public:
	RectShape(float posX, float posY, float sizeX, float sizeY);  // �������p�R���X�g���N�^

	void SetPos(float posX, float posY);   // ���S�̍��W���Z�b�g
	void SetSize(float sizeX, float sizeY);  // �傫�����Z�b�g

	float GetPosX() const;   // ���S��X���W���擾
	float GetPosY() const;   // ���S��Y���W���擾
	float GetSizeX() const;  // �������擾
	float GetSizeY() const;  // �c�����擾

public:
	float posX, posY;    // ���S�̍��W
	float sizeX, sizeY;  // �傫��
};