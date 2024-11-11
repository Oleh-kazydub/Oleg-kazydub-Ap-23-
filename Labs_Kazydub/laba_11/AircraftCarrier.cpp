#include "AircraftCarrier.h"
#include <iostream>

AircraftCarrier::AircraftCarrier(std::string name, int length) : Ship(name, length) {}

const char* AircraftCarrier::type() const {
    return "Aircraft Carrier";
}

void AircraftCarrier::info() const {
    std::cout << "Aircraft Carrier: " << name << ", Length: " << length << " meters" << std::endl;
}
