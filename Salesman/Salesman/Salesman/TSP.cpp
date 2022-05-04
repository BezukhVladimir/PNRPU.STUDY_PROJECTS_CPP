#include "TSP.h"
#include <cmath>

using namespace constants::parameters;
using namespace constants::button::pause;
using namespace constants::button::changeTheme;

/*
const double M = -1.0;
typedef double ** Matrix;

bool equality(const double& left, const double& right) {
	return std::abs(left - right) < numeric_limits<double>::epsilon();
}

double TSP::subtractFromMatrix(Matrix* matrix)
{
	double subtract_sum = 0;
	for (int i = 0; i < number_of_nodes_; ++i) {
		double min = numeric_limits<double>::max();

		// нахождение минимумов по строкам
		for (int j = 0; j < number_of_nodes_; ++j)
			if (matrix[i][j]
				&& min > *matrix[i][j])
				min = *matrix[i][j];

		// редукция строк
		for (int j = 0; j < number_of_nodes_; ++j)
			if (matrix[i][j])
				*matrix[i][j] -= min;

		subtract_sum += min;
	}

	for (int j = 0; j < number_of_nodes_; ++j)
	{
		double min = numeric_limits<double>::max();

		// нахождение минимумов по столбцам
		for (int i = 0; i < number_of_nodes_; ++i)
			if (matrix[i][j]
				&& min > *matrix[i][j])
				min = *matrix[i][j];

		// редукция столбцов
		for (int i = 0; i < number_of_nodes_; ++i)
			if (matrix[i][j])
				*matrix[i][j] -= min;

		subtract_sum += min;
	}

	return subtract_sum;
}

void TSP::branchAndBoundMethod()
{
	initialAdjacencyMatrix();

	for (int l = 0; l < number_of_nodes_; ++l) {

		bottom_limit_ += subtractFromMatrix(adjacency_matrix_);

		for (int i = 0; i < number_of_nodes_; ++i)
			for (int j = 0; j < number_of_nodes_; ++j)
				grades_[i][j] = 0.0;

		// оценивание
		for (int i = 0; i < number_of_nodes_; ++i)
			for (int j = 0; j < number_of_nodes_; ++j) {
				if (adjacency_matrix_[i][j]
					&& equality(*adjacency_matrix_[i][j], 0.0)) {
					double hmin = numeric_limits<double>::max();
					double vmin = numeric_limits<double>::max();

					for (int l = 0; l < number_of_nodes_; ++l)
						if (l != i && adjacency_matrix_[l][j] && hmin > *adjacency_matrix_[l][j])
							hmin = *adjacency_matrix_[l][j];

					for (int l = 0; l < number_of_nodes_; ++l)
						if (l != j && adjacency_matrix_[i][l] && vmin > *adjacency_matrix_[i][l])
							vmin = *adjacency_matrix_[i][l];

					grades_[i][j] = hmin + vmin;
				}
			}

		double max_grade = 0.0;
		int mi = 0, mj = 0;
		for (int i = 0; i < number_of_nodes_; ++i)
			for (int j = 0; j < number_of_nodes_; ++j)
				if (adjacency_matrix_[i][j] && (max_grade < grades_[i][j])) {
					max_grade = grades_[i][j];
					mi = i;
					mj = j;
				}

		result_[mi] = mj;

		for (int i = 0; i < number_of_nodes_; ++i)
			adjacency_matrix_[i][mj] = nullptr;

		for (int j = 0; j < number_of_nodes_; ++j)
			adjacency_matrix_[mi][j] = nullptr;

		adjacency_matrix_[mj][mi] = nullptr;
	}

	// не хватает времени довести до ума
}

void TSP::initialAdjacencyMatrix()
{
	vector<Node*> nodes = map_.getNodes();

	bottom_limit_ = 0.0;
	record_ = numeric_limits<double>::max();

	adjacency_matrix_ = new double** [number_of_nodes_];
	grades_ = new double* [number_of_nodes_];

	for (int i = 0; i != nodes.size(); ++i)
		result_.emplace_back(-1);

	for (int i = 0; i < number_of_nodes_; ++i)
		grades_[i] = new double[number_of_nodes_];

	for (int i = 0; i < number_of_nodes_; ++i) {
		adjacency_matrix_[i] = new double*[number_of_nodes_];

		for (int j = 0; j < number_of_nodes_; ++j)
		{	
			double distance = nodes[i]->distance(nodes[j]);
			if (equality(distance, 0.0)) {
				adjacency_matrix_[i][j] = nullptr;
				continue;
			}

			adjacency_matrix_[i][j] = new double(distance);
		}
	}
}*/

