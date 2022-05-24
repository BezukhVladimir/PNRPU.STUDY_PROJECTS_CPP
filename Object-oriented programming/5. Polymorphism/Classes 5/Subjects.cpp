#include "Subjects.h"
#include <iostream>

void Subjects::addSubject(const std::string& subject, const Grade& grade) {
    subjects_and_grades_[subject] = grade;
}

void Subjects::eraseSubject(const std::string& subject) {
    subjects_and_grades_.erase(subjects_and_grades_.find(subject));
}

Grade Subjects::getGrade(const std::string& subject) const {
    return (subjects_and_grades_.find(subject))->second;
}

std::map<std::string, Grade> Subjects::getAllSubjects() const {
    return subjects_and_grades_;
}

void Subjects::clear() {
    subjects_and_grades_.clear();
}

std::ostream& operator<<(std::ostream& output, const Subjects& subjects)
{
    for (const auto& pair : subjects.subjects_and_grades_)
        output << pair.first << ": " << static_cast<int>(pair.second) << '\n';

    return output;
}

std::istream& operator>>(std::istream& input, Subjects& subjects)
{
    std::cout << "How many subjects do you want to add? Enter: ";

    size_t how_many; std::cin >> how_many;

    std::string subject; int grade;
    while (how_many--)
    {
        std::cout << "Enter subject: "; std::cin >> subject;
        std::cout << "Enter grade: "; std::cin >> grade;

        subjects.addSubject(subject, static_cast<Grade>(grade));
    }

    return input;
}
