#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <sstream>
#include <iomanip>
#include <cmath>
#include "Point2D.h"
#include "Size2D.h"
#include "Label.h"
#include "Button.h"
#include "InputBox.h"
#include "DialogBox.h"
#include "constants.h"
#include "user_interface.h"
#include "operations.h"
#include "engine.h"
#include "Calculator.h"

using namespace std;
using namespace sf;
using namespace defaultValues;
using namespace constants::mainWindow;

void calculator()
{
	Calculator app;
	app.launch();
}

int main()
{
	calculator();
}