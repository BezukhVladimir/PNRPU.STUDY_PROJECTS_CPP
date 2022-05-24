#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Point2D.h"
#include "constants.h"

using namespace std;
using namespace sf;
using namespace constants::label;

class Label {
public:
	string data;

protected:
	Font font_;
	Point2D coord_;
	Text text_;

public:
	Label(Point2D coord = Point2D(), string str = DEFAULT_LABEL_DATA) {
		font_.loadFromFile(DEFAULT_LABEL_FONT);
		coord_ = coord;
		data = str;  					       
		text_.setFont(font_);			       
		text_.setCharacterSize(DEFAULT_LABEL_FONT_SIZE);            
		text_.setFillColor(DEFAULT_LABEL_TEXT_COLOR);      
		text_.setPosition(coord_.x, coord_.y); 
	}
	
	virtual void changeCoord(const Point2D& coord);
	Text getText();
	Point2D getCoord();
	void changeTextColor(const sf::Color& color);

private:
	void fixData();
};