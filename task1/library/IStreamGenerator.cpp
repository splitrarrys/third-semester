
#include "IStreamGenerator.h"

namespace miit::algebra
{
    IStreamGenerator::IStreamGenerator(std::istream& inputStream) 
        : inputStream(inputStream) 
    {
    }
    
    int IStreamGenerator::generate()
    {
        int value;
        inputStream >> value;
        return value;
    }
}