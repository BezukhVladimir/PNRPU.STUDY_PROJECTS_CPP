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
* Люди A, B, C решили пойти в кино:
* 1) A пойдёт в кино тогда и только тогда, когда пойдут B и C.
* 2) A и C пойдут в кино вместе или оба останутся дома.
* 3) Чтобы в кино пошёл C, надо чтобы пошёл B.
* Из трёх утверждений только два истинных. Кто из этих людей пошёл в кино?
*/

#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    const unsigned int A[2] = { 0, 1 }, B[2] = { 0, 1 }, C[2] = { 0, 1 };

    for (const auto &a : A)
        for (const auto &b : B)
            for (const auto &c : C)
                if (((!a || (b && c)) + (a == c) + (!c || b)) == 2)
                    cout << (a ? "A пойдёт\n" : "A не пойдёт\n")
                         << (b ? "B пойдёт\n" : "B не пойдёт\n")
                         << (c ? "C пойдёт\n" : "C не пойдёт\n");
}