#include <iostream>
#include <limits>
#include <string>
#include "Carrier.h"
#include "Cruiser.h"

// Функція для вводу числових значень з перевіркою
template <typename T>
void getInput(const std::string& prompt, T& value) {
    std::cout << prompt;
    while (!(std::cin >> value)) {
        std::cout << "Некоректний ввід. Спробуйте ще раз: ";
        std::cin.clear(); // очищення стану потоку
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // очищення залишків вводу
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // очищення буфера після вводу числа
}

// Функція для вводу рядкових значень з перевіркою на непорожній рядок
void getStringInput(const std::string& prompt, std::string& value) {
    do {
        std::cout << prompt;
        std::getline(std::cin, value);
        if (value.empty()) {
            std::cout << "Ви не ввели значення. Будь ласка, спробуйте ще раз." << std::endl;
        }
    } while (value.empty()); // повторювати, поки введений рядок порожній
}

int main() {
    // Змінні для авіаносця
    std::string carrierName;
    int carrierCrewSize;
    double carrierDisplacement;
    int carrierAircraftCapacity;

    // Змінні для крейсера
    std::string cruiserName;
    int cruiserCrewSize;
    double cruiserDisplacement;
    int cruiserMissileCount;

    // Введення даних для авіаносця
    getStringInput("Введіть назву авіаносця: ", carrierName);
    getInput("Введіть кількість членів екіпажу авіаносця: ", carrierCrewSize);
    getInput("Введіть водотоннажність авіаносця (тонни): ", carrierDisplacement);
    getInput("Введіть кількість літаків на борту: ", carrierAircraftCapacity);

    // Створення об'єкта Carrier
    Carrier nimitz(carrierName, carrierCrewSize, carrierDisplacement, carrierAircraftCapacity);

    // Введення даних для крейсера
    getStringInput("Введіть назву крейсера: ", cruiserName);
    getInput("Введіть кількість членів екіпажу крейсера: ", cruiserCrewSize);
    getInput("Введіть водотоннажність крейсера (тонни): ", cruiserDisplacement);
    getInput("Введіть кількість ракет на борту крейсера: ", cruiserMissileCount);

    // Створення об'єкта Cruiser
    Cruiser germany(cruiserName, cruiserCrewSize, cruiserDisplacement, cruiserMissileCount);

    // Виведення даних
    std::cout << "\nДані про авіаносець:\n";
    nimitz.display();

    std::cout << "\nДані про крейсер:\n";
    germany.display();

    // Розрахунок загальної кількості членів екіпажу
    int totalCrew = nimitz.getCrewSize() + germany.getCrewSize();
    std::cout << "\nЗагальна кількість членів екіпажу на всіх кораблях: " << totalCrew << std::endl;

    return 0;
}
