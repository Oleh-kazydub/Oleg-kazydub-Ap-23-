#ifndef CRUISER_H
#define CRUISER_H

#include "Ship.h"

class Cruiser : public Ship {
    int weaponCount;  // кількість озброєння

public:
    Cruiser(const std::string& name = "", int crew = 0, int weaponCount = 0);
    ~Cruiser();

    void display() const override;
    void saveToFile(std::ostream& os) const override;
    void loadFromFile(std::istream& is) override;

    void inputData();  // метод для вводу даних через getline
};

#endif
