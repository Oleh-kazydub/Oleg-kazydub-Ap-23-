#include "ShipManager.h"
#include <fstream>
#include <stdexcept>

ShipManager::ShipManager(int choice) {
    if (choice == 1) {
        ship = new AircraftCarrier();
    } else if (choice == 2) {
        ship = new Cruiser();
    } else {
        throw std::invalid_argument("Невірно вибрано тип корабля!");
    }
}

ShipManager::~ShipManager() {
    delete ship;
}

void ShipManager::inputShipData() {
    ship->input();
}

void ShipManager::saveShipData(const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile) throw std::ios_base::failure("Не вдалося відкрити файл для запису!");
    ship->saveToFile(outFile);
}

void ShipManager::loadShipData(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) throw std::ios_base::failure("Не вдалося відкрити файл для зчитування!");
    ship->loadFromFile(inFile);
}

void ShipManager::displayShipInfo() const {
    ship->displayInfo();
}
