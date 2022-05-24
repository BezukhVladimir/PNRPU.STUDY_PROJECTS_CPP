#include "Person.h"

void Person::setPersonalName(const FullName& personal_name) { personal_name_ = personal_name; }
void Person::setDateOfBirth(const Date& date_of_birth) { date_of_birth_ = date_of_birth; }

FullName Person::getPersonalName() const { return personal_name_; }
Date Person::getDateOfBirth() const { return date_of_birth_; }


bool Person::operator==(const Person& right) const {
    return (personal_name_ == right.personal_name_) &&
           (date_of_birth_ == right.date_of_birth_);
}

void Person::handleEvent(const Event& event)
{
    if (event.type == EventType::NOTEMPTY)
    {
        switch (event.command)
        {
        case EventType::GET:
            std::cout << "Person name: " << getPersonalName() << std::endl;
            std::cout << "Date of birth: " << getDateOfBirth() << std::endl;
            break;
        }
    }
}

std::istream& operator>>(std::istream& input, Person& person) {
    return input >> person.personal_name_ >> person.date_of_birth_;
}

std::ostream& operator<<(std::ostream& output, const Person& person) {
    return output << person.personal_name_ << ' ' << person.date_of_birth_;
}