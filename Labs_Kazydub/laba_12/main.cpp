#include <iostream>
#include <fstream>
#include <vector>
#include "Ship.h"
#include "Cruiser.h"
#include "AircraftCarrier.h"

int main() {
    std::vector<Ship*> ships;  // Вектор для зберігання кораблів
    int choice;

    try {
        while (true) {
            std::cout << "Оберіть тип корабля (1 - Авіаносець, 2 - Крейсер, 3 - Завершити): ";
            std::cin >> choice;
            std::cin.ignore();  // Очищаємо буфер після вводу

            if (choice == 1) {
                Ship* newShip = new AircraftCarrier();
                newShip->input();  // Вводимо дані корабля
                ships.push_back(newShip);  // Додаємо корабель до вектору
            } else if (choice == 2) {
                Ship* newShip = new Cruiser();
                newShip->input();  // Вводимо дані корабля
                ships.push_back(newShip);  // Додаємо корабель до вектору
            } else if (choice == 3) {
                break;  // Виходимо з циклу
            } else {
                std::cout << "Невірний вибір. Спробуйте ще раз." << std::endl;
            }
        }

        // Виведення інформації про кораблі
        for (const auto& ship : ships) {
            ship->displayInfo();
        }

        // Збереження даних у файл
        std::ofstream outFile("ships_data.txt");
        for (const auto& ship : ships) {
            ship->saveToFile(outFile);
        }
        outFile.close();

        // Завантаження даних з файлу
        std::ifstream inFile("ships_data.txt");
        while (!inFile.eof()) {
            std::string shipType;
            std::getline(inFile, shipType);
            Ship* loadedShip = nullptr;

            if (shipType == "Авіаносець") {
                loadedShip = new AircraftCarrier();
            } else if (shipType == "Крейсер") {
                loadedShip = new Cruiser();
            }

            if (loadedShip) {
                loadedShip->loadFromFile(inFile);
                loadedShip->displayInfo();
                ships.push_back(loadedShip);  // Додаємо завантажений корабель
            }
        }

        // Очищення пам'яті
        for (auto& ship : ships) {
            delete ship;
        }
        ships.clear();

    } catch (const std::exception& e) {
        std::cerr << "Помилка: " << e.what() << std::endl;
    }

    return 0;
}

