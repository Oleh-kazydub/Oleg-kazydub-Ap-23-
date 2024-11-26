#include <iostream>
#include <string>
#include <vector>
#include "Ship.h"

// Функція для перевірки правильності введення числа
int getValidInt(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        std::string input;
        std::getline(std::cin, input); // Зчитуємо ввід як рядок

        try {
            value = std::stoi(input); // Перетворюємо рядок в ціле число
            if (value > 0) { // Перевірка, чи позитивне значення
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

// Функція для перевірки правильності введення назви корабля
std::string getValidName(const std::string& prompt) {
    std::string name;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, name); // Зчитуємо назву корабля

        if (!name.empty()) { // Перевірка, чи не порожня назва
            break;
        } else {
            std::cout << "Помилка: назва не може бути порожньою.\n";
        }
    }
    return name;
}

int main() {
    std::vector<Ship*> ships; // Вектор для зберігання вказівників на об'єкти Ship

    // Введення для авіаносця
    std::string name = getValidName("Введіть назву авіаносця: ");
    int length = getValidInt("Введіть довжину авіаносця в метрах: ");
    Ship* ac = new AircraftCarrier(name, length); // Створення об'єкту авіаносця
    ships.push_back(ac); // Додавання вектор

    // Введення для крейсера
    name = getValidName("Введіть назву крейсера: ");
    length = getValidInt("Введіть довжину крейсера в метрах: ");
    Ship* cr = new Cruiser(name, length); // Створення об'єкту крейсера
    ships.push_back(cr); // Додавання вектор

    // Виведення інформації про кораблі
    std::cout << "\nДеталі кораблів:\n";
    for (Ship* ship : ships) {
        ship->info(); // Виклик через вказівник, інформація виводиться віртуальним методом
    }

    // Звільнення пам'яті
    for (Ship* ship : ships) {
        delete ship; // Очищення пам'яті для кожного корабля
    }

    return 0;
}

