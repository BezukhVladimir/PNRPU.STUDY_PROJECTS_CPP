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
* Вывести все комбинации цифр числа, найти максимальное число среди комбинаций.
* Цифры в исходном числе не повторяются, любая комбинация выводится один раз.
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool nextPermutation(string &number)
{
	size_t i = number.length() - 2;

	while (i > 0 && number[i] >= number[i + 1]) --i;
	
	if (i == -1)
		return false;
	
	size_t j = number.length() - 1;
	
	while (number[i] >= number[j]) --j;
	
	swap(number[i], number[j]);
	
	size_t l = i + 1, r = number.length() - 1; // сортируем оставшуюся часть последовательности
	
	while (l < r)
		swap(number[l++], number[r--]);

	return true;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	vector<char> DIGITS;
	string number; getline(cin, number);
	
	sort(number.begin(), number.end()); 

	while (nextPermutation(number))
		cout << number << endl;
}