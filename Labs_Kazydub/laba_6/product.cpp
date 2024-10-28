#include "product.h"

// Конструктор за замовчуванням
Product::Product() {
    for (int i = 0; i < SIZE; ++i) {
        products[i].id = 0;
        products[i].name = "Unknown";
        products[i].price = 0.0;
        products[i].quantity = 0;
    }
}

// Деструктор
Product::~Product() {}

// Введення даних про товари
void Product::input() {
    for (int i = 0; i < SIZE; ++i) {
        std::cout << "Enter ID for product " << i + 1 << ": ";
        std::cin >> products[i].id;

        std::cout << "Enter name for product " << i + 1 << ": ";
        std::cin.ignore(); // Clear the newline character from the input buffer
        std::getline(std::cin, products[i].name); // Use getline for name input

        std::cout << "Enter price for product " << i + 1 << ": ";
        std::cin >> products[i].price;

        std::cout << "Enter quantity for product " << i + 1 << ": ";
        std::cin >> products[i].quantity;

        // Перевірка даних
        setId(products[i].id);
        setName(products[i].name);
        setPrice(products[i].price);
        setQuantity(products[i].quantity);
    }
}

// Виведення даних про товари
void Product::output() const {
    for (const auto& product : products) {
        std::cout << "ID: " << product.id 
                  << ", Name: " << product.name 
                  << ", Price: " << product.price 
                  << ", Quantity: " << product.quantity 
                  << std::endl;
    }
}

// Перевірка і встановлення ціни
void Product::setPrice(double price) {
    if (price >= 0.0) {
        products[0].price = price;  // Для простоти прикладу, це перший товар
    } else {
        std::cout << "Invalid price!" << std::endl;
    }
}

// Перевірка і встановлення імені
void Product::setName(const std::string& name) {
    if (!name.empty()) {
        products[0].name = name;  // Для простоти прикладу, це перший товар
    } else {
        std::cout << "Invalid name!" << std::endl;
    }
}

// Перевірка і встановлення ID
void Product::setId(int id) {
    if (id > 0) {
        products[0].id = id;  // Для простоти прикладу, це перший товар
    } else {
        std::cout << "Invalid ID!" << std::endl;
    }
}

// Перевірка і встановлення кількості
void Product::setQuantity(int quantity) {
    if (quantity >= 0) {
        products[0].quantity = quantity;  // Для простоти прикладу, це перший товар
    } else {
        std::cout << "Invalid quantity!" << std::endl;
    }
}

