
#include "Exercise.h"

namespace miit::algebra
{
    Exercise::Exercise(size_t size, std::unique_ptr<Generator> gen)
        : array(std::make_unique<Matrix<int>>(size))
        , generator(std::move(gen))
    {
    }
    
    void Exercise::fillArray()
    {
        array->fill(*generator);
    }
    
    const Matrix<int>& Exercise::getArray() const
    {
        return *array;
    }
}