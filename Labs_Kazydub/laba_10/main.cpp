#include <iostream>
#include <vector>
#include <algorithm>
#include "Triangle.h"

// Функція для сортування масиву трикутників за зростанням площі
void sortTrianglesByArea(std::vector<Triangle> &triangles) {
    std::sort(triangles.begin(), triangles.end(), [](const Triangle &t1, const Triangle &t2) {
        return t1 <= t2;
    });
}

// Функція для збільшення сторін усіх трикутників у масиві на задане значення
void increaseTriangleSides(std::vector<Triangle> &triangles, double increment) {
    for (auto &triangle : triangles) {
        triangle += increment;
    }
}

int main() {
    int numTriangles;
    std::cout << "Введіть кількість трикутників: ";
    std::cin >> numTriangles;

    std::vector<Triangle> triangles;
    triangles.reserve(numTriangles);

    // Ввід даних для кожного трикутника
    for (int i = 0; i < numTriangles; ++i) {
        Triangle triangle;
        std::cout << "\nТрикутник " << i + 1 << ":\n";
        try {
            triangle.input();
            triangles.push_back(triangle);
        } catch (const std::invalid_argument &e) {
            std::cout << "Помилка: " << e.what() << "\n";
        }
    }

    // Сортування трикутників за зростанням площі
    sortTrianglesByArea(triangles);
    std::cout << "\nТрикутники, відсортовані за площею:\n";
    for (const auto &triangle : triangles) {
        triangle.display();
    }

    // Збільшення сторін кожного трикутника на задане значення
    double increment;
    std::cout << "\nВведіть значення для збільшення сторін: ";
    std::cin >> increment;
    try {
        increaseTriangleSides(triangles, increment);
        std::cout << "\nТрикутники після збільшення сторін на " << increment << ":\n";
        for (const auto &triangle : triangles) {
            triangle.display();
        }
    } catch (const std::invalid_argument &e) {
        std::cout << "Помилка: " << e.what() << "\n";
    }

    return 0;
}
