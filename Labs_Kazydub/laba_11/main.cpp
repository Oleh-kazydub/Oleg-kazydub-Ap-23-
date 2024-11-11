#include <iostream>
#include <string>

// Базовий клас Ship
class Ship {
protected:
    std::string name;
    int length;  // Довжина корабля

public:
    Ship(const std::string& n, int l) : name(n), length(l) {}

    virtual void info() const {
        std::cout << "Ship: " << name << ", Length: " << length << " meters\n";
    }
};

// Клас AircraftCarrier (Авіаносець)
class AircraftCarrier : public Ship {
public:
    AircraftCarrier(const std::string& n, int l) : Ship(n, l) {}

    void info() const override {
        std::cout << "Aircraft Carrier: " << name << ", Length: " << length << " meters\n";
    }
};

// Клас Cruiser (Крейсер)
class Cruiser : public Ship {
public:
    Cruiser(const std::string& n, int l) : Ship(n, l) {}

    void info() const override {
        std::cout << "Cruiser: " << name << ", Length: " << length << " meters\n";
    }
};

// Функція для перевірки правильності введення числа
int getValidInt(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        std::string input;
        std::getline(std::cin, input);  // Зчитуємо ввід як рядок

        try {
            value = std::stoi(input);  // Перетворюємо рядок в ціле число
            if (value > 0) {  // Перевірка, чи позитивне значення
                break;
            } else {
                std::cout << "Помилка: довжина має бути позитивним числом.\n";
            }
        } catch (const std::invalid_argument&) {
            std::cout << "Помилка: введіть ціле число.\n";
        } catch (const std::out_of_range&) {
            std::cout << "Помилка: число занадто велике.\n";
        }
    }
    return value;
}

int main() {
    std::string name;
    
    // Введення для авіаносця
    std::cout << "Введіть назву авіаносця: ";
    std::getline(std::cin, name);  // Введення назви корабля
    int length = getValidInt("Введіть довжину авіаносця в метрах: ");  // Введення довжини

    AircraftCarrier ac(name, length);  // Створення об'єкту авіаносця

    // Введення для крейсера
    std::cout << "Введіть назву крейсера: ";
    std::getline(std::cin, name);  // Введення назви корабля
    length = getValidInt("Введіть довжину крейсера в метрах: ");  // Введення довжини

    Cruiser cr(name, length);  // Створення об'єкту крейсера

    // Виведення інформації про кораблі
    std::cout << "\nДеталі кораблів:\n";
    ac.info();
    cr.info();

    return 0;
}
