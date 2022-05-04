#pragma once
#include <SFML/Graphics.hpp>
#include "Point2D.h"

class Node
{
public:
	Node(Point2D coord, int index);
	~Node();
	void draw(sf::RenderWindow &window);
	double distance(Node* n) const;
	Point2D getCoord() const;
	void changeColor(const sf::Color& color);

private:
	Point2D coord_;
	int index_;
	sf::CircleShape* circle_;
};