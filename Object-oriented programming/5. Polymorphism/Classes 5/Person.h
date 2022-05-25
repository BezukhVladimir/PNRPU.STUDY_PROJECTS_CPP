#pragma once

#include "Object.h"
#include "Date.h"
#include "FullName.h"
#include "..\..\8. Event handling\Classes 8\Event.h"
#include <iostream>

class Person : public Object
{
public:
    Person() { personal_name_ = FullName(); date_of_birth_ = Date(); }

    void setPersonalName(const FullName&);
    void setDateOfBirth(const Date&);

    FullName getPersonalName() const;
    Date getDateOfBirth() const;

    bool operator==(const Person&) const;

    friend std::istream& operator>>(std::istream&, Person&);
    friend std::ostream& operator<<(std::ostream&, const Person&);

    virtual void show()  { std::cout << personal_name_ << ' ' << date_of_birth_; }
    virtual void input() { std::cout << "Введите полное имя (ФИО): "; std::cin >> personal_name_;
                           std::cout << "Введите дату рождения: "; std::cin >> date_of_birth_; }
    virtual void handleEvent(const Event& event);

protected:
    FullName personal_name_;
    Date date_of_birth_;
};