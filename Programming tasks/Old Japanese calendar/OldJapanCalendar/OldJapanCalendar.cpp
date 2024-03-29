﻿/*
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
* September 2021
* ИВТ-21-2б
* 
* Консольное приложение для определения названий годов по старояпонскому календарю.
* Основной алгоритм — обыкновенный эвристический. Работает для годов до нашей эры.
* Реализована проверка вводимых пользователем данных. Программа работает в "while (true)" цикле,
* что позволяет проверить неограниченное число номеров годов. Для завершения работы программы 
* достаточно ввести команду "EXIT".
*/

#include <string>
#include <iostream>

using namespace std; 

const string ANIMALS[12] = {"крысы!", "быка!", "тигра!", "кролика!", "дракона!", "змеи!",
                            "лошади!", "овцы!", "обезьяны!", "курицы!", "собаки!", "свиньи!"};
const string ELEMENTS[5] = {"деревянн", "огненн", "землян", "металлическ", "водян"};

bool isInteger16(const string& str)
{
    if (str.empty() || ((!isdigit(str[0])) && (str[0] != '-'))) /* проверка на пустую строку,
                                                                проверка первого символа строки */
        return false;

    char* end_pointer;
    const int TEMP_INT = strtol(str.c_str(), &end_pointer, 10);

    if ((TEMP_INT < -32768) || (32767 < TEMP_INT)) /* проверка 16 битного диапазона */
        return false;

    return (*end_pointer == NULL); /* если строка — целое число, 
                                   то указатель будет равен нулю-терминатору */
}

const short int userInput()
{
    while (true)
    {
        string input_string; getline(cin, input_string); // считываем строку, введённую пользователем

        if (input_string == "EXIT") // команда для выхода из программы
            exit(0);
        else if (isInteger16(input_string)) // если строка — целое 16 битное число, то...
            return (const short int) stoi(input_string); /* ...конвертируем строку в целое число,
                                                         преобразуем в константное 16 битное число */
        else
            cout << "Некорректный ввод. Пожалуйста, повторите попытку: ";
    }
}

const short int consoleInterface()
{ 
    cout << "Введите номер года от -32768 до 32767. Используйте отрицательные числа для номеров годов до нашей эры. Для завершения работы программы введите команду \"EXIT\". Ввод: ";

    const short int YEAR = userInput();

    cout << "\nТеперь вы знаете, что ";
    
    if (YEAR < 0) // динамический пользовательский интерфейс
        cout << -YEAR << " год до н.э. — год ";
    else
        cout << YEAR << " год — год ";

    return YEAR;
}

void printYearElement(const short int& YEAR_REMAINDER_10, const short int& YEAR_REMAINDER_12)
{
    /* найдя остаток от деления скорректированного относительно нуля
    номера года на 10, получим числа от -10 до 9: значения соответственно
    равны определенным элементам годов в старояпонском календаре */
    
    /* корректировка значения для соответствия с нужным индексом массива ELEMENTS:
    — если значение меньше нуля, то прибавляем к нему 10, а затем делим нацело на 2;
    — иначе сразу делим значение нацело на 2. */
    cout << ELEMENTS[YEAR_REMAINDER_10 < 0 ? (YEAR_REMAINDER_10 + 10) / 2 : YEAR_REMAINDER_10 / 2];

    /* найдя остаток от деления скорректированного относительно нуля
    номера года на 12, получим числа от -12 до 11: так можно узнать
    животное для этого номера года в старояпонском календаре */

    if (((-11 <= YEAR_REMAINDER_12) && (YEAR_REMAINDER_12 <= -8)) ||
          ((1 <= YEAR_REMAINDER_12) && (YEAR_REMAINDER_12 <= 4)))
        cout << "ого ";
    else
        cout << "ой ";
}

void printYearAnimal(const short int& YEAR_REMAINDER_12)
{
    /* найдя остаток от деления скорректированного относительно нуля
    номера года на 12, получим числа от -12 до 11: так можно узнать 
    животное для этого номера года в старояпонском календаре */

    /* корректировка значения для соответствия с нужным индексом массива ANIMALS:
    — если значение меньше нуля, то прибавляем к нему 12;
    — иначе оставляем без изменений. */
    cout << ANIMALS[YEAR_REMAINDER_12 < 0 ? YEAR_REMAINDER_12 + 12 : YEAR_REMAINDER_12] << "\n\n";
}

int main()
{
    setlocale(LC_ALL, "Russian");

    while (true) 
    {
        const short int YEAR = consoleInterface();

        const short int YEAR_REMAINDER_10 = ((YEAR - 4) % 10); /* остаток от деления на 10
                                                               с учётом корректировки старояпонского
                                                               60-летнего цикла относительно
                                                               нулевого года нашей эры */
        const short int YEAR_REMAINDER_12 = ((YEAR - 4) % 12);

        printYearElement(YEAR_REMAINDER_10, YEAR_REMAINDER_12); /* поиск названия года старояпонского
                                                                календаря через эвристические алгоритмы */
        printYearAnimal(YEAR_REMAINDER_12);
    }
}