#pragma once

#include <iostream>

class Date
{
public:
    void setDay(const unsigned int&);
    void setMonth(const unsigned int&);
    void setYear(const unsigned int&);

    unsigned short getDay() const;
    unsigned short getMonth() const;
    unsigned short getYear() const;

    bool operator==(const Date&) const;
    bool operator!=(const Date&) const;
    bool operator<(const Date&) const;

    friend std::istream& operator>>(std::istream&, Date&);
    friend std::ostream& operator<<(std::ostream&, const Date&);

private:
    unsigned short day_;
    unsigned short month_;
    unsigned short year_;
};