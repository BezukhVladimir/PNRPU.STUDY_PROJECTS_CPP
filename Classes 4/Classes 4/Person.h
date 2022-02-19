#include "Date.h"
#include "FullName.h"
#include <iostream>

class Person
{
public:
    void setPersonalName(const FullName&);
    void setDateOfBirth(const Date&);

    FullName getPersonalName() const;
    Date getDateOfBirth() const;

    bool operator==(const Person&) const;

    friend std::istream& operator>>(std::istream&, Person&);
    friend std::ostream& operator<<(std::ostream&, const Person&);

protected:
    FullName personal_name_;
    Date date_of_birth_;
};