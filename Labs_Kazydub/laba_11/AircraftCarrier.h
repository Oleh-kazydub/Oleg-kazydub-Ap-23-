#ifndef AIRCRAFTCARRIER_H
#define AIRCRAFTCARRIER_H

#include "Ship.h"

class AircraftCarrier : public Ship {
public:
    AircraftCarrier(std::string name, int length);

    const char* type() const override;
    void info() const override;
};

#endif // AIRCRAFTCARRIER_H
