#ifndef SHIP_H
#define SHIP_H

#include <iostream>
#include <string>
#include <vector>

// Абстрактний клас Ship
class Ship {
protected:
    std::string name;
    int length;

public:
    Ship(std::string name, int length) : name(name), length(length) {}
    virtual ~Ship() {}

    std::string getName() const { return name; }
    int getLength() const { return length; }

    // Віртуальний метод для визначення типу корабля
    virtual const char* type() const = 0;

    // Віртуальний метод для виведення інформації
    virtual void info() const {
        std::cout << "Ship: " << name << ", Type: " << type() << ", Length: " << length << " meters" << std::endl;
    }
};

// Клас Cruiser, який наслідує Ship
class Cruiser : public Ship {
public:
    Cruiser(std::string name, int length) : Ship(name, length) {}

    const char* type() const override {
        return "Cruiser";
    }

    void info() const override {
        std::cout << "Cruiser: " << name << ", Length: " << length << " meters" << std::endl;
    }
};

// Клас AircraftCarrier, який наслідує Ship
class AircraftCarrier : public Ship {
public:
    AircraftCarrier(std::string name, int length) : Ship(name, length) {}

    const char* type() const override {
        return "Aircraft Carrier";
    }

    void info() const override {
        std::cout << "Aircraft Carrier: " << name << ", Length: " << length << " meters" << std::endl;
    }
};

#endif // SHIP_H
