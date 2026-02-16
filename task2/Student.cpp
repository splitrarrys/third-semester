#include "Student.h"
#include "Group.h"

Student::Student() : Person(), group(nullptr) {}

Student::Student(const std::string& name, int age, Group* group) 
    : Person(name, age), group(group) {}

void Student::printInfo() const {
    std::cout << "Студент ";
    Person::printInfo();
    if (group) {
        std::cout << ", Группа: " << group->getName();
    }
}

void Student::readFromInput() {
    Person::readFromInput();
    // Группа будет назначена отдельно
}

int Student::getRecordBookId() const {
    return getId(); // Используем id из Person как номер зачетки
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