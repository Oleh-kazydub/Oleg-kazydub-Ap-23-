#include "Ship.h"
#include <iostream>

Ship::Ship(const std::string& name, int crew) : name(name), crew(crew) {}

Ship::~Ship() {}

void Ship::display() const {
    std::cout << "Корабель: " << name << ", Екіпаж: " << crew << std::endl;
}

void Ship::saveToFile(std::ostream& os) const {
    os << name << '\n' << crew << '\n';
}

void Ship::loadFromFile(std::istream& is) {
    std::getline(is, name);
    std::string crewStr;
    std::getline(is, crewStr);
    crew = std::stoi(crewStr);
}

void Ship::inputData() {
    std::cout << "Введіть назву корабля: ";
    std::getline(std::cin, name);
    std::cout << "Введіть кількість екіпажу: ";
    std::string crewStr;
    std::getline(std::cin, crewStr);
    crew = std::stoi(crewStr);
}
