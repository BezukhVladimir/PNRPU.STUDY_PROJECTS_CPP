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
* ИВТ-21-2б
*/

#include <random>
#include <iostream>
#include <vld.h>

void input(int* array, const int& size)
{
	std::mt19937 rnd(time(0));
	std::uniform_int_distribution<> uid(100, 999);

	for (int i = 0; i != size; ++i)
		array[i] = uid(rnd);
}

void output(const int* array, const int& size) {
	for (int i = 0; i != size; ++i)
		std::cout << array[i] << " ";

	std::cout << "\n";
}

bool contain(const int* array, const int& size, const int& value)
{
	for (int i = 0; i != size; ++i)
		if (array[i] == value)
			return true;

	return false;
}

void removeFirst(int*& array, int& size, const int& value)
{
	bool shift = false;
	int* new_array = new int[--size];

	for (int i = 0; i != size; ++i) {
		if (array[i] == value && !shift)
			shift = true;

		new_array[i] = array[i + (int)shift];
	}

	delete [] array;
	array = new_array;
}

void replace(int*& array, int& size, const int& value, const int& start, const int& finish)
{
	if (start < 0 || start >= size)
		return;

	if (finish < 0 || finish >= size)
		return;

	if (start > finish)
		return;

	if (start == finish) {
		array[start] = value;
		return;
	}

	if (start + 1 == finish) {
		bool shift = false;
		int* new_array = new int[++size];

		for (int i = 0; i != size; ++i) {
			if (i == finish) {
				new_array[i] = value;
				shift = true;
			} else new_array[i] = array[i - (int)shift];
		}

		delete[] array;
		array = new_array;
	} else {
		for (int i = 0; i != size; ++i)
			if (start < i && i < finish)
				array[i] = value;
	}
}

int main()
{
	int size; std::cin >> size;
	int* array = new int[size];

	input(array, size);
	output(array, size);

	int value; std::cin >> value;
	if (contain(array, size, value)) removeFirst(array, size, value);
	output(array, size);

	int start, finish; std::cin >> start >> finish;
	replace(array, size, value, start, finish);
	output(array, size);

	delete [] array;
}