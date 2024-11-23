#ifndef CRUISER_H
#define CRUISER_H

#include "Ship.h"

class Cruiser : public Ship {
public:
    Cruiser(std::string n = "", double l = 0, double t = 0, int c = 0);
    void displayInfo() const override;
    void input() override;
    void saveToFile(std::ofstream& outFile) override;
    void loadFromFile(std::ifstream& inFile) override;
};

#endif // CRUISER_H
