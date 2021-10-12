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

#include <iostream>

using namespace std;

int main()
{
    int n = 0; // дано n целых чисел
    cin >> n; // нужно ввести количество чисел последовательности

    int * array = new int[n];

    for (size_t i = 0; i < n; ++i)
    {
        int input_number = 0; cin >> input_number; // вводим числа последовательности

        array[i] = input_number; // заполняем массив
    }

    int even_numbers_counter = 0,
        even_numbers_summa = 0; // счётчик чётных целых чисел и сумматор для чётных чисел

    for (size_t i = 0; i < n; ++i)
    {
        if (array[i] % 2 == 0) // проверка целого числа на чётность
        {
            ++even_numbers_counter; // счётчик для чётных чисел
            even_numbers_summa += array[i]; // сумматор для чётных чисел
        }
    } 

    /* int copy_n = n, iterator = 0;

    while (copy_n--)
    {
        if (array[iterator] % 2 == 0) // проверка целого числа на чётность
        {
            ++even_numbers_counter; // счётчик для чётных чисел
            even_numbers_summa += array[iterator]; // сумматор для чётных чисел
        }

        ++iterator;
    } */

    /* int copy_n = n - 1, iterator = 0;

    do
    {
        if (array[iterator] % 2 == 0) // проверка целого числа на чётность
        {
            ++even_numbers_counter; // счётчик для чётных чисел
            even_numbers_summa += array[iterator]; // сумматор для чётных чисел
        }

        ++iterator;
    } while (copy_n--); */

    cout << even_numbers_counter << " " << even_numbers_summa; // вывод данных

    delete[] array;
}