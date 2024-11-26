#ifndef CRUISER_H
#define CRUISER_H

#include "Ship.h"

class Cruiser : public Ship {
public:
    Cruiser(std::string n = "", double l = 0, double t = 0, int c = 0)
        : Ship(n, l, t, c) {}

    void displayInfo() const override {
        std::cout << "Крейсер: " << name << std::endl;
        Ship::displayInfo();
    }

    void input() override {
        std::cout << "Введіть інформацію для Крейсера:\n";
        Ship::input();
    }

    void saveToFile(std::ofstream& outFile) override {
        outFile << "Крейсер\n";
        Ship::saveToFile(outFile);
    }

    void loadFromFile(std::ifstream& inFile) override {
        std::string temp;
        std::getline(inFile, temp); // Читання "Крейсер"
        Ship::loadFromFile(inFile);
    }
};

#endif // CRUISER_H

