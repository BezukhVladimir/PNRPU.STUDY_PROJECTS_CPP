#pragma once
#include "Label.h"
#include "Size2D.h"
#include "constants.h"

using namespace std;
using namespace sf;
using namespace constants::button;

class Button :
    public Label
{
protected:
	Size2D size_;
	RectangleShape box_;
	Color box_fill_color_;
	Color box_hovered_color_;

	bool hovered_; // mouse hover
	bool pressed_; 

public:
	Button(Size2D size = DEFAULT_BUTTON_SIZE,
		Point2D coord = Point2D(), string str = DEFAULT_BUTTON_DATA) : Label(coord, str)
	{
		pressed_ = false;
		hovered_ = false;
		size_ = size;
		box_.setSize(Vector2f(size_.w, size_.h));
		box_.setPosition(coord_.x, coord_.y);
		box_.setFillColor(DEFAULT_BUTTON_FILL_COLOR);
		box_.setOutlineThickness(DEFAULT_BUTTON_OUTLINE_THICKNESS);
		box_.setOutlineColor(DEFAULT_BUTTON_OUTLINE_COLOR);
	}
	
	void press();
	void release();
	bool isPressed() const; 
	bool isHovered(const Vector2i mouse);
	RectangleShape getBox() const;
	void changeBoxFillColor(const Color& color, const Color& h_color);
	void changeBoxSize(const Size2D& size);
	virtual void changeCoord(const Point2D& coord) override;
	void fixedLabel();
};