#pragma once
#include "Button.h"
#include "constants.h"

using namespace std;
using namespace sf;
using namespace constants::inputBox;

class InputBox : 
	public Button
{
public:
	InputBox(Size2D size = DEFAULT_INPUTBOX_SIZE,
		Point2D coord = Point2D(), string str = DEFAULT_INPUTBOX_DATA) : Button(size, coord, str)
	{
		text_.setFillColor(DEFAULT_INPUTBOX_FONT_COLOR);
		box_.setFillColor(DEFAULT_INPUTBOX_FILL_COLOR);
	}

	size_t getLastIndex();
	void reText(char);
	bool select();
	bool select(Vector2i);
	Text displayText();
	RectangleShape displayBox();
	string readText();
};