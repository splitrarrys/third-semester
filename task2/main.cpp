#include <iostream>
#include "University.h"

enum class Command {
    ShowStudents = 1,
    FindStudentById = 2,
    FindStudentByName = 3,
    ShowDepartmentDisciplines = 4,
    ShowGroupTeachers = 5,
    ShowSpecialtyGroups = 6,
    ShowAllInfo = 7,
    Exit = 8
};

void printMenu() {
    std::cout << "\n=== СИСТЕМА УПРАВЛЕНИЯ УНИВЕРСИТЕТОМ ===\n";
    std::cout << static_cast<int>(Command::ShowStudents) << " - Показать всех студентов\n";
    std::cout << static_cast<int>(Command::FindStudentById) << " - Найти студента по номеру зачетки\n";
    std::cout << static_cast<int>(Command::FindStudentByName) << " - Найти студента по ФИО\n";
    std::cout << static_cast<int>(Command::ShowDepartmentDisciplines) << " - Показать дисциплины кафедры\n";
    std::cout << static_cast<int>(Command::ShowGroupTeachers) << " - Показать преподавателей группы\n";
    std::cout << static_cast<int>(Command::ShowSpecialtyGroups) << " - Показать группы специальности\n";
    std::cout << static_cast<int>(Command::ShowAllInfo) << " - Показать всю информацию об университете\n";
    std::cout << static_cast<int>(Command::Exit) << " - Выход\n";
    std::cout << "Выберите опцию: ";
}

