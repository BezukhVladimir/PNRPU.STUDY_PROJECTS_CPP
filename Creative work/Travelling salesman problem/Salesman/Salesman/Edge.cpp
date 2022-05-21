#include "Edge.h"

using namespace constants::edge;

Edge::Edge(Node *from, Node *to, sf::Color color)
{
	n1_ = from;
	n2_ = to;
	float angle = atan2((n1_->getCoord().y - n2_->getCoord().y),
						(n1_->getCoord().x - n2_->getCoord().x))
							* 180 / defaultValues::PI - 180;
	
	rect_ = new sf::RectangleShape(sf::Vector2f(n1_->distance(n2_),
								   DEFAULT_EDGE_HEIGHT));
	rect_->setPosition(sf::Vector2f(n1_->getCoord().x, 
									n1_->getCoord().y));
	rect_->setFillColor(color);
	rect_->setOrigin(0, 2);
	rect_->setRotation(angle);
}

Edge::~Edge()
{
	delete rect_;
}

void Edge::changeColor(const Color& color)
{
	rect_->setFillColor(color);
}

void Edge::draw(sf::RenderWindow &window)
{
	window.draw(sf::RectangleShape(*rect_));
}

double Edge::distance()
{
	return n1_->distance(n2_);
}