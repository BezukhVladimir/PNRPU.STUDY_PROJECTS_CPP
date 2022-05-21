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

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <iterator>
#include <algorithm>

struct FullName {
    std::string forename;
    std::string surname;
    std::string patronym;

    bool operator==(const FullName& right) const
    {
        return (forename == right.forename) &&
               (surname == right.surname) &&
               (patronym == right.patronym);
    }
};

struct Date {
    unsigned int day;
    unsigned int month;
    unsigned int year;

    bool operator==(const Date& right) const
    {
        return (day == right.day) &&
               (month == right.month) &&
               (year == right.year);                
    }

    bool operator!=(const Date& right) const {
        return !(*this == right);
    }

    bool operator<(const Date& right) const {
        if (year < right.year) return true;
        else if (year == right.year)
        {
            if (month < right.month) return true;
            else if (month == right.month) return day < right.day;
            else return false;
        }
        else return false;
    }
};

struct Address {
    std::string city;
    std::string street_name;
    std::string house_number;

    bool operator==(const Address& right) const
    {
        return (city == right.city) &&
               (street_name == right.street_name) &&
               (house_number == right.house_number);
    }
};

struct Student {
    FullName personal_name;
    Date date_of_birth;
    Address personal_address;
    int personal_rating;

    bool operator==(const Student& right) const
    {
        return (personal_name == right.personal_name) &&
               (date_of_birth == right.date_of_birth) &&
               (personal_address == right.personal_address) &&
               (personal_rating == right.personal_rating);
    }

    friend std::istream& operator>>(std::istream& input, Student& student)
    {
        input >> student.personal_name.forename;
        input >> student.personal_name.surname;
        input >> student.personal_name.patronym;
        input >> student.date_of_birth.day;
        input >> student.date_of_birth.month;
        input >> student.date_of_birth.year;
        input >> student.personal_address.city;
        input >> student.personal_address.street_name;
        input >> student.personal_address.house_number;
        input >> student.personal_rating;

        return input;
    }

    friend std::ostream& operator<<(std::ostream& output, const Student& student)
    {
        output << student.personal_name.forename << ' ';
        output << student.personal_name.surname << ' ';
        output << student.personal_name.patronym << ' ';
        output << student.date_of_birth.day << ' ';
        output << student.date_of_birth.month << ' ';
        output << student.date_of_birth.year << ' ';
        output << student.personal_address.city << ' ';
        output << student.personal_address.street_name << ' ';
        output << student.personal_address.house_number << ' ';
        output << student.personal_rating << '\n';

        return output;
    }
};

int main()
{
    std::vector<Student> students;
    std::ifstream f_input("FileInput.txt");
    std::ofstream f_output("FileOutput.txt");

    while (!f_input.eof()) {
        Student student;
        f_input >> student;
        students.emplace_back(student);
    }

    sort(students.begin(), students.end(),
        [](const Student& left, const Student& right) 
        { return left.date_of_birth < right.date_of_birth; });

    bool flag_new_group = true;
    std::vector<Student> result_students;
    for (auto prev = students.begin(); prev != students.end(); ++prev) { 
        auto curr = prev; ++curr;
        if (curr == students.end()) {
            if (flag_new_group)
                result_students.emplace_back(*prev);

            break;
        }

        if (prev->date_of_birth != curr->date_of_birth) {
            if (flag_new_group)
                result_students.emplace_back(*prev);

            flag_new_group = true;
        } else
            flag_new_group = false;
    }

    std::string surname; std::cin >> surname;
    Student student; std::cin >> student;
    auto iterator = result_students.begin();
    for (; iterator->personal_name.surname != surname; ++iterator);
    result_students.emplace(iterator, student);

    for (auto& result_student : result_students)
        f_output << result_student;

    f_input.close();
    f_output.close();
}