#include "University.h"
#include <algorithm>
#include <utility>

University::University() 
    : name(""), departmentCount(0), departmentCapacity(2),
      specialtyCount(0), specialtyCapacity(2), groupCount(0), groupCapacity(2) {
    departments = std::make_unique<Department[]>(departmentCapacity);
    specialties = std::make_unique<Specialty[]>(specialtyCapacity);
    groups = std::make_unique<Group[]>(groupCapacity);
}

University::University(const std::string& name) 
    : name(name), departmentCount(0), departmentCapacity(2),
      specialtyCount(0), specialtyCapacity(2), groupCount(0), groupCapacity(2) {
    departments = std::make_unique<Department[]>(departmentCapacity);
    specialties = std::make_unique<Specialty[]>(specialtyCapacity);
    groups = std::make_unique<Group[]>(groupCapacity);
}

void University::resizeDepartments() {
    if (departmentCount >= departmentCapacity) {
        departmentCapacity *= 2;
        auto newDepartments = std::make_unique<Department[]>(departmentCapacity);
        for (int i = 0; i < departmentCount; i++) {
            newDepartments[i] = std::move(departments[i]);
        }
        departments = std::move(newDepartments);
    }
}

void University::resizeSpecialties() {
    if (specialtyCount >= specialtyCapacity) {
        specialtyCapacity *= 2;
        auto newSpecialties = std::make_unique<Specialty[]>(specialtyCapacity);
        for (int i = 0; i < specialtyCount; i++) {
            newSpecialties[i] = std::move(specialties[i]);
        }
        specialties = std::move(newSpecialties);
    }
}

void University::resizeGroups() {
    if (groupCount >= groupCapacity) {
        groupCapacity *= 2;
        auto newGroups = std::make_unique<Group[]>(groupCapacity);
        for (int i = 0; i < groupCount; i++) {
            newGroups[i] = std::move(groups[i]);
        }
        groups = std::move(newGroups);
    }
}

std::string University::getName() const {
    return name;
}

int University::getDepartmentCount() const {
    return departmentCount;
}

const Department* University::getDepartments() const {
    return departments.get();
}

int University::getSpecialtyCount() const {
    return specialtyCount;
}

const Specialty* University::getSpecialties() const {
    return specialties.get();
}

int University::getGroupCount() const {
    return groupCount;
}

const Group* University::getGroups() const {
    return groups.get();
}

void University::addDepartment(const Department& department) {
    resizeDepartments();
    departments[departmentCount++] = department;
}

void University::addSpecialty(const Specialty& specialty) {
    resizeSpecialties();
    specialties[specialtyCount++] = specialty;
}

void University::addGroup(const Group& group) {
    resizeGroups();
    groups[groupCount++] = group;
}

Student* University::findStudentByRecordBookId(int recordBookId) const {
    for (int g = 0; g < groupCount; g++) {
        Student* student = groups[g].findStudentByRecordBookId(recordBookId);
        if (student) {
            return student;
        }
    }
    return nullptr;
}

Student* University::findStudentByName(const std::string& name) const {
    for (int g = 0; g < groupCount; g++) {
        Student* student = groups[g].findStudentByName(name);
        if (student) {
            return student;
        }
    }
    return nullptr;
}

void University::printDisciplinesOfDepartment(const std::string& departmentName) const {
    std::cout << "\n=== ДИСЦИПЛИНЫ КАФЕДРЫ " << departmentName << " ===\n";
    
    for (int i = 0; i < departmentCount; i++) {
        if (departments[i].getName() == departmentName) {
            const Discipline* disciplines = departments[i].getDisciplines();
            int count = departments[i].getDisciplineCount();
            
            if (count == 0) {
                std::cout << "На кафедре нет дисциплин.\n";
            } else {
                for (int j = 0; j < count; j++) {
                    std::cout << "  " << (j + 1) << ". " << disciplines[j] << "\n";
                }
            }
            return;
        }
    }
    std::cout << "Кафедра не найдена.\n";
}

void University::printTeachersOfGroup(const std::string& groupName) const {
    std::cout << "\n=== ПРЕПОДАВАТЕЛИ ГРУППЫ " << groupName << " ===\n";
    
    for (int i = 0; i < groupCount; i++) {
        if (groups[i].getName() == groupName) {
            Teacher** teachers = groups[i].getTeachers();
            int count = groups[i].getTeacherCount();
            
            if (count == 0) {
                std::cout << "У группы нет преподавателей.\n";
            } else {
                for (int j = 0; j < count; j++) {
                    if (teachers[j]) {
                        std::cout << "  " << (j + 1) << ". " << teachers[j]->getName();
                        if (teachers[j]->getDepartment()) {
                            std::cout << " (" << teachers[j]->getDepartment()->getName() << ")";
                        }
                        std::cout << "\n";
                    }
                }
            }
            return;
        }
    }
    std::cout << "Группа не найдена.\n";
}

