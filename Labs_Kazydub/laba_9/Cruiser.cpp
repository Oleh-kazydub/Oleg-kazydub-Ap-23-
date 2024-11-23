#include "Cruiser.h"
#include <iostream>

Cruiser::Cruiser(const std::string& name, double displacement, int numberOfGuns)
    : Ship(name, displacement), numberOfGuns(numberOfGuns) {}

Cruiser::~Cruiser() {}

void Cruiser::display() const {
    std::cout << "Крейсер: " << name << "\n"
              << "Водотоннажність: " << displacement << " тонн\n"
              << "Кількість гармат: " << numberOfGuns << std::endl;
}
