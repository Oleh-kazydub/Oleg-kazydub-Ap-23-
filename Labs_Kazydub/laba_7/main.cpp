#include "product.h"
#include <iostream>
#include <limits>

void getInput(std::string& name, double& price, int& quantity) {
    std::cout << "Введіть назву товару: ";
    std::getline(std::cin, name);
    
    std::cout << "Введіть ціну: ";
    while (!(std::cin >> price) || price < 0) {
        std::cout << "Некоректне значення ціни. Спробуйте ще раз: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Введіть кількість: ";
    while (!(std::cin >> quantity) || quantity < 0) {
        std::cout << "Некоректне значення кількості. Спробуйте ще раз: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    Product productManager;
    int choice, id, position;
    std::string name;
    double price;
    int quantity;

    do {
        std::cout << "\n1. Додати товар\n2. Показати всі товари\n3. Оновити товар\n4. Видалити товар\n5. Очистити всі товари\n"
                  << "6. Вставити товар у позицію\n7. Обміняти товари місцями\n0. Вийти\n";
        std::cout << "Ваш вибір: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                getInput(name, price, quantity);
                productManager.addProduct(name, price, quantity);
                break;
            case 2:
                productManager.displayProducts();
                break;
            case 3:
                std::cout << "Введіть ID товару для оновлення: ";
                std::cin >> id;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                getInput(name, price, quantity);
                productManager.updateProduct(id, name, price, quantity);
                break;
            case 4:
                std::cout << "Введіть ID товару для видалення: ";
                std::cin >> id;
                productManager.deleteProduct(id);
                break;
            case 5:
                productManager.clearProducts();
                std::cout << "Список товарів очищено.\n";
                break;
            case 6:
                std::cout << "Введіть позицію для вставки товару: ";
                std::cin >> position;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                getInput(name, price, quantity);
                productManager.insertProduct(position, name, price, quantity);
                break;
            case 7:
                int id1, id2;
                std::cout << "Введіть ID першого товару: ";
                std::cin >> id1;
                std::cout << "Введіть ID другого товару: ";
                std::cin >> id2;
                productManager.swapProducts(id1, id2);
                break;
            case 0:
                std::cout << "Вихід...\n";
                break;
            default:
                std::cout << "Невірний вибір. Спробуйте ще раз.\n";
        }
    } while (choice != 0);

    return 0;
}
