#include "Button.h"

void Button::press()
{
	pressed_ = true;
}

void Button::release()
{
	pressed_ = false;
}

bool Button::isPressed() const
{
	return pressed_;
}

bool Button::isHovered(const Vector2i mouse = Vector2i(0, 0))
{
	if (mouse != Vector2i(0, 0))
	{
		if ((mouse.x > coord_.x && mouse.x < coord_.x + size_.w) && 
			(mouse.y > coord_.y && mouse.y < coord_.y + size_.h)) {
			hovered_ = true;
		}
		else {
			hovered_ = false;
		}
	}

	if (hovered_) {
		box_.setFillColor(box_hovered_color_);
	} else {
		box_.setFillColor(box_fill_color_);
	}

	return hovered_;
}

RectangleShape Button::getBox() const
{ 
	return box_;
}

void Button::changeBoxFillColor(const Color& color, const Color& h_color)
{
	box_fill_color_ = color;
	box_hovered_color_ = h_color;
	box_.setFillColor(color);
}

void Button::changeBoxSize(const Size2D& size)
{
	size_ = size;
	box_.setSize(Vector2f(size_.w, size_.h));
}

void Button::changeCoord(const Point2D& coord)
{
	Label::changeCoord(coord);
	box_.setPosition(sf::Vector2f(coord.x, coord.y));
}

void Button::fixedLabel()
{
	float th, tw;
	th = text_.getLocalBounds().height;
	tw = text_.getLocalBounds().width;
	text_.setPosition(Vector2f(coord_.x + (size_.w - tw) / 2.0f,
							   coord_.y - (size_.h - th) / 2.0f));
}
