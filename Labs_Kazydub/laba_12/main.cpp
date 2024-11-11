#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include "Carrier.h"
#include "Cruiser.h"

void saveDataToFile(const std::vector<std::shared_ptr<Ship>>& fleet, const std::string& filename) {
    std::ofstream ofs(filename);
    for (const auto& ship : fleet) {
        ship->saveToFile(ofs);
    }
}

void loadDataFromFile(std::vector<std::shared_ptr<Ship>>& fleet, const std::string& filename) {
    std::ifstream ifs(filename);
    while (ifs) {
        std::shared_ptr<Carrier> carrier = std::make_shared<Carrier>();
        carrier->loadFromFile(ifs);
        if (ifs) fleet.push_back(carrier);

        std::shared_ptr<Cruiser> cruiser = std::make_shared<Cruiser>();
        cruiser->loadFromFile(ifs);
        if (ifs) fleet.push_back(cruiser);
    }
}

int main() {
    std::vector<std::shared_ptr<Ship>> fleet;

    // Введення даних користувачем
    std::shared_ptr<Carrier> carrier = std::make_shared<Carrier>();
    carrier->inputData();
    fleet.push_back(carrier);

    std::shared_ptr<Cruiser> cruiser = std::make_shared<Cruiser>();
    cruiser->inputData();
    fleet.push_back(cruiser);

    // Збереження у файл
    saveDataToFile(fleet, "fleet_data.txt");

    // Завантаження з файлу
    fleet.clear();
    loadDataFromFile(fleet, "fleet_data.txt");

    // Виведення даних
    for (const auto& ship : fleet) {
        ship->display();
    }

    return 0;
}
