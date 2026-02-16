#include "CppUnitTest.h"
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "Department.h"
#include "Discipline.h"
#include "Group.h"
#include "Specialty.h"
#include "University.h"
#include <sstream>
#include <memory>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UniversityTests
{
    TEST_CLASS(PersonTests) {
    public:
        TEST_METHOD(PersonConstructor_ValidData_Success) {
            Person person1("Иванов Иван Иванович", 25);
            Person person2("Петров Петр Петрович", 30);
            
            Assert::AreEqual(std::string("Иванов Иван Иванович"), person1.getName());
            Assert::AreEqual(25, person1.getAge());
            Assert::IsTrue(person2.getId() > person1.getId()); // ID увеличивается
        }

        TEST_METHOD(PersonDefaultConstructor_Success) {
            Person person1;
            Person person2;
            
            Assert::AreEqual(std::string(""), person1.getName());
            Assert::AreEqual(0, person1.getAge());
            Assert::IsTrue(person2.getId() > person1.getId()); // ID увеличивается
        }

        TEST_METHOD(PersonPrintInfo_ValidData_OutputsCorrectInfo) {
            Person person("Петрова Мария Сергеевна", 22);
            std::ostringstream os;
            os << person;
            
            std::string result = os.str();
            Assert::IsTrue(result.find("ID:") != std::string::npos); // Проверяем наличие ID
            Assert::IsFalse(result.empty());
        }
    };
    
    TEST_CLASS(StudentTests) {
    public:
        TEST_METHOD(StudentConstructor_ValidData_Success) {
            Group group("ПИ-101", nullptr);
            Student student1("Смирнов Дмитрий Александрович", 20, &group);
            Student student2("Иванова Мария Сергеевна", 21, &group);
            
            Assert::AreEqual(std::string("Смирнов Дмитрий Александрович"), student1.getName());
            Assert::AreEqual(20, student1.getAge());
            Assert::IsTrue(student2.getRecordBookId() > student1.getRecordBookId()); // ID увеличивается
        }

        TEST_METHOD(StudentDefaultConstructor_Success) {
            Student student1;
            Student student2;
            
            Assert::AreEqual(std::string(""), student1.getName());
            Assert::AreEqual(0, student1.getAge());
            Assert::IsNull(student1.getGroup());
            Assert::IsTrue(student2.getRecordBookId() > student1.getRecordBookId());
        }

        TEST_METHOD(StudentPrintInfo_ValidData_OutputsCorrectInfo) {
            Group group("ПИ-101", nullptr);
            Student student("Козлова Анна Петровна", 21, &group);
            std::ostringstream os;
            
            os << student;
            
            std::string result = os.str();
            Assert::IsTrue(result.find("Студент") != std::string::npos);
            Assert::IsTrue(result.find("ID:") != std::string::npos); // Проверяем наличие ID
        }

        TEST_METHOD(StudentFindByName_Success) {
            Specialty spec("Тест", "Т-01");
            Group group("ТЕСТ-101", &spec);
            
            Student student1("Волков Сергей Андреевич", 22, &group);
            Student student2("Лебедева Ольга Игоревна", 21, &group);
            
            group.addStudent(student1);
            group.addStudent(student2);
            
            Student* found = group.findStudentByName("Волков Сергей Андреевич");
            Assert::IsNotNull(found);
            Assert::AreEqual(std::string("Волков Сергей Андреевич"), found->getName());
            
            Student* notFound = group.findStudentByName("Несуществующий");
            Assert::IsNull(notFound);
        }
        
        TEST_METHOD(StudentFindByRecordBookId_Success) {
            Specialty spec("Тест", "Т-01");
            Group group("ТЕСТ-101", &spec);
            
            Student student1("Волков Сергей Андреевич", 22, &group);
            Student student2("Лебедева Ольга Игоревна", 21, &group);
            
            group.addStudent(student1);
            group.addStudent(student2);
            
            int id1 = student1.getRecordBookId();
            Student* found = group.findStudentByRecordBookId(id1);
            Assert::IsNotNull(found);
            Assert::AreEqual(std::string("Волков Сергей Андреевич"), found->getName());
            
            Student* notFound = group.findStudentByRecordBookId(999999);
            Assert::IsNull(notFound);
        }
    };
    
    TEST_CLASS(TeacherTests) {
    public:
        TEST_METHOD(TeacherConstructor_ValidData_Success) {
            Department dept("Кафедра информатики");
            Teacher teacher("Иванов Александр Сергеевич", 45, "Профессор", &dept);
            
            Assert::AreEqual(std::string("Иванов Александр Сергеевич"), teacher.getName());
            Assert::AreEqual(45, teacher.getAge());
            Assert::AreEqual(std::string("Профессор"), teacher.getPosition());
            Assert::AreEqual(0, teacher.getDisciplineCount());
        }

        TEST_METHOD(TeacherAddDiscipline_Success) {
            Department dept("Кафедра математики");
            Teacher teacher("Петрова Мария Владимировна", 50, "Профессор", &dept);
            Discipline math("Математический анализ", 60, "Лекция");
            Discipline algebra("Алгебра", 45, "Практика");
            
            teacher.addDiscipline(math);
            teacher.addDiscipline(algebra);
            
            Assert::AreEqual(2, teacher.getDisciplineCount());
            const Discipline* disciplines = teacher.getDisciplines();
            Assert::AreEqual(std::string("Математический анализ"), disciplines[0].getName());
            Assert::AreEqual(std::string("Алгебра"), disciplines[1].getName());
        }
        
        TEST_METHOD(TeacherPrintInfo_IncludesId_Success) {
            Department dept("Кафедра физики");
            Teacher teacher("Козлова Анна Петровна", 42, "Доцент", &dept);
            std::ostringstream os;
            
            teacher.printInfo();
            os << teacher;
            
            std::string result = os.str();
            Assert::IsTrue(result.find("ID:") != std::string::npos);
            Assert::IsTrue(result.find("Преподаватель") != std::string::npos);
        }
    };
    
    TEST_CLASS(DepartmentTests) {
    public:
        TEST_METHOD(DepartmentAddDiscipline_Success) {
            Department dept("Кафедра физики");
            Discipline physics1("Механика", 60, "Лекция");
            Discipline physics2("Термодинамика", 45, "Практика");
            
            dept.addDiscipline(physics1);
            dept.addDiscipline(physics2);
            
            Assert::AreEqual(2, dept.getDisciplineCount());
            const Discipline* disciplines = dept.getDisciplines();
            Assert::AreEqual(std::string("Механика"), disciplines[0].getName());
            Assert::AreEqual(std::string("Термодинамика"), disciplines[1].getName());
        }
    };
    
    TEST_CLASS(UniversityTests) {
    public:
        TEST_METHOD(UniversityConstructor_Success) {
            University university("Московский государственный университет");
            Assert::AreEqual(std::string("Московский государственный университет"), university.getName());
            Assert::AreEqual(0, university.getDepartmentCount());
            Assert::AreEqual(0, university.getSpecialtyCount());
            Assert::AreEqual(0, university.getGroupCount());
        }

        TEST_METHOD(UniversityAddDepartment_Success) {
            University university("Технический университет");
            Department dept1("Кафедра информатики");
            Department dept2("Кафедра математики");
            
            university.addDepartment(dept1);
            university.addDepartment(dept2);
            
            Assert::AreEqual(2, university.getDepartmentCount());
            const Department* departments = university.getDepartments();
            Assert::AreEqual(std::string("Кафедра информатики"), departments[0].getName());
            Assert::AreEqual(std::string("Кафедра математики"), departments[1].getName());
        }
        
        TEST_METHOD(UniversityFindStudentById_IntegrationTest) {
            University university("Тестовый университет");
            
            Specialty spec("Тест", "Т-01");
            Group group("ТЕСТ-101", &spec);
            
            university.addSpecialty(spec);
            university.addGroup(group);
            
            Student student("Тестов Студент Тестович", 20, &group);
            group.addStudent(student);
            
            int studentId = student.getRecordBookId();
            Student* found = university.findStudentByRecordBookId(studentId);
            
            Assert::IsNotNull(found);
            Assert::AreEqual(std::string("Тестов Студент Тестович"), found->getName());
        }
    };
}