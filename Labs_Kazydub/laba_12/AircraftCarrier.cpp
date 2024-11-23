#include "AircraftCarrier.h"
#include <iostream>

AircraftCarrier::AircraftCarrier(std::string n, double l, double t, int c) : Ship(n, l, t, c) {}

void AircraftCarrier::displayInfo() const {
    std::cout << "Авіаносець " << name << "\n";
    Ship::displayInfo();
}

void AircraftCarrier::input() {
    std::cout << "Введіть інформацію для Авіаносця:\n";
    Ship::input();
}

void AircraftCarrier::saveToFile(std::ofstream& outFile) {
    outFile << "Авіаносець\n";
    Ship::saveToFile(outFile);
}

void AircraftCarrier::loadFromFile(std::ifstream& inFile) {
    std::string temp;
    std::getline(inFile, temp); // Читання рядка "Авіаносець"
    Ship::loadFromFile(inFile);
}
