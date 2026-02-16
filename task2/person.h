#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

class Person {
protected:
    int id;
    std::string name;
    int age;
    static int nextId;

public:
    Person();
    Person(const std::string& name, int age);
    virtual ~Person() = default;

    virtual void printInfo() const;
    virtual void readFromInput();

    int getId() const;
    std::string getName() const;
    int getAge() const;

    friend std::ostream& operator<<(std::ostream& os, const Person& person);
    friend std::istream& operator>>(std::istream& is, Person& person);
};

#endif