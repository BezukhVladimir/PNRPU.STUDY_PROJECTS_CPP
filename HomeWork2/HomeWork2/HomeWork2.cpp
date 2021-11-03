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
* November 2021
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
* 
* Пятое задание:
* Написать программу, которая переводит температуру в градусах по Фаренгейту
* в градусы Цельсия по формуле: 𝐶 = 5/9 * (𝐹 − 32)
* 
* Шестое задание:
* Заданы два момента времени в течение дня.
* Написать программу для нахождения промежутка времени между ними.
*/

#include <string>
#include <iostream>

using namespace std;

struct DayMoment
{
    size_t hours, mins, secs;

    size_t getAllSecs();
    void takeAllSecs(size_t all_secs);

    DayMoment() : hours(0), mins(0), secs(0) {}
    DayMoment(size_t hours, size_t mins, size_t secs) : hours(hours), mins(mins), secs(secs) {}
};

size_t DayMoment::getAllSecs() 
{
    return hours * 3600 + mins * 60 + secs;
}

void DayMoment::takeAllSecs(size_t all_secs)
{
    hours = all_secs / 3600; all_secs %= 3600;
    mins = all_secs / 60;   all_secs %= 60;
    secs = all_secs;
}

DayMoment getDayMoment()
{
    cout << "Введите момент времени суток в часах, минутах и секундах: ";

    DayMoment DAY_MOMENT; cin >> DAY_MOMENT.hours >> DAY_MOMENT.mins >> DAY_MOMENT.secs; cin.ignore();

    return DAY_MOMENT;
}

string getString()
{
    cout << "Введите строку символов: ";

    string INPUT_STRING; getline(cin, INPUT_STRING);

    return INPUT_STRING;
}

float getGallons()
{
    cout << "Введите число галлонов: ";

    float GALLONS; cin >> GALLONS; cin.ignore();

    return GALLONS;
}

float getFahrenheit()
{
    cout << "Введите число градусов Фаренгейта: ";

    float FAHRENHEIT; cin >> FAHRENHEIT; cin.ignore();

    return FAHRENHEIT;
}

float gallonsToCubicFeetConversion(const float &GALLONS)
{
    return GALLONS / 7.481f;
}

float fahrenheitToCelsiusConversion(const float &FAHRENHEIT)
{
    return (FAHRENHEIT - 32) * 5 / 9;
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

    float FIRST_NUMBER, SECOND_NUMBER; cin >> FIRST_NUMBER >> SECOND_NUMBER; cin.ignore();

    cout << "Произведение чисел " << FIRST_NUMBER << " и " << SECOND_NUMBER
         << " равно " << FIRST_NUMBER * SECOND_NUMBER << "\n\n";
}

void fourthTask()
{
    // Обратный вывод последовательности символов

    const string INPUT_STRING = getString();

    cout << "Введённая строка в обратном порядке: ";

    for (int i = INPUT_STRING.length() - 1; i >= 0; --i)
        cout << INPUT_STRING[i];

    cout << "\n\n";
}

void fifthTask()
{
    // Перевод градусов Фаренгейта в градусы Цельсия

    const float FAHRENHEIT = getFahrenheit();

    const float CELSIUS =
        fahrenheitToCelsiusConversion(FAHRENHEIT);

    cout << FAHRENHEIT << " градусов Фаренгейта эквивалентно " << CELSIUS << " градусам Цельсия\n\n";
}

void sixthTask() 
{
    // Разница между двумя моментами времени суток

    DayMoment FIRST_DAY_MOMENT = getDayMoment(), SECOND_DAY_MOMENT = getDayMoment();
    
    DayMoment DIFF_TIME; 
    DIFF_TIME.takeAllSecs(abs((int) (FIRST_DAY_MOMENT.getAllSecs() - SECOND_DAY_MOMENT.getAllSecs())));

    cout << "\nПромежуток составляет: часов — "
         << DIFF_TIME.hours << ", минут — "
         << DIFF_TIME.mins  << ", секунд — "
         << DIFF_TIME.secs  << ".\n\n";
}

int main()
{
    setlocale(LC_ALL, "Russian");

    firstTask();
    secondTask();
    thirdTask();
    fourthTask();
    fifthTask();
    sixthTask();  
}