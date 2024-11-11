#ifndef CARRIER_H
#define CARRIER_H

#include "Ship.h"

class Carrier : public Ship {
    int aircraftCapacity;  // кількість літаків

public:
    Carrier(const std::string& name = "", int crew = 0, int aircraftCapacity = 0);
    ~Carrier();

    void display() const override;
    void saveToFile(std::ostream& os) const override;
    void loadFromFile(std::istream& is) override;

    void inputData();  // метод для вводу даних через getline
};

#endif
