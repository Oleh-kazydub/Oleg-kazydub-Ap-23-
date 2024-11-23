#ifndef SHIP_MANAGER_H
#define SHIP_MANAGER_H

#include "Ship.h"
#include "AircraftCarrier.h"
#include "Cruiser.h"

class ShipManager {
private:
    Ship* ship;

public:
    ShipManager(int choice);
    ~ShipManager();

    void inputShipData();
    void saveShipData(const std::string& filename);
    void loadShipData(const std::string& filename);
    void displayShipInfo() const;
};

#endif
