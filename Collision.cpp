#include <math.h>
#include "Collision.h"

bool Collision::CircleAndCircleTest(const CircleShape circle_a, const CircleShape circle_b)
{
	// 円の中心同士の距離の平方を計算
	float sqDist = powf(fabsf(circle_a.GetCenterX() - circle_b.GetCenterX()), 2.0f) + powf(fabsf(circle_a.GetCenterY() - circle_b.GetCenterY()), 2.0f);

	// 円同士が交差するのは、それらの中心間の平方した距離が平方した円の半径の合計よりも小さい場合
	return sqDist <= powf(circle_a.GetRadius() + circle_b.GetRadius(), 2.0f);
}

bool Collision::CircleAndRectTest(const CircleShape circle, const RectShape rect)
{
	// 円の中心と矩形の間の距離の平方を計算
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

	// 円と矩形が交差するのは、それらの間の平方した距離が平方した円の半径よりも小さい場合
	return sqDist <= powf(circle.GetRadius(), 2.0f);
}

bool Collision::RectAndRectTest(const RectShape rect_a, const RectShape rect_b)
{
	// 矩形の中心同士のX方向とY方向の距離を計算
	//float centerX_a = rect_a.GetPosX() + rect_a.GetSizeX() / 2.0f;
	//float centerY_a = rect_a.GetPosY() + rect_a.GetSizeY() / 2.0f;
	//float centerX_b = rect_b.GetPosX() + rect_b.GetSizeX() / 2.0f;
	//float centerY_b = rect_b.GetPosY() + rect_b.GetSizeY() / 2.0f;

	float distanceX = fabsf(rect_a.GetPosX() - rect_b.GetPosX());
	float distanceY = fabsf(rect_a.GetPosY() - rect_b.GetPosY());

	// 矩形の中心から端までの長さの合計を計算
	float size_sumX = (rect_a.GetSizeX() + rect_b.GetSizeX()) / 2.0f;
	float size_sumY = (rect_a.GetSizeY() + rect_b.GetSizeY()) / 2.0f;

	// 矩形同士が交差するのは、それらの中心間の距離が中心から端までの長さの合計よりも小さい場合
	return (distanceX <= size_sumX) && (distanceY <= size_sumY);
}

bool Collision::RectAndPointTest(const RectShape rect, const float point_x, const float point_y)
{
	return (point_x >= rect.posX - rect.sizeX / 2.0f && point_x <= rect.posX + rect.sizeX / 2.0f && point_y >= rect.posY - rect.sizeY / 2.0f && point_y <= rect.posY + rect.sizeY / 2.0f);
}

bool Collision::RectAndRectHit(const TPos_and_Size rect_a, const TPos_and_Size rect_b)
{
	// 矩形の中心同士のX方向とY方向の距離を計算
	float distanceX = fabsf(rect_a.posx - rect_b.posx);
	float distanceY = fabsf(rect_a.posy - rect_b.posy);

	// 矩形の中心から端までの長さの合計を計算
	float size_sumX = (rect_a.sizex + rect_b.sizex) / 2.0f;
	float size_sumY = (rect_a.sizey + rect_b.sizey) / 2.0f;

	// 矩形同士が交差するのは、それらの中心間の距離が中心から端までの長さの合計よりも小さい場合
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
	// ベクトルの作成
	Vec2 start_to_center = Vec2(circle.centerX - x1, circle.centerY - y1);
	Vec2 end_to_center = Vec2(circle.centerX - x2, circle.centerY - y2);
	Vec2 start_to_end = Vec2(x2 - x1, y2 - y1);

	// 単位ベクトル化する
	float start_to_end_length = sqrtf(start_to_end.x * start_to_end.x + start_to_end.y * start_to_end.y);
	Vec2 normal_start_to_end = Vec2(start_to_end.x / start_to_end_length, start_to_end.y / start_to_end_length);

	/*
	射影した線分の長さ
		始点と円の中心で外積を行う
		※始点 => 終点のベクトルは単位化しておく
	*/
	float distance_projection = start_to_center.x * normal_start_to_end.y - normal_start_to_end.x * start_to_center.y;

	// 線分と円の最短の長さが半径よりも小さい
	if (fabsf(distance_projection) < circle.radius)
	{
		// 始点 => 終点と始点 => 円の中心の内積を計算する
		float dot01 = start_to_center.x * start_to_end.x + start_to_center.y * start_to_end.y;
		// 始点 => 終点と終点 => 円の中心の内積を計算する
		float dot02 = end_to_center.x * start_to_end.x + end_to_center.y * start_to_end.y;

		// 二つの内積の掛け算結果が0以下なら当たり
		if (dot01 * dot02 <= 0.0f)
		{
			return true;
		}
		else
		{
			/*
			上の条件から漏れた場合、円は線分上にはないので、
			始点 => 円の中心の長さか、終点 => 円の中心の長さが
			円の半径よりも短かったら当たり
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
