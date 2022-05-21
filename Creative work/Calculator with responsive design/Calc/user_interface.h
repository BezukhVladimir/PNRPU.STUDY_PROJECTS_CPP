#pragma once
#include <array>
#include <SFML/Graphics.hpp>
#include "Size2D.h"
#include "Point2D.h"
#include "Label.h"
#include "Button.h"
#include "InputBox.h"
#include "DialogBox.h"

using namespace std;
using namespace sf;
using namespace defaultValues;
using namespace constants::mainWindow;
using namespace constants::label;
using namespace constants::button;
using namespace constants::inputBox;

array<Button*, MAIN_WINDOW_NUMBER_OF_BUTTONS>* createUIbuttons();
void drawButton(RenderWindow&, Button&);
void drawUIbuttons(RenderWindow&, array<Button*, MAIN_WINDOW_NUMBER_OF_BUTTONS>*);

DialogBox* createUIdialogbox();
void drawUIdialogbox(RenderWindow&, DialogBox*);

InputBox* createUIinputbox();
void drawUIinputbox(RenderWindow&, InputBox*);

// mouse hover engine
void checkButtons(array<Button*, MAIN_WINDOW_NUMBER_OF_BUTTONS>*, const Vector2i&);