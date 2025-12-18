#include "Person.h"

Person::Person(const std::string& name, int age) : name(name), age(age) {}

void Person::printInfo() const {
    std::cout << "Имя: " << name << ", Возраст: " << age;
}

void Person::readFromInput() {
    std::cout << "Введите имя: ";
    std::getline(std::cin, name);
    std::cout << "Введите возраст: ";
    std::cin >> age;
    std::cin.ignore();
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