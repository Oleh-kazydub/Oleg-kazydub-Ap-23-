#ifndef SHIP_H
#define SHIP_H

#include <string>
#include <fstream>

class Ship {
public:
    Ship(std::string n = "", double l = 0, double t = 0, int c = 0);
    virtual ~Ship() {}

    virtual void displayInfo() const;
    virtual void input();
    virtual void saveToFile(std::ofstream& outFile);
    virtual void loadFromFile(std::ifstream& inFile);

protected:
    std::string name;
    double length;
    double tonnage;
    int capacity;
};

#endif // SHIP_H
