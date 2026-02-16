
#pragma once

#include "Generator.h"
#include <iostream>

namespace miit::algebra
{
    /**
     * @brief Класс для чтения значений из входного потока
     */
    class IStreamGenerator : public Generator
    {
    private:
        std::istream& inputStream;  ///< Ссылка на входной поток
        
    public:
        /**
         * @brief Конструктор
         * @param inputStream Входной поток для чтения (по умолчанию std::cin)
         */
        IStreamGenerator(std::istream& inputStream = std::cin);
        
        /**
         * @brief Чтение значения из потока
         * @return Прочитанное значение
         */
        int generate() override;
    };
}