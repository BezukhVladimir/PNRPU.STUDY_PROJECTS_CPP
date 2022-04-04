#pragma once
#include "Group.h"
#include "Event.h"

class Dialog : public Group
{
public:
	Dialog();

	virtual void getEvent(Event& event);
	virtual int execute();
	virtual void handleEvent(Event& event);
	virtual void clearEvent(Event& event);
	bool isValid();
	void endExec();

protected:
	int end_state_ = 0;
};