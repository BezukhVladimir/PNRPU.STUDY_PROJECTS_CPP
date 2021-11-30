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
* 
* ИВТ-21-2б
* February 2022
* 
* Лабораторная №7.2. Необязательные параметры функции.
* 
* Написать функцию, которая последовательно находит расстояния
* от точки до точки для произвольного количества точек.
* 
* Написать функцию, которая вычисляет площадь треугольника, заданного координатами вершин.
*
* Написать функцию, которая определяет площадь треугольника, содержащего диагональ наибольшей длины
* выпуклого многоугольника, заданного координатами вершин.
*/

#include <cmath>
#include <cstdarg>
#include <iostream>

struct Point
{
private:
    double x, y;

public:
    void setx(double x) { this->x = x; }
    double getx() const { return this->x; }

    void sety(double y) { this->y = y; }
    double gety() const { return this->y; }

    Point() : x(0.0), y(0.0) {};
    Point(double x, double y) : x(x), y(y) {};

    double distanceToPoint(const Point& other_point) const {
        return sqrt((other_point.x - this->x) * (other_point.x - this->x) +
                    (other_point.y - this->y) * (other_point.y - this->y));
    }

    Point& operator=(const Point& right) {
        this->x = right.x;
        this->y = right.y;
        return *this;
    }

    friend std::istream& operator>>(std::istream& cin_, Point& enter) {
        cin_ >> enter.x;
        cin_ >> enter.y;
        return cin_;
    }
};

double areaOfATriangle(const Point& first_point,
                       const Point& second_point,
                       const Point& third_point)
{
    return abs((third_point.getx() - first_point.getx()) * (second_point.gety() - first_point.gety()) -
               (second_point.getx() - first_point.getx()) * (third_point.gety() - first_point.gety())) * 0.5;
}


void distancesFromPointToPoint(const size_t& number_of_points, 
                               const Point& first_point,
                               const Point second_point, ...)
{
    const size_t number_of_optional_arguments = number_of_points - 2;

    va_list args;
    va_start(args, second_point);

    Point current = first_point, next = second_point;
    std::cout << current.distanceToPoint(next) << std::endl;

    for (size_t i = 0; i != number_of_optional_arguments; ++i)
    {
        current = next;
        next = va_arg(args, Point);
        std::cout << current.distanceToPoint(next) << std::endl;
    }

    va_end(args);
}

double longestDiagonal(const size_t& number_of_points,
                       const Point *array_of_points)
{
    double diagonal = abs(array_of_points[number_of_points - 2].distanceToPoint(array_of_points[0]));
    double longestDiagonal = abs(array_of_points[number_of_points - 1].distanceToPoint(array_of_points[1]));

    if (longestDiagonal < diagonal)
        longestDiagonal = diagonal;

    size_t counter = number_of_points - 2;

    for (size_t i = 0; i != counter; ++i)
    {
        diagonal = abs(array_of_points[i].distanceToPoint(array_of_points[i + 2]));

        if (longestDiagonal < diagonal)
            longestDiagonal = diagonal;
    }

    return longestDiagonal;
}

void firstTask()
{
    const Point A(1, 2), B(3, 1), C(4, 1), D(5, 3), E(4, 4), F(2, 4);
    distancesFromPointToPoint(6, A, B, C, D, E, F);
}

void secondTask()
{
    Point X, Y, Z; std::cin >> X >> Y >> Z;
    std::cout << areaOfATriangle(X, Y, Z) << std::endl;
}

void thirdTask()
{
    size_t number_of_points; std::cin >> number_of_points;
    Point* array_of_points = new Point[number_of_points];
    for (size_t i = 0; i != number_of_points; ++i)
        std::cin >> array_of_points[i];

    std::cout << longestDiagonal(number_of_points, array_of_points);
}


int main()
{
    firstTask();
    secondTask();
    thirdTask();
}