#include "Matrix.h"

// ==================== Конструкторы ====================

Matrix::Matrix() : data_(nullptr), rows_(0), cols_(0) {
}

Matrix::Matrix(int size) : data_(nullptr), rows_(size), cols_(size) {
    // TODO: реализовать в коммите 2
}

Matrix::Matrix(int rows, int cols) : data_(nullptr), rows_(rows), cols_(cols) {
    // TODO: реализовать в коммите 2
}

// ==================== Деструктор ====================

Matrix::~Matrix() {
    // TODO: реализовать в коммите 2
}

// ==================== Доступ к элементам ====================

int Matrix::get(int i, int j) const {
    // TODO: реализовать в коммите 2
    return 0;
}

void Matrix::set(int i, int j, int value) {
    // TODO: реализовать в коммите 2
}

// ==================== Заполнение ====================

void Matrix::inputFromKeyboard() {
    // TODO: реализовать в коммите 2
}

void Matrix::fillRandom() {
    // TODO: реализовать в коммите 2
}

// ==================== Вывод ====================

void Matrix::print() const {
    // TODO: реализовать в коммите 2
}

// ==================== Вычисления ====================

int Matrix::sum() const {
    // TODO: реализовать в коммите 2
    return 0;
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
    // TODO: реализовать в коммите 2
    return Matrix();
}