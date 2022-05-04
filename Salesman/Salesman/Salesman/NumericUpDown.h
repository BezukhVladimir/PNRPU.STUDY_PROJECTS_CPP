#pragma once
#include <SFML/Graphics.hpp>
#include "Label.h"
#include "Button.h"

struct NumericUpDown
{
public:
	void init(Point2D coord, const int& data) {
		float t;

		button_decrement_.changeCoord(coord);
		button_decrement_.data = "-";

		t = button_decrement_.getBox().getLocalBounds().width;
		label_.changeCoord(Point2D(coord.x + t + 15.0f,
								   coord.y));
		label_.data = to_string(data);

		t = label_.getText().getLocalBounds().width;
		coord = label_.getCoord();
		button_increment_.changeCoord(
			Point2D(coord.x + t + 20.0f,
					coord.y));
		button_increment_.data = "+";
	}

	void changeButtonsColor(const Color& color, const Color& h_color)
	{
		button_decrement_.changeBoxFillColor(
			color, h_color);
		button_increment_.changeBoxFillColor(
			color, h_color);
	}

	void changeLabelsColor(const Color& color)
	{
		label_.changeTextColor(color);
		button_decrement_.changeTextColor(color);
		button_increment_.changeTextColor(color);
	}

	bool isHovered(const Vector2i& mouse)
	{
		return
			button_decrement_.isHovered(mouse) ||
			button_increment_.isHovered(mouse);
	}

	Label  label_;
	Button button_increment_;
	Button button_decrement_;
};