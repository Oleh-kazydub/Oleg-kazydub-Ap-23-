#include "Ship.h"
#include <iostream>

Ship::Ship(const std::string& name, double displacement) : name(name), displacement(displacement) {}

Ship::~Ship() {}

void Ship::display() const {
    std::cout << "Ship Name: " << name << ", Displacement: " << displacement << " tons" << std::endl;
}

double Ship::getDisplacement() const {
    return displacement;
}
