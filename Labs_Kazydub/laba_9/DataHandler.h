#include "Carrier.h"
#include <iostream>

Carrier::Carrier(const std::string& name, int crewSize, double displacement, int aircraftCapacity)
    : Ship(name, crewSize, displacement), aircraftCapacity(aircraftCapacity) {}

Carrier::~Carrier() {}

void Carrier::display() const {
    Ship::display();
    std::cout << "Aircraft Capacity: " << aircraftCapacity << std::endl;
}

int Carrier::getAircraftCapacity() const {
    return aircraftCapacity;
}
