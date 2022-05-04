#include "Calculator.h"

map<string, int> BUTTONS_IDS =
{ { "-x", 0  }, { "0",   1  }, { ".", 2  }, { "=", 3  },
  { "1",  4  }, { "2",   5  }, { "3", 6  }, { "+", 7  },
  { "4",  8  }, { "5",   9  }, { "6", 10 }, { "-", 11 },
  { "7",  12 }, { "8",   13 }, { "9", 14 }, { "*", 15 },
  { "CE", 16 }, { "C",   17 }, { "<", 18 }, { "/", 19 },
  { "Pi", 20 }, { "1/x", 21 }, { "^", 22 }, { "%", 23 } };

Calculator::Calculator()
{
	main_window.create(MAIN_WINDOW_SIZE, MAIN_WINDOW_NAME, Style::Close | Style::Titlebar);
	main_window.setKeyRepeatEnabled(false);
	main_window.setVerticalSyncEnabled(true);
	main_window.pollEvent(event);

	if (!icon.loadFromFile(DEFAULT_ICON))
	{
		cout << "DEFAULT ICON NOT FOUND!";
	}
	main_window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	ptr_UI_buttons = createUIbuttons();
	ptr_dialogbox_result = createUIdialogbox();
	ptr_inputbox_user_data = createUIinputbox();
}

void Calculator::launch()
{
	while (main_window.isOpen())
	{
		handleEvent();
		frameRendering();
	}
}

void Calculator::handleEvent()
{
	while (main_window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			eventClosed();
		else if (event.type == Event::MouseMoved)
			eventMouseMoved();
		else if (event.type == Event::KeyPressed)
			eventKeyPressed();
		else if (event.type == Event::KeyReleased)
			eventKeyReleased();
		else if (event.type == Event::MouseButtonPressed)
			eventMouseButtonPressed();
		else if (event.type == Event::TextEntered)
			eventTextEntered();
	}
}

void Calculator::eventClosed()
{
	main_window.close();
}

void Calculator::eventMouseMoved()
{
	mouse = Mouse::getPosition(main_window);
	checkButtons(ptr_UI_buttons, mouse);
}

void Calculator::eventKeyPressedCopyPaste()
{
	// Ctrl + C (copy)
	if (event.key.control && event.key.code == Keyboard::C) {
		fixedDialog(ptr_dialogbox_result);
		string copy = ptr_dialogbox_result->data;
		Clipboard::setString(copy);
	}
	// Ctrl + V (paste)
	else if (event.key.control && event.key.code == Keyboard::V) {
		string paste = Clipboard::getString();
		clearEvent(ptr_dialogbox_result, ptr_inputbox_user_data, "CE");
		for (const auto& c : paste)
			ptr_inputbox_user_data->reText(c);

		fixedInput(ptr_inputbox_user_data);
	}
}

void Calculator::eventKeyPressedFuncion()
{
	if (event.key.code == Keyboard::A) {
		simpleEvent(ptr_dialogbox_result,
			ptr_inputbox_user_data,
			"+");
		(*ptr_UI_buttons)[BUTTONS_IDS["+"]]->press();
	}
	else if (event.key.code == Keyboard::S) {
		simpleEvent(ptr_dialogbox_result,
			ptr_inputbox_user_data,
			"-");
		(*ptr_UI_buttons)[BUTTONS_IDS["-"]]->press();
	}
	else if (event.key.code == Keyboard::M) {
		simpleEvent(ptr_dialogbox_result,
			ptr_inputbox_user_data,
			"*");
		(*ptr_UI_buttons)[BUTTONS_IDS["*"]]->press();
	}
	else if (event.key.code == Keyboard::D) {
		simpleEvent(ptr_dialogbox_result,
			ptr_inputbox_user_data,
			"/");
		(*ptr_UI_buttons)[BUTTONS_IDS["/"]]->press();
	}
	else if (event.key.code == Keyboard::R) {
		simpleEvent(ptr_dialogbox_result,
			ptr_inputbox_user_data,
			"%");
		(*ptr_UI_buttons)[BUTTONS_IDS["%"]]->press();
	}
	else if (event.key.code == Keyboard::P) {
		simpleEvent(ptr_dialogbox_result,
			ptr_inputbox_user_data,
			"^");
		(*ptr_UI_buttons)[BUTTONS_IDS["^"]]->press();
	}
	else if (event.key.code == Keyboard::I) {
		string tmp = to_string(myInverse(stod(ptr_inputbox_user_data->data)));
		clearEvent(ptr_dialogbox_result, ptr_inputbox_user_data, "CE");
		for (const auto& c : tmp)
			ptr_inputbox_user_data->reText(c);

		fixedInput(ptr_inputbox_user_data);
		(*ptr_UI_buttons)[BUTTONS_IDS["1/x"]]->press();
	}
}

