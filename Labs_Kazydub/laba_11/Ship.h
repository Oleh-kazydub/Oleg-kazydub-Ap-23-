#ifndef SHIP_H
#define SHIP_H

#include <string>

class Ship {
protected:
    std::string name;
    int length;

public:
    Ship(std::string name, int length);
    virtual ~Ship() {}

    std::string getName() const;
    int getLength() const;

    // Віртуальний метод для визначення типу корабля
    virtual const char* type() const = 0;

    // Віртуальний метод для виведення інформації
    virtual void info() const;
};

#endif // SHIP_H
