#ifndef AIRCRAFTCARRIER_H
#define AIRCRAFTCARRIER_H

#include "Ship.h"

class AircraftCarrier : public Ship {
public:
    AircraftCarrier(std::string n = "", double l = 0, double t = 0, int c = 0);
    void displayInfo() const override;
    void input() override;
    void saveToFile(std::ofstream& outFile) override;
    void loadFromFile(std::ifstream& inFile) override;
};

#endif // AIRCRAFTCARRIER_H
