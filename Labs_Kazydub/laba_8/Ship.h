#ifndef SHIP_H
#define SHIP_H

#include <string>

class Ship {
protected:
    std::string name;
    int crewSize;  // кількість членів екіпажу
    double displacement; // водотоннажність (тонни)

public:
    Ship(const std::string& name, int crewSize, double displacement);
    virtual ~Ship();

    virtual void display() const;
    int getCrewSize() const;
};

#endif // SHIP_H
