#include <iostream>
#include <memory>
#include <string>

#include "../Library/Matrix.h"
#include "../Library/Exercise.h"
#include "../Library/Task1_ReplaceMax.h"
#include "../Library/Task2_InsertAfterOnes.h"
#include "../Library/Task3_CreateArrayA.h"
#include "../Library/RandomGenerator.h"
#include "../Library/ConstantGenerator.h"
#include "../Library/IStreamGenerator.h"

using namespace miit::algebra;

/**
 * @brief Перечисление методов заполнения массива
 */
enum class FillMethod
{
    RANDOM,      ///< Случайное заполнение
    CONSTANT,    ///< Заполнение константным значением
    FROM_INPUT   ///< Ввод значений с клавиатуры
};

/**
 * @brief Перечисление выбора задания
 */
enum class TaskChoice
{
    TASK_1,      ///< Задание 1: Замена максимального элемента
    TASK_2,      ///< Задание 2: Вставка после элементов с цифрой 1
    TASK_3       ///< Задание 3: Формирование массива A
};

/**
 * @brief Функция для ввода размера массива
 * @return Размер массива
 * @throw std::runtime_error при некорректном вводе
 */
size_t inputSize()
{
    int size;
    std::cout << "Введите размер массива (больше 0): ";
    std::cin >> size;

    if (std::cin.fail() || size <= 0)
    {
        std::cout << "Ошибка: размер должен быть положительным числом!" << std::endl;
        throw std::runtime_error("Некорректный размер массива");
    }

    return static_cast<size_t>(size);
}

/**
 * @brief Функция для ввода целочисленного значения
 * @param message Сообщение для пользователя
 * @return Введенное значение
 * @throw std::runtime_error при некорректном вводе
 */
int inputValue(const char* message)
{
    int value;
    std::cout << message << ": ";
    std::cin >> value;

    if (std::cin.fail())
    {
        std::cout << "Ошибка ввода!" << std::endl;
        throw std::runtime_error("Некорректный ввод значения");
    }

    return value;
}

/**
 * @brief Главная функция программы
 * @return 0 при успешном выполнении, 1 при ошибке
 */
int main()
{
    try
    {
        // Ввод размера массива
        size_t size = inputSize();

        // Выбор метода заполнения
        std::cout << "\nВыберите метод заполнения массива:\n";
        std::cout << static_cast<int>(FillMethod::RANDOM) << " - Случайные числа\n";
        std::cout << static_cast<int>(FillMethod::CONSTANT) << " - Константное значение\n";
        std::cout << static_cast<int>(FillMethod::FROM_INPUT) << " - Ввод с клавиатуры\n";
        std::cout << "Ваш выбор: ";

        int fillChoice;
        std::cin >> fillChoice;

        FillMethod method;
        switch (fillChoice)
        {
            case static_cast<int>(FillMethod::RANDOM): method = FillMethod::RANDOM; break;
            case static_cast<int>(FillMethod::CONSTANT): method = FillMethod::CONSTANT; break;
            case static_cast<int>(FillMethod::FROM_INPUT): method = FillMethod::FROM_INPUT; break;
            default:
                std::cout << "Некорректный выбор метода заполнения!" << std::endl;
                return 1;
        }

        // Выбор задания
        std::cout << "\nВыберите задание для выполнения:\n";
        std::cout << static_cast<int>(TaskChoice::TASK_1) << " - Задание 1: Замена максимального элемента на противоположный\n";
        std::cout << static_cast<int>(TaskChoice::TASK_2) << " - Задание 2: Вставка максимального элемента после элементов с цифрой 1\n";
        std::cout << static_cast<int>(TaskChoice::TASK_3) << " - Задание 3: Формирование массива A из массива C\n";
        std::cout << "Ваш выбор: ";

        int taskChoice;
        std::cin >> taskChoice;

        TaskChoice task;
        switch (taskChoice)
        {
            case static_cast<int>(TaskChoice::TASK_1): task = TaskChoice::TASK_1; break;
            case static_cast<int>(TaskChoice::TASK_2): task = TaskChoice::TASK_2; break;
            case static_cast<int>(TaskChoice::TASK_3): task = TaskChoice::TASK_3; break;
            default:
                std::cout << "Некорректный выбор задания!" << std::endl;
                return 1;
        }

        // Создание генератора в зависимости от выбранного метода
        std::unique_ptr<Generator> generator;

        switch (method)
        {
            case FillMethod::RANDOM:
            {
                int min = inputValue("Введите минимальное значение");
                int max = inputValue("Введите максимальное значение");

                if (min > max)
                {
                    std::cout << "Ошибка: минимальное значение больше максимального!" << std::endl;
                    return 1;
                }

                generator = std::make_unique<RandomGenerator>(min, max);
                break;
            }

            case FillMethod::CONSTANT:
            {
                int value = inputValue("Введите константное значение");
                generator = std::make_unique<ConstantGenerator>(value);
                break;
            }

            case FillMethod::FROM_INPUT:
            {
                std::cout << "Введите " << size << " элементов массива:\n";
                generator = std::make_unique<IStreamGenerator>(std::cin);
                break;
            }
            
            default:
                // Этот случай не должен происходить
                std::cout << "Неизвестный метод заполнения!" << std::endl;
                return 1;
        }

        // Создание задания в зависимости от выбора пользователя
        std::unique_ptr<Exercise> exercise;

        switch (task)
        {
            case TaskChoice::TASK_1:
                exercise = std::make_unique<Task1_ReplaceMax>(size, std::move(generator));
                break;

            case TaskChoice::TASK_2:
                exercise = std::make_unique<Task2_InsertAfterOnes>(size, std::move(generator));
                break;

            case TaskChoice::TASK_3:
                exercise = std::make_unique<Task3_CreateArrayA>(size, std::move(generator));
                break;
                
            default:
                // Этот случай не должен происходить
                std::cout << "Неизвестное задание!" << std::endl;
                return 1;
        }

        // Заполнение и выполнение задания
        exercise->fillArray();

        std::cout << "\nИсходный массив: " << exercise->getArray().toString() << std::endl;

        exercise->execute();

        std::cout << "Результат: " << exercise->getArray().toString() << std::endl;

        return 0;
    }
    catch (const std::exception& error)
    {
        std::cout << "Произошла ошибка: " << error.what() << std::endl;
        return 1;
    }
    catch (...)
    {
        std::cout << "Произошла неизвестная ошибка!" << std::endl;
        return 1;
    }
}