int main() {
    // Создание университета с тестовыми данными
    University university("Национальный технический университет");
    
    // Создание кафедр
    Department csDept("Кафедра информатики и вычислительной техники");
    Department mathDept("Кафедра высшей математики");
    Department physicsDept("Кафедра общей физики");
    
    // Создание специальностей
    Specialty csSpecialty("Прикладная информатика", "09.03.03");
    Specialty seSpecialty("Программная инженерия", "09.03.04");
    Specialty mathSpecialty("Прикладная математика", "01.03.04");
    
    // Создание групп
    Group csGroup1("ПИ-101", &csSpecialty);
    Group csGroup2("ПИ-102", &csSpecialty);
    Group seGroup1("ПИН-101", &seSpecialty);
    Group mathGroup1("ПМ-101", &mathSpecialty);
    
    // Создание преподавателей
    Teacher profIvanov("Иванов Александр Сергеевич", 48, "Профессор", &csDept);
    Teacher profPetrova("Петрова Мария Владимировна", 52, "Профессор", &mathDept);
    Teacher lectSidorov("Сидоров Дмитрий Николаевич", 38, "Доцент", &csDept);
    Teacher lectKozlova("Козлова Анна Петровна", 42, "Доцент", &physicsDept);
    Teacher asstSmirnov("Смирнов Алексей Иванович", 35, "Ассистент", &csDept);
    
    // Создание дисциплин
    Discipline programming("Программирование", 120, "Лекция");
    Discipline algorithms("Алгоритмы и структуры данных", 90, "Лекция");
    Discipline calculus("Математический анализ", 60, "Практика");
    Discipline physics("Общая физика", 75, "Лекция");
    Discipline webDev("Веб-разработка", 80, "Лабораторная");
    Discipline discreteMath("Дискретная математика", 70, "Практика");
    Discipline databases("Базы данных", 85, "Лекция");
    Discipline oop("Объектно-ориентированное программирование", 95, "Лекция");
    
    // Добавление дисциплин на кафедры
    csDept.addDiscipline(programming);
    csDept.addDiscipline(algorithms);
    csDept.addDiscipline(webDev);
    csDept.addDiscipline(discreteMath);
    csDept.addDiscipline(databases);
    csDept.addDiscipline(oop);
    
    mathDept.addDiscipline(calculus);
    physicsDept.addDiscipline(physics);
    
    // Назначение дисциплин преподавателям
    profIvanov.addDiscipline(programming);
    profIvanov.addDiscipline(algorithms);
    profPetrova.addDiscipline(calculus);
    profPetrova.addDiscipline(discreteMath);
    lectSidorov.addDiscipline(webDev);
    lectSidorov.addDiscipline(databases);
    lectKozlova.addDiscipline(physics);
    asstSmirnov.addDiscipline(oop);
    
    // Добавление кафедр, специальностей и групп в университет
    university.addDepartment(csDept);
    university.addDepartment(mathDept);
    university.addDepartment(physicsDept);
    
    university.addSpecialty(csSpecialty);
    university.addSpecialty(seSpecialty);
    university.addSpecialty(mathSpecialty);
    
    university.addGroup(csGroup1);
    university.addGroup(csGroup2);
    university.addGroup(seGroup1);
    university.addGroup(mathGroup1);
    
    // Создание студентов
    Student student1("Смирнов Дмитрий Александрович", 20, &csGroup1);
    Student student2("Иванова Мария Сергеевна", 21, &csGroup1);
    Student student3("Петров Алексей Владимирович", 19, &csGroup2);
    Student student4("Сидорова Анна Дмитриевна", 22, &seGroup1);
    Student student5("Козлов Иван Николаевич", 20, &mathGroup1);
    Student student6("Морозова Екатерина Павловна", 21, &csGroup2);
    Student student7("Волков Сергей Андреевич", 23, &seGroup1);
    Student student8("Лебедева Ольга Игоревна", 20, &mathGroup1);
    Student student9("Федоров Павел Михайлович", 22, &csGroup1);
    Student student10("Новикова Татьяна Викторовна", 21, &seGroup1);
    
    // Добавление студентов в группы
    csGroup1.addStudent(student1);
    csGroup1.addStudent(student2);
    csGroup1.addStudent(student9);
    
    csGroup2.addStudent(student3);
    csGroup2.addStudent(student6);
    
    seGroup1.addStudent(student4);
    seGroup1.addStudent(student7);
    seGroup1.addStudent(student10);
    
    mathGroup1.addStudent(student5);
    mathGroup1.addStudent(student8);
    
    // Назначение преподавателей группам
    csGroup1.addTeacher(&profIvanov);
    csGroup1.addTeacher(&profPetrova);
    csGroup1.addTeacher(&asstSmirnov);
    
    csGroup2.addTeacher(&profIvanov);
    csGroup2.addTeacher(&lectSidorov);
    
    seGroup1.addTeacher(&lectSidorov);
    seGroup1.addTeacher(&asstSmirnov);
    
    mathGroup1.addTeacher(&profPetrova);
    mathGroup1.addTeacher(&lectKozlova);
    
    // Добавление групп на специальности
    csSpecialty.addGroup(&csGroup1);
    csSpecialty.addGroup(&csGroup2);
    seSpecialty.addGroup(&seGroup1);
    mathSpecialty.addGroup(&mathGroup1);
    
    // Добавление преподавателей на кафедры
    csDept.addTeacher(&profIvanov);
    csDept.addTeacher(&lectSidorov);
    csDept.addTeacher(&asstSmirnov);
    
    mathDept.addTeacher(&profPetrova);
    physicsDept.addTeacher(&lectKozlova);
    
    // Главное меню
    int choice = 0;
    do {
        printMenu();
        std::cin >> choice;
        std::cin.ignore();
        
        switch (static_cast<Command>(choice)) {
            case Command::ShowStudents: {
                std::cout << "\n=== ВСЕ СТУДЕНТЫ УНИВЕРСИТЕТА ===\n";
                university.printAllStudents();
                break;
            }
            
            case Command::FindStudentById: {
                int id;
                std::cout << "Введите номер зачетной книжки: ";
                std::cin >> id;
                std::cin.ignore();
                
                Student* student = university.findStudentByRecordBookId(id);
                if (student) {
                    std::cout << "\nСтудент найден:\n" << *student << "\n";
                } else {
                    std::cout << "Студент не найден.\n";
                }
                break;
            }
            
            case Command::FindStudentByName: {
                std::string name;
                std::cout << "Введите ФИО студента: ";
                std::getline(std::cin, name);
                
                Student* student = university.findStudentByName(name);
                if (student) {
                    std::cout << "\nСтудент найден:\n" << *student << "\n";
                } else {
                    std::cout << "Студент не найден.\n";
                }
                break;
            }
            
            case Command::ShowDepartmentDisciplines: {
                std::string deptName;
                std::cout << "Введите название кафедры: ";
                std::getline(std::cin, deptName);
                
                university.printDisciplinesOfDepartment(deptName);
                break;
            }
            
            case Command::ShowGroupTeachers: {
                std::string groupName;
                std::cout << "Введите название группы: ";
                std::getline(std::cin, groupName);
                
                university.printTeachersOfGroup(groupName);
                break;
            }
            
            case Command::ShowSpecialtyGroups: {
                std::string specialtyName;
                std::cout << "Введите название специальности: ";
                std::getline(std::cin, specialtyName);
                
                university.printGroupsOfSpecialty(specialtyName);
                break;
            }
            
            case Command::ShowAllInfo:
                std::cout << university;
                std::cout << "\n--- Детальная информация ---\n";
                university.printAllDepartments();
                university.printAllSpecialties();
                university.printAllGroups();
                break;
                
            case Command::Exit:
                std::cout << "До свидания!\n";
                break;
                
            default:
                std::cout << "Неверная опция. Попробуйте снова.\n";
        }
    } while (choice != static_cast<int>(Command::Exit));
    
    return 0;
}