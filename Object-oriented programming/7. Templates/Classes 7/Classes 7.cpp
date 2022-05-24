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
* Classes 7
* ИВТ-21-2б
*/

#include "Pair.h"
#include "SinglyList.h"

int main()
{
	Pair x = Pair(10, 20.52);
	Pair y = Pair(15, 30.25);
	Pair z = Pair(20, 40.43);

	SinglyList<Pair> list;
	list.pushBack(x);
	list.pushBack(y);
	list.pushBack(z);

	for (const auto& v : list)
		std::cout << v << " ";
	std::cout << std::endl;

	list * 10;

	for (const auto& v : list)
		std::cout << v << " ";
}