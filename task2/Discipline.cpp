#include "Discipline.h"

Discipline::Discipline() : name(""), hours(0), type("Лекция") {}

Discipline::Discipline(const std::string& name, int hours, const std::string& type) 
    : name(name), hours(hours), type(type) {}

std::string Discipline::getName() const {
    return name;
}

int Discipline::getHours() const {
    return hours;
}

std::string Discipline::getType() const {
    return type;
}

void Discipline::setName(const std::string& name) {
    this->name = name;
}

void Discipline::setHours(int hours) {
    this->hours = hours;
}

void Discipline::setType(const std::string& type) {
    this->type = type;
}

void Discipline::printInfo() const {
    std::cout << name << " (" << type << ", " << hours << " часов)";
}

void Discipline::readFromInput() {
    std::cout << "Введите название дисциплины: ";
    std::getline(std::cin, name);
    std::cout << "Введите количество часов: ";
    std::cin >> hours;
    std::cin.ignore();
    std::cout << "Введите тип (Лекция/Практика/Лабораторная): ";
    std::getline(std::cin, type);
}

std::ostream& operator<<(std::ostream& os, const Discipline& discipline) {
    discipline.printInfo();
    return os;
}

std::istream& operator>>(std::istream& is, Discipline& discipline) {
    discipline.readFromInput();
    return is;
}