void TSP::initialValues(const int& number_of_nodes = DEFAULT_NUMBER_OF_NODES,
						const float& calculations_per_second = DEFAULT_CALCULATIONS_PER_SECOND)
{
	main_window_settings_.antialiasingLevel = 8;
	main_window_.create(MAIN_WINDOW_SIZE, MAIN_WINDOW_NAME,
		Style::Close | Style::Titlebar,
		main_window_settings_);
	main_window_.setKeyRepeatEnabled(false);
	main_window_.setVerticalSyncEnabled(true);

	if (!main_window_icon_.loadFromFile(DEFAULT_ICON)) {
		cerr << "DEFAULT ICON NOT FOUND!";
	}
	main_window_.setIcon(main_window_icon_.getSize().x,
		main_window_icon_.getSize().y, main_window_icon_.getPixelsPtr());

	need_recover_theme_ = false;
	paused_ = false;
	number_of_nodes_ = number_of_nodes;
	calculations_per_second_ = calculations_per_second;

	map_.create(number_of_nodes_, main_window_);

	if (current_theme_ == Theme::DARK)
	{
		route_.create(map_, themes::dark::ROUTE_COLOR);
		best_route_.create(map_, themes::dark::BEST_ROUTE_COLOR);
	}
	else if (current_theme_ == Theme::LIGHT) {
		route_.create(map_, themes::light::ROUTE_COLOR);
		best_route_.create(map_, themes::light::BEST_ROUTE_COLOR);
	}

	best_distance_ = numeric_limits<int>::max();

	next_iteration_ = true;

	calculation_counter_ = 0;
	total_calculations_ = 1;

	for (int i = 1; i < number_of_nodes_; ++i)
		total_calculations_ *= i;

	button_change_theme_.changeCoord(MAIN_WINDOW_BUTTON_CHANGE_THEME_POSITION);
	button_change_theme_.changeBoxSize(DEFAULT_BUTTON_CHANGE_THEME_SIZE);
	button_change_theme_.data = DEFAULT_BUTTON_CHANGE_THEME_DATA;

	button_pause_.changeCoord(MAIN_WINDOW_BUTTON_PAUSE_POSITION);
	button_pause_.changeBoxSize(DEFAULT_BUTTON_PAUSE_SIZE);
	button_pause_.data = DEFAULT_BUTTON_PAUSE_DATA;

	ui_number_of_nodes_.init(MAIN_WINDOW_UI_NODES_POSITION, number_of_nodes_);
	ui_calculations_per_second_.init(MAIN_WINDOW_UI_CALCS_POSITION, calculations_per_second_);
}

TSP::TSP()
{
	initialValues();
}

void TSP::launch()
{
	changeTheme(Theme::DARK);
	while (main_window_.isOpen())
	{
		handleEvent();

		if (!paused_ && next_iteration_)
			solve();

		if (need_recover_theme_) {
			need_recover_theme_ = false;
			changeTheme(current_theme_);
		}
		frameRendering();
	}
}

void TSP::handleEvent()
{
	while (main_window_.pollEvent(event_))
	{
		if (event_.type == Event::Closed)
			eventClosed();
		else if (event_.type == Event::KeyPressed)
			eventKeyPressed();
		else if (event_.type == Event::KeyReleased)
			eventKeyReleased();
		else if (event_.type == Event::MouseButtonPressed)
			eventMouseButtonPressed();
		else if (event_.type == Event::TextEntered)
			eventTextEntered();
		else if (event_.type == Event::MouseMoved)
			eventMouseMoved();
	}
}

