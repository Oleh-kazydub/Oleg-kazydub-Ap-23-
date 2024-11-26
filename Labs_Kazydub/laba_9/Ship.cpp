#include "Ship.h"

// Реалізація класу Ship
Ship::Ship(const std::string& name, double displacement)
    : name(name), displacement(displacement) {}

Ship::~Ship() {}

double Ship::getDisplacement() const {
    return displacement;
}

void Ship::display() const {
    std::cout << "Назва: " << name << "\n"
              << "Водотоннажність: " << displacement << " тонн" << std::endl;
}

// Дружня функція для зміни водотоннажності корабля
void changeDisplacement(Ship& ship, double newDisplacement) {
    if (newDisplacement > 0) {
        ship.displacement = newDisplacement;
    } else {
        std::cout << "Некоректна водотоннажність!" << std::endl;
    }
}

// Реалізація класу AircraftCarrier
AircraftCarrier::AircraftCarrier(const std::string& name, double displacement, int numberOfAircraft)
    : Ship(name, displacement), numberOfAircraft(numberOfAircraft) {}

AircraftCarrier::~AircraftCarrier() {}

void AircraftCarrier::display() const {
    std::cout << "Авіаносець: " << name << "\n"
              << "Водотоннажність: " << displacement << " тонн\n"
              << "Кількість літаків: " << numberOfAircraft << std::endl;
}

void setAircraftCount(AircraftCarrier& carrier, int newCount) {
    if (newCount >= 0) {
        carrier.numberOfAircraft = newCount;
    } else {
        std::cout << "Некоректна кількість літаків!" << std::endl;
    }
}

// Реалізація класу Cruiser
Cruiser::Cruiser(const std::string& name, double displacement, int numberOfGuns)
    : Ship(name, displacement), numberOfGuns(numberOfGuns) {}

Cruiser::~Cruiser() {}

void Cruiser::display() const {
    std::cout << "Крейсер: " << name << "\n"
              << "Водотоннажність: " << displacement << " тонн\n"
              << "Кількість гармат: " << numberOfGuns << std::endl;
}

void setGunsCount(Cruiser& cruiser, int newCount) {
    if (newCount >= 0) {
        cruiser.numberOfGuns = newCount;
    } else {
        std::cout << "Некоректна кількість гармат!" << std::endl;
    }
}

// Реалізація класу ShipDisplay
void ShipDisplay::displayDetails(const Ship& ship) {
    std::cout << "Назва: " << ship.name << "\n"
              << "Водотоннажність: " << ship.displacement << " тонн" << std::endl;
}

// Реалізація класу DataHandler
void DataHandler::calculateTotalDisplacement(const std::vector<Ship*>& ships) {
    double totalDisplacement = 0;
    for (const auto& ship : ships) {
        totalDisplacement += ship->getDisplacement();
    }
    std::cout << "Загальна водотоннажність всіх кораблів: " << totalDisplacement << " тонн\n";
}
