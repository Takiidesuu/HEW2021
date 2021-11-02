#pragma once

#include "Shape.h"

//--------------------------------------
// “–‚½‚è”»’è‚ÌŠî’êƒNƒ‰ƒX
//--------------------------------------
class Collision
{
public:
	static bool CircleAndCircleTest(const CircleShape circle_a, const CircleShape circle_b);  // ‰~‚Æ‰~
	static bool CircleAndRectTest(const CircleShape circle, const RectShape rect);            // ‰~‚Æ‹éŒ`
	static bool RectAndRectTest(const RectShape rect_a, const RectShape rect_b);              // ‹éŒ`‚Æ‹éŒ`
};