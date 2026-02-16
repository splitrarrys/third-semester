
#pragma once

#include "Exercise.h"

namespace miit::algebra
{
    /**
     * @brief Класс для выполнения задания 1
     */
    class Task1_ReplaceMax : public Exercise
    {
    public:
        using Exercise::Exercise;
        
        /**
         * @brief Конструктор
         * @param size Размер массива
         * @param gen Генератор значений
         */
        Task1_ReplaceMax(size_t size, std::unique_ptr<Generator> gen);
        
        /**
         * @brief Выполнение задания 1
         * 
         * Находит максимальный элемент в массиве и заменяет его на противоположный по знаку
         */
        void execute() override;
    };
}