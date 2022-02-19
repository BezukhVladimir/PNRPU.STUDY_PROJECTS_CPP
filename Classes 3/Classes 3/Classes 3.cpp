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
* Classes 3
* ИВТ-21-2б
*/

#include "Time.h"
#include <iostream>

int main()
{
    Time a, b, c;
    std::cin >> a >> b; 
    
    ++a;

    std::cout << a << '\n';

    c = (a++) + b;

    std::cout << "a = " << a << '\n'; 
    std::cout << "b = " << b << '\n';
    std::cout << "c = " << c << '\n';

    a.set_min(10); a.set_sec(10);
    b.set_min(10); b.set_sec(10);

    if (a != b)
        std::cout << a << " <~ a != b ~> " << b;
    else
        std::cout << a << " <~ a == b ~> " << b;

    a = a - b; std::cout << '\n';

    if (a != b)
        std::cout << a << " <~ a != b ~> " << b;
    else
        std::cout << a << " <~ a == b ~> " << b;
}