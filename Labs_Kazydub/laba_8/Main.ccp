#include <iostream>
#include "Carrier.h"
#include "Cruiser.h"

int main() {
    Carrier nimitz("USS Nimitz", 5000, 100000, 90);
    Cruiser germany("Germany", 500, 11000, 16);

    nimitz.display();
    germany.display();

    int totalCrew = nimitz.getCrewSize() + germany.getCrewSize();
    std::cout << "Total crew size on all ships: " << totalCrew << std::endl;

    return 0;
}
