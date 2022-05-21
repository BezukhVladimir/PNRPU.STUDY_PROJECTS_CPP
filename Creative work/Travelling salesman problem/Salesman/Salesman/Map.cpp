#include "Map.h"

Map::Map() {}

void Map::create(int number_of_nodes, sf::RenderWindow& window)
{
	number_of_nodes_ = number_of_nodes;
	nodes_.reserve(number_of_nodes);
	
	for (int i = 0; i < number_of_nodes; ++i) {
		nodes_.emplace_back(new Node(
			Point2D(randomNum(50, window.getSize().x - 50),
					randomNum(50, window.getSize().y - 50)),
					i));
	}
}

Map::Map(int number_of_nodes, sf::RenderWindow& window) {
	create(number_of_nodes, window);
}

void Map::drawMap(sf::RenderWindow& window)
{
	for(int i = 0; i < number_of_nodes_; ++i) {
		nodes_.at(i)->draw(window);
	}
}

std::vector<Node *> Map::getNodes() const {
	return nodes_;
}

void Map::changeColor(const sf::Color& color)
{
	for (auto& n_ : nodes_)
		n_->changeColor(color);
}

int Map::getNodeCount() const {
	return number_of_nodes_;
}

int Map::randomNum(int min, int max) const
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> range(min, max);

	return range(gen);
}

Map::~Map()
{
	for (int i = 0; i < number_of_nodes_; ++i) {
		delete nodes_.at(i);
	}
}