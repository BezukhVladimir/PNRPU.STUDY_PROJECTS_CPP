#include "DialogBox.h"

void DialogBox::overload()
{
	data = constants::mainWindow::OVERLOAD;
	text_.setString(data);
	value = 0.0;
	operation = "";
}

Text DialogBox::displayText() {
	text_.setString(data);

	if (data.size() > 18)
		overload();
	else if (text_.getLocalBounds().width > size_.w - 10.0f)
		overload();

	text_.setPosition(coord_.x + size_.w - text_.getLocalBounds().width - 6.0f,
		coord_.y + size_.h / 2 - text_.getCharacterSize() * 2 / 3);

	return text_;
}

RectangleShape DialogBox::displayBox() {
	return box_;
}