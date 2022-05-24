#pragma once

#include "Person.h"
#include "Subjects.h"

class Student : public Person
{
public:
	Subjects subjects;
};