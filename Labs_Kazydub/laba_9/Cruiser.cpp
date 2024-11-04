#include "Cruiser.h"
#include <iostream>

Cruiser::Cruiser(const std::string& name, double displacement, int numberOfGuns)
    : Ship(name, displacement), numberOfGuns(numberOfGuns) {}

Cruiser::~Cruiser() {}

void Cruiser::display() const {
    Ship::display();
    std::cout << "Number of Guns: " << numberOfGuns << std::endl;
}

int Cruiser::getNumberOfGuns() const {
    return numberOfGuns;
}
