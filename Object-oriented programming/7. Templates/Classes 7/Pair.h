#pragma once

#include <iostream>

class Pair
{
public:
	Pair(int first, double second) : first_(first), second_(second) {}

	int first_;
	double second_;

	Pair operator*(const int& right);
	friend std::istream& operator>>(std::istream&, Pair&);
	friend std::ostream& operator<<(std::ostream&, const Pair&);
};

