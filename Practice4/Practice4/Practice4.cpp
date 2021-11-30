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
* Методы приближенного поиска корней нелинейных уравнений: бинарный и Ньютона. 
*/

#include <cmath>
#include <iostream>

using namespace std;

double fun(const double& x) { return 3 * sin(sqrt(x)) + 0.35 * x - 3.8; } // 2.29854
double dfun(const double& x) { double r = sqrt(x);  return 3 * cos(r) / 2 * r + 0.35; }

void dichotomySearchAlgorithm()
{
    double a = 2, b = 3;
    const double EPSILON = 0.000001;

    while (abs(a - b) >= EPSILON)
    {
        double x = (a + b) / 2;
        double f_a = fun(a), f_x = fun(x), f_b = fun(b);
        
        if (f_a * f_x > 0)
            a = x;
        else
            b = x;
    }

    cout << "Дихотомический поиск: " << b << "\n";
}

void newtonsMethod()
{
        double a = 2, b = a - fun(a) / dfun(a);
        const double EPSILON = 0.000001;
        
        while (abs(a - b) >= EPSILON)
        {
            a = b;
            b = a - fun(a) / dfun(a);
        }

        cout << "Метод Ньютона: " << b << '\n';
}

void thirdMethod()
{
    double x0, x1, d, c, r, ra, rb, l;
    const double e = 0.000001, a = 2, b = 3;

    c = abs(((a + b) / 2));

    ra = abs(dfun(a));
    rb = abs(dfun(b));

    r = (ra > rb) ? ra : rb;

    l = (dfun(c) > 0) ? (-0.5 / r) : (0.5 / r);

    x0 = c;

    do
    {
        x1 = x0 + l * fun(x0);
        d = x1 - x0;
        x0 = x1;
    } while (abs(d) > e);

    cout << "Метод итераций : " << x1;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    dichotomySearchAlgorithm();
    newtonsMethod();
    thirdMethod();
}

#include <iostream>

using namespace std;

template<typename T>
void insertSort(T* a, size_t size)
{
    for (size_t i = 1; i != size; ++i)
        for (size_t j = i - 1; j >= 0 && a[j] > a[j + 1]; --j)
            swap(a[j], a[j + 1]);
}

int main()
{
    size_t n; cin >> n;
    int* array = new int[n];
    for (size_t i = 0; i != n; ++i)
        cin >> array[i];

    insertSort(array, n);

    for (size_t i = 0; i != n; ++i)
        cout << array[i] << ' ';

    return 0;
}