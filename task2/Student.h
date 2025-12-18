#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <iostream>

class Group; // forward declaration

class Student : public Person {
private:
    int recordBookId;
    static int nextId;
    Group* group;

public:
    Student();
    Student(const std::string& name, int age, Group* group);
    
    void printInfo() const override;
    void readFromInput() override;

    int getRecordBookId() const;
    Group* getGroup() const;
    void setGroup(Group* group);

    friend std::ostream& operator<<(std::ostream& os, const Student& student);
    friend std::istream& operator>>(std::istream& is, Student& student);
};

#endif