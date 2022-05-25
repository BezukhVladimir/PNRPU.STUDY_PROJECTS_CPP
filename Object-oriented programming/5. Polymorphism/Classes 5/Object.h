#pragma once
#include "..\..\8. Event handling\Classes 8\Event.h"

class Object
{
public:
	virtual void show() = 0;
	virtual void input() = 0;

	virtual void handleEvent(const Event& event) = 0;
};

