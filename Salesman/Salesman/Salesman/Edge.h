#pragma once
#include <cmath>
#include <SFML/Graphics.hpp>
#include "Node.h"
#include "constants.h"

class Edge
{
public:
	Edge(Node *from, Node *to, sf::Color color);
	~Edge();
	void draw(sf::RenderWindow& window);
	double distance();
	void changeColor(const Color& color);

private:
	sf::RectangleShape *rect_;
	Node *n1_;
	Node *n2_;
};