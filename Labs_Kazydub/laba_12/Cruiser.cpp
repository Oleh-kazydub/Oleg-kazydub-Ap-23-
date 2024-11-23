#include "Cruiser.h"
#include <iostream>

Cruiser::Cruiser(std::string n, double l, double t, int c) : Ship(n, l, t, c) {}

void Cruiser::displayInfo() const {
    std::cout << "Крейсер " << name << "\n";
    Ship::displayInfo();
}

void Cruiser::input() {
    std::cout << "Введіть інформацію для Крейсера:\n";
    Ship::input();
}

void Cruiser::saveToFile(std::ofstream& outFile) {
    outFile << "Крейсер\n";
    Ship::saveToFile(outFile);
}

void Cruiser::loadFromFile(std::ifstream& inFile) {
    std::string temp;
    std::getline(inFile, temp); // Читання рядка "Крейсер"
    Ship::loadFromFile(inFile);
}
