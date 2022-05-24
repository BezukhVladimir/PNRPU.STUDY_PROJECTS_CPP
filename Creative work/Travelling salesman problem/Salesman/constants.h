#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "Size2D.h"
#include "Point2D.h"

using namespace std;
using namespace sf;

namespace themes
{
	enum class Theme {
		DARK,
		LIGHT
	};

	namespace dark {
		const Color WINDOW_BACKGROUND_COLOR(30, 30, 30);

		const Color ROUTE_COLOR(100, 100, 100);
		const Color BEST_ROUTE_COLOR(Color::Magenta);
		const Color NODES_COLOR(150, 150, 150);

		const Color BUTTON_FILL_COLOR(150, 150, 150);
		const Color BUTTON_HOVERED_FILL_COLOR(Color::Magenta);
		const Color BUTTON_OUTLINE_COLOR(Color::Black);
		const Color BUTTON_TEXT_COLOR(Color::White);

		const Color LABEL_COLOR(Color::White);
		const string DARK_LABEL = "D";
	}

	namespace light {
		const Color WINDOW_BACKGROUND_COLOR(250, 250, 250);

		const Color ROUTE_COLOR(210, 210, 210);
		const Color BEST_ROUTE_COLOR(Color::Cyan);
		const Color NODES_COLOR(50, 50, 50);

		const Color BUTTON_FILL_COLOR(230, 230, 230);
		const Color BUTTON_HOVERED_FILL_COLOR(Color::Cyan);
		const Color BUTTON_OUTLINE_COLOR(Color::Black);
		const Color BUTTON_TEXT_COLOR(Color::Black);

		const Color LABEL_COLOR(Color::Black);
		const string LIGHT_LABEL = "L";
	}
}

namespace defaultValues
{
	const string DEFAULT_FONT = "ttf/arialmt.ttf";
	const int    DEFAULT_FONT_SIZE = 30;
	const Color  DEFAULT_TEXT_COLOR(Color::White);
	const char   BACKSPACE = '\b';
	const char   ENTER = '\n';
	const double PI = 3.14159265359;
	const string DEFAULT_ICON = "icon/TSP.png";
}

namespace constants
{
	using namespace defaultValues;

	namespace parameters {
		const int DEFAULT_NUMBER_OF_NODES = 5;
		const float DEFAULT_CALCULATIONS_PER_SECOND = 25.0f;
	}

	namespace label {
		const string DEFAULT_LABEL_DATA = "label";
		const string DEFAULT_LABEL_FONT = DEFAULT_FONT;
		const int    DEFAULT_LABEL_FONT_SIZE = DEFAULT_FONT_SIZE;
		const Color  DEFAULT_LABEL_TEXT_COLOR = DEFAULT_TEXT_COLOR;
	}

	namespace button {
		namespace pause {
			const string DEFAULT_BUTTON_PAUSE_DATA = "Pause";
			const Size2D DEFAULT_BUTTON_PAUSE_SIZE(100.0f, 30.0f);
		}

		namespace changeTheme {
			const string DEFAULT_BUTTON_CHANGE_THEME_DATA = "D";
			const Size2D DEFAULT_BUTTON_CHANGE_THEME_SIZE(30.0f, 30.0f);
		}

		const string DEFAULT_BUTTON_DATA = "button";
		const Size2D DEFAULT_BUTTON_SIZE(30.0f, 30.0f);
		const Color  DEFAULT_BUTTON_FILL_COLOR(133, 133, 133);
		const Color  DEFAULT_BUTTON_HOVERED_FILL_COLOR(Color::Cyan);
		const float  DEFAULT_BUTTON_OUTLINE_THICKNESS = 1.0f;
		const Color  DEFAULT_BUTTON_OUTLINE_COLOR(Color::Black);
	}

	namespace edge {
		const float DEFAULT_EDGE_HEIGHT = 8.0f;
	}

	namespace node {
		const float DEFAULT_NODE_RADIUS = 16.0f;
		const Color	DEFAULT_NODE_COLOR(68, 68, 68);
	}

	namespace mainWindow {
		const string    MAIN_WINDOW_NAME = "Travelling Salesman Problem";
		const VideoMode MAIN_WINDOW_SIZE(1280, 720);

		const Point2D MAIN_WINDOW_BUTTON_PAUSE_POSITION(
			50.0f, MAIN_WINDOW_SIZE.height - 50.0f);
		const Point2D MAIN_WINDOW_UI_NODES_POSITION(
			175.0f, MAIN_WINDOW_SIZE.height - 50.0f);
		const Point2D MAIN_WINDOW_UI_CALCS_POSITION(
			325.0f, MAIN_WINDOW_SIZE.height - 50.0f);
		const Point2D MAIN_WINDOW_BUTTON_CHANGE_THEME_POSITION(
			MAIN_WINDOW_SIZE.width - 50.0f,
			MAIN_WINDOW_SIZE.height - 50.0f);
	}
}