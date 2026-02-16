
#pragma once
#include "Generator.h"

namespace miit::algebra
{
    /**
     * @brief Класс для генерации константных значений
     */
    class ConstantGenerator : public Generator
    {
    private:
        int value;  ///< Константное значение
        
    public:
        /**
         * @brief Конструктор
         * @param value Константное значение
         */
        ConstantGenerator(int value);
        
        /**
         * @brief Генерация значения
         * @return Константное значение
         */
        int generate() override;
    };
}