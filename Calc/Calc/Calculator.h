#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <array>
#include "InputBox.h"
#include "DialogBox.h"
#include "constants.h"
#include "user_interface.h"
#include "operations.h"
#include "engine.h"

using namespace std;
using namespace sf;
using namespace defaultValues;
using namespace constants::mainWindow;

class Calculator
{
private:
	// window
	RenderWindow main_window;
	Image icon;

	// UI
	array<Button*, MAIN_WINDOW_NUMBER_OF_BUTTONS>* ptr_UI_buttons;
	DialogBox* ptr_dialogbox_result;
	InputBox* ptr_inputbox_user_data;

	// UX
	Event event;
	Vector2i mouse;

public:
	Calculator();
	void launch();

private:
	void handleEvent();
	void eventClosed();
	void eventMouseMoved();
	void eventKeyPressedCopyPaste();
	void eventKeyPressedFuncion();
	void eventKeyPressedSpecial();
	void eventKeyPressedInput();
	void eventKeyPressed();
	void eventKeyReleasedFuncion();
	void eventKeyReleasedSpecial();
	void eventKeyReleasedInput();
	void eventKeyReleased();
	void eventMouseButtonPressedLeftFunction();
	void eventMouseButtonPressedLeftSpecial();
	void eventMouseButtonPressedLeftInput();
	void eventMouseButtonPressedLeft();
	void eventMouseButtonPressed();
	void eventTextEntered();
	void frameRendering();
};