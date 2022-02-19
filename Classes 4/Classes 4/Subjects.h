#include "Grade.h"
#include <map>
#include <string>

class Subjects
{
public:
	void addSubject(const std::string&, const Grade&);
	void eraseSubject(const std::string&);

	Grade getGrade(const std::string&) const;
	std::map<std::string, Grade> getAllSubjects() const;

	void clear();

	friend std::ostream& operator<<(std::ostream&, const Subjects&);

private:
	std::map<std::string, Grade> subjects_and_grades_;
};