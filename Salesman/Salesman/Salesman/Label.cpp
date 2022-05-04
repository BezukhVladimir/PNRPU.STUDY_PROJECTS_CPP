#include "Label.h"

void Label::changeCoord(const Point2D& coord)
{
	coord_ = coord;
	text_.setPosition(sf::Vector2f(coord.x, coord.y));
}

void Label::fixData() {
	if (data[data.size() - 7] == '.')
		data.erase(data.size() - 7, 7);
}

Text Label::getText() {
	fixData();

	text_.setString(data); 
	return text_;
}

Point2D Label::getCoord()
{
	return coord_;
}

void Label::changeTextColor(const sf::Color& color)
{
	text_.setFillColor(color);
}
