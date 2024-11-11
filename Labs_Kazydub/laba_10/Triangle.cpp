#include "Triangle.h"

// Конструктор за замовчуванням
Triangle::Triangle() : a(1), b(1), c(1) {}

// Конструктор з параметрами
Triangle::Triangle(double sideA, double sideB, double sideC) : a(sideA), b(sideB), c(sideC) {
    if (!isValid()) {
        throw std::invalid_argument("Сторони не утворюють трикутник.");
    }
}

// Деструктор
Triangle::~Triangle() {}

// Метод для обчислення площі за формулою Герона
double Triangle::area() const {
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

// Метод для перевірки, чи є сторони дійсним трикутником
bool Triangle::isValid() const {
    return (a + b > c && a + c > b && b + c > a);
}

// Перевантаження оператора <= для порівняння площ
bool Triangle::operator<=(const Triangle &other) const {
    return this->area() <= other.area();
}

// Перевантаження оператора += для збільшення сторін на задане значення
Triangle& Triangle::operator+=(double increment) {
    a += increment;
    b += increment;
    c += increment;
    if (!isValid()) {
        throw std::invalid_argument("Сторони не утворюють трикутник після збільшення.");
    }
    return *this;
}

// Метод для введення сторін трикутника
void Triangle::input() {
    std::cout << "Введіть сторони трикутника (a, b, c): ";
    std::cin >> a >> b >> c;
    if (!isValid()) {
        throw std::invalid_argument("Сторони не утворюють трикутник.");
    }
}

// Метод для виводу інформації про трикутник
void Triangle::display() const {
    std::cout << "Сторони: a=" << a << ", b=" << b << ", c=" << c << "\n";
    std::cout << "Площа: " << area() << "\n";
}
