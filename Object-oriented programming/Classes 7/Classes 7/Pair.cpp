#include "Pair.h"

std::istream& operator>>(std::istream& input, Pair& pair)
{
	return input >> pair.first_ >> pair.second_;
}

std::ostream& operator<<(std::ostream& output, const Pair& pair)
{
	return output << pair.first_ << ":" << pair.second_;
}

Pair Pair::operator*(const int& right)
{
	return Pair(first_ * right, second_ * static_cast<double>(right));
}
