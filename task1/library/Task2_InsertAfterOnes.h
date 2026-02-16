
#pragma once

#include "Exercise.h"

namespace miit::algebra
{
    /**
     * @brief Класс для выполнения задания 2
     */
    class Task2_InsertAfterOnes : public Exercise
    {
    public:
        using Exercise::Exercise;
        
        /**
         * @brief Конструктор
         * @param size Размер массива
         * @param gen Генератор значений
         */
        Task2_InsertAfterOnes(size_t size, std::unique_ptr<Generator> gen);
        
        /**
         * @brief Выполнение задания 2
         * 
         * Находит максимальный элемент массива и вставляет его после
         * всех элементов, которые содержат цифру 1
         */
        void execute() override;
        
    private:
        /**
         * @brief Проверка, содержит ли число цифру 1
         * @param number Проверяемое число
         * @return true если содержит цифру 1, иначе false
         */
        bool containsDigitOne(int number) const;
    };
}