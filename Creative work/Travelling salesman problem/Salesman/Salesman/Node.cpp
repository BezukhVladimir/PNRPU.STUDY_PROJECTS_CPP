#include <cmath>
#include "Node.h"
#include "constants.h"

using namespace constants::node;

Node::Node(Point2D coord, int index)
{
	coord_ = coord;
	index_ = index;
	circle_ = new sf::CircleShape(DEFAULT_NODE_RADIUS);
	circle_->setFillColor(DEFAULT_NODE_COLOR);
	circle_->setOrigin(DEFAULT_NODE_RADIUS, DEFAULT_NODE_RADIUS);
	circle_->setPosition(coord_.x, coord_.y);
}

void Node::draw(sf::RenderWindow& window)
{
	window.draw(sf::CircleShape(*circle_));
}

double Node::distance(Node* n) const 
{
	if (this == n)
		return 0.0;

	return sqrt(pow(coord_.x - n->coord_.x, 2) + 
				pow(coord_.y - n->coord_.y, 2));
}

Point2D Node::getCoord() const
{
	return coord_;
}

void Node::changeColor(const sf::Color& color)
{
	circle_->setFillColor(color);
}

Node::~Node()
{
	delete circle_;
}