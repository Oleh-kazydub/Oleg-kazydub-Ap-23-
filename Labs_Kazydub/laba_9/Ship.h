#ifndef SHIP_H
#define SHIP_H

#include <string>

class Ship {
protected:
    std::string name;
    double displacement; // in tons

public:
    Ship(const std::string& name, double displacement);
    virtual ~Ship();
    
    virtual void display() const;
    double getDisplacement() const;
};

#endif // SHIP_H
