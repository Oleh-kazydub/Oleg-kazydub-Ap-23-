#include "Ship.h"
#include <iostream>

Ship::Ship(const std::string& name, double displacement)
    : name(name), displacement(displacement) {}

Ship::~Ship() {}

double Ship::getDisplacement() const {
    return displacement;
}
