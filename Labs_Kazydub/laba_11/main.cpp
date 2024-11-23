#include <iostream>
#include <string>
#include "AircraftCarrier.h"
#include "Cruiser.h"

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

// Функція для перевірки правильності введення назви корабля
std::string getValidName(const std::string& prompt) {
    std::string name;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, name);  // Зчитуємо назву корабля

        if (!name.empty()) {  // Перевірка, чи не порожня назва
            break;
        } else {
            std::cout << "Помилка: назва не може бути порожньою.\n";
        }
    }
    return name;
}

int main() {
    // Введення для авіаносця
    std::string name = getValidName("Введіть назву авіаносця: ");  // Введення назви
    int length = getValidInt("Введіть довжину авіаносця в метрах: ");  // Введення довжини

    AircraftCarrier ac(name, length);  // Створення об'єкту авіаносця

    // Введення для крейсера
    name = getValidName("Введіть назву крейсера: ");  // Введення назви
    length = getValidInt("Введіть довжину крейсера в метрах: ");  // Введення довжини

    Cruiser cr(name, length);  // Створення об'єкту крейсера

    // Виведення інформації про кораблі
    std::cout << "\nДеталі кораблів:\n";
    ac.info();
    cr.info();

    return 0;
}
