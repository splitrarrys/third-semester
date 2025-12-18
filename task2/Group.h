#ifndef GROUP_H
#define GROUP_H

#include "Student.h"
#include "Specialty.h"
#include <memory>

class Teacher; // предварительное объявление

class Group {
private:
    std::string name;
    Specialty* specialty;
    std::unique_ptr<Student[]> students;
    int studentCount;
    int studentCapacity;
    std::unique_ptr<Teacher*[]> teachers;
    int teacherCount;
    int teacherCapacity;

    void resizeStudents();
    void resizeTeachers();

public:
    Group();
    Group(const std::string& name, Specialty* specialty);
    ~Group() = default;

    Group(const Group& other);
    Group& operator=(const Group& other);
    Group(Group&& other) noexcept;
    Group& operator=(Group&& other) noexcept;

    std::string getName() const;
    Specialty* getSpecialty() const;
    int getStudentCount() const;
    const Student* getStudents() const;
    int getTeacherCount() const;
    Teacher** getTeachers() const;

    void addStudent(const Student& student);
    void removeStudent(int index);
    void addTeacher(Teacher* teacher);
    void removeTeacher(int index);

    Student* findStudentByName(const std::string& name) const;
    Student* findStudentByRecordBookId(int recordBookId) const;
    bool hasStudent(const std::string& studentName) const;

    void printInfo() const;

    friend std::ostream& operator<<(std::ostream& os, const Group& group);
    friend std::istream& operator>>(std::istream& is, Group& group);
};

#endif