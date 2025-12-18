#ifndef SPECIALTY_H
#define SPECIALTY_H

#include <iostream>
#include <string>
#include <memory>

class Group; // предварительное объявление

class Specialty {
private:
    std::string name;
    std::string code;
    std::unique_ptr<Group*[]> groups;
    int groupCount;
    int groupCapacity;

    void resizeGroups();

public:
    Specialty();
    Specialty(const std::string& name, const std::string& code);
    
    std::string getName() const;
    std::string getCode() const;
    int getGroupCount() const;
    Group** getGroups() const;

    void addGroup(Group* group);
    void removeGroup(int index);

    void printInfo() const;

    friend std::ostream& operator<<(std::ostream& os, const Specialty& specialty);
    friend std::istream& operator>>(std::istream& is, Specialty& specialty);
};

#endif