void Calculator::eventKeyPressedSpecial()
{
	if (event.key.code == Keyboard::Enter) {
		solveEvent(ptr_dialogbox_result, ptr_inputbox_user_data);
		(*ptr_UI_buttons)[BUTTONS_IDS["="]]->press();
	}
	else if (event.key.code == Keyboard::Delete) {
		clearEvent(ptr_dialogbox_result, ptr_inputbox_user_data, "CE");
		(*ptr_UI_buttons)[BUTTONS_IDS["CE"]]->press();
	}
	else if (event.key.code == Keyboard::Escape) {
		clearEvent(ptr_dialogbox_result, ptr_inputbox_user_data, "C");
		(*ptr_UI_buttons)[BUTTONS_IDS["C"]]->press();
	}
	else if (event.key.code == Keyboard::C) {
		clearEvent(ptr_dialogbox_result, ptr_inputbox_user_data, "CE");
		for (const auto& c : PI) {
			ptr_inputbox_user_data->reText(c);
		}
		(*ptr_UI_buttons)[BUTTONS_IDS["Pi"]]->press();
	}
}

void Calculator::eventKeyPressedInput()
{
	if (event.key.code == Keyboard::Hyphen) {
		if (!ptr_inputbox_user_data->select())
			ptr_inputbox_user_data->reText('-');
		(*ptr_UI_buttons)[BUTTONS_IDS["-x"]]->press();
	}
	else if (event.key.code == Keyboard::Backspace) {
		if (!ptr_inputbox_user_data->select())
			ptr_inputbox_user_data->reText(BACKSPACE);
		(*ptr_UI_buttons)[BUTTONS_IDS["<"]]->press();
	}
	else if (event.key.code == Keyboard::Period) {
		if (!ptr_inputbox_user_data->select())
			ptr_inputbox_user_data->reText('.');
		(*ptr_UI_buttons)[BUTTONS_IDS["."]]->press();
	}
	else if (event.key.code == Keyboard::Num0 ||
		event.key.code == Keyboard::Numpad0) {
		if (!ptr_inputbox_user_data->select())
			ptr_inputbox_user_data->reText('0');
		(*ptr_UI_buttons)[BUTTONS_IDS["0"]]->press();
	}
	else if (event.key.code == Keyboard::Num1 ||
		event.key.code == Keyboard::Numpad1) {
		if (!ptr_inputbox_user_data->select())
			ptr_inputbox_user_data->reText('1');
		(*ptr_UI_buttons)[BUTTONS_IDS["1"]]->press();
	}
	else if (event.key.code == Keyboard::Num2 ||
		event.key.code == Keyboard::Numpad2) {
		if (!ptr_inputbox_user_data->select())
			ptr_inputbox_user_data->reText('2');
		(*ptr_UI_buttons)[BUTTONS_IDS["2"]]->press();
	}
	else if (event.key.code == Keyboard::Num3 ||
		event.key.code == Keyboard::Numpad3) {
		if (!ptr_inputbox_user_data->select())
			ptr_inputbox_user_data->reText('3');
		(*ptr_UI_buttons)[BUTTONS_IDS["3"]]->press();
	}
	else if (event.key.code == Keyboard::Num4 ||
		event.key.code == Keyboard::Numpad4) {
		if (!ptr_inputbox_user_data->select())
			ptr_inputbox_user_data->reText('4');
		(*ptr_UI_buttons)[BUTTONS_IDS["4"]]->press();
	}
	else if (event.key.code == Keyboard::Num5 ||
		event.key.code == Keyboard::Numpad5) {
		if (!ptr_inputbox_user_data->select())
			ptr_inputbox_user_data->reText('5');
		(*ptr_UI_buttons)[BUTTONS_IDS["5"]]->press();
	}
	else if (event.key.code == Keyboard::Num6 ||
		event.key.code == Keyboard::Numpad6) {
		if (!ptr_inputbox_user_data->select())
			ptr_inputbox_user_data->reText('6');
		(*ptr_UI_buttons)[BUTTONS_IDS["6"]]->press();
	}
	else if (event.key.code == Keyboard::Num7 ||
		event.key.code == Keyboard::Numpad7) {
		if (!ptr_inputbox_user_data->select())
			ptr_inputbox_user_data->reText('7');
		(*ptr_UI_buttons)[BUTTONS_IDS["7"]]->press();
	}
	else if (event.key.code == Keyboard::Num8 ||
		event.key.code == Keyboard::Numpad8) {
		if (!ptr_inputbox_user_data->select())
			ptr_inputbox_user_data->reText('8');
		(*ptr_UI_buttons)[BUTTONS_IDS["8"]]->press();
	}
	else if (event.key.code == Keyboard::Num9 ||
		event.key.code == Keyboard::Numpad9) {
		if (!ptr_inputbox_user_data->select())
			ptr_inputbox_user_data->reText('9');
		(*ptr_UI_buttons)[BUTTONS_IDS["9"]]->press();
	}
}

