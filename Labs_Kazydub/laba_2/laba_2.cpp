#include <iostream>
#include <cmath> // Для математичних функцій
#include <limits> // Для std::numeric_limits

// Функції для розрахунку y за різними умовами
double calculateForXLessThanOne(double a, double x) {
    if (a < 0) {
        throw std::invalid_argument("Parameter a cannot be negative."); // Перевірка на від'ємне a
    }
    return sin(x) + pow(abs(a),1/4); // Нова формула: y = sin(x) + 4√|a|
}

double calculateForTwoLessThanXLessThanFour(double b, double x) {
    return log(fabs(pow(b, 2) + x)); // y = log|b² + x| при 2 ≤ x < 4
}

double calculateForXGreaterOrEqualToFour(double a, double x) {
    return pow(cos(a * x), 3); // y = cos³(ax) при x більше або рівне 4
}

int main() {
    double a = 3; // Параметр a
    double b = 5; // Параметр b
    double x;

    // Введення числа x з перевіркою
    std::cout << "Введіть число x: ";
    while (!(std::cin >> x)) {
        std::cin.clear(); // Очистка помилки
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ігнорування некоректного вводу
        std::cout << "Будь ласка, введіть дійсне число: ";
    }

    double result;

    // Використання умовного розгалуження згідно з новими умовами
    if (x < 1) {
        try {
            result = calculateForXLessThanOne(a, x);
            std::cout << "Відповідь: y = " << result << std::endl;
        } catch (const std::invalid_argument& e) {
            std::cout << "Помилка: " << e.what() << std::endl; // Виводимо повідомлення про помилку
        }
    } else if (x >= 2 && x < 4) {
        result = calculateForTwoLessThanXLessThanFour(b, x);
        std::cout << "Відповідь: y = " << result << std::endl;
    } else if (x >= 4) {
        result = calculateForXGreaterOrEqualToFour(a, x);
        std::cout << "Відповідь: y = " << result << std::endl;
    } else {
        std::cout << "Значення не підпадає під умови!" << std::endl;
    }

    return 0;
}