void TSP::eventClosed()
{
	main_window_.close();
}

void TSP::eventMouseMoved()
{
	mouse_ = Mouse::getPosition(main_window_);
	button_pause_.isHovered(mouse_);
	button_change_theme_.isHovered(mouse_);
	ui_number_of_nodes_.isHovered(mouse_);
	ui_calculations_per_second_.isHovered(mouse_);
}

void TSP::eventKeyPressedCopyPaste()
{
	// Ctrl + C (copy)
	if (event_.key.control && event_.key.code == Keyboard::C) {
		// Clipboard::setString(copy);
	}
	// Ctrl + V (paste)
	else if (event_.key.control && event_.key.code == Keyboard::V) {
		// string paste = Clipboard::getString();
	}
}

void TSP::eventKeyPressed()
{
	eventKeyPressedCopyPaste();
}

void TSP::eventKeyReleased()
{

}

void TSP::eventMouseButtonPressed()
{
	mouse_ = Mouse::getPosition(main_window_);

	if (event_.mouseButton.button == sf::Mouse::Left)
	{
		if (button_pause_.isHovered(mouse_)) {
			if (!next_iteration_)
				initialValues();
			else if (paused_)
				paused_ = false;
			else
				paused_ = true;
		}

		if (button_change_theme_.isHovered(mouse_)) {
			using namespace themes;
			need_recover_theme_ = true;

			if (current_theme_ == Theme::DARK)
				current_theme_ = Theme::LIGHT;
			else if (current_theme_ == Theme::LIGHT)
				current_theme_ = Theme::DARK;
		}

		if (ui_number_of_nodes_.button_increment_.isHovered(mouse_)) {
			if (number_of_nodes_ < 10)
				++number_of_nodes_;

			initialValues(number_of_nodes_, calculations_per_second_);
			need_recover_theme_ = true;
		}
		else if (ui_number_of_nodes_.button_decrement_.isHovered(mouse_)) {
			if (number_of_nodes_ > 1)
				--number_of_nodes_;

			initialValues(number_of_nodes_, calculations_per_second_);
			need_recover_theme_ = true;
		}

		if (ui_calculations_per_second_.button_increment_.isHovered(mouse_)) {
			if (calculations_per_second_ < 100.0f)
				calculations_per_second_ *= 2.0f;

			initialValues(number_of_nodes_, calculations_per_second_);
			need_recover_theme_ = true;
		}
		else if (ui_calculations_per_second_.button_decrement_.isHovered(mouse_)) {
			if (calculations_per_second_ > 2.0f)
				calculations_per_second_ /= 2.0f;

			initialValues(number_of_nodes_, calculations_per_second_);
			need_recover_theme_ = true;
			cout << need_recover_theme_;
		}
	}
}

void TSP::eventTextEntered()
{
	if (event_.text.unicode < 128) {
	}
}

void TSP::solve()
{
	if (clock_.getElapsedTime().asSeconds() > 1.0f /
		calculations_per_second_) {
		clock_.restart();

		if (next_iteration_)
		{
			next_iteration_ = !route_.nextLexicOrder();
			calculation_counter_++;
		}

		route_.updateEdges();
		int distance = floor(route_.calcDistance());
		
		if (distance < best_distance_)
		{
			best_distance_ = distance;
			route_.copyOrder(&best_route_);
			best_route_.updateEdges();
		}

	    percent_done_ = calculation_counter_ * 1.0f / total_calculations_ * 100.0f;
		label_result_.data = ("Distance: " + std::to_string(distance) +
			" Best distance: " + std::to_string(best_distance_) +
			"\n" + std::to_string(percent_done_) + "% done");
	}
}

void TSP::drawLabel(RenderWindow& window, Label& label)
{
	window.draw(label.getText());
}

void TSP::drawButton(RenderWindow& window, Button& button)
{
	button.fixedLabel();
	window.draw(button.getBox());
	window.draw(button.getText());
}

