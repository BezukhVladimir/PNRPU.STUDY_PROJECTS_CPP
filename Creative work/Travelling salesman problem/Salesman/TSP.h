#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "constants.h"
#include "Label.h"
#include "Map.h"
#include "Edge.h"
#include "Route.h"
#include "Node.h"
#include "Button.h"
#include "NumericUpDown.h"

using namespace std;
using namespace sf;
using namespace defaultValues;
using namespace constants::mainWindow;
using namespace themes;

// Travelling Salesman Problem
class TSP
{
private:
	// window
	RenderWindow    main_window_;
	ContextSettings main_window_settings_;
	Image main_window_icon_;

	// parameters
	int   number_of_nodes_;
	float calculations_per_second_;

	// variables      
	bool paused_;
	int  best_distance_;       // best route
	int  percent_done_;        // progress
	bool next_iteration_;
	int  calculation_counter_;
	int  total_calculations_;

	// branch and bound method
	/*typedef double ** Matrix;
	Matrix* adjacency_matrix_;
	Matrix  grades_;
	vector<int> result_;
	double  bottom_limit_;
	double  record_;*/

	// UI
	Map    map_;
	Route  route_;
	Route  best_route_;
	Label  label_result_;
	Button button_pause_;
	Button button_change_theme_;
	NumericUpDown ui_number_of_nodes_;
	NumericUpDown ui_calculations_per_second_;
	Color main_window_color_;
	Theme current_theme_;

	// UX
	Event    event_;
	Clock    clock_;
	Vector2i mouse_;
	bool need_recover_theme_;

public:
	TSP();
	void launch();

private:
	void initialAdjacencyMatrix();
	void initialValues(const int& number_of_nodes,
					   const float& calculations_per_second);
	
	void handleEvent();
	void eventClosed();
	void eventMouseMoved();
	void eventKeyPressedCopyPaste();
	void eventKeyPressed();
	void eventKeyReleased();
	void eventMouseButtonPressed();
	void eventTextEntered();
	
	/*void branchAndBoundMethod();
	double subtractFromMatrix(Matrix* matrix);*/
	void solve();
	
	void setLightTheme();
	void setDarkTheme();
	void changeTheme(const Theme& theme);

	void drawLabel(RenderWindow&, Label&);
	void drawButton(RenderWindow&, Button&);
	void drawNumericUpDown(RenderWindow&, NumericUpDown&);
	void frameRendering();
};