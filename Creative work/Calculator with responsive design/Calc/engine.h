#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <sstream>
#include <iomanip>
#include "operations.h"
#include "Point2D.h"
#include "Size2D.h"
#include "Label.h"
#include "Button.h"
#include "InputBox.h"
#include "DialogBox.h"
#include "constants.h"
#include "user_interface.h"

using namespace std;
using namespace sf;
using namespace defaultValues;
using namespace constants;

void setOperation(DialogBox*, const string&);
void emptyDialog(DialogBox*, InputBox*, const string&);
void calculate(DialogBox*, InputBox*);
void simpleEvent(DialogBox*, InputBox*, const string&);
void solveEvent(DialogBox*, InputBox*);
void clearEvent(DialogBox*, InputBox*, const string&);
void fixedSetprecision(DialogBox*, InputBox*);
void fixedInput(InputBox*);
void fixedDialog(DialogBox*);