#include "Matrix.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

// ==================== Конструкторы ====================

Matrix::Matrix() : data_(nullptr), rows_(0), cols_(0) {
}

Matrix::Matrix(int size) : data_(nullptr), rows_(size), cols_(size) {
    if (size < 0) {
        throw std::invalid_argument("Размерность не может быть отрицательной");
    }
    if (size == 0) {
        return;
    }

    data_ = new int*[rows_];
    for (int i = 0; i < rows_; ++i) {
        data_[i] = new int[cols_]{}; // инициализация нулями
        data_[i][i] = 1;             // главная диагональ = 1
    }
}

Matrix::Matrix(int rows, int cols) : data_(nullptr), rows_(rows), cols_(cols) {
    if (rows < 0 || cols < 0) {
        throw std::invalid_argument("Размерность не может быть отрицательной");
    }
    if (rows == 0 || cols == 0) {
        rows_ = 0;
        cols_ = 0;
        return;
    }

    data_ = new int*[rows_];
    for (int i = 0; i < rows_; ++i) {
        data_[i] = new int[cols_]{};
    }
}
// ==================== Деструктор ====================

Matrix::~Matrix() {
    if (data_ == nullptr) {
        return;
    }
    for (int i = 0; i < rows_; ++i) {
        delete[] data_[i];
    }
    delete[] data_;
}

// ==================== Доступ к элементам ====================

int Matrix::get(int i, int j) const {
    if (i < 0 || i >= rows_ || j < 0 || j >= cols_) {
        throw std::out_of_range("Индексы вне диапазона матрицы");
    }
    return data_[i][j];
}

void Matrix::set(int i, int j, int value) {
    if (i < 0 || i >= rows_ || j < 0 || j >= cols_) {
        throw std::out_of_range("Индексы вне диапазона матрицы");
    }
    data_[i][j] = value;
}

// ==================== Заполнение ====================

void Matrix::inputFromKeyboard() {
    if (rows_ == 0 || cols_ == 0) {
        std::cout << "Матрица пустая, заполнение невозможно.\n";
        return;
    }

    std::cout << "Введите " << rows_ * cols_ << " чисел для матрицы "
              << rows_ << "x" << cols_ << ":\n";
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            std::cin >> data_[i][j];
        }
    }
}

void Matrix::fillRandom() {
    if (rows_ == 0 || cols_ == 0) {
        return;
    }

    static bool seeded = false;
    if (!seeded) {
        std::srand(static_cast<unsigned>(std::time(nullptr)));
        seeded = true;
    }

    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            data_[i][j] = std::rand() % 100;
        }
    }
}

// ==================== Вывод ====================

void Matrix::print() const {
    if (rows_ == 0 || cols_ == 0) {
        std::cout << "(пустая матрица " << rows_ << "x" << cols_ << ")\n";
        return;
    }

    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            std::cout << data_[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

// ==================== Вычисления ====================

int Matrix::sum() const {
    int total = 0;
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            total += data_[i][j];
        }
    }
    return total;
}

// ==================== Геттеры ====================

int Matrix::getRows() const {
    return rows_;
}

int Matrix::getCols() const {
    return cols_;
}

// ==================== Домашнее задание ====================

Matrix Matrix::transpose() const {
    Matrix result(cols_, rows_);

    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            result.data_[j][i] = data_[i][j];
        }
    }

    return result;
}