#include "Ship.h"
#include <iostream>

Ship::Ship(const std::string& name, int crewSize, double displacement)
    : name(name), crewSize(crewSize), displacement(displacement) {}

Ship::~Ship() {}

void Ship::display() const {
    std::cout << "Ship: " << name << ", Crew Size: " << crewSize 
              << ", Displacement: " << displacement << " tons" << std::endl;
}

int Ship::getCrewSize() const {
    return crewSize;
}
