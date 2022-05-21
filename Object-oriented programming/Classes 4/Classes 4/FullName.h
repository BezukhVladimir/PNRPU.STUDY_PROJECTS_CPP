#pragma once

#include <string>
#include <iostream>

class FullName
{
public:
    void setSurname(const std::string&);
    void setForename(const std::string&);
    void setPatronym(const std::string&);

    std::string getSurname() const;
    std::string getForename() const;
    std::string getPatronym() const;

    bool operator==(const FullName&) const;

    friend std::istream& operator>>(std::istream&, FullName&);
    friend std::ostream& operator<<(std::ostream&, const FullName&);

private:
    std::string surname_;
    std::string forename_;
    std::string patronym_;
};