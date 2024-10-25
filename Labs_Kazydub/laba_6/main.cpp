#include "product.h"
int main() {
    Product inventory;
    // Введення даних
    inventory.input();
    // Виведення даних
    std::cout << "Product data:" << std::endl;
    inventory.output();
    return 0;
}
