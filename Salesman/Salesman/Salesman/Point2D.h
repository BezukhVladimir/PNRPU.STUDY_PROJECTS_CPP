#pragma once

struct Point2D
{
public:
	Point2D(const float& x_ = 0.0, const float& y_ = 0.0)
		: x(x_), y(y_) {}

	float x, y;
};