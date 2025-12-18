#include "Specialty.h"
#include "Group.h"

Specialty::Specialty() 
    : name(""), code(""), groupCount(0), groupCapacity(2) {
    groups = std::make_unique<Group*[]>(groupCapacity);
}

Specialty::Specialty(const std::string& name, const std::string& code) 
    : name(name), code(code), groupCount(0), groupCapacity(2) {
    groups = std::make_unique<Group*[]>(groupCapacity);
}

void Specialty::resizeGroups() {
    if (groupCount >= groupCapacity) {
        groupCapacity *= 2;
        auto newGroups = std::make_unique<Group*[]>(groupCapacity);
        for (int i = 0; i < groupCount; i++) {
            newGroups[i] = groups[i];
        }
        groups = std::move(newGroups);
    }
}

std::string Specialty::getName() const {
    return name;
}

std::string Specialty::getCode() const {
    return code;
}

int Specialty::getGroupCount() const {
    return groupCount;
}

Group** Specialty::getGroups() const {
    return groups.get();
}

void Specialty::addGroup(Group* group) {
    resizeGroups();
    groups[groupCount++] = group;
}

void Specialty::removeGroup(int index) {
    if (index >= 0 && index < groupCount) {
        for (int i = index; i < groupCount - 1; i++) {
            groups[i] = groups[i + 1];
        }
        groupCount--;
    }
}

void Specialty::printInfo() const {
    std::cout << "Специальность: " << name << " (Код: " << code << ")\n";
    std::cout << "Группы (" << groupCount << "):\n";
    for (int i = 0; i < groupCount; i++) {
        if (groups[i]) {
            std::cout << "  " << (i + 1) << ". " << groups[i]->getName() << "\n";
        }
    }
}

std::ostream& operator<<(std::ostream& os, const Specialty& specialty) {
    specialty.printInfo();
    return os;
}

std::istream& operator>>(std::istream& is, Specialty& specialty) {
    std::cout << "Введите название специальности: ";
    std::getline(is, specialty.name);
    std::cout << "Введите код специальности: ";
    std::getline(is, specialty.code);
    return is;
}