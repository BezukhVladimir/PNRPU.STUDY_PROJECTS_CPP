/*
* This code is licensed under the Creative Commons
* Attribution - NonCommercial - NoDerivatives 4.0 International License.
* To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/
* or send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*
* https://bezukh.wixsite.com/blog
* https://github.com/BezukhVladimir
*
* © Developed by Bezukh Vladimir. All right reserved.
*/

/* 
* Developed by Bezukh Vladimir
* October 2021
* ИВТ-21-2б
* 
* Первое задание:
* Вывести все перестановки строки символов без повторений.
* Найти лексикографически-разрядно максимальную строку символов среди всех перестановок.
* Если все символы цифры, то такая строка — максимальное число.
* 
* Второе задание:
* Реализовать игру «Угадай число».
*/

#include <random>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int getRandomInt(const int &MIN, const int &MAX)
{
	random_device random_device; // источник энтропии
	mt19937 mersenne(random_device()); // ГПСЧ «Вихрь Мерсенна»

	// более равномерное распределение [MIN, MAX], нежели mersenne() % (MAX - MIN + 1) + MIN;
	uniform_int_distribution<> distribution(MIN, MAX);

	return distribution(mersenne);
}

string getString()
{
	cout << "Введите значение: ";

	string INPUT_STRING; getline(cin, INPUT_STRING);

	return INPUT_STRING;
}

bool nextPermutation(string &string)
{
	// на вход подаётся заранее отсортированная по возрастанию строка символов 

	int i = string.length() - 2; // индекс предпоследнего элемента

	// пока есть символы для перебора и не найдена пара отсортированных по возрастанию элементов...
	while (i >= 0 && string[i] >= string[i + 1]) --i; // ...проверять рядом стоящие пары элементов справа налево
	
	if (i == -1) // если по итогу алгоритма все пары элементов отсортированы в обратном порядке...
		return false; // ... значит больше нет новых перестановок без повторений
	
	int j = string.length() - 1; // индекс последнего элемента 
	
	while (string[i] >= string[j]) --j; // ищем первый элемент j с конца, который больше элемента i
	
	swap(string[i], string[j]); // сортируем найденные элементы в обратном порядке
	
	int l = i + 1, r = string.length() - 1; // сортируем по возрастанию часть последовательности справа от i
	
	while (l < r) // поскольку все элементы справа от i отсортированы по убыванию...
		swap(string[l++], string[r--]); // ... достаточно перевернуть эту подпоследовательность

	return true; // новая перестановка успешно найдена 
}

void firstTask()
{
	size_t permutation_counter = 1; // счётчик количества перестановок без повторений

	string input_string = getString();

	sort(input_string.begin(), input_string.end()); // сортируем символы в строке по возрастанию

	cout << "Перестановка №" << permutation_counter << " — " << input_string << "\n";

	while (nextPermutation(input_string)) // продолжаем цикл, пока существует следующая перестановка без повторений
	{
		cout << "Перестановка №" << ++permutation_counter << " — " << input_string << "\n";
	}

	cout << "Всего перестановок без повторений: " << permutation_counter << "\n"
		 << "Лексикографически-разрядно максимальная строка символов среди всех перестановок"
		 << " (если все символы цифры, то это максимальное число) : "
		 << input_string << "\n\n";
}

bool playGame(const unsigned int &ATTEMPTS, const int &SECRET_NUMBER)
{
	for (size_t counter = 1; counter <= ATTEMPTS; ++counter)
	{
		cout << "Ваша попытка №" << counter << ": ";

		int ATTEMPT; cin >> ATTEMPT;

		if (ATTEMPT > SECRET_NUMBER)
			cout << "Введённое число больше загаданного.\n";
		else if (ATTEMPT < SECRET_NUMBER)
			cout << "Введённое число меньше загаданного.\n";
		else
			return true; // игрок угадал число
	}

	return false; // игрок проиграл
}

bool playAgain()
{
	// Спрашиваем у игрока, хочет ли он сыграть ещё раз

	char player_answer;

	do
	{
		cout << "Хотите сыграть ещё раз? (Y/N)\n";
		cin >> player_answer;

	} while (player_answer != 'Y' && player_answer != 'N');

	return (player_answer == 'Y');
}

void secondTask()
{
	const unsigned int ATTEMPTS = 7; // количество попыток игрока
	const int SECRET_MIN = 1, SECRET_MAX = 100; // диапазон угадывания
	
	do
	{
		const int SECRET_NUMBER = getRandomInt(SECRET_MIN, SECRET_MAX); // секретное число, которое нужно угадать
	
		cout << "Начинаем игру \"Угадай число от " << SECRET_MIN << " до " << SECRET_MAX 
			 << " включительно\". У вас есть " << ATTEMPTS << " попыток, чтобы сделать это.\n";

		bool player_won = playGame(ATTEMPTS, SECRET_NUMBER);

		if (player_won)
			cout << "Вы угадали загаданное число " << SECRET_NUMBER << ". Поздравляем!\n";
		else
			cout << "К сожалению, вы проиграли. Секретное число: " << SECRET_NUMBER << ".\n";

	} while (playAgain());

	cout << "Спасибо за игру!\n";
}

int main()
{
	setlocale(LC_ALL, "Russian");

	firstTask();
	secondTask();
}