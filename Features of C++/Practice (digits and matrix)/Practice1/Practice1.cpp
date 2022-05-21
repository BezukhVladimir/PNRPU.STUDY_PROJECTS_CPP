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
* Найти сумму цифр натурального числа и вывести это число в обратном порядке.
*/

#include <iostream>

using namespace std;

unsigned int firstTask(unsigned int N)
{
    unsigned int digit_summa = 0;

    while (N > 0)
    {
        digit_summa += N % 10;
        N /= 10;
    }

    return digit_summa;
}

unsigned int secondTask(unsigned int N)
{
    unsigned int t = 0;

    while (N > 0)
    {
        t = (t * 10) + (N % 10);
        N /= 10;
    }

    return t;
}

void thirdTask(const unsigned int &S)
{
    for (size_t i = 0; i != S; ++i)
    {
        for (size_t j = 0; j != S; ++j)
            cout << "* "; 
        
        cout << "\n";
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    unsigned int N; 

    cin >> N; const unsigned int DIGIT_SUMMA_N = firstTask(N);
    cout << DIGIT_SUMMA_N << "\n";

    cin >> N; const unsigned int REVERSE_N = secondTask(N);
    cout << REVERSE_N << "\n";

    cin >> N; thirdTask(N);
}