void TSP::drawNumericUpDown(RenderWindow& window, NumericUpDown& button)
{
	drawLabel(window, button.label_);
	drawButton(window, button.button_decrement_);
	drawButton(window, button.button_increment_);
}

void TSP::setDarkTheme() {
	using namespace themes::dark;

	current_theme_ = Theme::DARK;
	main_window_color_ = WINDOW_BACKGROUND_COLOR;

	route_.changeColor(ROUTE_COLOR);
	best_route_.changeColor(BEST_ROUTE_COLOR);
	map_.changeColor(NODES_COLOR);
	
	button_pause_.changeBoxFillColor(
		BUTTON_FILL_COLOR,
		BUTTON_HOVERED_FILL_COLOR);
	button_pause_.changeTextColor(BUTTON_TEXT_COLOR);

	button_change_theme_.changeBoxFillColor(
		BUTTON_FILL_COLOR,
		BUTTON_HOVERED_FILL_COLOR);
	button_change_theme_.changeTextColor(BUTTON_TEXT_COLOR);
	button_change_theme_.data = DARK_LABEL;

	ui_number_of_nodes_.changeLabelsColor(BUTTON_TEXT_COLOR);
	ui_number_of_nodes_.changeButtonsColor(
		BUTTON_FILL_COLOR,
		BUTTON_HOVERED_FILL_COLOR);

	ui_calculations_per_second_.changeLabelsColor(BUTTON_TEXT_COLOR);
	ui_calculations_per_second_.changeButtonsColor(
		BUTTON_FILL_COLOR,
		BUTTON_HOVERED_FILL_COLOR);

	label_result_.changeTextColor(LABEL_COLOR);
}

void TSP::setLightTheme() {
	using namespace themes::light;
	
	current_theme_ = Theme::LIGHT;
	main_window_color_ = WINDOW_BACKGROUND_COLOR;

	route_.changeColor(ROUTE_COLOR);
	best_route_.changeColor(BEST_ROUTE_COLOR);
	map_.changeColor(NODES_COLOR);

	button_pause_.changeBoxFillColor(
		BUTTON_FILL_COLOR,
		BUTTON_HOVERED_FILL_COLOR);
	button_pause_.changeTextColor(BUTTON_TEXT_COLOR);

	button_change_theme_.changeBoxFillColor(
		BUTTON_FILL_COLOR,
		BUTTON_HOVERED_FILL_COLOR);
	button_change_theme_.changeTextColor(BUTTON_TEXT_COLOR);
	button_change_theme_.data = LIGHT_LABEL;

	ui_number_of_nodes_.changeLabelsColor(BUTTON_TEXT_COLOR);
	ui_number_of_nodes_.changeButtonsColor(
		BUTTON_FILL_COLOR,
		BUTTON_HOVERED_FILL_COLOR);

	ui_calculations_per_second_.changeLabelsColor(BUTTON_TEXT_COLOR);
	ui_calculations_per_second_.changeButtonsColor(
		BUTTON_FILL_COLOR,
		BUTTON_HOVERED_FILL_COLOR);

	label_result_.changeTextColor(LABEL_COLOR);
}

void TSP::changeTheme(const Theme& theme)
{
	switch (theme) {
	case Theme::DARK:
		setDarkTheme();
		break;
	case Theme::LIGHT:
		setLightTheme();
		break;
	default:
		setDarkTheme();
		break;
	}
}

void TSP::frameRendering()
{
	main_window_.clear(main_window_color_);

	if (next_iteration_)
		route_.drawEdges(main_window_);
	else
		best_route_.drawEdges(main_window_);

	map_.drawMap(main_window_);

	drawLabel(main_window_, label_result_);

	drawButton(main_window_, button_pause_);
	drawButton(main_window_, button_change_theme_);

	drawNumericUpDown(main_window_, ui_number_of_nodes_);
	drawNumericUpDown(main_window_, ui_calculations_per_second_);

	main_window_.display();
}