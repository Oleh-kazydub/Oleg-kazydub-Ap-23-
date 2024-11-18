#ifndef CRUISER_H
#define CRUISER_H

#include "Ship.h"
#include <iostream>

class Cruiser : public Ship {
private:
    int weaponCount; // Кількість видів зброї

public:
    Cruiser(const std::string& name = "", int capacity = 0, int weaponCount = 0)
        : Ship(name, capacity), weaponCount(weaponCount) {}

    void showInfo() const override {
        std::cout << "Cruiser: " << name << "\nCapacity: " << capacity
                  << "\nWeapon count: " << weaponCount << std::endl;
    }

    void saveToFile(std::ofstream& ofs) const override {
        ofs << "Cruiser " << name << " " << capacity << " " << weaponCount << std::endl;
    }

    void loadFromFile(std::ifstream& ifs) override {
        ifs >> name >> capacity >> weaponCount;
    }
};

#endif // CRUISER_H
