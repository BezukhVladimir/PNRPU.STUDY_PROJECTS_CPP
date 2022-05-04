#include "Button.h"

void Button::press()
{
	press_ = true;
	box_.setFillColor(HOVER_BUTTON_FILL_COLOR);
}

void Button::release()
{
	press_ = false;
	box_.setFillColor(DEFAULT_BUTTON_FILL_COLOR);
}

bool Button::pressed()
{
	return press_;
}

bool Button::select() {
	return focus_;
}

bool Button::select(Vector2i mouse) {
	if ((mouse.x > coord_.x && mouse.x < coord_.x + size_.w)
		&& (mouse.y > coord_.y && mouse.y < coord_.y + size_.h)) {
		focus_ = true;
		box_.setFillColor(HOVER_BUTTON_FILL_COLOR);
	}
	else {
		focus_ = false;

		if (!press_)
			box_.setFillColor(DEFAULT_BUTTON_FILL_COLOR);
	}

	return focus_;
}

RectangleShape Button::displayButton() 
{ 
	return box_;
}

void Button::changeFillColor(Color color)
{
	box_.setFillColor(color);
}
