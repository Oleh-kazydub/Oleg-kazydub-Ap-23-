#ifndef SHIP_H
#define SHIP_H

#include <string>
#include <fstream>
#include <iostream>
#include <stdexcept>

class Ship {
public:
    Ship(std::string name = "", double length = 0, double tonnage = 0, int capacity = 0)
        : name(name), length(length), tonnage(tonnage), capacity(capacity) {}

    virtual ~Ship() {}

    virtual void displayInfo() const {
        std::cout << "Назва корабля: " << name << std::endl;
        std::cout << "Довжина: " << length << " м" << std::endl;
        std::cout << "Водотоннажність: " << tonnage << " тонн" << std::endl;
        std::cout << "Місткість: " << capacity << " літаків" << std::endl;
    }

    virtual void input() {
        // Перевірка назви корабля
        while (true) {
            std::cout << "Введіть назву корабля: ";
            std::getline(std::cin, name);

            if (name.empty()) {
                std::cout << "Назва не може бути порожньою. Спробуйте ще раз." << std::endl;
            } else {
                break;  // Виходимо з циклу, якщо назва введена правильно
            }
        }

        // Перевірка введення довжини
        std::cout << "Введіть довжину корабля: ";
        std::cin >> length;
        if (length <= 0) throw std::invalid_argument("Довжина не може бути меншою або рівною нулю.");

        // Перевірка введення водотоннажності
        std::cout << "Введіть водотоннажність корабля: ";
        std::cin >> tonnage;
        if (tonnage <= 0) throw std::invalid_argument("Водотоннажність не може бути меншою або рівною нулю.");

        // Перевірка введення місткості
        std::cout << "Введіть місткість для літаків: ";
        std::cin >> capacity;
        if (capacity <= 0) throw std::invalid_argument("Місткість не може бути меншою або рівною нулю.");

        std::cin.ignore();  // Очищаємо буфер після вводу
    }

    virtual void saveToFile(std::ofstream& outFile) {
        outFile << name << std::endl;
        outFile << length << std::endl;
        outFile << tonnage << std::endl;
        outFile << capacity << std::endl;
    }

    virtual void loadFromFile(std::ifstream& inFile) {
        std::getline(inFile, name);
        inFile >> length >> tonnage >> capacity;
        inFile.ignore();  // Очищаємо буфер після вводу
    }

    bool operator<(const Ship& other) const {
        return length < other.length;
    }

protected:
    std::string name;
    double length;
    double tonnage;
    int capacity;
};

#endif // SHIP_H