void University::printGroupsOfSpecialty(const std::string& specialtyName) const {
    std::cout << "\n=== ГРУППЫ СПЕЦИАЛЬНОСТИ " << specialtyName << " ===\n";
    
    for (int i = 0; i < specialtyCount; i++) {
        if (specialties[i].getName() == specialtyName) {
            Group** groups = specialties[i].getGroups();
            int count = specialties[i].getGroupCount();
            
            if (count == 0) {
                std::cout << "На специальности нет групп.\n";
            } else {
                for (int j = 0; j < count; j++) {
                    if (groups[j]) {
                        std::cout << "  " << (j + 1) << ". " << groups[j]->getName();
                        std::cout << " (" << groups[j]->getStudentCount() << " студентов)\n";
                    }
                }
            }
            return;
        }
    }
    std::cout << "Специальность не найдена.\n";
}

void University::printAllDepartments() const {
    std::cout << "\n=== ВСЕ КАФЕДРЫ ===\n";
    for (int i = 0; i < departmentCount; i++) {
        std::cout << "  " << (i + 1) << ". " << departments[i].getName() << "\n";
    }
}

void University::printAllSpecialties() const {
    std::cout << "\n=== ВСЕ СПЕЦИАЛЬНОСТИ ===\n";
    for (int i = 0; i < specialtyCount; i++) {
        std::cout << "  " << (i + 1) << ". " << specialties[i].getName() 
                  << " (Код: " << specialties[i].getCode() << ")\n";
    }
}

void University::printAllGroups() const {
    std::cout << "\n=== ВСЕ ГРУППЫ ===\n";
    for (int i = 0; i < groupCount; i++) {
        std::cout << "  " << (i + 1) << ". " << groups[i].getName();
        if (groups[i].getSpecialty()) {
            std::cout << " (" << groups[i].getSpecialty()->getName() << ")";
        }
        std::cout << " - " << groups[i].getStudentCount() << " студентов\n";
    }
}

void University::printAllStudents() const {
    std::cout << "\n=== ВСЕ СТУДЕНТЫ ===\n";
    int totalStudents = 0;
    
    for (int i = 0; i < groupCount; i++) {
        const Student* students = groups[i].getStudents();
        int studentCount = groups[i].getStudentCount();
        
        for (int j = 0; j < studentCount; j++) {
            std::cout << "  " << (++totalStudents) << ". " << students[j] << "\n";
        }
    }
    
    if (totalStudents == 0) {
        std::cout << "В университете нет студентов.\n";
    }
}

std::ostream& operator<<(std::ostream& os, const University& university) {
    os << "\n=== ИНФОРМАЦИЯ ОБ УНИВЕРСИТЕТЕ ===\n";
    os << "Название: " << university.name << "\n";
    os << "Количество кафедр: " << university.departmentCount << "\n";
    os << "Количество специальностей: " << university.specialtyCount << "\n";
    os << "Количество групп: " << university.groupCount << "\n";
    
    int totalStudents = 0;
    for (int i = 0; i < university.groupCount; i++) {
        totalStudents += university.groups[i].getStudentCount();
    }
    os << "Общее количество студентов: " << totalStudents << "\n";
    
    return os;
}

std::istream& operator>>(std::istream& is, University& university) {
    std::cout << "Введите название университета: ";
    std::getline(is, university.name);
    
    int numDepts, numSpecs, numGroups;
    
    std::cout << "Введите количество кафедр: ";
    is >> numDepts;
    is.ignore();
    
    for (int i = 0; i < numDepts; i++) {
        std::cout << "\nКафедра #" << (i + 1) << ":\n";
        Department dept;
        is >> dept;
        university.addDepartment(dept);
    }
    
    std::cout << "\nВведите количество специальностей: ";
    is >> numSpecs;
    is.ignore();
    
    for (int i = 0; i < numSpecs; i++) {
        std::cout << "\nСпециальность #" << (i + 1) << ":\n";
        Specialty spec;
        is >> spec;
        university.addSpecialty(spec);
    }
    
    std::cout << "\nВведите количество групп: ";
    is >> numGroups;
    is.ignore();
    
    for (int i = 0; i < numGroups; i++) {
        std::cout << "\nГруппа #" << (i + 1) << ":\n";
        Group group;
        is >> group;
        university.addGroup(group);
    }
    
    return is;
}