void Calculator::eventKeyPressed()
{
	eventKeyPressedCopyPaste();
	eventKeyPressedFuncion();
	eventKeyPressedSpecial();
	eventKeyPressedInput();
}

void Calculator::eventKeyReleasedFuncion()
{
	if (event.key.code == Keyboard::A)
		(*ptr_UI_buttons)[BUTTONS_IDS["+"]]->release();
	else if (event.key.code == Keyboard::S)
		(*ptr_UI_buttons)[BUTTONS_IDS["-"]]->release();
	else if (event.key.code == Keyboard::M)
		(*ptr_UI_buttons)[BUTTONS_IDS["*"]]->release();
	else if (event.key.code == Keyboard::D)
		(*ptr_UI_buttons)[BUTTONS_IDS["/"]]->release();
	else if (event.key.code == Keyboard::R)
		(*ptr_UI_buttons)[BUTTONS_IDS["%"]]->release();
	else if (event.key.code == Keyboard::P)
		(*ptr_UI_buttons)[BUTTONS_IDS["^"]]->release();
	else if (event.key.code == Keyboard::I)
		(*ptr_UI_buttons)[BUTTONS_IDS["1/x"]]->release();
}

void Calculator::eventKeyReleasedSpecial()
{
	if (event.key.code == Keyboard::Enter)
		(*ptr_UI_buttons)[BUTTONS_IDS["="]]->release();
	else if (event.key.code == Keyboard::Delete)
		(*ptr_UI_buttons)[BUTTONS_IDS["CE"]]->release();
	else if (event.key.code == Keyboard::Escape)
		(*ptr_UI_buttons)[BUTTONS_IDS["C"]]->release();
	else if (event.key.code == Keyboard::C)
		(*ptr_UI_buttons)[BUTTONS_IDS["Pi"]]->release();
}

