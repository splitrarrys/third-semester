/**
 * @file Tests.cpp
 * @brief Файл с unit-тестами для проекта
 * @author Student
 * @date 2024
 * 
 * Набор тестов для проверки корректности работы всех компонентов проекта
 */

#include "CppUnitTest.h"
#include "../Library/Matrix.h"
#include "../Library/Exercise.h"
#include "../Library/Task1_ReplaceMax.h"
#include "../Library/Task2_InsertAfterOnes.h"
#include "../Library/Task3_CreateArrayA.h"
#include "../Library/RandomGenerator.h"
#include "../Library/ConstantGenerator.h"
#include "../Library/IStreamGenerator.h"
#include <sstream>
#include <memory>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AlgebraTests
{
    TEST_CLASS(MatrixTests)
    {
    public:
        TEST_METHOD(MatrixConstructor_ValidSize_Success)
        {
            // Arrange & Act
            miit::algebra::Matrix<int> matrix(5);

            // Assert
            Assert::AreEqual(size_t(5), matrix.getSize());
        }

        TEST_METHOD(MatrixAccessOperator_ValidIndex_Success)
        {
            // Arrange
            miit::algebra::Matrix<int> matrix(3);
            matrix[0] = 1;
            matrix[1] = 2;
            matrix[2] = 3;

            // Act & Assert
            Assert::AreEqual(1, matrix[0]);
            Assert::AreEqual(2, matrix[1]);
            Assert::AreEqual(3, matrix[2]);
        }

        TEST_METHOD(MatrixToString_ValidArray_ReturnsCorrectString)
        {
            // Arrange
            miit::algebra::Matrix<int> matrix(3);
            matrix[0] = 1;
            matrix[1] = 2;
            matrix[2] = 3;

            // Act
            std::string result = matrix.toString();

            // Assert
            Assert::AreEqual(std::string("[1, 2, 3]"), result);
        }
    };

    TEST_CLASS(GeneratorTests)
    {
    public:
        TEST_METHOD(RandomGenerator_ValidRange_Success)
        {
            // Arrange
            miit::algebra::RandomGenerator generator(1, 10);

            // Act
            int value = generator.generate();

            // Assert
            Assert::IsTrue(value >= 1 && value <= 10);
        }

        TEST_METHOD(ConstantGenerator_AlwaysReturnsConstant_Success)
        {
            // Arrange
            miit::algebra::ConstantGenerator generator(42);

            // Act
            int value1 = generator.generate();
            int value2 = generator.generate();

            // Assert
            Assert::AreEqual(42, value1);
            Assert::AreEqual(42, value2);
        }

        TEST_METHOD(IStreamGenerator_ReadsFromStream_Success)
        {
            // Arrange
            std::stringstream ss("123 456");
            miit::algebra::IStreamGenerator generator(ss);

            // Act
            int value1 = generator.generate();
            int value2 = generator.generate();

            // Assert
            Assert::AreEqual(123, value1);
            Assert::AreEqual(456, value2);
        }
    };

    TEST_CLASS(Task1_ReplaceMaxTests)
    {
    public:
        TEST_METHOD(Task1_ReplaceMax_ReplacesMaxElementWithOpposite_Success)
        {
            // Arrange
            auto generator = std::make_unique<miit::algebra::ConstantGenerator>(0);
            miit::algebra::Task1_ReplaceMax exercise(5, std::move(generator));

            // Manually set matrix values
            auto& matrix = const_cast<miit::algebra::Matrix<int>&>(exercise.getArray());
            matrix[0] = 5;
            matrix[1] = -3;
            matrix[2] = 8;  // maximum element
            matrix[3] =