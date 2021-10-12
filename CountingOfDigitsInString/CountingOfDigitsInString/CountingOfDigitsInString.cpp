/*
* This code is licensed under the Creative Commons
* Attribution - NonCommercial - NoDerivatives 4.0 International License.
* To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/
* or send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*
* https://github.com/BezukhVladimir
* https://bezukh.wixsite.com/blog
*
* © Developed by Bezukh Vladimir. All right reserved.
*/

/*
* Developed by Bezukh Vladimir
* September 2021
* ИВТ-21-2б
*
* Консольное приложение для определения, какая цифра(ы) встречается(ются) в строке чаще всего.
* Реализована проверка вводимых пользователем данных. Программа работает в "while (true)" цикле,
* что позволяет проверить неограниченное число строк. Для завершения работы программы 
* достаточно ввести команду "EXIT".
*/

#include <vector>
#include <string>
#include <iostream>

using namespace std;

string userInput()
{
    cout << "Вас приветствует программа для подсчёта цифр в строке и вывода самых часто встречаемых из них. Для завершения работы программы введите команду \"EXIT\". Ввод: ";

    while (true)
    {
        string input_string; getline(cin, input_string); // считываем строку, введённую пользователем

        if (input_string == "EXIT") // команда для выхода из программы
            exit(0);
        else if (!input_string.empty()) // если строка не пустая, то...
            return input_string; // ... передаём строку
        else
            cout << "Некорректный ввод. Пожалуйста, повторите попытку: ";
    }
}

void countingOfDigitsInString(unsigned short int *input_array, const string &str)
{
    for (char symbol : str) // перебираем все символы в строке
        if (isdigit(symbol)) // если символ является цифрой, то...
            ++input_array[symbol - '0']; //... увеличиваем счётчик соответствующей цифры
}

vector<unsigned short int> findForMaximumsIdsOfArray(const unsigned short int *input_array, 
                                                     const size_t &input_array_size)
{
    unsigned short int maximum_value = 0;
    vector<unsigned short int> maximums_ids;

    for (size_t i = 0; i < input_array_size; ++i) // поиск максимального значения в массиве
        if (input_array[i] > maximum_value)
            maximum_value = input_array[i];

    for (size_t i = 0; i < input_array_size; ++i) // поиск индексов максимальных значений в массиве
        if (input_array[i] == maximum_value)
            maximums_ids.emplace_back(i);

    return maximums_ids; // возвращаем вектор индексов максимальных значений массива
}

void outputResult(const unsigned short int *array_of_digit_counters, const size_t &ARRAY_OF_DIGIT_COUNTERS_SIZE, 
                  const vector<unsigned short int> &maximums_ids_of_digit_counters) 
{
    cout << "\nКоличество цифр в строке:\n";

    for (size_t i = 0; i < ARRAY_OF_DIGIT_COUNTERS_SIZE; ++i)
        cout << "— цифра " << i << " встречается " << array_of_digit_counters[i] << " раз(а)\n";

    cout << "\nСамая(ые) часто встречаемая(ые) цифра(ы):\n";

    for (unsigned short int id : maximums_ids_of_digit_counters)
        cout << "— цифра " << id << " встречается " << array_of_digit_counters[id] << " раз(а)\n";

    cout << "\n";
}

int main()
{
    setlocale(LC_ALL, "Russian");

    while (true)
    {
        unsigned short int array_of_digit_counters[10] = {0, 0, 0, 0, 0,
                                                          0, 0, 0, 0, 0};
        size_t ARRAY_OF_DIGIT_COUNTERS_SIZE = sizeof array_of_digit_counters /
                                              sizeof *array_of_digit_counters;

        string input_string; input_string = userInput();

        countingOfDigitsInString(array_of_digit_counters, input_string);

        vector<unsigned short int> maximums_ids_of_digit_counters =
            findForMaximumsIdsOfArray(array_of_digit_counters, ARRAY_OF_DIGIT_COUNTERS_SIZE);

        outputResult(array_of_digit_counters, ARRAY_OF_DIGIT_COUNTERS_SIZE, maximums_ids_of_digit_counters);
    }
}