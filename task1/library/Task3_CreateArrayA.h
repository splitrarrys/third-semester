
#pragma once

#include "Exercise.h"

namespace miit::algebra
{
    /**
     * @brief Класс для выполнения задания 3
     */
    class Task3_CreateArrayA : public Exercise
    {
    public:
        using Exercise::Exercise;
        
        /**
         * @brief Конструктор
         * @param size Размер массива
         * @param gen Генератор значений
         */
        Task3_CreateArrayA(size_t size, std::unique_ptr<Generator> gen);
        
        /**
         * @brief Выполнение задания 3
         * 
         * Создает массив A из массива C по заданному правилу
         */
        void execute() override;
    };
}