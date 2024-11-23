#include <iostream>
#include <vector>
#include <limits>
#include "AircraftCarrier.h"
#include "Cruiser.h"
#include "DataHandler.h"

void getInput(std::string& name, double& displacement, int& numAircraftOrGuns, const std::string& type) {
    // Введення назви
    while (true) {
        std::cout << "Введіть назву " << type << ": ";
        std::getline(std::cin, name);
        if (!name.empty()) {
            break;
        } else {
            std::cout << "Назва не може бути порожньою. Спробуйте ще раз.\n";
        }
    }

    // Введення водотоннажності
    std::cout << "Введіть водотоннажність " << type << " (в тоннах): ";
    while (!(std::cin >> displacement) || displacement <= 0) {
        std::cout << "Некоректне значення. Введіть дійсне число більше 0: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Очищення залишків

    // Введення кількості літаків/гармат
    std::cout << "Введіть кількість літаків/гармат для " << type << ": ";
    while (!(std::cin >> numAircraftOrGuns) || numAircraftOrGuns < 0) {
        std::cout << "Некоректне значення. Введіть дійсне число >= 0: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    std::vector<Ship*> ships;

    std::string name;
    double displacement;
    int numAircraftOrGuns;

    // Введення авіаносця
    std::cout << "Введення даних для авіаносця:\n";
    getInput(name, displacement, numAircraftOrGuns, "авіаносця");
    ships.push_back(new AircraftCarrier(name, displacement, numAircraftOrGuns));

    // Введення двох крейсерів
    for (int i = 1; i <= 2; ++i) {
        std::cout << "\nВведення даних для крейсера №" << i << ":\n";
        getInput(name, displacement, numAircraftOrGuns, "крейсера");
        ships.push_back(new Cruiser(name, displacement, numAircraftOrGuns));
    }

    // Виведення інформації про кораблі
    std::cout << "\nДані про кораблі:\n";
    for (const auto& ship : ships) {
        ship->display();
        std::cout << "---------------------\n";
    }

    // Обчислення загальної водотоннажності
    DataHandler::calculateTotalDisplacement(ships);

    // Звільнення пам'яті
    for (auto& ship : ships) {
        delete ship;
    }

    return 0;
}

