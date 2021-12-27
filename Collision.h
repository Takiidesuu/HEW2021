#pragma once

#include "Shape.h"
#include "GameObject.h"

//--------------------------------------
// “–‚½‚è”»’è‚ÌŠî’êƒNƒ‰ƒX
//--------------------------------------
class Collision
{
public:
	static bool CircleAndCircleTest(const CircleShape circle_a, const CircleShape circle_b);  // ‰~‚Æ‰~
	static bool CircleAndRectTest(const CircleShape circle, const RectShape rect);            // ‰~‚Æ‹éŒ`
	static bool RectAndRectTest(const RectShape rect_a, const RectShape rect_b);
	static bool RectAndPointTest(const RectShape rect, const float point_x, const float point_y);
	static bool RectAndRectHit(const TPos_and_Size rect_a, const TPos_and_Size rect_b);
	static bool LineAndLineTest(const float A1x, const float A1y, const float A2x, const float A2y, const float B1x, const float B1y, const float B2x, const float B2y);
	static bool RectAndLineTest(const RectShape rect, const float x1, const float y1, const float x2, const float y2);
	static bool CircleAndLineTest(const CircleShape circle, const float x1, const float y1, const float x2, const float y2);
};