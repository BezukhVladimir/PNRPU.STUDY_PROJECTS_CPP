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
* Classes 5
* ИВТ-21-2б
*/

#include "Person.h"
#include "Student.h"

int main()
{	
	Person p_Bezukh;
	Student s_Bezukh;

	p_Bezukh.setPersonalName(FullName("Bezukh", "Vladimir", "Sergeevich"));
	p_Bezukh.setDateOfBirth(Date(unsigned short{ 22 }, unsigned short{ 2 }, unsigned short{ 2000 }));

	s_Bezukh.setPersonalName(FullName("Bezukh", "Vladimir", "Sergeevich"));
	s_Bezukh.setDateOfBirth(Date(unsigned short{22}, unsigned short{2}, unsigned short{2000}));

	s_Bezukh.subjects.addSubject("Mathematics", Grade::GOOD);
	s_Bezukh.subjects.addSubject("Descriptive geometry", Grade::EXCELLENT);
	s_Bezukh.subjects.addSubject("Computer science", Grade::EXCELLENT);

	std::cout << s_Bezukh.getPersonalName() << std::endl;
	std::cout << s_Bezukh.getDateOfBirth() << std::endl;
	std::cout << s_Bezukh.subjects;

	// Демонстрация полиморфизма
	Person* ptr_person;
	Student* ptr_student;

	p_Bezukh.Show();
	s_Bezukh.Show();

	ptr_person = &p_Bezukh;
	ptr_student = &s_Bezukh;
	ptr_person->Show();
	ptr_student->Show();

	ptr_person = &s_Bezukh;
	ptr_person->Show();
}