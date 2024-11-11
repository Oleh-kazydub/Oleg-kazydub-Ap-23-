#ifndef SHIP_H
#define SHIP_H

#include <string>
#include <iostream>

class Ship {
protected:
    std::string name;
    int crew;

public:
    Ship(const std::string& name = "", int crew = 0);
    virtual ~Ship();

    virtual void display() const;
    virtual void saveToFile(std::ostream& os) const;
    virtual void loadFromFile(std::istream& is);

    void inputData();  // метод для вводу даних через getline
};

#endif
