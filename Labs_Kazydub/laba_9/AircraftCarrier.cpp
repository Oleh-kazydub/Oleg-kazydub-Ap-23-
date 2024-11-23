#include "AircraftCarrier.h"
#include <iostream>

AircraftCarrier::AircraftCarrier(const std::string& name, double displacement, int numberOfAircraft)
    : Ship(name, displacement), numberOfAircraft(numberOfAircraft) {}

AircraftCarrier::~AircraftCarrier() {}

void AircraftCarrier::display() const {
    std::cout << "Авіаносець: " << name << "\n"
              << "Водотоннажність: " << displacement << " тонн\n"
              << "Кількість літаків: " << numberOfAircraft << std::endl;
}

