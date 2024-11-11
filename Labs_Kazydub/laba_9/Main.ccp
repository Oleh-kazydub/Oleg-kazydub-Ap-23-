#include <iostream>
#include <vector>  // Додано для використання векторів
#include <limits>  // Потрібно для std::numeric_limits
#include "Ship.h"
#include "AircraftCarrier.h"
#include "Cruiser.h"
#include "DataHandler.h"

void getInput(std::string& name, double& displacement, int& numAircraftOrGuns) {
    std::cout << "Введіть назву корабля: ";
    std::getline(std::cin, name);  // Використовуємо getline для введення назви корабля

    // Введення водотоннажності з перевіркою коректності
    std::cout << "Введіть водотоннажність корабля (в тоннах): ";
    while (!(std::cin >> displacement) || displacement <= 0) {
        std::cout << "Некоректне значення водотоннажності. Спробуйте ще раз: ";
        std::cin.clear();  // Очищуємо потік від помилок
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Очищаємо буфер
    }

    // Очищення буфера після введення числа
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Очищаємо залишкові символи в буфері

    // Введення кількості літаків або гармат з перевіркою коректності
    std::cout << "Введіть кількість літаків або гармат на борту: ";
    while (!(std::cin >> numAircraftOrGuns) || numAircraftOrGuns < 0) {
        std::cout << "Некоректне значення кількості літаків/гармат. Спробуйте ще раз: ";
        std::cin.clear();  // Очищуємо потік від помилок
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Очищаємо буфер
    }

    // Очищення буфера після введення числа
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Очищаємо залишкові символи в буфері
}

int main() {
    std::vector<Ship*> ships;  // Використовуємо вектор для зберігання кораблів

    std::string name;
    double displacement;
    int numAircraftOrGuns;

    // Введення даних для авіаносця
    std::cout << "Введіть дані для авіаносця:\n";
    getInput(name, displacement, numAircraftOrGuns);
    ships.push_back(new AircraftCarrier(name, displacement, numAircraftOrGuns));

    // Введення даних для крейсера 1
    std::cout << "\nВведіть дані для першого крейсера:\n";
    getInput(name, displacement, numAircraftOrGuns);
    ships.push_back(new Cruiser(name, displacement, numAircraftOrGuns));

    // Введення даних для крейсера 2
    std::cout << "\nВведіть дані для другого крейсера:\n";
    getInput(name, displacement, numAircraftOrGuns);
    ships.push_back(new Cruiser(name, displacement, numAircraftOrGuns));

    // Виведення даних про кожен корабель
    std::cout << "\nДані про кораблі:\n";
    for (const auto& ship : ships) {
        DataHandler::display(*ship);
    }

    // Обчислення та виведення загальної водотоннажності
    DataHandler::calculateTotalDisplacement(ships); // Передаємо вектор

    // Очищення пам'яті
    for (auto& ship : ships) {
        delete ship;
    }

    return 0;
}
