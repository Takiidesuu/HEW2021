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

bool Collision::CircleAndLineTest(const CircleShape circle, const float x1, const float y1, const float x2, const float y2)
{
	// �x�N�g���̍쐬
	Vec2 start_to_center = Vec2(circle.centerX - x1, circle.centerY - y1);
	Vec2 end_to_center = Vec2(circle.centerX - x2, circle.centerY - y2);
	Vec2 start_to_end = Vec2(x2 - x1, y2 - y1);

	// �P�ʃx�N�g��������
	float start_to_end_length = sqrtf(start_to_end.x * start_to_end.x + start_to_end.y * start_to_end.y);
	Vec2 normal_start_to_end = Vec2(start_to_end.x / start_to_end_length, start_to_end.y / start_to_end_length);

	/*
	�ˉe���������̒���
		�n�_�Ɖ~�̒��S�ŊO�ς��s��
		���n�_ => �I�_�̃x�N�g���͒P�ʉ����Ă���
	*/
	float distance_projection = start_to_center.x * normal_start_to_end.y - normal_start_to_end.x * start_to_center.y;

	// �����Ɖ~�̍ŒZ�̒��������a����������
	if (fabsf(distance_projection) < circle.radius)
	{
		// �n�_ => �I�_�Ǝn�_ => �~�̒��S�̓��ς��v�Z����
		float dot01 = start_to_center.x * start_to_end.x + start_to_center.y * start_to_end.y;
		// �n�_ => �I�_�ƏI�_ => �~�̒��S�̓��ς��v�Z����
		float dot02 = end_to_center.x * start_to_end.x + end_to_center.y * start_to_end.y;

		// ��̓��ς̊|���Z���ʂ�0�ȉ��Ȃ瓖����
		if (dot01 * dot02 <= 0.0f)
		{
			return true;
		}
		else
		{
			/*
			��̏�������R�ꂽ�ꍇ�A�~�͐�����ɂ͂Ȃ��̂ŁA
			�n�_ => �~�̒��S�̒������A�I�_ => �~�̒��S�̒�����
			�~�̔��a�����Z�������瓖����
			*/
			float start_to_center_length = sqrtf(start_to_center.x * start_to_center.x + start_to_center.y * start_to_center.y);
			float end_to_center_length = sqrtf(end_to_center.x * end_to_center.x + end_to_center.y * end_to_center.y);

			if (start_to_center_length < circle.radius || end_to_center_length < circle.radius)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}
}
