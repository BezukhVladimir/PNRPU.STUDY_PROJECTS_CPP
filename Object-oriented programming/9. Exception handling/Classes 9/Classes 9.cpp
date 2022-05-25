/*
* This code is licensed under the Creative Commons
* Attribution - NonCommercial - NoDerivatives 4.0 International License.
* To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/
* or send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*
*
* https://bezukh.wixsite.com/blog
* https://github.com/BezukhVladimir
*
* © Developed by Bezukh Vladimir. All right reserved.
*/

/*
* Developed by Bezukh Vladimir
* Classes 9
* ИВТ-21-2б
*/

#include "Error.h"
#include "SinglyList.h"
#include <iostream>
#include <string>
#include <type_traits>

template <typename T>
void setInteger(T& data, const int& index, const int& integer)
{
	if (std::is_arithmetic_v<decltype(data[0])>)
		data.insert(index, std::to_string(integer));
	else
		throw
		Error("This is non-numbers type container!"); // throm 1;
}

int main()
{
	SinglyList<int> numbers;
	SinglyList<std::string> strings;

	numbers.pushBack(1);
	strings.pushBack("string");

	/*try
	{
		setInteger(numbers, 0, 21);
	}*/

	try
	{
		setInteger(strings, 0, 21);
	}

	catch (Error& error)
	{
		error.printMessage();
	}

	catch (int)
	{
		std::cout << "This is non-numbers type container!" << std::endl;
	}

	std::cout << std::endl << numbers[0] << std::endl;
	std::cout << strings[0];
}