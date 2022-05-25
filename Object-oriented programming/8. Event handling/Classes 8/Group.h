#pragma once
#include "../../5. Polymorphism/Classes 5/Object.h"
#include "../../5. Polymorphism/Classes 5/Person.h"
#include "../../5. Polymorphism/Classes 5/Student.h"

class Group
{
public:
	Group();
	Group(size_t);
	~Group();

	void add();
	void del();
	void show();
	size_t operator() ();

	virtual void handleEvent(const Event& event);

protected:
	Object** begin_;
	size_t size_;
	size_t current_;
};

