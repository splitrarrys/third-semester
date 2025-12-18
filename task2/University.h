#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include "Department.h"
#include "Specialty.h"
#include "Group.h"
#include "Teacher.h"
#include "Student.h"
#include <memory>

class University {
private:
    std::string name;
    std::unique_ptr<Department[]> departments;
    int departmentCount;
    int departmentCapacity;
    std::unique_ptr<Specialty[]> specialties;
    int specialtyCount;
    int specialtyCapacity;
    std::unique_ptr<Group[]> groups;
    int groupCount;
    int groupCapacity;

    void resizeDepartments();
    void resizeSpecialties();
    void resizeGroups();

public:
    University();
    University(const std::string& name);
    ~University() = default;

    University(const University& other);
    University& operator=(const University& other);
    University(University&& other) noexcept;
    University& operator=(University&& other) noexcept;

    std::string getName() const;
    int getDepartmentCount() const;
    const Department* getDepartments() const;
    int getSpecialtyCount() const;
    const Specialty* getSpecialties() const;
    int getGroupCount() const;
    const Group* getGroups() const;

    void addDepartment(const Department& department);
    void addSpecialty(const Specialty& specialty);
    void addGroup(const Group& group);

    Student* findStudentByRecordBookId(int recordBookId) const;
    Student* findStudentByName(const std::string& name) const;
    
    void printDisciplinesOfDepartment(const std::string& departmentName) const;
    void printTeachersOfGroup(const std::string& groupName) const;
    void printGroupsOfSpecialty(const std::string& specialtyName) const;

    void printAllDepartments() const;
    void printAllSpecialties() const;
    void printAllGroups() const;
    void printAllStudents() const;

    friend std::ostream& operator<<(std::ostream& os, const University& university);
    friend std::istream& operator>>(std::istream& is, University& university);
};

#endif