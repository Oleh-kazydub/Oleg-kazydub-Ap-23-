#include <iostream>
#include <limits>
#include "Carrier.h"
#include "Cruiser.h"

// Функція для вводу числових значень з перевіркою
template <typename T>
void getInput(const std::string& prompt, T& value) {
    std::cout << prompt;
    while (!(std::cin >> value)) {
        std::cout << "Некоректний ввід. Спробуйте ще раз: ";
        std::cin.clear(); // очищення потоку
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ігнорування залишків вводу
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // очищення буфера після вводу числа
}

// Функція для вводу рядкових значень
void getStringInput(const std::string& prompt, std::string& value) {
    std::cout << prompt;
    std::getline(std::cin, value);
}

int main() {
    std::string name;
    int crewSize, aircraftCapacity, missileCount;
    double displacement;

    // Введення даних для авіаносця
    getStringInput("Введіть назву авіаносця: ", name);
    getInput("Введіть кількість членів екіпажу авіаносця: ", crewSize);
    getInput("Введіть водотоннажність авіаносця (тонни): ", displacement);
    getInput("Введіть кількість літаків на борту: ", aircraftCapacity);

    Carrier nimitz(name, crewSize, displacement, aircraftCapacity);

    // Введення даних для крейсера
    getStringInput("Введіть назву крейсера: ", name);
    getInput("Введіть кількість членів екіпажу крейсера: ", crewSize);
    getInput("Введіть водотоннажність крейсера (тонни): ", displacement);
    getInput("Введіть кількість ракет на борту крейсера: ", missileCount);

    Cruiser germany(name, crewSize, displacement, missileCount);

    // Виведення даних
    nimitz.display();
    germany.display();

    int totalCrew = nimitz.getCrewSize() + germany.getCrewSize();
    std::cout << "Загальна кількість членів екіпажу на всіх кораблях: " << totalCrew << std::endl;

    return 0;
}
