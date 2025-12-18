#ifndef TEACHER_H
#define TEACHER_H

#include "Person.h"
#include "Discipline.h"
#include <memory>

class Department; // forward declaration

class Teacher : public Person {
private:
    std::string position;  // Должность
    Department* department; // Кафедра
    std::unique_ptr<Discipline[]> disciplines; // Дисциплины
    int disciplineCount;
    int disciplineCapacity;

    void resizeDisciplines();

public:
    Teacher();
    Teacher(const std::string& name, int age, const std::string& position, Department* department);
    ~Teacher() = default;

    Teacher(const Teacher& other);
    Teacher& operator=(const Teacher& other);
    Teacher(Teacher&& other) noexcept;
    Teacher& operator=(Teacher&& other) noexcept;

    void printInfo() const override;
    void readFromInput() override;

    std::string getPosition() const;
    Department* getDepartment() const;
    int getDisciplineCount() const;
    const Discipline* getDisciplines() const;

    void addDiscipline(const Discipline& discipline);
    void removeDiscipline(int index);
    bool teachesDiscipline(const std::string& disciplineName) const;

    friend std::ostream& operator<<(std::ostream& os, const Teacher& teacher);
    friend std::istream& operator>>(std::istream& is, Teacher& teacher);
};

#endif