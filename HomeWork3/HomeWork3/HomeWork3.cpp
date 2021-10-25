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
* Вывести все перестановки числа без повторений. Найти максимальное число среди всех перестановок.
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string getString()
{
	cout << "Введите число: ";

	string INPUT_STRING; getline(cin, INPUT_STRING);

	return INPUT_STRING;
}

bool nextPermutation(string &number)
{
	// на вход подаётся заранее отсортированная по возрастанию строка символов 

	int i = number.length() - 2; // индекс предпоследнего элемента

	// пока есть символы для перебора и не найдена пара отсортированных по возрастанию элементов...
	while (i >= 0 && number[i] >= number[i + 1]) --i; // ...проверять рядом стоящие пары элементов справа налево
	
	if (i == -1) // если по итогу алгоритма все пары элементов отсортированы в обратном порядке...
		return false; // ... значит больше нет новых перестановок без повторений
	
	int j = number.length() - 1; // индекс последнего элемента 
	
	while (number[i] >= number[j]) --j; // ищем первый элемент j с конца, который больше элемента i
	
	swap(number[i], number[j]); // сортируем найденные элементы в обратном порядке
	
	int l = i + 1, r = number.length() - 1; // сортируем по возрастанию часть последовательности справа от i
	
	while (l < r) // поскольку все элементы справа от i отсортированы по убыванию...
		swap(number[l++], number[r--]); // ... достаточно перевернуть эту подпоследовательность

	return true; // новая перестановка успешно найдена 
}

void firstTask()
{
	size_t permutation_counter = 1; // счётчик количества перестановок без повторений

	string input_number = getString();

	sort(input_number.begin(), input_number.end()); // сортируем символы в строке по возрастанию

	cout << "Перестановка №" << permutation_counter << " — " << input_number << "\n";

	while (nextPermutation(input_number)) // продолжаем цикл, пока существует следующая перестановка без повторений
	{
		cout << "Перестановка №" << ++permutation_counter << " — " << input_number << "\n";
	}

	cout << "Всего перестановок без повторений: " << permutation_counter << "\n"
		 << "Максимальное число среди всех перестановок: " << input_number << "\n\n";
}

int main()
{
	setlocale(LC_ALL, "Russian");

	firstTask();
}