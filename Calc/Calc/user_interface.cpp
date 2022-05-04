#include "user_interface.h"

array<Button*, MAIN_WINDOW_NUMBER_OF_BUTTONS>* createUIbuttons()
{
	array<Button*, MAIN_WINDOW_NUMBER_OF_BUTTONS>* buttons =
		new array<Button*, MAIN_WINDOW_NUMBER_OF_BUTTONS>;

	size_t i = 0;
	for (size_t y = 0; y < MAIN_WINDOW_NUMBER_OF_BUTTONS_IN_A_COLUMN; ++y)
		for (size_t x = 0; x < MAIN_WINDOW_NUMBER_OF_BUTTONS_IN_A_ROW; ++x)
			(*buttons)[i++] = new Button(MAIN_WINDOW_BUTTON_SIZE,
				Point2D(DEFAULT_BUTTON_OUTLINE_THICKNESS +
					MAIN_WINDOW_HORIZONTAL_SPACE_BETWEEN_TWO_BUTTONS +
					(MAIN_WINDOW_BUTTON_SIZE.w +
						DEFAULT_BUTTON_OUTLINE_THICKNESS * 2.0f +
							MAIN_WINDOW_HORIZONTAL_SPACE_BETWEEN_TWO_BUTTONS)
								* static_cast<float>(x),
					MAIN_WINDOW_SIZE.height -
					MAIN_WINDOW_BUTTON_SIZE.h -
					DEFAULT_BUTTON_OUTLINE_THICKNESS -
					MAIN_WINDOW_VERTICAL_SPACE_BETWEEN_TWO_BUTTONS -
					(MAIN_WINDOW_BUTTON_SIZE.h +
						DEFAULT_BUTTON_OUTLINE_THICKNESS * 2.0f +
							MAIN_WINDOW_VERTICAL_SPACE_BETWEEN_TWO_BUTTONS)
								* static_cast<float>(y)),
			MAIN_WINDOW_BUTTONS_LABELS[i].empty() ? 
				to_string(i) : MAIN_WINDOW_BUTTONS_LABELS[i]);

	return buttons;
}

void drawButton(RenderWindow& window, Button& button)
{
	window.draw(button.displayButton());
	window.draw(button.displayText());
}

void drawUIbuttons(RenderWindow& window, array<Button*, MAIN_WINDOW_NUMBER_OF_BUTTONS>* buttons)
{
	for (auto& button : *buttons)
		drawButton(window, *button);
}

DialogBox* createUIdialogbox()
{
	return new DialogBox(MAIN_WINDOW_DIALOGBOX_SIZE,
		Point2D(MAIN_WINDOW_HORIZONTAL_SPACE_BETWEEN_TWO_BUTTONS +
					DEFAULT_BUTTON_OUTLINE_THICKNESS,
				MAIN_WINDOW_VERTICAL_SPACE_BETWEEN_TWO_BUTTONS +
					DEFAULT_BUTTON_OUTLINE_THICKNESS),
				"");
}

void drawUIdialogbox(RenderWindow& window, DialogBox* dialogbox)
{
	window.draw(dialogbox->displayButton());
	window.draw(dialogbox->displayText());
}

InputBox* createUIinputbox()
{
	return new InputBox(MAIN_WINDOW_DIALOGBOX_SIZE,
		Point2D(MAIN_WINDOW_HORIZONTAL_SPACE_BETWEEN_TWO_BUTTONS +
					DEFAULT_BUTTON_OUTLINE_THICKNESS,
				MAIN_WINDOW_DIALOGBOX_SIZE.h +
					MAIN_WINDOW_VERTICAL_SPACE_BETWEEN_TWO_BUTTONS * 2.0f +
					DEFAULT_BUTTON_OUTLINE_THICKNESS * 3.0f),
				"0");
}

void drawUIinputbox(RenderWindow& window, InputBox* inputbox)
{
	window.draw(inputbox->displayButton());
	window.draw(inputbox->displayText());
}

void checkButtons(array<Button*, MAIN_WINDOW_NUMBER_OF_BUTTONS>* buttons, const Vector2i& mouse)
{
	for (auto button : *buttons)
		button->select(mouse);
}