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
* 1. Вывести на экран пустой квадрат с рамкой n.
* 
* 2. Подсчитать сумму последовательности S = 1 * 2 + 2 * 3 * 4 + 3 * 4 * 5 * 6 + ... + n * (n+1) * ... 2n.
*/

#include <iomanip>
#include <iostream>

using namespace std;

void firstTask()
{
    size_t N; cin >> N;
    size_t end = N - 1;

    for (size_t i = 0; i != N; ++i)
    {
        for (size_t j = 0; j != N; ++j)
            cout << setw(2) << ((i == 0 || j == 0 || i == end || j == end) ? '*' : ' ');

        cout << '\n';
    }
}

void secondTask()
{
    size_t N; cin >> N;
    size_t summa = 0, begin = 1, end = 3;
    
    for (size_t i = 0; i != N; ++i)
    {
        size_t p = 1;

        for (size_t j = begin; j != end; ++j)
            p *= j;

        begin += 1; end += 2; summa += p;
    }

    cout << summa;
}

int main()
{
    firstTask();
    secondTask();
}