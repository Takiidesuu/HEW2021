#include <math.h>
#include "Collision.h"

bool Collision::CircleAndCircleTest(const CircleShape circle_a, const CircleShape circle_b)
{
	// �~�̒��S���m�̋����̕������v�Z
	float sqDist = powf(fabsf(circle_a.GetCenterX() - circle_b.GetCenterX()), 2.0f) + powf(fabsf(circle_a.GetCenterY() - circle_b.GetCenterY()), 2.0f);

	// �~���m����������̂́A�����̒��S�Ԃ̕����������������������~�̔��a�̍��v�����������ꍇ
	return sqDist <= powf(circle_a.GetRadius() + circle_b.GetRadius(), 2.0f);
}

bool Collision::CircleAndRectTest(const CircleShape circle, const RectShape rect)
{
	// �~�̒��S�Ƌ�`�̊Ԃ̋����̕������v�Z
	float sqDist = 0.0f;

	if (circle.GetCenterX() < rect.GetPosX())
	{
		sqDist += powf(rect.GetPosX() - circle.GetCenterX(), 2.0f);
	}
	if (circle.GetCenterX() > rect.GetPosX() + rect.GetSizeX())
	{
		sqDist += powf(circle.GetCenterX() - rect.GetPosX() - rect.GetSizeX(), 2.0f);
	}

	if (circle.GetCenterY() < rect.GetPosY())
	{
		sqDist += powf(rect.GetPosY() - circle.GetCenterY(), 2.0f);
	}
	if (circle.GetCenterY() > rect.GetPosY() + rect.GetSizeY())
	{
		sqDist += powf(circle.GetCenterY() - rect.GetPosY() - rect.GetSizeY(), 2.0f);
	}

	// �~�Ƌ�`����������̂́A�����̊Ԃ̕����������������������~�̔��a�����������ꍇ
	return sqDist <= powf(circle.GetRadius(), 2.0f);
}

bool Collision::RectAndRectTest(const RectShape rect_a, const RectShape rect_b)
{
	// ��`�̒��S���m��X������Y�����̋������v�Z
	//float centerX_a = rect_a.GetPosX() + rect_a.GetSizeX() / 2.0f;
	//float centerY_a = rect_a.GetPosY() + rect_a.GetSizeY() / 2.0f;
	//float centerX_b = rect_b.GetPosX() + rect_b.GetSizeX() / 2.0f;
	//float centerY_b = rect_b.GetPosY() + rect_b.GetSizeY() / 2.0f;

	float distanceX = fabsf(rect_a.GetPosX() - rect_b.GetPosX());
	float distanceY = fabsf(rect_a.GetPosY() - rect_b.GetPosY());

	// ��`�̒��S����[�܂ł̒����̍��v���v�Z
	float size_sumX = (rect_a.GetSizeX() + rect_b.GetSizeX()) / 2.0f;
	float size_sumY = (rect_a.GetSizeY() + rect_b.GetSizeY()) / 2.0f;

	// ��`���m����������̂́A�����̒��S�Ԃ̋��������S����[�܂ł̒����̍��v�����������ꍇ
	return (distanceX <= size_sumX) && (distanceY <= size_sumY);
}