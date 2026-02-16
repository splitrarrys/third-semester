
#pragma once

#include "Matrix.h"
#include "Generator.h"
#include <memory>

namespace miit::algebra
{
    /**
     * @brief Абстрактный класс для выполнения заданий с массивами
     */
    class Exercise
    {
    protected:
        std::unique_ptr<Matrix<int>> array;  ///< Умный указатель на массив
        std::unique_ptr<Generator> generator;  ///< Умный указатель на генератор
        

        
    public:
        /**
         * @brief Конструктор
         * @param size Размер массива
         * @param gen Генератор значений
         */
        Exercise(const size_t size, std::unique_ptr<Generator> gen);


        /**
         * @brief Виртуальный деструктор
         */
        virtual ~Exercise() = default;
        
        /**
         * @brief Получение массива
         * @return Константная ссылка на массив
         */
        const Matrix<int>& getArray() const;
        
        /**
         * @brief Виртуальный метод для выполнения задания
         */
        virtual void execute() = 0;
    };
}