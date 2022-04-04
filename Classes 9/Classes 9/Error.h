#pragma once

#include <string>
#include <iostream>

class Error
{
public:
	Error(std::string error_message) { message_ = error_message; }
	void printMessage() { std::cout << message_; }
private:
	std::string message_;
};

