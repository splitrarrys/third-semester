#ifndef DISCIPLINE_H
#define DISCIPLINE_H

#include <iostream>
#include <string>

class Discipline {
private:
    std::string name;
    int hours;
    std::string type; // "Лекция", "Практика", "Лабораторная"

public:
    Discipline();
    Discipline(const std::string& name, int hours, const std::string& type);
    
    std::string getName() const;
    int getHours() const;
    std::string getType() const;

    void setName(const std::string& name);
    void setHours(int hours);
    void setType(const std::string& type);

    void printInfo() const;
    void readFromInput();

    friend std::ostream& operator<<(std::ostream& os, const Discipline& discipline);
    friend std::istream& operator>>(std::istream& is, Discipline& discipline);
};

#endif