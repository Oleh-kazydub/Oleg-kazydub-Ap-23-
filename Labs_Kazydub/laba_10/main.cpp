#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
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

// Функція для перевірки коректності введення числа
bool isValidDouble(const std::string& input) {
    if (input.empty()) return false; // Перевірка на порожній рядок
    size_t dotCount = 0;
    for (char c : input) {
        if (!std::isdigit(c) && c != '.') return false; // Лише цифри або одна крапка
        if (c == '.') {
            dotCount++;
            if (dotCount > 1) return false; // Не більше одного десяткового роздільника
        }
    }
    return true;
}

// Функція для введення коректного числа (не порожнього та числового)
double inputDouble(const std::string& prompt) {
    std::string input;
    double result;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (isValidDouble(input)) {
            result = std::stod(input); // Перетворення рядка на число
            break;
        } else {
            std::cout << "Некоректне значення! Спробуйте ще раз.\n";
        }
    }
    return result;
}

void inputTriangleSides(double& a, double& b, double& c) {
    std::string input;
    while (true) {
        std::cout << "Введіть сторону a: ";
        std::getline(std::cin, input);
        if (isValidDouble(input)) {
            a = std::stod(input);
            break;
        } else {
            std::cout << "Некоректне значення для a! Спробуйте ще раз.\n";
        }
    }
    
    while (true) {
        std::cout << "Введіть сторону b: ";
        std::getline(std::cin, input);
        if (isValidDouble(input)) {
            b = std::stod(input);
            break;
        } else {
            std::cout << "Некоректне значення для b! Спробуйте ще раз.\n";
        }
    }

    while (true) {
        std::cout << "Введіть сторону c: ";
        std::getline(std::cin, input);
        if (isValidDouble(input)) {
            c = std::stod(input);
            break;
        } else {
            std::cout << "Некоректне значення для c! Спробуйте ще раз.\n";
        }
    }
}

int main() {
    // Введення кількості трикутників з перевіркою
    int numTriangles = static_cast<int>(inputDouble("Введіть кількість трикутників: "));

    std::vector<Triangle> triangles;
    triangles.reserve(numTriangles);

    // Ввід даних для кожного трикутника
    for (int i = 0; i < numTriangles; ++i) {
        Triangle triangle;
        std::cout << "\nТрикутник " << i + 1 << ":\n";
        double a, b, c;
        inputTriangleSides(a, b, c); // Введення сторін трикутника з перевіркою

        try {
            triangle = Triangle(a, b, c); // Створення трикутника
            triangles.push_back(triangle);
        } catch (const std::invalid_argument &e) {
            std::cout << "Помилка: " << e.what() << "\n";
            std::cout << "Спробуйте ще раз.\n";
            --i; // Повторно запросити введення для поточного трикутника
        }
    }

    // Сортування трикутників за зростанням площі
    sortTrianglesByArea(triangles);
    std::cout << "\nТрикутники, відсортовані за площею:\n";
    for (const auto &triangle : triangles) {
        triangle.display();
    }

    // Введення значення для збільшення сторін з перевіркою
    double increment = inputDouble("\nВведіть значення для збільшення сторін: ");
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
