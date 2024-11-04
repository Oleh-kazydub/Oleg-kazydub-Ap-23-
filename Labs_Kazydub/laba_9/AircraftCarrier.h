#ifndef AIRCRAFTCARRIER_H
#define AIRCRAFTCARRIER_H

#include "Ship.h"

class AircraftCarrier : public Ship {
private:
    int numberOfAircraft;

public:
    AircraftCarrier(const std::string& name, double displacement, int numberOfAircraft);
    ~AircraftCarrier();
    
    void display() const override;
    int getNumberOfAircraft() const;
};

#endif // AIRCRAFTCARRIER_H
