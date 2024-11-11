#include "Cruiser.h"
#include <iostream>

Cruiser::Cruiser(std::string name, int length) : Ship(name, length) {}

const char* Cruiser::type() const {
    return "Cruiser";
}

void Cruiser::info() const {
    std::cout << "Cruiser: " << name << ", Length: " << length << " meters" << std::endl;
}
