#pragma once
#include "Button.h"
#include "constants.h"

using namespace std;
using namespace sf;
using namespace constants::inputBox;

class DialogBox :
	public Button
{
public:
	double value;
	string operation;

public:
	DialogBox(Size2D size = DEFAULT_INPUTBOX_SIZE,
		Point2D coord = Point2D(), string str = DEFAULT_INPUTBOX_DATA) : Button(size, coord, str)
	{
		value = 0.0l;
		operation = "";
		text_.setFillColor(DEFAULT_INPUTBOX_FONT_COLOR);
		box_.setFillColor(DEFAULT_INPUTBOX_FILL_COLOR);
	}
	
	void overload();
	Text displayText();
	RectangleShape displayBox();
};