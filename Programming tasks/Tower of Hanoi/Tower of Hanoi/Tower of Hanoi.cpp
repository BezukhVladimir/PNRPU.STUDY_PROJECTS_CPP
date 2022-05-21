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
* ИВТ-21-2б
*/

#include <iostream>

void move(const char& from, const char& to) {
    std::cout << from << " -> " << to << "\n";
}

void solve(int size, const char& from, const char& to, const char& buffer)
{
    if (size == 0)
        return;

    solve(size - 1, from, buffer, to);
    move(from, to);
    solve(size - 1, buffer, to, from);
}

int main()
{
    int size; std::cin >> size;
    solve(size, '1', '2', '3');
}