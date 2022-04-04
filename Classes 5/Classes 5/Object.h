#pragma once
#include "..\..\Classes 8\Classes 8\Event.h"

class Object
{
public:
	virtual void show() = 0;
	virtual void input() = 0;

	virtual void handleEvent(const Event& event) = 0;
};

