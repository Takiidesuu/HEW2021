#pragma once

#include "Shape.h"

//--------------------------------------
// �����蔻��̊��N���X
//--------------------------------------
class Collision
{
public:
	static bool CircleAndCircleTest(const CircleShape circle_a, const CircleShape circle_b);  // �~�Ɖ~
	static bool CircleAndRectTest(const CircleShape circle, const RectShape rect);            // �~�Ƌ�`
	static bool RectAndRectTest(const RectShape rect_a, const RectShape rect_b);              // ��`�Ƌ�`
};