#include "Department.h"
#include "Teacher.h"
#include <algorithm>
#include <utility>

Department::Department() 
    : name(""), disciplineCount(0), disciplineCapacity(2), 
      teacherCount(0), teacherCapacity(2) {
    disciplines = std::make_unique<Discipline[]>(disciplineCapacity);
    teachers = std::make_unique<Teacher*[]>(teacherCapacity);
}

Department::Department(const std::string& name) 
    : name(name), disciplineCount(0), disciplineCapacity(2),
      teacherCount(0), teacherCapacity(2) {
    disciplines = std::make_unique<Discipline[]>(disciplineCapacity);
    teachers = std::make_unique<Teacher*[]>(teacherCapacity);
}

void Department::resizeDisciplines() {
    if (disciplineCount >= disciplineCapacity) {
        disciplineCapacity *= 2;
        auto newDisciplines = std::make_unique<Discipline[]>(disciplineCapacity);
        for (int i = 0; i < disciplineCount; i++) {
            newDisciplines[i] = std::move(disciplines[i]);
        }
        disciplines = std::move(newDisciplines);
    }
}

void Department::resizeTeachers() {
    if (teacherCount >= teacherCapacity) {
        teacherCapacity *= 2;
        auto newTeachers = std::make_unique<Teacher*[]>(teacherCapacity);
        for (int i = 0; i < teacherCount; i++) {
            newTeachers[i] = teachers[i];
        }
        teachers = std::move(newTeachers);
    }
}

std::string Department::getName() const {
    return name;
}

int Department::getDisciplineCount() const {
    return disciplineCount;
}

const Discipline* Department::getDisciplines() const {
    return disciplines.get();
}

int Department::getTeacherCount() const {
    return teacherCount;
}

Teacher** Department::getTeachers() const {
    return teachers.get();
}

void Department::addDiscipline(const Discipline& discipline) {
    resizeDisciplines();
    disciplines[disciplineCount++] = discipline;
}

void Department::removeDiscipline(int index) {
    if (index >= 0 && index < disciplineCount) {
        for (int i = index; i < disciplineCount - 1; i++) {
            disciplines[i] = std::move(disciplines[i + 1]);
        }
        disciplineCount--;
    }
}

void Department::addTeacher(Teacher* teacher) {
    resizeTeachers();
    teachers[teacherCount++] = teacher;
}

void Department::removeTeacher(int index) {
    if (index >= 0 && index < teacherCount) {
        for (int i = index; i < teacherCount - 1; i++) {
            teachers[i] = teachers[i + 1];
        }
        teacherCount--;
    }
}

bool Department::hasDiscipline(const std::string& disciplineName) const {
    for (int i = 0; i < disciplineCount; i++) {
        if (disciplines[i].getName() == disciplineName) {
            return true;
        }
    }
    return false;
}

Discipline* Department::findDisciplineByName(const std::string& name) const {
    for (int i = 0; i < disciplineCount; i++) {
        if (disciplines[i].getName() == name) {
            return &disciplines[i];
        }
    }
    return nullptr;
}


void Department::printInfo() const {
    std::cout << "Кафедра: " << name << "\n";
    std::cout << "Дисциплины (" << disciplineCount << "):\n";
    for (int i = 0; i < disciplineCount; i++) {
        std::cout << "  " << (i + 1) << ". " << disciplines[i] << "\n";
    }
    std::cout << "Преподаватели (" << teacherCount << "):\n";
    for (int i = 0; i < teacherCount; i++) {
        std::cout << "  " << (i + 1) << ". " << teachers[i]->getName() << " (" 
                  << teachers[i]->getPosition() << ")\n";
    }
}

std::istream& operator>>(std::istream& is, Department& department) {
    std::cout << "Введите название кафедры: ";
    std::getline(is, department.name);
    return is;
}