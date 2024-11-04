#include "Cruiser.h"
#include <iostream>

Cruiser::Cruiser(const std::string& name, int crewSize, double displacement, int missileCount)
    : Ship(name, crewSize, displacement), missileCount(missileCount) {}

Cruiser::~Cruiser() {}

void Cruiser::display() const {
    Ship::display();
    std::cout << "Missile Count: " << missileCount << std::endl;
}

int Cruiser::getMissileCount() const {
    return missileCount;
}
