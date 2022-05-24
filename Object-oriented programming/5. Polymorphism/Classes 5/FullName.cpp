#include "FullName.h"

void FullName::setSurname(const std::string& surname) { surname_ = surname; }
void FullName::setForename(const std::string& forename) { forename_ = forename; }
void FullName::setPatronym(const std::string& patronym) { patronym_ = patronym; }

std::string FullName::getSurname() const { return surname_; }
std::string FullName::getForename() const { return forename_; }
std::string FullName::getPatronym() const { return patronym_; }

bool FullName::operator==(const FullName& right) const {
    return (surname_ == right.surname_) &&
           (forename_ == right.forename_) &&
           (patronym_ == right.patronym_);
}

std::istream& operator>>(std::istream& input, FullName& full_name) {
    return input >> full_name.surname_ >> full_name.forename_ >> full_name.patronym_;
}

std::ostream& operator<<(std::ostream& output, const FullName& full_name) {
    return output << full_name.surname_ << " " << full_name.forename_ << " " << full_name.patronym_;
}