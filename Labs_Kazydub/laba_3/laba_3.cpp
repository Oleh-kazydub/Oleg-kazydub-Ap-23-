#include <iostream>
#include <cmath>

using namespace std;

// Функція для обчислення y для заданого x
double calculate_y(double x, double a, double b) {
    return cbrt(pow(a, 3) + pow(x, 3)) / (pow(tan(b * x), 3) + 1.6);
}

// Функція для обчислення суми значень y, де 0 < y < 1
double calculate_sum(double x1, double x2, double h, double a, double b) {
    double sum = 0.0;
    for (double x = x1; x <= x2; x += h) {
        double y = calculate_y(x, a, b);
        cout << "y(" << x << ") = " << y << endl; // Виведення значення y для кожного x
        if (y > 0 && y < 1) {
            sum += y;
        }
    }
    return sum;
}

// Функція для перевірки коректності вхідних значень
bool check_input(double x1, double x2, double h) {
    return (x1 < x2) && (h > 0);
}

// Головна програма
int main() {
    double x1 = 0.2, x2 = 1.6, h = 0.2, a = 1.25, b = 0.86;

    if (!check_input(x1, x2, h)) {
        cout << "Некоректні вхідні значення. Переконайтесь, що x1 < x2 і h > 0." << endl;
        return 1;
    }

    cout << "Обчислення значень y для x від " << x1 << " до " << x2 << " з кроком " << h << ":" << endl;
    double sum = calculate_sum(x1, x2, h, a, b);

    cout << "Сума значень y, де 0 < y < 1: " << sum << endl;

    return 0;
}
