#include "InputBox.h"
#include "constants.h"

using namespace defaultValues;

size_t InputBox::getLastIndex()
{
	return data.size() - size_t{1};
}

void InputBox::reText(char temp)
{
	if (temp == '-')
	{
		if (data[0] == '-')
		{
			data[0] = '+';
		}
		else if (data[0] == '+')
		{
			data[0] = '-';
		}
		else {
			string tmp = "-";
			tmp += data;
			data = tmp;
		}
	}
	else if (temp == BACKSPACE) {
		if (data.size())
			data.erase(getLastIndex());
	}
	else {
		if (text_.getLocalBounds().width < box_.getSize().x - text_.getCharacterSize() / 2)
		{
			if (temp != '.') {
				if (data == "+0" || data == "-0")
					data[1] = temp;
				else
					data += temp;
			}
			else {
				if (data.find(".") == string::npos) {
					if (data == "0")
						data = "0.";
					else
						data += temp;
				}
			}
		}
	}

	if (data[0] == '-')
	{
		if (data[1] == '0')
			if (data.size() > 2 && data[2] != '.')
				data.erase(1, 1);
	}
	else if (data[0] == '0') {
		if (data.size() > 1 && data[1] != '.')
			data.erase(0, 1);
	}

	while (data.size() > 0 && !isdigit(data.back()) && data.back() != '.')
		data.erase(data.size() - 1, 1);

	if (data.empty())
		data = "0";

	text_.setString(data);
}

bool InputBox::select() {
	return focus_;
}

bool InputBox::select(Vector2i mouse)
{
	if ((mouse.x > coord_.x && mouse.x < coord_.x + size_.w)
	 && (mouse.y > coord_.y && mouse.y < coord_.y + size_.h)) {
		focus_ = true;
		box_.setOutlineColor(DEFUALT_INPUTBOX_FOCUS_OUTLINE_COLOR);
	}
	else {
		box_.setOutlineColor(DEFAULT_BUTTON_OUTLINE_COLOR);
		focus_ = false;
		if (data.empty())
			data = "0";
	}

	return focus_;
}

Text InputBox::displayText() {	
	text_.setPosition(coord_.x + size_.w - text_.getLocalBounds().width - 6.0f,
		coord_.y + size_.h / 2 - text_.getCharacterSize() * 2 / 3);
	
	text_.setString(data);
	return text_;
}

RectangleShape InputBox::displayBox() {
	return box_;
}

string InputBox::readText()
{
	return data;
}