void Calculator::eventKeyReleasedInput()
{
	if (event.key.code == Keyboard::Backspace)
		(*ptr_UI_buttons)[BUTTONS_IDS["<"]]->release();
	else if (event.key.code == Keyboard::Hyphen)
		(*ptr_UI_buttons)[BUTTONS_IDS["-x"]]->release();
	else if (event.key.code == Keyboard::Period)
		(*ptr_UI_buttons)[BUTTONS_IDS["."]]->release();
	else if (event.key.code == Keyboard::Num0 ||
		event.key.code == Keyboard::Numpad0)
		(*ptr_UI_buttons)[BUTTONS_IDS["0"]]->release();
	else if (event.key.code == Keyboard::Num1 ||
		event.key.code == Keyboard::Numpad1)
		(*ptr_UI_buttons)[BUTTONS_IDS["1"]]->release();
	else if (event.key.code == Keyboard::Num2 ||
		event.key.code == Keyboard::Numpad2)
		(*ptr_UI_buttons)[BUTTONS_IDS["2"]]->release();
	else if (event.key.code == Keyboard::Num3 ||
		event.key.code == Keyboard::Numpad3)
		(*ptr_UI_buttons)[BUTTONS_IDS["3"]]->release();
	else if (event.key.code == Keyboard::Num4 ||
		event.key.code == Keyboard::Numpad4)
		(*ptr_UI_buttons)[BUTTONS_IDS["4"]]->release();
	else if (event.key.code == Keyboard::Num5 ||
		event.key.code == Keyboard::Numpad5)
		(*ptr_UI_buttons)[BUTTONS_IDS["5"]]->release();
	else if (event.key.code == Keyboard::Num6 ||
		event.key.code == Keyboard::Numpad6)
		(*ptr_UI_buttons)[BUTTONS_IDS["6"]]->release();
	else if (event.key.code == Keyboard::Num7 ||
		event.key.code == Keyboard::Numpad7)
		(*ptr_UI_buttons)[BUTTONS_IDS["7"]]->release();
	else if (event.key.code == Keyboard::Num8 ||
		event.key.code == Keyboard::Numpad8)
		(*ptr_UI_buttons)[BUTTONS_IDS["8"]]->release();
	else if (event.key.code == Keyboard::Num9 ||
		event.key.code == Keyboard::Numpad9)
		(*ptr_UI_buttons)[BUTTONS_IDS["9"]]->release();
}

void Calculator::eventKeyReleased()
{ 
	eventKeyReleasedFuncion();
	eventKeyReleasedSpecial();
	eventKeyReleasedInput();
}

void Calculator::eventMouseButtonPressedLeftFunction()
{
	if ((*ptr_UI_buttons)[BUTTONS_IDS["+"]]->select(mouse))
		simpleEvent(ptr_dialogbox_result,
			ptr_inputbox_user_data,
			"+");
	else if ((*ptr_UI_buttons)[BUTTONS_IDS["-"]]->select(mouse))
		simpleEvent(ptr_dialogbox_result,
			ptr_inputbox_user_data,
			"-");
	else if ((*ptr_UI_buttons)[BUTTONS_IDS["*"]]->select(mouse))
		simpleEvent(ptr_dialogbox_result,
			ptr_inputbox_user_data,
			"*");
	else if ((*ptr_UI_buttons)[BUTTONS_IDS["/"]]->select(mouse))
		simpleEvent(ptr_dialogbox_result,
			ptr_inputbox_user_data,
			"/");
	else if ((*ptr_UI_buttons)[BUTTONS_IDS["%"]]->select(mouse))
		simpleEvent(ptr_dialogbox_result,
			ptr_inputbox_user_data,
			"%");
	else if ((*ptr_UI_buttons)[BUTTONS_IDS["^"]]->select(mouse))
		simpleEvent(ptr_dialogbox_result,
			ptr_inputbox_user_data,
			"^");
	else if ((*ptr_UI_buttons)[BUTTONS_IDS["1/x"]]->select(mouse)) {
		string tmp = to_string(myInverse(stod(ptr_inputbox_user_data->data)));
		clearEvent(ptr_dialogbox_result, ptr_inputbox_user_data, "CE");
		for (const auto& c : tmp)
			ptr_inputbox_user_data->reText(c);

		fixedInput(ptr_inputbox_user_data);
	}
}

