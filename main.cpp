#include "Matrix.h"
#include <iostream>
#include <stdexcept>

int main() {
    try {
        // 1. Создаём четыре матрицы разными конструкторами
        Matrix m1;          // 0x0
        Matrix m2(3);       // 3x3, единичная
        Matrix m3(3, 4);    // 3x4, нули
        Matrix m4(2, 3);    // 2x3, нули

        std::cout << "=== M1 (0x0) ===\n";
        m1.print();

        // 2. Выводим M2, M3, M4
        std::cout << "\n=== M2 (3x3, единичная) ===\n";
        m2.print();

        std::cout << "\n=== M3 (3x4, нули) ===\n";
        m3.print();

        std::cout << "\n=== M4 (2x3, нули) ===\n";
        m4.print();

        // 3. Заполняем M2 по формуле: элемент (i, j) = i * j
        std::cout << "\n=== M2 заполнена по формуле i*j ===\n";
        for (int i = 0; i < m2.getRows(); ++i) {
            for (int j = 0; j < m2.getCols(); ++j) {
                m2.set(i, j, i * j);
            }
        }
        m2.print();

        // 4. Заполняем M3 случайными числами
        std::cout << "\n=== M3 заполнена случайными числами ===\n";
        m3.fillRandom();
        m3.print();

        // 5. Заполняем M4 с клавиатуры
        std::cout << "\n=== M4: ввод с клавиатуры ===\n";
        m4.inputFromKeyboard();
        std::cout << "M4 после ввода:\n";
        m4.print();

        // 6. Считаем сумму элементов M3
        std::cout << "\n=== Сумма элементов M3 ===\n";
        std::cout << "Сумма = " << m3.sum() << '\n';

        // Домашнее задание: транспонирование
        std::cout << "\n=== Транспонирование M4 ===\n";
        Matrix m4t = m4.transpose();
        std::cout << "Исходная M4:\n";
        m4.print();
        std::cout << "Транспонированная M4 ("
                  << m4t.getRows() << "x" << m4t.getCols() << "):\n";
        m4t.print();

        // Демонстрация поверхностного копирования (проблема!)
        std::cout << "\n=== Проверка копирования объекта ===\n";
        {
            Matrix mm = m3; // поверхностное копирование (по умолчанию)
            std::cout << "Скопированная матрица mm:\n";
            mm.print();
            std::cout << "(ВНИМАНИЕ: деструкторы обоих объектов "
                         "освободят одну и ту же память — double free!)\n";
        }
        std::cout << "(Здесь может произойти ошибка/крэш — "
                     "это ожидаемое поведение без правил трёх)\n";

        // 7. Демонстрация исключений
        std::cout << "\n=== Демонстрация исключений ===\n";

        try {
            Matrix bad(-1, 5); // отрицательная размерность
        } catch (const std::invalid_argument& e) {
            std::cout << "Caught: " << e.what() << '\n';
        }

        try {
            m3.get(100, 100); // выход за границы
        } catch (const std::out_of_range& e) {
            std::cout << "Caught: " << e.what() << '\n';
        }

    } catch (const std::exception& e) {
        std::cerr << "Необработанное исключение: " << e.what() << '\n';
        return 1;
    }

    return 0;
}