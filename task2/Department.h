#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "Discipline.h"
#include <memory>

class Teacher; // forward declaration

class Department {
private:
    std::string name;
    std::unique_ptr<Discipline[]> disciplines;
    int disciplineCount;
    int disciplineCapacity;
    std::unique_ptr<Teacher*[]> teachers;
    int teacherCount;
    int teacherCapacity;

    void resizeDisciplines();
    void resizeTeachers();

public:
    Department();
    Department(const std::string& name);
    ~Department() = default;

    Department(const Department& other);
    Department& operator=(const Department& other);
    Department(Department&& other) noexcept;
    Department& operator=(Department&& other) noexcept;

    std::string getName() const;
    int getDisciplineCount() const;
    const Discipline* getDisciplines() const;
    int getTeacherCount() const;
    Teacher** getTeachers() const;

    void addDiscipline(const Discipline& discipline);
    void removeDiscipline(int index);
    void addTeacher(Teacher* teacher);
    void removeTeacher(int index);

    bool hasDiscipline(const std::string& disciplineName) const;
    Discipline* findDisciplineByName(const std::string& name) const;

    void printInfo() const;

    friend std::ostream& operator<<(std::ostream& os, const Department& department);
    friend std::istream& operator>>(std::istream& is, Department& department);
};

#endif