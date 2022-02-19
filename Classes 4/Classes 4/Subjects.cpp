#include "Subjects.h"

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
    for (auto& pair : subjects.subjects_and_grades_)
        output << pair.first << " — " << pair.second << '\n';

    return output;
}