#ifndef CARRIER_H
#define CARRIER_H

#include "Ship.h"
#include <iostream>

class Carrier : public Ship {
private:
    int aircraftCount; // Кількість літаків

public:
    Carrier(const std::string& name = "", int capacity = 0, int aircraftCount = 0)
        : Ship(name, capacity), aircraftCount(aircraftCount) {}

    void showInfo() const override {
        std::cout << "Carrier Ship: " << name << "\nCapacity: " << capacity
                  << "\nAircraft count: " << aircraftCount << std::endl;
    }

    void saveToFile(std::ofstream& ofs) const override {
        ofs << "Carrier " << name << " " << capacity << " " << aircraftCount << std::endl;
    }

    void loadFromFile(std::ifstream& ifs) override {
        ifs >> name >> capacity >> aircraftCount;
    }
};

#endif // CARRIER_H
