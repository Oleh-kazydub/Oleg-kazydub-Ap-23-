#include "AircraftCarrier.h"
#include <iostream>

AircraftCarrier::AircraftCarrier(const std::string& name, double displacement, int numberOfAircraft)
    : Ship(name, displacement), numberOfAircraft(numberOfAircraft) {}

AircraftCarrier::~AircraftCarrier() {}

void AircraftCarrier::display() const {
    Ship::display();
    std::cout << "Number of Aircraft: " << numberOfAircraft << std::endl;
}

int AircraftCarrier::getNumberOfAircraft() const {
    return numberOfAircraft;
}

