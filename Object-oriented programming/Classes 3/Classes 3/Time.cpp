#include "Time.h"
#include <iostream> 

Time& Time::operator=(const Time& copy)
{
	if (&copy != this)
	{
		min_ = copy.min_;
		sec_ = copy.sec_;
	}
	
	return *this;
}

Time& Time::operator++()
{
	int temp = min_ * 60 + sec_; temp++;

	min_ = temp / 60;
	sec_ = temp % 60;
	
	return *this;
}

Time Time::operator++(const int)
{
	Time temp(min_, sec_); ++(*this);
	return temp;
}

Time Time::operator+(const Time& right) const
{
	int temp_left = min_ * 60 + sec_;
	int temp_right = right.min_ * 60 + right.sec_;

	return Time((temp_left + temp_right) / 60,
				(temp_left + temp_right) % 60);
}

Time Time::operator-(const Time& right) const
{
	int temp_left = min_ * 60 + sec_;
	int temp_right = right.min_ * 60 + right.sec_;

	return Time((temp_left - temp_right) / 60,
				(temp_left - temp_right) % 60);
}

bool Time::operator==(const Time& right) const
{
	return (min_ == right.min_) && (sec_ == right.sec_);
}

bool Time::operator!=(const Time& right) const
{
	return !(*this == right);
}

std::istream& operator>>(std::istream& input, Time& time)
{
	return input >> time.min_ >> time.sec_;
}

std::ostream& operator<<(std::ostream& out, const Time& time)
{
	return out << time.min_ << ":" << time.sec_;
}