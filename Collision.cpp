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