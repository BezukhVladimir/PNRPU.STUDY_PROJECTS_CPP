#include "Dialog.h"

Dialog::Dialog()
{
	end_state_ = 0;
}

void Dialog::getEvent(Event& event)
{
	std::string op_int = "mq+-?/a";
	std::string s, param;

	char code;

	std::cout << '>';
	std::cin >> s; code = s[0];

	if (op_int.find(code) >= 0)
	{
		event.type = EventType::NOTEMPTY;

		switch (code)
		{
		case 'm': event.command = EventType::MAKE;   break;
		case 'q': event.command = EventType::QUIT;   break;
		case '+': event.command = EventType::ADD;    break;
		case '-': event.command = EventType::DELETE; break;
		case '?': event.command = EventType::SHOW;   break;
		case '/': event.command = EventType::GET;    break;
		}

		if (s.length() >= 1)
		{
			param = s.substr(1, s.length() - 1);
			int t = atoi(param.c_str());
			event.a = t;
		}
		else
			event.type = EventType::EMPTY;
	}
}

int Dialog::execute()
{
	Event event;

	do {
		end_state_ = 0;
		getEvent(event);
		handleEvent(event);
	} while (!isValid());

	return end_state_;
}

void Dialog::handleEvent(Event& event)
{
	if (event.type == EventType::NOTEMPTY)
	{
		switch (event.command)
		{
		case EventType::MAKE:
			size_ = event.a;
			begin_ = new Object*[size_];
			current_ = 0;
			clearEvent(event);
			break;
		case EventType::ADD:
			add();
			clearEvent(event);
			break;
		case EventType::DELETE:
			del();
			clearEvent(event);
			break;
		case EventType::SHOW:
			show();
			clearEvent(event);
			break;
		case EventType::QUIT:
			endExec();
			clearEvent(event);
			break;
		default:
			Group::handleEvent(event);
		}
	}
}

void Dialog::clearEvent(Event& event)
{
	event.type = EventType::EMPTY;
}

bool Dialog::isValid()
{
	return (end_state_ != 0);
}

void Dialog::endExec()
{
	end_state_ = 1;
}