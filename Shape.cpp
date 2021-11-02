#include "Shape.h"

CircleShape::CircleShape(float centerX, float centerY, float radius)
{
	this->centerX = centerX;
	this->centerY = centerY;
	this->radius = radius;
}

float CircleShape::GetCenterX() const
{
	return this->centerX;
}

float CircleShape::GetCenterY() const
{
	return this->centerY;
}

float CircleShape::GetRadius() const
{
	return this->radius;
}

RectShape::RectShape(float posX, float posY, float sizeX, float sizeY)
{
	this->posX = posX;
	this->posY = posY;
	this->sizeX = sizeX;
	this->sizeY = sizeY;
}

void RectShape::SetPos(float posX, float posY)
{
	this->posX = posX;
	this->posY = posY;
}

void RectShape::SetSize(float sizeX, float sizeY)
{
	this->sizeX = sizeX;
	this->sizeY = sizeY;
}

float RectShape::GetPosX() const
{
	return this->posX;
}

float RectShape::GetPosY() const
{
	return this->posY;
}

float RectShape::GetSizeX() const
{
	return this->sizeX;
}

float RectShape::GetSizeY() const
{
	return this->sizeY;
}