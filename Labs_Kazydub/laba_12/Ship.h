#ifndef SHIP_H
#define SHIP_H

#include <string>
#include <fstream>

class Ship {
protected:
    std::string name;
    int capacity;

public:
    Ship(const std::string& name = "", int capacity = 0) : name(name), capacity(capacity) {}
    virtual ~Ship() {}

    virtual void showInfo() const = 0; // Чисто віртуальний метод для виведення інформації
    virtual void saveToFile(std::ofstream& ofs) const = 0; // Віртуальний метод для запису у файл
    virtual void loadFromFile(std::ifstream& ifs) = 0; // Віртуальний метод для читання з файлу
};

#endif // SHIP_H
