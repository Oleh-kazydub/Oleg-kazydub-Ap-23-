#include "DataHandler.h"
#include <iostream>

void DataHandler::display(const Ship& ship) {
    ship.display();  // Викликається метод display() для кожного корабля
}

void DataHandler::calculateTotalDisplacement(const std::vector<Ship*>& ships) {
    double totalDisplacement = 0;
    for (const auto& ship : ships) {
        totalDisplacement += ship->getDisplacement();
    }
    std::cout << "\nЗагальна водотоннажність всіх кораблів: " << totalDisplacement << " тон" << std::endl;
}

