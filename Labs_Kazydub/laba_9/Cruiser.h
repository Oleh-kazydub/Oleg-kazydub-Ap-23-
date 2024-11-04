#ifndef CRUISER_H
#define CRUISER_H

#include "Ship.h"

class Cruiser : public Ship {
private:
    int numberOfGuns;

public:
    Cruiser(const std::string& name, double displacement, int numberOfGuns);
    ~Cruiser();
    
    void display() const override;
    int getNumberOfGuns() const;
};

#endif // CRUISER_H
