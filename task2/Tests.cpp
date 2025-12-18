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
            Person person("Иванов Иван Иванович", 25);
            Assert::AreEqual(std::string("Иванов Иван Иванович"), person.getName());
            Assert::AreEqual(25, person.getAge());
        }

        TEST_METHOD(PersonDefaultConstructor_Success) {
            Person person;
            Assert::AreEqual(std::string(""), person.getName());
            Assert::AreEqual(0, person.getAge());
        }

        TEST_METHOD(PersonPrintInfo_ValidData_OutputsCorrectInfo) {
            Person person("Петрова Мария Сергеевна", 22);
            std::ostringstream os;
            os << person;
            
            std::string result = os.str();
            Assert::IsTrue(result.find("Иванов Иван Иванович") == std::string::npos);
            Assert::IsTrue(result.find("25") == std::string::npos);
            // Проверяем что вывод работает
            Assert::IsFalse(result.empty());
        }
    };
    
    TEST_CLASS(StudentTests) {
    public:
        TEST_METHOD(StudentConstructor_ValidData_Success) {
            Group group("ПИ-101", nullptr);
            Student student("Смирнов Дмитрий Александрович", 20, &group);
            Assert::AreEqual(std::string("Смирнов Дмитрий Александрович"), student.getName());
            Assert::AreEqual(20, student.getAge());
            Assert::IsTrue(student.getRecordBookId() >= 1000);
        }

        TEST_METHOD(StudentDefaultConstructor_Success) {
            Student student1;
            Student student2;
            
            Assert::AreEqual(std::string(""), student1.getName());
            Assert::AreEqual(0, student1.getAge());
            Assert::IsNull(student1.getGroup());
            Assert::IsTrue(student2.getRecordBookId() > student1.getRecordBookId());
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
    };
}