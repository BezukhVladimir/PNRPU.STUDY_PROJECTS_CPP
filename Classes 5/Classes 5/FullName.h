#pragma once

#include <string>
#include <iostream>

class FullName
{
public:
    FullName() { surname_ = ""; forename_ = ""; patronym_ = ""; }
    FullName(std::string surname, std::string forename, std::string patronym) :
        surname_(surname), forename_(forename), patronym_(patronym) {}

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