#include "Group.h"
#include "Teacher.h"
#include <algorithm>
#include <utility>

Group::Group() 
    : name(""), specialty(nullptr), studentCount(0), studentCapacity(2),
      teacherCount(0), teacherCapacity(2) {
    students = std::make_unique<Student[]>(studentCapacity);
    teachers = std::make_unique<Teacher*[]>(teacherCapacity);
}

Group::Group(const std::string& name, Specialty* specialty) 
    : name(name), specialty(specialty), studentCount(0), studentCapacity(2),
      teacherCount(0), teacherCapacity(2) {
    students = std::make_unique<Student[]>(studentCapacity);
    teachers = std::make_unique<Teacher*[]>(teacherCapacity);
}

void Group::resizeStudents() {
    if (studentCount >= studentCapacity) {
        studentCapacity *= 2;
        auto newStudents = std::make_unique<Student[]>(studentCapacity);
        for (int i = 0; i < studentCount; i++) {
            newStudents[i] = std::move(students[i]);
        }
        students = std::move(newStudents);
    }
}

void Group::resizeTeachers() {
    if (teacherCount >= teacherCapacity) {
        teacherCapacity *= 2;
        auto newTeachers = std::make_unique<Teacher*[]>(teacherCapacity);
        for (int i = 0; i < teacherCount; i++) {
            newTeachers[i] = teachers[i];
        }
        teachers = std::move(newTeachers);
    }
}

std::string Group::getName() const {
    return name;
}

Specialty* Group::getSpecialty() const {
    return specialty;
}

int Group::getStudentCount() const {
    return studentCount;
}

const Student* Group::getStudents() const {
    return students.get();
}

int Group::getTeacherCount() const {
    return teacherCount;
}

Teacher** Group::getTeachers() const {
    return teachers.get();
}

void Group::addStudent(const Student& student) {
    resizeStudents();
    students[studentCount++] = student;
    // Обновляем указатель на группу у студента
    students[studentCount - 1].setGroup(this);
}

void Group::removeStudent(int index) {
    if (index >= 0 && index < studentCount) {
        for (int i = index; i < studentCount - 1; i++) {
            students[i] = std::move(students[i + 1]);
            students[i].setGroup(this);
        }
        studentCount--;
    }
}

void Group::addTeacher(Teacher* teacher) {
    resizeTeachers();
    teachers[teacherCount++] = teacher;
}

void Group::removeTeacher(int index) {
    if (index >= 0 && index < teacherCount) {
        for (int i = index; i < teacherCount - 1; i++) {
            teachers[i] = teachers[i + 1];
        }
        teacherCount--;
    }
}

Student* Group::findStudentByName(const std::string& name) const {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].getName() == name) {
            return const_cast<Student*>(&students[i]);
        }
    }
    return nullptr;
}

Student* Group::findStudentByRecordBookId(int recordBookId) const {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].getRecordBookId() == recordBookId) {
            return const_cast<Student*>(&students[i]);
        }
    }
    return nullptr;
}

bool Group::hasStudent(const std::string& studentName) const {
    return findStudentByName(studentName) != nullptr;
}

void Group::printInfo() const {
    std::cout << "Группа: " << name << "\n";
    if (specialty) {
        std::cout << "Специальность: " << specialty->getName() << "\n";
    }
    std::cout << "Студенты (" << studentCount << "):\n";
    for (int i = 0; i < studentCount; i++) {
        std::cout << "  " << (i + 1) << ". " << students[i] << "\n";
    }
    std::cout << "Преподаватели (" << teacherCount << "):\n";
    for (int i = 0; i < teacherCount; i++) {
        if (teachers[i]) {
            std::cout << "  " << (i + 1) << ". " << teachers[i]->getName() << "\n";
        }
    }
}

std::ostream& operator<<(std::ostream& os, const Group& group) {
    group.printInfo();
    return os;
}

std::istream& operator>>(std::istream& is, Group& group) {
    std::cout << "Введите название группы: ";
    std::getline(is, group.name);
    return is;
}