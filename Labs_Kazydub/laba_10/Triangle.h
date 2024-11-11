#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include <cmath>

class Triangle {
private:
    double a, b, c; // Довжини сторін трикутника

public:
    // Конструктор за замовчуванням
    Triangle();

    // Конструктор з параметрами
    Triangle(double sideA, double sideB, double sideC);

    // Деструктор
    ~Triangle();

    // Метод для обчислення площі трикутника
    double area() const;

    // Метод для перевірки правильності сторін трикутника
    bool isValid() const;

    // Перевантаження оператора <= для порівняння площі
    bool operator<=(const Triangle &other) const;

    // Перевантаження оператора += для збільшення сторін на задане значення
    Triangle& operator+=(double increment);

    // Метод для введення сторін трикутника
    void input();

    // Метод для виводу інформації про трикутник
    void display() const;
};

#endif // TRIANGLE_H
