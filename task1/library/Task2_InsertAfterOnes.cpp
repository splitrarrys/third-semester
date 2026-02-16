#include "Task2_InsertAfterOnes.h"
#include <vector>
#include <limits>
#include <cmath>
#include <algorithm>

namespace miit::algebra
{
    Task2_InsertAfterOnes::Task2_InsertAfterOnes(
        size_t size, std::unique_ptr<Generator> gen) 
        : Exercise(size, std::move(gen)) 
    {
    }
    
    void Task2_InsertAfterOnes::execute()
    {
        if (array->getSize() == 0) 
            return;
        
        // Находим максимальный элемент
        int maxValue = (*array)[0];
        for (size_t i = 1; i < array->getSize(); ++i)
        {
            if ((*array)[i] > maxValue)
            {
                maxValue = (*array)[i];
            }
        }
        
        // Создаем результирующий вектор
        std::vector<int> result;
        
        for (size_t i = 0; i < array->getSize(); ++i)
        {
            // Добавляем текущий элемент
            result.push_back((*array)[i]);
            
            // Если элемент содержит цифру 1, добавляем максимальный элемент после него
            if (containsDigitOne((*array)[i]))
            {
                result.push_back(maxValue);
            }
        }
        
        // Создаем новый массив с результатом
        auto newArray = std::make_unique<Matrix<int>>(result.size());
        for (size_t i = 0; i < result.size(); ++i)
        {
            (*newArray)[i] = result[i];
        }
        
        array = std::move(newArray);
    }
    
    bool Task2_InsertAfterOnes::containsDigitOne(int number) const
    {
        // Работаем с абсолютным значением для отрицательных чисел
        int n = std::abs(number);
        
        // Проверяем каждую цифру
        do {
            if (n % 10 == 1)
            {
                return true;
            }
            n /= 10;
        } while (n > 0);
        
        return false;
    }
}