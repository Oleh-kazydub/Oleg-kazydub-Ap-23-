#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <vector>
#include "Ship.h"

class DataHandler {
public:
    static void calculateTotalDisplacement(const std::vector<Ship*>& ships);
};

#endif // DATAHANDLER_H
