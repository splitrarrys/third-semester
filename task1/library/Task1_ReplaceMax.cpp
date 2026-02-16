
#include "Task1_ReplaceMax.h"
#include <limits>
#include <algorithm>

namespace miit::algebra
{
    Task1_ReplaceMax::Task1_ReplaceMax(
        size_t size, std::unique_ptr<Generator> gen) 
        : Exercise(size, std::move(gen)) 
    {
    }
    
    void Task1_ReplaceMax::execute()
    {
        if (array->getSize() == 0) 
            return;
        
        // Находим максимальный элемент и его индекс
        int maxValue = std::numeric_limits<int>::min();
        size_t maxIndex = 0;
        
        for (size_t i = 0; i < array->getSize(); ++i)
        {
            if ((*array)[i] > maxValue)
            {
                maxValue = (*array)[i];
                maxIndex = i;
            }
        }
        
        // Заменяем максимальный элемент на противоположный по знаку
        if (maxValue != std::numeric_limits<int>::min())
        {
            (*array)[maxIndex] = -maxValue;
        }
    }
}