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
* Classes 1
* ИВТ-21-2б
*/

#include <cmath>
#include <iomanip>
#include <iostream>

class Progression
{
public:
    Progression() : first_(0.0), second_(0.0) {}

    Progression(const double& a0, const double& r) : first_(a0), second_(r) {}

    double element(int j) { return first_ * pow(second_, j - 1); }

private:
    double first_;
    double second_;
};

int main()
{
    setlocale(LC_ALL, "Russian");

    // a_j = a_0 * r^(j - 1)

    size_t j;
    double a0, r;

    std::cout << "Введите значение первого члена прогрессии: "; std::cin >> a0;
    std::cout << "Введите значение постоянного отношения: ";    std::cin >> r;
    std::cout << "Введите индекс искомого члена прогрессии: ";  std::cin >> j;

    std::cout << "a_" << j << " = " << std::setprecision(10) << Progression(a0, r).element(j) << std::endl;
}