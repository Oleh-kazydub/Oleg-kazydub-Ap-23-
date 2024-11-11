#include "Cruiser.h"
#include <iostream>

Cruiser::Cruiser(const std::string& name, int crew, int weaponCount)
    : Ship(name, crew), weaponCount(weaponCount) {}

Cruiser::~Cruiser() {}

void Cruiser::display() const {
    Ship::display();
    std::cout << "Кількість озброєння: " << weaponCount << std::endl;
}

void Cruiser::saveToFile(std::ostream& os) const {
    Ship::saveToFile(os);
    os << weaponCount << '\n';
}

void Cruiser::loadFromFile(std::istream& is) {
    Ship::loadFromFile(is);
    std::string weaponStr;
    std::getline(is, weaponStr);
    weaponCount = std::stoi(weaponStr);
}

void Cruiser::inputData() {
    Ship::inputData();
    std::cout << "Введіть кількість озброєння: ";
    std::string weaponStr;
    std::getline(std::cin, weaponStr);
    weaponCount = std::stoi(weaponStr);
}
