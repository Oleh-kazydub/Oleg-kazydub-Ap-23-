#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <limits>
#include "Ship.h"
#include "Carrier.h"
#include "Cruiser.h"

// Функція для перевірки, чи рядок не є порожнім
bool isValidName(const std::string& name) {
    return !name.empty();
}

// Функція для перевірки, чи введено дійсне позитивне число
bool isValidPositiveNumber(const std::string& str) {
    if (str.empty()) return false;

    for (char c : str) {
        if (c < '0' || c > '9') {
            return false;
        }
    }
    return std::stoi(str) > 0;
}

// Функція для збереження даних у файл
void saveToFile(const std::string& filename, const std::vector<Ship*>& ships) {
    std::ofstream ofs(filename);
    if (!ofs) {
        std::cerr << "Не вдалося відкрити файл для запису." << std::endl;
        return;
    }
    for (const auto& ship : ships) {
        ship->saveToFile(ofs);
    }
    ofs.close();
    std::cout << "Дані успішно збережено у файл." << std::endl;
}

// Функція для завантаження даних з файлу
void loadFromFile(const std::string& filename, std::vector<Ship*>& ships) {
    std::ifstream ifs(filename);
    if (!ifs) {
        std::cerr << "Не вдалося відкрити файл для читання." << std::endl;
        return;
    }

    std::string type;
    while (ifs >> type) {
        if (type == "Carrier") {
            Ship* ship = new Carrier();
            ship->loadFromFile(ifs);
            ships.push_back(ship);
        } else if (type == "Cruiser") {
            Ship* ship = new Cruiser();
            ship->loadFromFile(ifs);
            ships.push_back(ship);
        }
    }
    ifs.close();
    std::cout << "Дані успішно завантажено з файлу." << std::endl;
}

// Функція для введення нових кораблів
void addShip(std::vector<Ship*>& ships) {
    int choice;

    while (true) {
        std::cout << "Оберіть тип корабля для додавання:\n";
        std::cout << "1. Авіаносець\n";
        std::cout << "2. Крейсер\n";
        std::cin >> choice;

        if (std::cin.fail() || (choice != 1 && choice != 2)) {
            std::cout << "Невірний вибір. Будь ласка, введіть 1 або 2.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    std::cin.ignore(); // Очищуємо буфер вводу перед використанням getline
    std::string name, capacityStr;

    while (true) {
        std::cout << "Введіть назву корабля: ";
        std::getline(std::cin, name);
        if (isValidName(name)) {
            break;
        } else {
            std::cout << "Назва не може бути порожньою. Спробуйте ще раз.\n";
        }
    }

    while (true) {
        std::cout << "Введіть місткість корабля: ";
        std::getline(std::cin, capacityStr);
        if (isValidPositiveNumber(capacityStr)) {
            break;
        } else {
            std::cout << "Місткість має бути дійсним числом більше 0. Спробуйте ще раз.\n";
        }
    }
    int capacity = std::stoi(capacityStr);

    if (choice == 1) {
        std::string aircraftCountStr;
        while (true) {
            std::cout << "Введіть кількість літаків: ";
            std::getline(std::cin, aircraftCountStr);
            if (isValidPositiveNumber(aircraftCountStr)) {
                int aircraftCount = std::stoi(aircraftCountStr);
                ships.push_back(new Carrier(name, capacity, aircraftCount));
                break;
            } else {
                std::cout << "Кількість літаків має бути дійсним числом більше 0. Спробуйте ще раз.\n";
            }
        }
    } else if (choice == 2) {
        std::string weaponCountStr;
        while (true) {
            std::cout << "Введіть кількість видів зброї: ";
            std::getline(std::cin, weaponCountStr);
            if (isValidPositiveNumber(weaponCountStr)) {
                int weaponCount = std::stoi(weaponCountStr);
                ships.push_back(new Cruiser(name, capacity, weaponCount));
                break;
            } else {
                std::cout << "Кількість видів зброї має бути дійсним числом більше 0. Спробуйте ще раз.\n";
            }
        }
    }
}

int main() {
    std::vector<Ship*> ships;
    std::string filename = "ships.txt";

    int option;
    do {
        std::cout << "\nМеню:\n";
        std::cout << "1. Додати новий корабель\n";
        std::cout << "2. Вивести інформацію про всі кораблі\n";
        std::cout << "3. Зберегти дані у файл\n";
        std::cout << "4. Завантажити дані з файлу\n";
        std::cout << "5. Вийти\n";
        std::cin >> option;
        std::cin.ignore(); // Очищуємо буфер вводу перед використанням getline

        switch (option) {
            case 1:
                addShip(ships);
                break;
            case 2:
                for (const auto& ship : ships) {
                    ship->showInfo();
                }
                break;
            case 3:
                saveToFile(filename, ships);
                break;
            case 4:
                loadFromFile(filename, ships);
                break;
            case 5:
                std::cout << "Вихід з програми.\n";
                break;
            default:
                std::cout << "Невірний вибір. Спробуйте ще раз.\n";
                break;
        }
    } while (option != 5);

    // Очищаємо пам'ять
    for (auto& ship : ships) {
        delete ship;
    }

    return 0;
}
