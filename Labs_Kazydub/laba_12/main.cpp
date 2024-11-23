#include <iostream>
#include <fstream>
#include "AircraftCarrier.h"
#include "Cruiser.h"

int main() {
    int choice;
    std::cout << "Оберіть тип корабля (1 - Авіаносець, 2 - Крейсер): ";
    std::cin >> choice;
    std::cin.ignore(); // Очищаємо потік після вибору

    Ship* ship = nullptr;

    try {
        if (choice == 1) {
            ship = new AircraftCarrier();
        } else if (choice == 2) {
            ship = new Cruiser();
        } else {
            throw std::invalid_argument("Невірний вибір типу корабля!");
        }

        ship->input();
        ship->displayInfo();
        
        // Збереження даних у файл
        std::ofstream outFile("ship_data.txt");
        if (!outFile) {
            throw std::ios_base::failure("Помилка при відкритті файлу для запису.");
        }
        ship->saveToFile(outFile);
        outFile.close();

        // Завантаження даних з файлу
        Ship* loadedShip = nullptr;
        std::ifstream inFile("ship_data.txt");
        if (!inFile) {
            throw std::ios_base::failure("Помилка при відкритті файлу для читання.");
        }

        std::string shipType;
        inFile >> shipType;
        if (shipType == "Aviancosec") {
            loadedShip = new AircraftCarrier();
        } else if (shipType == "Cruiser") {
            loadedShip = new Cruiser();
        }

        loadedShip->loadFromFile(inFile);
        loadedShip->displayInfo();
        inFile.close();
        
        delete ship;
        delete loadedShip;
    }
    catch (const std::exception& e) {
        std::cerr << "Помилка: " << e.what() << std::endl;
    }

    return 0;
}

