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
* Classes 2
* ИВТ-21-2б
*/

#include <iostream>

class FullName
{
public:
    friend std::istream& operator>>(std::istream& input, FullName& full_name)
    {
        input >> full_name.surname_ >> full_name.forename_ >> full_name.patronym_;

        return input;
    }
    friend std::ostream& operator<<(std::ostream& output, const FullName& full_name)
    {
        output << full_name.surname_ << ' ' << full_name.forename_ << ' ' << full_name.patronym_;

        return output;
    }

private:
    std::string surname_;
    std::string forename_;
    std::string patronym_;
};

class Employee
{
public:
    Employee() { FullName personal_name_; double salary_; double bonus_percentage_; }
    Employee(FullName personal_name = FullName(), double salary = 0.0, double bonus_percentage = 0.0) :
        personal_name_(personal_name), salary_(salary), bonus_percentage_(bonus_percentage) {}
    Employee(const Employee& copy) :
        personal_name_(copy.personal_name_), salary_(copy.salary_), bonus_percentage_(copy.bonus_percentage_) {}
    ~Employee() {}

    FullName getName() { return personal_name_; }
    double getSalary() { return salary_; }
    double getBonusPercentage() { return bonus_percentage_; }

    void setName(const FullName& personal_name) { personal_name_ = personal_name; }
    void setSalary(const double& salary) { salary_ = salary; }
    void setBonusPercentage(const double& bonus_percentage) { bonus_percentage_ = bonus_percentage; }

    friend std::istream& operator>>(std::istream& input, Employee& employee)
    {
        input >> employee.personal_name_ >> employee.salary_ >> employee.bonus_percentage_;

        return input;
    }
    friend std::ostream& operator<<(std::ostream& output, const Employee& employee)
    {
        output << employee.personal_name_ << ' ' << employee.salary_ << ' ' << employee.bonus_percentage_;

        return output;
    }

private:
    FullName personal_name_;
    double salary_;
    double bonus_percentage_;
};

int main()
{
}