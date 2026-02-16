
#include "RandomGenerator.h"

namespace miit::algebra
{
    RandomGenerator::RandomGenerator(int min, int max)
        : distribution(min, max)
        , randomEngine(std::random_device{}())
    {
    }
    
    int RandomGenerator::generate()
    {
        return distribution(randomEngine);
    }
}