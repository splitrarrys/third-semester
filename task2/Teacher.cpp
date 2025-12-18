#include "Teacher.h"
#include "Department.h"
#include <algorithm>
#include <utility>

Teacher::Teacher() 
    : Person(), position(""), department(nullptr), disciplineCount(0), disciplineCapacity(2) {
    disciplines = std::make_unique<Discipline[]>(disciplineCapacity);
}

Teacher::Teacher(const std::string& name, int age, const std::string& position, Department* department) 
    : Person(name, age), position(position), department(department), 
      disciplineCount(0), disciplineCapacity(2) {
    disciplines = std::make_unique<Discipline[]>(disciplineCapacity);
}

Teacher::Teacher(const Teacher& other) 
    : Person(other), position(other.position), department(other.department),
      disciplineCount(other.disciplineCount), disciplineCapacity(other.disciplineCapacity) {
    disciplines = std::make_unique<Discipline[]>(disciplineCapacity);
    for (int i = 0; i < disciplineCount; i++) {
        disciplines[i] = other.disciplines[i];
    }
}

Teacher& Teacher::operator=(const Teacher& other) {
    if (this != &other) {
        Person::operator=(other);
        position = other.position;
        department = other.department;
        disciplineCount = other.disciplineCount;
        disciplineCapacity = other.disciplineCapacity;

        disciplines = std::make_unique<Discipline[]>(disciplineCapacity);
        for (int i = 0; i < disciplineCount; i++) {
            disciplines[i] = other.disciplines[i];
        }
    }
    return *this;
}

Teacher::Teacher(Teacher&& other) noexcept
    : Person(std::move(other)), 
      position(std::move(other.position)),
      department(other.department),
      disciplines(std::move(other.disciplines)),
      disciplineCount(other.disciplineCount),
      disciplineCapacity(other.disciplineCapacity) {
    other.department = nullptr;
    other.disciplineCount = 0;
    other.disciplineCapacity = 0;
}

Teacher& Teacher::operator=(Teacher&& other) noexcept {
    if (this != &other) {
        Person::operator=(std::move(other));
        position = std::move(other.position);
        department = other.department;
        disciplines = std::move(other.disciplines);
        disciplineCount = other.disciplineCount;
        disciplineCapacity = other.disciplineCapacity;

        other.department = nullptr;
        other.disciplineCount = 0;
        other.disciplineCapacity = 0;
    }
    return *this;
}

void Teacher::resizeDisciplines() {
    if (disciplineCount >= disciplineCapacity) {
        disciplineCapacity *= 2;
        auto newDisciplines = std::make_unique<Discipline[]>(disciplineCapacity);
        for (int i = 0; i < disciplineCount; i++) {
            newDisciplines[i] = std::move(disciplines[i]);
        }
        disciplines = std::move(newDisciplines);
    }
}

void Teacher::printInfo() const {
    std::cout << "Преподаватель [Должность: " << position << "] ";
    Person::printInfo();
    if (department) {
        std::cout << ", Кафедра: " << department->getName();
    }
    std::cout << ", Дисциплин: " << disciplineCount << "\n";

    for (int i = 0; i < disciplineCount; i++) {
        std::cout << "  " << (i + 1) << ". " << disciplines[i] << "\n";
    }
}

void Teacher::readFromInput() {
    Person::readFromInput();
    std::cout << "Введите должность: ";
    std::getline(std::cin, position);
}


std::string Teacher::getPosition() const {
    return position;
}

Department* Teacher::getDepartment() const {
    return department;
}

int Teacher::getDisciplineCount() const {
    return disciplineCount;
}

const Discipline* Teacher::getDisciplines() const {
    return disciplines.get();
}

void Teacher::addDiscipline(const Discipline& discipline) {
    resizeDisciplines();
    disciplines[disciplineCount++] = discipline;
}

void Teacher::removeDiscipline(int index) {
    if (index >= 0 && index < disciplineCount) {
        for (int i = index; i < disciplineCount - 1; i++) {
            disciplines[i] = std::move(disciplines[i + 1]);
        }
        disciplineCount--;
    }
}

bool Teacher::teachesDiscipline(const std::string& disciplineName) const {
    for (int i = 0; i < disciplineCount; i++) {
        if (disciplines[i].getName() == disciplineName) {
            return true;
        }
    }
    return false;
}

std::ostream& operator<<(std::ostream& os, const Teacher& teacher) {
    teacher.printInfo();
    return os;
}

std::istream& operator>>(std::istream& is, Teacher& teacher) {
    teacher.readFromInput();
    return is;
}