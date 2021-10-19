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
* October 2021
* ИВТ-21-2б
* 
* Первое задание:
* Считая, что кубический фут равен 7.481 галлона, напишите программу,
* запрашивающую у пользователя число галлонов и выводящую на экран
* эквивалетный объем в кубических футах.
* 
* Второе задание:
* Напишите программу, генерирующую вывод:
* 
* 10
* 20
* 19
* 
* Используйте представление числа 10 в виде целой константы.
* Для вывода 20 используйте присваивание, для вывода 19 операцию декремента.
* 
* Третье задание:
* Напишите программу для умножения двух чисел и вывода на экран результата.
* Числа задаёт пользователь. 
* 
* Четвёртое задание:
* Вывести последовательность символов в обратном порядке.
*/

#include <string>
#include <iostream>

using namespace std;

float gallonsToCubicFeetConversion(const float &GALLONS)
{
    return GALLONS / 7.481f;
}

float getGallons()
{
    cout << "Введите число галлонов: ";

    float GALLONS; cin >> GALLONS; cin.ignore();

    return GALLONS;
}

string getString()
{
    cout << "Введите строку символов: ";

    string INPUT_STRING; getline(cin, INPUT_STRING);

    return INPUT_STRING;
}

void firstTask()
{
    // Перевод галлонов в кубические футы

    const float GALLONS = getGallons();

    const float CUBIC_FEET = 
        gallonsToCubicFeetConversion(GALLONS);

    cout << "В " << GALLONS << " галлонах содержится " << CUBIC_FEET << " кубических футов\n\n";
}

void secondTask()
{
    /*
    * Вывод в консоль целой константы со значением 10.
    * Вывод в консоль 20, вывод в консоль 19 через операцию декремента.
    */

    cout << "Вывод чисел:\n";

    int number;
    const int TEN = 10;

    cout << TEN << "\n";

    number = 20;

    cout << number << "\n";

    cout << --number << "\n\n";
}

void thirdTask()
{
    // Произведение двух чисел

    cout << "Введите два числа: ";

    float first_number, second_number; cin >> first_number >> second_number; cin.ignore();

    cout << "Произведение чисел " << first_number << " и " << second_number
         << " равно " << first_number * second_number << "\n\n";
}

void fourthTask()
{
    // Обратный вывод последовательности символов

    const string INPUT_STRING = getString();

    cout << "Введённая строка в обратном порядке: ";

    for (int i = INPUT_STRING.length() - 1; i >= 0; --i)
    {
        cout << INPUT_STRING[i];
    }

    cout << "\n";
}

int main()
{
    setlocale(LC_ALL, "Russian");

    firstTask();
    secondTask();
    thirdTask();
    fourthTask();
}