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
	bool focus_;
	bool press_;

public:
	Button(Size2D size = DEFAULT_BUTTON_SIZE,
		Point2D coord = Point2D(), string str = DEFAULT_BUTTON_DATA) : Label(coord, str)
	{
		press_ = false;
		focus_ = false;
		size_ = size;
		text_.setPosition(coord_.x + size_.w / 2 - (data.size() * text_.getCharacterSize() / 4),
						  coord_.y + size_.h / 2 - text_.getCharacterSize() * 2 / 3);
		box_.setSize(Vector2f(size_.w, size_.h));
		box_.setPosition(coord_.x, coord_.y);
		box_.setFillColor(DEFAULT_BUTTON_FILL_COLOR);
		box_.setOutlineThickness(DEFAULT_BUTTON_OUTLINE_THICKNESS);
		box_.setOutlineColor(DEFAULT_BUTTON_OUTLINE_COLOR);
	}
	
	void press();
	void release();
	bool pressed();
	bool select();
	bool select(Vector2i);
	RectangleShape displayButton();
	void changeFillColor(Color);
};