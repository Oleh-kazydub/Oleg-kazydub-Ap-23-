#include "Ship.h"
#include <iostream>

Ship::Ship(std::string name, int length) : name(name), length(length) {}

std::string Ship::getName() const {
    return name;
}

int Ship::getLength() const {
    return length;
}

void Ship::info() const {
    std::cout << "Ship: " << name << ", Type: " << type() << ", Length: " << length << " meters" << std::endl;
}
