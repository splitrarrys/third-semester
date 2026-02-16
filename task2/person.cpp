#include "Person.h"

int Person::nextId = 1;

Person::Person() : id(nextId++), name(""), age(0) {}

Person::Person(const std::string& name, int age) : id(nextId++), name(name), age(age) {}

void Person::printInfo() const {
    std::cout << "ID: " << id << ", Имя: " << name << ", Возраст: " << age;
}

void Person::readFromInput() {
    std::cout << "Введите имя: ";
    std::getline(std::cin, name);
    std::cout << "Введите возраст: ";
    std::cin >> age;
    std::cin.ignore();
}

int Person::getId() const {
    return id;
}

std::string Person::getName() const {
    return name;
}

int Person::getAge() const {
    return age;
}

std::ostream& operator<<(std::ostream& os, const Person& person) {
    person.printInfo();
    return os;
}

std::istream& operator>>(std::istream& is, Person& person) {
    person.readFromInput();
    return is;
}