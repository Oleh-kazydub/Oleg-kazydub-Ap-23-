#include "Ship.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <cctype>
#include <algorithm>

Ship::Ship(std::string n, double l, double t, int c) : name(n), length(l), tonnage(t), capacity(c) {}

void Ship::displayInfo() const {
    std::cout << "Назва корабля: " << name << "\n";
    std::cout << "Довжина: " << length << " метри\n";
    std::cout << "Водотоннажність: " << tonnage << " тонн\n";
    std::cout << "Місткість для літаків: " << capacity << " літаків\n";
}

void Ship::input() {
    std::cout << "Введіть назву корабля: ";
    std::getline(std::cin, name);
    
    while (name.empty() || std::all_of(name.begin(), name.end(), ::isdigit)) {
        std::cout << "Назва не може бути порожньою і не повинна містити лише цифри. Спробуйте ще раз.\n";
        std::getline(std::cin, name);
    }

    std::cout << "Введіть довжину корабля: ";
    while (!(std::cin >> length) || length <= 0) {
        std::cout << "Помилка: Довжина повинна бути позитивною! Спробуйте ще раз.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Введіть водотоннажність корабля: ";
    while (!(std::cin >> tonnage) || tonnage <= 0) {
        std::cout << "Помилка: Водотоннажність повинна бути позитивною! Спробуйте ще раз.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Введіть місткість для літаків: ";
    while (!(std::cin >> capacity) || capacity <= 0) {
        std::cout << "Помилка: Місткість повинна бути позитивною! Спробуйте ще раз.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void Ship::saveToFile(std::ofstream& outFile) {
    outFile << name << "\n" << length << "\n" << tonnage << "\n" << capacity << "\n";
}

void Ship::loadFromFile(std::ifstream& inFile) {
    std::getline(inFile, name);
    inFile >> length >> tonnage >> capacity;
    inFile.ignore();
}
