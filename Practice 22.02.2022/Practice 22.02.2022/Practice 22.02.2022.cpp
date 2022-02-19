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

#include <string>
#include <iostream>

struct Advertising {
	size_t number_of_impressions;
	double CTR; // click-through rate
	double CPC; // cost per click
};

struct FullName {
	std::string forename;
	std::string surname;
	std::string patronym;
};

struct Employee {
	FullName personal_name;
	size_t number_of_days_worked;
	double daily_salary;
	double cash_bonus;
 };

void firstTask()
{
	Advertising example;
	std::cin >> example.number_of_impressions >> example.CTR >> example.CPC;

	std::cout << example.number_of_impressions * example.CTR / 100 * example.CPC << '\n';
}

void secondTask()
{
	Employee example;
	std::cin >> example.personal_name.forename >> example.personal_name.surname >> example.personal_name.patronym >>
				example.number_of_days_worked >> example.daily_salary >> example.cash_bonus;

	std::cout << example.number_of_days_worked * example.daily_salary + example.cash_bonus;
}

int main()
{
	firstTask();
	secondTask();
}