#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "Size2D.h"
#include "Point2D.h"

using namespace std;
using namespace sf;

namespace defaultValues
{
	const string DEFAULT_FONT = "ttf/arialmt.ttf";
	const int    DEFAULT_FONT_SIZE = 38;
	const Color  DEFAULT_TEXT_COLOR(Color::White);
	const char   BACKSPACE = '\b';
	const char   ENTER = '\n';
	const string PI = "3.141593";
	const string DEFAULT_ICON = "icon/calculator.png";
}

namespace constants
{
	using namespace defaultValues;

	namespace label {
		const string DEFAULT_LABEL_DATA = "label";
		const string DEFAULT_LABEL_FONT = DEFAULT_FONT;
		const int    DEFAULT_LABEL_FONT_SIZE = DEFAULT_FONT_SIZE;
		const Color  DEFAULT_LABEL_TEXT_COLOR = DEFAULT_TEXT_COLOR;
	}

	namespace button {
		const string DEFAULT_BUTTON_DATA = "button";
		const Size2D DEFAULT_BUTTON_SIZE(150.0f, 30.0f);
		const Color  DEFAULT_BUTTON_FILL_COLOR(133, 133, 133);
		const Color  HOVER_BUTTON_FILL_COLOR(Color::Cyan);
		const float  DEFAULT_BUTTON_OUTLINE_THICKNESS = 2.0f;
		const Color  DEFAULT_BUTTON_OUTLINE_COLOR(Color::Black);
	}

	namespace inputBox {
		const string DEFAULT_INPUTBOX_DATA = "inputbox";
		const Size2D DEFAULT_INPUTBOX_SIZE(150.0f, 30.0f);
		const Color  DEFAULT_INPUTBOX_FONT_COLOR(Color::White);
		const Color  DEFAULT_INPUTBOX_FILL_COLOR(133, 133, 133);
		const Color  DEFUALT_INPUTBOX_FOCUS_OUTLINE_COLOR(Color::Cyan);
		const char   INPUTBOX_LAST_CHAR = '|';
	}

	namespace mainWindow {
		const string    MAIN_WINDOW_NAME = "Calculator";
		const VideoMode MAIN_WINDOW_SIZE(480, 627);
		const Color     MAIN_WINDOW_BACKGROUND_COLOR(Color::White);

		const float     MAIN_WINDOW_NUMBER_OF_DIALOGBOX = 2.0f;

		// UI buttons
		const Size2D    MAIN_WINDOW_BUTTON_SIZE(111.0f, 69.0f);
		const size_t    MAIN_WINDOW_NUMBER_OF_BUTTONS_IN_A_ROW = size_t{4};
		const size_t    MAIN_WINDOW_NUMBER_OF_BUTTONS_IN_A_COLUMN = size_t{6};
		const size_t    MAIN_WINDOW_NUMBER_OF_BUTTONS =
							MAIN_WINDOW_NUMBER_OF_BUTTONS_IN_A_ROW *
							MAIN_WINDOW_NUMBER_OF_BUTTONS_IN_A_COLUMN;

		const string MAIN_WINDOW_BUTTONS_LABELS[MAIN_WINDOW_NUMBER_OF_BUTTONS] =
							{"-x", "0", ".", "=",
							 "1", "2", "3", "+",
							 "4", "5", "6", "-",
							 "7", "8", "9", "*",
							 "CE", "C", "<", "/",
							 "Pi", "1/x", "^", "%" };

		const float     MAIN_WINDOW_HORIZONTAL_SPACE_BETWEEN_TWO_BUTTONS =
							(MAIN_WINDOW_SIZE.width -
								(MAIN_WINDOW_NUMBER_OF_BUTTONS_IN_A_ROW *
									(MAIN_WINDOW_BUTTON_SIZE.w +
										constants::button::DEFAULT_BUTTON_OUTLINE_THICKNESS * 2.0f))) /
							(MAIN_WINDOW_NUMBER_OF_BUTTONS_IN_A_ROW + 1.0f);

		const float     MAIN_WINDOW_VERTICAL_SPACE_BETWEEN_TWO_BUTTONS =
							(MAIN_WINDOW_SIZE.height -
								((MAIN_WINDOW_NUMBER_OF_BUTTONS_IN_A_COLUMN + MAIN_WINDOW_NUMBER_OF_DIALOGBOX) *
									(MAIN_WINDOW_BUTTON_SIZE.h +
										constants::button::DEFAULT_BUTTON_OUTLINE_THICKNESS * 2.0f))) /
							(MAIN_WINDOW_NUMBER_OF_BUTTONS_IN_A_COLUMN + MAIN_WINDOW_NUMBER_OF_DIALOGBOX + 1.0f);


		// UI inputbox
		const Size2D MAIN_WINDOW_DIALOGBOX_SIZE(MAIN_WINDOW_SIZE.width -
							constants::button::DEFAULT_BUTTON_OUTLINE_THICKNESS * 2.0f -
							MAIN_WINDOW_HORIZONTAL_SPACE_BETWEEN_TWO_BUTTONS * 2.0f,
						MAIN_WINDOW_BUTTON_SIZE.h);

		// UI dialogbox
		const string OVERLOAD = "overload (!)";
	}
}