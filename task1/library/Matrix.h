
#pragma once

#include <memory>
#include <string>

// Предварительное объявление класса Generator
namespace miit::algebra
{
    class Generator;
}

namespace miit::algebra
{
    /**
     * @brief Шаблонный класс Matrix (одномерный массив)
     * @tparam T Тип элементов массива
     */
    template<typename T>
    class Matrix
    {
    private:
        std::unique_ptr<T[]> data;  ///< Умный указатель на массив данных
        size_t size;                ///< Размер массива

    public:
        /**
         * @brief Конструктор по умолчанию
         */
        Matrix();

        /**
         * @brief Конструктор с заданным размером
         * @param size Размер массива
         */
        Matrix(const size_t size);

        /**
         * @brief Конструктор копирования
         * @param other Копируемый объект
         */
        Matrix(const Matrix& other);

        /**
         * @brief Конструктор перемещения
         * @param other Перемещаемый объект
         */
        Matrix(Matrix&& other) noexcept;

        /**
         * @brief Деструктор
         */
        ~Matrix() = default;

        /**
         * @brief Оператор присваивания копированием
         * @param other Присваиваемый объект
         * @return Ссылка на текущий объект
         */
        Matrix& operator=(const Matrix& other);

        /**
         * @brief Оператор присваивания перемещением
         * @param other Перемещаемый объект
         * @return Ссылка на текущий объект
         */
        Matrix& operator=(Matrix&& other) noexcept;

        /**
         * @brief Получение размера массива
         * @return Размер массива
         */
        size_t getSize() const;

        /**
         * @brief Оператор доступа к элементу по индексу
         * @param index Индекс элемента
         * @return Ссылка на элемент
         * @throw std::out_of_range при выходе за границы массива
         */
        T& operator[](const size_t index);

        /**
         * @brief Константный оператор доступа к элементу по индексу
         * @param index Индекс элемента
         * @return Константная ссылка на элемент
         * @throw std::out_of_range при выходе за границы массива
         */
        const T& operator[](const size_t index) const;

        /**
         * @brief Оператор циклического сдвига влево
         * @param shift Величина сдвига
         * @return Новый массив после сдвига
         */
        Matrix operator<<(const int shift) const;

        /**
         * @brief Оператор циклического сдвига вправо
         * @param shift Величина сдвига
         * @return Новый массив после сдвига
         */
        Matrix operator>>(const int shift) const;

        /**
         * @brief Заполнение массива с помощью генератора
         * @param generator Генератор значений
         */
        void fill(const Generator& generator);

        /**
         * @brief Преобразование массива в строковое представление
         * @return Строка с элементами массива
         */
        std::string toString() const;
    };
}