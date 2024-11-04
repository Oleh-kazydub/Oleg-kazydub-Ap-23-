#include <iostream>
#include <vector> // Додано для використання векторів
#include "Ship.h"
#include "AircraftCarrier.h"
#include "Cruiser.h"
#include "DataHandler.h"

int main() {
    std::vector<Ship*> ships; // Використовуємо вектор для зберігання кораблів

    // Створення кораблів
    ships.push_back(new AircraftCarrier("USS Nimitz", 100000, 60));
    ships.push_back(new Cruiser("USS Ticonderoga", 9800, 12));
    ships.push_back(new Cruiser("USS San Antonio", 25000, 11));

    // Виведення даних про кожен корабель
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
