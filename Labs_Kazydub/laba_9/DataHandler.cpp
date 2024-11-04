#ifndef CARRIER_H
#define CARRIER_H

#include "Ship.h"

class Carrier : public Ship {
private:
    int aircraftCapacity; // кількість літаків на борту

public:
    Carrier(const std::string& name, int crewSize, double displacement, int aircraftCapacity);
    ~Carrier();

    void display() const override;
    int getAircraftCapacity() const;
};

#endif // CARRIER_H