void Calculator::eventMouseButtonPressedLeftSpecial()
{
	if ((*ptr_UI_buttons)[BUTTONS_IDS["="]]->select(mouse))
		solveEvent(ptr_dialogbox_result, ptr_inputbox_user_data);
	else if ((*ptr_UI_buttons)[BUTTONS_IDS["CE"]]->select(mouse))
		clearEvent(ptr_dialogbox_result, ptr_inputbox_user_data, "CE");
	else if ((*ptr_UI_buttons)[BUTTONS_IDS["C"]]->select(mouse))
		clearEvent(ptr_dialogbox_result, ptr_inputbox_user_data, "C");
	else if ((*ptr_UI_buttons)[BUTTONS_IDS["Pi"]]->select(mouse)) {
		clearEvent(ptr_dialogbox_result, ptr_inputbox_user_data, "CE");
		for (const auto& c : PI)
			ptr_inputbox_user_data->reText(c);
	}
}

void Calculator::eventMouseButtonPressedLeftInput()
{
	if ((*ptr_UI_buttons)[BUTTONS_IDS["-x"]]->select(mouse))
		ptr_inputbox_user_data->reText('-');
	else if ((*ptr_UI_buttons)[BUTTONS_IDS["<"]]->select(mouse))
		ptr_inputbox_user_data->reText(BACKSPACE);
	else if ((*ptr_UI_buttons)[BUTTONS_IDS["."]]->select(mouse))
		ptr_inputbox_user_data->reText('.');
	else if ((*ptr_UI_buttons)[BUTTONS_IDS["0"]]->select(mouse))
		ptr_inputbox_user_data->reText('0');
	else if ((*ptr_UI_buttons)[BUTTONS_IDS["1"]]->select(mouse))
		ptr_inputbox_user_data->reText('1');
	else if ((*ptr_UI_buttons)[BUTTONS_IDS["2"]]->select(mouse))
		ptr_inputbox_user_data->reText('2');
	else if ((*ptr_UI_buttons)[BUTTONS_IDS["3"]]->select(mouse))
		ptr_inputbox_user_data->reText('3');
	else if ((*ptr_UI_buttons)[BUTTONS_IDS["4"]]->select(mouse))
		ptr_inputbox_user_data->reText('4');
	else if ((*ptr_UI_buttons)[BUTTONS_IDS["5"]]->select(mouse))
		ptr_inputbox_user_data->reText('5');
	else if ((*ptr_UI_buttons)[BUTTONS_IDS["6"]]->select(mouse))
		ptr_inputbox_user_data->reText('6');
	else if ((*ptr_UI_buttons)[BUTTONS_IDS["7"]]->select(mouse))
		ptr_inputbox_user_data->reText('7');
	else if ((*ptr_UI_buttons)[BUTTONS_IDS["8"]]->select(mouse))
		ptr_inputbox_user_data->reText('8');
	else if ((*ptr_UI_buttons)[BUTTONS_IDS["9"]]->select(mouse))
		ptr_inputbox_user_data->reText('9');
	else
		ptr_inputbox_user_data->select(mouse);
}

void Calculator::eventMouseButtonPressedLeft()
{
	mouse = Mouse::getPosition(main_window);

	eventMouseButtonPressedLeftFunction();
	eventMouseButtonPressedLeftSpecial();
	eventMouseButtonPressedLeftInput();
}

void Calculator::eventMouseButtonPressed()
{
	if (event.mouseButton.button == Mouse::Left)
		eventMouseButtonPressedLeft();
}

void Calculator::eventTextEntered()
{
	if (event.text.unicode < 128)
	{
		if ('0' <= event.text.unicode && event.text.unicode <= '9'
			|| event.text.unicode == BACKSPACE
			|| event.text.unicode == '.'
			|| event.text.unicode == '-') {
			if (ptr_inputbox_user_data->select()) {
				ptr_inputbox_user_data->reText(event.text.unicode);
			}
		}
	}
}

void Calculator::frameRendering()
{
	main_window.clear(MAIN_WINDOW_BACKGROUND_COLOR);
	drawUIbuttons(main_window, ptr_UI_buttons);
	drawUIinputbox(main_window, ptr_inputbox_user_data);
	drawUIdialogbox(main_window, ptr_dialogbox_result);
	main_window.display();
}