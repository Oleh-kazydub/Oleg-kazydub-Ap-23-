#include "Carrier.h"
#include <iostream>

Carrier::Carrier(const std::string& name, int crew, int aircraftCapacity)
    : Ship(name, crew), aircraftCapacity(aircraftCapacity) {}

Carrier::~Carrier() {}

void Carrier::display() const {
    Ship::display();
    std::cout << "Місткість літаків: " << aircraftCapacity << std::endl;
}

void Carrier::saveToFile(std::ostream& os) const {
    Ship::saveToFile(os);
    os << aircraftCapacity << '\n';
}

void Carrier::loadFromFile(std::istream& is) {
    Ship::loadFromFile(is);
    std::string capacityStr;
    std::getline(is, capacityStr);
    aircraftCapacity = std::stoi(capacityStr);
}

void Carrier::inputData() {
    Ship::inputData();
    std::cout << "Введіть кількість літаків: ";
    std::string capacityStr;
    std::getline(std::cin, capacityStr);
    aircraftCapacity = std::stoi(capacityStr);
}
