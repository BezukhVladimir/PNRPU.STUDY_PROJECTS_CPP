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
* Classes 6
* ИВТ-21-2б
*/

#include "SinglyList.h"

int main()
{
	SinglyList<int> list;

	list.pushBack(0); list.pushBack(1); list.pushBack(2); list.pushBack(3);
	for (const int& value : list)
		std::cout << value << " ";
	std::cout << std::endl;

	// Доступ к элементам через []
	list[0] = 42;
	for (const int& value : list)
		std::cout << value << " ";
	std::cout << std::endl;

	// Размер списка
	std::cout << list.size() << std::endl;

	// Умножение всех элементов списка на целочисленное число
	list * 10;
	for (const int& value : list)
		std::cout << value << " ";
	std::cout << std::endl;

	// Сдвиг итератора на N элементов вправо
	auto iter = list.begin();
	std::cout << *iter << " ";
	std::cout << *(iter + 2);
}