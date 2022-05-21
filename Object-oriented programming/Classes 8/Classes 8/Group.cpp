#include "Group.h"
#include <iostream>

Group::Group()
{
    current_ = 0;
    size_ = 0;
}

Group::Group(size_t size)
{
    begin_ = new Object*[size];
    current_ = 0;
    size_ = size;
}

Group::~Group()
{
    if (begin_ != nullptr)
        delete[] begin_;

    begin_ = nullptr;
}

void Group::add()
{
    Object* ptr_object;

    // "id. Type"
    std::cout << "1. Person\n";
    std::cout << "2. Student\n";
    
    int id; std::cin >> id;

    if (id == 1) {
        Person* ptr_person = new (Person);
        ptr_person->input();
        ptr_object = ptr_person;

        if (current_ < size_)
        {
            begin_[current_] = ptr_object;
            ++current_;
        }
    } else if (id == 2) {
        Student* ptr_student = new (Student);
        ptr_student->input();
        ptr_object = ptr_student;

        if (current_ < size_)
        {
            begin_[current_] = ptr_object;
            ++current_;
        }
    } else {
        std::cout << "This id was not found!\n";
    }
}

void Group::del()
{
    if (current_) // если не пустой
        --current_;
}

void Group::show()
{
    if (current_ == 0) {
        std::cout << "This group is empty.\n";
        return;
    }

    Object** ptr = begin_;
    for (size_t i = 0; i != current_; ++i)
    {
        std::cout << "Объект №" << i + 1 << ":\n"; (*ptr)->show(); std::cout << std::endl;
        ++ptr;
    }
}

size_t Group::operator()()
{
    return current_;
}

void Group::handleEvent(const Event& event)
{
    if (event.type == EventType::NOTEMPTY)
    {
        Object** ptr = begin_;

        for (size_t i = 0; i < current_; ++i)
        {
            (*ptr)->handleEvent(event);
            ++ptr;
        }
    }
}
