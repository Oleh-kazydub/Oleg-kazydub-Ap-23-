#ifndef CRUISER_H
#define CRUISER_H

#include "Ship.h"

class Cruiser : public Ship {
public:
    Cruiser(std::string name, int length);

    const char* type() const override;
    void info() const override;
};

#endif // CRUISER_H
