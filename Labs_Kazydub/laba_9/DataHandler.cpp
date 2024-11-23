#include "DataHandler.h"
#include <iostream>

void DataHandler::calculateTotalDisplacement(const std::vector<Ship*>& ships) {
    double totalDisplacement = 0;
    for (const auto& ship : ships) {
        totalDisplacement += ship->getDisplacement();
    }
    std::cout << "Загальна водотоннажність всіх кораблів: " << totalDisplacement << " тонн\n";
}

