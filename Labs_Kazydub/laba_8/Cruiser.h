#ifndef CRUISER_H
#define CRUISER_H

#include "Ship.h"

class Cruiser : public Ship {
private:
    int missileCount; // кількість ракет

public:
    Cruiser(const std::string& name, int crewSize, double displacement, int missileCount);
    ~Cruiser();

    void display() const override;
    int getMissileCount() const;
};

#endif // CRUISER_H
