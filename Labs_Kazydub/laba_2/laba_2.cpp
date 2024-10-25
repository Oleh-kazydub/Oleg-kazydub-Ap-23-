#include <iostream>
#include <cmath>  // Для математичних функцій

int main() {
    double a = 3;
    double b = 5;
    double x;

    // Введення числа x
    std::cout << "Введіть число x: ";
    std::cin >> x;

    double i;

    // Використання умовного розгалуження згідно з новими умовами
    if (x < 1) {
        i = sin(x) * pow(sqrt(fabs(a)), 4);  // y = sin(x) * √⁴|a|
        std::cout << "Відповідь: y = " << i;
    } else if (x >= 2 && x < 4) {
        i = log(fabs(pow(b, 2) + x));  // y = log|b² + x| при 2 ≤ x < 4
        std::cout << "Відповідь: y =  " << i;
    } else if (x >= 4) {
        i = pow(cos(a * x), 3);  // y = cos³(ax) при x більше або рівне 4
        std::cout << "Відповідь: y = " << i;
    } else {
        std::cout << "Значення не підпадає під умови!";
    }

    return 0;
}
