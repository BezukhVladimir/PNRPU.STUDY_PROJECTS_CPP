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
* December 2021
* ИВТ-21-2б
* 
* Дано: натуральное число N.
* Проверить: есть ли в этом числе цифра равная заданной цифре Z.
* 
* Дано: целые числа последовательности вводятся с клавиатуры. Признаком окончания ввода является 0.
* Определить: упорядочена ли последовательность по возрастанию.
* 
* Дано: последовательность целых чисел в которой N элементов.
* Определить: какое число встретится в последовательности первым — положительное или отрицательное. 
* Учесть, что все элементы последовательности могут быть нулевыми.
*/

#include <iostream>

using namespace std;

void thirdTask()
{
    bool f = true; // последовательность из нулей
    int a, n; cin >> n;

    while (n-- && f)
        { cin >> a; f = (a == 0); }

    if (f)
        cout << "Последовательность пуста или состоит из нулей.";
    else
        cout << "Первое число последовательности, отличное от нуля, — "
             << (a > 0 ? "положительное" : "отрицательное");
}

void secondTask()
{
    bool f = true; // пустая или отсортированная по возрастанию
    unsigned int l = 0, r; cin >> r;

    while (r && f) // r != 0
        if (f = (l <= r))
            { l = r; cin >> r; }

    cout << "Последовательность " << (f ? "пуста или" : "не") << " отсортирована по возрастанию\n";
}

void firstTask()
{
    bool f = true; // искомое число отсутствует
    unsigned int n, Z; cin >> n >> Z;

    while (n && f) // N != 0
        { f = (Z != n % 10); n /= 10; }

    cout << "В введённом числе " << (f ? "отсутствует" : "присутствует") << " цифра " << Z << '\n';
}

int main()
{
    setlocale(LC_ALL, "Russian");

    firstTask();
    secondTask();
    thirdTask();
}