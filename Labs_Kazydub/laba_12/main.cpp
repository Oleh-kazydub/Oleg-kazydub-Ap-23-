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
            std::cout << "Оберіть дію:\n";
            std::cout << "1 - Ввести новий корабель\n";
            std::cout << "2 - Завантажити дані з файлу\n";
            std::cout << "3 - Вивести інформацію про кораблі\n";
            std::cout << "4 - Зберегти дані в файл\n";
            std::cout << "5 - Завершити програму\n";
            std::cout << "Ваш вибір: ";
            std::cin >> choice;
            std::cin.ignore();  // Очищаємо буфер після вводу

            if (choice == 1) {
                std::cout << "Оберіть тип корабля (1 - Авіаносець, 2 - Крейсер): ";
                int shipType;
                std::cin >> shipType;
                std::cin.ignore();

                if (shipType == 1) {
                    Ship* newShip = new AircraftCarrier();
                    newShip->input();  // Вводимо дані корабля
                    ships.push_back(newShip);  // Додаємо корабель до вектору
                } else if (shipType == 2) {
                    Ship* newShip = new Cruiser();
                    newShip->input();  // Вводимо дані корабля
                    ships.push_back(newShip);  // Додаємо корабель до вектору
                } else {
                    std::cout << "Невірний вибір типу корабля.\n";
                }
            } else if (choice == 2) {
                // Завантаження даних з файлу
                std::ifstream inFile("ships_data.txt");
                if (inFile) {
                    std::cout << "Завантаження даних з файлу...\n";
                    while (!inFile.eof()) {
                        std::string shipType;
                        inFile >> shipType;  // Читаємо тип корабля

                        Ship* loadedShip = nullptr;
                        if (shipType == "Авіаносець") {
                            loadedShip = new AircraftCarrier();
                        } else if (shipType == "Крейсер") {
                            loadedShip = new Cruiser();
                        }

                        if (loadedShip) {
                            loadedShip->loadFromFile(inFile);  // Завантажуємо дані з файлу
                            ships.push_back(loadedShip);  // Додаємо завантажений корабель в список
                        }
                    }
                    inFile.close();
                } else {
                    std::cout << "Не вдалося відкрити файл для завантаження.\n";
                }
            } else if (choice == 3) {
                // Виведення інформації про всі кораблі
                std::cout << "\nІнформація про всі кораблі:\n";
                for (const auto& ship : ships) {
                    ship->displayInfo();
                }
            } else if (choice == 4) {
                // Збереження даних у файл
                std::ofstream outFile("ships_data.txt");
                if (!outFile) {
                    std::cerr << "Помилка при відкритті файлу для запису!" << std::endl;
                    return 1;
                }

                for (const auto& ship : ships) {
                    // Записуємо тип корабля
                    if (dynamic_cast<AircraftCarrier*>(ship)) {
                        outFile << "Авіаносець\n";
                    } else if (dynamic_cast<Cruiser*>(ship)) {
                        outFile << "Крейсер\n";
                    }
                    ship->saveToFile(outFile);  // Записуємо дані корабля
                }
                outFile.close();
                std::cout << "\nДані збережено у файл 'ships_data.txt'.\n";
            } else if (choice == 5) {
                // Завершення програми
                std::cout << "Завершення програми...\n";
                break;
            } else {
                std::cout << "Невірний вибір. Спробуйте ще раз.\n";
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

