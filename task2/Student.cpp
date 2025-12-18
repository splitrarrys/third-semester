#include "Student.h"
#include "Group.h"

int Student::nextId = 1000;

Student::Student() : Person(), recordBookId(nextId++), group(nullptr) {}

Student::Student(const std::string& name, int age, Group* group) 
    : Person(name, age), recordBookId(nextId++), group(group) {}

void Student::printInfo() const {
    std::cout << "Студент [Зачетка №: " << recordBookId << "] ";
    Person::printInfo();
    if (group) {
        std::cout << ", Группа: " << group->getName();
    }
}

void Student::readFromInput() {
    Person::readFromInput();
    // Group will be assigned separately
}

int Student::getRecordBookId() const {
    return recordBookId;
}

Group* Student::getGroup() const {
    return group;
}

void Student::setGroup(Group* group) {
    this->group = group;
}

std::ostream& operator<<(std::ostream& os, const Student& student) {
    student.printInfo();
    return os;
}

std::istream& operator>>(std::istream& is, Student& student) {
    student.readFromInput();
    return is;
}