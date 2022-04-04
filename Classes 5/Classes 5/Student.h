#pragma once

#include "Person.h"
#include "Subjects.h"

class Student : public Person
{
public:
	Student() { subjects = Subjects(); }

	virtual void show()  { Person::show(); std::cout << std::endl << subjects; }
	virtual void input() { Person::input(); std::cin >> subjects; }

public:
	Subjects subjects;
};