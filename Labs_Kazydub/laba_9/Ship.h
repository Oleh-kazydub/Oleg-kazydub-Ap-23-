#ifndef SHIP_H
#define SHIP_H

#include <string>
#include <iostream>
#include <vector>

// Базовий клас для кораблів
class Ship {
protected:
    std::string name;
    double displacement; // in tons

public:
    Ship(const std::string& name, double displacement);
    virtual ~Ship();

    virtual void display() const;
    double getDisplacement() const;

    // Дружня функція для зміни водотоннажності
    friend void changeDisplacement(Ship& ship, double newDisplacement);

    // Дружній клас для виведення деталей корабля
    friend class ShipDisplay;
};

// Клас для авіаносців
class AircraftCarrier : public Ship {
private:
    int numberOfAircraft;

public:
    AircraftCarrier(const std::string& name, double displacement, int numberOfAircraft);
    ~AircraftCarrier();

    void display() const override;
    int getNumberOfAircraft() const;

    // Дружня функція для зміни кількості літаків
    friend void setAircraftCount(AircraftCarrier& carrier, int newCount);
};

// Клас для крейсерів
class Cruiser : public Ship {
private:
    int numberOfGuns;

public:
    Cruiser(const std::string& name, double displacement, int numberOfGuns);
    ~Cruiser();

    void display() const override;
    int getNumberOfGuns() const;

    // Дружня функція для зміни кількості гармат
    friend void setGunsCount(Cruiser& cruiser, int newCount);
};

// Клас для виведення деталей кораблів
class ShipDisplay {
public:
    static void displayDetails(const Ship& ship);
};

// Клас для обробки даних
class DataHandler {
public:
    static void calculateTotalDisplacement(const std::vector<Ship*>& ships);
};

#endif // SHIP_H

