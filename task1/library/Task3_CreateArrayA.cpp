
#include "Task3_CreateArrayA.h"
#include <algorithm>

namespace miit::algebra
{
    Task3_CreateArrayA::Task3_CreateArrayA(
        size_t size, std::unique_ptr<Generator> gen) 
        : Exercise(size, std::move(gen)) 
    {
    }
    
    void Task3_CreateArrayA::execute()
    {
        size_t size = array->getSize();
        
        // Создаем новый массив A того же размера
        auto arrayA = std::make_unique<Matrix<int>>(size);
        
        for (size_t i = 0; i < size; ++i)
        {
            int valueC = (*array)[i];
            
            // Применяем правило для первых 10 элементов
            if (i < 10)
            {
                if ((i % 2) == 1) // нечетный индекс
                {
                    (*arrayA)[i] = valueC - static_cast<int>(i);
                }
                else // четный индекс
                {
                    (*arrayA)[i] = valueC + static_cast<int>(i);
                }
            }
            else // Для остальных элементов копируем без изменений
            {
                (*arrayA)[i] = valueC;
            }
        }
        
        // Заменяем исходный массив на результат
        array = std::move(arrayA);
    }
}