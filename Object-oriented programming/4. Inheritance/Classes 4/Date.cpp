#include "Date.h"

void Date::setDay(const unsigned int& day) { day_ = day; }
void Date::setMonth(const unsigned int& month) { month_ = month; }
void Date::setYear(const unsigned int& year) { year_ = year; }

unsigned short Date::getDay() const { return day_; }
unsigned short Date::getMonth() const { return month_; }
unsigned short Date::getYear() const { return year_; }

bool Date::operator==(const Date& right) const {
    return (day_ == right.day_) &&
           (month_ == right.month_) &&
           (year_ == right.year_);
}

bool Date::operator!=(const Date& right) const {
    return !(*this == right);
}

bool Date::operator<(const Date& right) const
{
    if (year_ < right.year_) return true;
    else if (year_ == right.year_)
    {
        if (month_ < right.month_) return true;
        else if (month_ == right.month_) return day_ < right.day_;
        else return false;
    }
    else return false;
}

std::istream& operator>>(std::istream& input, Date& date) {
    return input >> date.day_ >> date.month_ >> date.year_;
}

std::ostream& operator<<(std::ostream& output, const Date& date) {
    return output << date.day_ << date.month_ << date.year_;
}