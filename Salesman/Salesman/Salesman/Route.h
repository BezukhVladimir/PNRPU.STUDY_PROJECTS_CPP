#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Map.h"
#include "Edge.h"

class Route
{
public:
	Route();
	Route(Map &map, sf::Color color);
	void create(Map& map, sf::Color color);
	void copyOrder(Route* dest) const;
	void swap(const int& i, const int& j);
	void drawEdges(sf::RenderWindow &window);
	void shuffle();
	void updateEdges();
	//void updateEdges(const std::vector<int>& result_);
	double calcDistance() const;
	bool nextLexicOrder();
	void changeColor(const Color& color);
	~Route();

private:
	void reverse(int from);
	int number_of_nodes_;
	int * order_;
	sf::Color route_color_;
	std::vector<Edge *> edges_;
	Map *map_;
};