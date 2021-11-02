#pragma once

//--------------------------------------
// 形状の基底クラス
//--------------------------------------
class Shape
{

};

//--------------------------------------
// 円形状クラス
//--------------------------------------
class CircleShape : public Shape
{
public:
	CircleShape(float centerX, float centerY, float radius);  // 初期化用コンストラクタ

	float GetCenterX() const;  // 中心のX座標を取得
	float GetCenterY() const;  // 中心のY座標を取得
	float GetRadius() const;   // 半径を取得

public:
	float centerX, centerY;  // 中心の座標
	float radius;            // 半径
};

//--------------------------------------
// 矩形形状クラス
//--------------------------------------
class RectShape : public Shape
{
public:
	RectShape(float posX, float posY, float sizeX, float sizeY);  // 初期化用コンストラクタ

	void SetPos(float posX, float posY);   // 中心の座標をセット
	void SetSize(float sizeX, float sizeY);  // 大きさをセット

	float GetPosX() const;   // 中心のX座標を取得
	float GetPosY() const;   // 中心のY座標を取得
	float GetSizeX() const;  // 横幅を取得
	float GetSizeY() const;  // 縦幅を取得

public:
	float posX, posY;    // 中心の座標
	float sizeX, sizeY;  // 大きさ
};