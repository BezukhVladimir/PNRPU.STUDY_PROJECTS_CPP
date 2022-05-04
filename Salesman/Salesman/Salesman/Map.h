#pragma once
#include <vector>
#include <random>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include "Node.h"

class Map
{
public:
	Map();
	Map(int number_of_nodes, sf::RenderWindow& window);
	void create(int number_of_nodes, sf::RenderWindow& window);

	void drawMap(sf::RenderWindow& window);
	int getNodeCount() const;
	std::vector<Node *> getNodes() const;
	void changeColor(const sf::Color& color);

	~Map();

private:
	int number_of_nodes_;
	int randomNum(int min, int max) const;
	std::vector<Node *> nodes_;
};