#include <iostream>
#include <cmath>

using namespace std;

// Головна програма
int main() {

    // Обчислення значень y та їх суми
    cout << "Значення y для x від " << x1 << " до " << x2 << ":" << endl;
    for (double x = x1; x <= x2; x += h) {
        double y = cbrt(a * a * a + (pow(x, 3) / (pow(tan(b * x), 3) + 1.6)));
        cout << y << " "; // Виведення значення y

        // Обчислення суми y, де 0 < y < 1
        if (y > 0 && y < 1) {
            sum += y;
        }
    }
    cout << endl;

    cout << "Сума значень y, де 0 < y < 1: " << sum << endl;

    return 0;
}
