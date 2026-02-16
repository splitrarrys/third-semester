#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <iostream>

class Group; // предварительное объявление

class Student : public Person {
private:
    Group* group;

public:
    Student();
    Student(const std::string& name, int age, Group* group);
    
    void printInfo() const override;
    void readFromInput() override;

    int getRecordBookId() const; // Возвращает id из Person
    Group* getGroup() const;
    void setGroup(Group* group);

    friend std::ostream& operator<<(std::ostream& os, const Student& student);
    friend std::istream& operator>>(std::istream& is, Student& student);
};

#endif