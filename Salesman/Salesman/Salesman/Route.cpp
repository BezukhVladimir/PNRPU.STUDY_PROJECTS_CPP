#include <iostream>
#include <random>
#include <algorithm>
#include "Route.h"

Route::Route() {}

void Route::create(Map& map, sf::Color color)
{
	map_ = &map;
	number_of_nodes_ = map.getNodeCount();
	order_ = new int [number_of_nodes_];
	route_color_ = color;

	for (int i = 0; i < number_of_nodes_; ++i) {
		order_[i] = i;
	}

	edges_.reserve(number_of_nodes_);
	for (int i = 0; i < number_of_nodes_ - 1; ++i)
	{
		edges_.emplace_back(new Edge(map.getNodes().at(order_[i]),
									 map.getNodes().at(order_[i + 1]), color));
	}

	//Last edge to get to starting node
	edges_.emplace_back(new Edge(map.getNodes().at(order_[number_of_nodes_ - 1]),
							     map.getNodes().at(order_[0]), color));
}

Route::Route(Map& map, sf::Color color)
{
	create(map, color);
}

void Route::reverse(int from)
{
	std::reverse(order_ + from, order_ + number_of_nodes_);
}

bool Route::nextLexicOrder()
{
	int X = -1;
	for (int i = 1; i < number_of_nodes_ - 1; ++i) {
		if (order_[i] < order_[i + 1])
			X = i;
	}

	if (X == -1)
		return true;

	int Y = -1;
	for (int i = 1; i < number_of_nodes_; ++i) {
		if (order_[X] < order_[i])
			Y = i;
	}

	swap(X, Y);
	reverse(X + 1);
	return false;
}

void Route::copyOrder(Route *dest) const
{
	for (int i = 0; i < number_of_nodes_; ++i) {
		dest->order_[i] = order_[i];
	}
}

void Route::drawEdges(sf::RenderWindow& window)
{
	for (int i = 0; i < number_of_nodes_; ++i) {
		edges_.at(i)->draw(window);
	}
}

void Route::updateEdges()
{
	for (int i = 0; i < number_of_nodes_ - 1; ++i) {
		delete edges_.at(i);
		edges_.at(i) = new Edge(map_->getNodes().at(order_[i]),
								map_->getNodes().at(order_[i + 1]),
								route_color_);
	}

	// Last edge to get to starting node
	delete edges_.at(number_of_nodes_ - 1);
	edges_.at(number_of_nodes_ - 1) =
			new Edge(map_->getNodes().at(order_[number_of_nodes_ - 1]),
					 map_->getNodes().at(order_[0]), route_color_);
}

/* For the branch and bound method
void Route::updateEdges(const std::vector<int>& result_)
{
	order_.at(0) = 0;
	int j = 0;
	for (int i = 1; i < number_of_nodes_; ++i) {
		if (result_[j] > 0) {
			order_.at(i) = result_[j];
			j = result_[j];
		}
		else
			order_.at(i) = j;
	}

	updateEdges();
}*/

void Route::swap(const int& i, const int& j)
{
	int temp = order_[i];
	order_[i] = order_[j];
	order_[j] = temp;
}

void Route::shuffle()
{
	random_device rd;
	mt19937 gen(rd());

	for (int i = number_of_nodes_ - 1; i > 1; --i) {
		uniform_int_distribution<> range(0, i);
		swap(i, range(gen));
	}
}

double Route::calcDistance() const
{
	double d = 0;
	for (int i = 0; i < number_of_nodes_ - 1; ++i) {
		d += map_->getNodes().at(order_[i])->distance(
				map_->getNodes().at(order_[i + 1]));
	}

	d += map_->getNodes().at(
		order_[number_of_nodes_ - 1])->distance(
			map_->getNodes().at(order_[0]));
	
	return d;
}

void Route::changeColor(const Color& color)
{
	for (auto& e_ : edges_)
		e_->changeColor(color);
}

Route::~Route()
{
	for (unsigned int i = 0; i < edges_.size(); ++i) {
		delete edges_.at(i);
	}
}