
#pragma once

#include "Generator.h"
#include <random>

namespace miit::algebra
{
    /**
     * @brief Класс для генерации случайных чисел
     */
    class RandomGenerator : public Generator
    {
    private:
        std::uniform_int_distribution<int> distribution;  ///< Распределение случайных чисел
        std::mt19937 randomEngine;                        ///< Генератор случайных чисел
        
    public:
        /**
         * @brief Конструктор
         * @param min Минимальное значение
         * @param max Максимальное значение
         */
        RandomGenerator(int min, int max);
        
        /**
         * @brief Генерация случайного числа
         * @return Случайное число в заданном диапазоне
         */
        int generate() override;
    };
}