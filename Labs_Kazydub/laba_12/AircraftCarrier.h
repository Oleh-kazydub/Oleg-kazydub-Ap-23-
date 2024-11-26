#ifndef AIRCRAFTCARRIER_H
#define AIRCRAFTCARRIER_H

#include "Ship.h"

class AircraftCarrier : public Ship {
public:
    AircraftCarrier(std::string n = "", double l = 0, double t = 0, int c = 0)
        : Ship(n, l, t, c) {}

    void displayInfo() const override {
        std::cout << "Авіаносець: " << name << std::endl;
        Ship::displayInfo();
    }

    void input() override {
        std::cout << "Введіть інформацію для Авіаносця:\n";
        Ship::input();
    }

    void saveToFile(std::ofstream& outFile) override {
        outFile << "Авіаносець\n";
        Ship::saveToFile(outFile);
    }

    void loadFromFile(std::ifstream& inFile) override {
        std::string temp;
        std::getline(inFile, temp); // Читання "Авіаносець"
        Ship::loadFromFile(inFile);
    }
};

#endif // AIRCRAFTCARRIER_H
