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

bool Collision::RectAndPointTest(const RectShape rect, const float point_x, const float point_y)
{
	return (point_x >= rect.posX - rect.sizeX / 2.0f && point_x <= rect.posX + rect.sizeX / 2.0f && point_y >= rect.posY - rect.sizeY / 2.0f && point_y <= rect.posY + rect.sizeY / 2.0f);
}

bool Collision::RectAndRectHit(const TPos_and_Size rect_a, const TPos_and_Size rect_b)
{
	// ��`�̒��S���m��X������Y�����̋������v�Z
	float distanceX = fabsf(rect_a.posx - rect_b.posx);
	float distanceY = fabsf(rect_a.posy - rect_b.posy);

	// ��`�̒��S����[�܂ł̒����̍��v���v�Z
	float size_sumX = (rect_a.sizex + rect_b.sizex) / 2.0f;
	float size_sumY = (rect_a.sizey + rect_b.sizey) / 2.0f;

	// ��`���m����������̂́A�����̒��S�Ԃ̋��������S����[�܂ł̒����̍��v�����������ꍇ
	return (distanceX < size_sumX) && (distanceY < size_sumY);
}

bool Collision::LineAndLineTest(const float A1x, const float A1y, const float A2x, const float A2y, const float B1x, const float B1y, const float B2x, const float B2y)
{
	{
		const float baseX = B2x - B1x;
		const float baseY = B2y - B1y;
		const float sub1X = A1x - B1x;
		const float sub1Y = A1y - B1y;
		const float sub2X = A2x - B1x;
		const float sub2Y = A2y - B1y;

		const float bs1 = baseX * sub1Y - baseY * sub1X;
		const float bs2 = baseX * sub2Y - baseY * sub2X;
		const float re = bs1 * bs2;
		if (re > 0) {
			return false;
		}
	}
	{
		const float baseX = A2x - A1x;
		const float baseY = A2y - A1y;
		const float sub1X = B1x - A1x;
		const float sub1Y = B1y - A1y;
		const float sub2X = B2x - A1x;
		const float sub2Y = B2y - A1y;

		const float bs1 = baseX * sub1Y - baseY * sub1X;
		const float bs2 = baseX * sub2Y - baseY * sub2X;
		const float re = bs1 * bs2;
		if (re > 0) {
			return false;
		}
	}
	return true;
}

bool Collision::RectAndLineTest(const RectShape rect, const float x1, const float y1, const float x2, const float y2)
{
	const float left = rect.posX - rect.sizeX / 2.0f;
	const float right = rect.posX + rect.sizeX / 2.0f;
	const float top = rect.posY + rect.sizeY / 2.0f;
	const float bottom = rect.posY - rect.sizeY / 2.0f;

	if (LineAndLineTest(left, top, right, top, x1, y1, x2, y2)) { return true; }
	if (LineAndLineTest(right, top, right, bottom, x1, y1, x2, y2)) { return true; }
	if (LineAndLineTest(right, bottom, left, bottom, x1, y1, x2, y2)) { return true; }
	if (LineAndLineTest(left, bottom, left, top, x1, y1, x2, y2)) { return true; }

	return false;
}